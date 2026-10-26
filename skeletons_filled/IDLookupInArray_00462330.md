## IDLookupInArray_00462330 — DriverIDArrayIndexLookup

**Summary:** Queries a COM interface for a target ID, then searches a 104-entry DWORD array at this+0x3E18 for a match, returning the index or -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3E18 | R | — | Start of the 104-entry DWORD ID array to search |
| obj | 0x3FB8 | R | — | COM interface pointer for ID query |
| this | 0x0 | R | — | This pointer dereference |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a810 | SingleFunctionCallWrapper_a810 | Query COM object for target ID value |

**Guard conditions:** Returns -1 when no match found in array (after scanning all 104 entries).
