// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486300
// Canonical corpus name: UIStringAccessor_6300
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIStringAccessor_6300_00486300.c

void UnknownObject::GetSubObjectStringWithFallback()
{
    // String accessor (__thiscall): loads the sub-object pointer at this+0xC8 (this[50]) and returns 0 immediately when it is null; otherwise reads the string pointer stored at sub-object+0x50 and returns it, falling back to the global byte_5EA438 path string when that pointer is null. The ABI lead names it UI_String_Accessor_486300.
    // GUARD: Load the sub-object pointer this[50] (offset +0xC8); when it is null, the accessor is blocked and returns 0 with no fallback. [field:this:0x000000C8, source:raw]
    // GUARD: Read the string pointer stored at sub-object+0x50; when it is null, return the global fallback path byte_5EA438 instead of the sub-object string. [global:0x005EA438, source:raw]
    // RETURN: Return the resolved string pointer: the sub-object+0x50 string on success, byte_5EA438 as the fallback, or 0 when the sub-object pointer at this+0xC8 is null. [function:0x00486300, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   char *GetSubObjectStringWithFallback(void *self) {
    //     void *sub = self[50];                /* +0xC8 * /
    //     if (!sub) return 0;
    //     char *s = *(char **)((char *)sub + 0x50);
    //     if (!s) return byte_5EA438;
    //     return s;
    //   }
    // UNRESOLVED: Field this+0x118 appears in the packet field list but is not referenced by the raw decompiled source; its role in this function is unknown.
    // UNRESOLVED: The owning object of the sub-object at this+0xC8 and the meaning of the byte_5EA438 fallback string are unidentified.
}
