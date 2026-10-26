## F_2DRectangleDrawingWithOutline_00475d90 — CollisionDebugRectangleDraw

**Summary:** Draws a 2D debug rectangle outline and renders collision parameter visualization inside: draws rectangle border, syncs collision config, then draws a center gauge line or horizontal red bars representing the selected collision parameter value (contact stiffness, collision arrays).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x118 | R | — | Collision parameter selector: 0=center+gauge, 1=flt_7CD45C, 2=flt_7CD2B0, 3=flt_7CD610, 4+=nothing |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 007cd2b0 | flt_7CD2B0 | R | CollisionParamArrayA [DERIVED] — collision parameter set A for visualization |
| 007cd458 | flt_7CD458 | R | ContactStiffnessArray [DERIVED] — contact stiffness for gauge offset |
| 007cd45c | flt_7CD45C | R | CollisionParamArray [DERIVED] — collision parameter for visualization |
| 007cd610 | flt_7CD610 | R | CollisionParamArray3 [DERIVED] — collision parameter set 3 for visualization |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] — debug render enable flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00475d30 | CollisionConfigurationSync | Syncs collision config before reading params for visualization |
| 00487160 | UtilityFunction_7160 | Gets screen rectangle coordinates for debug overlay |
| 00494c20 | FloatVectorWithConditionalTransform | Draws a colored line between two 2D points |
| 00495150 | GlobalAccessor_5150 | Checks if debug rendering is enabled |
| 00587bdc | CRTFtol | Converts double to int (C runtime _ftol) |

**Guard conditions:** Early return (line 23-24) BLOCKED if UtilityFunction_7160 fails for either point 0 or point 1. Additional early returns at lines 96 and 98 if gauge bounds are invalid (v12 < v11 or v13 >= v21). Collision parameter switch uses this[0x118]: value 0 draws center line+gauge; values 1-3 select collision parameter arrays; value 4+ BLOCKED (v17 = 0.0).