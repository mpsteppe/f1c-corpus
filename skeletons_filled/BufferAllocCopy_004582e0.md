## BufferAllocCopy_004582e0 — KeyframeArrayDeepCopy

**Summary:** Allocates new keyframe array and deep-copies all 7 fields (28 bytes) per element from source format accessed via StridedArrayElementPointer. Validates source count >= 4, allocates heap memory, copies each keyframe's data, then recomputes cumulative arc lengths via KeyframeArcLengthPrecompute. Returns pointer to `this`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_459330 (00459330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | pointer to allocated keyframe array (starts after 4-byte count header) |
| this | 0x4 | RW | — | keyframe count (copied from source) |

**Written-by note (persistence):**
- this 0x0: written every successful call (new heap allocation). Pointer survives until freed externally.
- this 0x4: written every successful call. Survives until next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00457ee0 | sub_457EE0 | recompute cumulative arc length for each keyframe after copy |
| 00458020 | UtilityFunction_8020 | unknown initialization before allocation |
| 004582a0 | StridedArrayElementPointer | get pointer to source element at index v3 (handles source stride != 28) |
| 00587c03 | OperatorNewNhMallocWrapper | allocate heap memory: 28*a2[1] + 4 bytes |

**Guard conditions:** If a2[0] (source array pointer) == NULL, skip entire operation. If a2[1] (source count) < 4, skip allocation. Both guards must pass for work to proceed.
