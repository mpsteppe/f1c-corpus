// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B4840
// Canonical corpus name: HashTableLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HashTableLookup_004b4840.c

void UnknownObject::HashTableLookup()
{
    // Hash-table-style key lookup on a byte-array object. Row selector a2 addresses a 13-byte-stride bitmap region; the presence bit (a3%8) at this[13*a2 + a3/8 + 1] is tested first and a clear bit returns 0. On a hit, a bucket head is loaded from a 16-byte-stride slot at this[16*(a2+7)] and stored into an adjacent current-pointer slot at +8, then a chain of node pointers is walked comparing each node's low byte (the key) against a3; each step advances via the node's next pointer at +4. On a key match the function writes a secondary flag bit (a3%8) at this[13*a2 + a3/8 + 53] into out-parameter a4 and returns a pointer into the matched node; absence of head, empty node, or end of chain returns 0.
    // CALCULATION: v5 = &this[13*a2 + a3/8]: compute the bitmap row base for row a2 and byte a3/8. [source:raw]
    // GUARD: If the presence bit (a3%8) at v5+1 is clear, return 0: no entry present. [source:raw]
    // CALCULATION: v6 = 16*(a2+7): compute the bucket-slot offset for row a2 in the 16-byte-stride region. [source:raw]
    // ASSIGNMENT: Load the bucket head v7 from this[v6] and store it into the current-pointer slot this[v6+8]. [source:raw]
    // GUARD: If the bucket head v7 is null, return 0. [source:raw]
    // ASSIGNMENT: result = *v7: load the first node pointer from the bucket head. [source:raw]
    // GUARD: If the first node pointer is null, return 0. [source:raw]
    // LOOP: Walk the node chain while the low byte of the current node (*result) does not equal key a3. [source:raw]
    // ASSIGNMENT: Advance the chain: when the current node pointer v10 is nonzero, store node->next (at +4) into the current slot this[v6+8]. [source:raw]
    // GUARD: After advancing, if the new current pointer is null (end of chain without match), return 0. [source:raw]
    // ASSIGNMENT: On key match, write the secondary flag bit (a3%8) at v5+53 into out-parameter a4. [source:raw]
    // RETURN: Return the matched node pointer, or 0 on absence. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_4B4840(BYTE *this, int a2, int a3, BYTE *a4) {
    //     BYTE *bitmap = &this[13 * a2 + a3 / 8];
    //     if (((bitmap[1] >> (a3 % 8)) & 1) == 0) return 0;
    //     DWORD *bucket = (DWORD *)&this[16 * (a2 + 7)];
    //     bucket[2] = bucket[0];
    //     if (!bucket[0]) return 0;
    //     DWORD *node = bucket[0];
    //     if (!node) return 0;
    //     while ((BYTE)*node != a3) {
    //       DWORD *cur = bucket[2];
    //       if (cur) bucket[2] = *(DWORD **)((BYTE *)cur + 4);
    //       node = (DWORD *)bucket[2];
    //       if (!node) return 0;
    //     }
    //     *a4 = (bitmap[53] >> (a3 % 8)) & 1;
    //     return node;
    //   }
    // UNRESOLVED: Owner object and the layout role of the 13-byte (bitmap) vs 16-byte (bucket) regions are unproven.
    // UNRESOLVED: Node layout (key low byte at node[0], next pointer at +4) is derived from the decompiler indexing, not a confirmed struct.
    // UNRESOLVED: Meaning of the secondary flag written to a4 at offset +53 is unknown.
    // UNRESOLVED: a3 serves as both a bitmap bit index and a node key byte; the mapping between the two tables is inferred.
    // UNRESOLVED: High bytes of *node (the value payload alongside the key low byte) are not examined here.
}
