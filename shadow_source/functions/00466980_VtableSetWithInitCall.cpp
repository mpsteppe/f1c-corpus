// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466980
// Canonical corpus name: VtableSetWithInitCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VtableSetWithInitCall_00466980.c

void UnknownObject::VtableSetWithInitCall()
{
    // Constructor helper: calls UIConstructorWithVTableParams(this, a2, a3) to run base initialization, then overwrites the object's vtable slot at offset 0 with the alternate vtable pointer off_59F2C8, and returns this. Two integer/pointer parameters a2 and a3 are forwarded unchanged into the base constructor.
    // CALL: Call base constructor UIConstructorWithVTableParams(this, a2, a3), forwarding both parameters. [callee:0x0048D3A0, source:raw]
    // ASSIGNMENT: Store the alternate vtable pointer off_59F2C8 into the object's vtable slot at offset 0. [field:this:0x00000000, global:0x0059F2C8, source:raw]
    // RETURN: Return the constructed object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   VtableSetWithInitCall(void* this, int a2, int a3) {
    //       UIConstructorWithVTableParams(this, a2, a3);
    //       *(void**)this = &off_59F2C8;
    //       return this;
    //   }
    // UNRESOLVED: Meaning of parameters a2 and a3 is not observable here; they are consumed by UIConstructorWithVTableParams.
    // UNRESOLVED: Relationship between off_59F2C8 and the default vtable set by UIConstructorWithVTableParams is unknown.
}
