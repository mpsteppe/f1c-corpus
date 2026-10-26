## SearchPathPrune_0053ca00 — StringTablePruneFlagged

**Summary:** Prunes entries from the global string table that have flag 0x400 set. Compacts surviving entries to the front of the table and zeros remaining slots. Used to remove processed/matched entries from the active set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringMatchWithFlagSet (0053c900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b5a38 | dword_8B5A38 | R | StringTableFlags [DERIVED] (also: ` — flags) |
| 008b6ab8 | dword_8B6AB8 | R | AudioBufferLoopBoundary [DERIVED] |
| 008b8e30 | dword_8B8E30 | RW | RegisteredEntryCount [DERIVED] (also: ` — entry count (max 0x20) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053c6a0 | TwoFieldInitializer | Initializes/zeros a table entry (two-field pattern) |
| 0053c6b0 | ArithmeticComparison_c6b0 | Copies/moves one table entry to another (33 DWORD stride) |
| 005881c0 | __alloca_probe | Stack allocation probe for large local buffer (4224 bytes) |

**Guard conditions:** Checks if entry count (dword_8B8E30) > 0 before scanning and pruning. Checks each entry's flag 0x400: if set, entry is pruned; if clear, entry survives. After compaction, checks if new count < 32 before zeroing remaining slots up to boundary.
