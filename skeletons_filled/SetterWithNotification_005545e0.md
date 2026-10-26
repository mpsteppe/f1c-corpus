## SetterWithNotification_005545e0 — SetterWithNotification

**Summary:** Sets GameDeviceObject state 11 to a2 value directly via vtable+252, then stores a2 in this[11]. Skips if a2 == this[11] or a2 == -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiFieldSetterDispatchingTo7SubSetters (005546a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Object identifier / state ID |
| this | 0x2C | RW | — | Previous a2 value (this[11]), stores a2 after setting |

**Written-by note (persistence):**
- this 0x2C: Always overwritten with a2 on change; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be != -1 and != this[11]. If passes, dispatches a2 directly as value to state 11 on GameDeviceObject.
