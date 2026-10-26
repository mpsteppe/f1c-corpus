# Chain: Network Connection / Session Management — TCP connection lifecycle, session join, reconnection retry

Seed: FUN_00563260  |  System: docs/21-audio-network-internals.md  |  Depth: 5  |  Functions: 20

---

## Overview

FUN_00563260 manages the full TCP connection lifecycle for multiplayer in F1 Challenge 99-02. Called from the configuration/setup pipeline (FUN_00461ed0 — Directory String Processing with Decode), it handles three distinct connection modes: initial fresh connection (client or host), reconnection after disconnect, and session bind for existing connections.

The chain spans 20 unique functions across 4 doc files. The call tree is wide (9 direct callees) but relatively shallow (max depth 5). Non-leaf callees cluster around three utility subsystems: buffer/memory management (FUN_005648d0 stack, FUN_005646d0 factory alloc, FUN_005642f0 struct alloc), sleep/poll loop (FUN_00563000 listen mode), and cleanup wrappers (FUN_005648c0 thunk to FUN_005648d0).

Key integration points: Winsock socket creation via AF_INET/SOCK_DGRAM/UDP, vtable-based audio callback dispatch, Win32 Sleep() for polling loop, and memory realloc for dynamic buffer growth.

## Call Tree

```
FUN_00563260 — Network Connection / Session Management  [docs/21-audio-network-internals.md]
  |
  +-- FUN_005631a0 — Two-Step Dispatch / session resolve  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00562d20 — SocketArrayCreate  [docs/21-audio-network-internals.md]
  |     Creates UDP sockets via socket(2,2,0x11). Error-handles failures. LEAF
  |
  +-- FUN_00563160 — Conditional Network Utility / client connect  [docs/21-audio-network-internals.md]
  |     If param_1 non-null: calls network send + cleanup
  |     |
  |     +-- FUN_005642f0 — Struct Alloc/Init w/ Switch-Based Type  [docs/20-math-utilities.md]
  |     |     Allocates struct, dispatches by type param
  |     |     |
  |     |     +-- FUN_005646d0 — Allocate Int Array via Factory  [docs/01-engine-architecture.md]
  |     |           Allocates 0x14-byte control struct + int array, fills via factory
  |     |           |
  |     |           +-- FUN_00564810 — Malloc 0x18-byte Struct + Inner Buffer  [docs/21-audio-network-internals.md] LEAF
  |     |
  |     +-- FUN_005648c0 — Single Function Call Wrapper / cleanup  [docs/01-engine-architecture.md]
  |           Thunk: reads *param_1, calls FUN_005648d0
  |           |
  |           +-- FUN_005648d0 — Audio Stack Push with Overflow Realloc  [docs/21-audio-network-internals.md]
  |                 (see below for full subtree)
  |
  +-- FUN_005648b0 — Linear Interpolation / socket/port mgmt  [docs/20-math-utilities.md] LEAF
  |     Used as array base pointer getter
  |
  +-- FUN_00563e70 — Pointer Dereference Accessor / max clients  [docs/20-math-utilities.md] LEAF
  |
  +-- FUN_00562fe0 — Audio Value Setter + Call / network init  [docs/21-audio-network-internals.md] LEAF
  |     Writes param_2 to param_1[0], calls vtable[0x1e] audio callback
  |
  +-- FUN_00563000 — Polling Loop with Process Calls / listen mode  [docs/01-engine-architecture.md]
  |     Polls *param_1 flag, calls two functions per iteration
  |     |
  |     +-- FUN_00563410 — engine processing  [undocumented] LEAF
  |     +-- FUN_00564650 — Sleep Wrapper  [docs/01-engine-architecture.md]
  |           Calls Win32 Sleep(). LEAF
  |
  +-- FUN_005633d0 — Display Mode Query Wrapper / reconnect  [docs/19-renderer.md]
  |     Wrapper: struct alloc + audio stack push
  |     |
  |     +-- FUN_005642f0 — Struct Alloc/Init  [docs/20-math-utilities.md]
  |     |     (see above for subtree → FUN_005646d0 → FUN_00564810)
  |     |
  |     +-- FUN_005648d0 — Audio Stack Push with Overflow Realloc  [docs/21-audio-network-internals.md]
  |           (see below for full subtree)
  |
  +-- FUN_00563230 — Array-of-Struct Stride Search by ID / session bind  [triage only] LEAF

--- Shared Subtree: FUN_005648d0 — Audio Stack Push with Overflow Realloc ---
  FUN_005648d0(param_1=stack_struct, param_2=value)
    |
    +-- [if top == capacity] FUN_00564930 — Accumulator with Realloc on Growth  [docs/01-engine-architecture.md]
    |     Accumulates size, reallocs buffer when exceeded
    |     |
    |     +-- FUN_0058b5d4 — memory reallocation wrapper  [docs/06-session-race-logic.md] LEAF
    |
    +-- FUN_005648b0 — Linear Interpolation (size calculation)  [docs/20-math-utilities.md] LEAF
    |
    +-- FUN_0058b130 — Memory resize/realloc  [undocumented] LEAF
    |
    +-- FUN_00564960 — Aligned Memory Copy from Struct Buffer  [docs/01-engine-architecture.md]
          Copies data with alignment
          |
          +-- FUN_005648b0 — Linear Interpolation  [docs/20-math-utilities.md] LEAF
```

## Step-by-Step Trace

### Level 0 — Seed
**FUN_00563260 — Network Connection / Session Management** (docs/21-audio-network-internals.md, line 1910):
- Called from FUN_00461ed0 (Directory String Processing with Decode / Configuration set)
- 9 direct callees
- Three code paths based on `*param_1` (ConnectionState) and session variable:

**Path A — Initial/Fresh Connection (`*param_1 == 0`):**
1. Resolve IP via `inet_addr(param_2)`
2. Resolve session via `FUN_005631a0(param_3)` — LEVEL 1 LEAF
3. Create socket via `FUN_00562d20()` — creates UDP socket array, returns handle
4. If session == -1 (client mode):
   - `FUN_00563160(param_3, param_5)` — initiate client connection → branches to Level 2
5. Else (host mode):
   - Get socket via `FUN_005648b0()` — LEVEL 1 LEAF
   - Set port 9999, call `FUN_00564990()` + `FUN_005648c0()` — cleanup wrapper
6. `FUN_00563e70()` — get max clients → store at `param_1[0x1c]`
7. `FUN_00562fe0()` — network init finalization → LEVEL 1 LEAF
8. If `param_4 == 0`: `FUN_00563000()` — enter listen mode → poll loop at Level 2

**Path B — Reconnection (`*param_1 > 0` and session == -1):**
1. `FUN_005633d0(param_3, param_1[0x1c], param_5)` — reconnect handler
2. If state is 1 or 2: increment `param_1[0x26]` (retry counter)

**Path C — Existing Connection / Session Bind:**
1. Allocate socket via `FUN_005648b0()` — LEVEL 1 LEAF
2. If session index < max clients: set up socket, `FUN_00563230()` — session bind
3. Clear client entry, decrement max clients counter

Returns 0 on all paths.

### Level 1 — Direct Callees

**1. FUN_005631a0 — Two-Step Dispatch / session resolve** (docs/20-math-utilities.md)
- Calls FUN_00563e70(), passes result to FUN_005631d0
- Confidence: high | Algorithm: unknown | call_count: 0
- **LEAF** — no further callees tracked in call_graph

**2. FUN_00562d20 — SocketArrayCreate** (docs/21-audio-network-internals.md, line 2478)
- Loops `param_1+0x6c` times, creates UDP sockets via `socket(2, 2, 0x11)` = AF_INET, SOCK_DGRAM, IPPROTO_UDP
- Stores handles at stride 0x1c, error-handles failures
- **LEAF** — no further callees tracked

**3. FUN_00563160 — Conditional Network Utility / client connect** (docs/21-audio-network-internals.md, line 2997)
- Guards on param_1; if null returns 0
- Calls `FUN_005642f0(param_3, *(param_1+0x94))` — struct alloc/init
- Calls `FUN_005648c0` — cleanup wrapper
- **Branches to Level 2** (2 callees)

**4. FUN_005648b0 — Linear Interpolation / socket/port mgmt** (docs/20-math-utilities.md)
- Returns array base pointer / computed interpolation value
- Used in seed as socket getter, in deeper chain as buffer size calculator
- **LEAF** — call_count: 0

**5. FUN_00563e70 — Pointer Dereference Accessor / max clients** (docs/20-math-utilities.md)
- Dereferences and returns pointer value
- Used as array size/count getter
- **LEAF** — call_count: 0

**6. FUN_00562fe0 — Audio Value Setter + Call / network init** (docs/21-audio-network-internals.md, line 3179)
- Writes param_2 to param_1[0]
- Calls vtable[0x1e] (offset +0x78) with 5 args — audio callback dispatch
- Used as "network init finalization" in seed context
- **LEAF** — call_count: 0

**7. FUN_00563000 — Polling Loop with Process Calls / listen mode** (docs/01-engine-architecture.md, line 12065)
- Reads `*param_1` flag; while non-zero loops:
  - `FUN_00563410(param_1)` — engine processing (undocumented)
  - `FUN_00564650(param_1)` — Sleep wrapper
- **Branches to Level 2** (2 callees)

**8. FUN_005633d0 — Display Mode Query Wrapper / reconnect** (docs/19-renderer.md, line 7672)
- Calls `FUN_005642f0(param_4, *(param_1+0x94))` — struct alloc/init
- Calls `FUN_005648d0(param_3)` — audio stack push
- **Branches to Level 2** (2 callees)

**9. FUN_00563230 — Array-of-Struct Stride Search by ID / session bind** (triage only)
- Stride search algorithm: searches array-of-struct by matching ID field
- **LEAF** — call_count: 0

### Level 2 — Second Depth

**From FUN_00563160 (client connect):**

**FUN_005642f0 — Struct Alloc/Init with Switch-Based Type** (docs/20-math-utilities.md)
- Allocates struct, dispatches construction by type parameter
- Calls FUN_005646d0 (factory alloc)
- **Branches to Level 3**

**FUN_005648c0 — Single Function Call Wrapper / cleanup** (docs/01-engine-architecture.md, line 1232)
- Reads *param_1, calls FUN_005648d0(*param_1)
- Thunk/indirection pattern
- **Branches to Level 3**

**From FUN_00563000 (listen mode):**

**FUN_00563410 — engine processing** (undocumented)
- Not in functions.json — no metadata available
- **LEAF** — no further callees

**FUN_00564650 — Sleep Wrapper** (docs/01-engine-architecture.md, line 10918)
- `Sleep(param_1)` — Win32 API passthrough
- **LEAF**

**From FUN_005633d0 (reconnect):**

**FUN_005642f0** — same struct alloc/init as above → branches to Level 3

**FUN_005648d0 — Audio Stack Push with Overflow Realloc** (docs/21-audio-network-internals.md, line 2761)
- Dynamic stack/buffer push with overflow growth
- 4 callees: FUN_00564930 (buffer growth), FUN_005648b0 (interpolation), FUN_0058b130 (realloc), FUN_00564960 (aligned memcpy)
- **Branches to Level 3**

### Level 3 — Third Depth

**From FUN_005642f0:**

**FUN_005646d0 — Allocate Int Array via Factory** (docs/01-engine-architecture.md, line 12080)
- Allocates 0x14-byte control struct + param_2*4-byte int array
- Fills array via factory function FUN_00564810
- **Branches to Level 4**

**From FUN_005648c0 → FUN_005648d0:**

**FUN_005648d0** — (same as above, see shared subtree)

**From FUN_005648d0 (Audio Stack Push):**

**FUN_00564930 — Accumulator with Realloc on Growth** (docs/01-engine-architecture.md, line 2556)
- Accumulates size + addend, calls realloc if new size > allocation
- Calls FUN_0058b5d4 (memory reallocation wrapper)
- **Branches to Level 4**

**FUN_005648b0 — Linear Interpolation** (docs/20-math-utilities.md)
- Used for size calculation in growth path
- **LEAF**

**FUN_0058b130 — Memory resize/realloc** (docs/06-session-race-logic.md @ triage)
- Realloc/memory resize operation
- **LEAF** — call_count: 0

**FUN_00564960 — Aligned Memory Copy from Struct Buffer** (docs/01-engine-architecture.md)
- Aligned memcpy from struct buffer to destination
- Calls FUN_005648b0 (interpolation)
- **Branches to Level 4**

### Level 4 — Fourth Depth

**From FUN_005646d0:**

**FUN_00564810 — Malloc 0x18-byte Struct with Inner Buffer** (docs/21-audio-network-internals.md)
- Allocates 0x18-byte control struct + inner buffer of controlled size
- **LEAF** — call_count: 0

**From FUN_00564930:**

**FUN_0058b5d4 — memory reallocation wrapper** (docs/06-session-race-logic.md @ triage)
- Realloc wrapper (potentially heap_realloc or similar)
- **LEAF** — call_count: 0

**From FUN_00564960:**

**FUN_005648b0 — Linear Interpolation** (docs/20-math-utilities.md)
- Same as Level 1/3 — convergence point
- **LEAF**

### Level 5 — Termination
No functions reach Level 5. Maximum depth is 4 (seed → 3 callee levels → leaf).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 1 | `param_2` (IP string) | `inet_addr()` | Resolved IP address |
| 2 | `param_3` (session token) | `FUN_005631a0()` | Session identifier |
| 3 | Connection state | `FUN_00562d20()` | UDP socket array |
| 4a | [client] session ID + param_5 | `FUN_00563160()` → `FUN_005642f0()` | Allocated network struct |
| 4b | [client] cleanup path | `FUN_005648c0()` → `FUN_005648d0()` | Audio stack push |
| 4c | [host] socket array | `FUN_005648b0()` | Socket handle |
| 5 | N/A | `FUN_00563e70()` | Max client count |
| 6 | value + audio struct | `FUN_00562fe0()` | Audio callback dispatch |
| 7 | [listen] flag | `FUN_00563000()` → loop | Engine process + Sleep |
| 8 | [reconnect] session + retry | `FUN_005633d0()` | Struct alloc + audio push |
| 9 | [bind] session index | `FUN_00563230()` | Session bound to socket |

**Data flowing through network session struct (param_1):**
| Offset | Field | Source |
|--------|-------|--------|
| +0x00 | ConnectionState | Int, 0=initial, 1+=connected |
| +0x08 (param_1[2]) | ClientDataArray | Ptr, client data array stride 0x1c |
| +0x70 (param_1[0x1c]) | MaxClients | From FUN_00563e70 |
| +0x74 (param_1[0x1d]) | ConnAttempts | Connection attempt counter |
| +0x98 (param_1[0x26]) | RetryCount | Reconnection retry counter |

## Globals Written

No game-state globals directly written by this chain. Functions operate on:
- Network session struct pointed by param_1 (offsets above)
- UDP socket array allocated by FUN_00562d20
- Audio callback dispatched via vtable[0x1e] in FUN_00562fe0
- Heap allocations via FUN_00564810 (malloc), FUN_0058b130/FUN_0058b5d4 (realloc)
- Win32 Sleep() API — no global state impact
- `inet_addr()` — resolves IP string, no global write
- Winsock socket handles — internal kernel state, not game globals

## Notes

- **Max depth:** 4 (seed → 3 intermediate levels → leaf). Most paths terminate at Level 2.
- **Convergence points:**
  - FUN_005642f0 (Struct Alloc/Init) — called from both FUN_00563160 and FUN_005633d0
  - FUN_005648d0 (Audio Stack Push) — called from FUN_005648c0, FUN_005633d0, and FUN_005648c0
  - FUN_005648b0 (Linear Interpolation) — called from seed, FUN_005648d0, FUN_00564960
- **Knowledge graph discrepancies:**
  - FUN_005648b0 labeled "Linear Interpolation" in functions.json but used as socket/port getter in seed context — likely a multipurpose utility
  - FUN_00563e70 labeled "Pointer Dereference Accessor" in functions.json but returns max clients in seed context
  - FUN_00562fe0 labeled "Audio Value Setter + Call" but used as "network init finalization" in seed — called for side-effect audio callback during network setup
  - FUN_005633d0 labeled "Display Mode Query Wrapper" in docs/19 but used as reconnect handler in seed context
- **Undocumented functions:** FUN_00563410 (engine processing) has no functions.json entry at all — likely a core loop callback dispatched by pointer
- **Winsock usage:** Only FUN_00562d20 makes direct Winsock calls (socket()), and FUN_00563260 calls inet_addr(). Other network functions likely use the socket handles indirectly.
- **Audio-network coupling:** FUN_00562fe0 and FUN_005648d0 show tight coupling between network setup and audio subsystem — network init dispatches an audio callback, and reconnect pushes to the audio stack
- **Listen mode loop:** FUN_00563000 is a tight polling loop (Sleep per iteration) — suggests a dedicated listen thread or cooperative multitasking slot
- **Caller:** Only 1 caller — FUN_00461ed0 (Directory String Processing with Decode / Configuration set) — called during multiplayer session configuration
- **Moddability:** Port hardcoded to 9999, max clients from FUN_00563e70 (configurable)
