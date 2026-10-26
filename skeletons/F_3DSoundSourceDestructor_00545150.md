## F_3DSoundSourceDestructor_00545150 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A2220 (004a2220), ArrayResourceCleanup (004a29a0), sub_4D0080 (004d0080), VehicleResetClear (004e09e0), ResourceCleanupDestructionForDirectXObjects (00543bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14C | R | — | [LLM] |
| this | 0x150 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545150 | F_3DSoundSourceDestructor | [LLM] |
| 005452b0 | LinkedListRemove | [LLM] |
| 005459d0 | LinkedListRemove_59d0 | [LLM] |
| 0054a710 | TwoFunctionCallChain | [LLM] |
| 0054a770 | SceneGraph | [LLM] |
| 00560c00 | StateFlagSetterCleanup | [LLM] |
| 00560e50 | MultiFieldObjectDestructorWithCleanupCalls | [LLM] |
| 00560f10 | DoublyLinkedListNodeUnlink_0f10 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
