## sub_50FC7D_0050fc7d — MMX support detection with registry override

**Summary:** Detects MMX instruction support for rendering. Checks registry "DisableMMX" for forced disable; if uninitialized (dword_5D7994 negative), runs CPU feature detection and emits EMMS if MMX is available. Returns MMX enable state (0=disabled, 1=enabled).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722), FunctionPointerSwitch (00503888), RenderFeatureDispatch (005038c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e004 | RegQueryValueExA | R | registry value query API |
| 0059e008 | RegCloseKey | R | registry key close API |
| 0059e044 | RegOpenKeyA | R | registry key open API |
| 005ade4c | SubKey | R | "Software\Microsoft\Direct3D" subkey path |
| 005ade68 | ValueName | R | "DisableMMX" value name string |
| 005d7994 | dword_5D7994 | RW | MMX enable state — -1=uninit, 0=disabled, 1=enabled |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fc58 | sub_50FC58 | MMX CPU feature detection subroutine |

**Guard conditions:** Registry: RegOpenKeyA must succeed. Then RegQueryValueExA must succeed, Type must be REG_DWORD (4), and Data must be non-zero — if all met, MMX forced off (state=0). If dword_5D7994 is negative (PASS): run CPU detection via sub_50FC58, set state to 0 or 1. If dword_5D7994 >= 0 (BLOCKED): skip detection, return current state.
