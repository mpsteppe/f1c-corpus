## AudioSamplePositionVolumeSetter_004071f0 — AudioPositionVolumeVectorCopy

**Summary:** Copies a 3-component position/volume vector from input pointer to object fields at offsets 0x7C-0x84, then delegates to a computation function.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | RW | — | first component of position/volume vector |
| this | 0x80 | RW | — | second component of position/volume vector |
| this | 0x84 | RW | — | third component of position/volume vector |

**Written-by note (persistence):**
- this 0x7C: written unconditionally — set from input vector element 0
- this 0x80: written unconditionally — set from input vector element 1
- this 0x84: written unconditionally — set from input vector element 2

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00407d40 | ShortComputation_7d40 | performs additional processing with input parameters a2 and a3 |

**Guard conditions:** none — always copies the vector and calls the delegate function
