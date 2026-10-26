## j__atol_00631abd — atol import thunk

**Summary:** Jump thunk that forwards the CRT `atol` call to the real implementation. Used by callers linked against an import/jump-table slot rather than the direct address.

**Called by:** sub_4851B0 (004851b0), sub_488580 (00488580), sub_488A20 (00488a20), sub_4D8E30 (004d8e30), sub_4D93B7 (004d93b7), sub_52C875 (0052c875), sub_65E964 (0065e964), sub_65EDD0 (0065edd0), sub_660D48 (00660d48), sub_68076C (0068076c), sub_6AB114 (006ab114), sub_6B37F9 (006b37f9) … +3 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches; it tail-forwards its single argument to the real `atol` and returns its result unchanged.
