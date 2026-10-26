# Cross-Validation Results: worker_L_batch7

## Functions 4156–4209 (54 total)

---

### FUN_0059BEFD — Exception destructor with flag
**Current doc:** docs/decompiled_full_index_final.md (lines 5918, 7061) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (28 bytes): Calls `exception::~exception(param_1)`. If `(param_2 & 1) != 0`, calls `FUN_00587bcf(param_1)`. Returns `param_1`.
- **Doc line 5918**: category = `math_util` — WRONG. This is an exception class destructor with conditional free (Data/Dtor pattern).
- **Doc line 7061**: category = `Data/Dtor`, algorithm = `Exception destructor with flag` — CORRECT. Second entry properly identifies it.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** `exception::~exception`, `FUN_00587bcf` (conditional free).
- **Moddability:** N/A (CRT exception handling internals).

---

### FUN_00466290 — Struct byte zero-init
**Current doc:** docs/decompiled_full_index_final.md (line 1363) — no full ## FUN_ entry
**Issues found:** triage category misleading
**Details:**
- **Source** (31 bytes): Calls `FUN_004988a0(2)`. Writes 0 to bytes at `param_1 + 0xf4` and `param_1 + 0xf5`.
- **Doc**: category = `math_util`, algorithm = `short computation` — MISLEADING. This is a struct field zero-init (two bytes), not math or computation. Better: `Data/Init | struct field zero-init`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** `FUN_004988a0(2)`.

---

### FUN_00492030 — Brace-matching parser
**Current doc:** docs/decompiled_full_index_final.md (line 1973) + docs/12-globals-reference.md (line 3433)
**Issues found:** triage category mismatch vs globals doc description
**Details:**
- **Source** (124 bytes): Loop calls `FUN_00587c20(&DAT_007cdb70, &DAT_005cc4f8)` and `FUN_00587c20(&DAT_007cdb70, &DAT_005cc4f4)` to compare strings. Uses DAT_005cc4f8 (StringDelimiter_Brace) and DAT_005cc4f4 (Str_UI_CompareToken_CC4F4). Decrements `param_1 + 0x194`. Brace-matching counter: +1 for open-brace match, -1 for close-brace match.
- **Doc line 1973**: category = `unknown`, algorithm = `unidentified` — PARTIALLY CORRECT (not fully analyzed). However, globals doc (line 3433) describes it as "Used in brace-matching parser (FUN_00492030)" — implying known purpose.
- **Inconsistency**: Triage says "unidentified" but globals doc identifies it. Should be `game_logic | brace-matching parser`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Globals:** DAT_007cdb70 (StringCompareBuffer), DAT_005cc4f8 (StringDelimiter_Brace), DAT_005cc4f4 (Str_UI_CompareToken_CC4F4).
- **Calls:** FUN_00491fb0, FUN_00587c20.

---

### FUN_004B54A0 — Linked list traversal with callback
**Current doc:** docs/decompiled_full_index_final.md (line 2525) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (62 bytes): Walks linked list from `param_1 + 0x20`. For each node, calls `FUN_005001f0()`. Advances via `*(int *)(param_1 + 0x28)` at offset +4. Returns success/failure.
- **Doc**: category = `math_util`, algorithm = `arithmetic/comparison` — WRONG. This is a linked list traversal with iteration, not arithmetic. Better: `data_struct | linked list iteration`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** FUN_005001f0 (per-node callback).

---

### FUN_004F6D60 — Count non-null entries in array
**Current doc:** docs/decompiled_full_index_final.md (line 3312) — no full ## FUN_ entry
**Issues found:** triage category imprecise
**Details:**
- **Source** (37 bytes): Counts non-null entries in an array of 5 ints at `param_1[0x10]`. Sets `*param_1 = count`. Returns when null entry encountered or count reaches 5.
- **Doc**: category = `math_util`, algorithm = `arithmetic/comparison` — PARTIALLY OK. It IS comparison-based but better as `data_struct | count non-null entries`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.

---

### FUN_00528F00 — MMX/3DNow! SIMD vector math (likely rsqrt or div)
**Current doc:** docs/decompiled_full_index_final.md (line 3949) — no full ## FUN_ entry
**Issues found:** none (correctly marked as unidentified)
**Details:**
- **Source** (245 bytes): MMX/3DNow! SIMD instructions. Uses `PackedFloatingMAX/MIN`, `FloatingReciprocalAprox`, `PackedFloatingReciprocalIter1/Iter2`, polynomial evaluation. Constants: DAT_005d9358–DAT_005d93b8. Second-order Newton-Raphson approximation. Likely hardware-accelerated vector reciprocal sqrt or division.
- **Doc**: category = `unknown`, algorithm = `unidentified logic` — CORRECT for current state. Could be improved: `math_util | SIMD vector rsqrt/div (3DNow!)`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Architecture note:** Uses MMX registers (`in_MM0`, `in_MM1`). Classic 3DNow! instruction pattern.

---

### FUN_0057B6A0 — This pointer offset getter
**Current doc:** docs/decompiled_full_index_final.md (lines 5056, 7555) — no full ## FUN_ entry
**Issues found:** none
**Details:**
- **Source** (4 bytes): Returns `param_1 + 0x10`. Simple inline-style getter.
- **Doc line 7555**: category = `math_util`, algorithm = `returns param_1 + 0x10` — CORRECT. Properly identified.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.

---

### FUN_00403540 — Index remapping with stride table
**Current doc:** docs/decompiled_full_index_final.md (line 104) — no full ## FUN_ entry
**Issues found:** triage category and size mismatch
**Details:**
- **Source** (248 bytes): Complex index remapping. Processes arrays with stride 0x13c (316 bytes). Maps indices through lookup tables at offsets +0x110, +0x124, +0x10c, +0x120, +0x114, +0x128 relative to base at `param_1+0x134`. Index validation against `param_1+0x130` count. Invalid indices (-1 or >= count) get reset to -1.
- **Doc**: category = `math_util`, algorithm = `short computation` — WRONG. 248 bytes is NOT "short computation". Pattern matches graphics vertex buffer remapping or index buffer fixup. Better: `renderer | vertex/index remapping`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Stride 0x13c** likely corresponds to a vertex/struct stride.

---

### FUN_0049E490 — Large struct zero-init (92 bytes)
**Current doc:** docs/decompiled_full_index_final.md (line 2238) — no full ## FUN_ entry
**Issues found:** triage category/size mismatch
**Details:**
- **Source** (74 bytes): Writes 0 to 23 int32 fields at offsets 0x00–0x5c (92 bytes). Sequential zero-init of struct.
- **Doc**: category = `math_util`, algorithm = `short computation` — WRONG. NOT computation. This is `Data/Init | struct zero-init (92 bytes)`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.

---

### FUN_005118C1 — Two-step utility wrapper
**Current doc:** docs/decompiled_full_index_final.md (line 3710) — no full ## FUN_ entry
**Issues found:** none
**Details:**
- **Source** (37 bytes): Calls `FUN_005117c8(param_1, param_2)` then `FUN_00511887(param_1, local_54)`. Wrapper combining two operations.
- **Doc**: category = `unknown`, algorithm = `utility function` — ACCEPTABLE. Could be refined to `game_logic | two-step string/encoding utility`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** FUN_005117c8, FUN_00511887.

---

### FUN_00587500 — Struct field zero init (at +0x8)
**Current doc:** docs/decompiled_full_index_final.md (lines 5280, 7579) + docs/01-engine-architecture.md (lines 2075, 2089)
**Issues found:** no own ## FUN_ entry; doc entry mentions it as callee only
**Details:**
- **Source** (8 bytes): Writes 0 to int32 at `param_1 + 8`.
- **Doc line 7579**: category = `unknown`, algorithm = `struct field setter: zero at +0x8` — CORRECT.
- **Mentioned in 01-engine-architecture.md** at line 2089 as callee of FUN_005870e0: "Calls FUN_00587500 — (sub-routine, called first)". This matches source: it zeroes a field as sub-init step.
- **No full `## FUN_` entry** in docs/*.md — only referenced as callee. Triage-only.
- **Moddability (as callee):** hardcoded — CORRECT.

---

### FUN_00423490 — Function call wrapper (thunk)
**Current doc:** docs/decompiled_full_index_final.md (line 515) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (10 bytes): Calls `FUN_004234c0()`. No other logic.
- **Doc**: category = `math_util`, algorithm = `short computation` — WRONG. This is a simple thunk/wrapper. Better: `engine | function call wrapper`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** FUN_004234c0.

---

### FUN_0058890E — __abnormal_termination (MSVC CRT)
**Current doc:** docs/decompiled_full_index_final.md (lines 5343, 7442) — no full ## FUN_ entry
**Issues found:** none
**Details:**
- **Source** (35 bytes): MSVC CRT `__abnormal_termination`. Checks if `ExceptionList[4] == &LAB_00588884` and `ExceptionList[8] == ExceptionList[12][12]`. Returns 1 if exceptional termination detected.
- **Doc line 7442**: category = `unknown`, algorithm = `MSVC __abnormal_termination CRT function` — CORRECT.
- **Doc line 5343**: category = `crt_util` — CORRECT.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Skip pattern match:** MSVC CRT — documented correctly.

---

### FUN_004144A0 — Label/address registration wrapper
**Current doc:** docs/decompiled_full_index_final.md (line 374) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (12 bytes): Calls `FUN_00587b3e(&LAB_004144b0)`. Registers an address/label.
- **Doc**: category = `math_util`, algorithm = `short computation` — WRONG. This is a registration/callback pattern. Better: `engine | label/address registration`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** FUN_00587b3e.

---

### FUN_004760D0 — VTable constructor / struct init
**Current doc:** docs/decompiled_full_index_final.md (line 1542) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (45 bytes): Calls `FUN_0048fc50()`. Sets vtable pointer: `*param_1 = &PTR_LAB_005a4464`. Initializes: `param_1[0xf]=0`, `param_1[0x10]=0`, `param_1[0x11]=0`, `param_1[0x12]=0`, `param_1[0x14]=0`, `param_1[0x15]=0xffffffff`, `param_1[0x13]=0`.
- **Doc**: category = `math_util`, algorithm = `short computation` — WRONG. This is a constructor with vtable setup. Better: `engine | constructor/init (vtable + fields)`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Vtable:** PTR_LAB_005a4464.

---

### FUN_00496E20 — Float threshold comparison
**Current doc:** docs/decompiled_full_index_final.md (line 2033) — no full ## FUN_ entry
**Issues found:** none (category acceptable)
**Details:**
- **Source** (28 bytes): Compares `DAT_0059e440` (float) > `*(float *)(param_1 + 0xdc)`. Returns 1 if global exceeds field.
- **Doc**: category = `math_util`, algorithm = `short computation` — ACCEPTABLE. It IS a simple float comparison. Could refine to `game_logic | threshold check`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Global:** DAT_0059e440 (float threshold).

---

### FUN_004BB490 — Linked list push (head insert)
**Current doc:** docs/decompiled_full_index_final.md (line 2643) — no full ## FUN_ entry
**Issues found:** triage category mismatch
**Details:**
- **Source** (87 bytes): Allocates 0xc-byte node via `operator_new`. Stores `param_2` (data), `param_3` (flag byte). If list empty (`*param_1 == 0`): sets head/tail to new node. Else: inserts at head (`piVar2[1] = *param_1; *param_1 = piVar2`). Increments count at `param_1[3]`.
- **Doc**: category = `math_util`, algorithm = `arithmetic/comparison` — WRONG. This is a linked list push (head insertion). Better: `data_struct | linked list push`.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.
- **Calls:** operator_new (0xc bytes).

---

### FUN_00559350 — String copy with struct field init
**Current doc:** docs/decompiled_full_index_final.md (lines 4607, 7352) — no full ## FUN_ entry
**Issues found:** none (second triage entry correct)
**Details:**
- **Source** (51 bytes): Self-relative string copy: `iVar2 = param_1 - (char*)param_2`, copies bytes until null. Sets `param_1+0x14 = param_3`, `param_1+0x18 = param_4`, zeros `param_1+0x1c`.
- **Doc line 7352**: category = `unknown`, algorithm = `String copy with struct field initializer` — CORRECT.
- **No full `## FUN_` entry** in docs/*.md. Triage-only.

---

### FUN_0052E9B0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist in Ghidra function_sizes.csv or any .c file
**Details:**
- **Source:** `.c` file not found in analyzed/, decompiled_full/, tools/decompiled_ida/, or anywhere in project.
- **function_sizes.csv:** No entry for FUN_0052E9B0 or 0x0052e9b0.
- **triage index:** No entry in decompiled_full_index_final.md.
- **Conclusion:** This function is not present in the Ghidra database. The list entry appears to be from a stale/invalid index. Cannot cross-validate.

---

### FUN_00577A50 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004B4AE0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00504A9E — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004FC570 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_005163E9 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00587360 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0043DDD0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00454AF0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0048B330 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0051225E — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0054BB90 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0056C990 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00571730 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0040FAF0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00430790 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0048C4B0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004B1DC0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00515E2B — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00571630 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00597E9C — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004A74F0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004FA580 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00516685 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_005A04C5 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0045CA10 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_004C84C0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00513344 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0053DEB0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0058DF8C — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_005A04C2 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0044F7C0 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00563320 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_005A04A7 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_0052C540 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

### FUN_00454130 — SOURCE FILE NOT FOUND
**Current doc:** No entry in docs/ or decompiled_full_index_final.md
**Issues found:** function does not exist
**Details:** Same as FUN_0052E9B0 — no .c file, no function_sizes entry, no triage entry.

---

## Summary

| Status | Count | Functions |
|--------|-------|-----------|
| Cross-validated (no issues) | 6 | FUN_0057B6A0, FUN_00528F00, FUN_005118C1, FUN_0058890E, FUN_00496E20, FUN_00559350 |
| Triage category mismatch | 10 | FUN_0059BEFD, FUN_00466290, FUN_004B54A0, FUN_004F6D60, FUN_00403540, FUN_0049E490, FUN_00423490, FUN_004144A0, FUN_004760D0, FUN_004BB490 |
| Triage inconsistent with other doc | 1 | FUN_00492030 (triage="unidentified" but globals doc calls it "brace-matching parser") |
| Triage acceptable (minor) | 1 | FUN_00587500 (only referenced as callee, no own entry) |
| Source file not found (function doesn't exist in Ghidra DB) | 35 | All remaining functions (see above) |

**Key finding:** 35 of 54 functions in this batch (65%) do not exist in the Ghidra function database — no .c file, no function_sizes.csv entry, no triage entry. These need to be removed from the assignment list or investigated for whether they were removed/renamed during Ghidra re-analysis.
