// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046D680
// Canonical corpus name: ObjectConstructorWithVTable_d680
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructorWithVTable_d680_0046d680.c

void UnknownObject::ObjectConstructorWithVTable_d680()
{
    // Object constructor: calls ConstructorWithByteParams(this, 0, 0) to initialize the base object with two zero byte parameters, then sets the vtable slot at offset 0 to the vtable pointer off_59FCB8, and returns the constructed object pointer.
    // CALL: Call base initializer ConstructorWithByteParams(this, 0, 0) with both byte parameters zero. [callee:0x00487220, source:raw]
    // ASSIGNMENT: Store vtable pointer off_59FCB8 into the object's vtable slot at offset 0, replacing the base constructor's default. [field:this:0x00000000, global:0x0059FCB8, source:raw]
    // RETURN: Return the constructed object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   ObjectConstructorWithVTable_d680(void* this) {
    //       ConstructorWithByteParams(this, 0, 0);
    //       *(void**)this = &off_59FCB8;
    //       return this;
    //   }
    // UNRESOLVED: Semantics of the two zero byte parameters to ConstructorWithByteParams are not observable here.
    // UNRESOLVED: Why this constructor swaps in vtable off_59FCB8 rather than the base constructor's default is unknown.
}
