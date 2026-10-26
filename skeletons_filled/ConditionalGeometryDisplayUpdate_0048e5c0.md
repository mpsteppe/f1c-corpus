## ConditionalGeometryDisplayUpdate_0048e5c0 — ConditionalGeometryDisplayUpdate

**Summary:** Calls a virtual method at vtable+160 (0xA0) to check if a video resource needs reloading. If reload is not needed (returns 0), copies the source rectangle (this[58]-this[61]) from the render surface via Accessor/RenderSurfaceFillCopy to update the display.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA0 | R | — | Vtable offset 160 — reload-needed check method |
| this | 0x0 | R | — | Vtable pointer |
| this | 0xE8 | R | — | Source rectangle X (this[58]) |
| this | 0xEC | R | — | Source rectangle Y (this[59]) |
| this | 0xF0 | R | — | Source rectangle width (this[60]) |
| this | 0xF4 | R | — | Source rectangle height (this[61]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Get render surface/context |
| 004918d0 | RenderSurfaceFillCopy | Copy rendered surface region to display |

**Guard conditions:** PASS: vtable+160 returns 0 (no reload needed) → copy render surface region to display. BLOCKED: vtable+160 returns non-zero (reload needed) → skip copy, return the reload-needed value.
