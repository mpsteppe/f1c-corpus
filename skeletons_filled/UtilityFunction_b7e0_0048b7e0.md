## UtilityFunction_b7e0_0048b7e0 — TextEditBufferInit

**Summary:** Initializes text edit buffer pointers: stores buffer pointer at this+0x2F0 and buffer size at this+0x2F8, then calls vtable[42] with arg 1. Called during text field setup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UITextFieldInitialization (00470300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | unknown |
| this | 0x0 | R | — | VTable pointer |
| this | 0x2F0 | RW | a2 | Buffer start pointer for edit text |
| this | 0x2F8 | RW | a3 | Buffer end limit / max size |

**Written-by note (persistence):**
- this 0x2F0: written once during init with caller-provided buffer pointer. Persists until re-initialized.
- this 0x2F8: written once during init with caller-provided max size. Persists until re-initialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 (buffer) is null or a3 (size) <= 0 → BLOCKED (no-op, returns 0). Otherwise PASSES: buffer and size are stored, vtable[42] called.
