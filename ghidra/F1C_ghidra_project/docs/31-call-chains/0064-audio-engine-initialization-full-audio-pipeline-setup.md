# Chain: Audio Engine Initialization — Full Audio Pipeline Setup

Seed: FUN_00546010  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 13 callees

---

## Overview

FUN_00546010 initializes the audio engine. Called during scene init by FUN_004fa320 (VidMan::Init). Resets global sample counters, negotiates buffer size via FUN_0055b8c0, allocates mixer channels (0x1f0 bytes via operator_new), initializes the channel pipeline (FUN_005435d0/FUN_0053c5d0), sets up sample data (FUN_00543a80), initializes the mixer (FUN_00543fa0), flushes buffers (FUN_00545f50), iterates a processing chain linked list calling 5 setup functions (FUN_00549170/FUN_005492b0/FUN_00549380/FUN_00549440/FUN_00549470), and finalizes audio mode (FUN_0053ac70). On failure, frees resources via FUN_0053c630. Modifies DAT_008b8ee8-8ef8 (buffer size/counter globals).

## Call Tree

```
FUN_00546010 — Audio Engine Initialization  [trigger: scene init from VidMan::Init]
  +-- FUN_0055b8c0 — Buffer Size Negotiation  [retrieves buffer size to DAT_008b8ee8]
  +-- FUN_0053ac70 — Audio Mode Setup  [mode: 2=init, 1=finalize]
  +-- FUN_005435d0 — Channel Alloc  [allocates mixer channel]
  +-- FUN_0053c5d0 — Channel Init  [initializes channel state]
  +-- FUN_00543a80 — Sample Init  [initializes sample data]
  +-- FUN_00543fa0 — Mixer Init  [initializes audio mixer]
  +-- FUN_00545f50 — Buffer Flush  [resets/flushes audio buffers]
  +-- FUN_0053c630 — Cleanup  [frees resources on failure]
  +-- FUN_00549170 — Processing Chain Setup  [chain node 1]
  |     +-- [continues to FUN_005492b0]
  +-- FUN_005492b0 — Processing Chain Setup  [chain node 2]
  |     +-- [continues to FUN_00549380]
  +-- FUN_00549380 — Processing Chain Setup  [chain node 3]
  |     +-- [continues to FUN_00549440]
  +-- FUN_00549440 — Processing Chain Setup  [chain node 4]
  |     +-- [continues to FUN_00549470]
  +-- FUN_00549470 — Processing Chain Setup  [chain node 5 - leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00546010 — Audio Engine Initialization

**Trigger:** Scene/game initialization from VidMan::Init (FUN_004fa320)
**Called by:** FUN_004fa320 (VidMan::Init) with param_2=scenePath, param_3=0
**Purpose:** Full audio engine initialization — buffer allocation, channel setup, processing chain

**Key actions:**
1. Resets DAT_008b8ef8=0, DAT_008b8eec=0, DAT_008b8ee8=0 (global sample counters)
2. Calls FUN_0055b8c0(param_2, &DAT_008b8ee8) to negotiate buffer size
3. Sets DAT_008b8ef0 = DAT_008b8ee8, half-size = DAT_008b8ee8 / 2
4. Allocates 0x1f0 bytes for mixer channel via operator_new
5. Calls FUN_0053ac70(2, 0) to init audio mode
6. Initializes sample data via FUN_00543a80(param_2)
7. Initializes mixer via FUN_00543fa0()
8. Iterates processing chain linked list at *(*param_1 + 0x100), calls 5 setup functions
9. Finalizes with FUN_0053ac70(1, 0)

**Data passed to callees:** param_1 (audio system struct), param_2 (scene/config path)

### Level 1: Key Callees

**FUN_0055b8c0 — Buffer Size Negotiation**
- Reads buffer size info from audio device/system
- Writes size to DAT_008b8ee8
- Used to allocate sample data buffers

**FUN_0053ac70 — Audio Mode Setup**
- Called twice: once with (2, 0) for init, once with (1, 0) for finalize
- Controls audio pipeline mode transitions

**FUN_00549170..FUN_00549470 — Processing Chain Setup (5 functions)**
- Each function initializes one node in the audio processing chain
- Called sequentially, each passes to next via linked list at *(*param_1 + 0x100)
- Set up effects, filters, or codec stages in the audio pipeline

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00546010 | scenePath | Init sequence | Audio pipeline ready |
| FUN_0055b8c0 | param_2 | Negotiate | DAT_008b8ee8 = buffer size |
| Alloc | ~size/2 | operator_new 0x1f0 | Mixer channel object |
| FUN_00543fa0 | — | Mixer init | Mixer ready |
| 5× chain setup | chain list | Per-node init | Processing chain ready |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b8ee8 | AudioBufferSize | FUN_0055b8c0 | Total audio buffer size |
| DAT_008b8eec | HalfBufferSize | FUN_00546010 | Buffer size / 2 |
| DAT_008b8ef0 | BufferDataPtr | FUN_00546010 | Buffer pointer/reference |
| DAT_008b8ef4 | TotalSampleDataSize | FUN_00546010 | Accumulated sample size |
| DAT_008b8ef8 | BufferReadyCounter | FUN_00546010 | Incremented via InterlockedIncrement |

## Notes

- Audio mode functions (FUN_0053ac70) bracket the init sequence (mode 2 = start, mode 1 = finish)
- Processing chain has 5 nodes; each node setup function may have sub-callees but these are undocumented
- InterlockedIncrement used for thread safety during buffer flush
- On allocation failure, FUN_0053c630 frees allocated resources

---
