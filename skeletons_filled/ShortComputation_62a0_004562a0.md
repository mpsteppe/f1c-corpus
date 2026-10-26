## ShortComputation_62a0_004562a0 — Destructor_VTableFree

**Summary:** Destructor: sets vtable pointer and frees a heap-allocated buffer at offset 0x4 if non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FilePathEntryArrayDestructor (00408800), CameraViewSystem (00408e20), ArrayDestructorAndDeallocator (0040ac60), StaticCameraSceneLoader (0040b030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59EFCC) |
| this | 0x4 | R | — | heap buffer pointer to free |

**Written-by note (persistence):**
- this 0x0: always written (vtable). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059efcc | off_59EFCC | R | vtable for this destructor |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | frees heap memory |

**Guard conditions:** this[1] (offset 0x4) checked non-null before calling FreeWrapper_7bcf.
