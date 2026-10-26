## ConditionalVirtualDispatchWithStateCheck_0046d360 — Conditional virtual dispatch with state check

**Summary:** Tests a condition via sub_4D24A0; if condition fails (returns 0), invokes vtable callback at offset 56 with state 1, then always invokes same callback with state 0. Two-state notification (active then inactive) gated by condition check.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x38 | R | — | vtable offset 56 — callback invoked with state parameter 1 or 0 |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase — passed to sub_4D24A0 as condition input |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d24a0 | sub_4D24A0 | evaluates force-feedback/input condition; returns 0 = condition not met |

**Guard conditions:** If sub_4D24A0 returns 0 (condition not met), calls vtable callback with param 1 (active state) before the always-called callback with param 0. If sub_4D24A0 returns non-zero (condition met), only the param-0 callback fires. No early-return guard — function always calls callback at offset 56 with 0 before returning.
