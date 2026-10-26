## CameraViewportRenderSetup_004fbd70 — CameraViewportRenderSetup

**Summary:** Sets up camera viewports for rendering: detects session type changes, adjusts camera position per viewport, manages render-state fade transitions, computes per-object alpha blending from gradient ranges, and updates pit-crew animation offsets for both primary and secondary viewport layers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderScreenSave (004b40a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | primary viewport enable flag (0 = disabled, non-zero = active) |
| this | 0x4 | R | — | primary viewport position X (world coordinate) |
| this | 0x8 | R | — | primary viewport position Y (world coordinate) |
| this | 0xC | R | — | primary viewport position Z (world coordinate) |
| this | 0x18 | R | — | sub-viewport 0 position X (float, 16-byte stride entries) |
| this | 0x1C | R | — | sub-viewport 0 position Y / parameter (float) |
| this | 0x44 | RW | 18446744073709551615 | cached session type ID (compared against dword_7C56A4; reset to -1 on mismatch) |
| this | 0x48 | R | — | primary viewport count (number of viewports to process) |
| this | 0x70 | R | — | primary pit crew animation object handle (offset 28 dwords) |
| this | 0x74 | R | — | primary pit crew offset X (float) |
| this | 0x78 | R | — | primary pit crew offset Y (float) |
| this | 0x7C | R | — | secondary viewport count (second pass viewport layer) |
| this | 0xA4 | R | — | secondary pit crew animation object handle (offset 41 dwords) |
| this | 0xA8 | R | — | secondary pit crew offset X (float) |
| this | 0xAC | R | — | secondary pit crew offset Y (float) |
| this | 0xB0 | R | — | alpha blend gradient range minimum (start of fade) |
| this | 0xB4 | R | — | alpha blend gradient range maximum (end of fade) |
| this | 0xB8 | RW | — | cached render-state fade flag (updated when flt_8AFEC8 changes) |

**Written-by note (persistence):**
- this 0x44: written on session type change — external poke persists between render frames
- this 0xB8: written on render-state change — external poke persists between render frames

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007cf938 | byte_7CF938 | R | RenderClearFlag [DERIVED] |
| 007cf950 | flt_7CF950 | R | Unknown_Float_Camera [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afec8 | flt_8AFEC8 | R | RenderStateChangeFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c910 | ShortComputation_c910 | reference / initialize session manager for camera setup |
| 004fc550 | sub_4FC550 | handle session type change (cleanup and reinit camera context) |
| 00542460 | TripleFieldGetter_2460 | fetch three floating-point fields (camera target position X/Y/Z) |
| 0054b3b0 | ThreeFieldSetterWithSubCall | set camera position with three parameters and invoke sub-call |
| 0054b3f0 | OffsetDispatch | dispatch position offset / transform update to render pipeline |
| 0054bf60 | PitCrewAnimationOffsetUpdate | update pit crew animation position offset for given handle |
| 0054c030 | FlagFieldBitManipulation | set or clear rendering flags (alpha blend enable/disable) |
| 0054c230 | LinkedListIndexedAccessor_c230 | access linked list of renderable objects by index |
| 0054e100 | PackedArrayTotalSize | get total count of renderable objects in packed array |
| 0054e120 | PackedArrayIndexLookup | retrieve renderable object by index from packed array |
| 00587bdc | CRTFtol | convert floating-point alpha (0.0–1.0) to byte value (0–254) |

**Guard conditions:** no fixed field-vs-literal early-return guards — function uses dynamic state checks (session type match, render state change flag, viewport enable flags, non-zero position fields) to control processing branches.
