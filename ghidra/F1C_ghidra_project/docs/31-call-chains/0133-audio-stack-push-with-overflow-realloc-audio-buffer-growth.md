# Chain: Audio Stack Push with Overflow Realloc — Audio Buffer Growth

Seed: FUN_005648d0  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 5

---

## Overview

Pushes data onto an audio stack buffer with automatic overflow reallocation. Called when audio data needs to be queued for mixing/output. Checks current capacity, grows buffer via realloc if needed, copies data via aligned memcpy, and updates stack pointer.

## Call Tree

```
FUN_005648d0 — Audio Stack Push with Overflow Realloc  [trigger: audio data enqueue]
  +-- FUN_00564930 — Accumulator with Realloc on Growth  [checks capacity, reallocs if needed]
  |     +-- FUN_0058b5d4 — memory reallocation wrapper
  +-- FUN_005648b0 — Linear Interpolation  [size calculation / interpolation]
  +-- FUN_0058b130 — Memory Resize/Realloc  [heap reallocation for buffer growth]
  +-- FUN_00564960 — Aligned Memory Copy from Struct Buffer  [copies data to stack]
  |     +-- FUN_005648b0 — Linear Interpolation
```

## Key Actions

1. Checks if current buffer has capacity for new data
2. If overflow: calls FUN_00564930 which uses FUN_0058b5d4 to realloc buffer to larger size
3. Computes copy size via linear interpolation (FUN_005648b0)
4. Performs aligned memory copy of source data to stack buffer (FUN_00564960)
5. Updates stack pointer / buffer position after copy

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Audio data ptr | Capacity check | Grow or skip |
| Buffer (if full) | Realloc via FUN_0058b5d4 | Larger buffer |
| Source data | Aligned memcpy (FUN_00564960) | Data on stack |
| Stack position | Increment | Updated pointer |

## Notes

- 4 direct callees, 2 with sub-callees (depth 2)
- Buffer growth uses realloc wrapper (FUN_0058b5d4) from docs/06 range
- FUN_005648b0 (linear interpolation) is shared between size calculation and memcpy
- Stack-based buffer management pattern typical for audio mixing pipelines
- Called by 3 callers (callers.json): likely multiple audio sources push to this stack
