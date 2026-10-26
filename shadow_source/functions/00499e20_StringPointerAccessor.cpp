// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499E20
// Canonical corpus name: StringPointerAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringPointerAccessor_00499e20.c

void UnknownObject::StringPointerAccessor()
{
    // String pointer accessor. Reads the string pointer stored at this+0x10 (this[4]); when that pointer is null it returns the default path string global byte_5EA438, otherwise it returns the stored pointer. A small accessor used by resource-path, session and linked-list search callers on the frame path.
    // GUARD: Null check on the pointer field at this+0x10 (this[4]) selects the fallback path [field:this:0x00000010, source:raw]
    // RETURN: When the stored pointer is null, returns the default path string global byte_5EA438 [global:0x005EA438, source:raw]
    // RETURN: Otherwise returns the string pointer stored at this+0x10 (this[4]) [field:this:0x00000010, function:0x00499E20, source:raw]
    // CALL: Used by resource/session path lookup callers such as ResourceIDLookupByNameString and SessionConfigReader to obtain the active path string [caller:0x00407F10, caller:0x004C11E0, source:raw]

    // Conservative worker pseudocode:
    //   result = this[4];
    //   if (result == null) return byte_5EA438;
    //   return result;
    // UNRESOLVED: The content and role of the default string global byte_5EA438 (a path used when the object field is unset) are not defined in this packet; the accessor only forwards it
}
