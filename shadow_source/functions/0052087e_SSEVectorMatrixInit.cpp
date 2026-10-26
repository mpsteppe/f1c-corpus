// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052087E
// Canonical corpus name: SSEVectorMatrixInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEVectorMatrixInit_0052087e.c

void UnknownObject::SSEVectorMatrixInit()
{
    // Initializes a 52-byte matrix/struct at a1 from SSE constants and the __m128 result of EmptyStub_8bd0. Row 0 is a fixed constant (xmmword_8D61D0); the low component of xmmword_8D61C0 is placed at +0x10 and +0x2C, the full vector at +0x30; partial stores from the EmptyStub result and an XOR of its shuffled value with xmmword_8D61B0 fill +0x14/+0x1C/+0x24. Returns a1.
    // CALL: Call EmptyStub_8bd0 with four arguments (Hex-Rays frame slots v7-v10 at ebp-44h..ebp-38h); its __m128 return is the base for the shuffle/XOR computation. [callee:0x00528BD0, source:raw, function:0x0052087E]
    // ASSIGNMENT: Write the 16-byte constant xmmword_8D61D0 to a1+0 as the output matrix row 0. [field:this:0x00000000, global:0x008D61D0]
    // ASSIGNMENT: Write the low dword component of xmmword_8D61C0 to a1+16. [field:this:0x00000010, global:0x008D61C0]
    // ASSIGNMENT: Store the low 8 bytes (two floats) of the EmptyStub result vector to a1+20. [source:raw]
    // ASSIGNMENT: Store the low 8 bytes of xmmword_8D61C0 to a1+28. [global:0x008D61C0, source:raw]
    // ASSIGNMENT: Write the low dword component of xmmword_8D61C0 to a1+44 (0x2C). [field:this:0x0000002C, global:0x008D61C0]
    // CALCULATION: Store the low 8 bytes of shuffle(v5, 0x11) XOR xmmword_8D61B0 to a1+36 (0x24). [global:0x008D61B0, source:raw]
    // ASSIGNMENT: Write the full __m128 value of xmmword_8D61C0 to a1+48 (0x30) as the output matrix row 3. [field:this:0x00000030, global:0x008D61C0]
    // RETURN: Return a1 (result register set to the output pointer). [source:raw, function:0x0052087E]

    // Conservative worker pseudocode:
    //   matrix[0..15] = xmmword_8D61D0;
    //   dword(matrix+16) = low_dword(xmmword_8D61C0);
    //   store_low8(matrix+20, stub_result);
    //   store_low8(matrix+28, xmmword_8D61C0);
    //   dword(matrix+44) = low_dword(xmmword_8D61C0);
    //   store_low8(matrix+36, shuffle(stub_result, 0x11) ^ xmmword_8D61B0);
    //   vector(matrix+48) = xmmword_8D61C0;
    //   return matrix;
    // UNRESOLVED: The four arguments passed to EmptyStub_8bd0 (Hex-Rays v7-v10) are read from an uninitialized-looking stack window below the frame; true call arguments unknown.
    // UNRESOLVED: Stores at a1+20 (0x14), a1+28 (0x1C) and a1+36 (0x24) have no packet field evidence_ref entries.
    // UNRESOLVED: Parameter a2 is never referenced in the body; its role is unknown.
    // UNRESOLVED: Output object class is unidentified (owner UnknownObject); a 52-byte matrix or transform struct is implied but not proven.
}
