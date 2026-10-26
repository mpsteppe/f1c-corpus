# Cross-Validation Report: docs/08-file-formats.md + docs/09-track-system.md

Date: 2026-07-15
Validator: Worker C (batch 3)
Method: For each function, read .c source, compare against doc entry, return PASS/FAIL with reasoning.

---

## 1. FUN_004C1E80 — Game Options Writer (Save)

**Doc source:** docs/08-file-formats.md (lines 254-260)
**Doc content:** Companion to FUN_004c18b0 reader. Writes career stats + game options struct to file. Same field offsets as reader. Save function.
**.c source:** decompiled_all\0x004c1e80__FUN_004c1e80.c (135 lines)
**Strings present:** CAREERSEASON, PLAYERTRACKSTAT, ABORTEDSEASONS, TOTALLAPS, TOTALRACES, TOTALRACESWITHAI, TOTALPOINTSSCORED, TOTALCHAMPIONSHIPS, TOTALWINS, TOTALPOLES, TOTALLAPRECORDS, AVGSTARTPOSITION, AVGFINISHPOSITION, AVGRACEDISTANCE, AVGOPPONENTSTRENGTH, MECHFAIL_rate, RACECOND_*, GAMEOPT_*

**Analysis:** Source writes all career stats (aborted seasons, total laps, races, points, championships, wins, poles, lap records), averages (start/finish position, race distance, opponent strength), mechanical failure rate, race conditions (reconnaissance, walkthrough, formation, flag rules, weather, timescaled), and all GAMEOPT fields (qualify laps, race laps, race time, race length, opponents, fuel mult, tire mult, speed comp). Matches "career stats + game options writer" description. Also contains file-handle iteration loop and linked-list node insertion at lines 82-122 (career season / player track stat nodes) — not mentioned in brief doc entry.

**Verdict: PASS** — doc correctly identifies save function and struct purpose. Minor omission: doesn't mention linked-list node insertion for career/player track stat sections.

---

## 2. FUN_004C11E0 — Session Config Reader (SceneOrder)

**Doc source:** docs/08-file-formats.md (lines 586-605)
**Doc content:** Reads race weekend config from SeasonRaces section. Reads SceneOrder, QualifyLaps (+0xb130), QualifyTime (+0xb134), RaceLaps (+0xb138), RaceTime (+0xb13c). If param_2 < CurrentRace (+0xb148), stores track data at +0xb140 from +0xaf84 array (stride 4).
**.c source:** decompiled_all\0x004c11e0__FUN_004c11e0.c (71 lines)

**Analysis:** Source exactly matches:
- Line 11: `FUN_00568210(s_SceneOrder_005d28b4)` — SceneOrder read
- Lines 22-31: QualifyLaps → +0xb130
- Lines 32-39: QualifyTime → +0xb134  
- Lines 41-48: RaceLaps → +0xb138
- Lines 50-57: RaceTime → +0xb13c
- Line 59: `param_2 < *(int *)(param_1 + 0xb148)` — CurrentRace gate
- Line 60: `*(int *)(param_1 + 0xaf84 + param_2 * 4)` → +0xb140

All struct offsets verified. All field names from string constants match.

**Verdict: PASS** — doc entry matches source precisely.

---

## 3. FUN_00467F90 — HTML Output Section Processor

**Doc source:** docs/08-file-formats.md (lines 1048-1060)
**Doc content:** Walks linked list at param_1+0xf8 via param_1+0x100 cursor. Checks section type strings against `<HEADER>` and `<HEADER2>`. Forwards content to FUN_00486f30 (HTML output writer). Strings: <HEADER2>, <HEADER>.
**.c source:** decompiled_all\0x00467f90__FUN_00467f90.c (76 lines)

**Analysis:** Source matches:
- Line 12: `puVar3 = *(undefined4 **)(param_1 + 0xf8)` — linked list start
- Line 13: `*(undefined4 **)(param_1 + 0x100) = puVar3` — cursor
- Lines 20-24: Frees existing list at param_1+0x44..+0x50
- Line 37: `FUN_00588410(puVar1, s_<HEADER>_005c6720)` — HEADER check
- Line 57: `FUN_00588410(puVar1, s_<HEADER2>_005c6714)` — HEADER2 check
- Line 49: `FUN_00486f30(puVar1, 0xffffffff)` — forwards content
- Loop continues until list end

Doc also notes list cleanup at +0x44..+0x50 is performed before iteration. The doc correctly captures all major logic.

**Verdict: PASS** — doc entry accurately describes linked list traversal, section type comparison, and HTML output dispatch.

---

## 4. FUN_004057F0 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 149)
**Doc content:** `| 0x004057f0 | 39 | math_util | short computation | no | -- |`
**.c source:** analyzed\0x004057f0__FUN_004057f0.c (38 lines)

**Analysis:** Source is an object constructor/initializer:
- Line 14: `*param_1 = &PTR_FUN_0059e490` — vtable pointer assignment
- Lines 12-13: Zero and sentinel init
- Lines 15-19: Copies param_2 string pointer, copies param_2[2], param_2[3]
- Lines 22-34: Sets multiple fields including float constants (0x3c23d70a ≈ 0.01, 0x3f79999a ≈ 0.975, 0x3f000000 = 0.5, 0x472c4400 = 40000.0)
- No computation, not math_util

"Short computation" is incorrect. This is a struct/object constructor with vtable pointer, string references, and float constant initialization.

**Verdict: FAIL** — triage "short computation / math_util" is wrong. Function is an object constructor with vtable initialization and parameter copying.

---

## 5. FUN_004328F0 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 650)
**Doc content:** `| 0x004328f0 | 26 | physics_math | physics computation | no | -- |`
**.c source:** analyzed\0x004328f0__FUN_004328f0.c (26 lines)

**Analysis:** Source is a null-terminated string length / empty check:
```c
pcVar2 = *(char **)(*param_1 + 8);
// ... strlen loop ...
return '\x01' - (iVar3 != -2);  // returns 1 if non-empty, 0 if empty
```
Loads a string pointer from param_1 indirection, counts characters until null, returns boolean. No math, no physics, no computation.

"Physics computation" is completely wrong. This is a string emptiness test.

**Verdict: FAIL** — triage "physics computation / physics_math" is completely wrong. Function is a string empty-check returning boolean.

---

## 6. FUN_004B09A0 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 2406)
**Doc content:** `| 0x004b09a0 | 11 | game_logic | vehicle state + game state access | yes | -- |`
**.c source:** analyzed\0x004b09a0__FUN_004b09a0.c (77 lines)

**Analysis:** Source performs:
- `FUN_004b0180` — string/path copy
- `FUN_00568620(0x200)` — directory creation  
- Path processing loop: finds backslashes, calls _strncpy + `FUN_00589671` (mkdir)
- `FUN_004b01b0` — restore string
- `DAT_007cb710` flag check → calls `FUN_004ae750` (retail/dev mode dispatch)
- `DAT_008ac488 > 0` → `FUN_004c54f0` (profile/save operations)
- `DAT_008ac390 > 0` → renderer scene calls: `FUN_004c4080`, `FUN_00566650`, `FUN_00415730`
- `FUN_004add50`, `FUN_004ade20`, `FUN_004331a0`, `FUN_004b0770`

This is a directory creation + save system initialization function. It creates directory paths and initializes save/load subsystems. "Vehicle state + game state access" is imprecise — the function does access game state (DAT globals) but its primary purpose is filesystem directory/save system setup, not vehicle state.

**Verdict: FAIL** — triage "vehicle state + game state access" is imprecise. Function is primarily filesystem directory creation + save subsystem init. Minor game state reads but not vehicle state.

---

## 7. FUN_004CDBF0 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 2913)
**Doc content:** `| 0x004cdbf0 | 10 | game_logic | references game state | yes | -- |`
**.c source:** analyzed\0x004cdbf0__FUN_004cdbf0.c (38 lines)

**Analysis:** Source performs:
- String copy from `*param_1` into local buffer
- `FUN_005897ca(local_100, &DAT_005d251c)` — tokenize/compare against delimiter
- Loop: `FUN_00587c20(param_2, iVar2)` — string comparison/matching against param_2
- Returns 1 on match, 0 on no match

This is a string token matching function — iterates through tokens in a delimited string, searching for param_2. "References game state" is vague but not incorrect (string data could represent game state config). The function itself is a utility for string/token matching.

**Verdict: PASS (weak)** — "references game state" is vague but not demonstrably wrong. Function is a string token matcher that could process game config data. However, a more precise description would be "string token/pattern matcher."

---

## 8. FUN_004A1B90 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 2308)
**Doc content:** `| 0x004a1b90 | 22 | game_logic | references game state | yes | -- |`
**.c source:** analyzed\0x004a1b90__FUN_004a1b90.c (103 lines)

**Analysis:** Source performs:
- `FUN_00566e20()` — seed/get tick count
- `FUN_00566cc0(local_180, 0x180)` — read line from stream
- `FUN_00596c80(local_180, &DAT_005c30b8, 2)` — strip comment markers (likely "//")
- Strips null markers via `FUN_00587c20`
- Compares against `param_1[1]` string prefix
- If match: strips trailing backslash-quotes
- Calls function pointer: `(**(code **)(*param_1 + 4))(parsed_arg)`

This is a line-based command/script parser — reads lines, strips comments, matches against a prefix, parses quoted arguments, dispatches to a handler function. "References game state" is vague — the function reads a stream and dispatches to callbacks; game state access depends on the callback. It's more accurately a "line-based command dispatcher."

**Verdict: PASS (weak)** — "references game state" is too vague but not disproven by source. Function is a line-based command parser that dispatches to virtual handlers. Could process game state commands.

---

## 9. FUN_00592AF4 — Environment Variable Table Parser

**Doc source:** docs/08-file-formats.md (lines 2494-2501)
**Doc content:** Category: System/Startup. Environment variable table parser — parses GetEnvironmentStrings output into array of malloc'd strings, handles "=" separator for variable names, frees original buffer.
**.c source:** analyzed\0x00592af4__FUN_00592af4.c (53 lines)

**Analysis:** Source matches:
- Iterates `DAT_008d3eb4` (environment block pointer)
- Counts entries skipping those starting with '='
- `_malloc(iVar5 * 4 + 4)` — allocates pointer array
- For each entry: `_malloc(sVar2 + 1)`, copies via `FUN_0058fca0`
- `FUN_0058aa6f(DAT_008d3eb4)` — frees original block
- Sets `DAT_008d5a48 = 1` — init flag

All details verified. Doc correctly identifies GetEnvironmentStrings parsing, malloc allocation for string array, '=' separator skipping, and original buffer free.

**Verdict: PASS** — doc entry accurately describes the environment variable table parser.

---

## 10. FUN_00592C46 — String Tokenizer/Splitter

**Doc source:** docs/08-file-formats.md (lines 3046-3053)
**Doc content:** Size: 436 bytes (152 lines). Category: Utility — String Split. Purpose: String tokenizer/splitter with delimiters. Game Logic: Text/config parsing.
**.c source:** analyzed\0x00592c46__FUN_00592c46.c (152 lines)

**Analysis:** Source implements a sophisticated command-line style tokenizer:
- Quoted string handling (0x22 double-quote)
- Escape character handling (0x5c backslash)
- Whitespace/tab delimiters (0x20, 0x09)
- Character classification via `DAT_008d47e0` table (bit 4 = escape indicator)
- Backslash-quote escaping with even/odd counting logic
- Output: token count in param_4, char count in param_5, pointer array in param_2

Doc briefly summarizes as "string tokenizer/splitter with delimiters" which is correct. The full source confirms complex tokenizing with quote/escape handling beyond basic string splitting.

**Verdict: PASS** — doc correctly identifies as string tokenizer for text/config parsing.

---

## 11. FUN_00510012 — Image Format Stream Decoder

**Doc source:** docs/08-file-formats.md (lines 3549-3579)
**Doc content:** Parses binary image format from byte stream with callback-based buffer refill. Reads 2-byte header. Parses width/height/component count/pixel count. Validates width*height*3 + 8 == pixelCount. Iterates pixel data. Dispatches via virtual function calls.
**.c source:** analyzed\0x00510012__FUN_00510012.c (179 lines)

**Analysis:** Source confirms:
- Buffer structure at puVar3[3] (refill callback) — ✅
- Reads 2-byte header (bVar1, bVar2) — ✅
- Width at unaff_ESI[0x30], height at unaff_ESI[7], components at unaff_ESI[6], pixelCount at unaff_ESI[8] — ✅
- Validation: `(uint)bVar1 * 0x100 + (uint)bVar2 + -8 != unaff_ESI[8] * 3` — doc says "width*height*3 + 8 == pixelCount" but actual check is `headerValue - 8 != pixelCount * 3` (equivalent: `headerValue == pixelCount * 3 + 8`). The doc's formulation is dimensionally confusing (pixelCount = width*height but equation uses pixelCount on both sides). Minor doc formatting issue.
- Per-pixel loop reads color index (1 byte), nybbles (params), extra byte — ✅
- Writes to *unaff_ESI at +0x18, +0x1c, +0x20, +0x24 — ✅
- Virtual dispatch with opcodes (99=decode at +0x14) — ✅
- Sets flag at unaff_ESI[100] + 0x51 — ✅

**Verdict: PASS** — entry accurately describes the image stream decoder. Minor validation formula formatting issue in doc but semantically correct.

---

## 12. FUN_0059B208 — (triage-only entry, conflicting)

**Doc source:** decompiled_full_index_final.md (lines 5894 and 7049)
**Doc content:** Two conflicting entries:
- Line 5894: `| 0x0059b208 | 27 | unknown | -- | no | -- |`
- Line 7049: `| 0x0059b208 | 26 | FileSystem | Single byte write via stream | File I/O |`
**.c source:** analyzed\0x0059b208__FUN_0059b208.c (26 lines)

**Analysis:** Source truncates param_1 to a single byte (CONCAT13), then passes it as a 1-byte field to `FUN_0059b092` along with a return buffer. Reads back 16 bits from result. Sentinel check: if param_1 == -1, returns 0xffffffff.

This is a byte-level I/O function — likely a single-byte write followed by a 16-bit result read. The "FileSystem / Single byte write via stream" description is the more specific one.

**Verdict: PASS (with note)** — conflicting triage entries, but the FileSystem description ("Single byte write via stream") matches source better than "unknown." Source confirms byte-level I/O operation.

---

## 13. FUN_0059A3A9 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (lines 5840 and 7012)
**Doc content:** Two entries:
- Line 5840: `| 0x0059a3a9 | 25 | unknown | -- | no | -- |`
- Line 7012: `| 0x0059a3a9 | 24 | FileSystem | Stream creation with flag init | File I/O |`
**.c source:** analyzed\0x0059a3a9__FUN_0059a3a9.c (24 lines)

**Analysis:** Source:
- `*(param_1 + 0x2c) = 0` — clear flag
- `*(param_1 + 0x28) = param_2` — store stream target
- `FUN_0059b208(0x20)` — allocate 32-byte buffer, store at +0x30
- `FUN_0059a948()` — stream init call
- Conditional: if param_2 == 0 → `FUN_0059a5fe(flags | 4, 0)` — set error flag
- Conditional: if param_3 != 0 → `FUN_0059a8fa()` — more init

"Stream creation with flag init" accurately describes this function. The 0x20 byte allocation via FUN_0059b208, target storage, flag initialization pattern all confirm.

**Verdict: PASS** — "Stream creation with flag init" matches source.

---

## 14. FUN_004726C0 — (triage-only entry)

**Doc source:** decompiled_full_index_final.md (line 1492)
**Doc content:** `| 0x004726c0 | 18 | math_util | short computation | no | -- |`
**.c source:** analyzed\0x004726c0__FUN_004726c0.c (20 lines)

**Analysis:** Source is a constructor/initializer:
```c
FUN_00466d60(1);                          // global state increment
*param_1 = &PTR_FUN_005a2040;              // vtable pointer
param_1[199] = &DAT_007cff84;              // game state ref
param_1[0xc9] = 3; param_1[0xca] = 1;     // state ints
param_1[0xcb] = 1; param_1[0xcc] = 1;     // flags
param_1[0xce] = 0xffffffff;                // sentinel
param_1[0xcd] = 0x103;                     // mode flag
return param_1;
```

No computation whatsoever. Vtable pointer, game state reference, integer/flag initialization. "Short computation / math_util" is completely wrong.

**Verdict: FAIL** — triage "short computation / math_util" is wrong. Function is object/struct constructor with vtable pointer and state flag initialization.

---

## 15. FUN_0059C854 — (triage-only entry, SEH unwind)

**Doc source:** decompiled_full_index_final.md (lines 6010 and 7131)
**Doc content:** Two entries:
- Line 6010: `| 0x0059c854 | 13 | crt_util | -- | no | -- |`
- Line 7131: `| 0x0059c854 | 12 | Exception/Unwind | SEH unwind cleanup call | Unwind cleanup |`
**.c source:** analyzed\0x0059c854__Unwind_0059c854.c (12 lines)

**Analysis:** Source (named `Unwind_0059c854`): single call to `FUN_00581a80()`. This is an SEH cleanup handler — the file name itself confirms "Unwind" prefix. No computation, just a cleanup dispatch.

"SEH unwind cleanup call" is correct. Earlier triage "crt_util" is superseded by the more specific Exception/Unwind classification.

**Verdict: PASS** — "SEH unwind cleanup call" matches the single-call cleanup dispatcher. Source confirms unwind handler pattern.

---

## 16. FUN_005020BF — (no doc entry found)

**Doc source:** No entry found in any `docs/` file.
**.c source:** analyzed\0x005020bf__sub_5020BF.c (20 lines, IDA Hex-Rays)

**Analysis:** Source (IDA Hex-Rays decompilation):
```c
unsigned int __cdecl sub_5020BF(int a1, void *a2, unsigned int a3) {
    v3 = *(_DWORD *)(a1 + 84);          // get stream buffer struct
    if (a3 > *(_DWORD *)(v3 + 4))        // bounds check
        sub_511869(a1, "read error");     // error handler
    qmemcpy(a2, *(const void **)v3, a3); // copy data
    *(_DWORD *)v3 += a3;                 // advance buffer ptr
    *(_DWORD *)(v3 + 4) -= a3;           // decrement remaining
    return a3;
}
```

Bounded buffer read with overflow check. Reads a3 bytes from stream v3 into a2, advances pointer, decrements remaining count. Reports "read error" on overflow. Not a FUN_ but an IDA-discovered function.

**Verdict: FAIL** — no documentation entry exists. Function is a bounded buffer read with error checking, not documented anywhere.

---

## 17. FUN_004CA480 — Material Shader/Reaction Effect Parser

**Doc source:** docs/09-track-system.md (lines 25-45)
**Doc content:** Parses .MTS file particle/shader material effects. Reads "REACTION" token, compares against 14 smoke/particle type names. Assigns type code to param_1+4. Parses SCALE, GROWTH, GROWTHVEL, DURATION, ASDENVELOPE, POWER, RAMPSPEED, OFFSETVEL. RAMPSPEED clamped. ASDENVELOPE scaled by DAT_0059e8b4 for type 5 (SPRAY). Allocates 0xb0-byte D3D material at param_1+0x50. Parses VERTEX, PIXEL, CHROMA, COLOR, DESTBLEND, ASRCBLEND shader sections.
**.c source:** decompiled_all\0x004ca480__FUN_004ca480.c (539 lines)

**Analysis:** Comprehensive match:
- Line 26: Reads "REACTION" via FUN_00565520
- Lines 33-256: All 14 type comparisons (WHITESMOKE=1, BLUESMOKE=2, BLACKSMOKE=3, FLAMES=4, SPRAY=5, SOFTSKID=7, WETSKID=8, GROOVE=9, WETGROOVE=10, PARTICLE=0xb, SPARK=0xc, + two unnamed 6 and 0xd)
- Line 40: `*(undefined4 *)(param_1 + 4) = 0` — type code assignment
- Lines 259-288: SCALE, GROWTH, GROWTHVEL, DURATION, ASDENVELOPE, POWER, RAMPSPEED, OFFSETVEL parsing
- Lines 279-287: RAMPSPEED clamping (below DAT_0059e43c → 1.0; above DAT_0059eae0 → FLT_MAX)
- Lines 267-274: ASDENVELOPE scaling by DAT_0059e8b4 for type 5
- Lines 314-322: Allocates 0xb0-byte D3D material at +0x50
- Lines 324-331: Render state flags at +0x20, +0x58, +0x5c, +0x60, +0x64, +0x70, +0x38, +0x90
- Lines 410-536: VERTEX, PIXEL, CHROMA, COLOR, DESTBLEND, ASRCBLEND section parsers

Doc also notes calls to FUN_004cad30 (color parser), FUN_004cada0 (blend mode parser), FUN_00557350 (D3D material ctor) — confirmed in source at lines 465, 470, 320.

**Verdict: PASS** — doc entry comprehensively and accurately describes the .MTS material shader parser. All struct offsets, type names, field parsing, and render state initialization verified.

---

## 18. FUN_00419C50 — Per-Driver Race Commentary

**Doc source:** docs/09-track-system.md (lines 504-530)
**Doc content:** Generates per-driver race commentary. Checks DAT_007d0308 (race active) and DAT_007cf3c8 (track condition). Only for finished drivers (+0x4064 == 1) with no previous message (+0x4070 == 0). Player vs non-player branching. Commentary format IDs 0x9d-0x105. Calls FUN_004144d0/FUN_004144f0, FUN_00418560, FUN_004c2850, FUN_004c11d0, FUN_004c1190, FUN_004c13a0.
**.c source:** decompiled_all\0x00419c50__FUN_00419c50.c (203 lines)

**Analysis:** Source confirms:
- Line 15: `DAT_007d0308 != 0` (race active) and `DAT_007cf3c8 != DAT_0059e440` (track condition)
- Line 17: `*(int *)(param_1 + 0x4064) == 1` (finished) && `*(int *)(param_1 + 0x4070) == 0` (no message)
- Line 19: Team ID match check: `*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_1 + 0x4894)`
- Lines 20-131: Player branch with championship clinch logic and position-based commentary
- Lines 186-197: Non-player branch (positions 1, 2-5)
- Line 132: `FUN_004144f0(uVar5, ...)` — commentary text dispatch
- Lines 136-183: Championship clinch check via FUN_004c2850, FUN_004c11d0, FUN_004c1190

All format IDs referenced: 0x9d, 0x9e, 0x9f, 0xa0-0xb1, 0x104, 0x105 match source constants.

**Verdict: PASS** — doc entry accurately describes the per-driver commentary function. All conditions, field offsets, branching logic, and format IDs verified.

---

## 19. FUN_00462C00 — (no full doc entry in 09-track-system.md)

**Doc source:** No full entry in docs/09-track-system.md. Referenced in docs/00-source-tree.md as "Send Join Request to host" (line 439). Referenced in docs/12-globals-reference.md for DAT_005C5C28 (HostPortKey).
**.c source:** decompiled_all\0x00462c00__FUN_00462c00.c (41 lines)

**Analysis:** Source (NetComm.cpp from assert string):
- `FUN_00563e80()` — get network session
- `FUN_00564530(0)` — get local IP address
- `FUN_0058815f(&local_50, "%s:%d", ip)` — format "IP:port"
- `DAT_007c569c != 5` guard → debug log: "Sending Join Request to %s"
- `*(*param_1 + 0x378) = 0` — clear session flag
- `FUN_00462ce0(&local_50, param_3)` — send join request to host

Source confirms network multiplayer join request sending. The "Send Join Request to host" description in 00-source-tree.md matches. However, no proper documentation entry exists in 09-track-system.md.

**Verdict: FAIL** — no full doc entry in docs/09-track-system.md despite being listed for that file. 00-source-tree.md reference "Send Join Request to host" is accurate but insufficient.

---

## Summary Table

| # | Function | Doc Source | Verdict | Issue |
|---|----------|-----------|---------|-------|
| 1 | FUN_004C1E80 | 08-file-formats.md | PASS | Minor: linked-list insertion not mentioned |
| 2 | FUN_004C11E0 | 08-file-formats.md | PASS | Precise match |
| 3 | FUN_00467F90 | 08-file-formats.md | PASS | Accurate |
| 4 | FUN_004057F0 | triage index only | FAIL | "short computation" wrong; is constructor |
| 5 | FUN_004328F0 | triage index only | FAIL | "physics computation" wrong; is string empty check |
| 6 | FUN_004B09A0 | triage index only | FAIL | "vehicle state access" imprecise; is dir creation + save init |
| 7 | FUN_004CDBF0 | triage index only | PASS (weak) | Vague "references game state" but not wrong |
| 8 | FUN_004A1B90 | triage index only | PASS (weak) | Vague "references game state" but not wrong |
| 9 | FUN_00592AF4 | 08-file-formats.md | PASS | Precise match |
| 10 | FUN_00592C46 | 08-file-formats.md | PASS | Correct tokenizer identification |
| 11 | FUN_00510012 | 08-file-formats.md | PASS | Minor validation formula formatting issue |
| 12 | FUN_0059B208 | triage index only | PASS (note) | Conflicting entries; FileSystem desc more accurate |
| 13 | FUN_0059A3A9 | triage index only | PASS | "Stream creation with flag init" accurate |
| 14 | FUN_004726C0 | triage index only | FAIL | "short computation" wrong; is constructor |
| 15 | FUN_0059C854 | triage index only | PASS | "SEH unwind cleanup call" correct |
| 16 | FUN_005020BF | no entry found | FAIL | No documentation exists; is bounded buffer read |
| 17 | FUN_004CA480 | 09-track-system.md | PASS | Comprehensive match |
| 18 | FUN_00419C50 | 09-track-system.md | PASS | Precise match |
| 19 | FUN_00462C00 | no entry in target doc | FAIL | No full entry in 09-track-system.md |

**Summary:** 11 PASS, 5 FAIL (triage misclassifications), 2 PASS (weak), 1 FAIL (no doc entry)

**Key failures that need correction in CHANGELOG.md:**
1. FUN_004057F0: Wrong triage — is constructor, not math computation
2. FUN_004328F0: Wrong triage — is string empty check, not physics computation
3. FUN_004B09A0: Imprecise triage — is directory creation + save init
4. FUN_004726C0: Wrong triage — is constructor, not math computation
5. FUN_005020BF: No doc entry — needs documentation as bounded buffer read
6. FUN_00462C00: Missing entry in docs/09-track-system.md
