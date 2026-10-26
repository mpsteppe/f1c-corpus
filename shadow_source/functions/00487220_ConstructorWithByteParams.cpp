// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487220
// Canonical corpus name: ConstructorWithByteParams
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorWithByteParams_00487220.c

void UnknownObject::ConstructorWithByteParams()
{
    // Widget-like constructor. Calls base-class setup ShortComputation_5e30, stores two byte parameters a2 and a3 at this+0xE0 and this+0xE1, and installs the WidgetBase vtable (off_5AB968) at this+0x0. Returns this. Called by eleven construction sites (ShortComputation_d5f0, ObjectConstructorWithVTable_d680, sub_46DD10, ConstructorWithVTableAndParamStore, ShortComputation_f890, ObjectCreateWithVtable, SimpleObjectConstructor, SeasonDatabaseObjectFactory, LargeZeroInitConstructor, ShortComputation_e300, sub_493FC0).
    // CALL: Invoke base-class setup ShortComputation_5e30 on this [callee:0x00485E30, source:raw]
    // ASSIGNMENT: Store byte parameter a2 at this+0xE0 [field:this:0x000000E0, source:raw]
    // ASSIGNMENT: Set vtable pointer at this+0x0 to &off_5AB968 (WidgetBase vtable) [field:this:0x00000000, global:0x005AB968, source:raw]
    // ASSIGNMENT: Store byte parameter a3 at this+0xE1 [field:this:0x000000E1, source:raw]
    // RETURN: Return this as the constructed object [function:0x00487220, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall ConstructorWithByteParams(void* this, char a2, char a3) {
    //     ShortComputation_5e30(this);
    //     *(char*)(this + 0xE0) = a2;
    //     *(void**)this = &off_5AB968;
    //     *(char*)(this + 0xE1) = a3;
    //     return this;
    //   }
    // UNRESOLVED: Exact class owning the object and the semantics of the two byte parameters are not established.
    // UNRESOLVED: The base constructor ShortComputation_5e30 is shared with many construction sites; its role in this hierarchy is not grounded here.
}
