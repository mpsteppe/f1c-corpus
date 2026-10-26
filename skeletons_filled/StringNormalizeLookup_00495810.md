## StringNormalizeLookup_00495810 — StringNormalizeHashLookup

**Summary:** Normalizes an input string (via sub_589901), looks it up in a hash table (dword_5CC79C). If not found, constructs a compound key by appending the hash bucket head value and a file-extension byte, then allocates a collision node via CollisionNodeAllocator. Part of the collision/asset name resolution system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverNameStringHandler (00497ec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | First parameter (input string pointer) checked for NULL |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc79c | dword_5CC79C | R | HashTableHead — hash table head pointer for collision/asset name lookup; also used as raw binary data in compound key construction |
| 005cc7a0 | byte_5CC7A0 | R | FileExtSCNByte — single-byte file extension tag (".scn" identifier byte) appended to compound key |
| 007cde00 | unk_7CDE00 | R | Unknown render/data region — possibly a global hash table array or collision bucket storage |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494de0 | CollisionNodeAllocator | Allocate a new collision/asset hash node for the normalized string |
| 00587c20 | sub_587C20 | Hash table lookup: check if normalized string exists in the hash table at dword_5CC79C |
| 00589901 | sub_589901 | String normalization (likely lower/upper-case folding or path separator normalization) |

**Guard conditions:** NULL input → return -1 (BLOCKED). If normalized string IS found in hash table (sub_587C20 returns non-zero), skip compound-key construction and go directly to node allocation.
