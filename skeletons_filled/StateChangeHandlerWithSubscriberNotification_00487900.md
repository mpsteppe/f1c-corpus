## StateChangeHandlerWithSubscriberNotification_00487900 — State change handler with subscriber notification

**Summary:** Handles UI state change: dispatches notification if state differs, then activates (vtable+64 with 4) or deactivates (RangeCheck + ConditionalStateMachineDispatch), then walks subscriber linked list from this+0x90 notifying each via vtable+56.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x90)+0x0) | 0x38 | R | — | field in linked list node structure (accessed via StructFieldAccessor for traversal) |
| *(this+0x90) | 0x0 | R | — | first field (vtable/header) of head linked list node |
| obj | 0x2C | R | — | UI state field for change detection |
| obj | 0x40 | R | — | range field read by RangeCheck for deactivation path |
| this | 0x0 | R | — | vtable pointer for virtual notification and dispatch calls |
| this | 0x90 | R | — | linked list head pointer for subscriber notification iteration |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486320 | StructFieldAccessor | traverses linked list to get next subscriber node |
| 00486660 | StateChangeNotification | dispatches state change notification to subscribers |
| 00486710 | ByteFieldGetterAt100 | retrieves current UI state byte for change detection |
| 00487740 | RangeCheck | validates range for deactivation dispatch path selection |
| 00487830 | ConditionalStateMachineDispatch | dispatches state machine logic for deactivation (a2==0) path |

**Guard conditions:** a2 == ByteFieldGetterAt100(this) — BLOCKS vtable+44 notification. a2==0 — takes deactivation path (RangeCheck + ConditionalStateMachineDispatch). a2!=0 — takes activation path (vtable+64 with 4). this+0x90 (linked list head) == NULL — BLOCKS subscriber notification loop.
