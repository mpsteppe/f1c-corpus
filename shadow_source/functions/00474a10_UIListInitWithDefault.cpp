// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474A10
// Canonical corpus name: UIListInitWithDefault
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIListInitWithDefault_00474a10.c

void UnknownObject::UIListInitWithDefault()
{
    // Constructor for a UI list element: runs base initializer sub_48C070 with argument 1, installs the vtable off_5A3E40 at offset 0, stores literal 400 at field this+0x31C, then calls sub_474AB0 for additional list-element initialization before returning this. Straight-line, no branches; no static callers recorded.
    // CALL: Invoke sub_48C070 with the literal argument 1 to perform base initialization for the list element [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Install the vtable pointer: write off_5A3E40 into the object at offset 0 [field:this:0x00000000, global:0x005A3E40, source:raw]
    // ASSIGNMENT: Store literal value 400 at field this+0x31C (this[199]) [field:this:0x0000031C, source:raw]
    // CALL: Invoke sub_474AB0 for additional initialization specific to this list element type [callee:0x00474AB0, source:raw]
    // RETURN: Return this; no static callers are recorded (top-level or indirect-only invocation) [function:0x00474A10, source:raw]

    // Conservative worker pseudocode:
    //   void* UIListInitWithDefault(void* this) {
    //     sub_48C070(this, 1);
    //     *(this + 0x0) = &off_5A3E40;
    //     *(this + 0x31C) = 400;
    //     sub_474AB0(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantic role of the literal 400 stored at this+0x31C (value/ID/counter preset) is not established from this packet
    // UNRESOLVED: What sub_474AB0 initializes beyond this function is unknown
    // UNRESOLVED: Owner type is unknown; existing analysis labels the object a UI list element without confirmation
}
