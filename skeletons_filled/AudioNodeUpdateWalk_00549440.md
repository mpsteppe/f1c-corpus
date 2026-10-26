## AudioNodeUpdateWalk_00549440 — Walk audio node list and resolve dictionary references

**Summary:** Walks linked list of audio nodes starting at this+0xFC, following next pointers at node+0x14. For each node, calls StringLookupInLinkedDictionary and stores resolved value at node+0x10. Called during audio engine initialization to map string names to dictionary entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioEngineInitialization (00546010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x110) | 0x10 | RW | — | Dictionary lookup result stored per audio node |
| *(this+0x110) | 0x14 | R | — | Next pointer linking audio nodes in list |
| this | 0xFC | R | — | Head of audio node linked list |

**Written-by note (persistence):**
- *(this+0x110) 0x10: written once per node during walk; overwritten each time function runs

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054a2d0 | StringLookupInLinkedDictionary | Resolve audio node string name to dictionary entry pointer/ID |

**Guard conditions:** If `this[0xFC]` (head pointer) is null → loop body never executes, function is no-op. Non-null head PASSES: walk continues via node+0x14 next pointer until null terminator.
