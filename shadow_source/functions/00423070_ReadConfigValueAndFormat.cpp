// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423070
// Canonical corpus name: sub_423070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_423070_00423070.c

void UnknownObject::ReadConfigValueAndFormat()
{
    // Resolves the 'config' entry of an input structure/collection (a1) via sub_587C20, formats the found value as "config=%s" into an 80-byte stack buffer through the length-checked StrlenFormatCallWrapper, and, when the format succeeds, returns the string copied to a persistent/reallocated buffer via StringCopyWithBufferRealloc. Fails fast with the source result if a1 is null, the key is absent, or formatting fails.
    // ASSIGNMENT: result = a1: the default (fall-through) return value is the input pointer itself [source:raw]
    // GUARD: If a1 is zero the function returns a1 immediately; all lookups are blocked [source:raw]
    // CALL: sub_587C20(a1, aConfig) looks up the 'config' key value inside the a1 structure/collection; the key string is the global aConfig at 0x005C303C [callee:0x00587C20, global:0x005C303C, source:raw]
    // GUARD: If the lookup result is zero (config key not found) the function returns 0 [source:raw]
    // CALL: StrlenFormatCallWrapper(result, "config=%s", v2) length-checked-formatting of the found value into the 80-byte stack buffer v2 [callee:0x005887ED, source:raw]
    // GUARD: If the format result is not exactly 1 the function returns the format result code; the copy step is blocked [source:raw]
    // CALL: StringCopyWithBufferRealloc(v2) copies the formatted string to a persistent/reallocated buffer and returns that buffer [callee:0x00566650, source:raw]
    // RETURN: Returns the copied buffer on success, otherwise the format result code, the lookup result, or the original a1; the caller is GameMainEntry (0x0045B200) [function:0x00423070, caller:0x0045B200, source:raw]

    // Conservative worker pseudocode:
    //   result = a1;
    //   if (a1) {
    //     value = sub_587C20(a1, aConfig);
    //     if (value) {
    //       rc = StrlenFormatCallWrapper(value, "config=%s", buf);
    //       if (rc == 1) return StringCopyWithBufferRealloc(buf);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: global 0x005C3030 (aConfigS) appears in the skeleton analysis but is not referenced by the raw decompiled source of this function; its role in this call cannot be confirmed from this packet
    // UNRESOLVED: The 'config' key string literal is embedded in the StrlenFormatCallWrapper call site and has no separate deterministic evidence reference
}
