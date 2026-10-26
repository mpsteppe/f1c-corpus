## FloatComparisonListIteration_004b5380 — FloatThresholdListIterate

**Summary:** Walks a linked list, comparing each node's float fields at offsets +12 and +444 against threshold a2. Dispatches to different processing paths based on which field exceeds the threshold, or a default handler when both are within range. Called from sub_4B9000 for threshold-based list processing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0xC | R | — | Node float field at +12 (compared against threshold a2, lower bound) |
| *(*(this+0x20)+0x0) | 0x1BC | R | — | Node float field at +444 (compared against threshold a2, upper bound) |
| *(this+0x20) | 0x0 | R | — | First node data pointer (initial list entry) |
| *(this+0x28) | 0x4 | R | — | Next node pointer (cursor advancement) |
| *(this+0x28) | 0x8 | R | — | Node type/flag byte |
| this | 0x20 | R | — | List head pointer (source list for iteration) |
| this | 0x28 | RW | — | Cursor pointer (current node during iteration) |
| this | 0x30 | RW | — | Stored threshold value (a2 copied here) |

**Written-by note (persistence):**
- this 0x28: advanced to each node's next during iteration; becomes null at end
- this 0x30: written once — threshold a2 stored

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | Compare/process two fields (order depends on which threshold was exceeded) |
| 00500190 | VehicleDataBufferClear | Clear/reset vehicle data buffer (called when upper bound exceeded) |
| 005001b0 | sub_5001B0 | Process vehicle data (called when lower bound below threshold) |
| 005001d0 | FieldCompareConstant | Check field comparison result flag v6 |
| 005001f0 | FloatComparisonCheck | Check float comparison flag v5 |

**Guard conditions:**
1. If list head (this+0x20) is null: return immediately (no entries to process).
2. If first node's data pointer (*result) is null: skip loop (first iteration check fails).
3. For each node: if BOTH flags (v6 from FieldCompareConstant AND v5 from FloatComparisonCheck) are true AND node[+12] >= a2 AND node[+444] <= a2: skip processing (node is within valid range). Otherwise dispatch to handler:
   - If v5 AND node[+12] < a2: process lower bound violation (ArithmeticComparison_3a90 reversed, sub_5001B0).
   - Else if v6 AND node[+444] > a2: process upper bound violation (ArithmeticComparison_3a90 forward, VehicleDataBufferClear).
   - Else: default handler (unk_500170).
4. Loop terminates when cursor next pointer becomes null.
