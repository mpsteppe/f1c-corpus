// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058815F
// Canonical corpus name: StringFormatWithBufferOverflowCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatWithBufferOverflowCheck_0058815f.c

void UnknownObject::StringFormatWithBufferOverflowCheck()
{
    // Variadic string formatter: initializes a destination pointer and a 0x7FFFFFFF size budget, calls sub_58D04D to format into the destination, decrements the budget to detect underflow, and either invokes sub_58CF35 on overflow or writes a NUL terminator otherwise; returns the sub_58D04D result.
    // ASSIGNMENT: Start the va_list at a2 and initialize locals: v8/v6 point at destination a1, v9 = 66, v7 = 0x7FFFFFFF. [source:raw]
    // CALL: Call sub_58D04D(&v6, a2, va) to format the variadic arguments into the destination, advancing v6; assign result to v2. [callee:0x0058D04D, source:raw]
    // CALCULATION: Decrement v7 (--v7) and set v3 when the decrement makes it negative, flagging a remaining-budget underflow. [source:raw]
    // ASSIGNMENT: Assign v4 = v2 (the sub_58D04D result). [source:raw]
    // GUARD: Branch to the overflow path when v3 (budget underflow) is true. [source:raw]
    // CALL: On overflow, call sub_58CF35(0, &v6). [callee:0x0058CF35, source:raw]
    // ASSIGNMENT: On the non-overflow path, write a NUL byte (0) at the current cursor position via *v6 = 0. [field:this:0x00000000, source:raw]
    // RETURN: Return v4 (the sub_58D04D result). [source:raw]

    // Conservative worker pseudocode:
    //   va_start(va, a2);
    //   v8 = a1; v6 = a1;
    //   v9 = 66;
    //   v7 = 0x7FFFFFFF;
    //   v2 = sub_58D04D(&v6, a2, va);
    //   v3 = --v7 < 0;
    //   v4 = v2;
    //   if (v3)
    //     sub_58CF35(0, &v6);
    //   else
    //     *v6 = 0;
    //   return v4;
    // UNRESOLVED: Meaning of the local constant 66 and of the 0x7FFFFFFF budget, and the behavior of sub_58CF35 (overflow handler) and sub_58D04D (formatter) are unknown.
    // UNRESOLVED: The field evidence field:this:0x00000000 is mapped to the *v6 = 0 write on the assumption that v6 starts at the destination buffer; the packet's field base 'this' may not literally equal a1.
    // UNRESOLVED: Owning object type is unknown; the packet carries no field records beyond the single byte at offset 0x0.
}
