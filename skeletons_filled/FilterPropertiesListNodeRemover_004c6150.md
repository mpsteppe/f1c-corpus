## FilterPropertiesListNodeRemover_004c6150 — Remove filter property nodes matching criteria

**Summary:** Iterates filter property linked list, builds filter name from each node's scene entry, checks against filter criteria. Nodes whose filter name matches ALL criteria are preserved; non-matching nodes are unlinked and freed (with extra cleanup for the filter property structure).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileFilterBuilder (004c6330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Scene index in head node's filter property data |
| this | 0x8 | RW | — | Head pointer of linked list; updated if first node removed |
| this | 0xC | RW | — | Tail pointer; updated if tail removed |
| this | 0x10 | RW | — | Current iteration pointer; reset per node traversal |
| this | 0x14 | R | — | Count of items (returned at end) |

**Written-by note (persistence):**
- this 0x8: updated if head node removed
- this 0xC: updated if tail node removed
- this 0x10: rewritten during traversal; final value is head

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d31ec | aFilterProperti | R | FilterPropertiesString [DERIVED] (also: ` — "Filter Properties" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | Additional cleanup for filter property data (secondary pointers) |
| 004c58a0 | StringCopyWithValidation | Build filter property name from scene entry name at offset 0x104 |
| 00566810 | sub_566810 | Compare filter name against criterion value; 0 on match |
| 00587bcf | FreeWrapper_7bcf | Free filter property data struct and linked list node |

**Guard conditions:** Entry blocked if `*a2` (first filter) zero or `a3` (filter count) <= 0. If head list is null, return count. Per node: if scene entry is null OR filter name building fails, skip node without removal. If filter name matches ALL criteria (all `sub_566810` return 0), jump to next node (preserve). Otherwise, unlink and remove node from list.
