# WORKER C — F1C Architecture Narrative

You are writing a prose architecture overview for a game engine subsystem.
Worker C of 6.

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\arch_narrative\worker_C.md

## YOUR DOC FILE

Doc file: %USERPROFILE%\Desktop\F1C_ghidra_project\docs\19-renderer.md
  (429 function entries, 7770 lines)
  Output narrative targets: docs/19-renderer.md

## TASK

1. Read the ENTIRE doc file listed above — every `## FUN_` entry
2. Understand the system: what are the major function clusters, how do they interact,
   what data flows through them, what drives them in the game loop
3. Write an architecture overview to be prepended at the top of the doc file

## OUTPUT FORMAT

```
<!-- ARCHITECTURE NARRATIVE — prepend to top of doc file -->

## System Overview

[2–3 paragraphs: what this system does in the game engine, where it runs in the
game loop (init, per-frame, per-tick, on-event), what data structures it owns,
what other systems it interfaces with]

## Subsystem Structure

[Group the functions into logical clusters. For each cluster:]

### ClusterName (N functions)
- What it does
- Key functions: FUN_XXXXXXXX (role), FUN_YYYYYYYY (role)
- Internal data flow

## Data Flow

[How data enters this system (from which globals, structs, or other systems),
how it transforms through the processing pipeline, and where results go
(which globals are written, what other systems consume the output)]

## Key Entry Points

[Top-level functions that external code calls to drive this system. For each:]
- FUN_XXXXXXXX — what triggers it, what it orchestrates

## Call Graph Summary

[Major call chains described in plain English. Example:
"FUN_004XXXXX (tire update) calls FUN_004YYYYY (slip calc) which calls
FUN_004ZZZZZ (grip curve lookup), feeding results back into the force integrator
FUN_004WWWWW."]
```

Write the full narrative in one pass. This is synthesis, not per-function documentation.

## RULES
0. NEVER move, rename, or delete any files.
1. Read ALL function entries in the doc file before writing — the narrative must reflect
   the complete system, not just the first N entries you read.
2. Name specific FUN_ addresses when describing clusters and call chains.
3. Do not repeat individual function documentation — summarize and connect.
4. Focus on HOW the system works as a whole, not WHAT each function does individually.
5. If the doc file is very large (2000+ entries), organize clusters by address range
   proximity — functions compiled from the same source file cluster in address space.
