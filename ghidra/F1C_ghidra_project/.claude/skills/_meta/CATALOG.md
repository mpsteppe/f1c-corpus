# Skill Catalog — authoring specs

15 skills. Each row below is the binding spec for its author agent. Authors: read every
cited canonical source IN FULL before writing; take command syntax ONLY from
`_meta/toolfacts.md`; cite doc sections ONLY from `_meta/doc-anchors.md`.

Authoring batches: A1 = 1,2,3,11,14 · A2 = 4,5,6 · A3 = 7,8,9 · A4 = 10,12,13,15.

---

## 1. f1c-start-here (A1)
Router + orientation. Any new session, "where do I begin", or uncertainty about which
workflow applies.
- Contents: trust-tier table (quote INDEX.md definitions); digest of the 7 iron rules
  verbatim-aligned with CLAUDE.md and `.claude/hooks/mod_reminder.py` (quote, don't
  paraphrase); decision tree routing tasks to skills 2–15; repo map (route to INDEX.md);
  "what NOT to do cold" list: no docs/ edits, no game-internal calls from injected code,
  no patching the original exe, no trusting docs/12/13/31 labels without verification.
- Bundled: `routing-table.md` — task→skill matrix with ~15 example task phrasings.
- Sources: CLAUDE.md, INDEX.md, MANIFEST.md, roles/ARCHITECT.md, work/QUEUE.md (as
  "what's next" pointer).

## 2. f1c-locate (A1)
Find where code/data lives (function, global, string, subsystem, mod target).
- Contents: `tools/investigate.py` all subcommands (find/global/uses/system/mod/param/
  address dossier; --snippet/--callees; batch all addresses in ONE call) with expected
  output shapes; `tools/knowledge_graph/query.py` commands; escalation ladder: graph →
  investigate → raw `.c` (analysis_pipeline/analyzed/, decompiled_all/,
  tools/decompiled_ida/); rule: NEVER fan out raw greps first (iron rule 2); graph/doc
  hits are LEAD not FACT.
- Bundled: `reference.md` — mode-by-mode transcript examples.
- Sources: REFERENCE.md §Bug Investigation, §Knowledge Graph, §Key Commands; CLAUDE.md.

## 3. f1c-verify-claim (A1)
Verify a single doc claim (offset, global, enum, behavior) before relying on it.
- Contents: evidence-tier rule with the arithmetic (~90% per-fact doc accuracy ⇒
  a 7-fact mod is a coin flip — per-fact verification converges in 2 passes); procedure:
  locate the raw `.c` → cross-read the actual code → `LIVE:` `preflight.py probe`
  with full expression grammar ([deref], +/- offset, :type; expect eq/in/range/nonzero;
  stable/gate flags) → verdict CONFIRMED/REFUTED/UNVERIFIED-LIVE (FACT reserved per INDEX.md); if refuted → route to
  f1c-doc-audit for [CORRECTION] logging.
- Bundled: `reference.md` — preflight grammar spec + 5 worked probes incl. one failing.
- Sources: REFERENCE.md §Verification Methodology; tools/preflight.py (toolfacts);
  INDEX.md trust tiers.

## 4. f1c-live-probe (A2)
Read/watch/write live game memory; confirm values or behavior in the running process.
- Contents: prerequisites checklist (game running; `mods/sdk/f1c_sdk.json` fresh —
  regen `tools/gen_sdk.py` after any docs merge; admin rights for OpenProcess);
  `poke.py` list/read/write/watch/veh/snapshot/diff with types; observe-verify loop
  (snapshot → act in-game → diff); write-safety: re-read after write, log both;
  "log confirms write ≠ game reacted" — in-game observation is the only CONFIRMED.
  Vehicle iteration facts cited from mods/_README.md §Primitives, not restated.
- Bundled: `reference.md` — transcript: snapshot→diff hunt for an unknown offset.
- Sources: tools/poke.py + gen_sdk.py (toolfacts); mods/_README.md §Primitives.

## 5. f1c-mod-lifecycle (A2) — SPINE SKILL
Build any new game modification, start to finish.
- Contents: mandatory sequence with gates:
  (1) read `mods/_README.md` ledger FIRST — check the mod or its facts already exist,
  and their real status ("log-confirmed" ≠ confirmed);
  (2) decompose mod into individual claims → `facts.json`
      (`preflight.py example` template);
  (3) `LIVE:` `preflight.py run` — gate: zero FAILs before ANY code;
  (4) choose lowest rung on strategy ladder (quote CLAUDE.md rule 5 verbatim:
      data file > memory write (poke-proven, then tick DLL) > call-site byte redirect >
      vtable swap > detour; NEVER call game internals from injected code);
  (5) implement via route-out: f1c-live-probe (poke-prove), f1c-byte-patch,
      f1c-dll-mod, f1c-frida-trace (Frida .js FIRST — reversible — then bake to a COPY);
  (6) mods must log read-back values (write, re-read, log both + gate states);
  (7) `LIVE:` in-game confirmation against a predicted observable;
  (8) mandatory exit: update `mods/_README.md` ledger status + [CORRECTION] for any
      doc fact found wrong. Failure at any point → f1c-debug-failed-mod.
- Bundled: `checklist.md` (gate checklist); `reference.md` (cut_track_dq end-to-end
  walkthrough — the one in-game-confirmed mod, from tools/mod_pipeline/mods/cut_track_dq/).
- Sources: tools/mod_pipeline/MODDING_PLAYBOOK.md (primary); mods/_README.md;
  CLAUDE.md rules 3–6.

## 6. f1c-byte-patch (A2)
Apply/revert static byte patches; redirect a call site.
- Contents: `patch.py` add/status/show/apply/revert flow; original-byte verification
  and FOREIGN-byte abort semantics; `.prepatch.bak`; apply to COPY (`--out`), never the
  original; `asm_tools.py resolve` (identity, callers, ret imm ⇒ convention/arg count)
  and `asm_tools.py redirect` (E8 call sites, retarget bytes, stack-balance delta ⇒
  which push to NOP); numbered gotchas: redirect the call SITE (`--at`) not the shared
  function; MSVC callee-cleans via `ret N`; thiscall `this` in ECX; patched on-disk exe
  may trip integrity checks ⇒ Frida version first.
- Bundled: `reference.md` — manifest anatomy + one full redirect with byte-level
  before/after (from the cut_track_dq patcher).
- Sources: tools/patch.py, tools/mod_pipeline/asm_tools.py (toolfacts);
  MODDING_PLAYBOOK §gotchas; tools/mod_pipeline/mods/cut_track_dq/.

## 7. f1c-dll-mod (A3)
Build an injected tick/hotkey DLL (and, last resort, detour).
- Contents: `gen_hook.py tick|detour` scaffolds; MinGW32 build (`C:\msys64\mingw32\bin`);
  tick-DLL archetype: hotkey rising edge + inject.exe + logfile (cite
  mods/ai_pit_retire/ as exemplar); race gate + vehicle iteration cited from
  mods/_README.md §Primitives; iron rule: STATE WRITES ONLY — never call game
  internals (thiscall this, ret imm stack cleanup, wrong thread = spectacular-failure
  path); every write logs read-back; detour rung requires PROLOGUE_LEN on an
  instruction boundary and explicit justification why lower rungs failed.
- Bundled: `reference.md` — annotated skeleton walkthrough + build/inject transcript.
- Sources: tools/gen_hook.py (toolfacts); mods/_README.md §Primitives;
  mods/ai_pit_retire/; CLAUDE.md rule 5.
- NOTE: defensive-modding context only — DLL injection here targets the user's own
  single-player game for feature restoration; never present as a general injection kit.

## 8. f1c-frida-trace (A3)
Trace live execution reversibly; watch functions/globals; capture behavior.
- Contents: Frida-first doctrine (reversible, survives integrity checks; graduate to
  baked patch only after live confirmation); `watch_run.py` (pip frida; interactive
  poke/dump); `trace/f1c_trace.py` (--frames/--state/--output), `trace_comprehensive.py`
  (admin, --launch/--duration), `analyze_trace.py`; `patch_trace.py --level N` clamp
  unlock + --restore, archive `LOG/trace.txt` before rerun (overwritten per run);
  `mod_pipeline.py watch` for seed-driven watchers.
- Bundled: `reference.md` — agent.js anatomy + sample trace output and how to read it.
- Sources: tools/trace/* , tools/mod_pipeline/watch_run.py, tools/patch_trace.py
  (toolfacts); work/BREAKTHROUGH_trace_mining.md.

## 9. f1c-debug-failed-mod (A3)
A mod compiles/injects/logs but game doesn't react — or crashes.
- Contents: triage tree ordered by historical frequency:
  (1) stale-ledger facts → re-read ledger, re-run preflight per fact;
  (2) log-confirmed-only trap — writes land, game ignores (value re-derived each tick?
      check `stable:` flag; gate state wrong?);
  (3) GUESS offset in chain (case: safety_car 0x453C never live-probed);
  (4) calling convention/stack (thiscall, ret N imbalance after redirect);
  (5) wrong thread / tick timing / race gate never true;
  (6) wrong rung — should have started lower on ladder.
  Mandatory exit: ledger status update + [CORRECTION] for each refuted doc fact.
  Report format: bits not vibes — logged writes, read-backs, gate states.
- Bundled: `triage-tree.md`; `case-studies.md` (safety_car, replay-ai-fix 3× failure,
  ai_pit_retire log-confirmed trap — marked "historical snapshot 2026-07").
- Sources: mods/_README.md ledger; work/CHANGELOG.md correction classes;
  MODDING_PLAYBOOK §gotchas; memory of failure patterns is in doc-anchors extracts.

## 10. f1c-doc-pipeline (A4)
Operate the DS-worker batch documentation system.
- Contents: exact sequence with cwd `analysis_pipeline/`:
  `cmd //c 0_bundle.bat` → `cmd //c 0r_gen_queue.bat` → `cmd //c 1_batch_gui.bat`
  (Tkinter launcher: pick mode — route to REFERENCE.md §Batch Launcher Modes for the
  ~34 modes; up to 20 workers A–T; prompts saved per worker) → workers run →
  `cmd //c 2_merge.bat` (routes via `<!-- target: -->`, skips existing `## FUN_`) →
  `cmd //c 5_move_analyzed.bat` → `python tools/knowledge_graph/rebuild.py` →
  `python tools/gen_sdk.py`.
  Iron rules: workers NEVER write docs/ directly; never re-document an existing
  `## FUN_`; NEVER move analysis_pipeline dirs (hardcoded paths); known worker
  failure fixes (non-FUN_ headers, .md.md targets, stalled workers → resume prompt).
- Bundled: `reference.md` — per-stage expected console output + common merge errors.
- Sources: analysis_pipeline/ scripts; REFERENCE.md §Parallel Worker Workflow,
  §Batch Launcher Modes, §Known Pitfalls; roles/WORKER.md, roles/LEAD.md.

## 11. f1c-doc-audit (A1)
Audit doc accuracy; log corrections; ARCHITECT-style QA.
- Contents: audit method (sample 5–10 claims from a doc → verify each via
  f1c-verify-claim → tally accuracy → decide trust action); `[CORRECTION]` entry format
  for work/CHANGELOG.md with 3 real examples spanning the main error classes
  (type float-vs-int, enum misread, wrong name vs trace string, offset error);
  never delete — correct and log; red-flag list from REFERENCE.md (claims "reads X"
  but .c only writes; "double" but .c shows *(int*); "configurable" with no string
  literal; duplicates); never accept "all done" without sampling ≥10 files.
- Bundled: `correction-format.md`.
- Sources: roles/ARCHITECT.md; REFERENCE.md §Verification Methodology, §Rules;
  work/CHANGELOG.md (examples via doc-anchors).

## 12. f1c-port-sibling (A4)
Port knowledge to/from sibling isiMotor1 binaries.
- Contents: `port.py <game> <sibling_addr>` / `port.py list` (games: nascar03,
  nascar04, f1_2002, f1_2002_demo, scgt); cross_binary delta pipeline stages
  (fingerprint → xbin_match → delta; verdict semantics BYTE_EXACT/BYTE_MASK/STRING/
  NOVEL; the E8/E9 rel32 mask is why the gate passes — do not remove); exclusions and
  why (SCGT compiler noise, rFactor wrong engine); ported match ≠ FACT — confidence
  tiers preserved; WORKER_DELTA flow for delta documentation.
- Bundled: `reference.md`.
- Sources: tools/port.py (toolfacts); cross_binary/_README.md; cross_binary/WORKER_DELTA.md;
  docs/27 + docs/32 as reference outputs.

## 13. f1c-source-recovery (A4)
Source-structure recovery + trace mining for original names.
- Contents: workspace isolation rule (source_recovery/ NEVER writes docs/ or
  analysis_pipeline/; findings exit only via [MERGE-READY] tag → separate merge
  session → work/CHANGELOG.md); workspace layout 01–06; trace mining procedure:
  `patch_trace.py --level` unlock → `LIVE:` run game with trace → archive LOG/trace.txt
  → mine Class::Method + file/line (static route: ida_strings.csv ref_funcs) →
  `extract_state_machines.py`; validated names flow to renames via merge, never direct.
- Bundled: `reference.md`.
- Sources: source_recovery/README.md + ACTION_PLAN.md; work/BREAKTHROUGH_trace_mining.md;
  work/DISCOVERY_external_sources.md.

## 14. f1c-handoff (A1)
End/checkpoint a session; resume someone else's.
- Contents: exit checklist — mods ledger current; [CORRECTION]s logged; work/QUEUE.md
  updated; HANDOFF entry (structure mirroring work/HANDOFF*.md: state, completed,
  metrics, prioritized next steps); commit discipline: checkpoint commits
  (`docs: session checkpoint` convention), never commit patched exes / .bak /
  game binaries; resume checklist — read HANDOFF → QUEUE → mods ledger →
  `git log --oneline -10` → f1c-start-here routing.
- Bundled: `handoff-template.md`.
- Sources: work/_README.md; work/HANDOFF.md (structure); CLAUDE.md.

## 15. f1c-skill-maintenance (A4)
Keep this library true when tools/docs change or a skill misfires.
- Contents: run `python .claude/skills/_meta/validate_skills.py` (exit 0 = clean);
  the no-volatile-facts rule and why; patch procedure: fix skill → update
  `Last validated:` footer → re-run the skill's sim rubric with a fresh agent;
  when a tool CLI changes → regenerate the relevant toolfacts section first;
  when a skill caused a wrong action → treat as doc-audit: log what was wrong where.
- Bundled: none (points at _meta/).
- Sources: _meta/CONVENTIONS.md; _meta/toolfacts.md.
