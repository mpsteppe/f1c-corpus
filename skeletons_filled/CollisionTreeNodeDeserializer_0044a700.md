## CollisionTreeNodeDeserializer_0044a700 — Recursive collision tree node deserializer from stream

**Summary:** Deserializes a collision tree node from a file read stream. Reads node type byte: internal nodes (0-1) read a subtype byte and recurse into two children; leaf nodes (-1 = single, -2 = pair) allocate vertex storage and read indexed vertex data. Allocates output buffer space from arena pointers in v2.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HTreeTerrainFileFormatLoader (0044be70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Node type: 0/1 (internal with children), -1 (single leaf), -2 (pair leaf) |
| this | 0xA | RW | — | Internal node subtype/byte (unused for leaf nodes) |
| this | 0xC | RW | — | Output pointer: for internal nodes points to 16-byte child entries; for leaves points to 92-byte vertex data |

**Written-by note (persistence):**
- this 0x8: Written once during deserialization
- this 0xA: Written for internal nodes
- this 0xC: Written with arena-allocated pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00449f60 | IndexedVertexLookupFromStream | Reads and resolves indexed vertex data from stream into 92-byte vertex structure |
| 0044a700 | CollisionTreeNodeDeserializer | Recursive self-call for internal node children |
| 00566c00 | FileWriteWithBackendDispatch | Reads bytes from file stream (despite name, used for read) |

**Guard conditions:** File read failures (return != expected byte count) → return -1. Node type (char)a2 <= -3 (values -3 through -128) → invalid, return -1. Node type >= 2 → invalid, return -1. For leaf nodes: v8 >= v7 (all vertices read) → return 0 success. IndexedVertexLookupFromStream failure → return -1.
