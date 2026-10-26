// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466090
// Canonical corpus name: sub_466090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_466090_00466090.c

void UnknownObject::UIObjectConstructorWithFloatDefaults()
{
    // UI object constructor: calls UIStructInit (0048E600) to initialize the shared UI sub-object, then assigns the vtable pointer off_59F140 and initializes float/default fields at dword indices 60..73 (byte offsets +0xF0..+0x124) with default values including 5.0, 10.0, 1.0 and -1.0. Returns the constructed this pointer. Invoked by ShortComputation_8090 (00468090).
    // CALL: Call UIStructInit() (0048E600) to initialize the shared UI sub-object before the per-object fields are set [callee:0x0048E600, source:raw]
    // ASSIGNMENT: this[62] (offset +0xF8) = 1084227584 (5.0f) [field:this:0x000000F8, source:raw]
    // ASSIGNMENT: this[64] (offset +0x100) = 1084227584 (5.0f) [field:this:0x00000100, source:raw]
    // ASSIGNMENT: this[60] (offset +0xF0) = 0 [field:this:0x000000F0, source:raw]
    // ASSIGNMENT: Zero the two flag bytes at +244 (offset +0xF4) and +245 (offset +0xF5) [field:this:0x000000F4, field:this:0x000000F5, source:raw]
    // ASSIGNMENT: this[65], this[66], this[67] (offsets +0x104, +0x108, +0x10C) = 0 [field:this:0x00000104, field:this:0x00000108, field:this:0x0000010C, source:raw]
    // ASSIGNMENT: this[69] (offset +0x114) = 0 [field:this:0x00000114, source:raw]
    // ASSIGNMENT: this[71], this[72] (offsets +0x11C, +0x120) = 0 [field:this:0x0000011C, field:this:0x00000120, source:raw]
    // ASSIGNMENT: Set the vtable pointer at offset +0x0 to global off_59F140 [field:this:0x00000000, global:0x0059F140, source:raw]
    // ASSIGNMENT: this[63] (offset +0xFC) = 1092616192 (10.0f) [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: this[68] (offset +0x110) = 1065353216 (1.0f) [field:this:0x00000110, source:raw]
    // ASSIGNMENT: this[70] (offset +0x118) = -1082130432 (-1.0f) [field:this:0x00000118, source:raw]
    // ASSIGNMENT: this[73] (offset +0x124) = -1082130432 (-1.0f) [field:this:0x00000124, source:raw]
    // RETURN: Return the initialized this pointer [function:0x00466090, source:raw]
    // CALL: Invoked by ShortComputation_8090 (00468090) as a UI object construction entry point [caller:0x00468090, source:raw]

    // Conservative worker pseudocode:
    //   UIStructInit();
    //   this[62] = 5.0f; this[64] = 5.0f;
    //   this[60] = 0;
    //   byte(+244) = 0; byte(+245) = 0;
    //   this[65] = 0; this[66] = 0; this[67] = 0;
    //   this[69] = 0; this[71] = 0; this[72] = 0;
    //   *(void**)this = &off_59F140;
    //   this[63] = 10.0f; this[68] = 1.0f;
    //   this[70] = -1.0f; this[73] = -1.0f;
    //   return this;
    // UNRESOLVED: The concrete UI class that owns this constructor is not identifiable from this function alone; the object is accessed only as a dword/byte array through this
    // UNRESOLVED: The semantic role of the byte flags at +244 and +245, and of the grouped float defaults (5.0/10.0/1.0/-1.0), is specific to the enclosing UI subsystem and not documented here
}
