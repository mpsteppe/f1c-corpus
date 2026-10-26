## SubCallFieldZero_00477080 — UIDimensionCaptureAndFlagReset

**Summary:** Captures UI element dimensions via `UIDimensionCapture` and clears a byte flag at offset 0x17C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17C | RW | 0 | boolean/flag reset to 0 (false) after dimension capture |

**Written-by note (persistence):**
- this 0x17C: set to 0 every call; external poke survives between calls

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048ebd0 | UIDimensionCapture | captures/saves UI element dimensions from this object |

**Guard conditions:** none
