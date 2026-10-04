# Valkyrie Profile (JP Rev 1) decomp
SHELL := /bin/bash
.SHELLFLAGS := -o pipefail -c
TOOLS    := tools
BINUTILS := $(TOOLS)/binutils/bin/mipsel-linux-gnu-
PYTHON   := .venv/bin/python
GCC_VER  ?= 2.7.2-psx
CC1      := $(TOOLS)/gcc-$(GCC_VER)/cc1
MASPSX   := $(PYTHON) $(TOOLS)/maspsx/maspsx.py --aspsx-version=2.79 --gnu-as-path=$(BINUTILS)as
DIVFLAGS := --expand-div
# original objects from 0x80015294 on were assembled without div expansion
build/src/main/main2.o build/src/main/jt_8001ACF8.o: DIVFLAGS :=
# no overlay function has the break-7 checks: overlays were built without div expansion
build/src/ovl_%: DIVFLAGS :=
AS       := $(BINUTILS)as
LD       := $(BINUTILS)ld
OBJCOPY  := $(BINUTILS)objcopy

CPPFLAGS := -nostdinc -undef -P -Iinclude -D__GNUC__=2 -D__GNUC_MINOR__=7 -Dmips -D__mips__ -D__mips=1 -D_LANGUAGE_C -DPSX
CC1FLAGS := -quiet -O2 -G0 -mcpu=3000 -mips1 -fno-builtin -funsigned-char -mgas -msoft-float -gcoff
ASFLAGS  := -EL -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0 -Iinclude

MAIN     := slpm_863.79
BUILD    := build
C_FILES  := $(shell find src/main -name '*.c')
S_FILES  := $(shell find asm/main -name '*.s' -not -path '*nonmatchings*')
O_FILES  := $(C_FILES:%.c=$(BUILD)/%.o) $(S_FILES:%.s=$(BUILD)/%.o)

.PHONY: all check check-ovl split clean nonmatching
all: $(BUILD)/$(MAIN)

split:
	$(PYTHON) -m splat split config/$(MAIN).yaml
	for o in $(OVLS); do $(PYTHON) -m splat split config/ovl_$$o.yaml; done
	$(PYTHON) tools/scripts/fix_gte.py asm
	@# splat sometimes skips a function it thinks is defined in C; work/asm_ref holds every original
	@cp -n work/asm_ref/main/*.s asm/main/nonmatchings/main/ 2>/dev/null || true

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	cpp $(CPPFLAGS) $< | $(CC1) $(CC1FLAGS) -o - | $(MASPSX) $(DIVFLAGS) --run-assembler $(ASFLAGS) -o $@

$(BUILD)/%.o: %.s
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD)/$(MAIN).elf: $(O_FILES) $(BUILD)/$(MAIN).ld
	$(LD) -nostdlib --no-check-sections -T $(BUILD)/$(MAIN).ld -T config/undefined_syms_auto.main.txt -T config/undefined_funcs_auto.main.txt -Map $(BUILD)/$(MAIN).map -o $@

$(BUILD)/$(MAIN): $(BUILD)/$(MAIN).elf
	$(OBJCOPY) -O binary $< $@

# code overlays (all load at 0x8002F824); main-exe symbols come from config/symbols.mainexe_for_ovl.txt
OVLS := 4911 4850 4913 4923
define OVL_RULES
OVL_$(1)_O := $$(patsubst %.c,$(BUILD)/%.o,$$(shell find src/ovl_$(1) -name '*.c')) \
              $$(patsubst %.s,$(BUILD)/%.o,$$(shell find asm/ovl_$(1) -name '*.s' -not -path '*nonmatchings*'))
$(BUILD)/ovl_$(1).elf: $$(OVL_$(1)_O) $(BUILD)/ovl_$(1).ld
	$(LD) -nostdlib --no-check-sections -T $(BUILD)/ovl_$(1).ld -T config/symbols.mainexe_for_ovl.txt -T config/undefined_syms_auto.ovl_$(1).txt -T config/undefined_funcs_auto.ovl_$(1).txt -Map $(BUILD)/ovl_$(1).map -o $$@
$(BUILD)/ovl_$(1).bin: $(BUILD)/ovl_$(1).elf
	$(OBJCOPY) -O binary $$< $$@
endef
$(foreach o,$(OVLS),$(eval $(call OVL_RULES,$(o))))

check-ovl: $(foreach o,$(OVLS),$(BUILD)/ovl_$(o).bin)
	@for o in $(OVLS); do cmp -s $(BUILD)/ovl_$$o.bin disc/OVL_$$o.BIN && echo "OK: ovl_$$o matches" || { echo "MISMATCH: ovl_$$o"; exit 1; }; done

check: $(BUILD)/$(MAIN)
	@sha1sum $< disc/SLPM_863.79 | awk '{print $$1}' | uniq | wc -l | grep -q '^1$$' && echo "OK: $(MAIN) matches" || (echo "MISMATCH: $(MAIN)"; exit 1)

# compile the best C attempts of the still-asm functions (does not link or compare)
NM_O_FILES := $(C_FILES:%.c=build_nm/%.o)
nonmatching: $(NM_O_FILES)
	@echo "OK: NON_MATCHING sources compile"

build_nm/%.o: %.c
	@mkdir -p $(dir $@)
	cpp $(CPPFLAGS) -DNON_MATCHING $< | $(CC1) $(CC1FLAGS) -o - | $(MASPSX) --expand-div --run-assembler $(ASFLAGS) -o $@

clean:
	rm -rf $(BUILD) build_nm
