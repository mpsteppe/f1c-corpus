## StructFieldCopy_00456150 — Vector3Copy_0x24

**Summary:** Copies three consecutive DWORDs from source to struct fields at offsets 0x24, 0x28, 0x2C (elements [9], [10], [11]).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4348B0 (004348b0), ComponentTransformInitializer (00459010), SuspensionWheelForceCalculation (00459070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | first copied field (element [9]) |
| this | 0x28 | RW | — | second copied field (element [10]) |
| this | 0x2C | RW | — | third copied field (element [11]) |

**Written-by note (persistence):**
- this 0x24: always written when a2 non-null. Overwritten each call; external poke survives.
- this 0x28: same as 0x24.
- this 0x2C: same as 0x24.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 nullable; copy occurs only when a2 is non-null.
