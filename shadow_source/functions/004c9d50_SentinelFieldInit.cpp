// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C9D50
// Canonical corpus name: SentinelFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SentinelFieldInit_004c9d50.c

void UnknownObject::SentinelFieldInit()
{
    // thiscall initializer that writes the sentinel value -1 into three fields of the object (offsets 0x0, 0x4 and 0x44), marking them as invalid/empty, then returns the this pointer. Called from sub_4CB120.
    // ASSIGNMENT: Writes -1 into the dword field at offset 0x0, marking the first sentinel field as invalid/empty [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Writes -1 into the dword field at offset 0x4, marking the second sentinel field as invalid/empty [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Writes -1 into the dword field at offset 0x44, marking the third sentinel field as invalid/empty [field:this:0x00000044, source:raw]
    // RETURN: Returns the this pointer as the result of the initializer [function:0x004C9D50, source:raw]
    // CALL: Invoked from sub_4CB120 during object construction [caller:0x004CB120]

    // Conservative worker pseudocode:
    //   *this = -1;
    //   this[1] = -1;
    //   this[17] = -1;
    //   return this;
    // UNRESOLVED: Semantics of the three sentinel fields (offset 0x0, 0x4, 0x44) beyond invalid/empty marking are defined by consumers elsewhere and are not visible in this packet
    // UNRESOLVED: Object type is unknown; no constructor pattern or vtable assignment is visible
}
