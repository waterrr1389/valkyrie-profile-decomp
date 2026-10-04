# Valkyrie Profile (Japan, Rev 1) decompilation

A partial matching decompilation of Valkyrie Profile for the PlayStation (SLPM-86379/86380, **Rev 1**).
The C in `src/` compiles to the same bytes as the original code.

Provided as is: the project is not actively maintained, and building it from a fresh clone is not
guaranteed to work. Forks are welcome.

## Status
| Unit | C (matching) | Still asm |
|---|---|---|
| Main EXE `SLPM_863.79` | ~200 | 24 (23 of them have a non-matching C draft under `#ifdef NON_MATCHING`) |
| Overlay 4850 | 38 | 32 |
| Overlay 4911 | 21 | 15 |
| Overlay 4913 | 4 | 240 |
| Overlay 4923 | 4 | 312 |

Counts are game functions; PsyQ library code stays as asm. All five units byte-match the original.

## Target
Rev 1 disc images (redump-style `.bin`):
- Disc 1: sha1 `58717b0be800f01957389b65191046cb8ea5a96a`
- Disc 2: sha1 `a553e4c82a0a92e5ed66a371ae24be35a102f411`

Files the build compares against (`disc/`, not included):
- `SLPM_863.79` (from the ISO filesystem): sha1 `713d3f41b196f5666bc0c56a05d61679f4e1b0bb`
- Overlays are entries of the `VALKYRIE.BIN` archive, saved as `disc/OVL_<entry>.BIN`. The archive index is
  XOR-obfuscated (scheme from Pixel's [VP-extract.lua](https://static.grumpycoder.net/pixel/VP-extract.lua));
  entries may be SLZ-compressed (LZSS variants, documented by the Star Ocean 2 reversing community):
  - 4850 `06b7b4e024bc46e8e8f060b3cb293e4702a8893d`
  - 4911 `c99c0878be890b2c2ca6402271dce100557e54f1`
  - 4913 `687e4937f3b2cd11de511feda050981123308961`
  - 4923 `6d4069869a28efeaab5603368b17897d811585ed`

## Layout
- `src/main/`, `src/ovl_XXXX/`: C. Switch functions live in `src/main/jt_*.c` with jump tables at their original addresses.
- `include/`: declarations and asm macros.
- `config/`: splat configs and symbol lists (all overlays load at `0x8002F824`).
- `Makefile`: build rules; `make split`, then `make check` / `make check-ovl`.

## Compiler
GCC 2.7.2 (`2.7.2-psx` from old-gcc), `-O2 -G0 -mips1 -funsigned-char`, assembled through maspsx with
`--aspsx-version=2.79`. The original source was C++, but plain C produces the same code here.
Division expansion differs by file: see the Makefile. Overlays are built without it.

## Tools used
- [splat](https://github.com/ethteck/splat) (splat64 0.50.0): splitting the binaries into asm
- [old-gcc](https://github.com/decompals/old-gcc): GCC 2.7.2-psx `cc1`
- [maspsx](https://github.com/mkst/maspsx): PsyQ ASPSX replacement in front of GNU as
- [GNU binutils](https://www.gnu.org/software/binutils/) 2.47, built for `--target=mipsel-linux-gnu`
- [m2c](https://github.com/matt-kempster/m2c): first drafts of C from asm
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter): near-miss functions

The Makefile expects them under `tools/` (`tools/gcc-2.7.2-psx/`, `tools/binutils/`, `tools/maspsx/`) and
Python in `.venv/`. `make split` also copies asm from a local `work/asm_ref/` directory for functions splat
skips; that directory is not part of this repository.

## License
CC0 1.0 (see `LICENSE`). Covers the code in this repository only; no game data is included.
