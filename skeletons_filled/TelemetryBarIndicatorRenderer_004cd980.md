## TelemetryBarIndicatorRenderer_004cd980 — TelemetryBarIndicatorRender

**Summary:** Renders bar indicator particles with dual fade values computed from lifetime progress. Checks particle lifetime window and writes pixel attributes if within range; removes particles outside the window via ArrayElementRemoval.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | scale factor for fade value computation |
| this | 0x64 | R | — | particle count (this[25]) |
| this | 0x68 | R | — | particle array pointer (this[26]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acec4 | flt_5ACEC4 | R | Flt_TrackSegmentFade_SCEC4 [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | delegate to scoring system method |
| 004cb5a0 | ArrayElementRemoval | remove particle outside lifetime window |
| 00558dc0 | PixelAttributeWriteToTexture | write pixel attribute (color/fade) to texture buffer |

**Guard conditions:** For each particle: checks if current time (v9) is within particle lifetime window [v4[2], v4[3]] AND either fade value (v5 or v6) is non-zero. PASSES: render with computed fade attributes. BLOCKED (outside window or both fades zero): remove particle via ArrayElementRemoval.
