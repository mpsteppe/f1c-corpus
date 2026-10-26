## BufferEntryAppendWithMatrixInit_005698e0 — AppendSecondGroupEntry

**Summary:** Appends a 132-byte entry to the second constraint group buffer (this[142], stride 132). Stores metadata parameters at offsets 120/124/128, initializes a 3x3 matrix at offsets 24 and 48 via sub_56C3A0, and increments element count at this[141] (offset 0x234).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsJointSystemLoader (0056d930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x234 | R | — | element count for second group (incremented after append) |
| this | 0x238 | R | — | pointer to second group element buffer (stride 132) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0056c3a0 | sub_56C3A0 | initializes 3x3 matrix block within the entry (at offsets 24 and 48) |

**Guard conditions:** None — unconditional append with count increment.
