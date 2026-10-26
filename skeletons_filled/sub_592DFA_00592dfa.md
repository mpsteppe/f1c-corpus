## sub_592DFA_00592dfa — GetEnvironmentStringsBlock

**Summary:** Retrieves process environment strings block, attempting Unicode (W) variant first with fallback to ANSI (A). Caches which variant succeeded in global flag for subsequent calls.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_58A19E (0058a19e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e10c | GetEnvironmentStringsW | R | Retrieve Unicode environment strings block |
| 0059e110 | GetEnvironmentStrings | R | Retrieve ANSI environment strings block (fallback) |
| 0059e114 | FreeEnvironmentStringsW | R | Free Unicode environment strings block after processing |
| 0059e118 | FreeEnvironmentStringsA | R | Free ANSI environment strings block after processing |
| 0059e228 | WideCharToMultiByte | R | Convert Unicode environment strings to multibyte for caller |
| 008d41a8 | dword_8D41A8 | RW | CRT_EnvCache_Flag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | Allocate buffer for converted/copied environment strings |
| 0058aa6f | sub_58AA6F | Free buffer on WideCharToMultiByte conversion failure |
| 0058cc00 | MemoryCopy_cc00 | Copy ANSI environment strings into allocated buffer |

**Guard conditions:** `dword_8D41A8` cache flag: 0=uninitialized (tries GetEnvironmentStringsW first), 1=Unicode path (skips GetEnvironmentStringsW attempt, goes straight to WideCharToMultiByte), 2=ANSI path (skips all W-variant code). If GetEnvironmentStringsW returns NULL and flag was 0, falls through to ANSI GetEnvironmentStrings. If GetEnvironmentStringsW returns NULL and flag was 1 (should not happen in practice), returns NULL early. WideCharToMultiByte returning 0 triggers buffer free and returns NULL. Malloc returning 0 returns NULL.
