// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465160
// Canonical corpus name: WheelSpeedConversionWithZeroGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WheelSpeedConversionWithZeroGuard_00465160.c

void UnknownObject::WheelSpeedConversionWithZeroGuard()
{
    // Zero-guarded conversion of two speed inputs (a2, a3) into wheel-speed units (1000*x/8), stored to offsets 0x50 and 0x54 of the object whose base is resolved by dereferencing this+0x0. Each store happens only when the promoted input is greater than 0.0; non-positive inputs are skipped. Returns void. Called by SessionTypeSetter (0x00463F70).
    // GUARD: Zero-guard on first speed input: when a2 promoted to double is > 0.0 the conversion and store proceed; otherwise the store to offset 0x50 is skipped. [function:0x00465160, source:raw, global:0x0059E440, abi:lead]
    // CALCULATION: Convert a2 to wheel-speed units with integer formula 1000 * a2 / 8. [function:0x00465160, source:raw]
    // ASSIGNMENT: Store the converted first wheel speed (1000*a2/8) at offset 0x50 of the object base resolved by dereferencing this+0x0. [field:obj:0x00000050, field:this:0x00000000, function:0x00465160, source:raw]
    // GUARD: Zero-guard on second speed input: when a3 promoted to double is > 0.0 the conversion and store proceed; otherwise the store to offset 0x54 is skipped. [function:0x00465160, source:raw, global:0x0059E440]
    // CALCULATION: Convert a3 to wheel-speed units with integer formula 1000 * a3 / 8. [function:0x00465160, source:raw]
    // ASSIGNMENT: Store the converted second wheel speed (1000*a3/8) at offset 0x54 of the object base resolved by dereferencing this+0x0. [field:obj:0x00000054, field:this:0x00000000, function:0x00465160, source:raw]
    // RETURN: Return void; the function produces no return value. [abi:lead, function:0x00465160, source:raw]

    // Conservative worker pseudocode:
    //   void WheelSpeedConversionWithZeroGuard(this, a2, a3) {
    //     if ((double)a2 > 0.0) *(DWORD*)(*(DWORD*)this + 0x50) = 1000 * a2 / 8;
    //     if ((double)a3 > 0.0) *(DWORD*)(*(DWORD*)this + 0x54) = 1000 * a3 / 8;
    //   }
    // UNRESOLVED: Exact type of the object referenced by `this` is unknown; the packet's owner is UnknownObject with no class identity evidence.
    // UNRESOLVED: Global flt_59E440 (0x0059E440) does not appear in the raw source text; its role as the zero-threshold constant behind the guards is DERIVED from existing analysis, not confirmed by the raw source.
}
