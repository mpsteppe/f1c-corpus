// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3490
// Canonical corpus name: ArithmeticComparison_3490
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_3490_004f3490.c

void UnknownObject::ArithmeticComparison_3490()
{
    // Calls sub_565AA0 to fill a three-value tuple at 0x90, 0x98, 0xA0 from input a3, then, if the parse succeeds (non-zero return), applies fabs to each of the three tuple values. Returns the parse result. Called from TheSvmHdvVehicleFileParser.
    // CALL: result = sub_565AA0(a3, this + 0x90, this + 0x98, this + 0xA0, 0), parsing input a3 into the three tuple values. [callee:0x00565AA0, field:this:0x00000090, field:this:0x00000098, field:this:0x000000A0, source:raw]
    // GUARD: If result is non-zero (parse success), apply absolute values to the tuple elements. [callee:0x00565AA0, source:raw]
    // ASSIGNMENT: Set the tuple element at 0x90 to fabs of its current value. [field:this:0x00000090, source:raw]
    // ASSIGNMENT: Set the tuple element at 0x98 to fabs of its current value. [field:this:0x00000098, source:raw]
    // ASSIGNMENT: Set the tuple element at 0xA0 to fabs of its current value. [field:this:0x000000A0, source:raw]
    // RETURN: Return the sub_565AA0 result (parse success flag). [function:0x004F3490, source:raw]

    // Conservative worker pseudocode:
    //   int ArithmeticComparison_3490(long double *this, int a2, int a3) {
    //       int result = sub_565AA0(a3, this + 0x90, this + 0x98, this + 0xA0, 0);
    //       if (result) {
    //           *(this + 0x90) = fabs(*(this + 0x90));
    //           *(this + 0x98) = fabs(*(this + 0x98));
    //           *(this + 0xA0) = fabs(*(this + 0xA0));
    //       }
    //       return result;
    //   }
    // UNRESOLVED: Field element stride and long double element size are ambiguous in the raw source (packet fields are 0x90, 0x98, 0xA0).
    // UNRESOLVED: The purpose of argument a2 is not evidenced in the raw source.
}
