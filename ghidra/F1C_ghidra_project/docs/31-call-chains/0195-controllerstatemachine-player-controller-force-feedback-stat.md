# Chain 194: ControllerStateMachine — Player Controller/Force-Feedback State Machine

Seed: FUN_00516c7b  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 14 callees

---

## Overview

FUN_00516c7b manages the player controller force-feedback state machine. It processes controller state at 14 sub-function callees spanning init (FUN_00516a1d, FUN_005169ac), audio/DSP processing (FUN_0051a4f2, FUN_0051aec2, FUN_0051ba70, FUN_0051cb6d, FUN_0051c3e2, FUN_0051d166), rendering compositing (FUN_005199d5, FUN_00519bb2, FUN_00519d51), buffer management (FUN_005198b3, FUN_0051bc88, FUN_0051bf23), and UI list construction (FUN_0051a4f2). Triggered by FUN_00516f76 (constructor init) during controller/input system setup.

## Call Tree

```
FUN_00516c7b — ControllerStateMachine  [trigger: constructor init via FUN_00516f76]
  +-- FUN_00516a1d — Audio Sample Rate Conversion  [docs/21 — audio rate conversion]
  |     +-- FUN_00515917 — Ceiling Division  [leaf, math_util]
  |     +-- FUN_0051593f — 2D Array Block Copy  [leaf, math_util]
  +-- FUN_00516c0c — Buffer Init with Identity Pattern  [leaf]
  +-- FUN_005169ac — Complex State Validator  [leaf]
  +-- FUN_0051eb6e — Object Alloc + Callback Setup + Bounds Validation  [docs/01]
  |     +-- FUN_0051bad1 — Audio DSP Filter Selector  [docs/21 — has 6 callees]
  |     +-- FUN_0051a4b7 — Protocol State Handler  [docs/06]
  |     +-- FUN_0051cd53 — Audio Sample Stream  [docs/06]
  +-- FUN_0051e0dc — Unidentified Logic / D3D Device Buffer Alloc  [docs/19]
  |     +-- FUN_0051e2ba — Resource Decompression Output Filler  [docs/19]
  +-- FUN_0051cb6d — Input Binding/Config Setup  [docs/20]
  |     +-- 5 leaf callees (FUN_0051c5a3, FUN_0051c653, FUN_0051c6be, etc.)
  +-- FUN_0051c3e2 — Media/Audio Decode Dispatch  [docs/20]
  |     +-- FUN_0051c94f — Indexed Surface Blit  [docs/19]
  |     +-- FUN_0051c6be — 2D Copy Delegation  [docs/20]
  +-- FUN_0051d166 — Stream Decoder Init  [docs/06]
  |     +-- FUN_0051bf23 — Playback Buffer Alloc  [docs/06]
  |     +-- FUN_0051bc88 — UI List/ComboBox Buffer Alloc  [docs/06]
  |     +-- FUN_0051bfc0 — Audio Buffer Mixing  [docs/06 — leaf]
  |     +-- FUN_0051a4f2 — UI List/ComboBox Constructor  [docs/06 — has 5 callees]
  +-- FUN_0051bf23 — Playback Buffer Alloc  [leaf, docs/06]
  +-- FUN_0051bc88 — UI List/ComboBox Buffer Allocator  [docs/06]
  |     +-- FUN_0051bce8 — [leaf]
  +-- FUN_0051aec2 — Huffman Context Alloc  [leaf, docs/06]
  +-- FUN_0051ba70 — Huffman Tree Alloc  [leaf, docs/06]
  +-- FUN_0051a4f2 — UI List/ComboBox Constructor  [docs/06 — 5 callees]
  |     +-- FUN_0051a5ea — Huffman/Compression Tree Builder
  |     +-- FUN_00519986 — Sprite Frame Selector
  |     +-- FUN_00534d50 — Stream/Format Parser
  |     +-- FUN_00535550 — Passthrough
  |     +-- FUN_00535620 — Arithmetic / Struct Reset + Status Check
  +-- FUN_005198b3 — Media Buffer Alloc  [leaf, docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_00516c7b — ControllerStateMachine

**Trigger:** Called by FUN_00516f76 constructor during controller input system init.
**Called by:** FUN_00516f76 (constructor init)
**Purpose:** State machine managing player controller/force-feedback transitions.

**Key actions:**
1. Calls FUN_00516a1d and FUN_00516c0c for init/sub-state update
2. Stores state byte from FUN_005169ac at +0x10
3. Main dispatch on mode at +0x19 (mode 3 = triggered, other modes = default)
4. When active: dispatches to audio/DSP processing (FUN_0051eb6e, FUN_0051e0dc)
5. When flags set: calls FUN_0051cb6d + FUN_0051c3e2 or FUN_0051d166
6. End of frame: sets up effect object at unaff_ESI[2] with duration

**Data passed to callees:** Controller state struct pointer (unaff_ESI), mode/flag values

### Level 1: FUN_0051eb6e — Object Alloc + Callback Setup

**Trigger:** Called when controller active flag (+0x16) is set.
**Purpose:** Allocates object, sets up callbacks, validates size bounds.

**Key actions:**
1. Allocates audio processing object
2. Sets up callback functions
3. Validates size bounds
4. Calls FUN_0051bad1 (Audio DSP Filter Selector) and FUN_0051a4b7 (Protocol State Handler)

### Level 2 (from FUN_0051eb6e): FUN_0051bad1 — Audio DSP Filter Selector

**Trigger:** Called during audio processing object setup.
**Purpose:** Selects and configures audio DSP filter chain.

**Key actions:**
1. Dispatches to 6 sub-callees including FUN_0051e3e7 (Audio Waveform Table Generator), FUN_0051ea5a (Virtual Array Fill), FUN_0051df18 (Symmetric Array Init)
2. Cross-system: docs/21-audio-network-internals.md

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00516c7b | Controller struct | Mode dispatch | State flags at +0x10, +0x16, +0x59, +0x5a |
| FUN_0051eb6e | Controller flags | Object allocation | Audio processing object |
| FUN_0051e0dc | Intensity (+0x69) | D3D buffer alloc | Render buffer |
| FUN_0051a4f2 | UI config data | List construction | UI list |

## Notes

- 14 callees, heavy mix of audio/DSP (docs/21), renderer (docs/19), and UI (docs/06)
- FUN_0051bad1 is a cross-system handoff to docs/21 (audio internals)
- Controller struct has 14 documented offsets (see doc entry)
- FUN_0051a4f2 (UI List/ComboBox Constructor) appears twice in call tree — called both directly from seed and via FUN_0051d166

---
