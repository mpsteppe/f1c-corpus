## FAILWRONGDESCRIPTION_42e0_004b42e0 — CollisionDataDispatchWithTypeCheck

**Summary:** Dispatches collision data block through conditional dispatch system. Checks header type bits (must be 0x2 in high 3-bit field with specific subfield clear), conditionally computes and dispatches a transformed float value as byte, then dispatches data payload. Called from CollisionObjectListManagement.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionObjectListManagement (004b4b50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep — threshold constant |
| 005acd28 | dbl_5ACD28 | R | ScaleFactor — scaling divisor in transform computation |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566bd0 | ConditionalDispatch_6bd0 | Dispatch header, transformed byte, or data payload through output system |
| 00587bdc | CRTFtol | Convert float-to-long with truncation (rounds transformed value to byte) |

**Guard conditions:** Checks header dword bitfield:
- Bits [31:29] (mask 0xE0000000) must equal 0x20000000 (type tag = 2)
- Bits [21:16] (mask 0xFC0000) must be zero (subfield clear)
If condition FAILS: skip transformed byte dispatch, only dispatch raw data payload.
If condition PASSES: compute transformed value as `(float_field - a2) / 0.000167 + 0.5`, clamp to byte, dispatch.
Data payload at +8 always dispatched with length from header bits [17:8].
