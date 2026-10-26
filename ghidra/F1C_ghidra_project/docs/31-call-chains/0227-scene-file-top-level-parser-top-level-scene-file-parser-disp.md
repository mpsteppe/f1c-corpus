# Chain: Scene File Top-Level Parser — Top-level scene file parser dispatching to sub-parsers for .scn format

Seed: FUN_0055b200  |  System: docs/09-track-system.md  |  Depth: 6  |  Functions: ~25

---

## Overview

FUN_0055b200 is the top-level parser for `.scn` scene files. Triggered during track/UI loading, it reads the entire file into a buffer, tokenizes line-by-line, and dispatches to sub-parsers based on keyword tokens (INCLUDEFILE, SEARCHPATH, GROUPMETHOD, FONTFILE, MASFILE, AMBIENTCOLOR, fog parameters, GROUP, INSTANCE, LIGHT). The resulting scene graph is passed to the renderer. Most callees are themselves parsers or tokenizers; the deepest subtree is the INSTANCE parser (FUN_0055a910) which handles mesh/animation/shadow/actor loading.

## Call Tree

```
FUN_0055b200 — Scene File Top-Level Parser  [trigger: track/scene loading]
  +-- FUN_00559a40 — token init  [leaf: Large Buffer Zero-Init]
  +-- FUN_0058803f — read file  [Thread-Safe Read Wrapper]
  |     +-- FUN_0058c1b1 — mutex lock  [Stream Buffer Lock via Critical Section]
  |     +-- FUN_0058806e — raw read  [leaf]
  |     +-- FUN_0058c203 — mutex unlock  [leaf]
  +-- FUN_00559a70 — token next  [Line Reader from Buffer]
  |     +-- FUN_00559e20 — string token match  [leaf]
  +-- FUN_00559f00 — float token parse  [PRNG 4 Uniform Ints from Seed]
  +-- FUN_0055b6b0 — include file  [leaf]
  +-- FUN_0053c6f0 — search path add  [Search Path Registry]
  +-- FUN_0053cfe0 — font load  [String-Keyed Registry with Extension Fallback]
  |     +-- FUN_00589901 — string normalize  [leaf]
  |     +-- FUN_005523e0 — alloc init  [Hash Table Entry Default Init]
  |     +-- FUN_00552470 — create entry  [leaf]
  |     +-- FUN_0053d340 — register entry  [LinkedListAppend]
  |     +-- FUN_00557470 — unload  [Empty Stub]
  +-- FUN_0053ce10 — MAS archive open  [Error Handler Set]
  +-- FUN_00543800 — ambient color  [3D Position Set]
  +-- FUN_0054a160 — group method  [Flag Bit Setter 0x1000/0x2000]
  +-- FUN_0055a060 — scene render dispatch  [leaf, undocumented]
  +-- FUN_0055a790 — group dispatch  [leaf, undocumented]
  +-- FUN_0055a910 — instance dispatch  [Scene Node / Instance Parser - 18 callees]
  |     +-- FUN_0054a600 — instance alloc  [Large Object Initializer]
  |     +-- FUN_0059a70 — token next  [reuse tokenizer]
  |     +-- FUN_00559f00 — float parse  [reuse parser]
  |     +-- FUN_0059e20 — string token match  [reuse token matcher]
  |     +-- FUN_00545f50 — Audio Volume/Load Computation  [leaf]
  |     +-- [additional 13 leaf callees omitted for brevity]
  +-- FUN_0055a500 — light dispatch  [leaf, undocumented]
  +-- FUN_00587bcf — free buffer  [Free Wrapper]
```

## Step-by-Step Trace

### Level 0: FUN_0055b200 — Scene File Top-Level Parser

**Called by:** None documented (likely called from scene loading entry point)
**Purpose:** Top-level scene file parser that dispatches to sub-parsers for INCLUDEFILE, SEARCHPATH, GROUPMETHOD, FONTFILE, MASFILE, AMBIENTCOLOR, fog parameters, GROUP, INSTANCE, and LIGHT sections.

**Key actions:**
1. Reads entire file into buffer via FUN_0058803f
2. Initializes tokenizer via FUN_00559a40
3. Iterates tokens via FUN_00559a70, matching keywords against string table
4. For each recognized keyword: calls the appropriate sub-parser
5. Stores fog parameters in struct offsets +0x188–0x19c
6. Frees buffer via FUN_00587bcf

**Data passed to callees:** File buffer pointer, scene struct pointer (param_1)

### Level 1: FUN_0058803f — Thread-Safe Read Wrapper

**Called by:** FUN_0055b200 (read file)
**Purpose:** Reads file into buffer with critical section locking

**Key actions:**
1. Acquires mutex via FUN_0058c1b1
2. Performs raw read via FUN_0058806e
3. Releases mutex via FUN_0058c203
4. Returns buffer pointer

### Level 1: FUN_0055a910 — Scene Node / Instance Parser

**Called by:** FUN_0055b200 (instance dispatch)
**Purpose:** Parses INSTANCE nodes with 18 sub-handlers for mesh, animation, LOD, shadow, reflection, actor, collision response

**Key actions:**
1. Allocates instance node via FUN_0054a600
2. Checks VISGROUPS mask against DAT_008b8ee0
3. Dispatches to sub-parsers per token (MESHFILE, ANIMFILE, LODIN/OUT, etc.)
4. Can recurse for nested INSTANCE children

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0055b200 | .scn file path | tokenize + dispatch keyword handlers | Populated scene struct with fog, groups, instances |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b8ee0 | VISGROUPS mask | FUN_0055a910 | Visibility groups to render |

## Notes

- Many callees are simple leaf parsers (token alloc, match, parse) reused between the top-level parser and the INSTANCE sub-parser.
- FUN_0055a910 has the deepest subtree (18 callees) but most are leaf or leaf-adjacent.
- The fog state struct (+0x188–0x19c) is the main data output.

---
