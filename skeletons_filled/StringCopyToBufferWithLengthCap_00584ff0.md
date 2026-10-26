## StringCopyToBufferWithLengthCap_00584ff0 — StringCopyWith16ByteCap

**Summary:** Copies a source string to an internal 16-byte buffer with null-termination, clearing the buffer first. Safe string copy with fixed max length.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VirtualFunctionDispatchWithStackFrames (0057a4f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x64 | RW | 0 | string buffer (16 bytes), cleared before copy |
| this | 0x74 | RW | 0 | null terminator at buffer[16], always set to 0 |

**Written-by note (persistence):**
- this 0x64: cleared on every call; if a2 non-NULL, filled with up to 16 bytes from source
- this 0x74: set to 0 on every call (null terminator)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | safe string copy with max length (16) |

**Guard conditions:** Source pointer a2 must be non-NULL — BLOCKED (buffer cleared but no copy). PASSES: buffer filled with up to 16 chars + null terminator.
