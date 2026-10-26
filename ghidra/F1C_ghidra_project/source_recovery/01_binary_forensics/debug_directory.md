# BF-03: Debug Directory & PE Headers

**Status:** DONE (2026-07-16)

## PE Header Summary

| Field | Value |
|-------|-------|
| Machine | 0x14C (i386) |
| **Build timestamp** | **2003-04-15 15:27:50 UTC** |
| Linker version | 6.0 (MSVC 6.0) |
| ImageBase | 0x00400000 |
| Debug directory | **NONE** |
| Export table | **NONE** |
| Checksum | 0x0 (not set) |

## Sections

| Name | VA | VSize | RawSize | Characteristics |
|------|------|-------|---------|----------------|
| .text | 0x1000 | 0x19C5E6 | 0x19D000 | CODE, EXECUTE, READ |
| .rdata | 0x19E000 | 0x1F0A1 | 0x20000 | INITIALIZED, READ |
| .data | 0x1BE000 | 0x317A70 | 0x2D000 | INITIALIZED, READ, WRITE |
| .data1 | 0x4D6000 | 0x8E0 | 0x1000 | INITIALIZED, READ, WRITE |
| **LBMPEG_D** | **0x4D7000** | **0x400** | **0x1000** | INITIALIZED, READ, WRITE |
| **.text1** | **0x4D8000** | **0xB6000** | **0xB6000** | CODE, EXECUTE, READ |
| .data2 | 0x58E000 | 0x10000 | 0x10000 | INITIALIZED, READ, WRITE |
| .rsrc | 0x59E000 | 0x5B13C | 0x5C000 | INITIALIZED, READ |

## Key Findings

1. **No debug directory** — no PDB path, no CodeView info, no FPO data. Fully stripped release build.

2. **No exports** — exe doesn't export any functions. Plugin loading must use LoadLibrary/GetProcAddress on DLLs, not exe exports.

3. **Build date: April 15, 2003** — F1 Challenge released June 2003. This is ~2 months pre-release, likely a release candidate.

4. **LBMPEG_D section** — named section for Lee Briggs MPEG decoder data. Confirms MPEG video playback is a separate linked module with its own data section. Source path found: `\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp`.

5. **.text1 section** (0xB6000 = 745KB) — secondary code section. This is unusual. Likely a separately-linked module (possibly the physics engine or a DLL statically linked). Address range: 0x004D8000 - 0x0058E000 in memory. This maps to the dynamics solver, LDL^T factorization, and rigid body code we found via IDA.

6. **.data VSize (0x317A70 = 3.2MB) vs RawSize (0x2D000 = 180KB)** — massive BSS (uninitialized data). Most globals are zero-initialized at startup. This is where the physics workspace and vehicle arrays live.
