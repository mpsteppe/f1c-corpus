// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FA90
// Canonical corpus name: NetworkPacketDataReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketDataReader_0054fa90.c

void UnknownObject::NetworkPacketDataReader()
{
    // Reads a fixed-size payload (0x40 bytes) out of a packet buffer for a caller-supplied slot index. Loads a packet handle from this[0x1E0], rejects a null handle, an out-of-range index, or an entry whose present flag (bit 0) is clear, then copies the 64-byte payload from the matched 116-byte entry into the output buffer and returns 1 (success) or 0. Structural twin of the NetworkPacketDataWriter cluster (0054fa00). Callers: VehiclePhysicsVelocityAngularVelocityIntegrator (00459AE0), CollisionDetectionSystem (004EA970).
    // CALCULATION: Compute packet element address = data pointer at handle+8 + 116 * a2, using the 116-byte per-entry stride [source:raw]
    // GUARD: Load packet handle from this[0x1E0]; if null, return 0 [field:this:0x000001E0]
    // GUARD: If requested index a2 is >= the packet entry count stored at handle+4, return 0 [source:raw, field:this:0x000001E0]
    // GUARD: If the entry's flag byte at element+0 has bit 0 clear, return 0 (entry not present/finalized) [source:raw]
    // CALL: qmemcpy copy 0x40 bytes from element offset +52 into the caller's output buffer a3 [source:raw]
    // RETURN: Return 1 on successful payload copy, 0 on null handle, out-of-range index, or cleared present flag [source:raw, function:0x0054FA90]
    // CALL: Invoked by VehiclePhysicsVelocityAngularVelocityIntegrator (00459AE0) and CollisionDetectionSystem (004EA970) to fetch a packet payload by index [caller:0x00459AE0, caller:0x004EA970, source:raw]

    // Conservative worker pseudocode:
    //   handle = this[120];
    //   if (!handle) return 0;
    //   if (a2 >= *(int*)(handle + 4)) return 0;
    //   entry = (byte*)(*(int*)(handle + 8) + 116 * a2);
    //   if (!(entry[0] & 1)) return 0;
    //   memcpy(a3, entry + 52, 0x40);
    //   return 1;
    // UNRESOLVED: Semantics of this[0x1E4] and this[0x1E8] are not exercised in the raw decompiled source; their roles are unverified
    // UNRESOLVED: Meaning of flag bit 0 (present/finalized) and the 116-byte entry layout beyond offset +52 are inferred from the raw source only
    // UNRESOLVED: The 0x40-byte payload type and the packet buffer ownership model are not established
}
