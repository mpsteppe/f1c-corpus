// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463C80
// Canonical corpus name: VehicleDescriptionAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleDescriptionAccessor_00463c80.c

void UnknownObject::GetVehicleDescription()
{
    // __thiscall getter that reads the vehicle object's vtable first dword, adds offset 0xB4, and dereferences the resulting address as a char* description pointer. Returns the description pointer when non-null, otherwise returns the fallback global byte_5EA438.
    // ASSIGNMENT: Read the first dword at this (vtable pointer), add 180 (0xB4) bytes to it, and dereference as char* to obtain the vehicle description string pointer stored at obj+0xB4. [field:this:0x00000000, field:obj:0x000000B4, source:raw]
    // GUARD: If the description pointer is null, fall back to the global default path string byte_5EA438. [global:0x005EA438, source:raw]
    // RETURN: Return the description pointer when non-null, otherwise return byte_5EA438. [global:0x005EA438, source:raw]

    // Conservative worker pseudocode:
    //   char *GetVehicleDescription(void *this) {
    //     char *desc = *(char **)(*(int *)this + 180);
    //     if (!desc) return (char *)0x005EA438;
    //     return desc;
    //   }
    // UNRESOLVED: The value loaded via this[0] + 0xB4 is rendered by the decompiler as a vtable-relative access; the exact owning class is unknown, so the object type is UnknownObject.
    // UNRESOLVED: Semantics of byte_5EA438 (a shared fallback string) depend on the module that owns that global.
}
