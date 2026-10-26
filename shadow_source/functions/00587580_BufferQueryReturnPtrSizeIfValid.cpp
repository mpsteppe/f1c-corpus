// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587580
// Canonical corpus name: BufferQueryReturnPtrSizeIfValid
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferQueryReturnPtrSizeIfValid_00587580.c

void UnknownObject::BufferQueryReturnPtrSizeIfValid()
{
    // Queries a buffer descriptor: if the capacity/validity field this+0x4 is greater than zero, writes the buffer data pointer (this+0x0) into output a2 and the stored size (this+0x8) into output a3, returning 1. Otherwise zeroes both outputs and returns 0. Used by memory-copy, decompression and struct-parse paths.
    // GUARD: The query succeeds only while the capacity/validity field this+0x4 is greater than zero. [guard:0, field:this:0x00000004, source:raw]
    // ASSIGNMENT: On success, writes the buffer data pointer at this+0x0 into the output parameter a2. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: On success, writes the stored size at this+0x8 into the output parameter a3. [field:this:0x00000008, source:raw]
    // RETURN: Returns 1 to signal that the buffer descriptor was valid and outputs were populated. [source:raw]
    // ASSIGNMENT: On failure, zeroes both output parameters a2 and a3. [source:raw]
    // RETURN: Returns 0 to signal that the buffer descriptor was invalid. [source:raw]
    // CALL: Consumed by StructuredMemoryCopyWithHeaderPrepend, BoundedMemoryCopyWithSizeValidation, sub_587120, DecompressionDecode and StructInitParse as the buffer validity/query helper. [caller:0x0057D5D0, caller:0x00586A10, caller:0x00587120, caller:0x00587260, caller:0x00587490, source:raw]

    // Conservative worker pseudocode:
    //   char BufferQueryReturnPtrSizeIfValid(DWORD* this, DWORD* outPtr, DWORD* outSize) {
    //     if (this[1] > 0) {
    //       *outPtr = this[0];
    //       *outSize = this[2];
    //       return 1;
    //     }
    //     *outPtr = 0;
    //     *outSize = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The owning class of the buffer descriptor (this+0x0 data pointer, this+0x4 capacity flag, this+0x8 stored size) is unknown.
    // UNRESOLVED: Whether this+0x4 is a byte count or a validity flag is not established; only the >0 comparison is deterministic.
    // UNRESOLVED: The function has no callees, so the descriptor is consumed by callers but never produced here.
}
