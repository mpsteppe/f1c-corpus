# Routing table — task phrasing → skill

Companion to `f1c-start-here` SKILL.md. Match the task against the closest phrasing;
open the routed skill and follow it. When two rows match, the tie-break notes below win.

| # | If the task sounds like… | Route to |
|---|---|---|
| 1 | "Where is the pit-stop logic?" / "Which function handles penalties?" | `f1c-locate` |
| 2 | "What reads/writes this global?" / "Who touches SessionType?" | `f1c-locate` |
| 3 | "Map the tire subsystem" / "What's moddable around weather?" | `f1c-locate` |
| 4 | "Is this docs/13 offset correct?" / "Double-check this before we rely on it" | `f1c-verify-claim` |
| 5 | "Verify the enum values docs/15 claims" | `f1c-verify-claim` |
| 6 | "What's the current value of X in the running game?" / "Watch these globals while I drive" | `f1c-live-probe` |
| 7 | "Which memory location changed when I did X in-game?" (snapshot→diff hunt) | `f1c-live-probe` |
| 8 | "Make cutting the track give a DQ" / "Add a safety car" / ANY behavior change | `f1c-mod-lifecycle` |
| 9 | "Apply the byte patch" / "Redirect that call site" / "Revert the patch" | `f1c-byte-patch` |
| 10 | "Build the hotkey DLL" / "Scaffold a tick mod" | `f1c-dll-mod` |
| 11 | "Trace which functions fire when I pit" / "Hook it with Frida first" | `f1c-frida-trace` |
| 12 | "The mod logs writes but nothing happens in-game" / "The mod crashes the game" | `f1c-debug-failed-mod` |
| 13 | "Run workers on the undocumented functions" / "Merge the worker output" | `f1c-doc-pipeline` |
| 14 | "Audit docs/06 accuracy" / "Log a [CORRECTION]" / "Spot-check the last merge" | `f1c-doc-audit` |
| 15 | "Does NASCAR have this function?" / "Port the caution system" | `f1c-port-sibling` |
| 16 | "Find the original source file / class names" / "Mine the trace log for names" | `f1c-source-recovery` |
| 17 | "Wrap up the session" / "Write a handoff" / "Resume from last time" | `f1c-handoff` |
| 18 | "The skill's command flag doesn't exist" / "Update the skill library" | `f1c-skill-maintenance` |

## Tie-breaks

- **Rows 8 vs 9/10/11:** any NEW behavior change enters at `f1c-mod-lifecycle` even if
  the user names a rung ("just write the DLL"). Within behavior-change work, rows 9–11
  execute steps the lifecycle (or an existing mod's docs) already prescribes. Pure
  observation/tracing tasks with no behavior change (e.g. row 11's "trace which
  functions fire when I pit") go straight to `f1c-frida-trace` — no lifecycle needed.
- **Rows 4 vs 6:** "verify a claim" = compare against an expectation and produce a
  verdict (`f1c-verify-claim`, which itself uses live probing). "Just read/watch/write
  values" with no doc claim at stake = `f1c-live-probe`.
- **Rows 6 vs 11:** single globals/fields at low rate → `f1c-live-probe` (poke).
  Function-call activity, high-rate capture, or write-interception → `f1c-frida-trace`.
- **Rows 14 vs 4:** one claim inline = `f1c-verify-claim`; sampling a whole doc/batch
  and logging corrections = `f1c-doc-audit`.
- **Rows 16 vs 15:** F1C's own original names/structure = `f1c-source-recovery`;
  anything about a sibling binary's functions = `f1c-port-sibling`.

---
Canonical sources: INDEX.md §Common tasks → where to start; CLAUDE.md §Key pointers
Last validated: 2026-07-18 against 6bcccfe
