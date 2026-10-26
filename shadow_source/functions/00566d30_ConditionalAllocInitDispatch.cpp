// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566D30
// Canonical corpus name: ConditionalAllocInitDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalAllocInitDispatch_00566d30.c

void UnknownObject::ConditionalAllocInitDispatch()
{
    // Branch dispatch that selects one of two stream read/init routines based on the dword at this+0x10 (this[4]). When it is non-zero, AudioStreamBufferRead(*this, 0, 0) is used; otherwise sub_587F64(*this, 0, 0). Returns the boolean result of the selected call comparing to 0.
    // GUARD: Branch on the dword at this+0x10 (this[4]): if non-zero take the AudioStreamBufferRead path, else the sub_587F64 path. [field:this:0x00000010, source:raw]
    // CALL: Call AudioStreamBufferRead(*this, 0, 0) using the stream handle at this+0x0 and return whether it equals 0. [callee:0x00535390, field:this:0x00000000, source:raw]
    // CALL: Call sub_587F64(*this, 0, 0) using the stream handle at this+0x0 and return whether it equals 0. [callee:0x00587F64, field:this:0x00000000, source:raw]
    // RETURN: Return the boolean (== 0) outcome of whichever routine was selected. [source:raw]

    // Conservative worker pseudocode:
    //   if (this[4] != 0)
    //     return AudioStreamBufferRead(this[0], 0, 0) == 0;
    //   return sub_587F64(this[0], 0, 0) == 0;
    // UNRESOLVED: sub_587F64 is unidentified; its role as the alternate read/init path is inferred from the parallel call shape and the cluster_twin note pointing at 00566bd0.
    // UNRESOLVED: The meaning of the discriminator at this+0x10 (allocated-vs-not or mode flag) and the object owning these fields is unproven.
}
