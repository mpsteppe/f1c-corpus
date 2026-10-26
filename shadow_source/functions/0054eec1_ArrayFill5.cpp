// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054EEC1
// Canonical corpus name: ArrayFill5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayFill5_0054eec1.c

void UnknownObject::ArrayFill5()
{
    // Fills five consecutive DWORD slots starting at a caller-supplied pointer with the same integer value passed in a2, then returns the pointer. Unconditional small utility for initializing a five-element integer array or struct region.
    // ASSIGNMENT: Write a2 into the first DWORD slot at offset 0x0 of the destination array. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write a2 into the second DWORD slot at offset 0x4 of the destination array. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write a2 into the third DWORD slot at offset 0x8 of the destination array. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write a2 into the fourth DWORD slot at offset 0xC of the destination array. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write a2 into the fifth DWORD slot at offset 0x10 of the destination array. [field:this:0x00000010, source:raw]
    // RETURN: Return the destination pointer to the caller. [function:0x0054EEC1, source:raw]

    // Conservative worker pseudocode:
    //   void *fill_five(_DWORD *result, int a2)
    //   {
    //       result[0] = a2;
    //       result[1] = a2;
    //       result[2] = a2;
    //       result[3] = a2;
    //       result[4] = a2;
    //       return result;
    //   }
    // UNRESOLVED: No guard, callee, global, or caller evidence present in the packet; ownership of the destination object is unknown.
    // UNRESOLVED: Whether the five slots form an array versus distinct struct fields cannot be established from this function alone.
}
