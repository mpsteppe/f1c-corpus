// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005116D4
// Canonical corpus name: FormatStringWithArgs
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FormatStringWithArgs_005116d4.c

void UnknownObject::FormatStringWithArgs()
{
    // Selects a format string from a format-state object by index, falling back to the first primary-table string (overriding the stored argument) when the index is out of range, then scans the selected string for a '%s' (115) sequence to choose between varargs and va_list calling conventions and delegates to StringFormatWithBufferOverflowCheck.
    // ASSIGNMENT: Load the format-state pointer v2 = *(DWORD**)a1 and read the stored format index v3 from the object. [field:this:0x00000000, field:obj:0x00000014, source:raw]
    // GUARD: Range-check v3 against the primary table count and the alternate table start/end bounds; out-of-range indices route to the fallback path. [field:obj:0x00000074, field:obj:0x00000078, field:obj:0x0000007C, field:obj:0x00000080, source:raw]
    // CALCULATION: Alternate-range resolution: v4 = *(char**)(alternate table base + 4 * (v3 - alternate start index)). [field:obj:0x00000078, field:obj:0x0000007C, source:raw]
    // CALCULATION: Primary-range resolution: v4 = *(char**)(primary table base + 4 * v3). [field:obj:0x00000070, source:raw]
    // GUARD: Fallback when the resolved string pointer is null: write v3 into the stored argument field and use the first primary-table string as the format string. [field:*(obj+0x70):0x00000000, field:obj:0x00000018, field:obj:0x00000070, source:raw]
    // LOOP: Scan the selected format string for a null terminator or a '%' (37) character; if the terminator is reached first, return StringFormatWithBufferOverflowCheck(a2, v4, stored arguments) passing the stored argument fields. [callee:0x0058815F, field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024, field:obj:0x00000028, field:obj:0x0000002C, field:obj:0x00000030, field:obj:0x00000034, source:raw]
    // GUARD: After a '%' is found, check whether the following character is not 's' (115); when it is not '%s', call StringFormatWithBufferOverflowCheck with the individual stored arguments (varargs form). [guard:0, callee:0x0058815F, field:obj:0x00000018, source:raw]
    // RETURN: For the '%s' (115) case, return StringFormatWithBufferOverflowCheck(a2, v4, pointer to the stored argument fields) using the va_list-style form. [callee:0x0058815F, field:obj:0x00000018, abi:lead, function:0x005116D4, source:raw]

    // Conservative worker pseudocode:
    //   state = *(void**)a1; index = state->stored_index;
    //   if (index within primary range) fmt = state->primary_table[index];
    //   else if (index within alternate range) fmt = state->alternate_table[index - state->alternate_start];
    //   else { state->stored_arg0 = index; fmt = state->primary_table[0]; }
    //   if end of string reached before '%': return format(dst, fmt, args...);
    //   if next char != 's': return format(dst, fmt, args...);
    //   return format(dst, fmt, &args);
    // UNRESOLVED: exact format-state object type and the meaning of its fields are unknown
    // UNRESOLVED: the varargs vs va_list call-form distinction is inferred from the '%s' (115) check only
}
