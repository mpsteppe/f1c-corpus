// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004651C0
// Canonical corpus name: ResourceManagerFrameCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceManagerFrameCleanup_004651c0.c

void UnknownObject::ResourceManagerFrameCleanup()
{
    // Per-frame resource-manager cleanup. Computes the frame timestep from HighResolutionTimerDelta(*this+1), clamps it to [0.001, 1.0], feeds it through FloatFractionFromInt, and stores the clamped value in the manager at obj+0x60. Then walks and drains two singly linked lists headed at obj+0x6C and obj+0x7C, freeing each node's embedded data pointer when the node's +0x8 flag byte is 0 and always freeing the node itself, and clears the four dwords of each list head block. Zeroes a 104-entry byte array at dword offset 62 (obj+0xF8) with stride 140 dwords, resets the float accumulator at obj+0xE40C to 0.0, and returns the manager pointer. Called by TeamRadioNetworkMessageProcessing (0045F710).
    // CALL: HighResolutionTimerDelta(*this + 1) produces the frame timestep, stored locally [callee:0x00568CF0, field:this:0x00000000, source:raw]
    // GUARD: If the timestep is at least 0.001 it is clamped down to 1.0 when it exceeds 1.0; otherwise it is set to the 0.001 floor [source:raw]
    // CALL: FloatFractionFromInt(*this, timestep) is run in both branches, with the 0.001 floor value in the else path [callee:0x00464EF0, source:raw]
    // ASSIGNMENT: Writes the clamped timestep v12 to obj+0x60 (manager float slot 24) [field:obj:0x00000060, source:raw]
    // GUARD: First list walk runs only while the head pointer at obj+0x6C is non-zero [field:obj:0x0000006C, source:raw]
    // LOOP: Walks the first singly linked list from obj+0x6C; each node carries its next pointer at node+0x4, an embedded data pointer at node+0x0 and a free-data flag byte at node+0x8 [field:obj:0x0000006C, field:*(*(obj+0x6C)+0x4):0x00000004, field:*(obj+0x6C):0x00000000, field:*(obj+0x6C):0x00000008, source:raw]
    // GUARD: For each first-list node, the embedded data pointer is freed only when the node's flag byte at node+0x8 equals 0 (packet guard) [guard:0, field:*(obj+0x6C):0x00000008, source:raw]
    // CALL: FreeWrapper_7bcf releases the node's embedded data pointer (flag permitting) and then always releases the node itself [callee:0x00587BCF, field:*(obj+0x6C):0x00000000, source:raw]
    // ASSIGNMENT: After draining the first list, clears the four head dwords obj+0x6C through obj+0x78 to 0 [field:obj:0x0000006C, field:obj:0x00000070, field:obj:0x00000074, field:obj:0x00000078, source:raw]
    // GUARD: Second list walk runs only while the head pointer at obj+0x7C is non-zero [field:obj:0x0000007C, source:raw]
    // LOOP: Walks the second singly linked list from obj+0x7C with the same node layout (next at node+0x4, embedded data at node+0x0, free flag at node+0x8) [field:obj:0x0000007C, field:*(*(obj+0x7C)+0x4):0x00000004, field:*(obj+0x7C):0x00000000, field:*(obj+0x7C):0x00000008, source:raw]
    // GUARD: For each second-list node, the embedded data pointer is freed only when the node's flag byte at node+0x8 equals 0 (packet guard) [guard:1, field:*(obj+0x7C):0x00000008, source:raw]
    // CALL: FreeWrapper_7bcf releases the second list's node data (flag permitting) and the node itself [callee:0x00587BCF, field:*(obj+0x7C):0x00000000, source:raw]
    // ASSIGNMENT: After draining the second list, clears the four head dwords obj+0x7C through obj+0x88 to 0 [field:obj:0x0000007C, field:obj:0x00000080, field:obj:0x00000084, field:obj:0x00000088, source:raw]
    // LOOP: Zeroes 104 byte-locations of a per-entry flags array starting at dword offset 62 of the manager, stepping 140 dwords per entry [source:raw]
    // ASSIGNMENT: Resets the float accumulator at obj+0xE40C (manager float slot 14595) to 0.0 [field:obj:0x0000E40C, source:raw]
    // RETURN: Returns the manager pointer stored at this+0x0 [field:this:0x00000000, source:raw]
    // CALL: Invoked by TeamRadioNetworkMessageProcessing (0045F710) each frame [caller:0x0045F710, source:raw]

    // Conservative worker pseudocode:
    //   v12 = HighResolutionTimerDelta(*this + 1);
    //   if (v12 < 0.001)
    //       v12 = 0.001;
    //   else if (v12 > 1.0)
    //       v12 = 1.0;
    //   FloatFractionFromInt(*this, v12);
    //   (*this)[24] = v12;
    //   for (node = (*this)[27]; node; node = node[1]) {
    //       if (node_flag(node) == 0)
    //           FreeWrapper_7bcf(node[0]);
    //       FreeWrapper_7bcf(node);
    //   }
    //   (*this)[27] = (*this)[28] = (*this)[29] = (*this)[30] = 0;
    //   for (node = (*this)[31]; node; node = node[1]) {
    //       if (node_flag(node) == 0)
    //           FreeWrapper_7bcf(node[0]);
    //       FreeWrapper_7bcf(node);
    //   }
    //   (*this)[31] = (*this)[32] = (*this)[33] = (*this)[34] = 0;
    //   for (i = 0; i < 14560; i += 140)
    //       byte_at((*this)[i + 62]) = 0;
    //   (*this)[14595] = 0.0;
    //   return *this;
    // UNRESOLVED: The owning class of the object is unknown; caller TeamRadioNetworkMessageProcessing (0045F710) only establishes a per-frame usage context
    // UNRESOLVED: Read-only globals flt_59E43C and flt_59E600 are flagged by packet facts but never appear in the raw decompiled source; likely read indirectly through the timer/fraction helpers, unverifiable from this packet
}
