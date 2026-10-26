## sub_50FBFC_0050fbfc — Direct3D registry value query

**Summary:** Queries a registry value from HKLM\Software\Microsoft\Direct3D. Returns TRUE only if the key opens, the value is read successfully, and the registry value type matches the expected type parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50FEA7 (0050fea7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e004 | RegQueryValueExA | R | registry value query API |
| 0059e008 | RegCloseKey | R | registry key close API |
| 0059e044 | RegOpenKeyA | R | registry key open API |
| 005ade4c | SubKey | R | "Software\Microsoft\Direct3D" subkey path string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** RegOpenKeyA must return ERROR_SUCCESS (0) — otherwise function returns FALSE immediately. Then RegQueryValueExA must return ERROR_SUCCESS AND the stored value type (Type) must equal parameter a1 (expected type). Only when both conditions are met does the function return TRUE.
