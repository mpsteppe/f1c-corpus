## VTableDispatch_7640_00487640 — Radio state handler then vtable+168 dispatch

**Summary:** Handles radio/check button state via UIRadioCheckStateChangeHandler, then calls virtual function at vtable offset 168 for further processing; returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | field read through vtable+168 call for further processing |
| this | 0x0 | R | — | vtable pointer for virtual dispatch at offset 168 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00487460 | UIRadioCheckStateChangeHandler | manages radio/check button state with string validation |

**Guard conditions:** none — unconditional two-step dispatch
