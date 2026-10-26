// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00587DB0
// Canonical corpus name: sub_587DB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_587DB0_00587db0.c

void UnknownObject::FixedArgDelegation()
{
    // Thin cdecl delegation: forwards both incoming arguments (a1, a2) to sub_587D7F together with the fixed literal third argument 64, and returns sub_587D7F's result unchanged. Called from a wide range of file/settings loaders (ConfigIniParser, VehFileParser, AIDatabase_Init, file-open wrappers), consistent with a shared file-open/read-mode helper.
    // CALL: Call sub_587D7F(a1, a2, 64), passing both incoming arguments plus the fixed constant 64 as the third argument. [callee:0x00587D7F, source:raw]
    // RETURN: Return the result of sub_587D7F unchanged. [callee:0x00587D7F, source:raw]

    // Conservative worker pseudocode:
    //   return sub_587D7F(a1, a2, 64);
    // UNRESOLVED: The fixed third argument 64 passed to sub_587D7F has no documented meaning in the packet (likely a buffer size or flag).
    // UNRESOLVED: sub_587D7F is a mid-function entry of the neighboring routine; its own body is not in this packet, so the effect of a1/a2/64 is inferred only from the delegation shape.
}
