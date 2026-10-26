// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00529AF8
// Canonical corpus name: FieldSetterWithVTableAlloc
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetterWithVTableAlloc_00529af8.c

void UnknownObject::allocObjectAndSetFields()
{
    // Calls a function pointer read from (a5 + 32), passing the value stored at (a5 + 40), 1, and 28 as arguments; if the call returns non-null it zeroes the first dword and stores five caller-supplied fields (two bytes, two dwords) into the returned object, then returns that pointer.
    // CALL: invoke the function pointer located at (a5 + 32) with arguments (value at a5 + 40), 1, and 28; the return value is treated as the allocated object [source:raw, function:0x00529AF8]
    // GUARD: if the returned object is non-null, proceed to initialize its fields [source:raw]
    // ASSIGNMENT: write 0 to the first dword of the returned object [source:raw]
    // ASSIGNMENT: store byte argument a1 at object offset 16 [source:raw]
    // ASSIGNMENT: store byte argument a2 at object offset 17 [source:raw]
    // ASSIGNMENT: store dword argument a3 at object offset 20 [source:raw]
    // ASSIGNMENT: store dword argument a4 at object offset 24 [source:raw]
    // RETURN: return the object pointer, which may be null when the call at (a5 + 32) returned null [source:raw]

    // Conservative worker pseudocode:
    //   int allocObjectAndSetFields(char a1, char a2, int a3, int a4, int a5) {
    //     void* obj = ((int (__cdecl*)(int, int, int))(*(int*)(a5 + 32)))(*(int*)(a5 + 40), 1, 28);
    //     if (obj) { *(int*)obj = 0; *(char*)(obj + 16) = a1; *(char*)(obj + 17) = a2; *(int*)(obj + 20) = a3; *(int*)(obj + 24) = a4; }
    //     return obj;
    //   }
    // UNRESOLVED: Whether the dispatched call is an allocation, a factory, or another kind of operation is not proven; 1 and 28 may be a count/size pair or unrelated parameters
    // UNRESOLVED: Relationship between the receiver stored at (a5 + 40) and the vtable-like pointer at (a5 + 32) is unresolved
    // UNRESOLVED: What the single caller sub_527752 expects the returned object to be is unknown
}
