// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567DB0
// Canonical corpus name: HashTableLookupByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableLookupByName_00567db0.c

void UnknownObject::HashTableLookupByName()
{
    // Name-based hash-table lookup (thiscall on the bucket array). If the caller passes hash -1 the key string is hashed via StringHash; a -1 hash result fails immediately. Otherwise the table entry at index a3 (the hash) is taken as the head of a collision chain and walked by comparing each node's name pointer (node+16, falling back to global byte_5EA438 when null) against the key with sub_588410; the first matching node is returned, and 0 is returned when the chain ends without a match. Canonical and ABI names both describe a hash-table lookup by name.
    // GUARD: When the supplied hash a3 equals -1, compute the hash by calling StringHash(a2); if that also returns -1 the lookup fails immediately with 0. [callee:0x00567D00, source:raw]
    // ASSIGNMENT: v5 = this[v3]: dereference the bucket array at the resolved hash index to obtain the head of the collision chain. [function:0x00567DB0, source:raw]
    // GUARD: If the chain head v5 is null, return 0 (no entry for this hash). [function:0x00567DB0, source:raw]
    // LOOP: Walk the collision chain: read the node name pointer at node+16 (falling back to the global default string byte_5EA438 when null), compare it to the key a2 via sub_588410 and break on a match, then advance to the next node at node+4; a null next node ends the walk with 0. [callee:0x00588410, global:0x005EA438, source:raw]
    // RETURN: Return the matching chain node, or 0 when the hash is -1, the bucket is empty, or the chain is exhausted; the function is invoked by AudioChannelStop to resolve an audio channel by name. [function:0x00567DB0, caller:0x00568210, abi:lead]

    // Conservative worker pseudocode:
    //   hash = (a3 == -1) ? StringHash(a2) : a3;
    //   if (hash == -1) return 0;
    //   node = this[hash];
    //   if (node == 0) return 0;
    //   while (node) {
    //     name = *(node + 16);
    //     if (name == 0) name = byte_5EA438;
    //     if (sub_588410(name, a2) == 0) break;
    //     node = *(node + 4);
    //   }
    //   return node;
    // UNRESOLVED: The exact comparison convention of sub_588410 (whether a 0 return means equal, as assumed here) is not grounded by this packet.
    // UNRESOLVED: The role and content of the fallback global byte_5EA438 used when a node has no name pointer are unknown.
    // UNRESOLVED: The bucket-array layout behind `this` (how many buckets, stride, and how the array is owned) is outside this packet.
}
