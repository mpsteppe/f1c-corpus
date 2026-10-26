# CLAUDE.md

Reverse engineering of **F1 Challenge 99-02** (`F1 Challenge Online.exe`, x86 PE32,
MSVC ~2002, non-ASLR). 6,868 known functions, all documented. Role: **ARCHITECT**
(`roles/ARCHITECT.md`) — audit, verify, assign; delegate bulk doc work to DS workers.

**Python:** `%USERPROFILE%\AppData\Local\Python\bin\python3.exe`

**Skills:** every workflow is encoded in `.claude/skills/` — cold sessions start with
`f1c-start-here` (router). Validate library health: `python .claude/skills/_meta/validate_skills.py`.

This file is intentionally short — iron rules only. Everything else is in
**`REFERENCE.md`** (directory layout, pipeline, knowledge graph, IDA, doc formats,
worker workflow, batch modes, Ghidra patterns, pitfalls). Read its sections on
demand; do not re-derive what it already records. Repo entry point: `INDEX.md`.

## Iron rules

1. **Trust tiers.** Raw `.c` files (`analysis_pipeline/analyzed/`, `decompiled_all/`)
   and the live process are FACT. `docs/` labels, offsets, call chains are GUESS —
   LLM-generated, ~90% per-fact accuracy. Verify before building on any doc claim.
2. **LOCATE with `tools/investigate.py`** (`find` / `system` / `mod` / `global` /
   `uses` / address dossier) — never fan out raw greps or hand-read `.c` files to
   find code. Batch all addresses in ONE call. Offset table auto-decodes idx×4 and
   docs/13 names — build it once, reason once, never re-derive by hand.
3. **Mods: read `mods/_README.md` (ledger) FIRST**, then
   `tools/mod_pipeline/MODDING_PLAYBOOK.md`. Only `cut_track_dq` is in-game
   confirmed — treat everything else as unproven.
4. **Mods: verify facts before code.** Decompose the mod into individual claims and
   check each against the live game: `python tools/preflight.py run <facts.json>`
   (template: `preflight.py example`; ad-hoc: `preflight.py probe <expr>`).
   Never test "does the whole mod work" as the first test — 1-bit feedback over
   GUESS-tier facts is a coin flip; per-fact verification converges in 2 passes.
5. **Mod strategy ladder:** data file > memory write (poke-proven, then tick DLL) >
   call-site byte redirect > vtable swap > detour. **Never call game internals from
   injected code** (thiscall `this`, `ret imm` stack cleanup, wrong thread).
   Patch a COPY of the exe, verify original bytes first, test with Frida before baking.
6. **Mods must log read-back values** (write, re-read, log both + gate states) so a
   failure report carries bits, not "nothing happened".
7. Never re-document an address already in `docs/` (check `## FUN_` header first).
   Workers write to `analysis_pipeline/output/`, never directly to `docs/`.
   Flag doc errors in `work/CHANGELOG.md` as `[CORRECTION]`.

## Everyday commands

```bash
python tools/investigate.py find "tire wear"      # concept -> ranked addresses
python tools/investigate.py 0x004ef5a0 --snippet  # dossier (batch all addrs)
python tools/poke.py read SessionType             # live memory (game running)
python tools/preflight.py run mods/X/facts.json   # verify mod facts vs live game
analysis_pipeline/2_merge.bat                     # merge worker output + rebuild graph
python tools/knowledge_graph/rebuild.py           # rebuild graph after docs/ change
```

## Key pointers

| Need | Where |
|------|-------|
| Full reference (layout, pipeline, IDA, formats, pitfalls) | `REFERENCE.md` |
| Repo map + trust tiers | `INDEX.md` |
| Shipped mods + reusable primitives + strategy ladder | `mods/_README.md` |
| Modding process end-to-end | `tools/mod_pipeline/MODDING_PLAYBOOK.md` |
| Globals (~8,048 named) | `docs/12-globals-reference.md` |
| Struct offsets | `docs/13-struct-offsets.md` + `13-audit-report.md` |
| Ranked mod patch-points | `docs/35-mod-targets.md` |
| What's next | `work/HANDOFF.md`, `work/PLAN_*.md` |

Key globals cheat: SessionType `0x007c56a4` (7=race), GameState `0x007d00ec`,
VehicleCount `0x005c329c`, PlayerVehiclePtr `0x007c54e8`, VehiclePtrArray
`0x007c54f0`, RaceActiveFlag `0x007d0308`. Full list docs/12.
