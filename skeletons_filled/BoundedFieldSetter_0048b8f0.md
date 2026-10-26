## BoundedFieldSetter_0048b8f0 — SetBufferSizeLimit

**Summary:** Sets buffer size limit at this+0x2F8 to a2, clamped to max 255 (0xFF). Called during text field init to cap max edit length.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UITextFieldInitialization (00470300), EngineTemperatureDebugDisplay (00470400), ConstructorWithStringCopy (0048b420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F8 | RW | a2 | Buffer size limit / max length for edit text |

**Written-by note (persistence):**
- this 0x2F8: written only if a2 < 256. Persists until re-initialized.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 >= 256 (0x100) → BLOCKED (no write, size unchanged). If a2 < 256 → PASSES: stores a2 as new buffer size limit at this+0x2F8.
