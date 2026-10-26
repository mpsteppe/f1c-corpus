// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9CB0
// Canonical corpus name: VehicleLifetimeAverageAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleLifetimeAverageAccessor_004b9cb0.c

void UnknownObject::VehicleLifetimeAverageAccessor()
{
    // Accessor that reads a float at offset 0xF30 of the object pointed to by the pointer stored at this+0x0. First dereferences this to obtain the target object, then loads the float at object+0xF30 and returns it. No branches, guards, globals, or callees.
    // ASSIGNMENT: Dereference this to obtain the target object pointer stored at this+0x0. [field:this:0x00000000, source:raw]
    // RETURN: Load and return the float at the target object's offset 0xF30 (byte offset 3888). [field:obj:0x00000F30, source:raw]

    // Conservative worker pseudocode:
    //   double VehicleLifetimeAverageAccessor(void* this) {
    //     return *(float*)(*(int*)this + 3888);
    //   }
    // UNRESOLVED: The owning class of both this and the dereferenced object is unknown; the packet provides no owner evidence.
    // UNRESOLVED: The meaning of the float at object+0xF30 as a lifetime average is taken from the existing-analysis label and ABI legacy name (DERIVED); the field could equally be any scalar quantity, and the accessor reads only through a single pointer hop.
    // UNRESOLVED: The raw source declares a double return type while the value loaded is a 32-bit float; the discrepancy was not reconciled in this packet.
}
