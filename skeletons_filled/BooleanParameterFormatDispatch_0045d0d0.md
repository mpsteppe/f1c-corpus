## BooleanParameterFormatDispatch_0045d0d0 — Format password boolean parameter

**Summary:** Checks whether a password is configured by reading string length via ConstantOffsetAccessor(0). Formats boolean result (1 if password length > 0, 0 if empty) as "%d" and writes "password" key-value pair into output buffer via ShortComputation_ce30.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c5c40 | aPassword_0 | R | PasswordString [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045ce30 | ShortComputation_ce30 | Sets "password" key-value pair in output buffer |
| 00463750 | ConstantOffsetAccessor | Reads string from constant offset to check password length |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats boolean (password exists) as "%d" |

**Guard conditions:** none — unconditional formatting
