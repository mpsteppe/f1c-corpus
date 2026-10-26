## MultiFieldObjectDestructorWithCleanupCalls_00560e50 — SoundSubObjectDestructor

**Summary:** Destructor for 3D sound source sub-objects. Frees three allocated sub-objects at offsets 0xC, 0x1C, 0x20, calling cleanup stubs before each free. Part of 3D sound source teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DSoundSourceDestructor (00545150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Pointer to first sub-object to free |
| this | 0x1C | R | — | Pointer to second sub-object to free |
| this | 0x20 | R | — | Pointer to third sub-object to free |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | Cleanup stub for first sub-object |
| 00557470 | EmptyStub_7470 | Cleanup stub for sub-objects |
| 00560b90 | ConditionalFreeOfField | Conditional free of sub-object fields |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory |

**Guard conditions:** Each sub-object pointer (offsets 0xC, 0x1C, 0x20) checked for null before processing.
