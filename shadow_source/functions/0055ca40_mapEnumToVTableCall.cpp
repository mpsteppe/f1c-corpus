// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055CA40
// Canonical corpus name: EnumToVTableCallMapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/EnumToVTableCallMapper_0055ca40.c

void UnknownObject::mapEnumToVTableCall()
{
    // Action-enum dispatch through a virtual call. Reads the object pointer this[1088] (offset 0x1100) whose first dword is a vtable, and invokes vtable entry 37 (offset 0x94) with (this[1088], mappedParam, a3). Maps a2 == 1 to parameter 256, a2 == 2 to parameter 2, and a2 == 4 to parameter 3. Any other a2 returns (a2 - 4) without the vtable call. On the three recognized paths the call result is stored back to this[0] and returned.
    // GUARD: When a2 == 1, call vtable entry +0x94 of the object at this[0x1100] with arguments (this[0x1100], 256, a3) [field:*(this+0x1100):0x00000094, field:this:0x00001100, source:raw]
    // GUARD: Else when a2 == 2, call the same vtable entry +0x94 with arguments (this[0x1100], 2, a3) [field:*(this+0x1100):0x00000094, field:this:0x00001100, source:raw]
    // CALCULATION: Otherwise result = a2 - 4; when a2 != 4 return that value immediately without a vtable call and without storing to this[0] [function:0x0055CA40, source:raw]
    // CALL: When a2 == 4, call vtable entry +0x94 of the object at this[0x1100] with arguments (this[0x1100], 3, a3) [field:*(this+0x1100):0x00000094, field:this:0x00001100, source:raw]
    // ASSIGNMENT: On the recognized vtable-call paths, store the call result to this[0] [field:this:0x00000000, source:raw]
    // RETURN: Return the vtable call result on the recognized paths, or (a2 - 4) on the unrecognized path [function:0x0055CA40, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 1) result = vtable[this[0x1100]] + 0x94 (this[0x1100], 256, a3);
    //   else if (a2 == 2) result = vtable[this[0x1100]] + 0x94 (this[0x1100], 2, a3);
    //   else {
    //     result = a2 - 4;
    //     if (a2 != 4) return result;
    //     result = vtable[this[0x1100]] + 0x94 (this[0x1100], 3, a3);
    //   }
    //   this[0] = result;
    //   return result;
    // UNRESOLVED: The semantic meaning of the a2 enum values (1, 2, 4) and the mapped vtable parameters (256, 2, 3) is unknown without the vtable object's contract
    // UNRESOLVED: this[0] is written only on the recognized paths; its role as result/status storage is inferred from the write, not confirmed by a reader
}
