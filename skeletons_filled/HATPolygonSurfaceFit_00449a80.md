## HATPolygonSurfaceFit_00449a80 — QuadraticSurfaceFit

**Summary:** Solves a quadratic surface fit to a set of 6 input points using Gaussian elimination, storing 6 coefficients representing the fitted quadratic form. Part of the collision/physics geometry system, used by spatial hash, capsule shape, and Bezier tessellation pipelines.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpatialHashKeyGeneration (00449ed0), IndexedVertexLookupFromStream (00449f60), CollisionCapsuleShapeCopyToPipeline (0044b040), BezierPatchTessellation (0044b370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | coeffA_lo — low DWORD of quadratic coefficient A |
| this | 0x4 | RW | 0 | coeffA_hi — high DWORD of quadratic coefficient A |
| this | 0x8 | RW | 0 | coeffB_lo — low DWORD of coefficient B |
| this | 0xC | RW | 0 | coeffB_hi — high DWORD of coefficient B |
| this | 0x10 | RW | 0 | coeffC_lo — low DWORD of coefficient C |
| this | 0x14 | RW | 0 | coeffC_hi — high DWORD of coefficient C |
| this | 0x18 | RW | — | coeffD_lo — low DWORD of coefficient D |
| this | 0x1C | RW | — | coeffD_hi — high DWORD of coefficient D |
| this | 0x20 | RW | — | coeffE_lo — low DWORD of coefficient E |
| this | 0x24 | RW | — | coeffE_hi — high DWORD of coefficient E |
| this | 0x28 | RW | — | coeffF_lo — low DWORD of coefficient F |
| this | 0x2C | RW | — | coeffF_hi — high DWORD of coefficient F |
| this | 0x30 | RW | — | fallbackCoeff_0 — first fallback coefficient (3-point fit) |
| this | 0x34 | RW | — | fallbackCoeff_1 — second fallback coefficient |
| this | 0x38 | RW | — | fallbackCoeff_2 — third fallback coefficient |
| this | 0x3C | RW | — | fallbackCoeff_3 — fourth fallback coefficient |
| this | 0x40 | RW | — | fallbackCoeff_4 — fifth fallback coefficient |
| this | 0x44 | RW | — | fallbackCoeff_5 — sixth fallback coefficient |
| this | 0x48 | RW | — | fallbackCoeff_6 — seventh fallback coefficient |
| this | 0x4C | RW | — | fallbackCoeff_7 — eighth fallback coefficient |
| this | 0x50 | RW | — | fallbackCoeff_8 — ninth fallback coefficient |
| this | 0x54 | RW | — | spatialIndex — scoring-grid index from IndexedArrayAccess |
| this | 0x58 | RW | — | surfaceTypeFlag — byte flag copied from input point data |
| this | 0xB8 | R | — | gridOffset — scoring-grid base offset for coefficient adjustment |

**Written-by note (persistence):**
- this 0x0: recalc every call — external poke does NOT persist
- this 0x4: recalc every call — external poke does NOT persist
- this 0x8: recalc every call — external poke does NOT persist
- this 0xC: recalc every call — external poke does NOT persist
- this 0x10: recalc every call — external poke does NOT persist
- this 0x14: recalc every call — external poke does NOT persist
- this 0x18: recalc every call — external poke does NOT persist
- this 0x1C: recalc every call — external poke does NOT persist
- this 0x20: recalc every call — external poke does NOT persist
- this 0x24: recalc every call — external poke does NOT persist
- this 0x28: recalc every call — external poke does NOT persist
- this 0x2C: recalc every call — external poke does NOT persist
- this 0x30: recalc every call — external poke does NOT persist
- this 0x34: recalc every call — external poke does NOT persist
- this 0x38: recalc every call — external poke does NOT persist
- this 0x3C: recalc every call — external poke does NOT persist
- this 0x40: recalc every call — external poke does NOT persist
- this 0x44: recalc every call — external poke does NOT persist
- this 0x48: recalc every call — external poke does NOT persist
- this 0x4C: recalc every call — external poke does NOT persist
- this 0x50: recalc every call — external poke does NOT persist
- this 0x54: recalc every call — external poke does NOT persist
- this 0x58: recalc every call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 005c43d4 | aGaussianElimin_0 | R | String_GaussianElimination [DERIVED] |
| 005c4404 | aGaussianElimin | R | GaussianEliminationString [DERIVED] |
| 005c4434 | aDDevF119992002_0 | R | DDevF119992002String [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ce8d0 | IndexedArrayAccess | looks up an element from an indexed array using a 16-bit index |
| 004d7a50 | StringSplitLoop | string-split / token parsing loop used for debug conditional logging |
| 004d7aa0 | DebugLogWrite | writes a formatted string to the debug log buffer |
| 005677b0 | sub_5677B0 | Gaussian elimination solver for NxN linear system |

**Guard conditions:** The function has two main decision points: (1) After solving the 6x6 system, validates the result by checking if the surface evaluated at 3 reference points differs from expected by more than 0.001 — if so, retries with a reduced 3-point fit via a second Gaussian elimination call (line 231). (2) If the 3-point solve also fails, zeros most coefficients and falls through. (3) If input parameter `a3` is non-zero (line 252) and spatialIndex is valid, adjusts coefficient D by subtracting a grid-based offset — this is an optional post-fit correction step.

(End of file - total 85 lines)
