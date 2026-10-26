## GetSystemTimeAsFileTimeTo64BitTick_0058b59f — GetSystemTimeAsFileTime to 64-bit tick

**Summary:** Wraps GetSystemTimeAsFileTime, combines dwLowDateTime + (dwHighDateTime << 32) into a single 64-bit tick value, stores to global qword_8D3EC0, and returns it. No branching.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1b8 | GetSystemTimeAsFileTime | R | Win32 API import — retrieves current UTC time as FILETIME |
| 008d3ec0 | qword_8D3EC0 | W | SystemTimeTick64 [DERIVED] (also: ` — SystemTimeTick64 (docs/12) |
| 008d3ec4 | byte_8D3EC4 | W | High 32 bits of SystemTimeTick64 (overlapped by qword_8D3EC0 write) |
| ff00000000005394 | byte_FF00000000005394 | R | TLS byte — unknown startup/state flag |
| ff00000000005395 | byte_FF00000000005395 | R | TLS byte — unknown startup/state flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c6f0 | Allmul | 64-bit multiplication helper — shift dwHighDateTime left by 32 bits (multiply by 0x100000000) |

**Guard conditions:** None — straight-line function, no conditional branches.
