## PressureForceFieldMapping_004313c0 — TireContactPatchPressureMapper

**Summary:** Maps tire contact patch pressure forces to surface grid cells. Reads tire geometry parameters, computes blending factor from surface contact parameter, then finds best-matching pressure value for each session-state entry.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsStateInitIndexed (00431390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1640 | R | — | Count of session-state entries |
| this | 0x1644 | RW | 0 | Current/selected entry index, set during search loop |
| this | 0x1648 | R | — | Initial index value copied from adjacent field |
| this | 0x16C0 | R | — | Count of sub-entries within an entry |
| this | 0x16C4 | RW | 0 | Per-element data (64-byte stride array), index written |
| this | 0x16C8 | R | — | Element field value copied into 0x16C4 |
| this | 0x16CC | R | — | Flag byte checked for conditional pass-through |
| this | 0x1CA8 | R | — | Tire geometry offset parameter (float) |
| this | 0x1CAC | R | — | Tire contact position parameter (float) |
| this | 0x1CB0 | R | — | Tire width/contact-area parameter (float) |
| this | 0x1CB4 | R | — | Surface contact blend parameter (float, compared with 0.5) |

**Written-by note (persistence):**
- this 0x1644: set multiple times per call during search; final selected index stored at line 133. External poke survives until next call overwrites.
- this 0x16C4: set once per element in loop; final result stored. External poke survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e290 | PositionIndexClamp | Clamps computed position indices to valid grid range |
| 0042ed00 | SessionStateIndexedLookup | Looks up session state value for a given index |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1640 | > | 0 | Entry count for outer search loop |
| this | 0x16C0 | > | 0 | Sub-entry count for inner nearest-match loop |

**Guard interpretation:** 0x1640 > 0 allows the outer loop (lines 97-131) to search for best matching entry index across session states. When <= 0, search is bypassed and initial index value is used. 0x16C0 > 0 allows the inner loop (lines 143-157) to find the closest matching sub-entry by absolute difference; when <= 0, result defaults to 0.
