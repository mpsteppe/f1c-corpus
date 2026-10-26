# Chain: Network Packet Send with Query Matching — Mutex-protected query/response queue send

Seed: FUN_0057d8d0  |  System: docs/21-audio-network-internals.md  |  Depth: 4  |  Functions: 11

---

## Overview

FUN_0057d8d0 is the network packet send function for the query/response subsystem. Called from FUN_0057a6a0 (virtual dispatch), FUN_00570710, and FUN_005813e0 (connection send). It encodes query data, acquires a mutex, walks a linked-list send queue, matches entries against query IDs, and calls winsock `send()` on matched entries. Two code paths: fast path with direct ID filter (param_3), and full path iterating all registered queries.

The chain is narrow (6 direct callees) and shallow (max depth 4 via the query encode path). Most callees are simple leaf accessors.

---

## Call Tree

```
FUN_0057d8d0 — Network Packet Send with Query Matching  [docs/21-audio-network-internals.md]
  |
  +-- FUN_0057d5d0 — Structured Memory Copy with Header Prepend  [docs/01-engine-architecture.md]
  |     +-- FUN_0053d880 — Field Accessor (+0x8)  [triage: math_util] LEAF
  |     +-- FUN_00587580 — Buffer Query: Return Ptr+Size If Valid  [docs/01-engine-architecture.md]
  |           +-- FUN_00585770 — Thread-Safe Int Read with Mutex  [docs/01-engine-architecture.md] LEAF
  |
  +-- FUN_0057b6b0 — Offset Getter (param_1 + 0x20)  [triage: math_util] LEAF
  |
  +-- FUN_0057b0d0 — Indexed Linked-List Node Getter  [triage: Data/List] LEAF
  |
  +-- FUN_0057b2e0 — Query Handler Check (field at +0x24)  [triage: unknown / struct field getter] LEAF
  |
  +-- FUN_005871f0 — Read Field at Offset 0x14  [triage: math_util / Data/FieldRead] LEAF
  |
  +-- FUN_0057db80 — Two-Field Equality Check  [docs/01-engine-architecture.md] LEAF
```

---

## Step-by-Step Trace

### Level 0 — Seed
**FUN_0057d8d0 — Network Packet Send with Query Matching** (docs/21-audio-network-internals.md):
- Encodes query data into local buffer via FUN_0057d5d0 (1 byte header + structured copy)
- Acquires mutex at param_1+0xabc via WaitForSingleObject (timeout from +0xac0)
- Two paths based on param_3 (query filter):
  - **With filter (fast):** walks linked list at +0xaac, matches 16-bit ID and param_3[1]. On match: gets socket via FUN_0057b6b0 (+0x20), calls `send()`
  - **Without filter (full):** walks entire list. For each entry, iterates registered queries via FUN_0057b0d0. If entry matches query by ID (short at +2, short at +0x12) OR passes FUN_0057db80 equality check, sends the packet
- Calls FUN_0057b2e0 (query handler check at +0x24) during send decision
- Calls FUN_005871f0 (field read at +0x14) during send loop
- Returns 1 on success, 0 on send failure
- Releases mutex before return

### Level 1 — Direct Callees

**1. FUN_0057d5d0 — Structured Memory Copy with Header Prepend** (docs/01-engine-architecture.md)
- Reads source data pointer from param_1+0x14
- Computes byte count from bit-field at param_1+0x24: `(field & 7) != 0 + (field >> 3)`
- Writes 2-byte header: byte count at +0, value from FUN_0053d880 (+0x8 field accessor) at +2
- Copies source data 4-byte chunks + trailing bytes
- Calls FUN_00587580 (buffer validation) on output buffer and source
- Appends additional data from output buffer (second copy pass)
- Returns CONCAT31(..., 1)

**2. FUN_0057b6b0 — Offset Getter (param_1 + 0x20)** (triage: math_util)
- Returns pointer = param_1 + 0x20
- Used to get the socket handle for send()
- Leaf function

**3. FUN_0057b0d0 — Indexed Linked-List Node Getter** (triage: Data/List)
- Walks linked list, returns node at given index
- Used to iterate registered queries during full send path
- Leaf function

**4. FUN_0057b2e0 — Query Handler Check** (triage: struct field getter)
- Returns field at param_1+0x24
- Used during send decision logic
- Leaf function

**5. FUN_005871f0 — Read Field at Offset 0x14** (triage: Data/FieldRead)
- Returns int at param_1+0x14
- Used as random/state value during send loop
- Leaf function

**6. FUN_0057db80 — Two-Field Equality Check** (docs/01-engine-architecture.md)
- Checks *(param_1+4) == param_3 and *(param_1+2) == param_2 low short
- Returns 1 if both match, 0 otherwise
- Used as match predicate during send queue iteration
- Leaf function

### Level 2 — Deeper callees

**From FUN_0057d5d0:**
**FUN_0053d880 — Field Accessor (+0x8)** (triage: math_util)
- Returns small int from param_1+0x8
- Used as header field value
- Leaf function

**FUN_00587580 — Buffer Query: Return Ptr+Size If Valid** (docs/01-engine-architecture.md)
- If param_1[1] (capacity) < 1: sets *param_2=0, *param_3=0, returns 0
- Else: sets *param_2 = param_1[0] (data ptr), *param_3 = param_1[2] (size), returns 1
- Used for buffer validation before copy
- Calls FUN_00585770

### Level 3 — Termination leaf

**From FUN_00587580:**
**FUN_00585770 — Thread-Safe Int Read with Mutex** (docs/01-engine-architecture.md)
- Reads int at param_1+0xec under mutex at +0xf0 (handles WAIT_ABANDONED)
- Used as thread-safe state read during buffer validation
- Win32 APIs: WaitForSingleObject, ReleaseMutex
- Leaf function (no further calls in call_graph)

---

## Data Flow Summary

```
QueryData packet buffer ──→ FUN_0057d5d0 (encode with header)
                                  │
                                  ├──→ FUN_0053d880 (read header value from +0x8)
                                  └──→ FUN_00587580 (validate buffer)
                                        └──→ FUN_00585770 (thread-safe read)
                          
SendQueue (linked list at +0xaac) ──→ send() per matched entry
                                  │
                                  ├──→ FUN_0057b6b0 (get socket at +0x20)
                                  ├──→ FUN_0057b0d0 (iterate queries)
                                  ├──→ FUN_0057b2e0 (check handler at +0x24)
                                  ├──→ FUN_005871f0 (read state at +0x14)
                                  └──→ FUN_0057db80 (match 2-field predicate)
```

**Key struct (param_1, network manager):**
| Offset | Field | Type | Purpose |
|--------|-------|------|---------|
| +0xaac | SendQueuePtr | int* | Head of send queue linked list |
| +0xabc | SendMutex | HANDLE | Mutex for send queue |
| +0xac0 | MutexTimeout | DWORD | WaitForSingleObject timeout |
| +0x20 | Socket | SOCKET | Socket retrieved per-entry for send |

---

## Globals Written

No game-state globals. The chain operates on heap-allocated network manager struct and winsock API:
- `DAT_008d3e28` (network window handle, read by caller chain)
- Mutex handles and socket handles (Win32 kernel objects, closed on cleanup)

---

## Notes

- **Max depth = 4**: Seed → FUN_0057d5d0 → FUN_00587580 → FUN_00585770
- **Narrow chain**: 6 direct callees, 5 leaves, only 1 non-leaf path (query encode)
- **Thread safety**: Mutex at +0xabc protects send queue access; FUN_00585770 adds additional mutex for buffer read
- **Two-phase matching**: Fast path (direct filter) skips query iteration; full path iterates all registered queries
- **Undocumented callees**: FUN_0057b6b0, FUN_0057b0d0, FUN_0057b2e0, FUN_005871f0 exist only in triage index — no full doc entries
- **winsock dependency**: `send()` is the only external API called (winsock2)
- **Callers**: FUN_00570710 (line 715, context set), FUN_005813e0 (line 805, connection send), virtual dispatch from FUN_0057a6a0

---
