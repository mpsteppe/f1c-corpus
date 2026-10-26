// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517927
// Canonical corpus name: FunctionTableInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FunctionTableInit_00517927.c

void UnknownObject::FunctionTableInit()
{
    // Populates an 8-entry math dispatch table. Fills slots 0..7 at offsets 0x0..0x1C with Vec2AffineTransform, sub_517569, sub_517653, F_44MatrixMultiply, F_44MatrixMultiply_7899, Mat2x2Mul, sub_5175F4 and VectorNormalize, then returns the table base pointer. Called from sub_50FEA7 (0x0050FEA7).
    // ASSIGNMENT: Store Vec2AffineTransform into table slot 0 (offset 0x0). [global:0x005174CB, field:this:0x00000000]
    // ASSIGNMENT: Store sub_517569 into table slot 1 (offset 0x4). [global:0x00517569, field:this:0x00000004]
    // ASSIGNMENT: Store sub_517653 into table slot 2 (offset 0x8). [global:0x00517653, field:this:0x00000008]
    // ASSIGNMENT: Store F_44MatrixMultiply into table slot 3 (offset 0xC). [global:0x005177B6, field:this:0x0000000C]
    // ASSIGNMENT: Store F_44MatrixMultiply_7899 into table slot 4 (offset 0x10). [global:0x00517899, field:this:0x00000010]
    // ASSIGNMENT: Store Mat2x2Mul into table slot 5 (offset 0x14). [global:0x00517534, field:this:0x00000014]
    // ASSIGNMENT: Store sub_5175F4 into table slot 6 (offset 0x18). [global:0x005175F4, field:this:0x00000018]
    // ASSIGNMENT: Store VectorNormalize into table slot 7 (offset 0x1C). [global:0x005176EC, field:this:0x0000001C]
    // RETURN: Return the table base pointer (result = a1). [source:raw, caller:0x0050FEA7]

    // Conservative worker pseudocode:
    //   a1[0] = Vec2AffineTransform;
    //   a1[1] = sub_517569;
    //   a1[2] = sub_517653;
    //   a1[3] = F_44MatrixMultiply;
    //   a1[4] = F_44MatrixMultiply_7899;
    //   a1[5] = Mat2x2Mul;
    //   a1[6] = sub_5175F4;
    //   a1[7] = VectorNormalize;
    //   return a1;
    // UNRESOLVED: The unnamed entries sub_517569, sub_517653 and sub_5175F4 have no descriptive names in the packet; their precise math transform semantics are not recoverable from this packet alone.
    // UNRESOLVED: The owning class is unknown; the table base is received as argument a1 while the packet keys the entries as this fields.
}
