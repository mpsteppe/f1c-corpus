## sub_58BCCF_0058bccf — DecimalSeparatorReplaceAndShift

**Summary:** Scans string for first character that is not a digit (sub_58B465 returns != 101), replaces it with decimal separator (byte_5E6BD8), then left-shifts remaining characters by one position. Returns the displaced character. Used for inserting decimal separator into formatted number string.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First char of the numeric string being formatted (replaced with next char after shift) |
| this | 0x1 | RW | — | Second char of the string (shifted left during separator insertion) |

**Written-by note (persistence):**
- this 0x0: overwritten by the shift operation — once per call, the displaced char overwrites it
- this 0x1: overwritten by the shift operation — once per call, shifted left when separator is inserted

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e69c8 | off_5E69C8 | R | CharTypeTable [DERIVED] — character classification table (used if cbMultiByte <= 1) |
| 005e6bd4 | cbMultiByte | R | CharTypeTableVersion [DERIVED] (also: CharTypeTableVersion (docs/08, 12, 20) — selects single-byte vs multi-byte char classification path |
| 005e6bd8 | byte_5E6BD8 | R | DecimalSeparatorChar [DERIVED] — locale-dependent decimal separator character (e.g. '.' or ',') |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058b465 | sub_58B465 | Classify character type — returns 101 for digit-like chars, other values for non-digit |
| 0058c674 | CharacterEncodingConvertViaLookupTableFallback | Multi-byte character classification (used when cbMultiByte > 1) |

**Guard conditions:**
- Loop while `sub_58B465(*v1) != 101` (skip chars classified as digits) — stops at first non-digit
- Inner loop while `v2` (char classification result) is nonzero — skips non-digit type chars
- Second loop runs until `*v4++` is zero — copies/shifts characters left until null terminator
