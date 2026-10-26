## IterateTriggersViaVtableCallHandlersPerTick_00585bf0 — DispatchTriggerHandlersPerTick

**Summary:** Iterates objects (triggers) via vtable methods (start iteration at +200, get count at +164, get item at +28, check predicate at +172), dispatches each qualifying item through a handler at vtable offset +52 with parameters from DualQueryIntoTwoOutputParams, FieldGetter_5cc0, and ReadFieldAtOffset0x14. Releases items via vtable+32 and ends iteration via vtable+204.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UtilityFunction_a800 (0057a800)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Object header field accessed during dispatch |
| obj | 0x20 | R | — | Object link/next pointer field |
| obj | 0xA4 | R | — | Object data field read during dispatch |
| obj | 0xAC | R | — | Object data field read during dispatch |
| obj | 0xC8 | R | — | Object configuration field |
| obj | 0xCC | R | — | Object configuration field |
| this | 0x0 | R | — | Vtable pointer for dispatch calls |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | No-op stub called after each dispatch |
| 00585cc0 | FieldGetter_5cc0 | Get field pointer from this object |
| 005871c0 | DualQueryIntoTwoOutputParams | Query two output parameters from internal state |
| 005871f0 | ReadFieldAtOffset0x14 | Read field at offset 0x14 from v2 object |
| 00587220 | sub_587220 | Compute additional parameter from v2 object |

**Guard conditions:** vtable+172 predicate check on (this, index, currentItem) must return non-zero for item to be dispatched to handler at vtable+52. Items failing the check are skipped (still released later via vtable+32). Iteration count v14 from vtable+164; early exit when v3 >= v14.
