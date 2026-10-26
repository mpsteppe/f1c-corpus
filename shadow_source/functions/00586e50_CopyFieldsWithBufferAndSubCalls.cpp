// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586E50
// Canonical corpus name: ShortComputation_6e50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6e50_00586e50.c

void UnknownObject::CopyFieldsWithBufferAndSubCalls()
{
    // Partial struct copy from input a2 to receiver this: copies two leading DWORDs (offsets 0x0, 0x4) and two trailing DWORDs (offsets 0x4C, 0x50), and between them invokes BufferWriteWithParams on the buffer sub-struct at a2+2 and sub_59B3B0 on the sub-struct at a2+5. Returns this. Invoked by sub_5853B0 (005853B0).
    // ASSIGNMENT: Copies the first source DWORD: *this = *a2 (receiver offset 0x0) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copies the second source DWORD: this[1] = a2[1] (receiver offset 0x4) [field:this:0x00000004, source:raw]
    // CALL: BufferWriteWithParams called on a2 + 2 (buffer sub-struct at byte offset 0x8), writing buffer data [callee:0x00587620, source:raw]
    // CALL: sub_59B3B0 called on a2 + 5 (sub-struct at byte offset 0x14) to process its fields [callee:0x0059B3B0, source:raw]
    // ASSIGNMENT: Copies the twentieth source DWORD: this[19] = a2[19] (receiver offset 0x4C) [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Copies the twenty-first source DWORD: this[20] = a2[20] (receiver offset 0x50) [field:this:0x00000050, source:raw]
    // RETURN: Returns the receiver this pointer as result [source:raw, function:0x00586E50]
    // CALL: Invoked by sub_5853B0 (005853B0) as a partial struct-copy / initializer step [caller:0x005853B0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x0/4] = a2[0x0/4];
    //   this[0x4/4] = a2[0x4/4];
    //   BufferWriteWithParams(a2 + 2);
    //   sub_59B3B0(a2 + 5);
    //   this[0x4C/4] = a2[0x4C/4];
    //   this[0x50/4] = a2[0x50/4];
    //   return this;
    // UNRESOLVED: The sub-structs at a2 + 2 (buffer) and a2 + 5 are written entirely through the two callees; their element layout is not defined by this packet
    // UNRESOLVED: The receiver and source types are unknown; the ABI entry only records the thiscall copy-assignment shape
    // UNRESOLVED: The middle region between offset 0x4 and 0x4C is left untouched by this function
}
