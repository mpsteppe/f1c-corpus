## ColorMatrixTransformWithBlend_0050e9e6 — Color component transform with conditional blending

**Summary:** Processes three color components `a1` through a matrix-like transform, calling thunks conditionally based on flags `a4`/`a5`/`a6`. Optionally blends result with values from a palette/blend structure `a3` (per-channel offset and scale).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Color component 0 (e.g. Hue/R — read before blend, written with blended result) |
| this | 0x4 | RW | — | Color component 1 (e.g. Saturation/G — read before blend, written with blended result) |
| this | 0x8 | RW | — | Color component 2 (e.g. Value/B — read before blend, written with blended result) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call (possibly modified by blend) — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0050eb53 | jpt_50EA25 | R | Jump table for the flag-based switch dispatch |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c5bd | ThunkToThunkFUN0050c5b0 | Always-called transform thunk (applies color matrix operation) |
| 0050cbb0 | ThunkToFUN0050cba3 | Conditionally-called transform thunk (flag-dependent color processing) |

**Guard conditions:** Switch on bitmask `(a4!=0) | (2*(a5!=0)) | (4*(a6!=0))`: cases 3,5,6 call one ThunkToFUN0050cba3; case 7 calls two. Default cases skip all thunks. ThunkToThunkFUN0050c5b0 is always called regardless of flags. If `a3` is non-null, each output component is blended with the corresponding offset/scale from the `a3` structure.
