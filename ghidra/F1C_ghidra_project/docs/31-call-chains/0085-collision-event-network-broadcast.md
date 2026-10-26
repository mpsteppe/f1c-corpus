# Chain: Collision Event Network Broadcast

Seed: FUN_00462940  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 5

---

## Overview

Broadcasts collision event to network peers during multiplayer sessions. Checks if vehicle type is player or remote player (1 or 2 at +0x3fc4), creates network message, allocates buffer, sends via event broadcast system, and cleans up. Writes current session time from DAT_008afea0.

## Call Tree

```
FUN_00462940 — Collision Event Network Broadcast  [trigger: collision event in multiplayer]
  +-- FUN_004b33b0 — EventBroadcastSystem  [game event broadcast — leaf]
  +-- FUN_0057a680 — NetworkMessageCreate  [create network message]
  +-- FUN_0057a6a0 — BufferAlloc  [allocate send buffer]
  +-- FUN_0057a690 — MessageRelease  [release message handle — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00462940 — Collision Event Network Broadcast

**Trigger:** Called when a collision occurs during multiplayer session
**Called by:** Collision response system
**Purpose:** Broadcasts collision event to network peers.

**Key actions:**
1. Checks if vehicle type (*(param_1+0x3fc4)) is 1 or 2 (player/remote player vehicles)
2. Calls FUN_004b33b0 (event broadcast system) with collision type 0x20
3. Creates network message via FUN_0057a680
4. Allocates buffer for network send via FUN_0057a6a0
5. Returns success/failure flag
6. Cleans up message handle via FUN_0057a690

**Data passed to callees:** Vehicle pointer, collision type, session time

### Level 1: All 4 callees

FUN_004b33b0 and FUN_0057a690 are leaf functions. FUN_0057a680 and FUN_0057a6a0 are network message/buffer operations.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00462940 | param_1+0x3fc4 | Check vehicle type 1 or 2 | Player vehicle check |
| FUN_00462940 | DAT_008afea0 (session time) | Pass to event broadcast | Network event |
| FUN_00462940 | Collision type 0x20 | Network message create + buffer alloc | Sent message |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afea0 | SessionTime | (read by FUN_00462940) | Current session time |

## Notes

- Only broadcasts for player/remote player vehicles (types 1 and 2)
- Collision event type 0x20 used for identification on receiving end
- Network message/buffer functions (FUN_0057a680/FUN_0057a6a0) are cross-system into docs/21-audio-network-internals.md
- All 4 callees are leaf functions — no further recursion
