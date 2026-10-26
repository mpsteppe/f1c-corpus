## TrackSceneNodeAdd_004c28d0 — TrackSceneNodeAdder

**Summary:** Adds a new track scene node to the scene list. Checks for duplicates by name via LinkedListSearchByName, parses scene data, allocates and initializes a scene node block (24 bytes), wraps it in a list node (12 bytes), and appends to the linked list at this+0x10. Returns the existing or newly inserted node.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringInfoUpdater (004c2a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | scene list head pointer, set on first insertion |
| this | 0x14 | RW | — | scene list tail pointer, updated to new node on append |
| this | 0x18 | RW | — | scene list secondary pointer, set on first insertion |
| this | 0x1C | R | — | scene list node count, incremented on successful insert |

**Written-by note (persistence):**
- this 0x10: set to first node if list was empty — external poke survives
- this 0x14: updated to each new tail — external poke survives
- this 0x18: set to first node if list was empty — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] — index into scene array |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] — base of scene data array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c03a0 | AlternatingInit | initialize allocated 24-byte scene node block |
| 004c2860 | LinkedListSearchByName | search for existing node by name (dedup check + final return) |
| 004c5690 | SceneDataParser | parse scene data file by name |
| 00566650 | StringCopyWithBufferRealloc | realloc-copy scene path strings into node |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory (24 for scene node, 12 for list node) |

**Guard conditions:** LinkedListSearchByName must return 0 (no duplicate) for insertion. Scene pointer from dword_8AC490+396*dword_8AC48C must be non-null. AlternatingInit result must be non-null for list node wrapping and insertion.
