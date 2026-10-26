// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045CD70
// Canonical corpus name: sub_45CD70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45CD70_0045cd70.c

void UnknownObject::NetworkAuthKeyInit()
{
    // One-time network-auth initializer. Guards on the init flag at this[0]: when already set it returns true immediately. Otherwise it clears the four scratch dwords at 0x8D4680-0x8D468C, decodes a 6-byte XOR key from byte_59F0C4 (each byte XOR 0x3E) into that scratch buffer, and calls sub_561BF0 passing this[1], the configuration pointer off_5C5B68, the decoded key buffer, four callback function pointers (DebugFloatFormatString, SceneTextureApply, BooleanParameterFormatDispatch, NetworkScorePingDisplay), and a trailing 0. On a zero return it stores true in the init flag and returns it.
    // GUARD: If the byte at this[0] is non-zero the object is already initialized and the function returns 1 immediately. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Clear the four scratch dwords dword_8D4680, dword_8D4684, dword_8D4688 and dword_8D468C to zero. [global:0x008D4680, global:0x008D4684, global:0x008D4688, global:0x008D468C, source:raw]
    // LOOP: For v3 in 0..5, write byte_59F0C4[v3] ^ 0x3E into the scratch buffer byte at &dword_8D4680 + v3, decoding a 6-byte key into the contiguous scratch region. [global:0x0059F0C4, global:0x008D4680, source:raw]
    // CALL: Call sub_561BF0(this[1], off_5C5B68, &dword_8D4680, DebugFloatFormatString, SceneTextureApply, BooleanParameterFormatDispatch, NetworkScorePingDisplay, 0) to register/initialize with the decoded key, configuration pointer and four callbacks. [callee:0x00561BF0, field:this:0x00000004, global:0x005C5B68, global:0x008D4680, global:0x0045CDE0, global:0x0045CF50, global:0x0045D0D0, global:0x0045D130, source:raw]
    // ASSIGNMENT: Store result = (sub_561BF0 returned 0) into the init flag byte at this[0]. [field:this:0x00000000, source:raw]
    // RETURN: Return the init flag value: true when initialization succeeded. [function:0x0045CD70, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_45CD70(this) {
    //     if (*(byte*)this) return true;
    //     dword_8D4680 = 0; dword_8D4684 = 0; dword_8D4688 = 0; dword_8D468C = 0;
    //     for (v3 = 0; v3 < 6; ++v3)
    //       *((byte*)&dword_8D4680 + v3) = byte_59F0C4[v3] ^ 0x3E;
    //     bool result = sub_561BF0(this[1], off_5C5B68, &dword_8D4680,
    //         DebugFloatFormatString, SceneTextureApply,
    //         BooleanParameterFormatDispatch, NetworkScorePingDisplay, 0) == 0;
    //     *(byte*)this = result;
    //     return result;
    //   }
    // UNRESOLVED: Purpose and exact contract of sub_561BF0's 8-argument call (key, config pointer, four callbacks, trailing 0) are not grounded beyond this call site.
    // UNRESOLVED: Role of the four callback globals (DebugFloatFormatString, SceneTextureApply, BooleanParameterFormatDispatch, NetworkScorePingDisplay) is inferred from naming only.
    // UNRESOLVED: Caller GlobalFlagBasedStateSetter (0x0045D490) relationship and trigger conditions are outside this function's raw source.
    // UNRESOLVED: Why the 6-byte key is stored XOR-obfuscated in byte_59F0C4 is unexplained by the raw source.
}
