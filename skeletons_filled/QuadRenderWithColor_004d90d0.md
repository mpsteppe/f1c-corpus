## QuadRenderWithColor_004d90d0 — HUD quad render with position offset

**Summary:** Renders a full-screen-width textured quad (1280×50 scaled) at a vertical position determined by participant slot (this[8]==-1 → y=0, else y=140). Uses sub_553650 to set 4 vertices with UV coordinates. Skips render when color/alpha parameter a2 is zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8A30 (004d8a30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Participant slot/row selector: -1 = top position (y=0), else = lower position (y=140 scaled) |
| this | 0xE4 | R | — | Normalized screen width — scales quad width and X position |
| this | 0xE8 | R | — | Normalized screen height — scales quad height and Y position |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e828 | flt_59E828 | R | FloatOneConstant [DERIVED] (also: ` — float 1.0 constant) |
| 005acf40 | flt_5ACF40 | R | UIQuadDrawMultiplier [DERIVED] |
| 005acf44 | flt_5ACF44 | R | Render_QuadScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553650 | sub_553650 | Sets up one quad vertex with position (scaled x,y) and UV coordinates (u,v); called 4 times per quad |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 18446744073709551615 | Participant slot = -1 → y-offset 0; else → y-offset 140 |

**Guard interpretation:** `a2 == 0.0` → entire quad render BLOCKED (no vertices drawn). `a2 != 0.0` → PASSES to render. `this[8] == -1` → Y base position = 0 (top row). `this[8] != -1` → Y base position = 140 scaled (lower row for active participant).
