// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004484C0
// Canonical corpus name: Vec3Subtract
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vec3Subtract_004484c0.c

void UnknownObject::Vec3Subtract()
{
    // Element-wise subtract of two 16-byte geometry records: writes a2 - a3 into this as float(0), double(4) and float(12), then returns the a2 pointer. Called by RecursiveTriangleEdgeSubdivisionForCollision (0x0044AAE0) for collision triangle edge subdivision.
    // CALCULATION: Write output float at this+0 = a2.float(0) - a3.float(0). [field:this:0x00000000, source:raw]
    // CALCULATION: Write output double at this+4 = a2.double(4) - a3.double(4). [field:this:0x00000004, source:raw]
    // CALCULATION: Write output float at this+12 (float index 3) = a2.float(12) - a3.float(12). [field:this:0x0000000C, source:raw]
    // RETURN: Return the a2 input pointer as the result value. [source:raw]

    // Conservative worker pseudocode:
    //   *(float*)(this + 0)  = *(float*)(a2 + 0)  - *(float*)(a3 + 0);
    //   *(double*)(this + 4) = *(double*)(a2 + 4) - *(double*)(a3 + 4);
    //   *(float*)(this + 12) = *(float*)(a2 + 12) - *(float*)(a3 + 12);
    //   return a2;
    // UNRESOLVED: Layout float(0), double(4), float(12) is not a plain Vec3; Vec3Subtract is the legacy ABI name and does not fully describe the record.
    // UNRESOLVED: The meaning of the double component at offset 4 within the triangle-edge record is unknown.
}
