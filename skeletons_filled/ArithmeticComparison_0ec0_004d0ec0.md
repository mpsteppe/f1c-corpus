## ArithmeticComparison_0ec0_004d0ec0 — Value setter with conditional dispatch

**Summary:** Stores value `a2` at this+0x0, then conditionally calls sub_5506A0(a2, 0, 0) if the flag at this+0x4 or this+0x8 is non-zero. Acts as a setter with notification gate.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50), Steward_Restart (004d3cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Stored value (pointer/handle) being set |
| this | 0x4 | R | — | Notification gate flag — if non-zero, triggers sub_5506A0 |
| this | 0x8 | R | — | Secondary notification gate flag — if non-zero, triggers sub_5506A0 |

**Written-by note (persistence):**
- this 0x0: Written unconditionally with `a2` each call. External poke would be overwritten on next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005506a0 | sub_5506A0 | Called with (a2, 0, 0) when notification gate allows; likely a notify/validate/dispatch routine |

**Guard conditions:** None at top level — `a2` is stored unconditionally. Calls to sub_5506A0 are gated on this+0x4 and this+0x8 being non-zero.
