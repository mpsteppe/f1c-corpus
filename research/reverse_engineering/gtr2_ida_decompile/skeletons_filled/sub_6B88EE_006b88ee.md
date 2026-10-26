## sub_6B88EE_006b88ee — Copy window run into output buffer

**Summary:** Moves pending bytes from the window/stream substructure at +0x1C into the output cursor: copies min(source-available, output-budget) bytes, advances both cursors, decrements the source-available and output-budget counters, accumulates the byte counter at +0x14, and when the source run drains, re-arms the output budget from this+0x8. Low-level stream/flush helper of the compression pipeline.

**Called by:** sub_6B8942 (006b8942), sub_6B8F20 (006b8f20), sub_6B9044 (006b9044), sub_6B92EA (006b92ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x10 | RW | — | Window source read pointer; advanced by the number of bytes copied |
| *(this+0x1C) | 0x14 | RW | — | Source bytes available; decreased by the copy amount — reaching 0 drains the run |
| this | 0x8 | R | — | Block/window size value used to re-arm the output budget when the source run drains |
| this | 0xC | RW | — | Output destination cursor; advanced by the bytes copied |
| this | 0x10 | RW | — | Remaining output budget; clamp partner of the source-available count, decreased by the copy |
| this | 0x14 | RW | — | Total bytes copied counter, accumulated across copies |
| this | 0x1C | R | — | Pointer to the window/stream substructure holding the source side |

**Written-by note (persistence):**
- *(this+0x1C) 0x10: advanced only when a nonzero amount is copied; otherwise untouched
- *(this+0x1C) 0x14: decremented only when a nonzero amount is copied; reset semantics triggered when it reaches 0
- this 0xC: advanced only when a nonzero amount is copied; poke survives only while no copy happens
- this 0x10: decreased on each copy, and reset from this->0x8 when the source run drains; constantly recalculated while copies occur
- this 0x14: accumulated on each copy; external poke survives only while no copy happens

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Copy amount v2 = min(substruct->0x14 available, this->0x10 budget), clamped so it never exceeds the output budget. If v2 == 0 nothing happens at all — copy, cursor updates, and counter updates are all BLOCKED. If v2 != 0 the copy executes and all cursors/counters advance, and then: if the substructure's available count (substruct+0x14) reaches 0, the output budget this->0x10 is reset to this->0x8 (new block armed); otherwise it simply stays decremented.
