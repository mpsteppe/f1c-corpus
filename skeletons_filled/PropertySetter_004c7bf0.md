## PropertySetter_004c7bf0 — VehiclePropertySetter

**Summary:** Simple setter: stores a2 into the vehicle field at offset 0x48AC (this[4651]). Returns the value that was set.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4B3400 (004b3400), VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48AC | RW | — | vehicle property / state field |

**Written-by note (persistence):**
- this 0x48AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes.
