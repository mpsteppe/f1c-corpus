# Chain: Binary Data Deserialization — Type-Dispatching Record Read

Seed: 0x004054e0  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 7

---

## Overview

Binary Data Deserialization reads a data record from a memory buffer by index with type dispatch. No callers documented — likely a utility called by file parsers during resource loading. The chain covers string formatting, thread-safe reading, tokenization/preprocessing, bitfield extraction, and memory allocation for deserialized structs.

## Call Tree

```
FUN_004054e0 — Binary Data Deserialization  [trigger: file/resource loading]
  +-- FUN_00587f64 — String Format Wrapper
  +-- FUN_0058803f — Thread-Safe Read Wrapper
  +-- FUN_00404fe0 — One-Time Initialization with Atexit Registration
  +-- FUN_00407ef0 — Bitfield Extract from Struct  [leaf]
  +-- FUN_004056a0 — Memory Allocation / Serialization Struct Builder
  +-- FUN_0059b650 — [data at 0x0059b650 — 264 bytes]  [leaf]
  +-- FUN_0052d8d0 — Threaded Object Creator with SEH
```

## Step-by-Step Trace

### Level 0: FUN_004054e0 — Binary Data Deserialization

**Trigger:** Called during file/resource parsing
**Called by:** No callers documented
**Purpose:** Reads data record from memory buffer by index with type dispatch.

**Key actions:**
1. Calls FUN_00587f64 — format string/description wrapper
2. Calls FUN_0058803f — thread-safe read wrapper (guards against concurrent access)
3. Calls FUN_00404fe0 — one-time initialization with atexit-style registration
4. Calls FUN_00407ef0 — extracts bitfield values from struct
5. Calls FUN_004056a0 — allocates memory for serialization struct
6. Calls FUN_0059b650 — accesses constant data at 0x0059b650
7. Calls FUN_0052d8d0 — threaded object creator with SEH (structured exception handling)

**Data passed to callees:** memory buffer pointer, record index, type selector

### Level 1: FUN_00404fe0 — One-Time Init with Atexit

**Trigger:** Called to ensure initialization is done
**Purpose:** Tokenize/preprocess — one-time initialization with atexit-style cleanup registration
**Key actions:** Checks if init done, if not: initializes, registers atexit handler

### Level 1: FUN_0052d8d0 — Threaded Object Creator with SEH

**Trigger:** Called to create deserialization target object
**Purpose:** Thread-safe object creation with structured exception handling guard
**Key actions:** Creates object in try/except block, handles exceptions gracefully

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Deserialization | buffer, index | thread-safe read | raw data |
| Deserialization | raw data | bitfield extract | field values |
| Deserialization | field values | memory allocation | deserialized struct |
| Deserialization | struct data | SEH-guarded creation | final object |

## Globals Written in This Chain

None directly — operates on passed buffer and returns allocated struct.

## Notes

- Thread safety (FUN_0058803f, FUN_0052d8d0) suggests this runs in a multi-threaded load context
- FUN_0059b650 is a data constant (264 bytes at fixed address) — likely deserialization lookup table
- SEH handler (FUN_0052d8d0) protects against malformed data crashes
- FUN_00407ef0 (bitfield extract) is the core field-reading primitive

---
