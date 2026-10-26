## F_3FieldGetter_00542490 — Get three fields (orientation angles / facing)

**Summary:** Reads values at offsets 0x30, 0x34, 0x38 and writes them through output pointers a2, a3, a4 respectively. Each output pointer is individually null-guarded.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TwoCallDelegation_2420 (00542420), sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x30 | R | — | pitch angle |
| this | 0x34 | R | — | yaw angle |
| this | 0x38 | R | — | facing direction Z component |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) individually guarded: if null, that field is skipped. Non-null → write the field value.
