// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00488B40
// Canonical corpus name: UIStringComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStringComparison_00488b40.c

void UnknownObject::UIStringCompareAndSet()
{
    // Compares an input string a2 against the stored string at this offset 0xB0 (falling back to byte_5EA438). If the strings differ, copies the new string via StringCopyWithBufferRealloc and invokes the vtable slot at offset 0x2C (slot 44) with argument 1 to notify/reload. Returns -1 when a2 is null, otherwise 0.
    // GUARD: If a2 is null, return -1 immediately. [source:raw]
    // ASSIGNMENT: v4 = this[44] (the stored string pointer at this offset 0xB0); when null, fall back to byte_5EA438. [field:this:0x000000B0, global:0x005EA438, source:raw]
    // GUARD: If strcmp(a2, v4) is non-zero the strings differ and the update path runs; equal strings fall through to return 0. [source:raw]
    // CALL: StringCopyWithBufferRealloc(a2) allocates and copies the new string into the buffer. [callee:0x00566650, source:raw]
    // CALL: Virtual dispatch through the vtable pointer at this offset 0x0, calling the method at obj offset 0x2C (slot 44) with this and argument 1 to notify/reload. [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Returns 0 after the compare/set path; returns -1 when a2 is null. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == null) return -1;
    //   current = this->stored_string_at_0xB0;
    //   if (!current) current = byte_5EA438;
    //   if (strcmp(a2, current) != 0) {
    //     StringCopyWithBufferRealloc(a2);
    //     vtable_slot_44(this, 1);
    //   }
    //   return 0;
    // UNRESOLVED: Meaning of the byte_5EA438 default path and the argument 1 passed to the vtable slot are not established from this function alone.
}
