// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593C50
// Canonical corpus name: sub_593C50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_593C50_00593c50.c

void UnknownObject::CallSettingFrameWrapper()
{
    // stdcall SEH-frame path helper: runs a setup call sub_588931(a3), makes an indirect call through a function pointer (v3), then normalizes the type code (remapping 256 to 2) and runs sub_588931 again with the normalized code. Both callers (SEHExceptionFrameWrapper at 0x0058A3B6 and SEHAwareVirtualCallDispatchLoop at 0x0059379B) place it on exception-frame dispatch; the legacy ABI name is CRT___CallSettingFrame_12.
    // CALL: Call sub_588931 with the raw argument a3 as the frame-setup step. [callee:0x00588931, source:raw]
    // CALL: Indirect call through function pointer v3 (probably the frame handler supplied by the caller); the target is not statically resolvable. [source:raw]
    // ASSIGNMENT: Initialize v4 from a3 so the unmodified value is used unless the guard fires. [source:raw]
    // GUARD: When a3 equals 256, remap the type code v4 to 2. [source:raw]
    // CALL: Call sub_588931 with the normalized type code v4 as the finalization step. [callee:0x00588931, source:raw]
    // CALL: Called from SEHExceptionFrameWrapper (0x0058A3B6) and SEHAwareVirtualCallDispatchLoop (0x0059379B), indicating use on the SEH exception-frame dispatch path. [caller:0x0058A3B6, caller:0x0059379B, source:raw]
    // RETURN: Return without a value (void). [source:raw]

    // Conservative worker pseudocode:
    //   void sub_593C50(int a1, int a2, int a3) {
    //     sub_588931(a3);
    //     v3();                       // indirect call through function pointer
    //     int v4 = a3;
    //     if (a3 == 256) v4 = 2;
    //     sub_588931(v4);
    //   }
    // UNRESOLVED: Provenance and target of the indirect call v3 (likely the a1 function-pointer argument) are not statically resolvable from the packet.
    // UNRESOLVED: Role of a2 is unknown; it is not used in the function body.
    // UNRESOLVED: Meaning of the 256 -> 2 type-code remap and sub_588931's contract are not established here.
    // UNRESOLVED: Legacy ABI name CRT___CallSettingFrame_12 suggests a CRT call-setting-frame helper, but the identity is not proven by packet evidence.
}
