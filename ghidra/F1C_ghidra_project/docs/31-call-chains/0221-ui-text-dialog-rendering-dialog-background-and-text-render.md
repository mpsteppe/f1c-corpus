# Chain: UI Text/Dialog Rendering — Dialog Background and Text Render

Seed: 0x00495bd0  |  System: docs/19-renderer.md  |  Depth: 1  |  Functions: 9

---

## Overview

UI framework rendering callback — draws dialog boxes with colored background rectangles and text strings. Acquires font/surface, measures text dimensions (capped at 800x600), renders dark/light background, then renders text. All 9 callees are leaf UI helpers.

## Call Tree

```
0x00495bd0 — UI Text/Dialog Rendering  [trigger: UI framework callback, 0 callers]
  +-- 0x00495150 — font/surface getter
  +-- 0x00498550 — [undocumented UI helper]
  +-- 0x00499a50 — [undocumented UI helper]
  +-- 0x0049a2b0 — [undocumented UI helper]
  +-- 0x004983b0 — [undocumented UI helper]
  +-- 0x00494bf0 — text string render
  +-- 0x00494f10 — text string render
  +-- 0x00490920 — [undocumented UI helper]
  +-- 0x004918d0 — [undocumented UI helper]
```

## Step-by-Step Trace

### Level 0: 0x00495bd0 — UI Text/Dialog Rendering

**Trigger:** UI framework callback (0 callers in graph — vtable dispatch)
**Called by:** None recorded — likely called via UI framework function pointer
**Purpose:** Renders dialog with background and text

**Key actions:**
1. Gets font/surface via 0x00495150
2. Iterates 4 times collecting text measurements (width/height/advance)
3. Caps text width at 800px, height at 600px
4. Renders background rectangles: dark (0xaaff4444), light (0x222222)
5. Renders text strings via 0x00494bf0 and 0x00494f10

**Data passed to callees:** surface handle, position coordinates, color values, text strings

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x00495150 | — | Get font/surface | surface handle |
| 0x00495bd0 | text strings | Measure dimensions | width/height capped at 800x600 |
| 0x00495bd0 | 0xaaff4444, 0x222222 | Fill rects | background rendered |
| 0x00494bf0/0x00494f10 | text, position | Draw text | text rendered |

## Globals Written in This Chain

None — pure rendering, no state mutation

## Notes

- 0 callers in callers.json — called via UI framework vtable/function pointer
- All 9 callees are leaf UI helper functions
- Width/height caps (800, 600) are hardcoded rendering limits
---
