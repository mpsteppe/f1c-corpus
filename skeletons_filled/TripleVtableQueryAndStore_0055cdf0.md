## TripleVtableQueryAndStore_0055cdf0 — Three sequential vtable queries stored into struct fields

**Summary:** Makes three vtable calls to query property values: two via entry 38 (offset 0x98) with enum args 2 and 3, storing results at this+0x1458 and this+0x1498; one via entry 41 (offset 0xA4) storing at this+0x14D8. Part of UI property query/readback system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553700 (00553700)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x98 | R | — | Vtable entry 38 — query property by enum arg, store at output pointer |
| *(this+0x1100) | 0xA4 | R | — | Vtable entry 41 — query property (no enum), store at output pointer |
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
