## MultiFieldCleanup_004c3130 — StructPointerFieldCleanup

**Summary:** Destructor that frees multiple pointer fields in a structure: walks and frees a linked list at this+0x3D4, then individually frees pointer fields at offsets 0x0, 0x8, 0x10, 0x18, 0x20, 0x3CC, and 0x3D8. Each pointer is null-checked before freeing.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C2FC0 (004c2fc0), VehicleFileLoader (004c3d80), VehicleDataLoader (004c4240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3D4) | 0x8 | R | — | list node data payload pointer, freed if non-null |
| *(this+0x3D4) | 0x10 | R | — | list node next pointer, used for traversal |
| this | 0x0 | R | — | primary pointer field, freed if non-null |
| this | 0x8 | R | — | pointer field at [2], freed if non-null |
| this | 0x10 | R | — | pointer field at [4], freed if non-null |
| this | 0x18 | R | — | pointer field at [6], freed if non-null |
| this | 0x20 | R | — | pointer field at [8], freed if non-null |
| this | 0x3CC | R | — | pointer field at [243], freed if non-null |
| this | 0x3D4 | RW | — | linked list head pointer, walked and each node freed |
| this | 0x3D8 | R | — | pointer field at [246], freed if non-null |

**Written-by note (persistence):**
- this 0x3D4: set to next node during list walk (pointer becomes invalid after free)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | cleanup/release resources from list node |
| 00587bcf | FreeWrapper_7bcf | deallocate memory block |

**Guard conditions:** Each pointer is individually guarded: freed only if non-null. Linked list walk continues while next pointer is non-null.
