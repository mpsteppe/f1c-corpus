// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475530
// Canonical corpus name: StateResetAndConditionalInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateResetAndConditionalInit_00475530.c

void UnknownObject::StateResetAndConditionalInit()
{
    // State reset and conditional network init: clears byte_7CD850, refreshes the network browser UI via sub_475150(this), then conditionally starts network discovery. StartNetworkUpdate(dword_7CD25C) runs only when dword_7D0E74 is zero, byte_7D0FAC is nonzero, and the flag byte at this+0x17C is still zero; it then sets that flag to 1. Returns the value of dword_7D0E74 (or the inner flag/byte on short-circuit paths).
    // ASSIGNMENT: Reset global flag byte_7CD850 to 0. [global:0x007CD850]
    // CALL: Call sub_475150(this) to refresh the network game browser UI list. [callee:0x00475150]
    // GUARD: Guard: proceed to LAN discovery only when dword_7D0E74 is zero; otherwise skip (result stays dword_7D0E74). [global:0x007D0E74]
    // GUARD: Guard: proceed only when byte_7D0FAC is nonzero (discovery enabled). [global:0x007D0FAC]
    // GUARD: Guard: proceed only when the flag byte at this+0x17C is zero (not yet started). [field:this:0x0000017C]
    // CALL: Call StartNetworkUpdate(dword_7CD25C) to start LAN network discovery. [callee:0x00461DE0, global:0x007CD25C]
    // ASSIGNMENT: Set the flag byte at this+0x17C to 1 to mark network update as started. [field:this:0x0000017C]
    // RETURN: Return result: dword_7D0E74 when the outer guard fails, otherwise the inner flag/byte value. [source:raw]

    // Conservative worker pseudocode:
    //   char StateResetAndConditionalInit(int this) {
    //     char result;
    //     byte_7CD850 = 0;
    //     sub_475150((_DWORD*)this);
    //     result = dword_7D0E74;
    //     if (!dword_7D0E74) {
    //       result = byte_7D0FAC;
    //       if (byte_7D0FAC) {
    //         result = *(_BYTE*)(this + 380);
    //         if (!result) {
    //           result = StartNetworkUpdate(dword_7CD25C);
    //           *(_BYTE*)(this + 380) = 1;
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of byte_7CD850 (password flag) and the exact network modes denoted by dword_7D0E74 values are inferred from context, not proven here.
    // UNRESOLVED: Return value semantics differ by guard path (dword_7D0E74 vs byte_7D0FAC vs the this+0x17C byte); the caller's use is unknown.
    // UNRESOLVED: sub_475150's UI-refresh role is named from existing analysis only.
}
