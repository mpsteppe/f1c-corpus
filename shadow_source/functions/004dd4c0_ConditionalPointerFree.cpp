// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD4C0
// Canonical corpus name: sub_4DD4C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DD4C0_004dd4c0.c

void UnknownObject::ConditionalPointerFree()
{
    // Conditional pointer free helper: reads the pointer stored at this+0x8 (this[2]); when non-null it releases the buffer through FreeWrapper_7bcf (0x00587BCF) and returns the original non-null value; when null it returns null without freeing. ABI-legacy labeled Conditional_Pointer_Free; structural twin of EncodedDataWriterWithXOR (004d5900) per prelabel. Called by DualArrayDestructor (0x004DED20).
    // ASSIGNMENT: Load this[2] (offset 0x8) into result; this is the candidate buffer pointer to release. [field:this:0x00000008, source:raw]
    // GUARD: If result (this[2]) is non-null, the buffer is freed. [field:this:0x00000008, source:raw]
    // CALL: Release the buffer via FreeWrapper_7bcf (0x00587BCF). [callee:0x00587BCF, field:this:0x00000008, source:raw]
    // RETURN: Return result: the freed non-null pointer, or null when this[2] was null. [field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   LPVOID sub_4DD4C0(LPVOID *this) {
    //     LPVOID result = this[2];
    //     if (result)
    //       return FreeWrapper_7bcf(this[2]);
    //     return result;
    //   }
    // UNRESOLVED: Concrete type of the object holding the buffer pointer at offset 0x8 is unknown.
    // UNRESOLVED: FreeWrapper_7bcf (0x00587BCF) exact ownership/free semantics not grounded by this packet.
    // UNRESOLVED: Whether the returned pointer value is consumed by DualArrayDestructor (0x004DED20) is outside this function.
}
