// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473B90
// Canonical corpus name: ConditionalInitWithGlobalRefSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalInitWithGlobalRefSetup_00473b90.c

void UnknownObject::ConditionalInitWithGlobalRefSetup()
{
    // __thiscall that dispatches through the vtable of dword_7CD8C0 at slot +28 with argument 11 to obtain an object; if non-null it compares the names of that object and `this` via ObjectNameComparison. Unconditionally then stores &byte_7D0474 at this+0x320 and the literal 278 at this+0x31C, and returns 0.
    // CALL: Virtual call through the dword_7CD8C0 interface: load its vtable and invoke the entry at offset +28 with (dword_7CD8C0, 11), storing the result in v2. [global:0x007CD8C0, source:raw]
    // GUARD: Guard on the dispatch result v2 being non-null before comparing object names. [source:raw]
    // CALL: When v2 is non-null, call ObjectNameComparison (0x00477280) with (v2, this) to compare the two objects' names. [callee:0x00477280, source:raw]
    // ASSIGNMENT: Store the address of the global byte_7D0474 into this[200] (offset 0x320) as a reference to the text-encoding flag. [field:this:0x00000320, global:0x007D0474, source:raw]
    // ASSIGNMENT: Store the literal 278 into this[199] (offset 0x31C) as an identifier/counter preset. [field:this:0x0000031C, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalInitWithGlobalRefSetup(_DWORD* this) {
    //     _DWORD* v2 = (*(_DWORD*)(*(_DWORD*)dword_7CD8C0 + 28))(dword_7CD8C0, 11);
    //     if (v2) ObjectNameComparison(v2, (int)this);
    //     this[200] = &byte_7D0474;
    //     this[199] = 278;
    //     return 0;
    //   }
    // UNRESOLVED: What the dispatched call retrieves (object by ID 11 per existing analysis, DERIVED) is not confirmed by packet evidence alone.
    // UNRESOLVED: Semantics of ObjectNameComparison and the two objects involved are unknown.
    // UNRESOLVED: Purpose of the 278 value at this+0x31C and the byte_7D0474 reference at this+0x320 is unknown.
}
