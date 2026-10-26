## StateParameterSetterWithVirtualDeviceNotify_00554610 — StateParameterSetterWithVirtualDeviceNotify

**Summary:** Sets a parameter on GameDeviceObject via vtable+244. If a2 is non-null, reads value from a2+84+20 as the parameter; if null, sends 0. Stores a2 in this[12].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateFieldSetWithChainedInit (00553fa0), MultiFieldSetterDispatchingTo7SubSetters (005546a0), UICleanupIterator (00554d70), D3DResourceListCleanup (00554e10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Object identifier / state ID |
| this | 0x30 | RW | 0 | Previous a2 pointer (this[12]), stores a2 after setting |

**Written-by note (persistence):**
- this 0x30: Always overwritten with a2 on change; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b89a0 | dword_8B89A0 | R | GameDeviceObject [DERIVED] (also: ` — global game state device object (virtual dispatch) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Guard: if a2 == this[12], skip entirely (no change). When a2 != 0: reads *(*(a2+84)+20) as parameter value and dispatches to vtable+244. When a2 == 0: dispatches 0.
