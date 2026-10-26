# Chain: LoadingPhase1 — Initial Loading Screen Processing

Seed: FUN_004b87c0  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 9 callees

---

## Overview

FUN_004b87c0 is the first phase of the loading screen sequence. Called by FUN_004b9890 (loading manager). Computes elapsed time, sets loading active flag, iterates over vehicles to load textures and copy state, calls FUN_004d8840 (audio init), seeds RNG with loading time, and loads chunks until total elapsed >= target duration. Callees cover vehicle loading (FUN_004b7a00, FUN_00566e20, FUN_004e3a50, FUN_004e1970, FUN_004ef5a0, FUN_004b86e0), audio init (FUN_004d8840), serialization (FUN_00408420), and loading state advance (FUN_004b8ae0). Controlled by DAT_005acd1c loading flow flag.

## Call Tree

```
FUN_004b87c0 — LoadingPhase1  [trigger: game loading state machine]
  +-- FUN_004b7a00 — Vehicle Load Helper  [load texture/state per vehicle]
  +-- FUN_00566e20 — Vehicle Setup  [vehicle state copy]
  +-- FUN_004e3a50 — Vehicle Subsystem Load  [subsystem initialization]
  +-- FUN_004e1970 — Vehicle Dynamic Load  [dynamics loading]
  +-- FUN_004ef5a0 — Vehicle Unload/Reload  [vehicle state reset]
  +-- FUN_004b86e0 — Loading State Update  [loading phase advance]
  +-- FUN_004d8840 — Audio Init During Load  [audio initialization]
  +-- FUN_00408420 — Serialization Read  [data deserialization]
  +-- FUN_004b8ae0 — Loading Phase Complete  [mark phase complete]
```

## Step-by-Step Trace

### Level 0: FUN_004b87c0 — LoadingPhase1

**Trigger:** Game loading state machine, called by FUN_004b9890
**Called by:** FUN_004b9890 (loading manager)
**Purpose:** First phase of loading screen — loads vehicle data, textures, audio

**Key actions:**
1. Computes elapsed time since load start
2. Sets loading active flag
3. Loops over vehicles: load texture, copy state via callees
4. Calls FUN_004d8840 for audio init
5. Seeds RNG with loading time
6. Loads chunks until total elapsed >= target duration

**Data passed to callees:** param_1 (loading state struct), vehicle index

### Level 1: Key Callees

**FUN_004b7a00 — Vehicle Load Helper**
- Loads vehicle textures and state data
- Called per vehicle in the loop

**FUN_004ef5a0 — Vehicle Unload/Reload**
- Resets vehicle state for fresh loading
- Called before loading each vehicle's data

**FUN_004d8840 — Audio Init During Load**
- Initializes audio subsystem during loading screen
- Called once before vehicle loop

**FUN_00408420 — Serialization Read**
- Deserializes configuration data from file
- Used during chunk loading loop

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Phase1 | Loading state | Compute elapsed time | Progress calculation |
| Vehicle loop | Vehicle index | FUN_004b7a00 etc. | Vehicle textures loaded |
| Audio init | — | FUN_004d8840 | Audio system ready |
| Chunk loop | Serialization data | FUN_00408420 | Data deserialized |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005acd1c | LoadingFlowFlag | (read by) | Controls loading flow |

## Notes

- Controlled by DAT_005acd1c loading flow flag (moddability medium)
- RNG seeded with loading time for randomized loading screen elements
- LoadingPhase2 (FUN_004b8940) continues after this completes, restoring vehicle states

---
