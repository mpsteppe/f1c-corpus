// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048D3A0
// Canonical corpus name: UIConstructorWithVTableParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIConstructorWithVTableParams_0048d3a0.c

void UnknownObject::UIObjectConstructorWithStoredParams()
{
    // UI widget constructor. Runs base initialization (ShortComputation_5e30) and field initialization (F_5FieldInit) on the object, then stores two integer parameters (a2 at this+0xF4, a3 at this+0xF8), clears two byte flags at this+0xF0 and this+0xF1, writes the vtable pointer off_5AC118 into the object head, and returns this. Called by seven UI construction sites (InitVTableSet 004668E0, VtableSetWithInitCall 00466980, VTableSetInit 004795E0, sub_479C30, ConstructorWithRangeInitAndFlag 00479CD0, UIObjectInitWithFloatConstant 0047C7C0, sub_47C910).
    // CALL: Calls ShortComputation_5e30 on this as the base-object initialization step [callee:0x00485E30, source:raw]
    // CALL: Calls F_5FieldInit to run the additional field-initialization routine [callee:0x004883A0, source:raw]
    // ASSIGNMENT: Stores argument a2 into the dword at this+0xF4 [field:this:0x000000F4, source:raw]
    // ASSIGNMENT: Clears the byte flag at this+0xF0 to 0 [field:this:0x000000F0, source:raw]
    // ASSIGNMENT: Clears the byte flag at this+0xF1 to 0 [field:this:0x000000F1, source:raw]
    // ASSIGNMENT: Writes the vtable pointer off_5AC118 into the object head at this+0x0 [field:this:0x00000000, global:0x005AC118, source:raw]
    // ASSIGNMENT: Stores argument a3 into the dword at this+0xF8 [field:this:0x000000F8, source:raw]
    // RETURN: Returns this (constructor idiom returning the constructed object pointer) [source:raw]

    // Conservative worker pseudocode:
    //   ShortComputation_5e30(this);
    //   F_5FieldInit(this);
    //   this[0xF4] = a2;
    //   this[0xF0] = 0;
    //   this[0xF1] = 0;
    //   *(dword*)this = &off_5AC118;
    //   this[0xF8] = a3;
    //   return this;
    // UNRESOLVED: The meaning of the stored parameters a2 (this+0xF4) and a3 (this+0xF8) and the two byte flags (this+0xF0, this+0xF1) is not readable from this packet; they are written but never consumed here
    // UNRESOLVED: The concrete UI widget type owning this constructor is unknown; the object carries a vtable (off_5AC118) and is used by multiple construction helpers
}
