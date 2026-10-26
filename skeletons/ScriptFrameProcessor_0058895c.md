## ScriptFrameProcessor_0058895c — SEHExceptHandler3or4

**Summary:** MSVC CRT `_except_handler3`/`_except_handler4` frame handler. Evaluates exception filters and dispatches to catch handlers. Walks scope table trylevels, calls filter functions, performs global + local unwind on match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Flags field (bit 1 and 2 checked: value & 6); if set, full unwind without filter eval |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588864 | GlobalUnwind2 | Perform global unwind (RtlUnwind) before local unwind |
| 005888a6 | MSVCRTSEHFrameUnwinder | Unwind local SEH scope table to target trylevel |
| 0058893a | sub_58893A | Callback after successful filter match, passes scope entry handler address |

**Guard conditions:** Checks this+0x4 flags: if (value & 6) != 0, performs full unwind to -1 and returns 1 (unconditional unwind path). Otherwise, walks scope table evaluating filters normally.
