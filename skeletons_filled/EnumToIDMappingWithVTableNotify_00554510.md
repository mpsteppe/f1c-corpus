## EnumToIDMappingWithVTableNotify_00554510 — EnumToIDMappingWithVTableNotify

**Summary:** Maps enum a2 (0,1,2) to state parameter 14 values (1,3,2) and dispatches to GameDeviceObject via vtable+252. Records a2 in this[15]; skips if unchanged or a2==-1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiFieldSetterDispatchingTo7SubSetters (005546a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Object identifier / state ID |
| this | 0x3C | RW | — | Previous a2 value (this[15]), stores a2 after setting |

**Written-by note (persistence):**
- this 0x3C: Always written with a2 when changed; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be != -1 and != this[15]. Maps: a2=0→state14=1, a2=1→state14=3, a2=2→state14=2. Other values silently skipped.
