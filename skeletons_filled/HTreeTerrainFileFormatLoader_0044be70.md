## HTreeTerrainFileFormatLoader_0044be70 — TerrainHTreeFileLoader

**Summary:** Opens and validates a terrain H-tree file by checking version string and header fields, allocates and populates collision object arrays and tree node buffer, then deserializes collision tree structure from file data.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTrackFileLoader (0044c0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Pointer to allocated main collision data buffer (92 bytes per object) |
| this | 0x4 | RW | — | Pointer to initialized collision object array (16 bytes per node) |

**Written-by note (persistence):**
- this 0x0: written once during load to store main data allocation — persists until freed externally
- this 0x4: written once during load to store collision object array — persists until freed externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c445c | aVer006ThisFile | R | StrFileVersion [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044a430 | CollisionObjectInit | Initializes one collision object structure (zeroes or sets defaults) |
| 0044a700 | CollisionTreeNodeDeserializer | Deserializes tree nodes from file into collision tree data structure |
| 005668b0 | ZeroInitSmallStruct | Zero-initializes cleanup tracking structure on stack |
| 005668d0 | SubCallWithConditionalFieldFree | Conditional cleanup/free dispatch based on cleanup struct field flags |
| 00566b20 | AudioStreamOpen | Opens file for reading via audio stream abstraction |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | Closes file handle with conditional dispatch on cleanup flags |
| 00566c00 | FileWriteWithBackendDispatch | Reads data from file via backend dispatch (returns bytes read) |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper around free |
| 00587c03 | OperatorNewNhMallocWrapper | Memory allocation wrapper around new/malloc |

**Guard conditions:** 
1. `v20[0] != 0` (file open success) — PASS: continue reading. BLOCKED: goto error return -1.
2. Each `FileWriteWithBackendDispatch(...)` return must equal expected size — any mismatch: goto error.
3. `strcmp(version_string, aVer006ThisFile) == 0` — PASS: version matches, continue. BLOCKED: version mismatch, goto error.
4. `v6 != NULL` (object array allocation) — PASS: initialize objects. BLOCKED: pointer stays null, continue.
5. `v5 - 1 >= 0` (object count valid) — PASS: init each CollisionObject. BLOCKED: no objects.
6. `v16 > 0` (tree node count) — PASS: read nodes from file. BLOCKED: skip node reading.
7. `v17 > 0` (collision object count for deserialization) — PASS: call CollisionTreeNodeDeserializer. BLOCKED: skip.
8. `CollisionTreeNodeDeserializer(...)` returns 0 — PASS: success, continue to cleanup. BLOCKED: non-zero, goto error cleanup.
