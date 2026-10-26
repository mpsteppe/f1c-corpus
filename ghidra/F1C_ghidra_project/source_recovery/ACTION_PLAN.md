# Source Recovery — Action Plan

Master task list. Each task has a phase, ID, status, and clear deliverable.
Status: `TODO` | `ACTIVE` | `DONE` | `BLOCKED(reason)`.

No task depends on another unless marked with `AFTER: XX`.
Any session can pick up any `TODO` task — each is self-contained.

---

## Phase 1: Binary Forensics (F1C exe only, no downloads needed)

These run against the existing `F1 Challenge Online.exe` at
`%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe`.

### BF-01: PE Rich Header Decode
**Status:** DONE (2026-07-16)
**Tool:** Python `pefile` or manual hex parse
**Deliverable:** `01_binary_forensics/rich_header.md`
**What:** Decode XOR-encrypted Rich header. Extract:
- Exact MSVC compiler version (cl.exe build number)
- Exact linker version
- Number of compilation units (= number of .cpp files compiled)
- Which toolchain components used (C vs C++ compiler, assembler, resource compiler)
**Value:** Compilation unit count tells us how many .cpp files exist (we found 35 — how many are we missing?). Compiler version pins the exact MSVC release for binary pattern matching.
**How:**
```python
import pefile
pe = pefile.PE(r"%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe")
# Rich header is pe.RICH_HEADER if pefile supports it
# Otherwise: manual parse from offset after "DanS" marker
```

### BF-02: RTTI Pattern Scan
**Status:** DONE (2026-07-16)
**Deliverable:** `01_binary_forensics/rtti_scan.md`
**What:** Scan entire binary for `.?AV` (hex `2E 3F 41 56`) pattern.
Each hit is a mangled MSVC class name. Demangle with `undname.exe` or Python.
**Value:** Original ISI class names (CCarPhysics, CTireModel, etc.) — if RTTI was enabled.
**Note:** CLAUDE.md says "No RTTI (`/GR-`)" based on IDA vtable scan yielding 0 results. But that scan looked for vtable RTTI pointers specifically. A raw byte scan for `.?AV` is a different check — the binary may have partial RTTI from statically linked libraries even if the game code was compiled with `/GR-`.
**How:**
```python
with open(exe_path, 'rb') as f:
    data = f.read()
hits = []
idx = 0
while True:
    idx = data.find(b'.?AV', idx)
    if idx == -1: break
    end = data.find(b'\x00', idx)
    name = data[idx:end].decode('ascii', errors='replace')
    hits.append((hex(idx), name))
    idx += 1
```

### BF-03: Debug Directory & PDB Path
**Status:** DONE (2026-07-16)
**Deliverable:** `01_binary_forensics/debug_directory.md`
**What:** Read PE optional header debug directory entry. Extract:
- PDB file path (reveals original build directory: `D:\dev\F1_1999_2002\...`)
- Debug type (COFF, CodeView, MISC)
- Build timestamp (exact build date)
**Value:** Build directory structure, confirmation of source tree layout.
**How:** `dumpbin /headers` or `pefile` in Python.

### BF-04: Deep String Forensics
**Status:** DONE (2026-07-16)  
**AFTER:** BF-02
**Deliverable:** `01_binary_forensics/strings_forensic.md`
**What:** Beyond what we already extracted in `tools/trace_rename_table.csv`, scan for:
- `assert` / `verify` macro remnants (`%s(%d)` patterns with .cpp filenames)
- Format strings revealing parameter types (`%f`, `%d`, `%s` in context)
- Build environment strings (paths, usernames, server names)
- Any strings NOT in `ida_strings.csv` (IDA may have missed some)
**Value:** Additional .cpp filenames, line numbers, developer names.

### BF-05: Import/Export Table Analysis
**Status:** DONE (2026-07-16)
**Deliverable:** `01_binary_forensics/import_export.md`
**What:** Full import table with call-site mapping. For each DLL import:
- Which game functions call it (from knowledge_graph)
- Subsystem assignment
Also check: does exe export anything? (Unusual for game exe but possible.)
**Value:** Maps DLL boundaries. Identifies which D3D version (d3d8 vs d3d9).
Determines proxy DLL target for Phase 4.

---

## Phase 2: Cross-Binary Analysis (requires downloads)

### CB-01: Download Inventory
**Status:** DONE (2026-07-16)
**Deliverable:** `02_cross_binary/inventory.md`
**What:** Binaries available in `%USERPROFILE%\Desktop\source_material\`:
1. **F1 2002 WIP Demo** — HAVE (InstallShield SFX, 54MB, needs extraction)
2. **Sports Car GT PC** — HAVE (full install + v1.551 patch + widescreen fix)
3. **Sports Car GT PS1** — HAVE (CD image, 12 tracks)
4. **NASCAR Thunder 2003 Demo** — HAVE (extracted, 1.9MB exe)
5. **NASCAR Thunder 2003 Retail v1.1** — HAVE (ISO + patch)
6. **NASCAR Thunder 2004 Demo** — HAVE (extracted, 2.2MB exe)
7. **NASCAR Thunder 2004 Retail retail** — HAVE (2.2MB exe)
8. **InternalsPlugin.hpp** — HAVE (rFactor SDK header, 367 lines)
9. **F1 2000** — HAVE (full install, game .ICD + F1Config.exe debug build + Season00 data)
10. **rFactor** — HAVE (full install, 4.1MB game exe + dedicated + config + 3 plugins)
Still needed: Poochihead patched exe (Discord), F1C Developer Toolbox (MEGA)

### CB-02: F1 2002 WIP Demo Analysis
**Status:** DONE (2026-07-16)
**AFTER:** CB-01
**Deliverable:** `02_cross_binary/diff_results/f1_2002_demo.md`
**What:** Run full BF-01 through BF-05 on the demo exe. Then diff against F1C:
- Compare Rich headers (same compiler?)
- Compare RTTI hits
- Compare string tables (new debug strings?)
- Check for PDB path / debug directory
- Function count comparison
**Value:** WIP builds often have debug info the release stripped.

### CB-03: Sports Car GT Analysis
**Status:** DONE (2026-07-16) — partial (string/section analysis, no deep decompile)
**AFTER:** CB-01
**Deliverable:** `02_cross_binary/diff_results/sports_car_gt.md`
**What:** SCGT is oldest isiMotor1. 8 PE sections (unusual .text+CODE+DATA+CONST). 
No source paths, no RTTI, no debug info. 406 strings shared with F1C+NASCAR.
Glide/3Dfx primary renderer. CUBE engine string present.
**Remaining:** Deep Ghidra/IDA analysis of SCGT exe for function matching vs F1C.

### CB-05: NASCAR Binary Cross-Reference
**Status:** DONE (2026-07-16) — string-level analysis complete
**Deliverable:** Entry in `FINDINGS.md` (2026-07-16 Full Source Material Inventory)
**What:** All NASCAR 2003/2004 binaries analyzed:
- Source paths: D:\Dev\NASCAR_2003\Source\ and D:\Dev\NASCAR_2004\Source\ (32 files each)
- 3DConfig.exe has DEBUG PDB paths and debug directories (both 2003 and 2004)
- CUBE41 (2003) vs CUBE42 (2004) renderer versioning discovered
- ISIUtility\Source\FileLine.cpp = shared debug utility
- pitman.cpp and random.cpp unique to NASCAR (not in F1C)
- Near-identical source file list confirms shared isiMotor1 codebase
**Remaining:** Deep function-matching between NASCAR exes and F1C (Ghidra/BinDiff)

### CB-06: F1 2000 Full Analysis
**Status:** DONE (2026-07-16)
**Deliverable:** Entry in `FINDINGS.md` (2026-07-16 F1 2000 Analysis)
**What:** Full install at `source_material/F1 2000/`. Three executables analyzed:
- F1_2000.exe (253KB) — SafeDisc launcher, not game engine
- F1_2000.ICD (1.49MB) — real game exe: 10 sections, 581 Rich units, DDRAW/DINPUT/DSOUND, PDB path `D:\Dev\F1\WIN32\Gold\f1_2000.pdb`
- F1Config.exe (602KB) — debug build: PDB `D:\Dev\F1\CONFIG\Debug\F1Config.pdb`, CUBE engine strings
**Key findings:** Pre-D3D8 architecture (DirectDraw), pre-Miles audio (TbAudioR/QMixer), 22 C++ mangled symbols with ISI class names, .veh physics config format = direct ancestor to F1C .hdv/.pm. Dev tree root: `D:\Dev\F1\`

### CB-07: rFactor Analysis
**Status:** TODO
**Deliverable:** `02_cross_binary/diff_results/rfactor.md`
**What:** Full rFactor install at `source_material/rFactor/`. Analyze:
- rFactor.exe (4.1MB) — isiMotor 2.0, likely has RTTI, more debug info
- rFactor Dedicated.exe (4.7MB) — dedicated server
- rF Config.exe (917KB) — config utility
- 3 plugin DLLs: NetCommUtilPlugin, RaceCastPlugin, rFactorTrackIRPlugin
**Value:** isiMotor 2.0 = next-gen engine. RTTI scan may yield ISI class names. String analysis for evolved parameter names.

### CB-04: Poochihead Patch Diff
**Status:** TODO
**AFTER:** CB-01
**Deliverable:** `02_cross_binary/diff_results/poochihead_patches.md`
**What:** Binary diff patched exe vs retail. Every changed byte = a known function/address that someone already located and understood. Map changed addresses to our function database.
**Value:** Free ground-truth verification of specific function identifications.

---

## Phase 3: rFactor SDK Cross-Reference

### SDK-01: Download and Index Headers
**Status:** DONE (2026-07-16) — InternalsPlugin.hpp in headers/
**Deliverable:** `03_sdk_crossref/headers/` (files) + `03_sdk_crossref/class_hierarchy.md`
**What:** Download from the OverTake.gg tools pack:
- `InternalsPlugin.hpp`
- `RFPluginObjects.hpp`
- Example.cpp
- rFactorInternalsPlugin.pdf
Index all struct definitions, class hierarchies, enum values.

### SDK-02: Struct Alignment Check
**Status:** TODO
**AFTER:** SDK-01
**Deliverable:** `03_sdk_crossref/struct_alignment.md`
**What:** Take `TelemInfoBase`, `TelemWheel`, `ScoringInfoV2` struct layouts from SDK.
Compare field-by-field against our `docs/13-struct-offsets.md` offsets.
For each field: MATCH / SHIFTED / MISSING / NEW.
**Value:** Validates or corrects our struct reconstruction. rF1 is one generation ahead (isiMotor 2.0 vs 1.5), so expect similar-but-shifted layouts.

### SDK-03: Hardware Control String Grep
**Status:** TODO
**AFTER:** SDK-01
**Deliverable:** `03_sdk_crossref/hardware_controls.md`
**What:** The rF1 PDF lists 80+ hardware control names (SteeringHelp, TractionControl, AntiLockBrakes, ToggleAIControl, etc.). Grep every one against:
- `ida_strings.csv`
- `inputs/raw_strings/strings_raw.txt`
- All decompiled .c files in `analysis_pipeline/analyzed/`
Each hit maps a decompiled function to a known ISI feature name.
**Value:** Direct function naming from official ISI terminology.

### SDK-04: Game Phase Enum Validation
**Status:** TODO
**AFTER:** SDK-01
**Deliverable:** Entry in `FINDINGS.md`
**What:** `ScoringInfoV2` defines game phases 0-8:
0=before session, 1=recon, 2=grid, 3=formation, 4=starting lights,
5=green flag, 6=caution, 7=stopped, 8=over.
Compare against our RacePhase values from Frida traces.
Our trace showed: 0->2->4->5->8 in noplayer mode.
**Value:** Validates or corrects our RacePhase enum names in docs/15.

---

## Phase 4: DLL Modification Framework

### DLL-01: Identify Proxy Target
**Status:** TODO
**AFTER:** BF-05
**Deliverable:** `04_dll_framework/architecture.md`
**What:** From import table analysis, determine which DLL to proxy:
- d3d8.dll or d3d9.dll (rendering)
- dinput8.dll (input, button limit fix)
- Or: does F1C have a native plugin loader? (Search for GetPluginName/CreatePluginObject strings)
Document the loading mechanism and interface.

### DLL-02: Minimal Proxy Skeleton
**Status:** TODO
**AFTER:** DLL-01
**Deliverable:** `04_dll_framework/src/` (compilable C++ project)
**What:** Create a minimal proxy DLL that:
1. Forwards all calls to real system DLL
2. Logs that it loaded successfully
3. Has a hook registration system (MinHook)
4. Reads hook addresses from a config file (so we don't recompile per change)
**Toolchain:** Match original game's era — MSVC, 32-bit, cdecl/stdcall.

### DLL-03: First Hooks (proof of concept)
**Status:** TODO
**AFTER:** DLL-02
**Deliverable:** Working DLL that modifies one behavior
**What:** Pick 3 hooks from known functions:
1. A simple constant override (e.g., AI car count cap)
2. A parameter redirect (read from config instead of hardcoded)
3. A logging hook (dump struct data at a known physics function)
This proves the pipeline: identify function -> write hook -> test in game.

---

## Phase 5: Automated Trace Pipeline

### AT-01: AHK Script Suite
**Status:** TODO
**Deliverable:** `05_automation/ahk_scripts/` (one .ahk per scenario)
**What:** Write AHK scripts for the reliably-automatable scenarios:
1. `startup_shutdown.ahk` — launch, wait for menu, close
2. `menu_options.ahk` — navigate all settings screens
3. `track_load.ahk` — select track, load, wait, ESC, exit (parameterized per track)
4. `race_nointeraction.ahk` — start race, wait N seconds, ESC
5. `race_scripted_input.ahk` — throttle/brake/steer sequence
6. `session_transitions.ahk` — practice -> qualify -> race
7. `replay_scrub.ahk` — enter replay, scrub forward/back
Each script: pixel-check waits, fixed coordinates at known resolution, clean exit.
**Prerequisite:** Calibrate at a fixed resolution (e.g., 1024x768 windowed).

### AT-02: Frida Integration Script
**Status:** TODO
**AFTER:** AT-01
**Deliverable:** `05_automation/trace_configs/` + orchestrator script
**What:** Python orchestrator that:
1. Launches AHK script
2. Attaches Frida when game window appears
3. Installs scenario-specific hook set
4. Records to `05_automation/results/<scenario>_<timestamp>.log`
5. Kills game after AHK script completes
Build on existing `tools/trace/trace_comprehensive.py`.

### AT-03: Multi-Scenario Overnight Run
**Status:** TODO
**AFTER:** AT-01, AT-02
**Deliverable:** Complete trace library in `05_automation/results/`
**What:** Run all scenarios sequentially. Compare traces.
Specific repetition-required scenarios:
- All tracks (one run each)
- All cars on same track (one run each)
- Same car/track 3x (determinism check)
- Different AI counts (1, 10, max)
- Different race durations (10s, 30s, 120s)

---

## Phase 6: Community Source Recovery

### CS-01: F1CUI Plugin Offset Extraction
**Status:** TODO
**Deliverable:** `06_community_sources/modder_offsets.md`
**What:** Extract hardcoded offsets from known community files:
- `F1CUILivePlugin*.ini`
- `oph.ini`
- `steeringwheel.ini`
- Any custom DLL (disassemble if no source)
These contain field offsets someone already verified by testing.
**Note:** This was Source 2 in `work/DISCOVERY_external_sources.md`. Partially started.

### CS-02: Wayback Machine Trawl
**Status:** TODO
**Deliverable:** `06_community_sources/developer_interviews.md`
**What:** Search Wayback Machine for:
- `racesimulations.com` forum threads June-July 2003 (Tom Oliver ISI interview)
- `emacberry.com` / `emacf1.emacberry.com` mirrors
- rFactor Dev Corner Q&As (Pete Knepley, Joe Campana, Brad Shuber, Terence)
- GameSpy F1C forum archives
Extract any ISI developer statements about engine architecture.

### CS-03: Download Links Catalog
**Status:** TODO
**Deliverable:** `06_community_sources/downloads.md`
**What:** Verify and catalog all download links from Opus chat:
- F1 2002 WIP Demo: gamepressure.com
- Sports Car GT: archive.org
- rF1 tools pack: overtake.gg
- Poochihead exe: Discord
- rFactor Internals PDF: rfactor.net
- ISI modding tutorial: tirewall.net
Mark each: VERIFIED / DEAD / NEEDS-LOGIN.

---

## Priority Order

**Do first (no downloads, immediate results):**
BF-01, BF-02, BF-03, BF-05 — all run against local exe

**Do second (quick wins with downloads):**
SDK-01, SDK-03, SDK-04 — rFactor headers are freely downloadable
CS-01 — community files may already be in game directory

**Do third (requires larger downloads):**
CB-01 through CB-04 — game binaries from archive.org
CS-02, CS-03 — web research

**Do fourth (builds on earlier findings):**
DLL-01 through DLL-03 — needs import table (BF-05)
SDK-02 — needs both SDK headers and our struct data

**Do last (builds on everything):**
AT-01 through AT-03 — automation pipeline
Phase 4 advanced hooks — needs validated struct layouts

---

## Session Handoff Rules

1. **Starting a task:** Set status to `ACTIVE` in this file. Note session date.
2. **Completing a task:** Set status to `DONE`. Write findings to the deliverable file AND append a summary to `FINDINGS.md`.
3. **Blocked:** Set status to `BLOCKED(reason)`. Do not leave tasks silently incomplete.
4. **This file is the single source of truth.** Do not create separate TODO lists elsewhere.
5. **No task modifies `docs/` directly.** All doc changes go through `FINDINGS.md` -> `work/CHANGELOG.md` -> merge.
