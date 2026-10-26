## ResourceCascadeCleanup_005539f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionSystemShutdownCleanup (00494900), ConditionalDualCleanup (00499b50), ShortComputation_ec40 (0049ec40), SingleFieldFreeWrapper (0049eca0), AudioResourceReleaseByType (004d9030), ResourceCleanup_cd10 (004dcd10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553310 | ConditionalResourceCleanup_3310 | [LLM] |
| 0055c2e0 | DoublyLinkedListNodeUnlinkByMatch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
