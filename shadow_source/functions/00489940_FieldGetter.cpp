// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489940
// Canonical corpus name: FieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldGetter_00489940.c

void UnknownObject::FieldGetter()
{
    // Field getter: returns the dword at offset 0x168 (this[90]) of the __thiscall receiver. No side effects. Its callers are UI and multiplayer/session handlers (key binding UI, password validation, session join), so the read field is likely a per-session or per-UI object flag/value, but its exact meaning is unknown here.
    // RETURN: Return the dword field at offset 0x168 of this (index 90 of the dword array view). [field:this:0x00000168, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_489940(void *this) {
    //     return *(int *)((char *)this + 0x168);
    //   }
    // UNRESOLVED: The identity of the owning object is unknown; the caller set (key-binding UI, multiplayer password validation, session join handler) is the only hint.
    // UNRESOLVED: The semantic meaning of the value at 0x168 is not established from this packet alone.
}
