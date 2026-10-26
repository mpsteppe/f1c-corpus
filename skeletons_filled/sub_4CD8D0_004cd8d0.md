## sub_4CD8D0_004cd8d0 — ParticleColorFadeRenderer

**Summary:** Renders particles with computed color fade based on input parameter a2. When a2 > 0, computes a color value and writes pixel attributes to texture for each particle. When a2 == 0, falls back to sub_4CB5E0. Optionally triggers AI waypoint path checker rendering when particles are absent.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StridedArraySearchAndCall (004cefe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | waypoint path checker trigger flag (this[22]) |
| this | 0x64 | R | — | particle count (this[25]) |
| this | 0x68 | R | — | particle array pointer (this[26]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004024f0 | AIWaypointPathCheckerRenderer | render AI waypoint path checker visualization |
| 004cb5e0 | sub_4CB5E0 | alternate fallback renderer for zero-fade case |
| 00558dc0 | PixelAttributeWriteToTexture | write pixel attribute (color/fade) to texture buffer |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x58 | > | 0 | waypoint check trigger count |

**Guard interpretation:** Outer guard: a2 * 254 > 0. PASSES: computes fade color and renders particles; also triggers AIWaypointPathCheckerRenderer if this[22] > 0 and this[25] == 0. BLOCKED (a2 * 254 == 0): calls sub_4CB5E0 fallback if particles exist.
