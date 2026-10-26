// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431820
// Canonical corpus name: DynamicsJointCount
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DynamicsJointCount_00431820.c

void UnknownObject::DynamicsJointCount()
{
    // Side-effect-free joint-entry counter. Scans a 64-byte-strided entry array starting at this+0x16CC, counting consecutive entries whose first byte is non-zero, until an empty entry or a cap of seven entries is reached, and returns the count (v1 - 44, in the range 0..7). Called by sub_475A90 (0x00475A90).
    // ASSIGNMENT: Seed the counter v1 = 44 and the element pointer v2 = this + 5836 (this + 0x16CC, first joint entry) before entering the scan. [field:this:0x000016CC, source:raw]
    // LOOP: do-while scan of the 64-byte-strided entry array starting at this+0x16CC, iterating until the counter exceeds 50 (at most seven entries). [field:this:0x000016CC, source:raw]
    // GUARD: Break out of the scan as soon as an entry whose first byte is zero is found (*v2 == 0), treating it as the end of the active entries. [source:raw]
    // CALCULATION: Advance the scan by incrementing the counter (++v1) and stepping the pointer to the next entry (v2 += 64). [source:raw]
    // RETURN: Return v1 - 44, the number of consecutive non-zero entries counted (0..7). [source:raw]
    // CALL: Called by sub_475A90 (0x00475A90) to obtain the count of active joint entries. [caller:0x00475A90, source:raw]

    // Conservative worker pseudocode:
    //   int DynamicsJointCount(char *this) {
    //     int count = 44;
    //     _BYTE *entry = this + 5836;   // 0x16CC
    //     do {
    //       if (!*entry) break;
    //       ++count;
    //       entry += 64;
    //     } while (count <= 50);
    //     return count - 44;
    //   }
    // UNRESOLVED: The layout of each 64-byte joint entry is undefined by this packet; only its first byte is read here.
    // UNRESOLVED: The exact meaning of an 'active' entry (the zero first-byte sentinel) is not defined by this packet.
    // UNRESOLVED: The owner object type is unknown; only the entry array at slot 0x16CC is evidenced.
}
