# Cross-Validation Results: docs/06-session-race-logic.md — Batch 1

## FUN_004bc4e0 — PASS
**Reason:** Lap Completion / Penalty Processing doc matches source. Doc correctly describes: param_4 != 0 sector timing branch (line 22), param_4 == 0 lap completion branch (line 56), switch on DAT_007c56a4 (line 88), Race case 7 with DAT_008acf8c lap count check (line 141), formation lap FUN_0042d140(8) (line 146), Ignored Stop/Go Penalty DSQ (line 159), penalty countdown timer loop on param_1[0x10] stride 2 (lines 152-172), half-distance flag DAT_008acfa0 set when lap >= (total+1)/2 (line 174), Qualifying case 5 DSQ logic (lines 98-113), Practice case 0 simple update via FUN_004199e0 (line 90), and FUN_004bc240 standings update (line 184). All globals (DAT_008acf8c, DAT_008acf90, DAT_008acf94, DAT_008acfa0, DAT_007c56a4, DAT_007c56a8, DAT_007ce814) confirmed present in .c.

## FUN_0046bc20 — PASS
**Reason:** Lap Time HTML Formatter doc matches source. Doc correctly describes: checks DAT_005ef9a0[iVar5*0x1230] and DAT_005f0714 validity (line 39), sets param_1+0x178 to -1 on invalid (line 40), calls FUN_00489cb0 HTML buffer reset (line 43), copies driver name from DAT_005f0cf8 (line 44) and team name (line 46), loops laps up to local_23c (lines 53-161), formats time as "%d:%06.3f" (line 63) or "--:--.---" (lines 67-71), computes gap with "%s%d:%06.3f" (line 83), uses FUN_0058815f for formatting and FUN_00489600 for HTML write (line 155). All strings and calls confirmed.

## FUN_004a1200 — PASS
**Reason:** Application Window Init doc matches source. Doc correctly describes: GetDesktopWindow (line 17), WNDCLASSEXA struct at DAT_007ce270 with size 0x30 (line 18), window proc at LAB_004a1560 (line 21), title format "%s v%0.3f" with "F1 Challenge 99-02" and DAT_007c56b0 version (line 30), DAT_005ec4a4 fullscreen flag check (line 31), fullscreen branch: RegisterClassExA "CUBERealtime" (line 33), CreateWindowExA (line 37), ClipCursor (line 44), ShowWindow (line 45), DAT_007ce2e4=1 (line 46). Windowed branch: RegisterClassExA "CUBEApp" (line 61), GetClientRect (line 65), FUN_0059db88 (line 66). Minor: "F1 Challenge 99-02" is window title string, not a registered class — but doc lists it among strings used, which is acceptable.

## FUN_0047f230 — PASS
**Reason:** VehicleArraySearchAndReset doc matches source. Doc correctly describes: outer loop over VehicleCount (DAT_005c329c) stride 0x48c0 (lines 22-47), inner loop over VehicleFileCount (DAT_008ac390) stride 0x424 (lines 28-39), string comparison via FUN_00588410 (line 35), no-match cleanup via FUN_004c78f0(0) (line 42). All calls and strides confirmed.

## FUN_004bb8e0 — PASS
**Reason:** State Reset on Session Condition doc matches source. Doc correctly describes: non-race session check (DAT_007c56a4 < 7, line 8) + vehicle state valid (*(int *)(*param_1 + 13000) == 0/1, line 9), sets 3 floats to -4.0f (param_1[6], [7], [8] = -0x40800000, lines 14-16), calls FUN_004e9ca0 (line 10), always resets counters/flags outside if block (lines 18-23). All confirmed.

## FUN_004d1c40 — PASS
**Reason:** Lap Time Comparison / Position Swap doc matches source. Doc correctly describes: param_4==0 compare mode check (line 20), reads lap times from DAT_005f0774 (lines 24, 33), comparison flags returned (lines 25-27, 34-35), calls FUN_00419690 for swap when new time NOT better (line 38, when fVar2 >= fVar1). All logic confirmed.

## FUN_0042bc40 — PASS
**Reason:** Set Player Vehicle Index (E8) doc matches source. Doc correctly describes: computes DAT_007c54e8 = base season address + param_1 * 0x48c0 (line 10), iterates DAT_007c54f0 array up to 0x68 entries (lines 12-18), sets DAT_007c54e4 = index on first match (line 14). All confirmed.

## FUN_00463f70 — PASS
**Reason:** Session Type Setter doc matches source. Doc correctly describes: reads +0x3fc4 flag (line 32), flag 1 or 2 → DAT_007c56a0=3 race (lines 34-36), other → DAT_007c56a0=2 quali (line 40), formats driver name strings (lines 42-99). Core logic accurate. Doc is lightweight — omits additional logic (DAT_007d0e50 switch, FUN_0045f2a0, FUN_0057a750, etc.) but this is acceptable for a summary entry.

## FUN_0049d320 — PASS
**Reason:** Track/Position Name Formatter doc matches source. Doc correctly describes: reads value via FUN_0049b8f0 (line 13), negative branch looks up from DAT_005ccec4 via FUN_00423a00 (line 15), zero branch looks up from DAT_005c36fc (line 28), copies 3 chars max via _strncpy (lines 24, 37). Globals (DAT_005ec4cc, DAT_005ccec4, DAT_005c36fc) confirmed. Minor omission: positive value branch formats directly via FUN_0058815f (line 41) and FUN_00553070 call (line 43) not mentioned — acceptable for lightweight entry.

## FUN_00595924 — PASS
**Reason:** Triage entry matches source. Category System/IO correct. Description: "File handle table setter — sets file handle in global handle table with bounds (DAT_008d4a20 check line 12) and duplicate check (slot != -1 line 14), handles stdin/stdout/stderr via SetStdHandle (lines 15-27), sets errno on error (lines 33-36)." All confirmed.

## FUN_00553aa0 — PASS
**Reason:** Triage entry matches source. Category Data — Decode correct. Description "RGB color channel extraction with byte packing" consistent with observed behavior: color format dispatch based on *(param_6+0x30)==6 (line 22) or ==5 (line 27) with bitmask shifts (R, G, B extraction), 16-bit vs other depth branching (line 32), function pointer dispatch for pixel processing (lines 33-48). Drawing/rasterization logic present but acceptable under "Color data decode" summary.

## FUN_00581c20 — PASS
**Reason:** Triage entry matches source. Category Data — List correct. Description "Linked-list destruction with vtable release call" accurate: two linked-list traversals (first at param_1[4] lines 27-35, second at *param_1 lines 41-54), nodes freed via FUN_00587bcf, vtable-release call via FUN_0058a5f7(iVar2,0x54,...) at line 47, CloseHandle at line 22, pointer reset at lines 36-39 and 55-58. All confirmed.
