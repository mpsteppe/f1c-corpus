## VTableInitCallChain_004584a0 — CameraNodeVTableInit

**Summary:** Initializes vtable pointer (this[0]) to CameraNode vtable (off_59F00C), then calls resource cleanup/zero-init function and a short computation. Returns computation result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ArrayObjectDestructorWithDeallocation (0040b5c0), MainView (0040b850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to CameraNode vtable (off_59F00C) |

**Written-by note (persistence):**
- this 0x0: written every call to off_59F00C. External poke overwritten each call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f00c | off_59F00C | R | VTable_CameraNode [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00457cf0 | ConditionalFreeAndStructZeroInit | cleanup/zero-initialize associated resources or sub-objects |
| 004562a0 | ShortComputation_62a0 | compute return value from this |

**Guard conditions:** None — always executes all operations unconditionally.
