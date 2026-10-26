## ViewportRectangleRenderSetup_0048e750 — ViewportBoundsProjectionSetup

**Summary:** Reads rectangle bounds from struct fields, optionally computes scaled viewport offsets for HUD/shading using screen scale globals, updates camera projection, and writes computed rectangle to output parameters. Guarded by a child state field check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | rectangle left/x coordinate |
| this | 0x8 | R | — | rectangle right coordinate |
| this | 0xC | R | — | rectangle top/y coordinate |
| this | 0x10 | R | — | rectangle bottom coordinate |
| this | 0x40 | R | — | pointer to child object |
| this | 0x78 | R | — | state mode / type, checked against 2 |
| this | 0xE8 | R | — | flag enabling viewport offset computation |
| this | 0xEC | R | — | flag enabling viewport offset computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a68e8 | flt_5A68E8 | R | ScreenScaleFactors [DERIVED] (also: ` — screen scaling factors) |
| 005a68ec | flt_5A68EC | R | AudioMixConstant_5A68EC [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9f00 | ConditionalInit | initialize state tracking |
| 004f9f30 | ConditionalStateReset | reset state tracking |
| 00541b70 | CameraProjectionUpdate | update camera projection matrix |
| 00542200 | sub_542200 | set viewport rectangle / projection parameters |
| 00546200 | ArithmeticComparison_6200 | compare arithmetic values for rendering |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x78 | == | 2 | state mode flag |

**Guard interpretation:** 
- Outer guard (0x78): if this[30] field at offset 0x78 == 2 → PASS (compute viewport); if not 2 → BLOCKED (skip all, return 0)
- Inner guard (0xE8/0xEC): if this[58] non-zero AND this[59] non-zero → PASS (compute scaled viewport offsets); if either zero → BLOCKED (skip viewport computation, still write raw rectangle to outputs)
