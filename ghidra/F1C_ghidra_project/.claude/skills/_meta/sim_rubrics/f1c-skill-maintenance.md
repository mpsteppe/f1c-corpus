# Rubric: f1c-skill-maintenance

Task prompt: "poke.py just gained a new required flag on its `watch` subcommand,
and yesterday an agent following f1c-live-probe ran the old syntax and errored.
Bring the skill library back in line."

Expected steps (in order):
1. Reads the skill; runs the validator first:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python .claude/skills/_meta/validate_skills.py`
   and reads its violation count / exit code. (The validator exists; only if the
   file is missing from the checkout does the agent fall back to manual checks
   against `_meta/CONVENTIONS.md` §Hard conventions, saying so explicitly.)
2. Regenerates the toolfacts section FIRST: re-verifies `tools/poke.py`'s actual
   argparse (reads the tool source), rewrites the `tools/poke.py` section of
   `_meta/toolfacts.md` — BEFORE touching any skill.
3. Patches the affected skill(s) (`f1c-live-probe`, plus any other skill citing
   the changed subcommand), copying commands only from the regenerated toolfacts
   section.
4. Updates each patched skill's footer: `Last validated: <today> against
   <short-hash>` using `git log --oneline -1`.
5. Re-runs the patched skill's rubric (`_meta/sim_rubrics/f1c-live-probe.md`)
   with a FRESH agent and checks it against the rubric's pass criteria.
6. Re-runs the validator (or manual check), then reports: skills changed,
   toolfacts sections regenerated, sim outcome.

Forbidden actions:
- Editing a skill's command before regenerating the toolfacts section it comes
  from (wrong order).
- Writing the new flag syntax into the skill from memory instead of from the
  verified toolfacts section.
- Inlining any volatile fact (exe address, offset, mod status) into a skill
  while patching.
- Paraphrasing an iron rule while editing (must remain a verbatim CLAUDE.md
  quote).
- Leaving the `Last validated:` footer stale on a patched skill.
- Re-simulating with the same context/agent that wrote the patch (must be a
  fresh agent).

Pass criteria:
- Order held: validator → toolfacts regeneration → skill patch → footer →
  fresh-agent sim → re-validate.
- Validator run treated as the normal first step (exit code read, findings
  triaged); manual-check fallback used ONLY if the file is missing, and stated.
- The patched command in the skill matches the regenerated toolfacts section
  exactly.
- Footer date/hash updated on every touched skill and nothing else.
- Final report names each changed file and the sim result.
