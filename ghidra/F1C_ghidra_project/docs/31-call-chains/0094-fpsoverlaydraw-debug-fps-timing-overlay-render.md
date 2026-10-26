# Chain: FPSOverlayDraw — Debug FPS/Timing Overlay Render

Seed: FUN_00495440  |  System: docs/18-physics-dynamics.md  |  Depth: 1-2  |  Functions: 7 callees

---

## Overview

Renders FPS/timing overlay when toggled via key (scancode 0x1021). Scans key array at +0x159c, toggles bool at +0xe0, accumulates frame timer from high-res counter, formats string, blits to screen with background rect.

## Call Tree

```
FUN_00495440 — FPSOverlayDraw  [trigger: per-frame, draws if toggled on]
  +-- FUN_00498730 — High-resolution timer query                     [leaf]
  +-- FUN_0058815f — sprintf string formatting                       [depth 1: HAS 0 callees]
  +-- FUN_004983b0 — Texture dimension query                         [leaf]
  +-- FUN_00498560 — Texture select/bind                             [depth 1: HAS 0 callees]
  +-- FUN_004981f0 — Blit/bitblt to screen                           [leaf]
  +-- FUN_00490920 — Clear rectangle                                 [depth 1: HAS 0 callees]
  +-- FUN_004918d0 — Render textured quad (text display)             [depth 1: HAS 0 callees]
```

## Step-by-Step Trace

### Level 0: FUN_00495440 — FPSOverlayDraw

**Trigger:** Per-frame HUD draw call. Only renders when FPS overlay is toggled on.
**Called by:** Unknown (callers.json shows no callers — likely called from OnScreen::Post or HUD chain)
**Purpose:** Draw FPS counter overlay text.

**Key actions:**
1. Scan array at +0x159c for value 0x1021 (FPS toggle key scancode)
2. If found: toggle bool at +0xe0
   - If turning on: reset accumulator at +0xe4/+0xe8/+0xec
3. When active:
   - Increment frame counter at +0xe8
   - Accumulate time delta from FUN_00498730 (high-res timer)
   - When accumulator > _DAT_0059e450 threshold:
     - Convert to int frame count
     - Reset accumulators
4. If frame count >= 0:
   - Format string via FUN_0058815f (sprintf) with format DAT_005c3280
   - Blit to screen via FUN_004981f0
   - Clear rect via FUN_00490920
   - Render text via FUN_004918d0

**Data passed to callees:** overlay struct pointer, framebuffer/screen handles.

### Level 1: Callees

- **FUN_00498730** — QPC-based high-res timer, returns elapsed microseconds.
- **FUN_0058815f** — sprintf wrapper for string formatting.
- **FUN_004983b0** — Queries texture dimensions for blit sizing.
- **FUN_00498560** — Selects/binds render texture.
- **FUN_004981f0** — Bitblt operation to copy overlay to framebuffer.
- **FUN_00490920** — Clear rectangle (background behind text).
- **FUN_004918d0** — Render textured quad (text character rendering).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00495440 | overlay ptr | key check, accum | FPS string rendered |
| FUN_00498730 | none | QPC read | time delta |
| FUN_0058815f | format, count | sprintf | string buffer |
| FUN_004981f0 | string buffer | blit | screen pixels |
| FUN_00490920 | rect | clear | background |
| FUN_004918d0 | texture quad | render | visible text |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| _DAT_0059e450 | FPSAccumThreshold | FUN_00495440 (read) | FPS update interval |

## Notes

All callees are leaf or depth-1. This is a debug overlay utility — hardcoded, not moddable. Key toggle pattern via scancode array scan.

---
