## DualVTableDestructor_00502bf4 — DualVTableDestructor

**Summary:** Calls destructor (vtable entry 0) on two sub-objects with flag=1. Second sub-object pointer stored at this+4, first at this+0. Only calls destructor if the pointer is non-NULL.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkPacketSendReceive (0050070d), AudioSoundBufferSetup (005007ef)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | Vtable entry 0 (destructor) for the sub-object |
| *(this+0x4) | 0x0 | R | — | Vtable entry 0 (destructor) for the second child object |
| obj | 0x0 | R | — | Vtable pointer for the called sub-object |
| this | 0x0 | R | — | Primary child vtable pointer (first destructor target) |
| this | 0x4 | R | — | Secondary child vtable pointer (second destructor target) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Second child (this+4) called only if non-NULL. First child (this+0) called only if non-NULL. Return value from second destructor propagated if first is NULL.
