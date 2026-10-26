## LocalUnwindWrapper_00588a19 — LocalUnwindDispatch

**Summary:** Thin wrapper that reads SEH scope frame pointer and target trylevel from a struct at +0x18 and +0x1C, then dispatches to SEH frame unwinder. MSVC CRT helper for `_local_unwind`.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | Pointer to SEH scope table / exception registration record passed to unwinder |
| this | 0x1C | R | — | Target trylevel value passed to unwinder |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005888a6 | MSVCRTSEHFrameUnwinder | Unwind SEH scope table from current trylevel to target trylevel |

**Guard conditions:** None — unconditional call, no branches.
