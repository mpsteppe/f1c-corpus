# Cross-Validation Results: docs/20-math-utilities.md vs Source

## FUN_00595dc8 — FAIL

Source: docs/20-math-utilities.md (lines 4391–4471)

**Errors:**

- [MISSING_ANALYSIS] Entry is raw decompilation dump only — no human-readable analysis present. No **Key logic**, **Globals**, **Calls**, or **Moddability** sections.
- [MISSING_NAME] Entry heading `## FUN_00595dc8 (0x00595dc8)` lacks a descriptive name. Elsewhere in same doc (line 20170) it is called "Multibyte character conversion".
- [MISSING_GLOBALS] Function uses globals `DAT_008d41c0` (codepage type cache), `DAT_008d3f48` (default ANSI codepage), `DAT_008d3f38` (default locale), `DAT_007cd8bc` (empty string?). None documented.
- [MISSING_CALLS] Function calls `GetStringTypeW`, `GetStringTypeA`, `MultiByteToWideChar`, `FUN_005881c0` (memory allocation). None documented.
- [MISCATEGORIZATION] This is a character encoding/string type classification function (Windows codepage detection + dispatch), NOT a math utility. Belongs better in a text/encoding subsystem doc.
- [NO_MODDABILITY] Missing Moddability classification.

**Code accuracy:** Embedded source code matches the actual .c file verbatim. PASS on code fidelity.

**Corrected entry:**

```
## FUN_00595dc8 — Multibyte Character Type Classification

Source: decompiled_full/0x00595dc8__FUN_00595dc8.c. Wraps Windows GetStringType API with codepage auto-detection. Probes available API at first call, caches result, dispatches to WideChar or Ansi path.

**Key logic:**
- First call: probes `GetStringTypeW` (Unicode path), falls back to `GetStringTypeA` (ANSI path). Caches result in `DAT_008d41c0` (1=Wide, 2=Ansi).
- Wide path: converts multibyte→wide via `MultiByteToWideChar`, then calls `GetStringTypeW` on result. Uses default codepage from `DAT_008d3f48` if param_5==0.
- Ansi path: calls `GetStringTypeA` directly. Uses default locale from `DAT_008d3f38` if param_6==0.
- Returns BOOL: character type flags written to param_4 buffer.

**Globals:**
- `DAT_008d41c0` — cached codepage type: 0=unprobed, 1=WideChar available, 2=Ansi only
- `DAT_008d3f48` — default ANSI codepage (fallback when param_5==0)
- `DAT_008d3f38` — default LCID locale (fallback when param_6==0)
- `DAT_007cd8bc` — empty/fallback string for API probing
- `DAT_005b99c8`, `LAB_0058895c` — exception handler data

**Calls:** FUN_005881c0 (stack allocation), GetStringTypeW, MultiByteToWideChar, GetStringTypeA

**Moddability:** N/A — OS API wrapper
```

---

## FUN_0058b92a — FAIL

Source: docs/20-math-utilities.md (lines 5878–5925+)

**Errors:**

- [MISSING_ANALYSIS] Raw decompilation dump only. No **Key logic**, **Globals**, **Calls**, or **Moddability** sections.
- [MISSING_NAME] Entry heading lacks descriptive name.
- [MISSING_GLOBALS] Not applicable (no globals used — pure stack + params), but this should be noted.
- [MISSING_CALLS] Calls `GetCurrentDirectoryA`, `GetFullPathNameA`, `FUN_0058b9ff` (drive/path validator), `FUN_0058afd8` / `FUN_0058afcf` (errno set), `_malloc`, `FUN_0058fca0` (path copy). None documented.
- [MISCATEGORIZATION] This is a filesystem path resolution function (wraps GetFullPathNameA), NOT a math utility. Belongs in a filesystem/path subsystem doc.
- [NO_MODDABILITY] Missing.

**Code accuracy:** Embedded source matches the .c file verbatim. PASS on code fidelity.

**Corrected entry:**

```
## FUN_0058b92a — Full Path Resolution (Drive-Letter Variant)

Source: decompiled_full/0x0058b92a__FUN_0058b92a.c. Resolves a drive-letter-relative path to a full path, or returns current directory. MSVC `_fullpath`-like implementation.

**Key logic:**
- If param_1 == 0: calls `GetCurrentDirectoryA` → returns current working directory.
- If param_1 != 0: validates param_1 via `FUN_0058b9ff` (drive/path check). On failure: sets errno(0xf) + errno(0xd), returns 0.
- Constructs path string from param_1 as drive letter (`param_1 + 0x40` → e.g. 0→'@', 1→'A', 2→'B'...), prepends `./` → `./A:`, `./B:` etc. Calls `GetFullPathNameA`.
- Result stored in stack buffer (0x104 bytes). If param_2==NULL: allocates via `_malloc`. Copies via `FUN_0058fca0`.
- Error if buffer too small: sets errno(0x22=ENAMETOOLONG).
- Allocation failure: sets errno(0xc=ENOMEM).

**Calls:** FUN_0058b9ff (drive validation), FUN_0058afd8 (errno set high), FUN_0058afcf (errno set low), FUN_0058fca0 (string copy), GetCurrentDirectoryA, GetFullPathNameA, _malloc

**Moddability:** N/A — filesystem utility
```

---

## FUN_0055d460 — FAIL

Source: docs/20-math-utilities.md (lines 6862–6892)

**Errors:**

- [MISSING_ANALYSIS] Raw decompilation dump only. No **Key logic**, **Globals**, **Calls**, or **Moddability** sections.
- [MISSING_NAME] Entry heading lacks descriptive name. Function normalizes a 3D vector and flags dirty.
- [MISSING_GLOBALS] Uses `_DAT_0059e430` (likely 0.0f — zero comparison threshold), `_DAT_0059e43c` (likely 1.0f — normalization divisor), `DAT_008b8f28` (dirty-flag struct at +0xec). None documented.
- [MISSING_CALLS] Calls `FUN_005416a0` (update notification with type 5) and `SQRT` (intrinsic). Not documented.
- [MISSING_STRUCT_OFFSETS] Offsets +0x44, +0x48, +0x4c (vector x,y,z) and +0x04 (likely type/vtable) are not documented.
- [NO_MODDABILITY] Missing.

**Correctness:** Category (math utility) is correct — this IS vector normalization. PASS on categorization.

**Code accuracy:** Embedded source matches the .c file verbatim. PASS on code fidelity.

**Corrected entry:**

```
## FUN_0055d460 — Vector3 Normalize And Dirty Flag

Source: decompiled_full/0x0055d460__FUN_0055d460.c. Normalizes a 3-component vector stored at param_1+0x44, then marks parent struct as modified.

**Key logic:**
- Stores input components at param_1+0x44 (x), param_1+0x48 (y), param_1+0x4c (z).
- Computes magnitude = sqrt(x² + y² + z²).
- If magnitude != 0.0f (compared to `_DAT_0059e430`): divides each component by magnitude (via `_DAT_0059e43c` / magnitude * component).
- Calls `FUN_005416a0(param_1, *(param_1+4), 5)` — likely update/rebuild notification for physics/collision.
- Sets bit 0x800 at `DAT_008b8f28 + 0xec` as dirty flag.

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | type/vtable | Passed as arg to FUN_005416a0 |
| +0x44 | vector_x | First component |
| +0x48 | vector_y | Second component |
| +0x4c | vector_z | Third component |

**Globals:**
- `_DAT_0059e430` — zero threshold float (likely 0.0f)
- `_DAT_0059e43c` — normalization divisor (likely 1.0f)
- `DAT_008b8f28` — parent struct; +0xec holds dirty flags (bit 0x800 set)

**Calls:** FUN_005416a0 (update notification), SQRT (intrinsic)

**Moddability:** hardcoded
```

---

## FUN_00534aac — FAIL

Source: docs/20-math-utilities.md (lines 7277–7291)

**Errors:**

- [MISCATEGORIZATION] This is an audio library import thunk (Miles Sound System `_AIL_shutdown@0`), NOT a math utility. Belongs in docs/21-audio-network-internals.md (and indeed line 7287 already references that doc).
- [MISSING_SOURCE_PATH] Says "Source: unknown" but the analyzed file exists at `0x00534aac___AIL_shutdown_0.c` in analyzed/ directory. The source filename contains "AIL_shutdown" which confirms the MSS identification.
- [MISSING_GLOBALS] No **Globals** section (acceptable for a 6-byte thunk with no global access).
- [MISSING_CALLS] No **Calls** section. Though it's an indirect jump (thunk), documenting the target `_AIL_shutdown@0` as a call would be clearer.

**Correctness:** Description is accurate — it IS a thunk to `_AIL_shutdown`. The analysis (single indirect jump, audio library, game shutdown) is correct. PASS on factual accuracy.

**Code accuracy:** Source file shows 6-byte function with decompiler artifact (recursive call). The doc's description of "indirect jump" correctly interprets the artifact. PASS on code fidelity.

**Corrected entry:**

```
## FUN_00534aac — Thunk to _AIL_shutdown (Miles Sound System)

Source: decompiled_full/0x00534aac___AIL_shutdown_0.c (6 bytes)
Import thunk — indirect jump to Miles Sound System's _AIL_shutdown@0 DLL export. No local logic.

**Key logic:**
- Single indirect jump to _AIL_shutdown@0
- Imported from MSS (Miles Sound System) audio library
- Called at game shutdown to release audio resources

**Used by system:** docs/21-audio-network-internals.md — Miles Sound System audio teardown

**Moddability:** hardcoded (third-party library import)
```

---

## FUN_0045b300 — PASS

Source: docs/20-math-utilities.md (lines 7716–7729)

**Notes:**
- Entry is well-formed: has descriptive name, Key logic, Calls, Used by system, Moddability.
- Code accuracy: 10-byte wrapper that calls FUN_0045bb90() — documented correctly.
- Source says "unknown" which is acceptable (original .cpp unknown); file exists at `0x0045b300__FUN_0045b300.c`.
- No Globals section: correct, function uses no globals.
- Category (math_util) is plausible for a forwarding wrapper.
- Callee `FUN_0045bb90` is also undocumented in the doc — noted as "unknown" which is honest. No inaccuracies found.

---

## FUN_0050c4bb — PASS

Source: docs/20-math-utilities.md (lines 7892–7895)

**Notes:**
- Code accuracy: formula matches source exactly. Computes `result = base + (v3-base)*w1 + (v4-base)*w2` per x,y,z component. Verified against all 3 component formulas in source.
- No Globals: correct, pure computation.
- No Calls: correct, pure computation.
- Category (math_util): correct.
- Name "Bilinear Interpolation (3D)" is slightly imprecise — this is a 2-weight affine blend between 3 points (base, v3, v4), not classic bilinear interpolation (4-corner). But the formula description accurately captures the behavior.
- Missing **Moddability** field — should be documented. This is a hardcoded math utility.
- Lightweight entry format (h2 with inline description rather than ###) — minor format inconsistency vs CLAUDE.md spec, but functionally correct.

---

## FUN_00596dfe — PASS

Source: docs/20-math-utilities.md (lines 8014–8017)

**Notes:**
- Code accuracy: matches source exactly. Calls `FUN_00596e0f(param_1, 0, 4)`. Verified.
- No Globals: correct.
- No Calls section: description mentions the call inline, acceptable for lightweight entry.
- Missing **Moddability** — should be `hardcoded` (pure delegation wrapper).
- Callee `FUN_00596e0f` is not documented elsewhere in the doc — referenced only here. Not an error in this entry, but a broader documentation gap.
- Entry is accurate and well-formed for its simplicity.

---

## FUN_00418ac0 — PASS

Source: docs/20-math-utilities.md (lines 8450–8471)

**Notes:**
- Entry is well-formed with **Key logic**, **Globals**, **Calls**, **Moddability**, **Source**.
- Code accuracy verified:
  - 20-element array, stride 0x20 (8 int32) — confirmed from `do {} while (iVar3 < 0x14)` and `piVar2 + 8`.
  - Slot[0] == -1 gap detection — confirmed from `if (*piVar2 == -1)`.
  - Slot[3] compared against `DAT_008afea8` — confirmed from `fVar7 = (float10)_DAT_008afea8` and `slot[3] < fVar7`.
  - Shifts via `FUN_004145c0` — confirmed in the second loop body.
  - Random value from `FUN_004144d0()` — confirmed.
- Global `DAT_008afea8` correctly documented.
- Calls `FUN_004144d0` and `FUN_004145c0` correctly documented.

**Minor observations (not errors):**
- "tracks min index" phrasing is slightly imprecise — the __fastcall calling convention clobbers `ECX`/`EDX`, producing Ghidra decompilation artifacts (`extraout_ECX`, `extraout_EDX`). The actual index tracking logic is obscured by these artifacts. The doc description glosses over this complexity, which is acceptable.
- Threshold comparison is actually `slot[3] < DAT_008afea8` (strict less-than) — doc says "against threshold" which is vague but not wrong.
- Category (math_util) is questionable — this is an array compaction/defrag routine, not a math computation. Could belong in a data structure utility doc.

---

## FUN_004761e0 — PASS

Source: docs/20-math-utilities.md (lines 8849–8865)

**Notes:**
- Entry is well-formed: descriptive name, Key logic, Calls, Used by, Moddability.
- Code accuracy: all claims verified against source:
  - Phase 1 vtable `PTR_FUN_005a4478`, frees `param_1[0x10]` (+0x40) — confirmed.
  - Phase 2 vtable `PTR_FUN_005a4450`, frees `param_1[0xc]` (+0x30) — confirmed.
  - Phase 3 vtable `PTR_FUN_005a443c`, frees `param_1[1]` (+4) — confirmed.
  - `if (param_2 & 1)` frees self via `FUN_00587bcf(param_1)` — confirmed.
  - Calls FUN_00587bcf (operator delete/free) × 3-4 — confirmed.
- No Globals used (only vtable pointer constants `PTR_FUN_005a4478` etc., which are code addresses, not data globals) — omitted correctly.
- Category (math_util) is incorrect — this is a C++ multi-phase destructor, not a math utility. Belongs better in a memory management or object lifecycle doc.

---

## FUN_0048feb0 — PASS

Source: docs/20-math-utilities.md (lines 9193–9204)

**Notes:**
- Code accuracy: matches source exactly. Sets vtable to `PTR_FUN_005ac6b0`, calls `FUN_00485eb0()`. Verified.
- Entry is well-formed: name, Source, Key logic, Used by, Moddability.
- No **Calls** section — the call `FUN_00485eb0()` is documented inline in Key logic. Acceptable for a 2-line function.
- No **Globals** section — correct (none used beyond vtable pointer).
- Category (math_util) is incorrect — this is a C++ constructor sub-initializer, not a math utility. Belongs in an object lifecycle doc.
- Second reference at line 27520 calls this "cleanup" — this is the context of the caller, not a description of the function itself. No contradiction.


