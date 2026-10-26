## MultiCallSequence_0049afe0 — GlobalStateResetSequence

**Summary:** Calls sub_49E8F0 on five consecutive global data structures for initialization/reset, then zeroes a 96-byte block of global state (0x7CE058 through 0x7CE0B4). Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 007ce0b8 | unk_7CE0B8 | R | ScoringInitSentinel [DERIVED] |
| 007ce104 | unk_7CE104 | R | FuncCall_Afe0 [DERIVED] |
| 007ce150 | unk_7CE150 | R | ScoringDataStruct [DERIVED] |
| 007ce19c | unk_7CE19C | R | VBlankSyncState [DERIVED] |
| 007ce1e8 | unk_7CE1E8 | R | SessionDataBlock [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049e8f0 | sub_49E8F0 | Per-struct initialization/reset routine called on each target |

**Guard conditions:** none — always executes all calls and zeroing unconditionally
