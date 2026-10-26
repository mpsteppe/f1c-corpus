// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004765F0
// Canonical corpus name: LoadPathGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoadPathGetter_004765f0.c

void UnknownObject::LoadPathGetter()
{
    // Accessor that returns a load path string pointer stored at this+0x04. When that pointer is null it returns the global default string byte_5EA438 (an application/default directory path).
    // GUARD: Guard on load path pointer at this+0x04: if null, fall through to return the default string. [field:this:0x00000004, global:0x005EA438]
    // ASSIGNMENT: Load the load path string pointer from this[1] (byte offset 0x04). [field:this:0x00000004, source:raw]
    // RETURN: Return the load path pointer, or byte_5EA438 when the pointer is null. [global:0x005EA438, source:raw, function:0x004765F0]

    // Conservative worker pseudocode:
    //   char *sub_4765F0(void *this) {
    //     char *path = *(char **)((char *)this + 0x04);
    //     if (!path) return byte_5EA438;
    //     return path;
    //   }
    // UNRESOLVED: Object type holding the path at this+0x04 is unknown.
    // UNRESOLVED: Semantics of byte_5EA438 (default directory path) are DERIVED, not CONFIRMED.
}
