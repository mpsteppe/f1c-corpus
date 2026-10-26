// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00476030
// Canonical corpus name: UIOptionsConstructor_6030
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIOptionsConstructor_6030_00476030.c

void UnknownObject::UIOptionsConstructor()
{
    // Options-screen UI object constructor. Calls the base UI object constructor UIObjectConstructor_fc50, then installs the options vtable by writing &off_5A4428 into this+0x0, zeroes the state field at this+0x3C, and returns the object pointer.
    // CALL: Base UI object constructor UIObjectConstructor_fc50 invoked unconditionally as the first step [callee:0x0048FC50, source:raw]
    // ASSIGNMENT: Vtable install: writes the options vtable pointer &off_5A4428 into this+0x0 [field:this:0x00000000, global:0x005A4428, source:raw]
    // ASSIGNMENT: Zeroes the options state/flag field at this+0x3C (this[15]) during init [field:this:0x0000003C, source:raw]
    // RETURN: Returns the constructed object pointer [function:0x00476030, source:raw]

    // Conservative worker pseudocode:
    //   UIObjectConstructor_fc50();
    //   this->vtable = &off_5A4428;
    //   this[0x3C] = 0;
    //   return this;
    // UNRESOLVED: off_5A4428 vtable identity and the full options-screen vtable layout are not established from this packet alone
    // UNRESOLVED: Field at this+0x3C is zeroed at init but its runtime meaning (options state vs flag) is not confirmed
}
