## ShortComputation_f210_0047f210 — ConditionalVirtualDispatchWithFlag

**Summary:** Checks boolean flag at offset 0xC; if set and vtable pointer valid, dispatches virtual function 0 with argument 1; otherwise returns flag value directly.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | first vtable entry (virtual function 0) called with argument 1 |
| obj | 0x0 | R | — | vtable pointer, validated before virtual dispatch |
| this | 0x0 | R | — | vtable pointer (same as obj) |
| this | 0xC | R | — | boolean guard flag; if zero, skips virtual dispatch and returns 0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this+0xC is zero, returns 0 immediately without virtual dispatch. If vtable pointer (this+0x0) is null, skips dispatch and returns the flag value. Only dispatches vtable[0](v2, 1) when flag is non-zero AND vtable is valid.
