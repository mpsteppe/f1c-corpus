// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A580
// Canonical corpus name: VTableCallViaOffset0x6c
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableCallViaOffset0x6c_0057a580.c

void UnknownObject::VTableCallViaOffset0x6c()
{
    // Thin thiscall dispatch shim: loads the object pointer from the this slot, reads the virtual function pointer at vtable offset 0x6C (entry 27) of that object, calls it with the object as the this argument, and returns its result. Invoked by CollisionSpatialQuery (00462CE0).
    // ASSIGNMENT: Load the target object pointer from the this slot (*this). [field:this:0x00000000]
    // CALL: Dereference the object's vtable pointer at offset 0 and call the virtual function stored at vtable offset 0x6C, passing the object as the this argument. [field:obj:0x00000000, field:*(obj+0x0):0x0000006C]
    // RETURN: Return the result of the virtual dispatch. [function:0x0057A580, source:raw]
    // CALL: Called as a virtual query dispatch by CollisionSpatialQuery (00462CE0). [caller:0x00462CE0]

    // Conservative worker pseudocode:
    //   int VTableCallViaOffset0x6c(int *this) {
    //     int obj = *this;
    //     return (*(int (__thiscall **)(int))(*(int *)obj + 0x6C))(obj);
    //   }
    // UNRESOLVED: The identity of the target object class and the semantic of the virtual method at vtable offset 0x6C are unknown.
    // UNRESOLVED: The object pointer in the this slot is not validated; the dispatch assumes a valid vtable.
}
