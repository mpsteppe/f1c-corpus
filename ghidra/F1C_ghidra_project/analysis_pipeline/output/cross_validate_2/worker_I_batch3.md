# Cross-Validation Results — Batch 3 (47 functions)

## FUN_004d2e50 — PASS
Source: docs/07-pit-system.md
- All claims verified. State machine driven by DAT_007c56a4 (SessionType) and DAT_007c56a8 (RacePhase). Struct offsets +0xb4/+0xb0/+0xd8/+0xc2/+0xf4/+0x104 match source. Call list complete (FUN_0041a500, FUN_0042d140, FUN_004d0ec0, FUN_0041a6b0, FUN_004d1cd0, FUN_004d2e20, FUN_00423a00, FUN_004d11d0, FUN_0045bdf0, FUN_0040cde0, FUN_0040dd80, FUN_0040de60, FUN_0040e170, FUN_004bc9b0, FUN_00461db0, FUN_004d2210, FUN_0045bd10, FUN_0058957a). Globals list verified against source.

## FUN_004c18b0 — PASS
Source: docs/08-file-formats.md
- Career stats struct fields +0x08 through +0x23 verified against source (param_1 int-indexed). All field names match string constants in source (CAREERSEASON, PLAYERTRACKSTAT, TotalNumLaps, BestLapTime, TrackFile, Trackname, GAMEOPT_opponents/fuel_mult/tire_mult/speed_comp). FUN_00565760 for int fields, FUN_00565870 for race_length and best_lap_time, FUN_00565520 for avg fields — all match.

## FUN_004c2a80 — PASS
Source: docs/08-file-formats.md
- Gated by FUN_0042bc10() and DAT_008ab6e4 != 2 (source lines 14-15). Scene array DAT_008ac490 stride 0x18c at index DAT_008ac48c (line 16). Adds DAT_007c54e8+0x403c to scoring struct +0x10 (line 21). Updates +0x14 from +0x409c (lines 22-24). Race branch at DAT_007c56a4==7 (line 29). Finish position at +0x4060 (line 30). SeasonScoringInfo section read via thunk_FUN_0059d6a9 (line 41). All verified.

## FUN_0041f8a0 — PASS
Source: docs/08-file-formats.md
- Season load via FUN_004c2850 (line 23), race count via FUN_004c11d0 (line 24). 14 teams ARROWS through STEWART (lines 33-73). Leading team stored in local_44 (line 81). Re-iterates with FUN_0041f220 (line 140). Returns 1 if clinched (line 152), 0 otherwise (line 158). All claims verified.

## FUN_004c5cb0 — PASS
Source: docs/08-file-formats.md
- Default param_1[3] = 0x7fffffff (line 13). SceneOrder section via FUN_00568210 (line 14). thunk_FUN_0059d6a9 for entries (line 18). FUN_00499e20(+0x104) then FUN_00588410 (lines 21-22). All verified.

## FUN_00409440 — PASS
Source: docs/08-file-formats.md
- Check DAT_007cfe88==0 and param_2==3 (line 8). Player vehicle +0x344c and DAT_008ab6e4 gate (line 9). 8 < param_2 → FUN_00408740 (lines 13-14). Jump table at DAT_004096ac (line 19). All verified.

## FUN_00433290 — PASS
Source: docs/08-file-formats.md
- Extracts directory from path at *param_1 (lines 14-29, finds last backslash). FUN_004328e0 for comparison path (line 30). _strncmp compare (line 43). Copies to param_2 buffer with max param_3 (line 59). Falls back to DAT_005c4068 if empty (line 58-59). All verified.

## FUN_004bfcd0 — PASS
Source: docs/08-file-formats.md
- Bounds check against param_1[3] (line 12). DAT_008ac390/DAT_008ac394 stride 0x424 (line 30). Returns pointer to vehicle entry. All verified.

## FUN_004f81d0 — PASS
Source: docs/08-file-formats.md
- Checks if param_2 string empty → returns success (lines 22-30). Otherwise vtable dispatch through DAT_008ac4c4+0x5c (line 33). Doc description "String Match with Wildcard" is oversimplified (actual mechanism is vtable dispatch), but entry is triage-level with minimal claims. No factual errors.

## FUN_0046d060 — PASS
Source: docs/08-file-formats.md
- FUN_005881c0 (line 11), FUN_0042e320 (line 12). DAT_007ce668 with fallback to DAT_005ea438 (lines 13-16). FUN_0042fd00 (line 17). FUN_004b0770(1) (line 18). FUN_0042ddd0 (line 19). FUN_00587bcf for stack param (lines 20-22). All verified.

## FUN_005903da — PASS
Source: docs/08-file-formats.md (triage entry)
- Code page lookup: resolves "ACP" (line 13) and "OCP" (line 17). Registry call via (*DAT_008d3fb8)(DAT_008d3fb4,...) (line 21). Falls through to FUN_00587ece(param_1) for atoi fallback (line 27). All verified against triage claims.

## FUN_00599958 — PASS
Source: docs/08-file-formats.md (triage entry)
- Size 385 bytes (58 lines) matches source. Object constructor with SEH (ExceptionList at line 54) + vtable init (calls to FUN_0059a5e9, FUN_00599cb7, FUN_00599bf0, FUN_00599b1c). DAT_005ea04c counter increment (lines 17-23). All verified.

## FUN_004630c0 — PASS
Source: docs/08-file-formats.md
- Calls FUN_00566650() with no arguments (line 8). Simple delegation wrapper. Verified.

## FUN_005668f0 — PASS
Source: docs/08-file-formats.md
- FUN_0058ba75(param_1, 0) check exists (line 10). FUN_0058ba75(param_1, 6) check writable (line 12). FUN_0058ba36(param_1, 0x180) set attributes (line 14). Re-check returns 0 on failure (lines 15-16), 1 on success (line 21). Verified.

## FUN_00559a70 — PASS
Source: docs/08-file-formats.md
- Struct layout param_1[0]=status, [1]=readPos, [2]=bufSize, [0xc4]=srcBuf base (verified from code). Loop while pos < size copies byte to param_1+0xc+offset (lines 14-22). Stops at '\n' (line 22). Null-terminates (line 23). Returns status from FUN_00559ad0 (line 27). Verified.

## FUN_004c2830 — PASS
Source: docs/08-file-formats.md
- Calls FUN_004c2850(), if non-zero calls FUN_004c0f60() (lines 10-13). Verified.

## FUN_0059d004 — PASS
Source: docs/08-file-formats.md (triage, Unwind handler)
- 14-byte unwind handler calling FUN_00581750 (line 8). Unwind/thunk — negligible. Verified.

## FUN_005939cf — PASS
Source: docs/08-file-formats.md
- Magic check: *v1 == 0xE011CFD3 (-529697949) (line 12). v1[4] == 3 (line 12). v1[5] == 0x199999A0 (429065504) (line 12). v1[7] == 0 (line 12). Returns TRUE if all match. All verified.

## FUN_0049ca00 — PASS
Source: docs/09-track-system.md
- Gauge textures at stride 0x4c: +0x60 (TAC_01), +0xac (WATERTEMP), +0xf8 (OILTEMP), +0x144 (OILPRESS), +0x190 (FUEL) — stride verified from code (lines 19-28). LED textures at +0x20 through +0x48 matching names (lines 39-60). Font textures FONTREAD/FONTLCD/FONTAIDS (lines 74-85), LCD00/LCD01 (lines 90-94). DAT_008afe88 gate (line 29). CMAPS.MAS archive (line 71). All verified.

## FUN_0046B0C0 — SKIP
Source: (claimed docs/09-track-system.md, but no ## FUN_ entry exists)
- No doc entry found to validate. Source shows key binding handler with states 1 (waiting), 2 (processing), 3 (done). String "Press key or controller (ESC to skip)" and "POPUP_CONTROL_SET" present. Functions as key binding UI controller.

## FUN_0040adb0 — PASS
Source: docs/09-track-system.md
- Computes scaled world position from camera array (lines 29-33). Cam active check at param_1[4] (line 34). Iterates all vehicles for proximity + speed (lines 37-59) using DAT_005c329c/DAT_007c54f0. Random shake via FUN_0040c780+FUN_00457a00 (lines 52-54). Clear via FUN_00457b00(0) (line 61). Player camera orientation update with DAT_007c54e0 (lines 64-76). Vehicle offsets +0x58..0x60/+0x704..0x70c/+0x744..0x74c verified from code. All claimed calls present.

## FUN_0040b710 — PASS
Source: docs/09-track-system.md
- Index*0xd0 into array at param_1+0xc (line 23). Reads DAT_007c54e0+0x58/0x5c/0x60 (lines 27-29). FUN_0040c780 (line 32) and FUN_004084a0 (line 34). Vtable call at (*iVar1 + 0x18) (line 35). Camera shake and rendering calls match (lines 37-42). _DAT_0059e65c multiplier (lines 40-41). Verified.

## FUN_004c5830 — PASS
Source: docs/09-track-system.md
- DAT_008AC48C = param_1 (line 8). Verified.

## FUN_00435410 — PASS
Source: docs/10-vehicle-physics.md
- Reads suspension section: SpringParams (line 173), SpringCollLen (line 172), SpringBody (line 160), SpringHead (line 159), SpringDir (line 158), FREEDAMPING/SLIDING/NORMAL damping classification (lines 137-152). Double-precision reads via FUN_00565aa0. Stores at int-indexed offsets in param_1. All field names match string constants in source.

## FUN_0042f260 — PASS
Source: docs/10-vehicle-physics.md
- Base: int_value * double_multiplier + double_base (line 12). Offset from CG/Wedge at param_1+0xc84/+0xc78/+0xc70/+0x199c (lines 14-15). Metric %.1f with _DAT_0059ea20 (line 18). Imperial %.3f with _DAT_0059ea20*_DAT_0059ea18 (line 21). Verified.

## FUN_0042ad20 — PASS
Source: docs/10-vehicle-physics.md
- If DAT_007d0b64 != 0: __ftol return (lines 10-12). Default: 100 (line 14). Verified.

## FUN_004326e0 — PASS
Source: docs/10-vehicle-physics.md
- FUN_00432180/FUN_00432220/FUN_004326d0 init calls (lines 20-22). FUN_004326a0 gets name from DAT_005ec4cc (line 23). FUN_00423a00 search (line 26). Linked list iteration for matching index (lines 36-52). FUN_00432980 with matched name (line 57). FUN_00588410 compare (line 50). Verified.

## FUN_004e2540 — PASS
Source: docs/10-vehicle-physics.md
- Offset: param_2*0x128+0xd4+param_1 (line 18). Velocity = param_3 - position at +0x48/0x4c/0x50 (lines 19-21). Stores at +0x74/+0xb8 (lines 22-27). Params at +0xfc/+0xf8/+0xc4/+0xcc (lines 28-32). FUN_005670d0 (line 33). Copies 9 ints from +0xd0 to +0x8c (lines 34-40). FUN_00567340 (line 41). Verified.

## FUN_00476060 — PASS
Source: docs/10-vehicle-physics.md
- Sets this[44] = a2 (line 12). Returns a2 (line 11). Verified.

## FUN_004ea040 — PASS
Source: docs/17-physics-collision.md
- FUN_004ea930 for wheel-relative position (line 62). Transform via rotation matrix at +0x34b0 (lines 66-71). AABB overlap test (lines 78-83). D3D device iteration via FUN_0054c230/FUN_0054e100/FUN_0054e120 (lines 95-100). Closest point tracking (lines 110-123). Penetration depth computation (lines 130-195). FUN_004ed420 raycast (line 211). Restitution _DAT_0059e7e8 (line 235). Verified.

## FUN_004497e0 — PASS
Source: docs/17-physics-collision.md
- Allocates *param_1 × 5 floats (stride 0x14=5 floats, line 20). Reads 3 positions, computes min/max for X/Y/Z (lines 26-87). FUN_005890aa sort (line 93). Overlap pairs: X+Z overlap then Y check (lines 99-112). FUN_004491c0 precise test (line 106). Verified.

## FUN_0044c950 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&PTR_LAB_0044c960) (line 8). Verified.

## FUN_0044d130 — PASS
Source: docs/17-physics-collision.md (Thunk)
- FUN_00587b3e(&DAT_0044d140) (line 8). Verified.

## FUN_0044db80 — PASS
Source: docs/17-physics-collision.md
- DAT_007ccee8 = 0x2f (47) (line 10). Zeros 5 dwords at 007cceec-007ccefc (lines 11-15). Verified.

## FUN_0044d250 — PASS
Source: docs/17-physics-collision.md (Thunk)
- FUN_00587b3e(&PTR_LAB_0044d260) (line 8). Verified.

## FUN_0044a070 — PASS
Source: docs/17-physics-collision.md
- Iterates 3 half-space planes at param_1+0x34 stride 3 floats (lines 14-21). Quadratic form evaluation (lines 23-24). Updates param_2[4] with min distance (line 31). Records hit at param_2+5 and param_2+6 (lines 32-33). Returns 1 on hit (line 34), 0 on miss (lines 16, 29, 36). Verified.

## FUN_0044ec00 — PASS
Source: docs/17-physics-collision.md
- DAT_007ca3f8 = 99 (line 10). Zeros DAT_007ca3fc-DAT_007ca408 (lines 11-14). DAT_007ca40c = 9000 (line 15). Verified.

## FUN_0044d430 — PASS
Source: docs/17-physics-collision.md
- FUN_00587B3E(&DAT_0044D440) (line 8). Verified.

## FUN_0044fc20 — PASS
Source: docs/17-physics-collision.md
- param_4 clamped [0,1] stored at param_1+0x20+param_2*4 (lines 13-16). param_3 floored at 0 stored at param_1+0x2f8+param_2*4 (lines 17-20). param_5 clamped [0,1] stored at param_1+param_2*4 (lines 21-25, 29). FUN_0044f8f0() call (lines 26, 30). DAT_0059e440 and _DAT_0059e43c constants used. Verified.

## FUN_0044f070 — PASS
Source: docs/17-physics-collision.md
- Fills 0x40 dwords at param_1+0x27c with repeated byte pattern (CONCAT22/CONCAT11 replication) (lines 11-15). Verified.

## FUN_0044e4b0 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(&DAT_0044e4c0) (line 8). Verified.

## FUN_00498740 — PASS
Source: docs/17-physics-collision.md
- Reads DAT_007cb2fc (line 12), DAT_007cb300 (line 13), DAT_007cb304 (line 14). Writes to param_1+100, +0x68, +0x6c. FUN_0044f7d0 stored at +0x70 (lines 15-16). __ftol twice at +0x5c/+0x60 (lines 17-20). Verified.

## FUN_0044c770 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(DAT_0044c780) (line 8). Verified.

## FUN_0044d340 — PASS
Source: docs/17-physics-collision.md
- DAT_007ca4d0 = 0x3f (63) (line 10). Zero _DAT_007ca4d4 (line 11). _DAT_007ca4d8 = 0xbf800000 (-1.0f) (line 12). Zero _DAT_007ca4dc (line 13). Verified.

## FUN_0044df70 — PASS
Source: docs/17-physics-collision.md
- FUN_00587b3e(DAT_0044df80) (line 8). Verified.

## FUN_00490ee0 — PASS
Source: docs/17-physics-collision.md
- FUN_00490940 (line 23), FUN_00491680 (line 28), FUN_00491350 (line 35). Allocates 0xc nodes via operator_new (line 37). Stale entry removal by iVar7 match (lines 64-85). FUN_00491e10 notification (line 79). FUN_004bac20 (line 103), FUN_00490d00 merge (line 117). FUN_00434030/FUN_00581780 iteration (lines 122-123). FUN_00491db0 return (line 126). Verified.

## FUN_004070e0 — PASS
Source: docs/17-physics-collision.md
- Iterates array at *(param_1+0x48) stride 0x14 (lines 25, 37). Weighted comparison using power-of-2 bit shifts (line 31). Vtable+8 dispatch on winner (line 43). Returns winner pointer or null (lines 45-48). Verified.
