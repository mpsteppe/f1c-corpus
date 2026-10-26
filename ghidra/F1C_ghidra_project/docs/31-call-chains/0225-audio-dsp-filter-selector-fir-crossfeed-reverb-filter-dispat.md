# Chain: Audio DSP Filter Selector — FIR/Crossfeed/Reverb Filter Dispatch

Seed: 0x0051bad1  |  System: docs/21-audio-network-internals.md  |  Depth: 1  |  Functions: 6

---

## Overview

Called from audio list item handler (0x0051bc88) during audio playback. Selects and applies DSP filter effect based on mode flags (1,2,4,8): mode 0 = linear passthrough, mode 1 = FIR filter from DAT_005b0508 coefficient table, mode 2 = stereo crossfeed from DAT_005b0588 table, mode 8 = three sub-mode variations. All 6 callees are undocumented leaf DSP filter functions. Stride 0x15 per audio channel = 21 bytes/channel.

## Call Tree

```
0x0051bad1 — Audio DSP Filter Selector  [trigger: audio playback DSP stage]
  +-- 0x0052851d — [undocumented DSP filter - mode 1/2/4/8 variation]
  +-- 0x0052835f — [undocumented DSP filter - mode 1/2/4/8 variation]
  +-- 0x0052804a — [undocumented DSP filter - mode 0 linear]
  +-- 0x0052855a — [undocumented DSP filter - mode 8 var 0]
  +-- 0x005285a6 — [undocumented DSP filter - mode 8 var 1]
  +-- 0x005285f2 — [undocumented DSP filter - mode 8 var 2]
```

## Step-by-Step Trace

### Level 0: 0x0051bad1 — Audio DSP Filter Selector

**Trigger:** Called during audio playback DSP processing stage
**Called by:** 0x0051bc88 (audio list item handler)
**Purpose:** Dispatches to DSP filter implementations based on mode flags

**Key actions:**
1. Reads mode flags (1,2,4,8) to select filter type
2. Mode 0 (linear passthrough): dispatches to 0x0052804a, copies 64 samples unchanged
3. Mode 1 (FIR filter): dispatches to 0x0052851d/0x0052835f, applies coefficients from DAT_005b0508
4. Mode 2 (crossfeed): dispatches to filter, uses DAT_005b0588 table for stereo crossfeed mixing
5. Mode 8: dispatches to 0x0052855a/0x005285a6/0x005285f2 for 3 sub-variations (reverb/delay/other)
6. Error codes: 0x2f (invalid mode), 0x06 (processing error)
7. Operates with stride 0x15 (21 bytes) per audio channel

**Data passed to callees:** audio sample buffer, coefficient tables, channel count

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x0051bad1 | mode flags | Select filter | dispatch target |
| 0x0052804a | 64 samples | Linear copy | passthrough samples |
| 0x0052851d | DAT_005b0508, samples | FIR convolution | filtered samples |
| 0x0052835f | DAT_005b0588, samples | Crossfeed mix | stereo samples |

## Globals Written in This Chain

None — reads from coefficient tables (DAT_005b0508, DAT_005b0588) but writes only to output buffer

## Notes

- All 6 callees are undocumented leaf DSP functions
- Coefficient tables at DAT_005b0508 (FIR) and DAT_005b0588 (crossfeed) are the moddable parameters
---
