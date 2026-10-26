## SingleVTablePointerSet_0057bc70 — SetPhysicsVTablePointer

**Summary:** Assigns Physics vtable pointer (off_5B8A00) to object's first field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlacementDeleteDispatcher (005831b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to Physics vtable) |

**Written-by note (persistence):**
- this 0x0: unconditionally set per call; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a00 | off_5B8A00 | R | PhysicsVtable [DERIVED] — Physics object vtable pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
