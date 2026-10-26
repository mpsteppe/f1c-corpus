# Chain 38: Team Radio/Network Message Processing — Radio dispatch with FIFO queue across drivers

Seed: FUN_0045f710  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 16 callees

---

## Overview

Triggered during network/radio update cycle. The seed processes team radio communication messages with conditional transmission dispatch. It checks radio state, initializes driver entries from the vehicle grid array, reads messages from a FIFO queue, appends team IDs for race mode, and sends radio messages per active driver. Gated by DAT_007d0f04 (radio silence flag) and lap counter DAT_007d0e98.

## Call Tree

```
FUN_0045f710 — Team Radio/Network Message Processing  [trigger: radio update tick]
  +-- FUN_00461440 — Session Flag Check  [checks radio state global]
  +-- FUN_004651c0 — Collision Detection  [checks active state]
  +-- FUN_004652d0 — Slot Activation Counter  [counts active driver slots]
  +-- FUN_0057a760 — SEH-Protected Data Copy  [reads message from FIFO queue]
  +-- FUN_00460c30 — Linear Search in 104-Element Array  [finds team frequency]
  +-- FUN_0045c8f0 — CollisionContactSolver  [resolves contact/radio state?]
  |     +-- 2 leaf callees omitted
  +-- FUN_0045d890 — NetComm Session Message Dispatcher  [network dispatch — cross-system: docs/09 →]
  |     +-- 21 callees (session sync, message buffer, player slot mgmt, see docs/09)
  +-- FUN_00461470 — Thunk to FUN_00461480  [channel setup]
  +-- FUN_00462300 — Single Function Dispatch  [local player ID]
  +-- FUN_004614c0 — Two-Stage Check  [validates channel]
  +-- FUN_004b3b30 — SessionDataCopy  [copies session data]
  +-- FUN_004b3af0 — AdvanceRingBuffer  [advances ring buffer ptr]
  +-- FUN_00462250 — Texture Creation Wrapper  [writes buffer data]
  +-- FUN_0057a730 — Two-Step Init Sub-Call  [queue init signal]
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [cleanup]
  +-- FUN_00465300 — Message Dispatch Node Allocator  [allocates message node]
```

## Step-by-Step Trace

### Level 0: FUN_0045f710 — Team Radio/Network Message Processing

**Trigger:** Network/radio update cycle per frame or per event.
**Called by:** FUN_00463ca0 (unknown caller context, likely main network update loop).
**Purpose:** Processes team radio communication messages with conditional transmission dispatch.

**Key actions:**
1. Calls FUN_00461440 to check radio state
2. Initializes driver entries via DAT_005ef9a0 (VehicleGridArray) loop with FUN_004652d0
3. Reads messages from FIFO queue (FUN_0057a760)
4. If race mode (param_1+0x3fc4 == 1 or 2), appends team ID via FUN_00460c30
5. For each active driver, sends radio message to team frequency
6. Checks DAT_007d0f04 (radio silence flag) and DAT_007d0e98 (lap counter)
7. Sends queue-init signal if conditions met
8. Cleans up via FUN_0057a730, FUN_004b0170

**Globals:** DAT_007d0f04 (radio silence flag), DAT_007d0e98 (lap counter), DAT_005ef9a0 (VehicleGridArray)

### Level 1: Key callees

**FUN_0045d890 — NetComm Session Message Dispatcher** — Cross-system to docs/09-track-system.md. Dispatches 21 callees for network message processing including session sync, player slot management, message display. Handles the actual network send path.

**FUN_00461440 — Session Flag Check** — Checks radio state flag. Leaf function.

**FUN_0057a760 — SEH-Protected Data Copy** — Reads message data from FIFO queue with exception handling. Leaf function.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00461440 | Radio state global | Check if radio enabled | enable flag |
| FUN_004652d0 | DAT_005ef9a0 | Count active driver slots | slot count |
| FUN_0057a760 | FIFO queue | Read message | message data |
| FUN_00460c30 | Team ID array | Find team frequency | frequency |
| FUN_0045d890 | Message + frequency | Network send (cross-system) | sent packet |

## Globals Written in This Chain

None directly — reads DAT_007d0f04 and DAT_007d0e98, does not write globals.

## Notes

- `configurable` — gated by DAT_007d0f04 (radio silence flag)
- Cross-system handoff to docs/09 via FUN_0045d890 for actual network transmission
- 16 callees, most are leaf or simple wrappers

---
