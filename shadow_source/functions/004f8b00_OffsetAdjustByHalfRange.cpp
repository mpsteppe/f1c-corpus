// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8B00
// Canonical corpus name: sub_4F8B00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F8B00_004f8b00.c

void UnknownObject::OffsetAdjustByHalfRange()
{
    // Calls ArithmeticComparison_8c00 with this+0xC. Stores the comparison result at this+0x0. If the result is zero, subtracts 0x8000 from the three dword values at this+0x4, this+0x8 and this+0xC (suggested by the existing fill as converting an unsigned 16-bit range to signed). Returns the comparison result.
    // CALL: Call ArithmeticComparison_8c00 with the address of this+0xC; its return value is the result. [callee:0x004F8C00, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the comparison result into this+0x0. [field:this:0x00000000, source:raw]
    // GUARD: Only when the comparison result is zero, subtract 0x8000 from the three values at this+0x4, this+0x8, this+0xC. [field:this:0x00000000, source:raw]
    // CALCULATION: Subtract 0x8000 from this+0x4 (the existing fill suggests a conversion of an unsigned 16-bit range to signed). [field:this:0x00000004, source:raw]
    // CALCULATION: Subtract 0x8000 from this+0x8. [field:this:0x00000008, source:raw]
    // CALCULATION: Subtract 0x8000 from this+0xC. [field:this:0x0000000C, source:raw]
    // RETURN: Return the comparison result to the caller. [function:0x004F8B00, source:raw]

    // Conservative worker pseudocode:
    //   int result = ArithmeticComparison_8c00(this + 0xC);
    //   this->f0 = result;
    //   if (result == 0) {
    //       this->f4 -= 0x8000;
    //       this->f8 -= 0x8000;
    //       this->fC -= 0x8000;
    //   }
    //   return result;
    // UNRESOLVED: Semantic meaning of the ArithmeticComparison_8c00 result (what the zero/non-zero outcome represents) is not established from the packet.
    // UNRESOLVED: Whether the 0x8000 subtraction really converts unsigned to signed 16-bit values is only a DERIVED suggestion from the existing fill, not proven.
    // UNRESOLVED: Class/owner of the this pointer and the meaning of the three adjusted fields is unknown.
    // UNRESOLVED: Legacy ABI label 'Screen_Coordinate_Clamp' is LEGACY trust with no prototype and no runtime evidence; it cannot be promoted.
}
