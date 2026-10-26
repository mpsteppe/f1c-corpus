## CollisionDataCopy_0044fbb0 — Copy collision device caps data

**Summary:** Copies a block of device capability/configuration data (0x244 bytes starting at offset 0x84) from stack parameters to the object, and stores a version/count field at offset 0x2F4. Called from the device enumeration callback sub_44ED10.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_44ED10 (0044ed10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2F4 | RW | — | Capability version/feature count — copied from parameter a2 |

**Written-by note (persistence):**
- this 0x2F4: written unconditionally during copy; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional copy of all parameters
