# Chain: Audio Buffer Format Setup — Configures audio buffer format and prepares playback

Seed: FUN_00541120  |  System: docs/21-audio-network-internals.md  |  Depth: 6  |  Functions: ~10

---

## Overview

FUN_00541120 configures audio buffer format (sample rate, channels, bits) and prepares playback buffer. Called during audio initialization or format change, it queries the audio system, validates source, sets format flags, prepares a playback buffer, and starts playback. The most complex callee is FUN_00546a0 (Multi-Field Setter Dispatching to 7 Sub-Setters) for buffer preparation.

## Call Tree

```
FUN_00541120 — Audio Buffer Format Setup  [trigger: audio init/format change]
  +-- FUN_00553db0 — Struct Init with Default Values  [leaf]
  +-- FUN_00554790 — set format  [leaf]
  +-- FUN_005546a0 — Multi-Field Setter Dispatching to 7 Sub-Setters  [7 callees]
  |     +-- FUN_00553fc0 — entity factory/creation  [leaf]
  |     +-- FUN_005542f0 — entity property set  [leaf]
  |     +-- FUN_005545e0 — Setter with Notification  [leaf]
  |     +-- FUN_00554560 — UI animation interpolation  [leaf]
  |     +-- FUN_00554610 — State Parameter Setter with Virtual Device Notify  [leaf]
  |     +-- [2 additional callees omitted]
  +-- FUN_00553fa0 — State Field Set with Chained Init  [sub: 2]
  +-- FUN_00554700 — Property Value Setter with Refresh on Change  [leaf]
  +-- FUN_00554f80 — source validation  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00541120 — Audio Buffer Format Setup

**Called by:** None documented (likely from audio system init)
**Purpose:** Configures audio buffer format (sample rate, channels, bits) and prepares playback buffer.

**Key actions:**
1. Calls audio system query (FUN_00553db0)
2. If source valid: copies buffer from device, sets format flags
3. Default: 0x100 (16-bit mono); param_4 & 0x40: 0x500 (16-bit stereo); param_5 < 0: adds 8-bit
4. Calls format apply (FUN_00554790), buffer prepare (FUN_005546a0), playback start (FUN_00553fa0), finalize (FUN_00554700)
5. Computes buffer size: if param_7 == 0, param_2 / 3, else param_7

### Level 1: FUN_005546a0 — Multi-Field Setter Dispatching to 7 Sub-Setters

**Called by:** FUN_00541120 (buffer preparation)
**Purpose:** Prepares buffer by dispatching to 7 sub-setters for various buffer properties.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00541120 | Audio format params (rate, channels, bits) | Format config + buffer alloc | Ready playback buffer |

## Globals Written in This Chain

None documented.

## Notes

- Chain is flat (depth 1-2).
- Cross-system: FUN_00554610 (State Parameter Setter with Virtual Device Notify) goes to docs/01-engine-architecture.

---
