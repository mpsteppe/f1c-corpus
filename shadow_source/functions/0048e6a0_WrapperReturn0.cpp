// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E6A0
// Canonical corpus name: WrapperReturn0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WrapperReturn0_0048e6a0.c

void UnknownObject::WrapperReturn0()
{
    // Thin __thiscall wrapper: forwards this to LinkedListNodeInsert_66e0 (0x004966E0), ignores its result, and returns 0. No fields, globals, or guards. Called by FunctionCallWrapper_6160 (0x00466160).
    // CALL: Forward this to LinkedListNodeInsert_66e0 (0x004966E0) without reading a return value. [source:raw, callee:0x004966E0]
    // RETURN: Always return the constant 0, discarding the callee result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_48E6A0(void* this) {
    //     LinkedListNodeInsert_66e0(this);
    //     return 0;
    //   }
    // UNRESOLVED: Why the callee result is discarded and 0 returned; contract between this wrapper and its single caller FunctionCallWrapper_6160 (0x00466160) is not evidenced.
    // UNRESOLVED: Object type is unknown; owner has no packet evidence.
}
