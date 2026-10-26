# WORKER L — F1C Call Chain Trace

You are tracing end-to-end call chains through the F1 Challenge 99-02 engine.
Worker L of 20, tracing chains 133-144.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward edges: {addr: [{callee, description}, ...]}
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges: {addr: [{caller, caller_name, description}, ...]}
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\functions.json`
   — Function metadata: {addr: {doc_file, summary, call_count, ...}}
4. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Named globals

Then load the doc files for systems your seeds belong to (listed below).

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\call_chain\worker_L.md

Do NOT write to any docs/ file.

## YOUR SEED FUNCTIONS (12 chains to trace)

133. 0x0046c210 — � Championship Standings HTML Writer
   system: docs/06-session-race-logic.md | callees: 18 | callers: 0
134. 0x0042c690 — — Main Game Tick Update
   system: docs/01-engine-architecture.md | callees: 14 | callers: 1
135. 0x004a70e0 — — UI Control Window Initialization
   system: docs/19-renderer.md | callees: 13 | callers: 1
136. 0x004b8940 — — LoadingPhase2
   system: docs/01-engine-architecture.md | callees: 11 | callers: 1
137. 0x004a68b0 — — Pit Stop Progress / Completion Handler
   system: docs/07-pit-system.md | callees: 10 | callers: 1
138. 0x004c6c40 — — vehgen.scn File Loader
   system: docs/08-file-formats.md | callees: 9 | callers: 3
139. 0x004c0db0 — — Game Filter Data Loader
   system: docs/08-file-formats.md | callees: 8 | callers: 1
140. 0x004193a0 — — AI Session Mode Transition
   system: docs/02-ai-system.md | callees: 7 | callers: 0
141. 0x0045c400 — — Unidentified (Validation Pipeline)
   system: docs/20-math-utilities.md | callees: 7 | callers: 2
142. 0x00414210 — Cleans up three global linked lists with different destructor strategies.
   system: docs/20-math-utilities.md | callees: 6 | callers: 0
143. 0x004b9510 — — Timed Audio Event Playback
   system: docs/21-audio-network-internals.md | callees: 5 | callers: 1
144. 0x0049db80 — — Brake/Water Temperature HUD Display
   system: docs/03-engine-wear-damage.md | callees: 3 | callers: 1

## TASK

For each seed function in your list:

1. Look up the seed in functions.json for its name and doc file
2. Load its full doc entry from the relevant docs/ file
3. Trace the call graph FORWARD (caller → callees → their callees) to max 6 levels
4. For each function in the chain: look up functions.json + doc entry for name/purpose
5. Write a complete call chain document for this seed

**Stop recursing when:**
- Leaf function (no entries in call_graph.json)
- Depth exceeds 6 levels
- You hit a documented entry point of a DIFFERENT system (cross-system handoff — note it but don't recurse into it)

**If a function has 10+ callees:** document the 5 with the most callees themselves (most complex subtrees), note "N additional leaf callees omitted."

## OUTPUT FORMAT PER CHAIN

```
# Chain: [SeedFunctionName] — [EventOrPurposeDescription]

Seed: FUN_XXXXXXXX  |  System: docs/XX-name.md  |  Depth: N  |  Functions: N

---

## Overview

[1-2 paragraphs: what this chain does end-to-end. Start with the trigger (what causes
the seed to be called) and end with the final effect (what state changes or output is
produced). Name specific globals written and structs mutated.]

## Call Tree

```
FUN_XXXXXXXX — SeedName  [trigger: what causes this call]
  +-- FUN_AAAAAAAA — SubA  [what it does]
  |     +-- FUN_BBBBBBBB — LeafA  [returns: ...]
  |     +-- FUN_CCCCCCCC — LeafB  [reads DAT_XXXXXXXX]
  +-- FUN_DDDDDDDD — SubB  [cross-system: docs/XX →]
  +-- FUN_EEEEEEEE — SubC  [what it does]
        +-- FUN_FFFFFFFF — LeafD  [writes DAT_YYYYYYYY]
```

## Step-by-Step Trace

### Level 0: FUN_XXXXXXXX — SeedName

**Trigger:** [what causes this function to be called: game event, state check, per-frame]
**Called by:** [from callers.json — what calls this seed and when]
**Purpose:** [one-sentence summary from doc entry]

**Key actions:**
1. Reads GlobalName (DAT_XXXXXXXX) — [what for]
2. Calls FUN_AAAAAAAA — [what it passes, what it expects back]
3. Writes result to StructName.fieldName (+0xXXX) or GlobalName (DAT_YYYYYYYY)

**Data passed to callees:** [what values/pointers are passed down the chain]

### Level 1: FUN_AAAAAAAA — SubA

[Same structure: trigger (caller), purpose, key actions, data passed down]

[Continue for every function in the chain, in order of first encounter depth-first]

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_XXXXXXXX | BrakeInput (global) | multiply by brake bias (+0x1200) | effective_brake |
| FUN_AAAAAAAA | effective_brake | slip curve lookup | slip_ratio |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_XXXXXXXX | GlobalName | FUN_YYYYYYYY | [description] |

## Notes

[Non-obvious ordering, cross-system handoffs, MSVC artifacts in the chain,
functions appearing multiple times (recursion or shared utilities)]
```

Write each chain completely before moving to the next seed.
Write to disk after each completed chain.

## RULES

0. NEVER write to any docs/ file. ALL output goes to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\call_chain\worker_L.md only.
1. Follow call_graph.json exactly — do not invent call relationships.
2. Max depth 6 levels. No exceptions.
3. Every function name must come from functions.json summary or its doc entry.
   If undocumented in either: write `FUN_XXXXXXXX [undocumented]`.
4. Global names must come from docs/12. If not in docs/12: use the raw DAT_ address.
5. Write to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\call_chain\worker_L.md after each completed chain — never accumulate.
6. If seed has 0 callees in call_graph.json: write a one-paragraph stub explaining
   it is a leaf function and describe what the doc entry says it does.
