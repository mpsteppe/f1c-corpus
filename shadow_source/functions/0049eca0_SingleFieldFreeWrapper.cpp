// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049ECA0
// Canonical corpus name: SingleFieldFreeWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFieldFreeWrapper_0049eca0.c

void UnknownObject::SingleFieldFreeWrapper()
{
    // Releases the resource handle stored at this[1] (offset 0x4) via ResourceCascadeCleanup and clears the field to 0. If the handle is already null the cleanup is skipped and null is returned.
    // ASSIGNMENT: Load the current value of this[1] (offset 0x4) into the result variable. [source:raw, field:this:0x00000004]
    // GUARD: Guard on this[1] being non-null; when null the cleanup and clear are skipped. [source:raw, field:this:0x00000004]
    // CALL: Call ResourceCascadeCleanup on the loaded handle and store its return value as the result. [callee:0x005539F0]
    // ASSIGNMENT: Clear this[1] (offset 0x4) to 0 after the cleanup call. [source:raw, field:this:0x00000004]
    // RETURN: Return the result of the cleanup call, or null when the guard failed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49ECA0(int *this) {
    //     int result = this[1];
    //     if (result) {
    //       result = ResourceCascadeCleanup(result);
    //       this[1] = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Nature of the resource object behind the handle and what ResourceCascadeCleanup releases remains external to this function.
    // UNRESOLVED: The caller relationship to the read global is not visible in the raw source.
}
