## SortedStringTableBuilder_00423530 — InsertKeyValuePairWithAutoGrow

**Summary:** Inserts a key-value string pair into a table structure. Auto-grows capacity by 128 slots when full, copies/reallocates existing entries, frees old buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_423890 (00423890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Capacity (max number of entries) |
| this | 0x4 | R | — | Count (current number of entries) |
| this | 0x8 | RW | — | Pointer to entries array (each entry = 16 bytes: {char* str1, int val1, char* str2, int val2}) |

**Written-by note (persistence):**
- this 0x0: written when capacity exhausted, grows by 128 unconditionally; external poke would change capacity threshold
- this 0x8: written when buffer reallocated; external poke would corrupt entry pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | Deallocate/free string entry during buffer resize |
| 00566650 | StringCopyWithBufferRealloc | Copy string with reallocation (for entry strings and new key/value) |
| 00587bcf | FreeWrapper_7bcf | Free old entries buffer after reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new entries buffer (16 * new_capacity + 4 bytes) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | > | 0 | Count field — entries exist in current buffer |

**Guard interpretation:** a2 == NULL, a3 == NULL, a2 empty, a3 empty, or a2 == a3: return -1 (blocked). Count (this[1]) < Capacity (this[0]): skip growth path, directly insert new pair. OperatorNewNhMallocWrapper returns NULL: entries pointer set to 0 (data loss). Count > 0: copy old entries before freeing buffer. All guard-passing paths insert key/value strings at end and increment count.
