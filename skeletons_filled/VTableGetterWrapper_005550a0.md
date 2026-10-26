## VTableGetterWrapper_005550a0 — VTableGetterWrapper

**Summary:** Calls device object vtable+136 method and stores result in *this. Thin wrapper returning a value obtained from the device.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_553070 (00553070), sub_553700 (00553700), sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1100) | 0x88 | R | — | Device vtable+136 getter method |
| this | 0x0 | RW | — | Result from getter dispatch |
| this | 0x1100 | R | — | Pointer to device object (this[1088]) |

**Written-by note (persistence):**
- this 0x0: Updated from getter return; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditionally dispatches and updates *this.
