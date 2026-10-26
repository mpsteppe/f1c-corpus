## SceneOrderSlotFinder_004c5cb0 — Find scene position in SceneOrder list

**Summary:** Initializes order slot to INT_MAX (0x7FFFFFFF), loads the SceneOrder linked list, then iterates through it comparing scene names against the scene entry name at global offset. Stores the matching list index in field 0xC.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C5C80 (004c5c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Scene index used to locate scene entry in global scene array |
| this | 0xC | RW | 2147483647 | Position in SceneOrder list; initialized to INT_MAX, set to match index if found |

**Written-by note (persistence):**
- this 0xC: set to 0x7FFFFFFF then conditionally overwritten with SceneOrder index if match found; survives external pokes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d28b4 | aSceneorder | R | SceneOrderStringConst [DERIVED] (also: ` — "SceneOrder" string constant) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | Extract name string pointer from SceneOrder linked list node |
| 005679a0 | NullCheckWrapper | Safely retrieve SceneOrder list node by index (returns node or null) |
| 00568210 | AudioChannelStop | Load SceneOrder linked list by key "SceneOrder" from audio channel system |
| 00588410 | sub_588410 | Compare scene name against SceneOrder list entry name; 0 on match |

**Guard conditions:** If scene entry pointer at `dword_8AC490 + 396 * *this` is null, skip search and return 0 with this[3] remaining INT_MAX. If `NullCheckWrapper(0)` returns null (SceneOrder list empty), skip search.
