## LinkedListDestructorWithChildCleanup_00565e20 — two-level list destructor with inner cleanup

**Summary:** Destroys two-level linked list. Calls EnhancedListCleanupWithSubObjectDelete on inner list, frees extra resource at v3[132] (offset 0x210), then iterates outer nodes freeing data (with sub-object ShortComputation_4370) and nodes. Finally zeroes list head and frees head structure. Directory/file enumeration cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ResourceListCleanup (00404d50), FileEnumerationByExtension (00421b10), PlayerNameNeverUsedProfileFileCreateRead (004b03f0), TGATextureFileScanner (004c3a00), sub_4C84A0 (004c84a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | node's data pointer |
| *(obj+0x0) | 0x8 | R | — | node flag — whether data needs cleanup |
| obj | 0x0 | RW | 0 | list head field 1 (zeroed after cleanup) |
| obj | 0x4 | RW | 0 | list head field 2 (zeroed after cleanup) |
| obj | 0x8 | RW | 0 | list head field 3 (zeroed after cleanup) |
| obj | 0xC | RW | 0 | list head field 4 (zeroed after cleanup) |
| obj | 0x210 | R | — | extra sub-resource pointer to free before node iteration |
| this | 0x0 | R | — | pointer to list head structure |

**Written-by note (persistence):**
- obj 0x0: unconditionally zeroed; external poke does not survive
- obj 0x4: unconditionally zeroed; external poke does not survive
- obj 0x8: unconditionally zeroed; external poke does not survive
- obj 0xC: unconditionally zeroed; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | sub-object cleanup on data+0x144 |
| 00565d50 | EnhancedListCleanupWithSubObjectDelete | cleanup inner list |
| 00587bcf | FreeWrapper_7bcf | memory deallocation (free equivalent) |

**Guard conditions:** If `*this == NULL` → skip entire outer cleanup. If `v3[132] == NULL` → skip extra resource free. Per node: if byte at node+8 == 0 → skip data cleanup. If data pointer `*v5 == NULL` → skip data cleanup.
