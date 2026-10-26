## DestructorWithConditionalFreeFlagClear_005502c0 — ConditionalFreeThenFlagClear

**Summary:** Conditionally frees a sub-object pointer, calls cleanup, then clears the free flag. Used as error-path or release destructor across texture/sound/resource systems.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionSystemShutdownCleanup (00494900), SoundResourceCleanup (0049ec60), ConditionalFreeSubCall (0049ecc0), sub_4D8CF0 (004d8cf0), AudioResourceReleaseByType (004d9030), ResourceCleanup_cd10 (004dcd10), sub_544740 (00544740), AudioNetworkStreamCleanup (00544af0), ReferenceCountedResourceRelease (005469c0), sub_546AA0 (00546aa0), sub_54FEC0 (0054fec0), D3DTextureCreation (00550080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | Free/destroy flag — cleared to 0 after resource is freed |
| this | 0x54 | RW | 0 | Pointer to allocated sub-object; freed then zeroed if non-null |

**Written-by note (persistence):**
- this 0x4: Written unconditionally to 0 on every call; external poke overwritten
- this 0x54: Written to 0 only when pointer was non-null; external poke survives if pointer was null

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542e50 | sub_542E50 | Cleanup/destructor for the sub-object at this+0x54 |
| 00557470 | EmptyStub_7470 | Stub function called before free (likely debug or sentinel) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation for freed sub-object |

**Guard conditions:** 
- this+0x54 (pointer at offset 0x54) == 0: skip entire sub-object cleanup and free block. PASS when non-null (cleanup runs), BLOCKED when null.
