// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559350
// Canonical corpus name: StringCopyFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyFieldInit_00559350.c

void UnknownObject::StringCopyFieldInit()
{
    // Initializer (__thiscall): strcpy-copies string parameter a2 into the object start, then writes parameter a3 into dword this+0x14, parameter a4 into dword this+0x18, and zeroes dword this+0x1C. Returns a3.
    // CALL: strcpy copies string at a2 into object memory starting at this+0x0 [function:0x00559350, source:raw]
    // ASSIGNMENT: Write parameter a3 to dword at this+0x14 [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write parameter a4 to dword at this+0x18 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write literal 0 to dword at this+0x1C [field:this:0x0000001C, source:raw]
    // RETURN: Return parameter a3 [function:0x00559350, source:raw]

    // Conservative worker pseudocode:
    //   int StringCopyFieldInit(char* this, const char* a2, int a3, int a4) {
    //     strcpy(this, a2);
    //     *(dword*)(this + 0x14) = a3;
    //     *(dword*)(this + 0x18) = a4;
    //     *(dword*)(this + 0x1C) = 0;
    //     return a3;
    //   }
    // UNRESOLVED: strcpy target starts at this+0x0, but the packet has no field evidence for offset 0x0.
    // UNRESOLVED: Semantic role of the two stored parameters (0x14, 0x18) is unknown.
}
