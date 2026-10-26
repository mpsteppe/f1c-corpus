## LinkedListStringKeyRemoval_00551790 — LinkedListNodeStringKeyedFlagClear

**Summary:** Walks linked list of animation nodes, clears cascade flag (bit 0x20000) on nodes whose name string matches the given key, then triggers audio flag update.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13C | R | — | Linked list head pointer (this[79]) — start of node walk |
| this | 0x164 | RW | — | Node flags field — bit 0x20000 cleared on matching node |
| this | 0x17C | R | — | Node field (related to string comparison target) |
| this | 0x184 | R | — | Node field |

**Written-by note (persistence):**
- this 0x164: Bit 0x20000 cleared ANDed on matching node; other bits survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551480 | AudioFlagSet | Set audio timer flag (0x1000) and return accumulated timer |

**Guard conditions:** 
- strcmp(a2, i[7]+28) != 0: skip node (name mismatch). PASS when match found (clear flag + AudioFlagSet).
- i == 0 (end of list): loop terminates silently. PASS when non-null.
