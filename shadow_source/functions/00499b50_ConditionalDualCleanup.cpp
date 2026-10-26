// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499B50
// Canonical corpus name: ConditionalDualCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDualCleanup_00499b50.c

void UnknownObject::ConditionalDualCleanup()
{
    // Conditionally cleans up two resources held by the object. If the pointer field at this+0x30 is non-null, cascade-cleans it via ResourceCascadeCleanup and clears the field to 0. Independently, if the field at this+0x2C is non-zero, invokes an object-level cleanup routine (named in raw source, no packet callee address). Returns the outcome of the this+0x30 cleanup.
    // ASSIGNMENT: Load the pointer field at this+0x30 into result. [field:this:0x00000030, function:0x00499B50]
    // GUARD: If the pointer field at this+0x30 is non-null. [field:this:0x00000030]
    // CALL: Cascade-clean the resource pointed to by this+0x30 via ResourceCascadeCleanup. [callee:0x005539F0, field:this:0x00000030]
    // ASSIGNMENT: Clear the field at this+0x30 to 0 after cleanup. [field:this:0x00000030]
    // GUARD: If the field at this+0x2C is non-zero. [field:this:0x0000002C]
    // RETURN: Invoke the object-level cleanup path for the this+0x2C resource (routine named DestructorWithConditionalFreeFlagClear in raw source; no callee address present in packet). [source:raw, field:this:0x0000002C]
    // RETURN: Return the saved this+0x30 cleanup outcome on the path where this+0x2C is zero. [source:raw]

    // Conservative worker pseudocode:
    //   result = this[12];
    //   if (result) { result = ResourceCascadeCleanup(result); this[12] = 0; }
    //   if (this[11]) return cleanup_object();
    //   return result;
    // UNRESOLVED: Global dword_8AFE64 (R) is listed but is not directly referenced in the raw source text; it is likely read inside one of the called cleanup routines.
    // UNRESOLVED: The object-level cleanup routine for this+0x2C has no callee address in the packet, so its identity and whether it returns a meaningful value are unverified.
}
