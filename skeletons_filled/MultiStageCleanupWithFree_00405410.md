## MultiStageCleanupWithFree_00405410 — MultiStageSubObjectDestructor

**Summary:** Multi-stage cleanup: runs conditional dual-free cleanup, calls sub-object destructor, virtual-table-backed destructor at offset 0x30, and conditionally frees a heap buffer at offset 0x4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioSystemShutdown (00406e50), LinkedListNodeInsert (00407520), UtilityFunction (004081e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | heap buffer pointer (freed if non-null) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004054a0 | ConditionalCleanupWithDualFree | conditionally performs dual-free cleanup on global/static data |
| 004d4860 | sub_4D4860 | sub-object destructor/cleanup routine |
| 0052d8c0 | VTableDestructorWrapperWithNullCheck | virtual-table-backed destructor with null check |
| 00587bcf | FreeWrapper_7bcf | standard heap free wrapper |

**Guard conditions:** Checks this[1] (offset 0x4) != NULL before calling FreeWrapper_7bcf. PASSES: heap buffer freed. BLOCKED: heap buffer NULL, skips free.
