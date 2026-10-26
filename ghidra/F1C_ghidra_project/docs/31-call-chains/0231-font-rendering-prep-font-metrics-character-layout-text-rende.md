# Chain: Font Rendering Prep — Font metrics, character layout, text rendering dispatch

Seed: FUN_00411840  |  System: docs/19-renderer.md  |  Depth: 6  |  Functions: ~20+

---

## Overview

FUN_00411840 prepares text formatting and rendering. Called per-frame for on-screen text (HUD, overlays), it gets font metrics, initializes static render state, maps character codes to glyph positions, and dispatches character rendering. The chain includes character code mapping (FUN_00411b50), event message formatting (FUN_00411bf0), character render dispatch (FUN_00411db0), and sound event dispatching (FUN_00411e90). The most complex subtrees are the event message dispatcher and the character render dispatcher.

## Call Tree

```
FUN_00411840 — Font Rendering Prep  [trigger: per-frame HUD/text rendering]
  +-- FUN_004119d0 — Short Computation (Range Check)  [leaf]
  +-- FUN_00411a00 — Short Computation / Two-Table Lookup by ID  [sub: 1]
  +-- FUN_00411a50 — Short computation  [leaf]
  +-- FUN_00411b50 — Character Code Mapper  [sub: 1]
  +-- FUN_00411bf0 — Race Event Message Dispatcher  [6 callees]
  |     +-- FUN_004122c0 — Session String/Name Lookup  [sub: 4]
  |     +-- FUN_00412490 — Game Control Mapping  [sub: 1]
  |     +-- FUN_00412e50 — DirectInput Scancode Mapping  [sub: 1]
  |     +-- FUN_004133b0 — Text Attribute Lookup (Format 0)  [sub: 2]
  |     +-- FUN_00413710 — Text Attribute Lookup (Format 3)  [sub: 2]
  |     +-- [1 additional callee omitted]
  +-- FUN_00414140 — Decrement Counter with Floor at Zero  [leaf]
  +-- FUN_00411db0 — Font Character Render Dispatcher  [5 callees]
  |     +-- FUN_00412490 — Game Control Mapping  [sub: 1]
  |     +-- FUN_00414010 — Enum Value Translation (Resource IDs)  [sub: 1]
  |     +-- FUN_00414140 — Decrement Counter  [leaf]
  |     +-- FUN_00414160 — Global Value Selector  [leaf]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
  +-- FUN_00411e90 — Sound Event Dispatcher  [11 callees]
  |     +-- FUN_00413600 — Text Attribute Lookup (Format 2)  [sub: 2]
  |     +-- FUN_00413710 — Text Attribute Lookup (Format 3)  [sub: 2]
  |     +-- FUN_004122c0 — Session String/Name Lookup  [sub: 4]
  |     +-- FUN_00412490 — Game Control Mapping  [sub: 1]
  |     +-- FUN_00412e50 — DirectInput Scancode Mapping  [sub: 1]
  |     +-- [6 additional callees omitted]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
  +-- FUN_00587b3e — Boolean-to-Int Conversion  [sub: 1]
```

## Step-by-Step Trace

### Level 0: FUN_00411840 — Font Rendering Prep

**Called by:** FUN_004186f0 (overlay text render)
**Purpose:** Prepares text formatting and rendering — gets font metrics, initializes render state, maps characters, dispatches rendering.

**Key actions:**
1. Gets font metrics via FUN_004119d0/FUN_00411a00/FUN_00411a50
2. Initializes static state on first call (sets DAT_005ea5e0 bit 0)
3. Maps character codes to render positions via FUN_00411b50
4. Renders each character via FUN_00414140
5. Returns number of rendered chars

**Globals:** DAT_005ea5e0, DAT_005ea5d0, _DAT_005ea5d4, _DAT_005ea5d8, _DAT_005ea5dc

### Level 1: FUN_00411bf0 — Race Event Message Dispatcher

**Called by:** FUN_00411840 (message format/text lookup)
**Purpose:** Formats race event messages (session strings, control mappings, text attributes).

### Level 1: FUN_00411db0 — Font Character Render Dispatcher

**Called by:** FUN_00411840 (character rendering)
**Purpose:** Dispatches character rendering by type: image (0x2693), fill (0x2694), or glyph lookup.

### Level 1: FUN_00411e90 — Sound Event Dispatcher

**Called by:** FUN_00411840 (sound events tied to text)
**Purpose:** Dispatches sound events associated with text/UI elements. 11 callees spanning text attribute lookups, session strings, and control mappings.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00411840 | Text string, font handle | Font metrics + char mapping + render dispatch | Rendered characters, rendered count |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ea5e0 | Font render state | FUN_00411840 | Bit 0 = initialized flag |

## Notes

- Cross-system: FUN_00411e90 (Sound Event Dispatcher) goes to docs/21-audio-network-internals.
- FUN_004122c0 (Session String/Name Lookup) goes to docs/02-ai-system.
- The chain has significant overlap — FUN_00412490, FUN_004122c0, FUN_00413710 are reused by multiple dispatchers.

---
