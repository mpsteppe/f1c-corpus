## VTablePointerSetter_00599e66 — VTable pointer setter to off_5B9C68

**Summary:** Sets this->vtable to off_5B9C68 and returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FixedDelegation (005997f5), sub_599822 (00599822), sub_59984F (0059984f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5B9C68 |

**Written-by note (persistence):**
- this 0x0: written once to off_5B9C68; value persists until overwritten by another vtable assignment

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9c68 | off_5B9C68 | R | PTR_VTABLE_5B9C68 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional.
