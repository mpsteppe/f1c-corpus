## VTableDispatchWithConditionalBranch_00585400 — BitmapTestThenListAppendOrVTableDispatch

**Summary:** Tests a bitmap range for occupancy: if occupied, appends to a list via sub_584DD0; if free, dispatches via vtable+0x2C and vtable+0x5C with a sub_584230 call. Part of a resource/buffer tracking system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50), BufferCopyViaVirtualTypeDispatch (00587930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x2C | R | — | vtable+44 dispatch, called on free path |
| obj | 0x5C | R | — | vtable+92 dispatch, called on free path |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00584230 | sub_584230 | process/update function called on free path |
| 00584dd0 | sub_584DD0 | mutex-guarded list append on occupied path |
| 00586d00 | BitmapRangeOccupancyTestViaBitOps | test bitmap for range occupancy |

**Guard conditions:** BitmapRangeOccupancyTestViaBitOps(a2) — if true (occupied), BLOCKED (takes list append path, skips dispatches). If false (free), PASSES (dispatches via vtable calls).
