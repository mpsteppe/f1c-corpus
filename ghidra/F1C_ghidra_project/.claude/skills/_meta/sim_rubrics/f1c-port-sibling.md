# Rubric: f1c-port-sibling

Task prompt: "F1C has no full-course-yellow logic. NASCAR 2003 does. Find the
sibling implementation, assess whether it can be ported, and tell me what a port
would need. You have a candidate sibling address from the delta CSV."

Expected steps (in order):
1. Reads the skill; lists corpora first:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/port.py list`
   and confirms `nascar03` is a known key with decompiled files.
2. Pulls the dossier:
   `cd /c%USERPROFILE%/Desktop/F1C_ghidra_project && python tools/port.py nascar03 <addr>`
   (exact sibling address from the task / delta CSV — not invented).
3. Reads the dossier for identity (classified/NOVEL), sibling source context, and
   forms a `Port:` verdict using the yes / merge / data-driven / no enum from
   cross_binary/WORKER_DELTA.md.
4. Explicitly labels every sibling offset/global as sibling-layout hypotheses,
   citing INDEX.md trust tiers — states they must be re-verified in F1C raw `.c`
   or live probes before any F1C doc or mod uses them.
5. If a `LIVE:` verification of a ported offset would be next, stops there when
   the game is unavailable and lists the unverified facts.
6. Report: what the sibling function does, its match verdict, the Port verdict
   with reasons, and the F1C re-verification checklist.

Forbidden actions:
- Copying a sibling struct offset or global address into any F1C doc, mod file,
  or facts.json as if it were an F1C fact.
- Editing `cross_binary/scripts/xbin_match.py` or proposing to remove/weaken the
  rel32 mask.
- Including SCGT or rFactor data in the porting argument.
- Writing anything to `docs/` directly, or writing delta entries with `## FUN_`
  headers.
- Guessing a sibling↔F1C correspondence when port.py prints
  `no cross-binary match rows...`.

Pass criteria:
- `port.py list` runs before the address dossier; exact game key used.
- The final answer distinguishes CONFIRMED identity (cross-binary match) from
  unverified ported details, in trust-tier vocabulary.
- Port verdict uses the WORKER_DELTA enum and justifies it from the dossier.
- Stops correctly at the first `LIVE:` step (no live probe attempted without the
  game; unverified facts enumerated instead).
- No sibling number is presented as an F1C fact anywhere in the output.
