## FileHandleCloseRegistration_004b4470 — ResourceHandleDispatchRegistration

**Summary:** Looks up a resource handle via ResourceLookupDispatcher, stores it at offset 0x4, then dispatches 4-byte header and 2-byte sub-field through conditional dispatch. Called from CollisionObjectListManagement during object registration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionObjectListManagement (004b4b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Resource handle pointer from lookup dispatcher |

**Written-by note (persistence):**
- this 0x4: written once — set to result of ResourceLookupDispatcher

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566bd0 | ConditionalDispatch_6bd0 | Dispatch 4-byte header (this) and 2-byte sub-field (this+2) |
| 00566e20 | ResourceLookupDispatcher | Look up resource handle by key a2 |

**Guard conditions:** No guard conditions — always executes fully (linear, no branches).
