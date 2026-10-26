// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567FB0
// Canonical corpus name: FileDataProcessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileDataProcessor_00567fb0.c

void UnknownObject::InsertKeyedDataEntry()
{
    // Normalizes a key/value pair into local buffers, hashes the normalized key to select one of up to nine hash buckets, allocates and initializes a 44-byte data entry, copies both strings into it, and inserts the entry either into a caller-provided linked list (a5) or into the hash table indexed by the hash, with a special channel chain for audio-related keys. Returns the inserted entry pointer, or null when the key is null or the hash is out of the valid bucket range.
    // GUARD: If the key pointer a2 is null, return null immediately. [source:raw]
    // ASSIGNMENT: Initialize two zero-filled local 256-byte buffers, seeding each first byte from byte_5EA438. [source:raw, global:0x005EA438]
    // CALL: Normalize the key string a2 into buffer v19 via sub_567AF0. [callee:0x00567AF0]
    // CALL: Normalize the value string a3 into buffer v22 via sub_567B00. [callee:0x00567B00]
    // CALL: Compute StringHash of the normalized key and store it as the bucket index. [callee:0x00567D00]
    // GUARD: If the hash is greater than 8, return null (bucket index out of the valid 0..8 range). [source:raw]
    // CALL: Allocate a 44-byte data entry via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // CALL: Initialize the new entry via StructInitWithConditionalDefaultRead, seeded from the caller container a5 when present. [callee:0x00567900]
    // CALL: When no caller list is provided, look up the hash-table entry index with HashTableEntrySearch and store it into the entry via Setter. [callee:0x00568220, callee:0x004979C0]
    // CALL: Copy the normalized key string into the entry at dword index 4 via StringCopyWithBufferRealloc. [callee:0x00566650]
    // CALL: If the normalized value string is non-empty, copy it into the entry at dword index 6 via StringCopyWithBufferRealloc. [callee:0x00566650]
    // CALL: When a caller list is present, search it for an existing node with the same normalized key via StringKeyedLinkedListSearch. [callee:0x005679C0]
    // ASSIGNMENT: Caller-list path with a key match: walk to the tail of the matched node's chain (field index 3) and append the entry, linking its back pointer at field index 10. [source:raw]
    // ASSIGNMENT: Caller-list path with no key match: walk to the tail of the list head chain (offset +4) and append the entry, linking its back pointer at field index 9, or make it the head when the chain is empty. [source:raw]
    // CALL: Hash-table path: classify the normalized key via AudioChannelStop to select the audio channel chain. [callee:0x00568210]
    // ASSIGNMENT: Non-audio hash-table path: insert the entry into the bucket this[hash], walking the +4 chain and linking the back pointer at field index 9. [source:raw]
    // ASSIGNMENT: Audio path: append the entry to the channel chain at offset +12 and link the back pointer at field index 10. [source:raw]
    // RETURN: Return the inserted entry pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *insert(_DWORD *hashTable, int key, int value, int tableKey, _DWORD *list) {
    //       char keyBuf[256]; char valBuf[256];
    //       seed_default(keyBuf); seed_default(valBuf);   // first byte from byte_5EA438, rest zeroed
    //       if (!key) return 0;
    //       normalize_key(key, keyBuf);
    //       normalize_value(value, valBuf);
    //       unsigned hash = StringHash(keyBuf);
    //       if (hash > 8) return 0;
    //       _DWORD *entry = OperatorNewNhMallocWrapper(44);
    //       if (entry) entry = StructInitWithConditionalDefaultRead(entry, list);
    //       if (!list) Setter(entry, HashTableEntrySearch(tableKey));
    //       StringCopyWithBufferRealloc(entry + 4, keyBuf);
    //       if (strlen(valBuf)) StringCopyWithBufferRealloc(entry + 6, valBuf);
    //       if (list) { append_to_list(list, keyBuf, entry); return entry; }
    //       if (AudioChannelStop(keyBuf)) append_to_chain(entry, 12, 10);
    //       else append_to_chain_bucket(hashTable[hash], entry);
    //       return entry;
    //   }
    // UNRESOLVED: Semantics of the caller-provided container a5 and the distinction between its +4 head chain and the matched node's field[3] chain.
    // UNRESOLVED: Which keys classify as audio via AudioChannelStop and what the +12 channel chain represents.
    // UNRESOLVED: The purpose of HashTableEntrySearch(a4)/Setter and how tableKey relates to the hash bucket.
    // UNRESOLVED: The distinct roles of the two back-link fields (field index 9 vs field index 10).
}
