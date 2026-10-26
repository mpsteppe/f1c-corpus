// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004871F0
// Canonical corpus name: WrapperToSub487060
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WrapperToSub487060_004871f0.c

void UnknownObject::WrapperToSub487060()
{
    // Thin thiscall wrapper that forwards the object pointer to sub_487060 (0x00487060) with a constant second argument of 1 and returns its result unchanged. No fields, globals, or guards are touched.
    // CALL: Call sub_487060(this, 1), forwarding the object pointer and passing the constant integer 1 as the second argument. [callee:0x00487060, source:raw]
    // RETURN: Return the result of the sub_487060 call unchanged. [function:0x004871F0, source:raw]

    // Conservative worker pseudocode:
    //   int WrapperToSub487060(DWORD *this) {
    //     return sub_487060(this, 1);
    //   }
    // UNRESOLVED: The meaning of the constant 1 passed to sub_487060 is not evidenced by this packet (e.g. an enable/init flag or state value).
    // UNRESOLVED: The owning class and the purpose of sub_487060 (0x00487060) are not evidenced here.
}
