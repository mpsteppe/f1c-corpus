# Chain 43: NetworkConnectionManager — Mutex-guarded socket connection lookup/create + send

Seed: FUN_005813e0  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 9 callees

---

## Overview

Triggered during network session connection management. The function manages socket connections with mutex protection: walks a linked list of existing connections looking for a matching session ID, creates new socket if none found, checks connection status, and conditionally sends setup packets with htonl/htons byte ordering.

## Call Tree

```
FUN_005813e0 — NetworkConnectionManager  [trigger: network connection request]
  +-- FUN_00587030 — Object Init with VTable Setup  [stack setup]
  +-- FUN_00587310 — Binary Packet Field Parser with Offset Math  [param setup]
  |     +-- 1 leaf callee omitted
  +-- FUN_0057b7d0 — Socket Create  [creates Win32 socket]
  |     +-- 1 leaf callee omitted
  +-- FUN_0057b820 — Socket Close  [closes socket handle]
  |     +-- 1 leaf callee omitted
  +-- FUN_00587220 — [PARTIAL] Unknown  [connection check]
  +-- FUN_00587230 — Counter Increment/Decrement by Flag  [counter update]
  +-- FUN_00585d20 — Mutex-Protected Pointer Read + Release  [status query]
  +-- FUN_0057b9f0 — Copy 4 Dwords Struct to Struct  [socket setup]
  +-- FUN_0057dd40 — Socket Send  [sends data over socket]
```

## Step-by-Step Trace

### Level 0: FUN_005813e0 — NetworkConnectionManager

**Trigger:** Network connection setup or packet send request.
**Called by:** Orphan (no callers recorded in call_graph.json).
**Purpose:** Mutex-guarded socket connection lookup and creation with data transmission.

**Key actions:**
1. Sets up SEH exception frame for cleanup
2. Acquires mutex at param_1 + 0xad8 via WaitForSingleObject (timeout from param_1 + 0xadc)
3. Walks linked list at param_1 + 0xac8 matching session ID (local_14)
4. No match: allocates 0x20-byte node, creates socket via FUN_0057b7d0
5. Appends to linked list, increments count
6. Calls connection check via FUN_00587220
7. If connected (==2) and param_4 flag: sends setup packet via FUN_0057b9f0 + FUN_0057dd40 with htonl/htons
8. Post-send: queries FUN_00585d20 for status, if 3 and connected: resends
9. Releases mutex via ReleaseMutex

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xad8 | mutexHandle | Win32 mutex |
| +0xadc | mutexTimeout | Wait timeout in ms |
| +0xac8 | connectionList | Linked list head |
| +0xacc | listPrev | Previous pointer |
| +0xad0 | listCurrent | Current iterator |
| +0xad4 | listCount | Total connections |

### Level 1: Key callees

**FUN_0057b7d0 — Socket Create** — Creates Win32 socket via OS API. Returns handle to local_28.

**FUN_0057dd40 — Socket Send** — Sends data buffer over socket with htonl/htons byte ordering. Leaf function.

**FUN_0057b820 — Socket Close** — Closes socket handle. Leaf function.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| WaitForSingleObject | Mutex handle | Acquire mutex | WAIT_OBJECT_0 |
| FUN_0057b7d0 | Socket params | Create socket | Socket handle |
| FUN_0057b9f0 | Setup data | Copy to send buffer | Buffer ready |
| FUN_0057dd40 | Buffer + handle | Send over network | Bytes sent |
| ReleaseMutex | Mutex handle | Release mutex | Success |

## Globals Written in This Chain

None — all state is in param_1 struct.

## Notes

- Uses Win32 synchronization primitives (WaitForSingleObject, ReleaseMutex)
- Network byte ordering via htonl/htons
- Linked list nodes: [0]=handle, [1]=next, [2]=refcount
- `hardcoded`

---
