## DestructorWithConditionalFreeFlagClear_005502c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionSystemShutdownCleanup (00494900), SoundResourceCleanup (0049ec60), ConditionalFreeSubCall (0049ecc0), sub_4D8CF0 (004d8cf0), AudioResourceReleaseByType (004d9030), ResourceCleanup_cd10 (004dcd10), sub_544740 (00544740), AudioNetworkStreamCleanup (00544af0), ReferenceCountedResourceRelease (005469c0), sub_546AA0 (00546aa0), sub_54FEC0 (0054fec0), D3DTextureCreation (00550080)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542e50 | sub_542E50 | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
