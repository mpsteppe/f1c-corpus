// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057B9F0
// Canonical corpus name: Copy4DwordsStructToStruct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Copy4DwordsStructToStruct_0057b9f0.c

void UnknownObject::CopyStructDwords()
{
    // Copies four consecutive 32-bit words from this (offsets 0x0, 0x4, 0x8, 0xC) to the destination pointer a2, then returns a2. A plain 16-byte struct copy with no arithmetic, branching, globals or callees. Structural twin of F_4x4MatrixMultiply_ef88 (0055ef88) per cluster prelabel. Heavily used by the network layer: called by sub_57CB50, UDPSocketBind (0057E860), NetworkGetLocalIP (0057E8D0), NetworkReceivePacket (0057E940), NetworkMessageQueueDequeue (0057EA30), NetworkPacketSend_ead0 (0057EAD0), NetworkThreadConnectionCleanup (0057EDD0), NetworkPacketSend_0c10 (00580C10) and sub_5813E0.
    // ASSIGNMENT: Copies dword at this+0x0 to a2+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copies dword at this+0x4 to a2+0x4 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Copies dword at this+0x8 to a2+0x8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Copies dword at this+0xC to a2+0xC [field:this:0x0000000C, source:raw]
    // RETURN: Returns the destination pointer a2 [source:raw, function:0x0057B9F0]
    // CALL: Invoked by the network packet layer (UDPSocketBind, NetworkGetLocalIP, NetworkReceivePacket, NetworkMessageQueueDequeue, NetworkPacketSend variants, NetworkThreadConnectionCleanup, sub_57CB50, sub_5813E0) [caller:0x0057CB50, caller:0x0057E860, caller:0x0057E8D0, caller:0x0057E940, caller:0x0057EA30, caller:0x0057EAD0, caller:0x0057EDD0, caller:0x00580C10, caller:0x005813E0]

    // Conservative worker pseudocode:
    //   a2[0] = this[0];
    //   a2[1] = this[1];
    //   a2[2] = this[2];
    //   a2[3] = this[3];
    //   return a2;
    // UNRESOLVED: The semantic meaning of the copied four-dword block depends on the caller objects; this is a raw struct copy with no per-field meaning visible
    // UNRESOLVED: Whether this and a2 can alias is not established by the raw source
}
