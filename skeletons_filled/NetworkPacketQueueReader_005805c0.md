## NetworkPacketQueueReader_005805c0 — dual-list packet queue reader with transfer

**Summary:** Reads from two mutex-protected linked lists: processes first list (at this+0xB74), extracts a node element via sub_583430 validation, or if none found, processes second list (at this+0xB48) with cleanup and element removal. Writes result from second list into first list's data field at offset +72. Returns element value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8C) | 0x48 | RW | — | First list node data at field +72 (written with result from second list) |
| this | 0xB58 | R | — | Second list node pointer (cursor entry at list+4) |
| this | 0xB60 | RW | 0 | Second list cursor (updated during traversal) |
| this | 0xB68 | RW | 0 | Second list mutex handle |
| this | 0xB6C | R | — | Second list mutex timeout |
| this | 0xB8C | R | — | First list struct field (pointer to data) |
| this | 0xB94 | RW | 0 | First list mutex handle |
| this | 0xB98 | R | — | First list mutex timeout |

**Written-by note (persistence):**
- *(this+0xB8C) 0x48: written with value from second list; survives until next read
- this 0xB60: updated during second list traversal; persists until next operation
- this 0xB68: mutex handle; set externally
- this 0xB94: mutex handle; set externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on both list mutexes |
| 0059e1a4 | ReleaseMutex | R | Release both list mutexes |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ba780 | ShortComputation_a780 | Compute/validate on list structure |
| 005823c0 | sub_5823C0 | Process second list (fallback path) |
| 00582780 | sub_582780 | Process first list (fallback path) |
| 00582b10 | LinkedListElementRemovalWithCleanup | Remove and clean up element from list |
| 005832e0 | sub_5832E0 | Validate/process node from second list |
| 00583430 | sub_583430 | Validate/process node from first list |

**Guard conditions:**
- If first list mutex handle is null or wait fails → skip first list processing (v4=0, null deref risk on v5)
- This function has multiple fallback paths; if one list has no valid element, it falls through to the other list's processing
