## sub_58BE2E_0058be2e — FloatToStrExponentAndDecimalFormat

**Summary:** Formats a floating-point number's string representation: writes sign character '-', inserts decimal separator at correct position, appends exponent marker 'E' and decomposes exponent value into digits (hundreds/tens/units) added to pre-initialized '0' characters. Called by floating-point-to-string conversion routines.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatToStringWithSignWidth (0058bdcd), UtilityFunction_bfec (0058bfec)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 45 | Sign character position — written with '-' (45) if value is negative |
| this | 0x1 | RW | — | Digit right of decimal point — shifted left when decimal separator inserted |
| this | 0x2 | R | — | Read for string positioning during formatting |

**Written-by note (persistence):**
- this 0x0: written once if negative sign needed — overwritten with '-' from initial buffer state
- this 0x1: once per call — shifted left by one position during decimal separator insertion

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8d80 | aE000 | R | String_E000 [DERIVED] — template "E+000" for exponent formatting (or "-000") |
| 005e6bd8 | byte_5E6BD8 | R | DecimalSeparatorChar [DERIVED] — locale decimal separator inserted into formatted string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c0d0 | StringShiftByOffset | Shift string content right by one position (make room for sign or decimal separator) |
| 0058fca0 | sub_58FCA0 | Advance output pointer past formatted portion of buffer |

**Guard conditions:**
- `a5 != 0` → call StringShiftByOffset before writing sign (conditional spacing)
- `*(_DWORD *)a4 == 45` (negative) → write '-' at buffer start
- `a2 > 0` → shift and insert decimal separator (byte_5E6BD8) at position a2
- `a3 != 0` → write exponent marker 'E' (69) at end
- `**(BYTE **)(a4 + 12) != '0'` → compute and write exponent digits (handle negative exponent with '-')
- Exponent values decomposed into base-10 digits added to pre-initialized '0' characters at positions 2-4
