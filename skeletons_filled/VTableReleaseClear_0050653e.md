## VTableReleaseClear_0050653e — Release single COM interface pointer and null

**Summary:** If the stored interface pointer (*this) is non-null, calls its vtable+40 method (likely Unlock or Release), then sets the pointer to 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_506971 (00506971)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x28 | R | — | vtable entry at offset 40 (Release/Unlock method) on the stored interface |
| obj | 0x0 | R | — | stored COM interface pointer to release |
| this | 0x0 | RW | 0 | storage slot for COM interface pointer, set to 0 after release |

**Written-by note (persistence):**
- this 0x0: once — set to 0 after releasing the old pointer; external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If *this is non-null → calls vtable+40 on it, then nulls pointer. If *this is already null → just returns 0.
