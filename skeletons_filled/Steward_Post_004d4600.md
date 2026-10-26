## Steward_Post_004d4600 — Steward post-race cleanup and teardown

**Summary:** Post-race cleanup: frees D3D audio state at 0xA8, resets comparison and camera director, frees state arrays at 0x110 and 0x114, frees counted array at 0x1AC, zeros 52 pairs of entries at 0x1B0/0x280, resets all vehicle substates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | RW | 0 | D3D audio state pointer — freed and set to 0 |
| this | 0x10C | RW | 0 | State array entry count — reset to 0 |
| this | 0x110 | RW | 0 | State array pointer — freed and set to 0 |
| this | 0x114 | RW | 0 | Previous state array pointer — freed and set to 0 |
| this | 0x1A8 | RW | 0 | Counter — reset to 0 |
| this | 0x1AC | RW | 0 | Counted pointer array — elements and container freed, set to 0 |

**Written-by note (persistence):**
- this 0xA8: Written to 0 unconditionally after free. External poke would survive.
- this 0x10C: Written to 0 unconditionally. External poke would survive.
- this 0x110: Written to 0 unconditionally after free. External poke would survive.
- this 0x114: Written to 0 unconditionally after free. External poke would survive.
- this 0x1A8: Written to 0 unconditionally. External poke would survive.
- this 0x1AC: Written to 0 after free. External poke would survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | R | VehicleCount — loop bound for per-vehicle reset |
| 005d3b6c | aDDevF119992002_3 | R | Scene path for debug logging |
| 005d43ac | aEnteredSteward_2 | R | "Entered Steward Post" debug message string |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray — vehicle pointers for substate reset |
| 007d0410 | dword_7D0410 | R | ChampionshipMode — if not 4, update season scoring |
| 007d2db0 | dword_7D2DB0 | R | RaceStandingsSortBuffer — passed to SeasonScoringInfoUpdater |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer — target for debug log |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040da30 | CameraDirectorResetInit | Resets camera director state |
| 004482d0 | D3DStateInit | Initializes/reinitializes D3D audio state (called before free) |
| 004bb950 | StructResetReinitializer | Resets per-vehicle substate at offset +16436 |
| 004c2a80 | SeasonScoringInfoUpdater | Updates season scoring if championship mode != 4 |
| 004d24d0 | sub_4D24D0 | Cleanup/reset subroutine |
| 004d2e20 | ArithmeticComparison_2e20 | Resets arithmetic comparison state |
| 004d7a50 | StringSplitLoop | Debug message control |
| 004d7aa0 | DebugLogWrite | Writes debug entry message |
| 00587bcf | FreeWrapper_7bcf | Frees heap-allocated memory |

**Guard conditions:** All cleanup operations are conditionally gated on pointer validity (non-null). The 52-pair zeroing loop at the end is unconditional.
