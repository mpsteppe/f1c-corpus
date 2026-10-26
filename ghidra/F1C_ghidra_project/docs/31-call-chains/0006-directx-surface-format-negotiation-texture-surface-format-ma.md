# Chain: DirectX Surface Format Negotiation — Texture/Surface Format Match

Seed: FUN_00502a15  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 12

---

## Overview

Triggered during texture/surface creation when source and destination formats differ. Compares surface pixel formats, attempts format conversion through a chain of specialized converters (FUN_005029e5, FUN_00501722, FUN_00501992), falls back through alternative paths (FUN_0050210e, FUN_005026a4, FUN_00501e39), and resolves ambiguous formats via FUN_00500fca. Cleans up intermediate surfaces and handles format-specific edge cases. DirectX rendering pipeline utility — no game globals used.

## Call Tree

```
FUN_00502a15 — DirectX Surface Format Negotiation  [trigger: source != dest surface format]
  +-- FUN_005029e5 — [undocumented D3D format converter 1]
  +-- FUN_00501722 — [undocumented D3D format converter 2]
  +-- FUN_00501992 — [undocumented D3D format converter 3]
  +-- FUN_0050210e — [undocumented D3D fallback converter 1]
  +-- FUN_005026a4 — [undocumented D3D fallback converter 2]
  +-- FUN_00501e39 — [undocumented D3D fallback converter 3]
  +-- FUN_00500fca — [undocumented D3D format resolver]
  +-- FUN_00587bcf — Heap Free  [cleanup intermediate surfaces]
  +-- FUN_00500fae — [undocumented D3D edge case handler]
  +-- FUN_005006a4 — [undocumented D3D edge case handler]
```

## Step-by-Step Trace

### Level 0: FUN_00502a15 — DirectX Surface Format Negotiation

**Trigger:** Called during renderer surface/texture creation when format mismatch detected.
**Called by:** 2 callers (from callers.json) — D3D texture/surface creation code.
**Purpose:** Negotiate D3D surface format between source and destination.

**Key actions:**
1. Compares source and destination surface formats
2. If formats differ, tries conversion via FUN_005029e5, FUN_00501722, FUN_00501992
3. Falls back through secondary chain: FUN_0050210e, FUN_005026a4, FUN_00501e39
4. Calls FUN_00500fca for final format resolution
5. Cleans up intermediate surfaces via FUN_00587bcf (operator delete)
6. Edge cases: FUN_00500fae, FUN_005006a4 for format-specific paths

**Data passed to callees:** D3D surface handles, format DWORDs, surface data pointers

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00502a15 | src_format, dst_format | Compare | Format match? |
| FUN_005029e5 | src surface | Conversion attempt | Converted surface or null |
| FUN_00501722 | src surface | Alternative conversion | Converted surface or null |
| FUN_00500fca | ambiguous format | Resolution | Final format |
| FUN_00587bcf | intermediate surface | Free | Memory released |

## Globals Written in This Chain

None — pure DirectX pipeline utility, no game globals.

## Notes

- Pure renderer utility — no game logic or globals touched
- Fallback chain suggests D3D surface format compatibility matrix
- FUN_00587bcf (operator delete) is the only runtime library call

---

---
