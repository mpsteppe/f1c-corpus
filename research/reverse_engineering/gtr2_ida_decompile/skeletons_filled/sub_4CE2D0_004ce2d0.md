## sub_4CE2D0_004ce2d0 — GetListNodeNameByIndex

**Summary:** Variant of sub_4CE170 taking the traversal index as an argument: walks the list headed at 0x90 by a2 steps and returns the reached node's string pointer (node+0xA0), falling back to WindowName when null. Returns 0 for a negative index, an empty list, or a walk that runs off the end.

**Called by:** sub_4A04E0 (004a04e0), sub_4B00C0 (004b00c0), sub_4B4BA0 (004b4ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8C | R | — | Node next/link field (node+0x8C) followed once per traversal step |
| *(this+0x11C) | 0xA0 | R | — | Node string pointer (node+0xA0); returned when non-null |
| this | 0x90 | R | — | List head pointer (this[36]) where the walk starts |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16bc | WindowName | R | Fallback name string returned when the reached node's string pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 < 0 → returns 0 (BLOCKED). List head this[0x90] == 0 → returns 0 (BLOCKED). During the while loop, if the next node (node+0x8C) is 0 before a2 steps complete → returns 0 (BLOCKED). Reached node's string (node+0xA0) == 0 → returns the global WindowName; non-null → returns that node string. Note the index 0 returns the head node itself (loop not entered).
