// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513B51
// Canonical corpus name: sub_513B51
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_513B51_00513b51.c

void UnknownObject::SetFlagPairWithFloatConstant()
{
    // Gated dual flag-setter wrapper. When both a1 (this object) is non-null and the low DWORD of the packed 64-bit value a2 is non-zero, calls FlagSetterWithGuard_3b36(a1, a2, SBYTE4(a2)) to set a flag/state from a2 using its sign-extended high byte as the guard value, then calls FlagSetterFloatStore(a1, a2, 0.4545499980449677) to store the constant loaded from dbl_5AF4C8 into a related field. Returns nothing.
    // GUARD: If a1 is null the function returns immediately without performing either flag-setting call. [source:raw]
    // GUARD: If the low DWORD of a2 is zero the two flag-setting calls are skipped. [source:raw]
    // CALL: Call FlagSetterWithGuard_3b36(a1, a2, SBYTE4(a2)), passing a1, the packed 64-bit value a2 and the sign-extended high byte of a2 as the guard value. [callee:0x00513B36, source:raw]
    // CALL: Call FlagSetterFloatStore(a1, a2, 0.4545499980449677), the float constant loaded from dbl_5AF4C8 at global 0x005AF4C8. [callee:0x00513A56, global:0x005AF4C8, source:raw]
    // CALL: Invoked from sub_518D29 (0x00518D29). [caller:0x00518D29, source:raw]

    // Conservative worker pseudocode:
    //   void SetFlagPairWithFloatConstant(int a1, __int64 a2) {
    //     if (!a1 || !(_DWORD)a2) return;
    //     FlagSetterWithGuard_3b36(a1, a2, SBYTE4(a2));
    //     FlagSetterFloatStore(a1, a2, 0.4545499980449677); /* constant read from dbl_5AF4C8 * /
    //   }
    // UNRESOLVED: The semantics of a1 and a2 (likely a flag-bearing object and a packed flag/value) are unknown; the guard byte SBYTE4(a2) role is unproven.
    // UNRESOLVED: The purpose of the 0.4545499980449677 constant read from dbl_5AF4C8 is unknown; it is not established as a physical or tuning parameter.
    // UNRESOLVED: The exact fields written by FlagSetterWithGuard_3b36 and FlagSetterFloatStore are not visible from this function.
}
