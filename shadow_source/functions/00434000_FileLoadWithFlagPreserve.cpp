// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434000
// Canonical corpus name: FileLoadWithFlagPreserve
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileLoadWithFlagPreserve_00434000.c

void UnknownObject::FileLoadWithFlagPreserve()
{
    // Preserves the global flag byte byte_7C56C0, selects the vehicle-setup file path (*this, or the default application directory byte_5EA438 when *this is null), calls VehicleSetupFileWriter(flag, path, 1) to load the setup file, then restores byte_7C56C0 to its pre-call value. Returns the VehicleSetupFileWriter result. The flag is saved and restored so the file-load call does not permanently alter the global flag state.
    // ASSIGNMENT: Save the current global flag byte byte_7C56C0 into a local before the load so it can be restored afterwards. [global:0x007C56C0, source:raw]
    // GUARD: Guard on the path string: when *this is null, fall back to &byte_5EA438 (the default application directory). [field:this:0x00000000, global:0x005EA438, source:raw]
    // CALL: Call VehicleSetupFileWriter(&byte_7C56C0, path, 1) to load the vehicle setup file with flag parameter 1; store its return value as result. [callee:0x0042FD00, global:0x007C56C0, global:0x005EA438, source:raw]
    // ASSIGNMENT: Restore byte_7C56C0 to the value saved before the call. [global:0x007C56C0, source:raw]
    // RETURN: Return the VehicleSetupFileWriter result. [source:raw]
    // CALL: Called by sub_4A00A0 (0x004A00A0) as part of a vehicle setup load path. [caller:0x004A00A0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_434000(char **this) {
    //     char saved_flag = byte_7C56C0;
    //     char *path = *this ? *this : &byte_5EA438;
    //     int result = VehicleSetupFileWriter(&byte_7C56C0, (int)path, 1);
    //     byte_7C56C0 = saved_flag;
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the flag parameter 1 passed to VehicleSetupFileWriter are unknown.
    // UNRESOLVED: Meaning of byte_7C56C0's flag bits and why the caller needs it preserved around the load is unknown.
    // UNRESOLVED: Owner object is unknown; the __thiscall receiver this is only used as a path-string holder.
}
