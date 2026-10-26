## AudioPhysicsMixWithLerp_0040e2b0 — AudioPhysicsMixWithLerp

**Summary:** Computes averaged vertex position from packed array, lerps with bounding box center using blend factor (0.35 for mode 2, 0.70 otherwise), then applies triple-field offset and updates global vector. Part of audio-physics scene graph integration.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ShortComputation_e770 (0040e770), ConditionalAudioParamSetup (004dfa60)

**Struct fields accessed:**
*(none directly on this)*

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e458 | flt_59E458 | R | ConstraintForceEpsilon [DERIVED] (also: ` — constraint force threshold (near-zero) |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e1f0 | GlobalVectorOffsetUpdate | Applies computed offset vector to scene graph vertices |
| 004dd550 | BoundingBoxComputation | Computes bounding box from vertex array |
| 0054b3b0 | ThreeFieldSetterWithSubCall | Sets three fields (X/Y/Z offset) with internal sub-call |
| 0054b420 | TripleFieldQuery | Queries three current field values (X/Y/Z offset) |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses linked list node by index |
| 0054e100 | PackedArrayTotalSize | Returns total element count in packed array |
| 0054e120 | PackedArrayIndexLookup | Retrieves packed array element by index |

**Guard conditions:** Packed array count > 0 → compute average of all vertex positions. a2 == 2 → blend factor 0.35, else → 0.70.
