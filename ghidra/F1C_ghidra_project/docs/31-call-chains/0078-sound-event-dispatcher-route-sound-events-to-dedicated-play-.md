# Chain: Sound Event Dispatcher — Route sound events to dedicated play functions

Seed: FUN_00411e90  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 12

---

## Overview

Central sound event dispatcher called from game logic when a sound event fires. Routes 50+ event types (engine, exhaust, tire skid, collision, ambient, radio, gear, wind, rain) to dedicated play functions with randomized volume/pan. Uses _rand() for randomization. Reads pitch/volume/pan from param_3+0x10/0x14/0x18.

## Call Tree

```
FUN_00411e90 — Sound Event Dispatcher  [trigger: game logic sound event]
  +-- FUN_00413600 — EngineLoopSound  [event type 1 — docs/21]
  +-- FUN_00413710 — ExhaustSound  [event type 2 — docs/21]
  +-- FUN_004122c0 — TireSkidSound  [event type 4, 0x2f — docs/21]
  +-- FUN_00412490 — CollisionSound  [event types 5, 10, 0x17 — docs/21]
  +-- FUN_00412e50 — AmbientSound  [event types 0xe, 0x13, 0x29 — docs/21]
  +-- FUN_00414010 — RadioVoiceSound  [event types 0x11, 0x34 — docs/21]
  +-- FUN_004133b0 — GearChangeSound  [event type 0x1e — docs/21]
  +-- FUN_00413820 — WindSound  [event type 0x1f — docs/21]
  +-- FUN_004139c0 — RainSound  [event type 0x20 — docs/21]
  +-- FUN_00412c30 — SpecialSound  [event type 0x32 — docs/21]
  +-- FUN_00413b60 — UnusedSoundSlot  [unmapped event]
```

## Step-by-Step Trace

### Level 0: FUN_00411e90 — Sound Event Dispatcher

**Trigger:** Called from game logic when a sound event fires
**Called by:** Various game systems (FUN_004f12e0 vehicle sounds, collision system)
**Purpose:** Routes sound events to dedicated play functions.

**Key actions:**
1. Uses _rand() to add randomization to sound playback
2. Switch on param_2+0xc (sound event type):
   - 1: FUN_00413600 (engine loop)
   - 2: FUN_00413710 (exhaust)
   - 4, 0x2f: FUN_004122c0 (tire skid)
   - 5, 10, 0x17: FUN_00412490 (collision, repeat=1)
   - 6, 0x1b, etc: FUN_00412490 (collision, repeat=0)
   - 0xe, 0x13, 0x29: FUN_00412e50 (ambient)
   - 0x11, 0x34: FUN_00414010 (radio/voice)
   - 0x1e: FUN_004133b0 (gear change)
   - 0x1f: FUN_00413820 (wind)
   - 0x20: FUN_004139c0 (rain)
   - 0x32: FUN_00412c30 (special)
3. Uses param_3+0x10/0x14/0x18 for pitch/volume/pan arguments

**Data passed to callees:** param_3 (sound params with pitch/volume/pan)

### Level 1: All 11 play functions

All callees are dedicated sound play functions. None have further documented callees in call_graph.json.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00411e90 | param_2+0xc (event type) | Switch-case dispatch | Specific play function |
| FUN_00411e90 | param_3+0x10/0x14/0x18 | Pitch/volume/pan passed to callee | Sound playback |

## Notes

- All 11 callees are leaf sound play functions — no further recursion
- Some event types share callees (e.g., multiple types dispatch to same function)
- The dispatcher is hookable for mod sound customization
- Engine loop (type 1) and exhaust (type 2) are separate functions for RPM-based continuous sounds

---
