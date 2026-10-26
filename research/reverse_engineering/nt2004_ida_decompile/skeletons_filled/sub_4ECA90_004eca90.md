## sub_4ECA90_004eca90 — AssetTreeSelectionSwap

**Summary:** Searches a tree/asset hierarchy by matching a category name and item name (case-insensitive), then swaps the currently loaded asset object with a new one created from the matched entry, cleaning up the old object.

**Called by:** sub_4ED7B0 (004ed7b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(*(this+0xC)+0x8)+0x4)+0x0) | 0x0 | R | — | Name string pointer at leaf node (matched against v4) |
| *(*(*(this+0xC)+0x18)+0x0) | 0x0 | R | — | Name string pointer of matched category entry |
| *(*(*(this+0xC)+0x18)+0x4) | 0x4 | R | — | Next sibling pointer in category linked list |
| *(*(*(this+0xC)+0x8)+0x4) | 0x0 | R | — | First child item name string pointer |
| *(*(*(this+0xC)+0x8)+0x4) | 0x4 | R | — | Next child node pointer for traversal |
| *(*(this+0xC)+0x18) | 0x0 | R | — | Item count for this category (loop bound) |
| *(obj+0x0) | 0x0 | R | — | Name string pointer of object's associated asset entry |
| *(this+0xC) | 0x8 | R | — | Pointer to first child item linked list head |
| *(this+0xC) | 0x14 | R | — | Item count in this category node (guard: must be >0) |
| *(this+0xC) | 0x18 | R | — | Pointer to category sub-list/array |
| *(this+0xC) | 0x24 | R | — | Count of category sub-items (inner loop bound) |
| obj | 0x0 | R | — | Name string pointer at obj (default-checked against empty) |
| this | 0x0 | R | — | Root tree/list pointer (must be non-null to proceed) |
| this | 0x8 | RW | — | Traversal cursor — current node in the linked list walk |
| this | 0xC | R | — | Pointer to selected category node (source of v3 data) |
| this | 0x60 | RW | — | Currently loaded/active asset object — replaced on match |
| this | 0x6C | R | — | Used as parameter to sub_4EB6C0 to create new object |
| this | 0x74 | R | — | Used as parameter to sub_4EB6C0 to create new object |

**Written-by note (persistence):**
- this 0x8: Recalc every call — rewound to `*this` then advanced during traversal; external poke overwritten immediately
- this 0x60: Written once on successful match; external poke survives until next successful match

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | Default empty string fallback when a name pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d5b0 | sub_40D5B0 | Destroy/free owned pointer members in old asset object during cleanup |
| 004667a0 | LinkedListDestructorWithData [structural] | Destroy linked list at old object+9 with data cleanup |
| 004e9ce0 | sub_4E9CE0 | Initialize new asset object from the selected tree context |
| 004eace0 | sub_4EACE0 | Cleanup/reset a sub-component of old asset object |
| 004eb6c0 | sub_4EB6C0 | Create new asset object from matched tree entry name |
| 004edad0 | sub_4EDAD0 | Destroy sub-list at old object+17 and old object+13 |
| 004edbe0 | sub_4EDBE0 | Destroy sub-list at old object+21 |
| 00578600 | StringCopyWithBufferRealloc [structural] | Copy path/name string with reallocation |
| 005be8ae | sub_5BE8AE | Free/deallocate the old object memory |
| 005bf290 | __strcmpi | Case-insensitive string comparison for category name and item name matching |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC) | 0x14 | <= | 0 | Item count check — BLOCKED if no items in category |
| this | 0x0 | == | 0 | Root pointer check — BLOCKED (early return 0) if no tree loaded |

**Guard interpretation:** Function returns 0 (failure) immediately if `*this` (root pointer) is null or if the item count in the matched category is ≤ 0. Successful match replaces `this[24]` with a newly created object and returns 1.
