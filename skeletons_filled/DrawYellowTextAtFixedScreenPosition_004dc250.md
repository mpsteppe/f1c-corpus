## DrawYellowTextAtFixedScreenPosition_004dc250 — Render yellow text at fixed screen position

**Summary:** Renders a yellow-colored text string at fixed screen coordinates (880, 140) by setting the color field at offset +72 of a context object to yellow (16776960), then calling sub_49F1C0 with the race session state and render device.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049f1c0 | sub_49F1C0 | Render text at screen coordinates with specified color and device context |
| 004d7fa0 | SwitchBasedGlobalLookup | Retrieve context/global object pointer via switch-case lookup (key=0) |

**Guard conditions:** Checks return of `SwitchBasedGlobalLookup(0)` for non-null. PASSES (renders text) when pointer is non-null. BLOCKED (skips) when null — early return without rendering.
