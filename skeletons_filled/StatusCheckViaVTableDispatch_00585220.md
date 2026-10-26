## StatusCheckViaVTableDispatch_00585220 — StatusCheckWithVTableThreshold

**Summary:** Reads a status byte flag and compares a vtable-dispatched function result against a threshold, returning true only if both conditions are met. Status query with dual condition check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA4 | R | — | vtable dispatch offset +164, function returning comparison value |
| this | 0x0 | R | — | vtable pointer |
| this | 0x5D | R | — | status byte flag (first return condition) |
| this | 0x60 | R | — | threshold value (comparison against vtable result) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always proceeds. Optional output params (a2, a3) only written if non-NULL. Returns `this[0x5D] != 0 && (vtable+164)(this) < this[0x60]`.
