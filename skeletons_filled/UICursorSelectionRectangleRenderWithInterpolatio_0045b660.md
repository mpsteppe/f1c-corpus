## UICursorSelectionRectangleRenderWithInterpolatio_0045b660 — SelectionRectangleRenderWithInterpolation

**Summary:** Renders UI cursor selection rectangle with smooth interpolation. Computes target size from active physics channel count and max coordinate, interpolates current rectangle bounds toward targets with 0.4 blend factor (clamped at 0.001 threshold), then renders 4 rectangle edges via DirectX device. Resets interpolation state when inactive.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionDamageDecayProcessor (0045b840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x324 | RW | — | interpolated rectangle dimension/position X (smoothed toward target each frame) |
| this | 0x328 | RW | — | interpolated rectangle dimension/position Y (smoothed toward target each frame) |

**Written-by note (persistence):**
- this 0x324: overwritten every frame with interpolation. External poke survives one frame if difference > threshold.
- this 0x328: overwritten every frame with interpolation. External poke survives one frame if difference > threshold.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059f078 | flt_59F078 | R | PenaltyScaleFactor [DERIVED] |
| 0059f088 | dbl_59F088 | R | ThresholdFloat [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] — DirectX render device pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b5c0 | sub_45B5C0 | compute max normalized coordinate value across active physics channels |
| 0045bb00 | FloatArrayThresholdSearch | return count of active channels |
| 00494c20 | FloatVectorWithConditionalTransform | draw rectangle edge (4 calls for 4 sides) using render device |
| 004dcd60 | ConditionalCall | execute conditional render operation |
| 004dcda0 | FloatToIntConversionDispatch | convert float rectangle bounds to integer pixel coordinates for rendering |
| 004dcee0 | sub_4DCEE0 | set render state with alpha/color parameters (0.5, 0.0, 1.0, 2) |
| 004dcf30 | TwinFieldGetter_cf30 | retrieve two render position/size values (width, height) |
| 004dcf50 | TripleFieldGetter | retrieve three render position/size values (x, y, z) |

**Guard conditions:** If FloatArrayThresholdSearch returns 0 AND this[0x328] (field 202) == 0.0 → set this[0x324] = 0.0 and skip all rendering. Otherwise → compute target rectangle dimensions from channel data, interpolate both fields with 0.4 blend factor (snap if difference < 0.001), convert to ints, and render 4 rectangle edges.
