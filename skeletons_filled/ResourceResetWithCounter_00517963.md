## ResourceResetWithCounter_00517963 — ResetResourceWithStateCheck

**Summary:** Validates non-null pointers (this and sub-object at this+0x1C), resets state counters to 0 (this+0x8, this+0x14, this+0x18), sets sub-object first dword to 7 or 0 based on condition flag at sub-object+0xC, then calls sub_52765A with data pointer from sub-object+0x14.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5179E0 (005179e0), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | state counter/field, cleared to 0 |
| this | 0x14 | RW | 0 | state counter/field, cleared to 0 |
| this | 0x18 | RW | 0 | state counter/field, cleared to 0 |
| this | 0x1C | RW | — | pointer to sub-object whose first dword is set to 7 or 0 based on condition |
| this | 0x28 | R | — | sub-object field at +0xC (offset 12), used as condition for value selection |
| this | 0x30 | R | — | sub-object field at +0x14 (offset 20), passed as argument to sub_52765A |

**Written-by note (persistence):**
- this 0x8: cleared to 0 each reset
- this 0x14: cleared to 0 each reset
- this 0x18: cleared to 0 each reset
- this 0x1C: first dword of sub-object set to 7 or 0 each reset

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052765a | sub_52765A | performs additional reset/cleanup with pointer from sub-object+0x14 |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x28 | != | 0 | sub-object pointer at this+0x1C — null returns -2 early |

**Guard interpretation:**
1. this == NULL → return -2 immediately
2. *(this+0x1C) == NULL → return -2 immediately  
3. If both non-null: proceed to reset counters, set sub-object dword based on v1[3] condition, call sub_52765A
4. *(sub-object+0xC) != 0 → set first dword to 7; == 0 → set first dword to 0
