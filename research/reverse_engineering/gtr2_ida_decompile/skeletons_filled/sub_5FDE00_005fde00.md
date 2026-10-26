## sub_5FDE00_005fde00 — Dispatch notification to matching handlers

**Summary:** For a given object, walks the manager's linked list of registered entries and invokes the handler (virtual method at +0x14) of every entry whose type id matches the object's id at +0x224, writing a context value into the object at +0x20 first; then invokes the object's own default handler (method at +0x20) if one is registered.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x230)+0x0)+0x18) | 0x14 | R | — | handler object's method pointer slot; checked nonzero before invoking |
| *(*(*(this+0x230)+0x0)+0x18) | 0x18 | R | — | handler context value copied into the notified object at +0x20 |
| *(*(this+0x230)+0x0) | 0x14 | R | — | entry type id compared against the object's id at +0x224 |
| *(*(this+0x230)+0x0) | 0x18 | R | — | handler object pointer stored in the matching list entry |
| *(obj+0x224) | 0x20 | R | — | default handler method slot; checked nonzero before invoking |
| *(obj+0x224) | 0x24 | R | — | default handler context value copied into the notified object at +0x20 |
| *(this+0x230) | 0x0 | R | — | first node of the handler-entry list (read from the cached cursor) |
| *(this+0x238) | 0x4 | R | — | next-entry link read while advancing the traversal |
| obj | 0x224 | R | — | object's type/id and handler-table pointer used for matching and default dispatch |
| this | 0x0 | R | — | pointer to the object being notified |
| this | 0x8 | R | — | manager/subsystem pointer whose handler list is enumerated |
| this | 0x20 | RW | — | notification context/scratch slot written before each handler invocation |
| this | 0x230 | R | — | cached traversal cursor over the handler-entry list |
| this | 0x238 | RW | — | traversal link refreshed on every loop iteration |

**Written-by note (persistence):**
- this 0x20: written conditionally, only when a matching entry with a non-null handler is found (or the default handler exists); an external poke survives until the next dispatch that matches.
- this 0x238: rewritten on every loop iteration during traversal; an external poke does not survive (recalculated each call).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Manager pointer (this+0x8) must be nonzero to enter the enumeration; its cached list cursor (this+0x230, taken from manager+0x228) must be nonzero or enumeration is skipped. Per entry, dispatch happens only if the entry's id (entry+0x14) equals the object's id (obj+0x224) AND the handler object's method slot (handler+0x14) is nonzero — then this+0x20 is set from handler+0x18 and the method is invoked with the object. Traversal stops when the cursor or its next link becomes null. The second phase runs only if obj+0x224 is nonzero and the default handler's method slot (+0x20) is nonzero; only then is this+0x20 set from +0x24 and the method invoked.
