// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004796C0
// Canonical corpus name: ObjectInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectInit_004796c0.c

void UnknownObject::ObjectInit()
{
    // UI object component constructor: calls VTableSetInit(this, 0, 1045220557) to initialize the base UI component with parameter 0 and default float value 0.2 (1045220557), then installs the object vtable pointer off_5A4C48 at this+0x0, overriding the base vtable. Returns this.
    // CALL: VTableSetInit(this, 0, 1045220557) initializes the base UI component with parameter 0 and default float 0.2 (1045220557). [callee:0x004795E0, function:0x004796C0, source:raw]
    // ASSIGNMENT: Install the object vtable pointer: this+0x0 = off_5A4C48, overriding the base vtable installed by VTableSetInit. [field:this:0x00000000, global:0x005A4C48, source:raw]
    // RETURN: Return the initialized this pointer. [function:0x004796C0, source:raw]

    // Conservative worker pseudocode:
    //   void* ObjectInit(UnknownObject* this) {
    //     VTableSetInit(this, 0, 1045220557);
    //     this->vtable = &off_5A4C48;
    //     return this;
    //   }
    // UNRESOLVED: The exact UI object class and the meaning of parameter 0 / default float 0.2 are owned by the base VTableSetInit (004795E0) and not evidenced here.
    // UNRESOLVED: No static callers are evidenced; object creation path is unknown.
}
