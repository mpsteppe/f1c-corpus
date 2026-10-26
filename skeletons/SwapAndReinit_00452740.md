## SwapAndReinit_00452740 — Swap collision node values and reinitialize

**Summary:** Calls CollisionNodePropertySetter with the old value, then replaces both stored properties (offset 0x0 and 0x4) with new values, and calls CollisionNodePropertySetter again with the new ones. Used during collision node property updates from various init paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructInitWithFixedValues (00452780), StructInitWithSubCall (004527e0), DeviceObjectSelector (00452810), sub_452B10 (00452b10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Collision property value (old → replaced with a2) |
| this | 0x4 | RW | — | Collision property associated value (replaced with a3) |

**Written-by note (persistence):**
- this 0x0: updated unconditionally each call; external poke overwrites
- this 0x4: updated unconditionally each call; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca594 | byte_7CA594 | R | WheelBrakeBiasThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f050 | CollisionNodePropertySetter | Applies collision node property change with old and new values |

**Guard conditions:** none — always executes both property setter calls and value swap
