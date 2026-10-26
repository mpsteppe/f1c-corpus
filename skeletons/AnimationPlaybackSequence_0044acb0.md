## AnimationPlaybackSequence_0044acb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionGeometryOperationSelector (0044bb60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044aae0 | RecursiveTriangleEdgeSubdivisionForCollision | [LLM] |
| 004ce860 | StringListLookup | [LLM] |
| 004ce8d0 | IndexedArrayAccess | [LLM] |
| 004dd9f0 | TriangleNormalComputation | [LLM] |
| 005452f0 | AudioNetworkNodeCount | [LLM] |
| 00545340 | LinkedListNodeFinder | [LLM] |
| 00547370 | ArithmeticComparison_7370 | [LLM] |
| 0054c210 | SceneGraphChildCount | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 0054e190 | CameraDistanceGetter | [LLM] |
| 0054e1a0 | IndexedTransformRead | [LLM] |
| 0054e240 | ArrayIndexRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
