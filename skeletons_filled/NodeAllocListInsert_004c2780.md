## NodeAllocListInsert_004c2780 — AudioNodeAllocAndListInsert

**Summary:** Allocates and initializes an audio subsystem block (45396 bytes), loads game filter data into it, then wraps it in a 12-byte list node appended to this object's linked list. Optionally removes an existing node first if DelegatedFieldGetter returns 2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionSceneInitChain (004a0630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | list head pointer, set to new node if list was empty |
| this | 0x4 | RW | — | list tail pointer, updated to new node on append |
| this | 0x8 | RW | — | list secondary pointer, set to new node if list was empty |
| this | 0xC | R | — | list node count, incremented on each insertion |

**Written-by note (persistence):**
- this 0x0: set to new node if list was empty — external poke survives
- this 0x4: updated to new tail node each insertion — external poke survives
- this 0x8: set to new node if list was empty — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c0ab0 | AudioSubsystemInitializer | initialize allocated audio subsystem block |
| 004c0db0 | GameFilterDataLoader | load game filter data into initialized block |
| 004c1820 | LinkedListNodeRemovalWithCleanup | remove existing node from list (conditional) |
| 004c2760 | DelegatedFieldGetter | check field value to decide whether to remove old node |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (45396 for audio block, 12 for list node) |

**Guard conditions:** If DelegatedFieldGetter(this) returns 2, an existing node is removed first. AudioSubsystemInitializer must return non-null for node allocation and insertion to proceed.
