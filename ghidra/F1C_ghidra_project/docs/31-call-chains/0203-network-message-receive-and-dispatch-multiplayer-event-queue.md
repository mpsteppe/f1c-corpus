# Chain 202: Network Message Receive and Dispatch — Multiplayer Event Queue

Seed: FUN_004c7ca0  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 6 callees

---

## Overview

FUN_004c7ca0 receives network messages and queues them per player in a linked-list event buffer. Guard: checks DAT_008acfcc (network active flag). Allocates 4096-byte receive buffer, iterates all players, receives data per player, allocates event objects, and appends to player's event queue. Triggered by FUN_004c8ae0 (Sound::Init) — called during sound/system initialization. The chain uses flag property getters (FUN_0054c110, FUN_0054c150), linked list node finders (FUN_005452f0, FUN_00545340), particle emitter init (FUN_004c9a50, docs/19), and transform dispatch (FUN_004c8f80, docs/01).

## Call Tree

```
FUN_004c7ca0 — Network Message Receive and Dispatch  [trigger: Sound::Init via 0x004c8ae0]
  +-- FUN_0054c110 — Render Flag Setter (Bitmask)  [docs/06 — leaf]
  +-- FUN_005452f0 — Audio/Network Node Count  [docs/06 — leaf]
  +-- FUN_00545340 — LinkedListNodeFinder  [docs/06 — leaf]
  +-- FUN_0054c150 — FlagPropertyGetter  [docs/06 — leaf]
  +-- FUN_004c9a50 — Memory Allocation / Particle Emitter Factory  [docs/19]
  |     +-- FUN_004c8f10 — ParticleEmitterInit  [docs/19]
  +-- FUN_004c8f80 — Transform Dispatch / VTable Method Dispatch  [docs/01]
        +-- FUN_004c8f10 — ParticleEmitterInit  [docs/19]
```

## Step-by-Step Trace

### Level 0: FUN_004c7ca0 — Network Message Receive and Dispatch

**Trigger:** Called by FUN_004c8ae0 (Sound::Init) during module initialization.
**Called by:** FUN_004c8ae0 (sound hardware init)
**Purpose:** Receives network messages and queues them per player in linked-list buffer.

**Key actions:**
1. Checks DAT_008acfcc (network active flag) — if not set, skip
2. Starts receive operation with 4096-byte buffer
3. Iterates all players: starts per-player receive
4. If data received: allocates event object, processes message
5. If processing returns 0: creates linked list node, appends to player's event queue
6. If processing returned non-zero: calls virtual destructor

**Globals read:**
- DAT_008acfcc — network active flag

### Level 1: FUN_0054c110 — Render Flag Setter (Bitmask)

**Trigger:** Called during receive setup to query/render flags.
**Purpose:** Gets/sets render flags via bitmask operations.

### Level 1: FUN_004c9a50 — Memory Allocation / Particle Emitter Factory

**Trigger:** Called to allocate event objects on receive.
**Purpose:** Allocates memory for particle emitter / event objects.

**Key actions:**
1. Allocates memory block
2. Calls FUN_004c8f10 (ParticleEmitterInit) to initialize

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004c7ca0 | Network buffer | Receive message | Event queue |
| FUN_005452f0 | Player list | Count players | Node count |
| FUN_00545340 | Event list | Find node | Matching node |
| FUN_004c9a50 | Event data | Allocate memory | Event object |
| FUN_004c8f80 | Event object | Transform dispatch | Processed event |

## Notes

- 6 callees, mix of docs/06 (session/race), docs/19 (renderer), docs/01 (engine)
- Despite being in docs/21 (audio-network), most callees are from other systems
- FUN_004c9a50 allocates particle emitters — suggests network events may trigger visual effects
- Cross-system: FUN_004c8f80 from docs/01 (vtable dispatch)

---
