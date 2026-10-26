## DualFieldCleanupWithNullChecks_0055fe30 — cube map struct cleanup (file + buffer)

**Summary:** Cleans up a cube map struct: closes the open file handle (if non-null) and frees the allocated data buffer (if non-null). Both fields zeroed after release.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PhysicsObjectLinkedListRemoval (0053ce40), DoublyLinkedListNodeRemovalByFlag (0053ced0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | 0 | File handle to close |
| this | 0x128 | RW | 0 | Allocated data buffer pointer to free |

**Written-by note (persistence):**
- this 0x10: cleared (set to 0) after file close; survives as 0 until next load
- this 0x128: cleared (set to 0) after free; survives as 0 until next load

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free allocated data buffer |
| 00587d02 | FileCloseWithLock | Close MAS file handle |

**Guard conditions:**
- If this+0x10 (file handle) is 0 → skip close, proceed to buffer check
- If this+0x128 (data buffer pointer) is 0 → skip free, return 0
