## sub_50FC7D_0050fc7d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722), FunctionPointerSwitch (00503888), RenderFeatureDispatch (005038c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e004 | RegQueryValueExA | R | [LLM] |
| 0059e008 | RegCloseKey | R | [LLM] |
| 0059e044 | RegOpenKeyA | R | [LLM] |
| 005ade4c | SubKey | R | RegistrySubKey [DERIVED] |
| 005ade68 | ValueName | R | DXTextureValueName [DERIVED] |
| 005d7994 | dword_5D7994 | RW | RendererStateInt [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fc58 | sub_50FC58 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
