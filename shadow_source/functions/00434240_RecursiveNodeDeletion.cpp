// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434240
// Canonical corpus name: RecursiveNodeDeletion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveNodeDeletion_00434240.c

void UnknownObject::RecursiveNodeDeletion()
{
    // Destroys a node and its owned data struct. Guarded by the node's flag byte at +8: if set and the node's data pointer at +0 is non-null, resets the data struct via SessionConfigDefaultInit, frees three optional internal pointer fields (at +0, +8, +0x14) and then frees the data struct itself. Returns the flag byte value.
    // ASSIGNMENT: Read the node flag byte at this+8 into the result value. [field:this:0x00000008]
    // GUARD: If the flag byte is zero, return it immediately without touching the data struct. [field:this:0x00000008]
    // ASSIGNMENT: Load the node's data struct pointer from this+0. [field:this:0x00000000]
    // GUARD: If the data struct pointer is null, return the flag value without performing deletion. [field:this:0x00000000]
    // CALL: Reset the data struct to default state via SessionConfigDefaultInit. [callee:0x00432CC0, field:this:0x00000000]
    // GUARD: If the data struct pointer field at +0x14 (v2[5]) is non-null, free it. [field:obj:0x00000014]
    // CALL: Free the data struct pointer field at +0x14 via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000014]
    // GUARD: If the data struct pointer field at +8 (v2[2]) is non-null, free it. [field:obj:0x00000008]
    // CALL: Free the data struct pointer field at +8 via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000008]
    // GUARD: If the data struct pointer field at +0 (v2[0]) is non-null, free it. [field:obj:0x00000000]
    // CALL: Free the data struct pointer field at +0 via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000000]
    // CALL: Free the data struct itself via FreeWrapper_7bcf and return the flag value. [callee:0x00587BCF, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   result = this[8];
    //   if (result) {
    //     v2 = *this;
    //     if (*this) {
    //       SessionConfigDefaultInit(*this);
    //       if (v2[5]) FreeWrapper_7bcf(v2[5]);
    //       if (v2[2]) FreeWrapper_7bcf(v2[2]);
    //       if (v2[0]) FreeWrapper_7bcf(v2[0]);
    //       return FreeWrapper_7bcf(v2);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Node and data struct types are unknown; the three data struct pointer fields at +0, +8 and +0x14 are opaque.
}
