// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005418B0
// Canonical corpus name: ConstructorInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstructorInit_005418b0.c

void UnknownObject::ConstructorInit()
{
    // Constructor-style initializer. Calls GlobalZeroInit_c2a0 to zero the whole object, then explicitly writes zero to four fields at offsets 0x80, 0x19C, 0x1B4 and 0x1B8 before returning this. No branches, no globals touched.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the entire object memory. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x80 after the global zero-init. [field:this:0x00000080, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x19C after the global zero-init. [field:this:0x0000019C, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x1B4 after the global zero-init. [field:this:0x000001B4, source:raw]
    // ASSIGNMENT: Write zero to the dword at this+0x1B8 after the global zero-init. [field:this:0x000001B8, source:raw]
    // RETURN: Return this pointer. [function:0x005418B0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *__thiscall ConstructorInit(_DWORD *this)
    //   {
    //     GlobalZeroInit_c2a0(this);
    //     this[0x80/4] = 0;
    //     this[0x19C/4] = 0;
    //     this[0x1B4/4] = 0;
    //     this[0x1B8/4] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object owning these fields is unknown; the caller set (sub_544E90, sub_548AD0, sub_553700, sub_560C10) spans unrelated subsystems.
    // UNRESOLVED: Semantic purpose of the four explicitly re-zeroed fields beyond GlobalZeroInit is not established.
}
