## PollingLoopWithBranch_0046e7f0 — Path polling loop with conditional branch

**Summary:** Iteratively strips directory components from module callback path until empty, then branches: if field at offset 0x168 is zero, reads settings setup file; otherwise, normalizes path string with UI text input and performs file enumeration. Part of file path processing system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x168 | R | — | field at offset 360 (this[90]) — determines branch: 0 = read settings, non-zero = normalize path with UI text |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c73e0 | dword_7C73E0 | RW | ModuleCallbackTable — path string consumed by loop, then passed to read/normalize |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004328f0 | StringEmptyCheck | checks if module callback path string is empty |
| 00432980 | PathNormalizerFileEnumeration | normalizes path and enumerates files |
| 00432a10 | DirectoryPathExtraction | extracts/removes one directory component from path |
| 00489920 | UIScreenTextAccessor | retrieves text content from UI screen element |

**Guard conditions:** No entry guard. Loop: while module callback path string is NOT empty, calls DirectoryPathExtraction to strip components. After loop: if this[90]==0, reads settings setup file and returns; else (non-zero), gets UI text and runs path normalization/file enumeration, returns result.
