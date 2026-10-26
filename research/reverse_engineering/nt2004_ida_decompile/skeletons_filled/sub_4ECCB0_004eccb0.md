## sub_4ECCB0_004eccb0 — Penalty/Steward List Node Copy by Name

**Summary:** Searches a linked list for a node matching a given string name and a parent/context name, then copies its fields (name, value, context) into a separate target node in a different list. Used to transfer stewards' penalty or message data between lists.

**Called by:** sub_4ED7F0 (004ed7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAC)+0x0) | 0x8 | RW | — | Target node: penalty/event enum value |
| *(*(this+0xAC)+0x0) | 0x14 | RW | — | Target node: value/duration field |
| *(*(this+0xAC)+0x0) | 0x18 | RW | — | Target node: word-sized flag field |
| *(*(this+0xAC)+0x0) | 0x24 | RW | — | Target node: word-sized flag field 2 |
| *(*(this+0xAC)+0x0) | 0x28 | RW | — | Target node: context string pointer |
| *(this+0x20) | 0x0 | R | — | Source list: string name at node head |
| *(this+0x20) | 0x1C | R | — | Source list: context string pointer at node |
| *(this+0x28) | 0x0 | R | — | Target list: node pointer (linked list head) |
| *(this+0x28) | 0x8 | R | — | Target list node: penalty/event enum value |
| *(this+0x28) | 0xC | R | — | Target list node: next-node pointer |
| *(this+0x28) | 0x14 | R | — | Target list node: value/duration field |
| *(this+0x28) | 0x18 | R | — | Target list node: word-sized flag |
| *(this+0x28) | 0x1C | R | — | Target list node: context string pointer |
| *(this+0x28) | 0x24 | R | — | Target list node: word-sized flag 2 |
| *(this+0x28) | 0x28 | RW | 0 | Target list node: context string copied |
| *(this+0xA4) | 0x0 | R | — | Source list head pointer |
| *(this+0xAC) | 0x0 | R | — | Target list head pointer |
| *(this+0xAC) | 0x4 | R | — | Target list next-node pointer |
| this | 0x20 | R | — | Iterator state for source list |
| this | 0x28 | RW | — | Iterator state for target list |
| this | 0x2C | R | — | Reference to source context string (from this+0x20+0x1C) |
| this | 0x60 | R | — | Reference to target context string |
| this | 0x74 | R | — | Some node identifier |
| this | 0xA4 | R | — | Source list head |
| this | 0xAC | RW | — | Target list head/current |

**Written-by note (persistence):**
- *(*(this+0xAC)+0x0) 0x8: written once during copy; persists until next copy operation
- *(*(this+0xAC)+0x0) 0x14: written once during copy; persists until next copy
- *(*(this+0xAC)+0x0) 0x18: written once during copy; persists until next copy
- *(*(this+0xAC)+0x0) 0x24: written once during copy; persists until next copy
- *(*(this+0xAC)+0x0) 0x28: copied string via sub_578600; persists until next copy overwrites
- *(this+0x28) 0x28: copied string; external poke would be overwritten on next match
- this 0x28: iterator state; recalculated each call
- this 0xAC: target list head; set once, stable reference

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | Empty string used as default when pointer is null |
| 007da988 | dword_7DA988 | R | Global penalty/steward state flag |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00578600 | StringCopyWithBufferRealloc [structural] | Copy string with buffer management into target node |
| 00592310 | DestroyFree [structural] | Free previously allocated string in target node before overwrite |
| 005bf290 | __strcmpi | Case-insensitive string comparison for matching source/target nodes |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0xAC)+0x0) | 0x8 | != | 1 | Target node enum value not 1; keeps iterating target list until finding a node with enum==1 |

**Guard interpretation:** The function iterates the target list looking for a node where the enum field (offset 0x8) equals 1. This is the "active" or "matching" node into which source data is copied. Only when a node with enum==1 is found does the copy proceed; all other nodes are skipped. Also checks that source string matches the input String2 and that the context strings match between source node (offset 0x1C/0x28) and reference context (from this+0x24+0x14 / this+0x2C at offset 0x10).
