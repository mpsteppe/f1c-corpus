## VTableSwitchWithVirtualCall_0040b5a0 — VTable Switch E6AC To SceneNode

**Summary:** Temporarily switches vtable to VTable_59E6AC, calls sub-object virtual function (arg=3) if present, then switches to VTable_SceneNodeChain. Acts as a vtable transition sequence.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x0 | R | — | Vtable entry 0 of sub-object (called with arg 3) |
| this | 0x0 | RW | — | VTable pointer (switched twice: to VTable_59E6AC then to VTable_SceneNodeChain) |
| this | 0xC | R | — | Sub-object pointer (notified during vtable transition) |

**Written-by note (persistence):**
- this 0x0: Written unconditionally twice per call (first to VTable_59E6AC, then to VTable_SceneNodeChain). External poke does NOT survive — both writes originate here.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e634 | off_59E634 | R | VTable_SceneNodeChain [DERIVED] |
| 0059e6ac | off_59E6AC | R | VTable_59E6AC [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Sub-object pointer at this+0xC must be non-null for virtual call to execute; if null, only vtable switch happens.
