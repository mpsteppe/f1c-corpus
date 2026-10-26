// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052DF10
// Canonical corpus name: sub_52DF10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52DF10_0052df10.c

void UnknownObject::CodecTypeDispatchDecoder()
{
    // Codec-type dispatcher: runs a vtable-based precondition check via the object's vtable slot at +8; on non-zero (not ready) it returns -1. Otherwise it dispatches on the codec-type byte at this+0x2490: 1 -> CompressedAudioDecoder(a2), 2 -> TextureDecompression_1250(a2). An unknown type returns 0.
    // ASSIGNMENT: Initialize the default result v3 to 0. [source:raw]
    // CALL: Indirect thiscall through the vtable pointer at this+0x0, invoking the function at vtable offset +8 as a precondition check on this. [field:this:0x00000000, field:obj:0x00000008, source:raw]
    // RETURN: Return -1 when the vtable precondition check returns non-zero (decoder not ready). [source:raw]
    // GUARD: Guard: codec-type byte at this+0x2490 equals 1 (audio codec). [guard:0, field:this:0x00002490]
    // CALL: Dispatch to CompressedAudioDecoder(a2) for codec type 1. [callee:0x0052E6F0]
    // RETURN: Return the result of CompressedAudioDecoder. [callee:0x0052E6F0, source:raw]
    // GUARD: Guard: codec-type byte at this+0x2490 equals 2 (texture codec). [guard:1, field:this:0x00002490]
    // CALL: Dispatch to TextureDecompression_1250(a2) for codec type 2. [callee:0x00531250]
    // RETURN: Return the result of TextureDecompression_1250. [callee:0x00531250, source:raw]
    // RETURN: Return the default result 0 when the codec type matches neither 1 nor 2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_52DF10(_BYTE *this, int a2) {
    //     int result = 0;
    //     if ((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 8))(this)) return -1;
    //     if (this[0x2490] == 1) return CompressedAudioDecoder(a2);
    //     if (this[0x2490] == 2) return TextureDecompression_1250(a2);
    //     return result;
    //   }
    // UNRESOLVED: The object class and the exact precondition checked by the vtable slot at +8 are unknown; owner stays UnknownObject.
    // UNRESOLVED: Meaning of a2 (input data pointer/size) depends on the caller MPEGBuffer context.
}
