## VTableInitOnly_00598e2e — VTablePointerInit

**Summary:** Initializes object's vtable pointer (offset 0x0) to `off_5B9BCC`. Returns `this`. Unused second parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5986B2 (005986b2), LocaleFunctionCallWrapper (005986df), SingleFunctionCallWrapper_8794 (00598794)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to vtable at off_5B9BCC |

**Written-by note (persistence):**
- this 0x0: written once to vtable address; external poke would replace vtable and crash on next virtual call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9bcc | off_5B9BCC | R | VTable_5B9BCC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional write.
