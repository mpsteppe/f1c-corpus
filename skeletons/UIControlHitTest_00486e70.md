## UIControlHitTest_00486e70 — UIControlPointInRectTest

**Summary:** Tests if point (a2, a3) falls within the control's bounding rectangle. Hit testing is gated by an enable flag at this+0x65. Returns 1 on hit, 0 otherwise. Part of UI control interaction system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | vtable offset 8 — get bounds method (returns left/top/right/bottom) |
| this | 0x0 | R | — | vtable pointer |
| this | 0x65 | R | — | hit-test enable flag (byte); when zero, always returns 0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[101] (byte at offset 0x65) is zero → return 0 (hit testing disabled). If non-zero → retrieve bounds via vtable+8, then check if a2 between left/right and a3 between top/bottom.
