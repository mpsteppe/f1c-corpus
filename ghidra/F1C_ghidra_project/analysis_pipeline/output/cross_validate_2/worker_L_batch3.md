# Cross-Validation Report: worker_L_batch3

## 3961–4005 cross-validation results

---

### 3961. FUN_00554BE0 — no issues
**Current doc:** docs/06-session-race-logic.md (line 15885)
**Issues found:** none
**Details:** Doc describes "Mode/State Setter Through Vtable" — stores param_2 at param_1[0x4e8] if changed, calls vtable[200](ptr, 0xe, param_2), sets *param_1 = result. Source confirms: conditional store at param_1[0x4e8], dispatch via `(**(code **)(*piVar1 + 200))(piVar1,0xe,param_2)`, result stored to *param_1. Toggle behavior (param_2 is 0 or 1) matches.

---

### 3962. FUN_004CDAD0 — no issues
**Current doc:** docs/06-session-race-logic.md (line 16400)
**Issues found:** none
**Details:** Doc "ScoringGateTimeoutCheck" matches source: guard `dword_8AB6E4 == 2`, elapsed time via `sub_4B9CE0(&unk_8AB6EC)`, iteration of entries at `this[26]` with count `this[25]`, compares entry+0x8 float against elapsed time, removes via `sub_4CB5A0`. All globals, calls, and logic verified.

---

### 3963. FUN_0041B910 — issues: missing globals + gates
**Current doc:** docs/07-pit-system.md (line 299)
**Issues found:** incomplete gating documentation
**Details:** Doc says "Clears all three pit selection flags. Calls FUN_00418a20 with 0x7b, 0x7c, 0x7d." But source has 4 gating conditions:
- `DAT_007d0308 != 0` (RaceActiveFlag)
- `DAT_007cf3c8 != DAT_0059e440` (timer not zero)
- `DAT_007c56a8 != 8` (RacePhase != 8)
- `param_1 == 5`
Without these gates, function is a no-op. Doc does not list any of these globals. Calls listing is correct (FUN_00418a20 ×3). Recommend adding gate conditions to entry.

---

### 3964. FUN_0041B980 — no issues
**Current doc:** docs/08-file-formats.md (line 86)
**Issues found:** none
**Details:** Doc "Team Name → Display ID Lookup" matches source: gated by DAT_007d0308 and DAT_007cf3c8, massive nested FUN_00566810 calls (44+), returns team display IDs 0x125–0x150. String header confirms "[2002 Williams, 2002 Toyota, ...]" matches team name strings. Calls FUN_004144d0() and FUN_00566810() as documented.

---

### 3965. FUN_004C5AE0 — no issues
**Current doc:** docs/08-file-formats.md (line 402)
**Issues found:** none
**Details:** Doc "SeasonRaces Section Writer" matches source: strips extension from param_1 filename, appends DAT_005c5d24/DAT_005c5d28 (suffix constants), opens/creates "SeasonRaces" section via FUN_00568210 (fallback FUN_00567fb0), writes via FUN_00567f40. All verified. String "SeasonRaces" confirmed in source.

---

### 3966. FUN_004C6330 — no issues
**Current doc:** docs/08-file-formats.md (line 825)
**Issues found:** none
**Details:** Doc "Scene File Filter Builder" is detailed and accurate. Filter path logic, DAT_007d0398/DAT_007d0410 gate, tokenizer via FUN_005897ca, three category arrays, merge sort via FUN_004c6810, linked list management at param_1+8/0xc/0x10/0x14/0x18 all verified against source. Globals DAT_008ac488, DAT_008ac490, DAT_005d31ec ("Filter Properties") confirmed.

---

### 3967. FUN_004C6150 — no issues
**Current doc:** docs/08-file-formats.md (line 1306)
**Issues found:** none
**Details:** Doc "Filter Properties List Node Remover" matches source: iterates linked list at param_1+8, computes scene ptr via `*piVar6 * 0x18c + DAT_008ac490`, reads "Filter Properties" field via FUN_004c58a0 at +0x104, calls FUN_00566810 up to param_3 times, removes nodes on match. Node unlinking (doubly-linked list), free logic (FUN_00587bcf), count decrement at param_1+0x14 all verified.

---

### 3968. FUN_00415C30 — no issues
**Current doc:** docs/08-file-formats.md (line 1710)
**Issues found:** none
**Details:** Doc "Null-safe Pointer Dereference" matches source: returns *param_1 if non-NULL, else returns &DAT_005ea438 (empty string). Verified.

---

### 3969. FUN_00434000 — no issues
**Current doc:** docs/08-file-formats.md (line 1917)
**Issues found:** none
**Details:** Doc "File Load with Flag Preserve" matches source: saves DAT_007c56c0, calls FUN_0042fd00(puVar2, 1) with param_1 string and literal 1, restores DAT_007c56c0. All verified.

---

### 3970. FUN_004C38D0 — ISSUE: misclassified as "File Loader"
**Current doc:** docs/08-file-formats.md (line 2086)
**Issues found:** DOC MISCLASSIFIED — function does NOT load files
**Details:** Doc says "File/INI Loader. Reads param_1 filename into 512-byte buffer. Processes file content." Source shows this is purely a FILENAME STRING PROCESSOR, not a file loader. It:
- Copies filename string into local_200[512] buffer
- Strips path (finds last backslash `\`, copies remainder)
- Strips extension (finds last `.`, replaces with `\0`)
- No file I/O calls whatsoever (no CreateFile, fopen, ReadFile, etc.)
The function extracts the base filename from a full path. Recommend renaming to "Filename Path+Extension Stripper" or similar.

---

### 3971. FUN_005622C0 — no issues (lightweight entry acceptable)
**Current doc:** docs/08-file-formats.md (line 2242)
**Issues found:** none
**Details:** Doc "File Path/Name Lookup" is a lightweight entry (triage-level). Source shows switch dispatch with 8 cases calling sub-functions (FUN_005626b0, FUN_00562830, FUN_00562890, FUN_005628f0, FUN_00562610, FUN_00562950) and semicolon dispatch via vtable+0xfc. The lightweight description is adequate for the current triage status — no factual errors.

---

### 3972. FUN_0058E4D2 — no issues
**Current doc:** docs/08-file-formats.md (line 2406)
**Issues found:** none
**Details:** Doc describes printf/scanf format string parser. Source (632 lines) confirms: handles flags (+,-,0,#), width, precision, length modifiers (h,l,I64,w), conversion specifiers (d,i,o,u,x,X,f,F,e,E,g,G,c,s,p,n,[,{). Uses character classification lookup via DAT_005e69c8. All correctly described.

---

### 3973. FUN_00588212 — no issues
**Current doc:** docs/08-file-formats.md (line 2566)
**Issues found:** none
**Details:** Doc describes as "Math library function — likely pow(x,y) or similar transcendental." Source confirms IEEE 754 double decomposition, NaN/Inf/zero handling, FLAGS checking, helper calls to __fload_withFB, log2, etc. Status codes described (0=success, 1=overflow, 2=domain, 7=indeterminate). Globals DAT_008d3e40, DAT_005e6c50 verified.

---

### 3974. FUN_005968F6 — no issues
**Current doc:** docs/08-file-formats.md (line 3185)
**Issues found:** none
**Details:** Doc "Registry/INI key read — reads string or hex DWORD from registry/INI." Source confirms: param_1==0 reads hex DWORD from DAT_008d41c4 buffer (0x8d41c4-0x8d41cb range), param_1==1 reads string. Character classification via FUN_0058c674/PTR_DAT_005e69c8. All verified.

---

### 3975. FUN_00598CF9 — no issues
**Current doc:** docs/08-file-formats.md (line 3714)
**Issues found:** none
**Details:** Doc "InputStream Read with Buffered Fill" matches source: loop until param_3 bytes read, buffer managed by param_1[0xb] (remaining) and param_1[7] (buffer ptr), memcpy via FUN_0058cc00 when buffer has data, refill via vtable+0x14 when empty, returns -1 on EOF. All verified.

---

### 3976. FUN_00562090 — no issues
**Current doc:** docs/08-file-formats.md (line 4388)
**Issues found:** none
**Details:** Doc "Base64 Encode (3→4 byte transform)" matches source: reads 3 bytes at a time, if fewer than 3 remain pads with zero, generates 4 encoded chars via FUN_00564c40. Output null-terminated. Classic Base64 pattern confirmed.

---

### 3977. FUN_00568540 — no issues
**Current doc:** docs/08-file-formats.md (line 5343)
**Issues found:** none
**Details:** Doc "File Attributes + Existence Check" matches source: calls FUN_0058ba36(param_1, 0x180) (file attr set), calls FUN_0058986e(param_1) (file check), returns TRUE if result == 0. All verified.

---

### 3978. FUN_00588678 — no issues
**Current doc:** docs/08-file-formats.md (line 5763)
**Issues found:** none
**Details:** Doc "File Read Wrapper with Lock" matches source: FUN_0058c1b1(param_4) acquire lock, FUN_005886a7(param_1,param_2,param_3,param_4) actual read, FUN_0058c203(param_4) release lock. All verified.

---

### 3979. FUN_0059D4F4 — skip (Unwind/SEH handler)
**Current doc:** docs/08-file-formats.md (line 4774)
**Issues found:** N/A — SEH unwind handler, no deep validation needed
**Details:** Unwind_0059d4f4 — 8 bytes, calls FUN_0059a5e9. Doc correctly identifies as SEH unwind helper.

---

### 3980. FUN_0046CD20 — no issues
**Current doc:** docs/08-file-formats.md (line 6613)
**Issues found:** none
**Details:** Doc "CopyProfileIconBMP" matches source (IDA Hex-Rays): reads directory from this[57] or defaults, builds "profileicon.bmp" path, file search via sub_497C40, existence check via sub_497AD0, CopyFileA(bFailIfExists=1), UI texture creation via dword_7CD8C0 vtable[28](17), texture init via sub_477640/sub_477680, UI reload via sub_568540/sub_566650, reset via sub_4B0770(0), finalize via vtable+56. All verified.

---

### 3981. FUN_00417F60 — no issues
**Current doc:** docs/09-track-system.md (line 172)
**Issues found:** none
**Details:** Doc "Track Name → Display ID Lookup" matches source: uses scene array (DAT_008ac490, stride 0x18c), 20+ nested FUN_00566810 string compares returning track display IDs via formula `(-(uint)(param_4 != '\0') & 0xffffffed) + 0x6c` (resulting IDs 0x69-0x8f approx). Lookup table only. Gated by DAT_007d0308, DAT_007cf3c8. Verified.

---

### 3982. FUN_00462160 — no issues
**Current doc:** docs/09-track-system.md (line 731)
**Issues found:** none
**Details:** Doc "Network Filter/Sort (numplayers/mapname/hostname)" matches source: if param_3 non-zero toggles flag at param_1+0xc4, clamps DAT_007d1020 between DAT_007d1028/DAT_007d102c, calls FUN_00461fc0, dispatches on DAT_007d1020 (1=default, 2=mapname, 3=numplayers, default=hostname). Strings "numplayers", "mapname", "hostname" confirmed in source. All verified.

---

### 3983. FUN_0040C650 — no issues
**Current doc:** docs/09-track-system.md (line 1185)
**Issues found:** none
**Details:** Doc "Camera View Assignment (In-Car vs Chase)" matches source: if param_2 == player target (from (&DAT_007c54f0)[DAT_007c54e4] + 0x4894 = TeamID), calls FUN_0040cde0 with queued mode. Else switch on param_1+0xc (0/1/2 → call FUN_0040c610 reset, else set -1). If mode 3 + player flag: assign 2 (in-car) or 5 (director). Calls FUN_0040cde0, FUN_0040c610 as documented.

---

### 3984. FUN_00475920 — no issues
**Current doc:** docs/09-track-system.md (line 1502)
**Issues found:** none
**Details:** Doc "Scene Load and Name Match" matches source: calls vtable+0x1c on DAT_007cd8c0 with arg 3, gets entry name via FUN_0048d360/FUN_004693e0, iterates scene linked list at param_1+0xe8 (count at +0xf4/+0xf8), compares names for match via byte-by-byte comparison (unicode-style 2-byte stride). Globals DAT_007cd8c0 confirmed. Calls FUN_0048d360, FUN_004693e0 verified.

---

### 3985. FUN_00461DB0 — no issues
**Current doc:** docs/09-track-system.md (line 1750)
**Issues found:** none
**Details:** Doc "Session State Check Wrapper" matches source: calls FUN_00461cd0(), returns (result != 0). 11-byte trivial wrapper. Verified.

---

### 3986. FUN_004F3090 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 255)
**Issues found:** none
**Details:** Doc "Fender/Aero Setup Section Reader" matches source: reads FenderCenter (sets active flag if present), FenderDragParams, FenderLiftParams, FenderSideways, FenderFlareRange/Setting via FUN_00565aa0. Struct offsets: +0x00 active, +0x04-0x14 drag (3 doubles), +0x1c-0x2c lift (3 doubles), +0x34 sideways, +0x3c-0x4c center (3 doubles), +0x54 flare setting. Strings FenderCenter, FenderDragParams, FenderLiftParams, FenderSideways, FenderFlareRange, FenderFlareSetting confirmed.

---

### 3987. FUN_00433ED0 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 834)
**Issues found:** none
**Details:** Doc "Validate Vehicle Configuration File" matches source: calls FUN_0042bc10 config check, reads vehicle file from DAT_007c54e8+0x4898, sets DAT_007c56c4 = DAT_007d0450 (CostDisplayMode backup), calls FUN_0042ed70, opens file via FUN_004f4270, falls back on failure (sets DAT_007c56c0=0). Calls FUN_0042bc10, FUN_0042ed70, FUN_004f4270, FUN_0042ebc0, FUN_00430f00, FUN_00566650, FUN_00568b00 verified.

---

### 3988. FUN_0049B8F0 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 1245)
**Issues found:** none
**Details:** Doc "Engine/Rev Value Accessor" matches source: 12-byte function returning `*(undefined4 *)(DAT_007c54e0 + 0x39fc)`. Reads value from PlayerVehiclePtr+0x39fc. Global DAT_007c54e0 confirmed.

---

### 3989. FUN_004B0C00 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 1485)
**Issues found:** none
**Details:** Doc "Vehicle Setup Default Copy" matches source: copies 13 parameter blocks from offsets 0x496c-0x49a4 (template) to various runtime offsets via FUN_0047f1f0 calls. Clamps gearing (0x275c) between (0x2764, 0x2768) min/max. Clamps speed (0x2858) between (0x2860, 0x2864). Initializes diff lock (0x248c) with inbound check against (0x2494, 0x2498). Calls FUN_00464720, FUN_004646c0, FUN_0047f1f0 verified.

---

### 3990. FUN_004D6AE0 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 1966)
**Issues found:** none
**Details:** Doc "Vehicle Suspension Force Helper" matches source: computes `((param_1+0x118 + DAT_0059eac8) × param_2 × DAT_0059eb40 × (param_1+0x40)) + (param_1+0x38)`. All doubles confirmed from source. Globals DAT_0059eac8, DAT_0059eb40 verified.

---

### 3991. FUN_0047A080 — no issues
**Current doc:** docs/10-vehicle-physics.md (line 2427)
**Issues found:** none
**Details:** Doc "Parameter value clamping across array" matches source (IDA Hex-Rays): calls sub_466910 (init), gets v2 from dword_7CD8C0 vtable[28](8), checks this[256] flag, gets value via vtable+180, validates via sub_490190, iterates array at 0x7D1448 stride 27 floats (108 bytes), clamps to [v3[2], v3[3]], ends at flt_7D17A8. Globals dword_7CD8C0, unk_7D1448, flt_7D17A8 confirmed.

---

### 3992. FUN_004B4B50 — no issues
**Current doc:** docs/17-physics-collision.md (line 161)
**Issues found:** none
**Details:** Doc "Collision Object List Management" matches source: manages 4 linked lists at param_1+0x70 (stride 4 ints), counts at +0x7c. Finds min distance (1e38f start), removes objects within _DAT_005acd0c tolerance of minimum. Creates tree nodes via operator_new(0xc), calls FUN_004b42e0 (collision response) and FUN_004bb490 (cleanup). Frees via FUN_00582290/FUN_00587bcf. Returns count. Calls FUN_004bab20, FUN_004bac20, FUN_004b42e0, FUN_004bb490, FUN_004ba790, FUN_00582290, FUN_00587bcf verified.

---

### 3993. FUN_0051D247 — no issues
**Current doc:** docs/17-physics-collision.md (line 696)
**Issues found:** none
**Details:** Doc "Grid Occupancy Bounding Box Scan" matches source: scans 2D grid of shorts for non-zero cells. Grid accessed via `*(int *)(*(int *)(in_EAX + 0x1a4) + 0x18)` indirection. Grid cells are shorts with stride 0x20 (32) per row. Scans from center outward in 6 directions, finds first non-zero cell, shrinks bounding box. Computes weighted squared distance `(width_Y*8)^2+(width_Z*12)^2+(width_X*16)^2`. Counts non-zero cells. Stores results in unaff_ESI[6] and [7]. All verified.

---

### 3994. FUN_0044E030 — no issues
**Current doc:** docs/17-physics-collision.md (line 998)
**Issues found:** none
**Details:** Doc "Collision Sound Unregister (DAT)" matches source: 12-byte leaf calling FUN_00587b3e(&DAT_0044e040). Unregisters callback. Verified.

---

### 3995. FUN_0044E810 — no issues
**Current doc:** docs/17-physics-collision.md (line 1347)
**Issues found:** none
**Details:** Doc "Thunk" matches source: delegates to FUN_00587b3e(&PTR_LAB_0044e820). 12-byte leaf. No entry needed — correct classification.

---

### 3996. FUN_0044C680 — no issues
**Current doc:** docs/17-physics-collision.md (line 1722)
**Issues found:** none
**Details:** Doc "Spatial Node Init (index 2, radius -1.0)" matches source: sets DAT_007cca44=2, zeros _DAT_007cca48, sets _DAT_007cca4c=0xbf800000 (-1.0f), zeros _DAT_007cca50. All verified.

---

### 3997. FUN_0044E930 — no issues
**Current doc:** docs/17-physics-collision.md (line 2039)
**Issues found:** none
**Details:** Doc "Thunk" matches source: delegates to FUN_00587b3e(&DAT_0044e940). 12-byte leaf. Correct classification.

---

### 3998. FUN_0044DCA0 — no issues
**Current doc:** docs/17-physics-collision.md (line 2432)
**Issues found:** none
**Details:** Doc "CollisionStateInit_32" matches source: initializes collision system state block at DAT_007ccea0 with type 0x32, zeros 5 following fields (_DAT_007ccea4 through _DAT_007cceb4). All verified.

---

### 3999. FUN_00455E50 — no issues
**Current doc:** docs/17-physics-collision.md (line 2771)
**Issues found:** none
**Details:** Doc "Collision Global Update Broadcast" matches source: calls FUN_004537b0((float)_DAT_008afe90) (push global cooling rate into collision system), calls FUN_00455bd0 (update). Global DAT_008afe90 (EngineCoolingRate) confirmed. Calls FUN_004537b0, FUN_00455bd0 verified.

---

### 4000. FUN_0044EAB0 — no issues
**Current doc:** docs/17-physics-collision.md (line 3104)
**Issues found:** none
**Details:** Doc "Collision Resource Release +A0" matches source: calls FUN_00587b3e(&DAT_0044eac0). 12-byte leaf. Correct.

---

### 4001. FUN_0044DE20 — no issues
**Current doc:** docs/17-physics-collision.md (line 3400)
**Issues found:** none
**Details:** Doc "Collision global init (group 0x36)" matches source: sets DAT_007cce40=0x36 (54), zeros _DAT_007cce44 through _DAT_007cce54 (5 fields). All verified.

---

### 4002. FUN_0044C5F0 — no issues
**Current doc:** docs/17-physics-collision.md (line 3676)
**Issues found:** none
**Details:** Doc "Collision Init Delegator (0xC5F0)" matches source: calls FUN_00587b3e(&LAB_0044c600). 12-byte leaf. Verified.

---

### 4003. FUN_004584C0 — no issues
**Current doc:** docs/17-physics-collision.md (line 3992)
**Issues found:** none
**Details:** Doc "CollisionResponseFilter (contact velocity resolution)" matches source: computes relative velocity = ABS(v3-v4)+ABS(v1-v2), scales by param_1+0xa4 (RestitutionFactor) × param_5, compares against epsilon (_DAT_0059e440). If below threshold: computes ratio, clamps to 1.0 (0x3f800000), applies impulse via FUN_00567030/FUN_00567580. Else: copies source to output. Calls FUN_00455f90, FUN_00455fd0, FUN_00567030, FUN_00567580, FUN_00567010 verified. Globals _DAT_0059e440, _DAT_0059e43c confirmed.

---

### 4004. FUN_0044CAA0 — no issues
**Current doc:** docs/17-physics-collision.md (line 4243)
**Issues found:** none
**Details:** Doc "InitMouseAbsAxisX" matches source: sets DAT_007cd148=0x66 (102), zeros _DAT_007cd14c and _DAT_007cd150, sets _DAT_007cd154=0x3f800000 (1.0f). All verified.

---

### 4005. FUN_0044DE50 — no issues
**Current doc:** docs/17-physics-collision.md (line 4446)
**Issues found:** none
**Details:** Doc "Collision Callback Registration (&PTR_LAB_0044de60)" matches source: calls FUN_00587b3e(&PTR_LAB_0044de60). 12-byte leaf. Verified.
