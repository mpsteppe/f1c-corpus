# Chain 190: NetworkMessageDispatch — Packet Decode + Handler Dispatch

Seed: FUN_004b54e0  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 6 direct

---

## Overview

Decodes a network message packet header and dispatches to registered handlers via linked list lookup. Extracts a 6-bit key from packet header bits 18-23, walks a handler linked list for matching key, and if no match is found, walks a secondary list to register a new handler dynamically.

## Call Tree

```
FUN_004b54e0 — NetworkMessageDispatch  [per-packet, called from network receive loop]
  +-- FUN_004ba7a0 — Doubly-Linked List Node Removal  [2 callees — handler list walk]
  |     +-- FUN_004b0170 — [unnamed — list helper]
  |     +-- FUN_00587bcf — Memory Free  [cleanup]
  +-- FUN_004ba980 — Conditional Sized Array Alloc  [handler allocation, 1 callee]
  |     +-- FUN_004ff670 — [unnamed — alloc helper]
  +-- FUN_004bad70 — Collision Node List Insertion  [handler registration]
  +-- FUN_004bae20 — Linked List Remove by Value  [2 callees — handler unregister]
  |     +-- FUN_004b0170 — [unnamed — list helper]
  |     +-- FUN_00587bcf — Memory Free  [cleanup]
  +-- FUN_00500170 — Short Computation (Struct Init with Values)  [handler struct init, 2 callees]
  |     +-- FUN_00500190 — [init helper]
  |     +-- FUN_005001b0 — [init helper]
  +-- FUN_004fffb0 — Zone/Threshold Comparison with Conditional Action  [dispatch call, 1 callee]
        +-- FUN_004b3a90 — [unnamed — conditional action]  [dispatches to registered handler]
```

## Step-by-Step Trace

### Level 0: FUN_004b54e0 — NetworkMessageDispatch

**Trigger:** Called per-packet from the network receive pipeline when a message arrives.

**Called by:** Network receive dispatch (docs/21-audio-network-internals.md receive pipeline).

**Purpose:** Decodes a message packet header and dispatches to registered handlers via linked list lookup. Part of the network message routing system.

**Key actions:**
1. Extracts 6-bit key from bits 18-23 and byte key from param_2[2]
2. Walks linked list looking for match at offsets +0x368 and +0x36c
3. If match found: dispatches to handler
4. If no match: walks secondary list, allocates new handler via FUN_004ba980
5. Registers handler via FUN_004bad70 and dispatches via FUN_004fffb0

**Data passed to callees:** param_1 (network context), param_2 (packet data), key value, handler data

### Level 1: Callees

**FUN_004ba7a0 — Doubly-Linked List Node Removal**
- 2 callees: FUN_004b0170 (list helper) + FUN_00587bcf (free)
- Walks handler linked list nodes
- Finds matching handler by key
- Removes node from list if found, frees memory

**FUN_004ba980 — Conditional Sized Array Alloc**
- 1 callee: FUN_004ff670
- Allocates new handler node when no match found
- Sizes array based on handler data requirements

**FUN_004bad70 — Collision Node List Insertion**
- Leaf function
- Inserts new handler into the handler linked list
- Registers handler for future message dispatch

**FUN_004bae20 — Linked List Remove by Value**
- 2 callees: FUN_004b0170 + FUN_00587bcf
- Removes handler from linked list by key match
- Frees handler memory after removal

**FUN_00500170 — Short Computation (Struct Init with Values)**
- 2 callees: init helpers
- Initializes handler struct with values
- Sets up handler context for dispatch

**FUN_004fffb0 — Zone/Threshold Comparison with Conditional Action**
- 1 callee: FUN_004b3a90
- Performs zone/threshold comparison check
- Dispatches to final handler function if conditions met
- Routing point for conditional message delivery

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Packet | param_2 data | Extract bits 18-23 | 6-bit key |
| List walk | handler list head | Match +0x368/+0x36c | Handler or null |
| FUN_004ba980 | key | Allocate new handler | Handler node |
| FUN_004bad70 | handler node | Insert into list | Handler registered |
| FUN_004fffb0 | message data | Zone check | Dispatch to handler |

## Notes

- The 6-bit key (bits 18-23) allows for 64 unique message types
- Two identical list walk patterns: primary list (existing handlers) and secondary list (pending registration)
- FUN_004b0170 is shared between FUN_004ba7a0 and FUN_004bae20 (list manipulation utility)
- FUN_00587bcf (memory free) appears in both lookup paths for cleanup
- This is a dynamic handler registration system — handlers can be added at runtime when new message types arrive

---
