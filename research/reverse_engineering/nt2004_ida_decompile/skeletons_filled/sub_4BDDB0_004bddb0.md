## sub_4BDDB0_004bddb0 — InitPitCrew

**Summary:** Initializes pit crew system — loads pit crew data files (PITS.MAS, CDB.MAS, CMAPS.MAS), configures crew member positions and animations, and sets up camera transforms. Iterates crew member linked list to position each member.

**Called by:** sub_4BFD80 (004bfd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x4C | R | — | Crew member field at +76 (position X) |
| *(this+0xB8) | 0x50 | R | — | Crew member field at +80 (position Y) |
| *(this+0xB8) | 0x54 | R | — | Crew member field at +84 (position Z) |
| *(this+0xB8) | 0x58 | R | — | Crew member field at +88 (rotation/float X) |
| *(this+0xB8) | 0x5C | R | — | Crew member field at +92 (rotation/float Y) |
| *(this+0xB8) | 0x60 | R | — | Crew member field at +96 (rotation/float Z) |
| *(this+0xC4) | 0x0 | R | — | Crew member active flag at +100 — non-zero triggers position/rotation set |
| this | 0x0 | RW | 1 | Pit crew initialized flag |
| this | 0xB8 | R | — | Crew member linked list head pointer (this[46]) |
| this | 0xC0 | RW | — | Current crew member node pointer (this[48]) — walk pointer |
| this | 0xC4 | R | — | Data file handle #3 (PITS.MAS) |
| this | 0xCC | R | — | Pit crew context/state pointer (this[51]) |

**Written-by note (persistence):**
- this 0x0: written once during init (set to 1); external poke would survive until re-init
- this 0xC0: written repeatedly during linked list traversal; temporary walk pointer, overwritten each init cycle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0060116c | aSSS_3 | R | "%s%s%s" format string for path concatenation |
| 0060950c | aCmapsMas | R | "CMAPS.MAS" — crew map data file name |
| 00609aec | aDDevNascar2004_12 | R | Source file path "D:\\dev\\NASCAR_2004\\Source\\pitcrew.cpp" for error context |
| 00609f00 | aUnableToSetupA | R | "Unable to setup after pitcrew %s" error message format |
| 00609f24 | aCdbMas | R | "CDB.MAS" — crew database file name |
| 00609f2c | aPitsMas | R | "PITS.MAS" — pit crew data file name |
| 00628f60 | flt_628F60 | R | Float constant — passed to camera setup |
| 00629120 | byte_629120 | R | Empty string fallback |
| 0062a068 | dword_62A068 | R | Base data directory path |
| 0062a0b8 | dword_62A0B8 | R | Sub-path string for data files |
| 0062bf64 | unk_62BF64 | R | Unknown reference data |
| 0075aacc | dword_75AACC | R | Camera/object handle — passed to sub_4F8F10 and sub_404ED0 |
| 007d7428 | byte_7D7428 | R | Unknown config flag |
| 007d7920 | dword_7D7920 | R | Error display context |
| 007da988 | dword_7DA988 | R | File/resource handle — passed to sub_5924D0 for MAS file loading |
| 007da9b8 | dword_7DA9B8 | R | Pit crew data object — checked for non-null before proceeding |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404ed0 | sub_404ED0 | Set up camera/view transform with float constant, object, position vector |
| 0042dbc0 | sub_42DBC0 | Check some condition — if true, camera setup proceeds |
| 004be390 | sub_4BE390 | Initialize pit crew internal structures |
| 004bea40 | sub_4BEA40 | Apply position and rotation to pit crew |
| 004bec30 | sub_4BEC30 | Finalize pit crew initialization |
| 004f8f10 | sub_4F8F10 | Get position vector and orientation from object |
| 00500f90 | sub_500F90 | Show error/assert dialog |
| 00500fe0 | sub_500FE0 | Display formatted error message |
| 00591c90 | sub_591C90 | Query/retrieve some string value |
| 005924d0 | sub_5924D0 | Load MAS data file by name into handle |
| 00592750 | sub_592750 | Release/unload MAS data file handle |
| 00596220 | sub_596220 | Check if pit crew setup failed |
| 005974a0 | sub_5974A0 | Process pit crew context/state |
| 0059e050 | ThreeFieldSetterWithSubCall [structural] | Set crew member position (X, Y, Z) |
| 0059e0f0 | sub_59E0F0 | Set crew member rotation/orientation |
| 0059ecc0 | FlagFieldBitManipulation [structural] | Set/clear flags (called with 1, 0, 0, 0) |
| 005beec8 | _sprintf | Build file path string |

**Guard conditions:** 
- dword_7DA9B8 == 0 → BLOCKED, return 0 (no pit crew object)
- this[51] == 0 → BLOCKED, return 0 (no pit crew context)
- sub_596220 returns non-zero → error shown ("Unable to setup after pitcrew %s")
- Crew member active flag at +100 == 0 → skip that crew member (iterate to next)
- this[48] (walk pointer) becomes null → exit linked list traversal

**String literals referenced (deterministic):**

- `%s%s%s`
- `%s%s%s`
- `CMAPS.MAS`
- `D:\dev\NASCAR_2004\Source\pitcrew.cpp`
- `Unable to setup after pitcrew %s`
- `CDB.MAS`
- `PITS.MAS`
