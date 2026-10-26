# WORKER F — F1C Implementation Specification

You are writing reimplementation specs for F1 Challenge 99-02 subsystems.
Each spec must be precise enough to reimplement the system in modern C++ without
access to the original binary.
Worker F of 15.

## STEP 1 — LOAD REFERENCE FILES

Read these before starting:
1. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\12-globals-reference.md`
   — Complete globals reference. Use known names, not raw DAT_ addresses.
2. `%USERPROFILE%\Desktop\F1C_ghidra_project\docs\13-struct-offsets.md`
   — Struct field names by offset. Use field names in the spec.
3. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\call_graph.json`
   — Forward call edges: {addr: [{callee, description}, ...]}
4. `%USERPROFILE%\Desktop\F1C_ghidra_project\knowledge_graph\callers.json`
   — Inverse edges: {addr: [{caller, caller_name, description}, ...]}

## YOUR OUTPUT FILE

Write ALL output to: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\impl_spec\worker_F.md

Do NOT write to any docs/ file.

## YOUR SYSTEMS (1 doc files)

- docs/05-weather-system.md  (6 entries, 161 lines)  [Weather System]

## TASK

For EACH doc file in your list:
1. Read the ENTIRE doc file (every ## FUN_ and ### FUN_ entry and arch narrative)
2. Study docs/12 and docs/13 to resolve global names and struct fields
3. Use call_graph.json to identify internal call chains for this system
4. Use callers.json to identify what external systems drive this system
5. Write a complete implementation spec for each system

## OUTPUT FORMAT PER SYSTEM

```
# Implementation Spec: [System Name]

Source: docs/XX-system-name.md  |  Functions: N  |  Date: 2026-07-15

---

## Overview

[2-3 paragraphs: what this system does, when it runs in the game loop (init/per-frame/
per-tick/on-event), what data structures it owns, what other systems interface with it.
Name specific globals, structs, and functions at the system boundaries.]

## Data Structures

### StructName
```c
struct StructName {
    /* +0x0000 */ int   sessionType;    // matches DAT_007c56a4 (0-7)
    /* +0x0004 */ float tireTemp;       // celsius, updated each physics tick
    /* +0x0008 */ float tireWear;       // 0.0-1.0, floor at 0.75
};
// Total size: 0xXXXX bytes (confirmed from stride/array observations in docs/13)
// Accessed via: DAT_007c54f0 (VehiclePtrArray) / param_1 pattern
```

[Repeat for every distinct struct used by this system. If size is unknown, omit.
If field name is unknown, write `/* +0xXXXX */ unknown_t unk_XXXX;`]

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007c56a4 | int | SessionType | 7=race 6=quali 0-5=practice |

[Only globals this system WRITES. Globals it only reads go in Dependencies.]

## Public API — Entry Points

Functions external code calls to drive this system:

### FUN_XXXXXXXX — FunctionName

**Inferred signature:** `ReturnType FunctionName(ParamType param1, ...)`
**Called from:** [which system/doc calls this, and when — per-frame, on event, etc.]
**Called by (from callers.json):** [list caller addresses and their descriptions]

**What it does:**
1. [Step-by-step. All branches with exact conditions.]
2. [Key constants with their meaning: 0.75 = minimum wear floor]
3. [Return value meaning if non-void]

**Side effects:**
- Writes: GlobalName (DAT_XXXXXXXX) — [what value/when]
- Reads: GlobalName (DAT_YYYYYYYY)
- Struct mutations: StructName.fieldName (+0xXXX) — [when/what]

[Repeat for every major entry point. Minor helpers can be grouped under their caller.]

## Internal Call Graph

Major call chains within this system:

```
FUN_XXXXXXXX — TopLevel  [triggered by: ...]
  +-- FUN_AAAAAAAA — SubA  [what it does]
  |     +-- FUN_BBBBBBBB — LeafA  [returns: ...]
  |     +-- FUN_CCCCCCCC — LeafB  [returns: ...]
  +-- FUN_DDDDDDDD — SubB  [what it does]
        +-- FUN_EEEEEEEE — LeafC  [returns: ...]
```

[Only include chains with depth >= 2. Leaf-only calls go in the entry point section.]

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0.75 | FUN_XXXXXX | Minimum tire wear floor |

## Inter-System Dependencies

**Reads from (external globals/systems):**
- GlobalName (DAT_XXXXXXXX) — from docs/XX, [what this system uses it for]

**Calls into:**
- docs/XX-other-system.md: FUN_YYYYYYYY ([what for])

**Called by:**
- docs/XX-calling-system.md: [which entry points call into this system]

## Reimplementation Notes

[Non-obvious behaviors, invariants, MSVC artifacts, ordering dependencies.
E.g.: "SessionType must be set before RacePhase is read — race branch assumes ordering."
"Tire temp calc assumes 60Hz tick — caller must divide by dt before passing."
"Function at 0x00XXXXXX is an empty stub — virtual method never implemented."]

## Completeness

- Full specs written: N / M total documented functions
- Thunks/empty stubs omitted: K
- Confidence: high | medium | low [reason if not high]
```

Write each system spec completely before starting the next.
Write to disk after completing each system spec.

## RULES

0. NEVER write to any docs/ file. ALL output goes to %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\impl_spec\worker_F.md only.
1. Read the ENTIRE doc file before writing the spec.
2. Use field names from docs/13 — not raw offsets.
3. Use global names from docs/12 — not raw DAT_ addresses.
4. Every constant or threshold claimed must appear in a ## FUN_ entry. Do not invent.
5. For struct fields with conflicting types: note the conflict and pick the majority type.
6. To clarify unclear functions: read the .c source file from the Source: line in the doc entry.
7. Inferred function signatures are OK — mark them as `(inferred)`.
8. The spec must be precise enough to reimplement without the original binary.
