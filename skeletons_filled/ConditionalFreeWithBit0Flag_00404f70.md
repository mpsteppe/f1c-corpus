## ConditionalFreeWithBit0Flag_00404f70 — ConditionalBufferAndNodeFree

**Summary:** Frees the inner buffer at this->0 if non-null, then conditionally frees the container node itself if parameter a2 has bit 0 set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderNodeListDestructor (00404ac0), ComplexDestructorWith4LinkedLists (00406ba0), PlayerProfileScanner (00468ee0), sub_47C360 (0047c360), UIFullRenderPass (0048b030), sub_4C83B0 (004c83b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | inner buffer pointer (freed if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | standard heap free wrapper |

**Guard conditions:** Checks this->0 != NULL before freeing inner buffer. Checks a2 & 1 != 0 before freeing container node. PASSES: inner buffer freed if present; container freed if a2 bit 0 set. BLOCKED: inner buffer not freed if NULL; container not freed if a2 bit 0 clear.
