## sub_6A2EE8_006a2ee8 — InstantiateObjectsFromDescriptorTable

**Summary:** Walks the descriptor table (this[140], count this[19]) and builds a 116-byte object for every qualifying descriptor: allocates, initializes with the descriptor's element count, links child slots returned by sub_681AAA, appends the object to the this[139]/this[136] list and registers it via sub_681997. Part of the object/asset loading system.

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | base of a lookup table used in the two-level indirection that yields the control byte checked before allocating |
| this | 0x14 | R | — | base of the second lookup table in that indirection (descriptor list value → object → index) |
| this | 0x4C | R | — | descriptor count in the this[140] array; loop bound and early-out test |
| this | 0x88 | R | — | context value passed to child-slot allocator sub_681AAA |
| this | 0x220 | R | — | number of objects already appended to this[139]; compared against the 0x200 capacity |
| this | 0x22C | R | — | base of the built-object pointer list; new object stored at [0x22C + 4*count] |
| this | 0x230 | R | — | base of the descriptor pointer array iterated by the loop |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0066238f | sub_66238F | releases the partially built object (called with flag 1) on the error path |
| 00680cec | ZeroInit16ElementArray [structural] | zero-initializes the 16 dwords of the newly allocated object |
| 00680d22 | sub_680D22 | attaches the source descriptor to the new object; negative result aborts |
| 00681186 | sub_681186 | allocates the 116-byte object (null result → error) |
| 006811d1 | sub_6811D1 | initializes object with element count v17 and flag 0x10000000; negative result aborts |
| 00681997 | sub_681997 | registers/finalizes the constructed object; negative result aborts |
| 00681aaa | sub_681AAA | obtains a child slot for index v8 (context this[34]); returned index is cross-linked into the new object |

**Guard conditions:** Early-out: if this[19] (0x4C) == 0 → return 0 immediately. Per descriptor: null descriptor pointers are skipped; entries whose (first dword & 0xFFF00000) == 0 or == 1913651200 (0x72100000) are skipped. For the remaining entries the two-level indirect lookup must yield a control byte with bit 0x2 set — otherwise the entry is skipped without allocation. Failures BLOCK with return -2147024882 (0x8007000E): null object after sub_681186, or this[136] (0x220) >= 0x200. Negative returns from sub_6811D1, sub_680D22 or sub_681997 jump to the error path that releases the object and returns that error code. PASS: loop ends when ++v18 >= this[19] → return 0.
