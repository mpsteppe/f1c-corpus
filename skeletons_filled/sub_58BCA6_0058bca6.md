## sub_58BCA6_0058bca6 — IsProcessorFeaturePresentQuery

**Summary:** Dynamically resolves IsProcessorFeaturePresent from kernel32.dll via GetModuleHandleA/GetProcAddress and calls it with argument 0 (PF_XMMI — SSE instruction set). Falls back to sub_58BC68 if the API is unavailable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InitWrapperCalling3Subroutines (00587b7f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0cc | GetProcAddress | R | Win32 API import — resolve IsProcessorFeaturePresent from KERNEL32 module |
| 0059e21c | GetModuleHandleA | R | Win32 API import — get handle to KERNEL32 module |
| 005b8d58 | aIsprocessorfea | R | String literal "IsProcessorFeaturePresent" (search term) |
| 005b8d74 | aKernel32 | R | String literal "KERNEL32" (module name) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `GetModuleHandleA("KERNEL32")` returns NULL → skip API resolution, fall back to sub_58BC68
- `GetProcAddress` returns NULL → IsProcessorFeaturePresent not available, fall back to sub_58BC68
- Both succeed → call IsProcessorFeaturePresent(0) and return its result
