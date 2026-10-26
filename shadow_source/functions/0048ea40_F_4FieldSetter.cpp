// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048EA40
// Canonical corpus name: F_4FieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4FieldSetter_0048ea40.c

void UnknownObject::F_4FieldSetter()
{
    // Unconditional thiscall setter storing four arguments into consecutive dword fields of the `this` object at offsets 0x1C, 0x20, 0x24, and 0x28 with argument reordering (a4 to 0x1C, a5 to 0x20, a2 to 0x24, a3 to 0x28). Returns the second argument (a2). No branches, calls, or global access.
    // ASSIGNMENT: Store the fourth argument (a4) into field at offset 0x1C of `this` (this[7]). [field:this:0x0000001C, function:0x0048EA40, source:raw]
    // ASSIGNMENT: Store the fifth argument (a5) into field at offset 0x20 of `this` (this[8]). [field:this:0x00000020, function:0x0048EA40, source:raw]
    // ASSIGNMENT: Store the second argument (a2) into field at offset 0x24 of `this` (this[9]). [field:this:0x00000024, function:0x0048EA40, source:raw]
    // ASSIGNMENT: Store the third argument (a3) into field at offset 0x28 of `this` (this[10]). [field:this:0x00000028, function:0x0048EA40, source:raw]
    // RETURN: Return the second argument (a2), which was also stored at offset 0x24. [function:0x0048EA40, source:raw]

    // Conservative worker pseudocode:
    //   this[0x1C/4] = a4;
    //   this[0x20/4] = a5;
    //   this[0x24/4] = a2;
    //   this[0x28/4] = a3;
    //   return a2;
    // UNRESOLVED: Semantic meaning of the four fields (offsets 0x1C, 0x20, 0x24, 0x28) and the argument-reordering rationale are unknown; no caller or constructor evidence is available.
    // UNRESOLVED: No callers, callees, globals, or guards are present in the evidence packet, so the owning class and the purpose of the returned value (a2) cannot be determined.
}
