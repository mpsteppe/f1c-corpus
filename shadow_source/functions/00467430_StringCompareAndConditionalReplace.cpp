// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00467430
// Canonical corpus name: StringCompareAndConditionalReplace
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCompareAndConditionalReplace_00467430.c

void UnknownObject::StringCompareAndConditionalReplace()
{
    // Conditional string replace on an object holding a string buffer. Returns -1 early when the input string is null or when the current buffer already equals the input (plain strcmp). Otherwise copies the new string into the buffer with a length bound of (buffer size limit - 1) via sub_587DD0, null-terminates it, resets the tracked position pointer to the buffer start and advances it to the null terminator, then invokes the vtable method at slot 11 (vtable + 0x2C) with argument 1 to signal the change; returns 0 on success. Used by MenuOptionValueDisplay for menu option text.
    // GUARD: Return -1 when the input string a2 is null. [source:raw]
    // GUARD: Compare the current buffer string at this+0x2F0 against a2 with strcmp; return -1 when they are already equal. [field:this:0x000002F0, source:raw]
    // CALCULATION: Compute the max copy length as the buffer size limit this[190] (offset 0x2F8) minus 1. [field:this:0x000002F8, source:raw]
    // CALL: Copy the new string a2 into the buffer with the length bound via sub_587DD0. [callee:0x00587DD0, field:this:0x000002F0, source:raw]
    // ASSIGNMENT: Null-terminate the copied string at buffer[max copy length]. [field:this:0x000002F0, source:raw]
    // ASSIGNMENT: Reset the position pointer at this+0x2F4 to the start of the buffer. [field:this:0x000002F4, source:raw]
    // LOOP: Advance the position pointer at this+0x2F4 until the null terminator is reached. [field:this:0x000002F4, source:raw]
    // CALL: Invoke the vtable method at slot 11 (vtable + 0x2C) with argument 1 to signal the string change. [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // RETURN: Return 0 on a successful replacement; the guard paths return -1 instead. [source:raw]
    // CALL: Invoked by MenuOptionValueDisplay to update displayed option text. [caller:0x004673B0, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return -1;
    //   buf = this[188];
    //   if (strcmp(buf, a2) == 0) return -1;
    //   maxlen = this[190] - 1;
    //   sub_587DD0(buf, a2, maxlen);
    //   buf[maxlen] = 0;
    //   this[189] = buf;
    //   while (*this[189]) this[189]++;
    //   (*(this[0] + 0x2C))(this, 1);
    //   return 0;
    // UNRESOLVED: The status byte at this+0x2F5 is flagged as read by the static evidence but is not referenced in the visible decompilation; its purpose is unknown.
    // UNRESOLVED: Identity of the object and the meaning of the slot-11 vtable callback's integer argument (1) are not established from this packet.
    // UNRESOLVED: The buffer size limit this[190] semantics (exact capacity vs reserved bytes) is not resolvable from this packet alone.
}
