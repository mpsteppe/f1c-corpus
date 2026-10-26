## GameStateSettingViaVirtualDispatch_005544c0 — GameStateSettingViaVirtualDispatch

**Summary:** Sets game state parameter 13 on GameDeviceObject via vtable+252 with value mapped from a2 (0→1, 1→3, 2→2). Records a2 in this[14] and skips if a2 == this[14] or a2 == -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiFieldSetterDispatchingTo7SubSetters (005546a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Object identifier / state ID |
| this | 0x38 | RW | — | Previous state (this[14]), stores a2 after setting |

**Written-by note (persistence):**
- this 0x38: Always written with a2 when changed; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be != -1 and != this[14]. If a2 is 0,1,2 it dispatches to vtable+252 with values 1,3,2 respectively. Any other non-matching value skips silently.
