## SetUITextFieldsViaVtableCalls_0055ce50 — Three sequential vtable property sets from stored fields

**Summary:** Makes three vtable calls to set properties: two via entry 37 (offset 0x94) with enum args 2 and 3, reading values from this+0x1458 and this+0x1498; one via entry 40 (offset 0xA0) reading from this+0x14D8. Counterpart to TripleVtableQueryAndStore — writes previously queried values back.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553700 (00553700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x94 | R | — | Vtable entry 37 — set property by enum arg, value from output pointer |
| *(this+0x1100) | 0xA0 | R | — | Vtable entry 40 — set property, value from output pointer |
| this | 0x0 | RW | — | Scratch/result storage — written from each vtable call result |
| this | 0x1100 | R | — | Pointer to sub-struct with vtable |

**Written-by note (persistence):**
- this 0x0: Written three times per call. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes all three vtable calls unconditionally.
