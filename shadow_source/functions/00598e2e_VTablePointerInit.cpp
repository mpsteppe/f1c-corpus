// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598E2E
// Canonical corpus name: VTableInitOnly
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableInitOnly_00598e2e.c

void UnknownObject::VTablePointerInit()
{
    // Initializes an object's vtable pointer at this+0x0 to the vtable at off_5B9BCC and returns this. Unconditional write; second parameter a2 is unused.
    // ASSIGNMENT: Write vtable address off_5B9BCC into the object's vtable pointer at this+0x0. [field:this:0x00000000, global:0x005B9BCC, source:raw]
    // RETURN: Return this to the caller. [source:raw]

    // Conservative worker pseudocode:
    //   this->vtable = &off_5B9BCC;
    //   return this;
    // UNRESOLVED: Purpose and value of unused second parameter a2 (possibly a hidden ownership or alignment flag) is unknown.
}
