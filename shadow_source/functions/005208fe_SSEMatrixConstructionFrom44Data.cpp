// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005208FE
// Canonical corpus name: SSEMatrixConstructionFrom44Data
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEMatrixConstructionFrom44Data_005208fe.c

void UnknownObject::SSEMatrixConstructionFrom44Data()
{
    // Builds a 4x4 matrix at output a1 from four packed input dwords (v6..v9) fed through EmptyStub_8bd0. Row 0 is the masked/shuffled result of AND with xmmword_8D6210 XOR xmmword_8D6200; row 1 is the xmmword_8D61F0 constant; row 2 is a re-shuffle of the masked vector; row 3 is the xmmword_8D61E0 constant. SSE math-library helper.
    // CALL: Invoke EmptyStub_8bd0 with the four input dwords to obtain a packed vector [callee:0x00528BD0, source:raw]
    // CALCULATION: Broadcast the first component of the packed vector and AND it against the xmmword_8D6210 mask [global:0x008D6210, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store row 0 at offset 0: XOR the xmmword_8D6200 constant with the masked vector [global:0x008D6200, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store row 1 at offset 16 from the xmmword_8D61F0 constant [global:0x008D61F0, field:this:0x00000010, source:raw]
    // CALCULATION: Re-shuffle the masked vector into the row-2 component order [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store row 2 at offset 32 from the shuffled masked vector [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Store row 3 at offset 48 from the xmmword_8D61E0 constant [global:0x008D61E0, field:this:0x00000030, source:raw]
    // RETURN: Return the output matrix base a1 [function:0x005208FE, source:raw]

    // Conservative worker pseudocode:
    //   v2 = EmptyStub_8bd0(v6, v7, v8, v9);
    //   v3 = (broadcast first component of v2) AND xmmword_8D6210;
    //   row0 = xmmword_8D6200 XOR v3;
    //   row1 = xmmword_8D61F0;
    //   row2 = shuffle(v3);
    //   row3 = xmmword_8D61E0;
    //   store rows 0..3 at a1+0, a1+16, a1+32, a1+48;
    //   return a1;
    // UNRESOLVED: The individual meaning of the four input dwords and the numeric content of the four SSE constants are not documented in this function
    // UNRESOLVED: EmptyStub_8bd0 is a stub whose exact packing order is not derivable here
}
