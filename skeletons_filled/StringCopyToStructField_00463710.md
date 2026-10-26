## StringCopyToStructField_00463710 — String Copy to Fixed-Size Struct Field

**Summary:** Copies a source string (max 31 chars) into struct buffer at +0x1B0 with null-termination at +0x1CF. If source is null, zeros first byte of buffer (empty string). Returns pointer to this.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550), NetCommParseCommandLine (00463160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B0 | RW | 0 | destination buffer start for string copy (32 bytes total) |
| obj | 0x1CF | RW | 0 | null terminator position at end of 32-byte buffer (offset +31) |
| this | 0x0 | R | — | vtable/primary pointer |

**Written-by note (persistence):**
- obj 0x1B0: written once per call (via sub_587DD0 copy); survives until next copy
- obj 0x1CF: written once per call (null terminator); survives until next copy

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587dd0 | sub_587DD0 | string copy with max length 31 to destination buffer |

**Guard conditions:** If a2 (source string pointer) is null: BLOCKED from copy, zeros first byte at +0x1B0 instead (empty string). PASSES when a2 non-null — copies string up to 31 chars and null-terminates.
