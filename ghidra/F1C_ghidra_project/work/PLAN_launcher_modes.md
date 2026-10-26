# Plan: Add 15 Launcher Modes to batch_launcher.py

**Target file:** `analysis_pipeline/batch_launcher.py` (3,230 lines currently)
**Pattern:** Every existing mode follows the same 4-piece pattern. Replicate it exactly.

---

## Architecture — How Modes Work

Each mode needs exactly 4 things:

1. **`PROMPT_XXX`** — template string with `{letter}`, `{total_workers}`, `{start_num}`, `{end_num}`, `{output_file}`, `{count}`, `{file_list}` (or `{global_list}`) placeholders
2. **`get_xxx_items()`** — returns list of dicts. Each dict = one work item for a worker
3. **`build_prompt_xxx(letter, bucket, total_workers, global_start)`** — formats the prompt template with the bucket's items
4. **GUI wiring** — 3 touch points:
   - Add radio button in `_build_ui()` 
   - Add stats line in `_refresh_stats()`
   - Add to dispatch dict in `_generate()` + add `_generate_xxx(n)` method

All new modes use `_generate_new_mode()` (line 2977) — no custom generator needed.

Output dirs: `output/<mode_id>/worker_X.md`
Prompt dirs: `prompts/<mode_id>/worker_X_prompt.md`
Both auto-created by `_mode_output_dir()` / `_mode_prompts_dir()`.

---

## Existing Modes (13 already built — DO NOT recreate)

| Mode ID | Prompt | get_items | build_prompt | GUI row |
|---------|--------|-----------|--------------|---------|
| triage | PROMPT | get_files_sorted | build_prompt | row1 |
| review | PROMPT_REVIEW | get_review_files | build_prompt_review | row1 |
| deepdive | PROMPT_DEEPDIVE | get_triage_only_files | build_prompt_deepdive | row1 |
| cross_validate | PROMPT_CROSSVALIDATE | get_cross_validate_items | build_prompt_cross_validate | row2 |
| struct_synth | PROMPT_STRUCTSYNTH | get_struct_synth_items | build_prompt_struct_synth | row2 |
| global_sweep | PROMPT_GLOBALSWEEP | get_global_sweep_items | build_prompt_global_sweep | row2 |
| stub_upgrade | PROMPT_STUBUPGRADE | get_stub_upgrade_items | build_prompt_stub_upgrade | row2 |
| arch_narrative | PROMPT_ARCHNARRATIVE | get_arch_narrative_items | build_prompt_arch_narrative | row2 |
| impl_spec | PROMPT_IMPLSPEC | get_impl_spec_items | build_prompt_impl_spec | row3 |
| call_chain | PROMPT_CALLCHAIN | get_call_chain_items | build_prompt_call_chain | row3 |
| orphan_resolve | PROMPT_ORPHANRESOLVE | get_orphan_resolve_items | build_prompt_orphan_resolve | row3 |
| ida_gaps | PROMPT_IDAGAPS | get_ida_gap_items | build_prompt_ida_gaps | row4 |
| global_validate | PROMPT_GLOBAL_VALIDATE | get_global_validate_items | build_prompt_global_validate | row4 |

---

## New Modes to Add (15 total — maps to HANDOFF.md tasks 1–15)

### Mode 1: `global_validate_2` (HANDOFF Task 1)

**Items source:** `tools/ida_undocumented_globals.csv` — but include globals with ref_count < 2 this time (round 1 only did >=2). Also subtract any globals added to docs/12 since round 1.

**`get_global_validate_2_items()`:**
- Load `tools/ida_undocumented_globals.csv` (all 7,195 rows)
- Load current docs/12 globals (parse `| DAT_XXXXXXXX |` rows)
- Subtract already-documented addresses
- Return remaining, sorted by ref_count descending
- Each item: `{addr, ida_name, ref_count, access, func_count, top_funcs}`

**`build_prompt_global_validate_2()`:**
- Reuse exact same logic as `build_prompt_global_validate()` — reads `ida_data_xrefs.csv`, embeds .c excerpts from top referencing functions
- Only difference: prompt text says "round 2" and includes the current docs/12 as additional reference

**`PROMPT_GLOBAL_VALIDATE_2`:**
- Copy `PROMPT_GLOBAL_VALIDATE` verbatim
- Change title to "Round 2"  
- Add instruction: "Read `docs/12-globals-reference.md` first. Do NOT re-name globals already in it."
- Keep same output format: `<!-- target: docs/12-globals-reference.md -->` + table rows

**Stats line:** `GLOBAL VALIDATE 2  |  {N} remaining undocumented globals  |  {total_refs} total refs`

**Workers:** 20

---

### Mode 2: `struct_audit` (HANDOFF Task 2)

**Items source:** `docs/13-struct-offsets.md` — split into chunks of ~700 lines each.

**`get_struct_audit_items()`:**
- Read `docs/13-struct-offsets.md`
- Split at struct boundaries (lines starting with `## ` or `### `)
- Each item: `{struct_name, start_line, end_line, line_count, content_slice}`
- If struct section too large (>1000 lines), split at sub-boundaries

**`build_prompt_struct_audit()`:**
- Embed the struct slice content directly in prompt
- For each offset in the slice, pre-grep `analysis_pipeline/analyzed/` for files containing that offset pattern (e.g., `+ 0x1330`)
- Include up to 5 .c file paths per offset as evidence sources

**`PROMPT_STRUCT_AUDIT`:**
```
# WORKER {letter} — F1C Struct Confidence Audit

You are auditing struct field definitions from docs/13 against actual Ghidra decompilation.
Worker {letter} of {total_workers}.

## STEP 1 — LOAD REFERENCES
1. `docs/13-struct-offsets.md` — current struct definitions (your audit target)
2. `docs/12-globals-reference.md` — named globals for context

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR STRUCT SECTIONS ({count})
{file_list}

## TASK
For each struct field in your section:
1. Read the .c files listed as evidence sources
2. Check: does the .c file actually dereference this offset with the claimed type?
3. Grade confidence: HIGH (3+ .c files agree), MEDIUM (1-2 agree), LOW (no .c evidence)
4. Flag CONFLICTS: same offset claimed as different types across entries
5. Find NEW offsets: patterns like `*(type *)(param + 0xNEW)` not in docs/13

## OUTPUT FORMAT
```
=== AUDIT RESULTS ===
## StructName

| Offset | Current Type | Current Name | Confidence | Evidence | Conflicts |
|--------|-------------|--------------|------------|----------|-----------|
| +0x0000 | int | sessionType | HIGH | 5 .c files agree | none |
| +0x1330 | double | ??? | LOW | only 1 .c, typed as float in FUN_X | FUN_Y says int |

=== NEW OFFSETS DISCOVERED ===
| Struct | Offset | Type | Found in | Notes |
|--------|--------|------|----------|-------|
```

## RULES
0. NEVER modify any files except {output_file}.
1. Process ALL fields in your sections.
2. Read actual .c files — do not guess confidence from docs alone.
3. Flag every conflict. Do not silently pick a winner.
4. For new offsets: only report if seen in 2+ .c files.
```

**Stats line:** `STRUCT AUDIT  |  {N} struct sections  |  {total_fields} fields to audit`

**Workers:** 10

---

### Mode 3: `triage_upgrade` (HANDOFF Task 3)

**Items source:** Knowledge graph `functions.json` — functions where documented=false or no `## FUN_` header in any docs/ file.

**`get_triage_upgrade_items()`:**
- Load `knowledge_graph/functions.json`
- For each function, check if any docs/ file contains `## FUN_XXXXXXXX` or `### FUN_XXXXXXXX`
- Filter to those with NO header match (triage-only in index)
- Must have .c file in `analyzed/` (use `_build_addr_to_c_index()`)
- Each item: `{addr, c_path, doc_file, summary, category, target}`
- Use `_resolve_target(category)` for target doc

**`build_prompt_triage_upgrade()`:**
- Same structure as `build_prompt_deepdive()` but smaller batch
- Embed call context from `call_graph.json` and `callers.json` for each function

**`PROMPT_TRIAGE_UPGRADE`:**
- Copy `PROMPT_DEEPDIVE` as base
- Change title: "Triage Upgrade — Remaining Undocumented Functions"
- Add: for each function, list known callers and callees from graph JSON
- Same output format: `<!-- target: docs/XX.md -->` + `## FUN_XXXXXXXX` entries

**Stats line:** `TRIAGE UPGRADE  |  {N} undocumented functions  |  .c files available`

**Workers:** 4 (only ~63 items)

---

### Mode 4: `gap_analyze` (HANDOFF Task 4)

**Items source:** `tools/ida_gaps.csv` — filter to `classification == "possible_code_or_data"`.

**`get_gap_analyze_items()`:**
- Read `tools/ida_gaps.csv`
- Filter rows where classification == "possible_code_or_data" (852 rows)
- For each gap, find surrounding functions (nearest documented function before and after by address)
- Load any data xrefs pointing into gap region from `tools/ida_data_xrefs.csv`
- Each item: `{start, end, size, hex_head, prev_func, next_func, xrefs_into}`

**`build_prompt_gap_analyze()`:**
- Embed hex_head (first 128 bytes), surrounding function context, data xrefs
- No .c file reading needed — just hex analysis

**`PROMPT_GAP_ANALYZE`:**
```
# WORKER {letter} — F1C .text Gap Classification

You are classifying unidentified regions in the .text section of F1 Challenge 99-02.
IDA Pro found {count} gaps — regions neither Ghidra nor IDA identified as functions.
Your job: determine what each region actually contains.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR GAPS ({count})
{file_list}

## CLASSIFICATION CATEGORIES
- `missed_function` — valid x86 code that is a callable function (has prologue/epilogue patterns)
- `jump_table_data` — switch/case jump target table (array of addresses)
- `data_table` — numeric lookup table, coefficient array, or constant pool
- `vtable` — virtual function table (array of function pointers)
- `string_data` — embedded string literals
- `padding` — alignment padding (0x90/0xCC/0x00 fill)
- `mixed` — combination of above (describe components)
- `unknown` — genuinely unclassifiable

## HOW TO CLASSIFY
1. Look at hex_head bytes:
   - `55 8B EC` or `56 57` = x86 function prologue → missed_function
   - Repeating 4-byte values in 0x00400000-0x005E0000 range → vtable or jump_table
   - ASCII-range bytes (0x20-0x7E) → string_data
   - `90 90 90` or `CC CC CC` → padding
   - Regular patterns of floats/doubles → data_table
2. Check xrefs_into: if code references point here, what instruction uses them?
3. Check surrounding functions: what system are they part of?

## OUTPUT FORMAT
```
=== GAP CLASSIFICATIONS ===
| Start | End | Size | Classification | Confidence | Description |
|-------|-----|------|---------------|------------|-------------|
| 0x00XXXXXX | 0x00YYYYYY | 287 | padding | HIGH | 0x90 NOP fill between functions |
| 0x00AAAAAA | 0x00BBBBBB | 1024 | data_table | MEDIUM | array of 128 doubles, likely physics coefficients |

=== NOTABLE FINDINGS ===
[Any gaps that reveal undiscovered functions, vtables, or interesting data structures]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Classify EVERY gap in your list.
2. hex_head shows first 64 bytes — use byte patterns to classify.
3. For missed_function: note the prologue pattern and estimated function size.
4. For data_table: note element type (int/float/double) and count if determinable.
5. Write to disk after every 20 classifications.
```

**Stats line:** `GAP ANALYZE  |  {N} possible code/data gaps  |  {total_bytes} bytes unclassified`

**Workers:** 10

---

### Mode 5: `switch_map` (HANDOFF Task 5)

**Items source:** `tools/ida_switches.csv` (286 rows).

**`get_switch_map_items()`:**
- Read `tools/ida_switches.csv`
- For each switch, find the containing function's .c file via `_build_addr_to_c_index()` using `func_addr`
- Look up existing doc entry for func_addr in docs/
- Each item: `{func_addr, switch_addr, jtable_addr, ncases, targets, c_path, doc_file, default}`

**`build_prompt_switch_map()`:**
- Embed full .c source of containing function (cap at 30KB)
- Include existing doc entry summary if available
- Include switch metadata from CSV

**`PROMPT_SWITCH_MAP`:**
```
# WORKER {letter} — F1C Switch/Jump Table Documentation

You are documenting switch/case dispatch tables in F1 Challenge 99-02.
IDA Pro identified {count} jump tables. Each represents a state machine, message handler,
or type dispatcher. Document what each case value means.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## STEP 1 — LOAD REFERENCES
1. `docs/12-globals-reference.md` — named globals
2. `docs/13-struct-offsets.md` — struct field names

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR SWITCHES ({count})
{file_list}

## TASK
For each switch table:
1. Read the containing function's .c source
2. Identify the switch variable — what value is being dispatched on?
3. For each case: what does it do? What state/type/message does it handle?
4. Relate to known enums: SessionType (0-7), GameState (1-7), RacePhase, etc.

## OUTPUT FORMAT
```
=== SWITCH TABLE ENTRIES ===

### FUN_XXXXXXXX — switch at 0xYYYYYYYY ({N} cases)

**Dispatch variable:** [what is being switched on — global, parameter, struct field]
**Enum type:** [known enum name if matches, or "unknown"]
**System:** docs/XX-name.md

| Case | Target Addr | Purpose | Game-critical? |
|------|-------------|---------|---------------|
| 0 | 0x00AAAAAA | Menu state — initialize UI | yes |
| 1 | 0x00BBBBBB | Loading state — read track data | yes |
| default | 0x00CCCCCC | Error fallthrough | no |

**Notes:** [any pattern observations — sequential enum, message handler, etc.]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Document EVERY switch in your list.
2. Read the full .c source — do not guess case purposes from addresses alone.
3. If dispatch variable matches a known global from docs/12, name it.
4. Mark cases as game-critical if they affect gameplay state.
5. Write to disk after every 10 switches.
```

**Stats line:** `SWITCH MAP  |  {N} jump tables  |  {total_cases} total cases`

**Workers:** 6

---

### Mode 6: `exception_map` (HANDOFF Task 6)

**Items source:** `tools/ida_exceptions.csv` (98 rows).

**`get_exception_map_items()`:**
- Read `tools/ida_exceptions.csv`
- For each, find .c file via `_build_addr_to_c_index()` using `func_addr`
- Look up doc entry if exists
- Each item: `{func_addr, func_name, seh, cxx_eh, c_path, doc_file}`

**`build_prompt_exception_map()`:**
- Embed full .c source for each function
- Small enough items that source can be inlined

**`PROMPT_EXCEPTION_MAP`:**
```
# WORKER {letter} — F1C Exception Handler Classification

You are classifying {count} SEH/C++ exception handling functions in F1 Challenge 99-02.
Determine which are game-logic error recovery, which are CRT boilerplate, and which
protect specific subsystems.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR FUNCTIONS ({count})
{file_list}

## CLASSIFICATION CATEGORIES
- `game_recovery` — catches game-specific errors, attempts recovery (e.g., reset state)
- `subsystem_guard` — protects a specific subsystem (renderer, audio, network) from crashes
- `crt_boilerplate` — MSVC CRT exception infrastructure (__CxxFrameHandler, etc.)
- `seh_filter` — SEH exception filter (decides whether to handle or pass)
- `cleanup_handler` — destructor or cleanup code triggered on exception

## OUTPUT FORMAT
```
=== EXCEPTION CLASSIFICATIONS ===
| Address | IDA Name | Type (SEH/C++) | Classification | Confidence | Protected Subsystem | Notes |
|---------|----------|---------------|---------------|------------|-------------------|-------|

=== FULL ENTRIES ===
<!-- target: docs/XX-name.md -->
## FUN_XXXXXXXX — Exception Handler Name
[full entry only for game_recovery and subsystem_guard classifications]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Classify EVERY function in your list.
2. Read the .c source — CRT boilerplate has distinctive patterns (__CxxFrameHandler calls, 
   MSVC exception table structures). Game recovery touches game globals.
3. Full `## FUN_` entries only for game_recovery and subsystem_guard.
4. For subsystem_guard: name which subsystem is protected and what error condition is caught.
```

**Stats line:** `EXCEPTION MAP  |  {N} exception handlers  |  SEH: {seh_count}  C++: {cxx_count}`

**Workers:** 4

---

### Mode 7: `import_map` (HANDOFF Task 7)

**Items source:** `tools/ida_imports.csv` (246 rows).

**`get_import_map_items()`:**
- Read `tools/ida_imports.csv`
- Group by DLL (KERNEL32, USER32, etc.)
- For each import, resolve caller addresses to doc entries/summaries
- Each item: `{addr, name, dll, callers_list, caller_summaries}`

**`build_prompt_import_map()`:**
- Group imports by DLL in the prompt
- For each caller, include one-line summary from knowledge graph functions.json
- No .c source embedding needed — caller summaries suffice

**`PROMPT_IMPORT_MAP`:**
```
# WORKER {letter} — F1C DLL Import Usage Map

You are mapping how F1 Challenge 99-02 uses Win32 DLL imports. For each import,
document which game subsystem calls it and why.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## STEP 1 — LOAD REFERENCES
1. `knowledge_graph/functions.json` — function metadata and summaries
2. `docs/12-globals-reference.md` — named globals

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR IMPORTS ({count})
{file_list}

## OUTPUT FORMAT
```
=== IMPORT USAGE MAP ===

### {DLL_NAME} ({N} imports)

| Import | Address | Caller Count | Primary Subsystem | Purpose in Game |
|--------|---------|-------------|-------------------|----------------|
| CreateFileA | 0x0059XXXX | 12 | File I/O | Opens .svm/.hdv/.veh game data files |
| GetTickCount | 0x0059YYYY | 8 | Engine Core | Frame timing / performance measurement |

**Usage patterns:**
- [How this DLL's imports work together in the game]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Document EVERY import in your list.
2. Determine subsystem from caller functions (use functions.json summaries).
3. Group output by DLL.
4. Note any imports that appear unused (0 callers) — likely indirect/dynamic.
```

**Stats line:** `IMPORT MAP  |  {N} DLL imports  |  {dll_count} DLLs`

**Workers:** 4

---

### Mode 8: `string_map` (HANDOFF Task 8)

**Items source:** `tools/ida_strings.csv` (5,434 rows).

**`get_string_map_items()`:**
- Read `tools/ida_strings.csv`
- For each string, resolve ref_funcs to doc entries
- Each item: `{addr, length, encoding, value, ref_funcs, func_summaries}`
- Pre-categorize obvious ones: strings starting with `D:\dev` = source_path, contains `.` + 3-letter ext = file_path, etc.

**`build_prompt_string_map()`:**
- Batch strings into prompt
- Include func summaries for referencing functions
- No .c source needed — string value + referencing function summaries give enough context

**`PROMPT_STRING_MAP`:**
```
# WORKER {letter} — F1C String Cross-Reference Map

You are categorizing {count} strings extracted from F1 Challenge 99-02 and mapping
each to its game purpose and referencing subsystem.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR STRINGS ({count})
{file_list}

## CATEGORIES
- `game_message` — player-visible text (UI, HUD, messages)
- `config_key` — .ini/.cfg key name or section header
- `file_path` — file path or extension (.svm, .hdv, .veh, .scn, etc.)
- `source_path` — D:\dev\ assert path (original source tree)
- `error_string` — error message (not player-visible)
- `debug_print` — debug/log output string
- `format_string` — printf-style format (contains %d, %s, %f, etc.)
- `library_internal` — zlib/DirectX/Miles/CRT library string
- `game_data` — track names, driver names, team names, car data
- `network_protocol` — TCP/UDP message identifiers, protocol strings
- `registry_key` — Windows registry paths

## OUTPUT FORMAT
```
=== STRING CLASSIFICATIONS ===
| Address | Value (truncated) | Category | Subsystem | Referencing Functions | Notes |
|---------|-------------------|----------|-----------|----------------------|-------|
| 0x005XXXXX | "Race Complete" | game_message | session | FUN_XXXXXXXX | shown at race end |

=== NOTABLE DISCOVERIES ===
[Strings that reveal undocumented features, hidden config options, debug commands, etc.]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Categorize EVERY string in your list.
2. Truncate string values to 60 chars in the table.
3. Flag strings that suggest undocumented features (debug menus, cheat codes, hidden options).
4. Source paths (D:\dev\...) are valuable — note the .cpp filename.
5. Write to disk after every 50 strings.
```

**Stats line:** `STRING MAP  |  {N} strings  |  {unique_funcs} referencing functions`

**Workers:** 15

---

### Mode 9: `orphan_resolve_2` (HANDOFF Task 9)

**Items source:** Same as `orphan_resolve` but enhanced with data xrefs + switch targets.

**`get_orphan_resolve_2_items()`:**
- Same logic as `get_orphan_resolve_items()` (line 2336)
- Additionally: load `tools/ida_data_xrefs.csv` and check if any data xref points into orphan address
- Load `tools/ida_switches.csv` and check if any switch target matches orphan address
- Add to each item: `{..., data_xrefs: [...], switch_refs: [...]}`

**`build_prompt_orphan_resolve_2()`:**
- Same as `build_prompt_orphan_resolve()` but include data xref and switch target info per orphan

**`PROMPT_ORPHAN_RESOLVE_2`:**
- Copy `PROMPT_ORPHANRESOLVE` as base
- Add "Round 2" to title
- Add new evidence types: data xrefs, switch table targets, address proximity analysis
- Add instruction: "Load `work/orphan_resolve_summary.csv` — skip any addresses already classified there"

**Stats line:** `ORPHAN RESOLVE 2  |  {N} orphans  |  {with_data_xrefs} have data xrefs  |  {with_switch} in switch targets`

**Workers:** 10

---

### Mode 10: `enum_catalog` (HANDOFF Task 10)

**Items source:** All .c files in `analyzed/` — scan for switch statements and magic number patterns.

**`get_enum_catalog_items()`:**
- List all .c files in `analyzed/` (6,800+ files)
- Each item: just `{c_path, addr}` — workers do the analysis
- Sort by address for locality

**`build_prompt_enum_catalog()`:**
- List .c file paths for the worker to read
- Include known enums as reference (SessionType 0-7, GameState 1-7, RacePhase 0-7, etc.)

**`PROMPT_ENUM_CATALOG`:**
```
# WORKER {letter} — F1C Magic Number / Enum Recovery

You are systematically identifying hardcoded magic numbers and grouping them into enums.
Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## STEP 1 — LOAD REFERENCES
1. `docs/12-globals-reference.md` — known globals with value ranges
2. `docs/13-struct-offsets.md` — struct fields

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR FILES ({count})
{file_list}

## KNOWN ENUMS (do not re-discover these)
- SessionType: 0=free practice, 1-5=practice sessions, 6=qualifying, 7=race
- GameState: 1-7
- RacePhase: 0-7
- WeatherMode: 0-5 (0=dry, 1-5=rain levels)
- EngineWearMode: 0/2/3
- RaceMode: 3=championship, 4=championship

## TASK
For each .c file:
1. Find switch statements — extract all case values and what each does
2. Find comparisons against literal integers (if x == 3, if x < 7, etc.)
3. Find assignments of literal values to globals or struct fields
4. Group related values into enum candidates

## OUTPUT FORMAT
```
=== ENUM DISCOVERIES ===

### EnumName (new/extension of existing)
Source evidence: FUN_XXXXXXXX, FUN_YYYYYYYY
Variable: DAT_XXXXXXXX or param_1+0xNNN

| Value | Meaning | Evidence Function | Confidence |
|-------|---------|------------------|------------|
| 0 | state_name | FUN_XXXXXXXX (switch case 0) | HIGH |
| 1 | state_name | FUN_YYYYYYYY (comparison) | MEDIUM |

=== MAGIC NUMBERS ===
| Value | Hex | Type | Used In | Context | Likely Meaning |
|-------|-----|------|---------|---------|---------------|
| 0.017453 | — | float | FUN_X | multiply angle | DEG_TO_RAD |
```

## RULES
0. NEVER modify any files except {output_file}.
1. Process ALL files in your list.
2. Do NOT re-report known enums listed above unless you find NEW values for them.
3. Group related magic numbers: 3.14159=PI, 0.0174533=DEG_TO_RAD, 57.2957=RAD_TO_DEG, etc.
4. For physics constants: identify if it's gravity (9.81), air density (1.225), etc.
5. Write to disk after every 20 files.
```

**Stats line:** `ENUM CATALOG  |  {N} .c files to scan`

**Workers:** 20

---

### Mode 11: `sig_refine` (HANDOFF Task 11)

**Items source:** `tools/ida_functions.csv` (6,170 rows) — functions with IDA type signatures.

**`get_sig_refine_items()`:**
- Read `tools/ida_functions.csv`
- Filter to game range (0x401000–0x5E0000)
- For each, find .c file in `analyzed/` via `_build_addr_to_c_index()`
- Each item: `{addr, name, size, flags, calling_conv, type_sig, c_path}`

**`build_prompt_sig_refine()`:**
- Embed IDA signature + first 3KB of .c source per function
- Batch ~300 per worker

**`PROMPT_SIG_REFINE`:**
```
# WORKER {letter} — F1C Function Signature Refinement

You are comparing IDA Pro type signatures against Ghidra decompilation to refine
parameter types, return types, and calling conventions.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR FUNCTIONS ({count})
{file_list}

## TASK
For each function:
1. Compare IDA's declared signature against Ghidra's decompiled parameters
2. Check: do they agree on param count? param types? return type? calling convention?
3. If they disagree, determine which is more likely correct from the code context
4. Identify struct pointer params (params accessed with `*(type *)(param + offset)`)

## OUTPUT FORMAT
```
=== SIGNATURE REFINEMENTS ===
| Address | IDA Params | Ghidra Params | Agreed? | Refined Signature | Notes |
|---------|-----------|---------------|---------|-------------------|-------|
| 0x00XXXX | (int, int, float) | (undefined4, undefined4, undefined4) | param count yes, types differ | void __thiscall FUN_X(Vehicle* this, int param2, float force) | param1 is this ptr |

=== PARAM COUNT DISAGREEMENTS ===
[Functions where IDA and Ghidra disagree on parameter count — these need manual review]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Process ALL functions in your list.
2. `__thiscall` with first param accessed as struct → note struct type from docs/13.
3. `__cdecl` vs `__stdcall` matters for stack cleanup — note which IDA chose.
4. If Ghidra shows `undefined4` and IDA shows `int` → IDA usually wins for basic types.
5. Write to disk after every 30 functions.
```

**Stats line:** `SIG REFINE  |  {N} functions  |  IDA signatures available`

**Workers:** 20

---

### Mode 12: `source_tree` (HANDOFF Task 12)

**Items source:** `tools/ida_strings.csv` — filter for strings containing `D:\dev`.

**`get_source_tree_items()`:**
- Read `tools/ida_strings.csv`
- Filter to strings containing `D:\dev` or `d:\dev`
- Also scan all .c files in `decompiled_all/` for assert strings containing source paths
- Deduplicate source paths
- Each item: `{source_path, ref_funcs, func_count}`
- Group by directory

**`build_prompt_source_tree()`:**
- This is a synthesis task — embed all source paths + referencing functions
- Small enough for 2-4 workers max

**`PROMPT_SOURCE_TREE`:**
```
# WORKER {letter} — F1C Source Tree Reconstruction

You are reconstructing the original source tree of F1 Challenge 99-02 from assert strings
and debug paths embedded in the binary.

Worker {letter} of {total_workers}.

## OUTPUT FILE
Write ALL output to: {output_file}

## SOURCE PATHS FOUND ({count})
{file_list}

## TASK
1. Parse all D:\dev\ paths into a directory tree
2. For each source file (.cpp/.h):
   - List all functions that reference it (from assert strings)
   - Estimate total function count (some functions lack asserts)
   - Note address range of referencing functions (cluster analysis)
3. Identify "gaps" — address ranges with no source path → inlined or path-less code

## OUTPUT FORMAT
```
# F1 Challenge 99-02 — Reconstructed Source Tree

## Directory Structure
```
D:\dev\F1_1999_2002\Source\
  ├── Physics\
  │   ├── tire_model.cpp          (12 functions, 0x004A0000-0x004A8000)
  │   ├── suspension.cpp          (8 functions, 0x004A8000-0x004AC000)
  ...
```

## Source File Details

### Physics/tire_model.cpp
Functions: FUN_004AXXXX, FUN_004AYYYY, ...
Address range: 0x004A0000 — 0x004A8000
Estimated total functions: 15 (12 with asserts, ~3 inlined)

## Inlined Function Gaps
[Address ranges with functions but no source path — likely inlined]

## Statistics
- Total .cpp files found: N
- Total functions with source attribution: N
- Estimated inlined/missing functions: N
```

## RULES
0. NEVER modify any files except {output_file}.
1. Every D:\dev path must appear in the reconstructed tree.
2. Use address clustering to group functions by source file even without explicit paths.
3. Note the original project structure — subdirectories reveal team organization.
```

**Stats line:** `SOURCE TREE  |  {N} source paths  |  {unique_files} unique .cpp files`

**Workers:** 2-4

---

### Mode 13: `data_map` (HANDOFF Task 13)

**Items source:** `tools/ida_segments.csv` (8 rows) + `tools/ida_data_xrefs.csv` density analysis.

**`get_data_map_items()`:**
- Read `tools/ida_segments.csv` — focus on .data and .rdata segments
- Split each segment into 4KB blocks
- For each block, count data xrefs from `ida_data_xrefs.csv` that fall in range
- Each item: `{segment, block_start, block_end, xref_count, xref_funcs, known_globals_in_range}`
- Cross-reference with `docs/12` globals in range

**`build_prompt_data_map()`:**
- Embed segment layout, xref density per block, known globals
- Workers analyze blocks by xref density and known content

**`PROMPT_DATA_MAP`:**
```
# WORKER {letter} — F1C Data Segment Mapping

You are mapping the .data and .rdata sections of F1 Challenge 99-02 to identify
data structures, config tables, lookup tables, string pools, and vtable regions.

Worker {letter} of {total_workers}.

## STEP 1 — LOAD REFERENCES
1. `docs/12-globals-reference.md` — known globals and their types
2. `tools/ida_strings.csv` — string locations in data sections

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR SEGMENTS / BLOCKS ({count})
{file_list}

## OUTPUT FORMAT
```
=== DATA SECTION MAP ===

### Segment: .data (0x005BE000 — 0x008D6000)

| Block Start | Block End | Type | Xref Density | Purpose | Key Globals |
|-------------|-----------|------|-------------|---------|-------------|
| 0x005BE000 | 0x005BF000 | config_table | 45 xrefs | Game configuration array | DAT_005BEXXX |
| 0x007C5000 | 0x007C6000 | game_state | 120 xrefs | Session/race state globals | SessionType, RacePhase |
| 0x008D0000 | 0x008D9000 | physics_workspace | 8 xrefs | Dynamics solver matrix workspace | [known from IDA gap analysis] |

=== REGION DETAILS ===
### 0x007C5000 — Game State Block
[Detailed breakdown of this high-density region: individual globals, their relationships,
which subsystems access them most heavily]
```

## RULES
0. NEVER modify any files except {output_file}.
1. Map EVERY block in your assignment.
2. High xref density = important game data. Low density = static constants or padding.
3. Use docs/12 globals to anchor known regions.
4. Note regions with consecutive same-type globals (arrays/tables).
```

**Stats line:** `DATA MAP  |  {N} data blocks  |  {total_xrefs} data xrefs  |  {known_globals} known globals in range`

**Workers:** 4

---

### Mode 14: `cross_validate_2` (HANDOFF Task 14)

**Items source:** All `## FUN_` and `### FUN_` entries across ALL docs/ files (not just 17-21 like round 1).

**`get_cross_validate_2_items()`:**
- Same logic as `get_cross_validate_items()` but scan ALL docs/*.md, not just docs/17-21
- Use updated docs/12 (2,356 globals) and docs/13 (6,910 lines) as ground truth
- Each item: `{addr, doc_path, doc_rel, c_path}`

**`build_prompt_cross_validate_2()`:**
- Same as `build_prompt_cross_validate()` 
- Prompt includes stricter checks using updated docs/12 and docs/13

**`PROMPT_CROSSVALIDATE_2`:**
- Copy `PROMPT_CROSSVALIDATE` as base
- Change title: "Cross-Validation Round 2"
- Add checks:
  - "Check global names against docs/12 — wrong name is an error"
  - "Check struct offsets against docs/13 — wrong field name is an error"
  - "Check Calls section against call_graph.json — missing edges are errors"
- Same output format as round 1

**Stats line:** `CROSS VALIDATE 2  |  {N} entries across all docs/  |  using updated docs/12 ({global_count} globals) + docs/13`

**Workers:** 20

---

### Mode 15: `inline_detect` (HANDOFF Task 15)

**Items source:** All .c files in `analyzed/` — pattern matching for repeated code blocks.

**`get_inline_detect_items()`:**
- List all .c files in `analyzed/`
- Each item: `{c_path, addr}`
- Sort by address

**`build_prompt_inline_detect()`:**
- List .c file paths
- Workers scan for repeated patterns

**`PROMPT_INLINE_DETECT`:**
```
# WORKER {letter} — F1C Inlined Function Recovery

You are finding compiler-inlined functions — code patterns that appear identically
across multiple functions, indicating an original helper that was inlined by MSVC.

Worker {letter} of {total_workers}, items {start_num}–{end_num}.

## OUTPUT FILE
Write ALL output to: {output_file}

## YOUR FILES ({count})
{file_list}

## TASK
For each .c file:
1. Read the decompiled source
2. Look for code blocks (5-20 lines) that look like they could be a standalone function:
   - Same sequence of operations on a struct parameter
   - Same math formula with same constants
   - Same conditional pattern with same thresholds
   - Same loop structure operating on same offset patterns
3. Note the pattern signature and which file contains it
4. After processing all files, group identical/near-identical patterns

## PATTERN TYPES TO LOOK FOR
- Vector operations: `x = a*b + c*d + e*f` (dot product) across many functions
- Normalization: `len = sqrt(x*x + y*y + z*z); x/=len; y/=len; z/=len`
- Clamping: `if (x < min) x = min; if (x > max) x = max;`
- Matrix row access: same offset arithmetic pattern
- Struct field validation: same bounds-check pattern on same offsets
- Memory clear: same memset-like pattern on struct range

## OUTPUT FORMAT
```
=== INLINED FUNCTION CANDIDATES ===

### InlinedFuncName (candidate)
Pattern: [describe the repeated code block in 2-3 lines]
Occurrences: {N} functions
Found in: FUN_XXXXXXXX, FUN_YYYYYYYY, FUN_ZZZZZZZZ, ...
Likely original source: [source file from address clustering]
Confidence: HIGH (identical pattern) / MEDIUM (similar with variations) / LOW (structural match only)

Code pattern:
```c
// representative example from FUN_XXXXXXXX
[5-15 lines of the repeated code]
```
```

## RULES
0. NEVER modify any files except {output_file}.
1. Process ALL files in your list.
2. Only report patterns appearing in 3+ functions (2 could be coincidence).
3. Distinguish: exact match (HIGH), same structure different offsets (MEDIUM), 
   same algorithm different constants (LOW).
4. Do NOT flag standard C patterns (null checks, return error codes) — only game-specific patterns.
5. Write to disk after every 50 files.
```

**Stats line:** `INLINE DETECT  |  {N} .c files to scan`

**Workers:** 20

---

## GUI Wiring

### Radio button layout (6 rows total)

Current rows 1-4 have 13 modes. Add rows 5-6 for new modes:

**Row 5:** `global_validate_2`, `struct_audit`, `triage_upgrade`, `gap_analyze`, `switch_map`
**Row 6:** `exception_map`, `import_map`, `string_map`, `orphan_resolve_2`, `enum_catalog`
**Row 7:** `sig_refine`, `source_tree`, `data_map`, `cross_validate_2`, `inline_detect`

### Dispatch dict additions (in `_generate()`)

```python
'global_validate_2': self._generate_global_validate_2,
'struct_audit':      self._generate_struct_audit,
'triage_upgrade':    self._generate_triage_upgrade,
'gap_analyze':       self._generate_gap_analyze,
'switch_map':        self._generate_switch_map,
'exception_map':     self._generate_exception_map,
'import_map':        self._generate_import_map,
'string_map':        self._generate_string_map,
'orphan_resolve_2':  self._generate_orphan_resolve_2,
'enum_catalog':      self._generate_enum_catalog,
'sig_refine':        self._generate_sig_refine,
'source_tree':       self._generate_source_tree,
'data_map':          self._generate_data_map,
'cross_validate_2':  self._generate_cross_validate_2,
'inline_detect':     self._generate_inline_detect,
```

All use `_generate_new_mode()` — each `_generate_xxx(n)` is a one-liner:
```python
def _generate_xxx(self, n):
    self._generate_new_mode(n, get_xxx_items, build_prompt_xxx, 'xxx', 'Label')
```

### Stats lines (in `_refresh_stats()`)

Each mode needs an `elif mode == "xxx":` block that counts items and displays stats.
Use same pattern as existing modes. Avoid calling slow functions (like full .c scans) in stats — use fast count methods.

For slow modes (enum_catalog, sig_refine, inline_detect that scan all .c files): just count files in `analyzed/` directory, don't scan contents.

---

## Merge Scripts Needed

Each new mode needs a merge script in `work/` to integrate output into docs/:

| Mode | Merge target | Script needed |
|------|-------------|---------------|
| global_validate_2 | docs/12-globals-reference.md | `work/merge_global_validate.py` (exists — extend) |
| struct_audit | docs/13-struct-offsets.md | `work/merge_struct_audit.py` (new) |
| triage_upgrade | docs/01-21 (via target comments) | `analysis_pipeline/merge_to_docs.py` (existing — works) |
| gap_analyze | docs/14-binary-gaps.md (new doc?) | `work/merge_gap_analyze.py` (new) |
| switch_map | docs/15-switch-tables.md (new doc?) | `work/merge_switch_map.py` (new) |
| exception_map | docs/01-engine-architecture.md | `analysis_pipeline/merge_to_docs.py` (existing) |
| import_map | docs/16-import-reference.md (exists) | `work/merge_import_map.py` (new) |
| string_map | docs/23-string-reference.md (new doc?) | `work/merge_string_map.py` (new) |
| orphan_resolve_2 | knowledge_graph rebuild | `work/merge_orphan_resolve.py` (exists — extend) |
| enum_catalog | docs/24-enum-catalog.md (new doc?) | `work/merge_enum_catalog.py` (new) |
| sig_refine | docs/25-function-signatures.md (new?) | `work/merge_sig_refine.py` (new) |
| source_tree | docs/26-source-tree.md (new doc?) | Manual — one-shot output |
| data_map | docs/27-data-segments.md (new doc?) | `work/merge_data_map.py` (new) |
| cross_validate_2 | docs/01-21 (corrections) | `work/merge_cross_validate.py` (new) |
| inline_detect | docs/22-inlined-functions.md (new) | `work/merge_inline_detect.py` (new) |

**Note:** Merge scripts are NOT part of batch_launcher.py. Build them separately. The launcher only generates prompts and manages workers.

---

## Implementation Order

Implement in this order (matches HANDOFF priority + dependency):

1. **Tier 1 modes** (Tasks 1-4): global_validate_2, struct_audit, triage_upgrade, gap_analyze
2. **Tier 2 modes** (Tasks 5-9): switch_map, exception_map, import_map, string_map, orphan_resolve_2
3. **Tier 3 modes** (Tasks 10-15): enum_catalog, sig_refine, source_tree, data_map, cross_validate_2, inline_detect

Each mode is independent — no mode depends on another being built first.

---

## Testing

After adding each mode:
1. Run `python batch_launcher.py`
2. Select the new mode radio button
3. Verify stats line shows correct counts
4. Click Generate with 2 workers
5. Verify prompt files appear in `prompts/<mode_id>/`
6. Verify output dir created at `output/<mode_id>/`
7. Spot-check prompt content — are items correctly formatted?
