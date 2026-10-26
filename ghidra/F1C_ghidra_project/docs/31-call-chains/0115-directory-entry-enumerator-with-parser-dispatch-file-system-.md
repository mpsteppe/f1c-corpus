# Chain: Directory Entry Enumerator with Parser Dispatch — File System Scanning

Seed: 0x0045c0c0  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 9

---

## Overview

Directory Entry Enumerator scans a directory for files matching an extension filter, classifies them by type, parses them, and inserts parsed data into a linked list for later loading. No callers documented — likely called during resource scanning at game startup. The chain covers directory traversal (open, iterate, read), file type dispatch to three parser variants, path string formatting, and linked list node allocation.

## Call Tree

```
FUN_0045c0c0 — Directory Entry Enumerator with Parser Dispatch  [trigger: resource scan at startup]
  +-- FUN_00565f80 — [open dir — not in functions.json]
  +-- FUN_00565f50 — Linked List Pop Front  [begin iteration — leaf]
  +-- FUN_005662d0 — Directory Entry Iterator  [read entry — leaf]
  +-- FUN_0058815f — String Format with Buffer Overflow Check  [format path]
  +-- FUN_0045c400 — Unidentified (Validation Pipeline)  [parser type 1]
  +-- FUN_0045c650 — Data File Check/Size Query  [parser type 2]
  +-- FUN_00568a60 — Utility Function (Weighted Running Checksum)  [generic parser]
  +-- FUN_00565f20 — Linked List Node Peek  [iteration check — leaf]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0045c0c0 — Directory Entry Enumerator

**Trigger:** Game startup resource scanning
**Called by:** No callers documented
**Purpose:** Enumerates directory entries, classifies them, inserts into linked list for later loading.

**Key actions:**
1. Opens directory with FUN_00565f80(path, 1, extension, 1) — open dir with filter
2. Begins iteration via FUN_00565f50() — pop front of enumeration list
3. Loop: reads entries via FUN_005662d0() until exhausted
4. Formats path string via FUN_0058815f(local_200, &DAT_005be860, extension, iVar3)
5. Routes to parser based on param_4:
   - 1: FUN_0045c400 — texture/image parser
   - 2: FUN_0045c650 — model/geometry parser
   - else: FUN_00568a60 — generic parser via param_1+1 (type byte)
6. On success: strips to filename, allocates 12-byte node (operator_new(0xc))
7. Node layout: [0]=0, [4]=0xffffffff, [8]=parsed_data_ptr
8. Allocates second node: [0]=first_node_ptr, [4]=0, [8]=1 (linked flag)
9. Appends to doubly-linked list at param_1: +4(head), +8(tail), +0xc(last), +0x10(count)
10. Continues until FUN_00565f20() returns false

**Data passed to callees:** directory path, extension filter, struct param_1 with list state

### Level 1: FUN_0045c400 — Parser Type 1 (Validation Pipeline)

**Trigger:** Called for each file when param_4 == 1
**Purpose:** Likely texture/image resource parser — validates and loads file data

### Level 1: FUN_0045c650 — Parser Type 2 (Data File Check/Size Query)

**Trigger:** Called for each file when param_4 == 2
**Purpose:** Likely model/geometry parser — checks file size and validity

### Level 1: FUN_00568a60 — Generic Parser (Weighted Running Checksum)

**Trigger:** Called for each file when param_4 != 1,2
**Purpose:** Generic file parser that computes weighted running checksum over file stream

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Enumerator | path, extension | open + iterate dir | file entries |
| Enumerator | param_4 | parser dispatch | parsed data |
| Enumerator | parsed data | node allocation | linked list entry |
| Enumerator | list state | append to list | param_1+4/8/c/10 |

## Globals Written in This Chain

- `DAT_005be860` — format string for path construction (read)

## Notes

- Parser dispatch is hardcoded to 3 types via param_4 — extensible via generic parser path
- Double-node encoding (data node + flag node) is unusual — flag node with [4]=0, [8]=1 indicates linked-list membership
- FUN_00565f80 not in functions.json — external or unanalyzed directory open function
- String copy (FUN_00566650) uses buffer realloc — variable-length filename support

---
