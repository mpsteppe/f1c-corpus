## ShortComputation_5050_00405050 — ResourceIDStringResolver

**Summary:** Resolves a string parameter to a numeric resource ID: tries direct name lookup first, then attempts prefix-based extraction or numeric string formatting, writing the result to an output parameter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be820 | asc_5BE820 | R | AscStringConst80 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | ensures static resource manager singleton is initialized |
| 00407e40 | ResourceNodeLookupByStringOrID | looks up resource node by string ID value |
| 00407f10 | ResourceIDLookupByNameString | looks up numeric resource ID by name string |
| 00566810 | sub_566810 | checks if string starts with a given prefix |
| 00587f59 | SingleFunctionCallWrapper_7f59 | converts numeric substring to integer |
| 00595ae2 | StringFormatWith0x40Size | formats numeric string to resource ID with size parameters |

**Guard conditions:** Checks if ResourceIDLookupByNameString returns -1. PASSES (not -1): direct name match found, stores ID. BLOCKED (-1): attempts fallback paths — prefix extraction with asc_5BE820 prefix match (length >= 5) or numeric string formatting.
