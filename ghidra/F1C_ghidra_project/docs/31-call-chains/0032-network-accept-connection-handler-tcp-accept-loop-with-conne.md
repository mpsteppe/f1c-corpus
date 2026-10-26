# Chain: Network Accept / Connection Handler — TCP Accept Loop with Connection Management

Seed: FUN_00580190  |  System: docs/21-audio-network-internals.md  |  Depth: 3  |  Functions: 9

---

## Overview

Called from the network listening thread. Polls a TCP listening socket via select() with zero timeout. On incoming connection: accepts, sets TCP_NODELAY, allocates connection tracking nodes, stores remote address. Manages two mutex-protected lists (connection list and completed list) for thread-safe access. Uses a secondary socket (param_1+0x93c) for cancellation signal.

## Call Tree

```
FUN_00580190 — Network Accept / Connection Handler  [listening thread: select/accept loop]
  +-- select, accept, htonl, htons, setsockopt, getpeername  [Win32 Winsock APIs]
  +-- WaitForSingleObject, ReleaseMutex  [Win32 sync APIs]
  +-- FUN_00582eb0 — Linked-List Node Removal with Cleanup Callback  [docs/01: list mgmt]
  |     +-- FUN_00587bcf — Free Wrapper  [heap free via FUN_0058aa6f]
  |     +-- FUN_004b0170 — Empty Stub  [cleanup callback no-op]
  +-- FUN_005830c0 — Object Allocation with SEH  [docs/20: allocates connection slot]
  |     +-- FUN_0058a6eb — N-Time Callback Loop with SEH  [allocation loop]
  |     +-- FUN_00582110 — SocketAddressInit  [init sockaddr_in struct]
  |     +-- FUN_0047aa60 — Empty Stub
  +-- FUN_00583530 — Zero-Fill Memory Region with Step  [docs/01: connection data init]
  |     +-- FUN_00586000 — Linked-List Node Append
  |     +-- FUN_00583210 — Linked List Node Alloc & Prepend
  +-- FUN_004979c0 — Setter  [docs/20: field assignment]
  +-- FUN_0057b6a0 — Pointer Advance  [docs/20: socket address advance]
  +-- FUN_0057dc10 — [undocumented]
  +-- FUN_0057cb50 — [undocumented: socket data check]  [called twice]
  +-- FUN_0057b6b0 — Offset Getter (param_1+0x20)  [docs/20]
  +-- FUN_00587bcf — Free Wrapper  [docs/01: list node cleanup]
        +-- FUN_0058aa6f — Heap Deallocation  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_00580190 — Network Accept / Connection Handler

**Trigger:** Called from network listening thread; polls for incoming TCP connections
**Called by:** No callers in call_graph.json (likely called from a dedicated accept thread via function pointer)
**Purpose:** Accepts incoming TCP connections, sets up socket options, and queues accepted connection handles for processing.

**Key actions:**
1. Calls select() with 0 timeout on listening socket (param_1+0x938)
2. If data available: accept() → new socket
3. Gets local address via htonl/htons
4. Waits on accept mutex (param_1+0xbec)
5. Allocates connection slot via FUN_005830c0(0), registers with FUN_00583530
6. Releases mutex
7. Sets TCP_NODELAY via setsockopt(IPPROTO_TCP, TCP_NODELAY, 1)
8. Gets remote address via getpeername → FUN_0057b6a0
9. Checks cancellation socket (param_1+0x93c) via FUN_0057cb50
10. Acquires second mutex (param_1+0xabc) for connection list access
11. Iterates connection list, allocates tracking nodes, appends
12. Releases mutex
13. Iterates completed list, checks socket handles via FUN_0057cb50
14. Frees processed nodes

**Struct fields used:**
- param_1+0x938 — ListenSocket (SOCKET)
- param_1+0x93c — CheckSocket (SOCKET, cancellation signal)
- param_1+0xbec — AcceptMutex (HANDLE)
- param_1+0xabc — Connection list mutex (HANDLE)

### Level 1: Network Primitives

**FUN_00582eb0 — Linked-List Node Removal** [docs/01-engine-architecture.md]
- Removes nodes from a linked list with cleanup callback
- Calls FUN_00587bcf to free node memory
- Calls FUN_004b0170 (empty stub) as cleanup callback

**FUN_005830c0 — Object Allocation with SEH** [docs/20-math-utilities.md]
- Allocates connection slot with SEH protection
- Calls FUN_0058a6eb (N-time callback loop with SEH) for retry logic
- Inits socket address via FUN_00582110

**FUN_00583530 — Zero-Fill Memory Region** [docs/01-engine-architecture.md]
- Fills connection data region with step pattern
- Appends node to tracking list via FUN_00586000
- Pre-allocates via FUN_00583210

**FUN_0057cb50** (called twice) — [undocumented]
- Checks socket for incoming data or error state

## Globals Written in This Chain

None directly — all state is managed via the connection struct (param_1).

## Notes

- All 9 callees are documented as utilities or infrastructure
- FUN_0057dc10 and FUN_0057cb50 are undocumented but are socket I/O related
- FUN_00587bcf (free wrapper) appears at multiple levels for cleanup
- Cross-system: docs/21-audio-network → docs/01-engine-architecture (FUN_00582eb0, FUN_00583530)
- Uses Winsock APIs directly (select, accept, setsockopt, getpeername)

---
