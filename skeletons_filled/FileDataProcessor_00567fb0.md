## FileDataProcessor_00567fb0 — DataEntryProcessorWithHashIndex

**Summary:** Normalizes key and value strings via helper functions, hashes the key to index into a hash table (max 9 buckets), allocates a 44-byte data entry struct, and inserts it into either a caller-provided linked list (a5) or the hash table indexed by hash value. Handles special case via AudioChannelStop for audio-related entries.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonRacesSectionWriter (004c5ae0), FileSettingsDataLoad (00567bb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004979c0 | Setter | sets value on newly created entry struct |
| 00566650 | StringCopyWithBufferRealloc | copies key/value strings into entry struct |
| 00567900 | StructInitWithConditionalDefaultRead | initializes 44-byte entry struct with defaults or from a5 |
| 005679c0 | StringKeyedLinkedListSearch | searches a5 linked list by key string |
| 00567af0 | sub_567AF0 | normalizes/sanitizes key string argument |
| 00567b00 | sub_567B00 | normalizes/sanitizes value string argument |
| 00567d00 | StringHash | computes hash of normalized key for bucket index |
| 00568210 | AudioChannelStop | checks for special audio-related entry handling |
| 00568220 | HashTableEntrySearch | looks up entry index in hash table |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 44-byte data entry struct |

**Guard conditions:** if a2 (key string) is NULL, returns NULL immediately. If StringHash of key > 8, returns NULL (hash index out of valid bucket range).
