// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00479940
// Canonical corpus name: ShortComputation_9940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9940_00479940.c

void UnknownObject::ObjectConstructorWithEnableFlag()
{
    // Object constructor: calls VtableSetWithInitCall with literal arguments 0 and 1065353216, installs vtable off_5A55A0 at this[0], and sets byte enable flag at offset 0xF0 to 1; returns this.
    // CALL: Calls VtableSetWithInitCall(this, 0, 1065353216) to initialize leading fields of the object. [callee:0x00466980, source:raw]
    // ASSIGNMENT: Sets this[0] (offset 0x0, vtable pointer) to off_5A55A0. [field:this:0x00000000, global:0x005A55A0, source:raw]
    // ASSIGNMENT: Sets byte at offset 0xF0 to 1 (enable flag). [field:this:0x000000F0, source:raw]
    // RETURN: Returns the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(this, 0, 1065353216);
    //   this[0] = &off_5A55A0;
    //   *(_BYTE *)(this + 240) = 1;
    //   return this;
    // UNRESOLVED: Interpretation of literal 1065353216 (possibly a float bit pattern) is not evidenced in the packet and is left unspecified.
}
