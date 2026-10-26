## ArrayShiftConditionalDispatch_004bbf70 — FixedArrayDequeueShift

**Summary:** Decrements entry count of the fixed-size accumulator array, shifts remaining entries left by one slot (each slot = 2 DWORDs), then reports emptiness status through ArithmeticComparison_5660. Used by sub_4B3400 as the dequeue counterpart to AccumulatorWithFixedArray.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B3400 (004b3400)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to parent container object (used to access comparison target at container+13004) |
| this | 0x3C | RW | — | entry count of the fixed-size array (decremented on dequeue) |
| this | 0x40 | RW | — | first array slot type field (slot 0 pair) |
| this | 0x44 | RW | — | first array slot value field (slot 0 pair) |
| this | 0x48 | R | — | second array slot type field (slot 1 pair) |
| this | 0x4C | R | — | second array slot value field (slot 1 pair) |

**Written-by note (persistence):**
- this 0x3C: decremented by 1 on each call when count > 0; external poke might survive but will be overwritten on next dequeue
- this 0x40: overwritten when shifting — slot 0 copy becomes old slot 1; external poke does not survive
- this 0x44: overwritten when shifting — slot 0 value becomes old slot 1 value; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5660 | ArithmeticComparison_5660 | reports whether array is empty (arg=0) or has entries (arg=1) |

**Guard conditions:** if count (this+0x3C) <= 0, skip dequeue and shift but still report status (0 if empty, 1 if has entries); if count > 0, remove entry and shift
