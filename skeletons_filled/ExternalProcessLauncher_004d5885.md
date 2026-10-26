## ExternalProcessLauncher_004d5885 — ExternalProcessLauncher

**Summary:** Launches an external process via CreateProcessA. Builds command line as `"<exe_path>" <args>`, using dword_7CEA18 as override exe path or default byte_5EA438 directory. Part of process-launch utility layer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d0 | CreateProcessA | R | Windows API — creates a new process and its primary thread |
| 005d45b8 | aSS_7 | R | SsFormatString [DERIVED] — format string `"%s" %s` for command-line construction |
| 005ea438 | byte_5EA438 | R | default application directory/executable path (fallback) |
| 007cea18 | dword_7CEA18 | R | alternate executable path override (if non-null, replaces default) |
| ff000000000053de | byte_FF000000000053DE | W | unknown write target (may be a thunk or data ref not visible in decompiler) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | safe snprintf-style string formatting into CommandLine buffer |

**Guard conditions:** value checks on two globals: if a1 (arg) is null, uses byte_5EA438 as argument; if dword_7CEA18 is null, uses byte_5EA438 as executable path. No early return — always proceeds to CreateProcessA.
