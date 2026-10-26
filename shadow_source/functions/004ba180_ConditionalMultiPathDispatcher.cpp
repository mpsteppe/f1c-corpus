// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA180
// Canonical corpus name: ConditionalMultiPathDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalMultiPathDispatcher_004ba180.c

void UnknownObject::ConditionalMultiPathDispatcher()
{
    // Key-priority multi-path dispatcher. Early-exits unless the sentinel at this[0] equals 2. Otherwise dispatches between the pit-service steering-animation path (when KeyPriorityChain returns 2) and an alternative handler sub_4B8C40, unless a packed flag read at this + 2 is already set. After the dispatch, if a float read from the sub-struct differs from the value at offset 3900 of the target, or the byte flag at offset 3968 is non-zero, processes driver entries, delegates, forwards float values through sub_4B9000 and sub_4B9B80, and clears the flag at offset 3968.
    // GUARD: Guard: *this != (float*)2 causes an immediate return (type/sentinel check on field 0x0). [guard:0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set v4 = this + 2, the pointer to the sub-data struct (this + 0x8). [field:this:0x00000008, source:raw]
    // GUARD: If PackedFlagRead_9a00(this + 2) is set, skip the key-priority dispatch and jump to the shared tail. [callee:0x004B9A00, source:raw]
    // CALL: Call KeyPriorityChain() and store the result as v5. [callee:0x004B8BD0, source:raw]
    // GUARD: Branch on v5: value 2 selects the steering-animation path, any other value the alternative-handler path. [source:raw]
    // CALL: On the steering path, call GuardedVirtualCall(1065353216) with the float-1.0 sentinel integer. [callee:0x004C8DC0, source:raw]
    // CALL: On the steering path, call PitServiceSteeringAnimationStep(v4). [callee:0x004B9E40, source:raw]
    // CALL: On the alternative path, call sub_4B8C40(*v4, *(float*)&v5, 1). [callee:0x004B8C40, source:raw]
    // CALCULATION: Read a float from *v6 via FloatGetter into v3 (v6 aliases the sub-struct pointer v4). [source:raw]
    // GUARD: Guard: if the float at v2 + 3900 differs from v3 OR the byte at v2 + 3968 is non-zero, run the driver-entry processing block. [field:*(this+0x8):0x00000F80, source:raw]
    // CALL: Call ProcessDriverEntries(v2) to update driver entries. [source:raw]
    // CALL: Call Delegation(v1) to hand the sub-struct to the selected handler. [source:raw]
    // CALL: Call sub_4B9000((char*)*v1, v3) forwarding the previously read float. [source:raw]
    // CALL: Call sub_4B9B80(v1, FloatGetter(*v1)) forwarding a freshly read float. [source:raw]
    // STATE_TRANSITION: Clear the byte processing flag at (*v1) + 3968 to 0. [field:*(this+0x8):0x00000F80, source:raw]

    // Conservative worker pseudocode:
    //   void ConditionalMultiPathDispatcher(float** this_) {
    //     if (*this_ != (float*)2) return;
    //     float** v4 = this_ + 2;
    //     if (!PackedFlagRead_9a00(this_ + 2)) {
    //       int v5 = KeyPriorityChain();
    //       if (v5 == 2) {
    //         GuardedVirtualCall(1065353216);
    //         PitServiceSteeringAnimationStep(v4);
    //       } else {
    //         sub_4B8C40(*v4, *(float*)&v5, 1);
    //       }
    //     }
    //     float v3 = FloatGetter(*v4);
    //     if (*(float*)(v2 + 3900) != v3 || *(_BYTE*)(v2 + 3968)) {
    //       ProcessDriverEntries(v2);
    //       Delegation(v4);
    //       sub_4B9000((char*)*v4, v3);
    //       sub_4B9B80(v4, FloatGetter(*v4));
    //       *((_BYTE*)*v4 + 3968) = 0;
    //     }
    //   }
    // UNRESOLVED: byte_8AC494 is listed in the packet globals but does not appear in the raw source body; its purpose here is unknown.
    // UNRESOLVED: FloatGetter, ProcessDriverEntries, Delegation, sub_4B9000 and sub_4B9B80 are called by the raw source but have no evidence refs in this packet, so their addresses are unknown.
    // UNRESOLVED: The target base v2 (register ecx) is not statically resolved; the float comparison offset 3900 has no packet field evidence ref.
    // UNRESOLVED: The FloatGetter return is the value stored, forwarded and compared against the float at offset 3900.
}
