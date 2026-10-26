## D3DResourceListCleanup_00554e10 — D3DResourceListCleanup

**Summary:** Two-phase cleanup: first resets device parameters for all slots via StateParameterSetter, then traverses a linked list of resource groups calling UICleanupIterator on each non-protected item (those without flag 0x80000).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0250 (004a0250), RenderTargetCleanup (0053f270), sub_554F80 (00554f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13B0 | R | — | Slot count (this[1260]), number of entries to clear in first phase |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00554610 | StateParameterSetterWithVirtualDeviceNotify | Resets device parameter to null for each slot |
| 00554d70 | UICleanupIterator | Iterates and releases UI resources in each group |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x13B0 | > | 0 | Slot count must be > 0 to enter parameter reset loop |

**Guard interpretation:** Phase 1: this[1260] > 0 gates the slot reset loop. Phase 2: a2 must be non-null to traverse resource tree. In traversal, items with flag 0x80000 set are skipped (protected/persistent resources).
