// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A102
// Canonical corpus name: VtableFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VtableFieldGetter_0049a102.c

void UnknownObject::VtableFieldGetter()
{
    // Shallow copy/read helper: stores a1 into the dword pointed by a2, reads the dword at a3 + 100 (0x64), stores that value into the dword pointed by a5, and returns the same value. The named-input/out-param shape matches the legacy Vtable_Field_Getter ABI lead, but no class or vtable identity is visible in this packet.
    // ASSIGNMENT: Store a1 into the dword pointed by a2. [function:0x0049A102, source:raw]
    // CALCULATION: result = dword read from a3 + 100 (0x64). [function:0x0049A102, source:raw]
    // ASSIGNMENT: Store result into the dword pointed by a5. [function:0x0049A102, source:raw]
    // RETURN: Return result, the dword read from a3 + 100. [function:0x0049A102, source:raw]

    // Conservative worker pseudocode:
    //   *a2 = a1;
    //   result = *(dword*)(a3 + 100);
    //   *a5 = result;
    //   return result;
    // UNRESOLVED: The object type of a3 and the meaning of the dword field at displacement 100 (0x64) are unknown; no field or vtable evidence exists in this packet.
    // UNRESOLVED: The declared legacy Vtable_Field_Getter ABI name is unverified by any other packet evidence.
    // UNRESOLVED: a4 is declared but never used in the body.
}
