## UIListSearchByName_76c0_004976c0 — SearchTwoLevelNestedListByName

**Summary:** Traverses a two-level nested linked list. Outer list rooted at this+0x4. For each outer node, retrieves inner list head via FieldGetter_8e30, then walks inner list using next pointer at offset 0x48, comparing name string at offset 0x34 against `a2`. Returns last matching inner item pointer, or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492160 (00492160), LookupDispatch (00497940), sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Outer linked list head pointer |
| this | 0xC | RW | — | Current outer node pointer during traversal |
| this | 0x10 | R | — | Loop boundary or list count |

**Written-by note (persistence):**
- this 0xC: Written at entry and each outer iteration. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default name string when inner node name is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498e30 | FieldGetter_8e30 | Retrieves inner list head from outer node |
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions:** Parameter a2 must be non-null — null returns 0 immediately. Outer head this[1] must be non-null — null skips outer loop (returns 0). Inner and outer next pointers checked for null during traversal — null breaks respective loop.
