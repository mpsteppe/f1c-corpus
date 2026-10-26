# INDEX — Start Here
> ## RELOCATION NOTICE — 2026-08-16 (Root Reorganization Batch 9)
>
> This repository's canonical location is now
> `%USERPROFILE%\Desktop\F1\research\reverse_engineering\F1C_ghidra_project`.
> Old absolute paths inside historical/deprecated scripts may remain stale;
> those paths were not mass-rewritten in this batch. See
> `%USERPROFILE%\Desktop\F1\workspace_organization_audit\ROOT_REORGANIZATION_BATCH_9_REPORT.md`.
> ## PATH CORRECTION — 2026-08-16 (audit C3)
>
> The "Key facts" section below cites the game install as
> `%USERPROFILE%\Desktop\F1 Challenge V10\...` (missing the `F1\`
> segment). Canonical paths (verified 2026-08-14) are
> `%USERPROFILE%\Desktop\F1\F1 Challenge V10` and
> `%USERPROFILE%\Desktop\F1\f1c_ida_decompiled`. Treat any literal
> missing the `F1\` segment as stale (per `f1c_ida_decompiled\AGENTS.md`).


**This is the entry point for the F1 Challenge 99-02 reverse-engineering repo.**
If you are an LLM working in this repo, read this file first, then `CLAUDE.md`.

---

## What this project is

Reverse engineering of `F1 Challenge Online.exe` (x86 PE32, MSVC 6.0, 2002).
6,868 functions mapped, full call graph, struct layouts, globals, and — as of the
latest work — a **modding capability**: surgical byte-patches authored from the
decompilation (first shipped mod: cutting the track = instant disqualification).

The reverse-engineering phase is essentially complete. Active frontier is
**modding**: understand a behavior in the binary, then change it.

**Cross-binary port map (NEW):** every isiMotor1 sibling (F1 2002, NASCAR Thunder
03/04, SCGT) was diffed against F1C. **2,357 functions that exist in a sibling but
NOT in F1C** are documented with **Port verdicts** (drop-in / merge / data-driven / no)
in `source_material/<game>/docs/40-43`. The F1C↔F1 2002 portability matrix is
`docs/32-sibling-exclusive-functions.md`. Headline portable features F1C lacks:
full-course caution/safety-car (NASCAR), career/economy (NASCAR 04), driving school
(F1 2002), penalty detection, HAT terrain. Pipeline + tools: `cross_binary/`.

---

## Trust tiers — READ THIS BEFORE TRUSTING ANY FILE

Not all information here is equal. Sorted most to least reliable:

| Tier | What | Where | Rule |
|------|------|-------|------|
| **FACT** | Raw decompiled `.c` source | `decompiled_all/`, `analysis_pipeline/analyzed/`, `tools/decompiled_ida/` | Ground truth. Trust over any doc. |
| **FACT** | Bytes read from the exe | via `tools/mod_pipeline/` | Deterministic. The final arbiter. |
| **CONFIRMED** | ISI class/function identity | `tools/cross_binary_final.csv` | Verified by NASCAR cross-match. |
| **DERIVED** | IDA exports, graphs, CSVs | `tools/*.csv`, `knowledge_graph/` | Regenerable. Accurate but mechanical. |
| **GUESS** | Global labels, struct offsets | `docs/12`, `docs/13*` | DS-worker inferred. Verify before relying. |
| **LEAD** | Call chains, semantic names | `docs/31-call-chains/`, `docs/30-impl-specs/` | **May be hallucinated.** A chain (0008) mislabeled a network function as "track grip". Treat as a hint, confirm in source. |
| **SCRATCH** | Chat logs, temp files | `ds.txt`, `opus_chat.txt`, `analysis_pipeline/_launch_*.ps1` | Historical. Do not treat as current. |

**The one rule that prevents wasted work:** for anything precise (a mod, an offset,
a value), confirm against FACT-tier raw source or an exe byte-read. Never act on a
GUESS/LEAD label alone.

---

## Repo map (current layout)

| Path | Role | Trust |
|------|------|-------|
| `CLAUDE.md` | Iron rules only (kept short by design) | authoritative |
| `REFERENCE.md` | Full project reference (layout, pipeline, IDA, formats, pitfalls) | authoritative |
| `.claude/skills/` | 15 `f1c-*` workflow skills; cold sessions start at `f1c-start-here` (router); `_meta/` holds conventions + validator | authoritative |
| `docs/` | Documentation, 00–27 by system (see `docs/_README.md` for per-file trust) | mixed |
| `decompiled_all/` | 666 string-anchored raw `.c` (identifiable functions) | FACT |
| `analysis_pipeline/` | DS-worker doc pipeline; `analyzed/` holds 6,116+ raw `.c` | FACT source + tooling |
| `tools/` | Scripts + IDA export CSVs + subtools | code + DERIVED data |
| `tools/mod_pipeline/` | **Modding: SEED/MAP/WATCH/PATCH + asm_tools + PLAYBOOK** | tooling |
| `tools/trace/` | Frida runtime tracing | tooling |
| `knowledge_graph/` | Call graph / globals / structs as JSON | DERIVED |
| `mods/` | Shipped mods (red-flag-dll) | output |
| `source_recovery/` | Binary-forensics workspace (self-contained, own ACTION_PLAN.md) | mixed |
| `roles/` | WORKER / LEAD / ARCHITECT LLM prompts | reference |
| `scripts/` | Ghidra Java extraction scripts | tooling |
| `work/` | Plans, merge scripts, working data | meta + tooling |
| `reference/` | constants.md | reference |
| `monitor_output/` | Runtime struct-dump snapshots (F1CUI/Frida) | DERIVED |
| `archive/` *(planned)* | Superseded scratch | dead |

Loose data at root (driver*.bin, strings_raw.txt, inventory.csv, etc.) is being
tidied — see `work/PLAN_reorg.md`. Nothing is deleted; scratch is archived.

---

## Common tasks → where to start

| I want to… | Start here |
|------------|-----------|
| **Cold-start a session / pick a workflow** | `.claude/skills/f1c-start-here/SKILL.md` (routes to the other 14 skills) |
| **Mod a game behavior** | `tools/mod_pipeline/MODDING_PLAYBOOK.md` (read fully first) |
| **Find a mod patch-point** (a rule to change) | `docs/35-mod-targets.md` — 155 ranked enforcement branches (only DQ confirmed; rest candidates, verify first) |
| Find a function's real source file / name | `docs/34-source-atlas.md` + `work/source_atlas.csv` (baked file/line/Class::Method) |
| Find a class's virtual methods / hook a vtable | `docs/36-vtables.md` + `work/vtables.csv` (181 recovered vtables, RTTI-less) |
| Find a physics constant / magic number | `docs/37-fp-constants.md` + `work/fp_constants.csv` (845 FP consts w/ values + readers) |
| **Investigate any address** (now shows source file, vtable role, mod-target, FP consts) | `python tools/investigate.py <addr>` — identity block auto-fuses the above |
| Understand what a function does | `tools/mod_pipeline/asm_tools.py resolve <addr>` → raw `.c` |
| Find who touches a global | `tools/mod_pipeline/mod_pipeline.py map <seed>` |
| Understand a game system | `docs/01`–`docs/10` (string-anchored, FACT-leaning) |
| Find a global's real value | `mod_pipeline.py patch --addr … ` reads the exe byte |
| Watch state live | `tools/trace/` (Frida) |
| Regenerate IDA data | `tools/ida_export_all.py` (needs IDA 9.1) |
| See current status / history | `REFERENCE.md`, `MANIFEST.md`, `work/CHANGELOG.md` |
| Reorganize the repo | `work/PLAN_reorg.md` |

---

## Key facts a fresh LLM needs

- **Exe:** `%USERPROFILE%\Desktop\F1 Challenge V10\F1 Challenge Online.exe` (ImageBase 0x400000, no ASLR — VAs match Ghidra/IDA).
- **Python:** `%USERPROFILE%\AppData\Local\Python\bin\python3.exe`
- **IDA:** `C:\Program Files\IDA Professional 9.1\idat.exe` (PowerShell only for headless).
- **Compiler:** MSVC 6.0, `/GR-` (no RTTI). thiscall = `this` in ECX; callee cleans stack via `ret N`.
- **Sibling binaries** (NASCAR 2003/2004) share 29 source files — used for `cross_binary_final.csv` identity matching.

See `MANIFEST.md` for a complete item-by-item breakdown.
