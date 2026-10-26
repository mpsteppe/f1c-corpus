// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566DB0
// Canonical corpus name: sub_566DB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_566DB0_00566db0.c

void UnknownObject::State_Check_Lookup_Wrapper()
{
    // Read-dispatch wrapper on a stream-like object. When the state flag at offset 0x10 is nonzero, reads a2 bytes directly through AudioStreamBufferRead on the stream handle at offset 0x0. Otherwise it reads through sub_587F64; a nonzero return there signals failure and yields -1, otherwise a2 (the requested read size) is returned.
    // GUARD: Branch on the state flag this[4] (offset 0x10): a nonzero value selects the audio stream buffer read path. [field:this:0x00000010, source:raw]
    // CALL: Read through AudioStreamBufferRead(*this, a2, 0) using the stream handle stored at offset 0x0. [callee:0x00535390, field:this:0x00000000, source:raw]
    // RETURN: Return the result of AudioStreamBufferRead directly. [callee:0x00535390, source:raw]
    // CALL: When the flag is clear, read through sub_587F64(*this, a2, 0) on the same stream handle. [callee:0x00587F64, field:this:0x00000000, source:raw]
    // GUARD: A nonzero return from sub_587F64 indicates read failure. [callee:0x00587F64, source:raw]
    // RETURN: Return -1 when the sub_587F64 read path reports failure. [callee:0x00587F64, source:raw]
    // RETURN: Return a2, the requested read size, when the sub_587F64 read path succeeds. [field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   if (this[4])
    //       return AudioStreamBufferRead(*this, a2, 0);
    //   if (sub_587F64(*this, a2, 0))
    //       return -1;
    //   return a2;
    // UNRESOLVED: The object type behind this is unknown; field this[0] is dereferenced and passed as a stream/file handle to both read paths.
    // UNRESOLVED: The +0x10 flag meaning (audio buffer vs file path) is inferred from the two callees and the structural twin prelabel (ConditionalDispatch_6bd0); not independently confirmed.
    // UNRESOLVED: sub_587F64's exact read semantics are outside this packet.
}
