## UtilityFunction_bf45_0058bf45 — FloatToStrZeroPadAndDecimalInsert

**Summary:** Formats floating-point output buffer: writes leading '-' if negative, fills with '0' padding, inserts decimal separator (byte_5E6BD8) after the integer part, and pads with '0' characters (0x30) for negative exponent positions. Handles zero-value special case with '0\0' termination.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** IntToStringWithSignPositionDraw (0058bef0), UtilityFunction_bfec (0058bfec)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 45 | Buffer start — written with '-' (45) if number is negative |
| this | 0x1 | RW | 48 | Pad/fill character — initialized to '0' (48) for zero padding |
| this | 0x2 | RW | — | Buffer position — written during string manipulation |

**Written-by note (persistence):**
- this 0x0: once per call if negative sign — overwritten with '-'
- this 0x1: once per call when padding with '0' characters — overwritten by sub_58BB10 or StringShiftByOffset
- this 0x2: once per call — overwritten during formatting

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e6bd8 | byte_5E6BD8 | R | DecimalSeparatorChar [DERIVED] — locale decimal separator inserted into output |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | Fill buffer region with repeated character (0x30 = '0') for padding |
| 0058c0d0 | StringShiftByOffset | Shift string content right by one position (make room for sign or decimal separator) |

**Guard conditions:**
- `a4 != 0 && a3[1] - 1 == a2` → zero special case: write '0\0' at position, terminate early
- `*a3 == 45` (negative sign) → write '-' at buffer start, advance pointer
- `a3[1] > 0` → position at offset a3[1] from sign-adjusted start
- `a3[1] <= 0` → shift string right by 1, write '0' at start
- `a2 > 0` → shift string right by 1 at decimal position, insert byte_5E6BD8 (decimal separator)
- `a3[1] < 0` (negative exponent) → shift left by a2, fill with '0' characters via sub_58BB10
