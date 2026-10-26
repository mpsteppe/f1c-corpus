## SceneFileFilterBuilder_004c6330 — SceneFileFilteredListBuilder

**Summary:** Builds a filtered, sorted linked list of scene files — either the full unfiltered set (when no filter string or in photo/free-camera mode), or a parsed filter string supporting AND:/NOT: logic with tokenized include/exclude buckets and merge-sorted output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x4 | RW | 0 | Linked list node `next` pointer — set when appending new nodes to the tail |
| this | 0x8 | RW | — | Linked list head pointer (first node in filtered scene list) |
| this | 0xC | RW | — | Linked list tail pointer (last node, used for append; also iteration cursor) |
| this | 0x10 | RW | — | Current/iteration cursor pointer (duplicate of tail, used during traversal) |
| this | 0x14 | RW | — | Total node count in the linked list (incremented on each insertion) |
| this | 0x18 | RW | 0 | State flag/counter — reset to 0 at end of function |

**Written-by note (persistence):**
- *(this+0xC) 0x4: Conditional write — set only when appending to non-empty list (existing tail's next pointer); external poke would be lost on next list rebuild
- this 0x8: Once per call — rebuilt from scratch on each invocation; external poke survives only until next filter build
- this 0xC: Once per call — rebuilt from scratch; external poke overwritten next call
- this 0x10: Once per call — rebuilt from scratch; external poke overwritten next call
- this 0x14: Once per call — recomputed; external poke overwritten next call
- this 0x18: Once per call — always reset to 0 at end; external poke overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d30c0 | dword_5D30C0 | R | StringCompConstantBlock [DERIVED] |
| 005d30c4 | dword_5D30C4 | R | NetSessionInfo_5D30C4 [DERIVED] |
| 005d30c8 | byte_5D30C8 | R | Byte_NetCheckFlags_30C8 [DERIVED] |
| 005d30cc | dword_5D30CC | R | MessageBoxConfig [DERIVED] |
| 005d30d0 | byte_5D30D0 | R | MPRegionSelectFlags [DERIVED] |
| 005d30d4 | dword_5D30D4 | R | FilterCategoryPat0 [DERIVED] (also: `/etc — filter category name patterns (copied from static data) |
| 005d30d8 | byte_5D30D8 | R | FilterCategoryName [DERIVED] |
| 005d31ec | aFilterProperti | R | FilterPropertiesString [DERIVED] (also: ` — "Filter Properties" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] (also: � photo/free camera mode flag) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c58a0 | StringCopyWithValidation | Copy scene property string from scene array entry with bounds checking |
| 004c5c80 | sub_4C5C80 | Construct a scene file info node from its name string and index |
| 004c5d30 | SceneSortComparator | Compare two scene file nodes for merge sort ordering |
| 004c5e50 | FilterPropertiesListBuilder | Build include-list from AND: prefix tokens — adds matching scenes |
| 004c5fd0 | FilterPropertiesListBuilder_5fd0 | Build exclude-not list from NOT: prefix tokens |
| 004c6150 | FilterPropertiesListNodeRemover | Remove exclude-list nodes from the main linked list |
| 004c62c0 | ResourceListCleanup_62c0 | Clean up and free all existing linked list nodes |
| 004c6810 | MergeSortLinkedList | Recursive merge sort on the linked list using SceneSortComparator |
| 00566650 | StringCopyWithBufferRealloc | Copy filter string to internal buffer |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate list node (16 bytes) and bucket entries (12 bytes) |
| 00587dd0 | sub_587DD0 | Copy/tokenize filter string into working buffer with length limit |
| 00588410 | sub_588410 | String comparison — check token against "AND:"/"NOT:" prefixes |
| 005897ca | sub_5897CA | String tokenizer — extract next token from buffer using delimiter set |

**Guard conditions:**
- `!a2 || !strcmp(a2, byte_5EA438) || (dword_7D0398 && dword_7D0410 != 5)`: Build full unfiltered list. PASSES when filter string is NULL, empty, or in photo/free-camera mode not in championship race 5. Iterates all `dword_8AC488` scene files, building nodes from properties strings. BLOCKED — enters filter parsing branch.
- Filter parsing branch: tokenizes filter string by delimiters `" ,\t\n"`. Each token checked:
  - `sub_588410(i, v37)` ("AND:" prefix): sets `v30 = 0` (include mode)
  - `sub_588410(i, &v39)` (comparison constant): sets `v30 = 1` (exclude-not mode)
  - `sub_588410(i, v38)` ("NOT:" prefix): sets `v30 = 2` (exclude mode)
  - Each bucket capped at 49 entries (`*v5 < 49`). PASSES when under limit; BLOCKED at 50+ tokens of that type.
- After list construction: `v16 >= 2` (node count check): Merge sort only when 2+ entries exist. PASSES with multiple entries — performs full merge sort using `SceneSortComparator`. BLOCKED with 0-1 entries — list used as-is.
- `v2[2]` (head pointer): if non-null (existing head), appends new nodes by chaining through tail's next. If null, sets head = tail = current = new node.