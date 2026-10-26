## LinkedListIndexedAccessor_f590_0048f590 — LinkedListElementByIndex

**Summary:** Accesses the Nth element in a linked list by index: validates index against list count, traverses list nodes starting from head pointer (offset 0xF0) using next pointers (offset +4), returns data pointer of matched node or 0 if out of bounds or not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FrontendScreenLoadingDisplayHandler (00476250), UIRenderUpdateChain (00476d70), SeasonSceneNameAccessor (00477640), TrackSceneConfigLoader (00477680), GameContentFilterCheck (00477aa0), ProfileIconPathSetter (00478390), DriverCareerStatsHTMLWriter (0047dd10), sub_47E0A0 (0047e0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF4 | R | — | linked list tail pointer |
| this | 0xF8 | R | — | linked list cursor pointer |
| this | 0xFC | R | — | linked list element count |
| this | 0x174 | R | — | zero-based index to access |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- if (index < 0 OR index >= list count) → BLOCKED (return 0, out of bounds)
- if (index > 0) traverse list nodes via next (+4) pointers:
  - if traversal ends before index exhausted → BLOCKED (return 0, list shorter than index)
- if (resulting node is null) → BLOCKED (return 0)
- PASS: return first dword of matched node (node data pointer)
