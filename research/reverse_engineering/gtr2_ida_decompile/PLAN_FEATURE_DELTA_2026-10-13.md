# GTR2 decompilation and F1C feature-delta plan

Date: 2026-10-13 (local time). Pipeline stage: **define** (plan only).
Product: F1C SDK/research platform. No product stage change.

## Objective

Build an IDA corpus for GTR2 (ISI gMotor2 lineage, SimBin 2006). Find features,
systems and functions GTR2 has that F1 Challenge 99-02 lacks. Rank them by
port value to F1C mods.

Non-goals: no GTR2 mods, no executable patching, no protection removal, no
installation changes, no live memory writes, no ports (those are later,
separate specs).

## Verified facts (2026-10-13, static, this session)

- Install: `C:\GTR2`. Treat as read-only game installation.
- `GTR2.exe` 15.8 MB, PE timestamp 2006-08-16 era, image base 0x400000.
  Extra sections `age`, `agis`, `quod`, `.rld` (4.6 MB, 2.1 MB, 3.4 MB raw).
  Strings contain `SecuROM User Access Service (V7)` and SecuROM activation URLs.
  **Retail exe is SecuROM 7 protected.** Same trap as NT2004 SafeDisc exe.
- `GTR2Dedicated.exe` 5.7 MB: clean MSVC layout (`.text/.rdata/.data/.rsrc/.reloc`),
  zero SecuROM strings. `.text` virtual size 0x2E03A4 versus GTR2.exe 0x2F0000:
  nearly the same code size. `.data` 0x865718 versus 0x866000: same globals layout
  size. Inference (unverified): dedicated build shares almost all sim/AI/rules code,
  minus rendering/UI/input.
- `net.dll` / `net_dedicated.dll`: clean, small. Netcode module, analyze too.
- F1C reference: `F1.exe` 2002-04, `.text` 0x19C5E6. GTR2 code is about 1.8x larger.

## Binary strategy

1. **Primary: `GTR2Dedicated.exe`.** Unprotected, legal to analyze (owner's copy),
   no unpacking needed. Covers physics, AI, rules, race control, pits, weather?,
   session logic, netcode, file formats.
2. **Secondary: `GTR2.exe` client-only code** (rendering, HUD, UI, cameras, FFB,
   input, sound). Needs unprotected code image. Options, owner decides:
   - a. Owner supplies a legitimate unprotected build (for example a store
     release without SecuROM) they own.
   - b. Runtime memory dump of the owner's own running process (NT2004 fallback
     precedent). Agent does not download cracks or retail files.
   - c. Skip: dedicated covers most port-relevant sim code.
   Decide after Phase 3 shows what is missing from dedicated.
3. Copy binaries to `research\reverse_engineering\gtr2_ida_decompile\bin\`
   with SHA-256 manifest; never analyze in `C:\GTR2`.

## Phases

### Phase 0: orient and record (Claude, 0.5 day)
- Cold-start per root `AGENTS.md`; workspace validator.
- Hash all GTR2 binaries; record versions (`Readme.txt`, PE timestamps).
- Create `HANDOFF.md` copying NT2004 layout. Index in `research\README.md`.

### Phase 1: IDA database (Claude, headless)
- `idat.exe -A -S` with `idaapi.auto_wait()` first, `qexit(0)` last,
  file logging (NT2004 HANDOFF gotchas 1-4). Never `-B`.
- Sanity gate: function count in the thousands; entry in `.text`;
  Hex-Rays output readable on 10 sampled functions. Fail = stop.
- Apply FLIRT for MSVC 7.1 runtime (`msvcr71`, `msvcp71` imports) to strip
  library noise.

### Phase 2: bulk extraction (scripts, reuse NT2004 tooling)
Clone and rename from `nt2004_ida_decompile`:
`batch_decompile.py`, `extract_strings.py`, `skeleton_extract.py`,
`render_skeleton_nt2004.py`, `build_priority_index_nt2004.py`,
`tools_crossmatch*.py`, `tools_anchor_names.py`, `skeleton_batch_launcher_nt2004.py`.
Outputs: `functions\*.c`, `strings_index.json`, `callgraph.json`, `skeletons\`.

### Phase 3: cross-match against F1C (Claude scripts, deterministic)
Goal: label every GTR2 function **matched / changed / new**.
- Anchor 1, strings: shared format strings, log messages, INI/PLR/GDB keys.
  F1C corpus names transfer to GTR2 functions referencing the same unique string.
- Anchor 2, structural: call graph neighbourhood, constants (physics magic
  numbers), basic-block shape. Reuse `tools_crossmatch2.py` trusted/junk split.
- Anchor 3, optional: BinDiff or Diaphora on F1C `.i64` versus GTR2 `.i64`
  for a third opinion. Install only if owner approves.
- Propagate F1C names (7,143 functions in `f1c_ida_decompiled\functions`) into
  GTR2 IDB as `f1c_<name>` with confidence tag.
- Output: `crossmatch_gtr2.json`, `gtr2_unmatched.json` = **new-function
  candidate list**. Expect thousands; that is the DeepSeek workload.

### Phase 4: DeepSeek skeleton fill (DeepSeek, Claude reviews)
Same pipeline as F1C/NT2004 (`RUNBOOK_SKELETON_BATCH.md`):
- Agents `f1c-ida-skeleton` (flash), `-pro`, `-free` fallback; new agent
  prompt variant `gtr2-ida-skeleton` adds field `f1c_counterpart` and
  `delta_kind` (new / extended / renamed / same).
- Pilot first: 1 chunk x 25 funcs. Claude reviews, then `validate_analysis.py`
  gate: 0 arithmetic, 0 ungrounded.
- Order: unmatched functions referenced by unique GTR2 strings first, then
  priority index (call fan-in, size), library-tagged last or skipped.
- Pro tier only for monsters (AI main, physics step, rules/penalty core).
- DeepSeek gets mechanical specs only; Claude reviews every batch at stops.

### Phase 5: feature delta survey (Claude, DeepSeek assists)
String- and config-driven hunt. GTR2 features expected beyond F1C (hypotheses,
each to verify in code):
- Rules: drive-through/stop-go penalties, flag rules, cutting detection,
  full-course yellow, rolling start / formation lap, mandatory pit window,
  driver swaps (endurance), 24h time-based races.
- Race control: Safety Car (GTR2 has pace car) - compare with NT2004 map
  and our SC mod.
- Sim: tyre thermal/wear model (4-node?), brake temperature, damage and
  mechanical failures, fuel model, track rubbering / grip evolution,
  day-night transition, dynamic weather / wet track.
- AI: AI pit strategy, AI mistakes, wet AI, AI tyre choice.
- Hardware: FFB effects, Real Feel style steering, wheel LED / dashboard
  telemetry, plugin interface (`InternalsPlugin` style API, if present).
- Online: net.dll changes, dedicated server admin, rejoin.
- UI/HUD: in-car displays, pit menu (MFD), replays.
Method per feature: GDB/PLR/HDV/INI keys in `GameData`/`UserData` -> string
xrefs -> function cluster -> F1C counterpart check -> verdict.

Output: `FEATURE_DELTA_GTR2_<date>.md` table: feature, GTR2 functions,
F1C status (absent / partial / modded already), port difficulty, value.

### Phase 6: SDK integration and findings
- Append every proven/disproven/open delta to
  `f1c_ida_decompiled\findings.jsonl` (tier + evidence + source), backup first.
- Register GTR2 corpus in SDK front door if `f1c_mod.py` supports extra
  corpora; else record as follow-up.
- Top 3 port candidates get separate define/specify tickets.

## Acceptance criteria

- Corpus reproducible from hashed binary with committed scripts.
- Every GTR2 function tagged matched / changed / new with confidence.
- Validator gate passes on all filled skeletons.
- Feature delta table: each row cites function addresses and evidence tier.
- Findings appended; `research\README.md` indexes corpus.

## Risks and abort conditions

- Dedicated exe lacks client systems: expected; triggers Phase 1b decision.
- gMotor2 drift too large for string anchors: fall back to BinDiff; if match
  rate under 20 %, stop and re-plan.
- DeepSeek quota: runbook account swap / free model fallback.
- Disk: no game copies in workspace; only hashed binaries + IDB (retention
  policy: knowledge store kept, per-run output to `%TEMP%`).
- Abort if any step would need protection bypass without owner decision.

## Owner decisions needed

1. Approve `GTR2Dedicated.exe` as primary target.
2. Client exe route: a (owned unprotected build), b (own-process dump), or c (skip).
3. BinDiff/Diaphora install: yes/no.
4. DeepSeek budget: flash only, or flash + pro for monsters.
5. Priority features for Phase 5 (default: rules/penalties, pit/driver swap,
   tyre/weather, FFB).

## Pending validation

Everything in "Verified facts" is static file inspection only. Code-sharing
between dedicated and client is inference until Phase 3.
