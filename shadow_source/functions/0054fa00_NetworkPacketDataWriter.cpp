// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FA00
// Canonical corpus name: NetworkPacketDataWriter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketDataWriter_0054fa00.c

void UnknownObject::NetworkPacketDataWriter()
{
    // Writes six dwords from a source struct a2 into the entry at index a3 of a packet-buffer array, then marks the entry dirty by setting bit 3 of its flags. The array is reached through a descriptor: this[120] (this+0x1E0) points to a descriptor whose +4 slot holds the element count and +8 slot holds the data pointer. If the data pointer is null or a3 is out of bounds, the write is skipped. Always returns 0.
    // ASSIGNMENT: Load the descriptor pointer v3 = this[120] (this+0x1E0). [field:this:0x000001E0, source:raw]
    // ASSIGNMENT: Load the packet data array pointer v4 = *(v3 + 8) (descriptor data slot, corresponding to this+0x1E8). [field:this:0x000001E8, source:raw]
    // GUARD: Skip the write when the data pointer is null or the slot index a3 is >= the element count *(v3 + 4) (descriptor count slot, corresponding to this+0x1E4). [field:this:0x000001E4, source:raw]
    // CALCULATION: Compute the target entry pointer v5 = v4 + 116 * a3 (fixed element stride of 116 bytes). [source:raw]
    // ASSIGNMENT: Copy six dwords from source a2 into the entry: v5[1..3] = a2[0..2] and v5[7..9] = a2[3..5]. [source:raw]
    // ASSIGNMENT: Mark the entry dirty by setting bit 3 of its flags word: *v5 |= 8u. [source:raw]
    // RETURN: Always returns 0. [source:raw]
    // CALL: Called from VehiclePhysicsVelocityAngularVelocityIntegrator, VehicleOrientationMatrixConstruction and VehicleBodyToWheelContactDistanceComputation to publish per-frame state into the packet buffer. [caller:0x00459AE0, caller:0x0045B050, caller:0x004E9A40, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54FA00(unsigned int *this, unsigned int *src, int index) {
    //     unsigned int *desc = (unsigned int *)this[120];
    //     unsigned int *data = *(unsigned int **)(desc + 2);
    //     if (data && index < desc[1]) {
    //       unsigned int *entry = data + 29 * index;
    //       entry[1] = src[0]; entry[2] = src[1]; entry[3] = src[2];
    //       entry[7] = src[3]; entry[8] = src[4]; entry[9] = src[5];
    //       entry[0] |= 8;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Identity and type of the descriptor object at this+0x1E0 and of the packet array entries is unknown.
    // UNRESOLVED: Meaning of the six copied dwords and of the dirty bit 3 depends on the network/state protocol the buffer implements.
    // UNRESOLVED: Element stride of 116 bytes is fixed by the accessed layout, not separately evidenced.
}
