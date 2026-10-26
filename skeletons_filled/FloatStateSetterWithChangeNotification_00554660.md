## FloatStateSetterWithChangeNotification_00554660 — FloatStateSetterWithChangeNotification

**Summary:** Sets float field this[16] to a2 and notifies GameDeviceObject via vtable+252 with state 19 if the value changed. Floats compared by value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53EB70 (0053eb70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Object identifier / state ID |
| this | 0x40 | RW | — | Float value field (this[16]), stores current float state |

**Written-by note (persistence):**
- this 0x40: Overwritten when float differs; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only writes if a2 != this[16] (float comparison). On change: stores float, then dispatches this[16] as int to GameDeviceObject state 19 via vtable+252.
