// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A418
// Canonical corpus name: StdGninc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StdGninc_0059a418.c

void UnknownObject::StdGninc()
{
    // Advances a wide-character stream read: decrements the dword at the pointer stored in this+0x2C, then reads the dword at the pointer stored in this+0x1C, adds 2 to it, and returns the pre-adjustment value. Shape matches a get-next-increment (gninc) on a wide-character buffer; the structural twin of PointerOffsetAdjuster (0059a407) with the sign of each adjustment flipped. Called by MSVCStreambufUflow and sub_59A103.
    // ASSIGNMENT: Decrements the dword value at the pointer stored in this+0x2C by one; interpreted as lowering an available/remaining count when one character is consumed. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Reads the dword at the pointer stored in this+0x1C (this[7]) into the result; the current byte-oriented buffer position. [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Adds 2 to the dword at the pointer stored in this+0x1C, advancing the buffer position by two bytes (one wide character). [field:this:0x0000001C, source:raw]
    // RETURN: Returns the pre-adjustment position value captured before the two-byte advance. [function:0x0059A418, source:raw]
    // CALL: Called by MSVCStreambufUflow (0x00599D31) and sub_59A103 (0x0059A103), both supplying the this object for their stream-advance paths. [caller:0x00599D31, caller:0x0059A103, source:raw]

    // Conservative worker pseudocode:
    //   --**(this + 0x2C);
    //   result = **(this + 0x1C);
    //   **(this + 0x1C) += 2;
    //   return result;
    // UNRESOLVED: The std::streambuf-like get/increment interpretation behind this+0x1C and this+0x2C is DERIVED from the raw body and the ABI lead (std__Gninc); the exact owner class and buffer-width contract are not independently confirmed.
    // UNRESOLVED: Equal offsets on unrelated this pointers elsewhere are not proof the fields or owner class are identical.
    // UNRESOLVED: The relationship between this function and its structural twin PointerOffsetAdjuster (0059a407) is prelabeled as a cluster copy; identical instruction shape is not proof of identical object semantics.
}
