# AUDIT PROMPT — F1 Challenge 99-02 Modding / Engine-Modification Capability Assessment

> Paste this whole file to an advanced model (Opus/GPT-class) running INSIDE the repo
> `%USERPROFILE%\Desktop\F1C_ghidra_project`. It must read the cited files before
> answering — do not let it reason from this prompt alone.

---

## ROLE

You are a senior reverse-engineering + game-engine architect. You are auditing a
mature RE project for **F1 Challenge 99-02** (`F1 Challenge Online.exe`, x86 PE32,
MSVC 6.0, 2002, isiMotor1 / gMotor engine). Your job is to produce a **realistic,
evidence-grounded capability assessment**: how deep can this project modify the game,
what can be ported into it, and where the hard ceilings are. The output is a
**reference compilation** that will be fed to lower-throughput models as ground truth,
so it must be self-contained, structured, and specific (addresses, offsets, file
paths, function names — not vague claims).

## HARD RULE — GROUND EVERYTHING

Read the actual files before claiming anything. When you assert a capability, cite the
evidence (file + function/offset). Distinguish **proven** (already done in-repo),
**feasible** (clear path, not yet done), and **speculative** (plausible, unverified).
Never inflate. If the evidence says "diverged / needs offset re-map", do not call it
"drop-in".

---

## WHAT ALREADY EXISTS (read these to calibrate)

Orientation + trust tiers (READ FIRST):
- `INDEX.md`, `CLAUDE.md`, `MANIFEST.md`, `docs/_README.md` — trust tiers matter: raw
  `.c` and bytes-from-exe are FACT; DS-worker docs/offsets are GUESS until verified.

Reverse-engineering assets:
- `docs/01-10` game systems, `docs/17-22` engine internals, `docs/12` ~8k globals,
  `docs/13-struct-offsets.md` + `docs/13-audit-report.md` struct layouts,
  `docs/15-analysis-limits.md` + `docs/23-gap-analysis.md` known LIMITS,
  `docs/30-impl-specs/` reimplementation specs, `docs/31-call-chains/` traces.
- `knowledge_graph/*.json` (call graph, callers, globals_usage, structs), query via
  `tools/knowledge_graph/query.py`. `tools/investigate.py` = locate+dossier tool.
- Raw decompiles: `analysis_pipeline/analyzed/` (Ghidra), `tools/decompiled_ida/` (IDA).

Proven modding capability (this is the ceiling evidence — study it):
- `tools/mod_pipeline/` — SEED/MAP/WATCH/PATCH flow, `asm_tools.py`, PLAYBOOK.
- `mods/` — SHIPPED, IN-GAME-CONFIRMED mods: `red-flag.md` / `red-flag-dll` (cut track =
  instant DQ, 3-byte patch redirecting steward penalty calls to DQ handler
  FUN_004bc0e0); `replay-ai-fix`. DLL injection is PROVEN (patched exe loads custom DLL).
- `docs/22-modding-reference.md`, `docs/16-moddable-fields.md` — moddable surface.
- Runtime: Frida traces (physics 864Hz, AI 31.7Hz), `tools/trace/`, struct dumps in
  `monitor_output/`.

Cross-binary port map (the "what could be ported" evidence — study closely):
- `docs/32-sibling-exclusive-functions.md` — F1C↔F1 2002 PORTABILITY MATRIX (two bins:
  what F1C has that F1 2002 lacks, and vice versa; genuine-exclusive vs diverged).
- `source_material/<game>/docs/40-43` — **2,357 functions in a sibling (F1 2002 /
  NASCAR Thunder 03/04 / SCGT) but NOT in F1C**, each with a **Port verdict**:
  `yes` (drop-in) / `merge` (F1C has diverged version — re-map struct offsets) /
  `data-driven` / `no` (engine-generic / not portable, e.g. SCGT Glide).
- `cross_binary/_README.md` + `cross_binary/_delta/featdiff_<game>_not_f1c.csv` — the
  raw port bins + methodology (byte-mask + TF-IDF source + string-absence matching).
- KEY CONSTRAINT documented there: matching only works within the SAME COMPILER
  GENERATION. F1 2002 + NASCAR 03/04 (2002-04) match F1C well; SCGT (1999) does not.
  Source-root differs between builds (`D:\dev\F1_1999_2002\Source\` vs
  `D:\Dev\Common\Source\`) — struct offsets may have MOVED between builds. This is the
  crux of drop-in-vs-merge.

Prior strategic analysis (context, verify against current state — some is now done):
- `work/DISCOVERY_external_sources.md`, `work/PLAN_recreation.md`, memory notes.

---

## AUDIT — ANSWER ALL, WITH EVIDENCE

### 1. Modification-depth ceiling
Enumerate the modification MECHANISMS and what each can/can't reach, with a proven
example from `mods/` where one exists:
- **Data-file** (config/.hdv/.svm) — no code change. What's exposed?
- **Byte-patch** (in-place, must fit original footprint) — proven (cut=DQ). Limits?
- **DLL hook/detour** (replace/add whole functions via injection) — proven path. What
  does it unlock that byte-patch can't? Struct-offset + calling-convention requirements.
- **Full subsystem replacement** (reimplement + hook) — feasible? Cost?
- State the HARD CEILINGS: what is impossible without partial engine rewrite (D3D8→newer,
  physics-solver restructure, adding multiplayer if absent). Cite `docs/15-analysis-limits.md`.

### 2. Portable-feature assessment (the core question)
Using `docs/32` + `source_material/<game>/docs/40-43` Port verdicts, produce a RANKED
table of the realistically portable features INTO F1C. For each:
- feature, source game, key functions (addresses), Port verdict, and WHY.
- the real blocker for `merge` ones: which struct offsets must be verified/re-mapped,
  and how (the compile-and-diff oracle, or runtime struct dump).
- Separate **genuine drop-in** (self-contained, F1C lacks the whole subsystem — e.g.
  driving school, caution system) from **merge** (diverged — e.g. HAT, NetComm) from
  **not-worth-it** (SCGT Glide-era).
Headline candidates to assess: full-course caution/safety-car (NASCAR), career/economy
(NASCAR 04), driving school (F1 2002), penalty/infraction detection, honors/achievements,
multiplayer voting + GameSpy matchmaking, replay helper, lap-timing HUD.

### 3. Effort tiers
Bucket the capability into realistic effort: **weekend mod** (byte-patch / data / small
hook), **multi-week** (self-contained subsystem port via DLL), **months / team**
(full subsystem reimpl, open-source ladder). Map the headline features to these tiers.

### 4. Open-source-recreation ladder
Assess the realistic intermediate stages between "mod" and "full open-source engine"
(subsystem-by-subsystem DLL replacement → reimplementation library → standalone sim
core → wrapper exe). Which stages are reachable now, which are labor-bound, and what's
the true bottleneck (correctness verification, not parallelism).

### 5. Risk / blocker register
List the concrete blockers with evidence: anti-tamper status (any? — the exe already
takes a custom DLL, so likely none), D3D8 lock, compiler-generation gap (SCGT),
struct-offset drift between builds, RTTI absence (`/GR-`, no class names), the 55
undocumented string-less helpers, the ~11.7k string-less byte-novels not analyzed.

---

## OUTPUT FORMAT

A single structured markdown reference titled **"F1C Capability Bible"**, sections:
1. Executive summary (3-5 sentences: how deep, realistically).
2. Modification mechanisms table (mechanism → reach → proven example → limit).
3. Portable-feature ranked table (feature → source → funcs → verdict → blocker → effort).
4. Effort tiers (weekend / multi-week / months).
5. Open-source ladder (stage → reachable? → bottleneck).
6. Risk/blocker register.
7. "For lower models" appendix: a compressed decision tree — given a desired change,
   which mechanism, which files to read, which verification step. Make this section
   copy-pasteable as a system-prompt fragment for a smaller model.

Be specific and honest. This becomes the project's canonical capability reference.
