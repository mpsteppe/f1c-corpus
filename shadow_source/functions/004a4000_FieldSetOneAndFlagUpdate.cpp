// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4000
// Canonical corpus name: UtilityFunction_4000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_4000_004a4000.c

void UnknownObject::FieldSetOneAndFlagUpdate()
{
    // Small __thiscall helper that unconditionally writes DWORD field this+0x78 = 1 and DWORD field this+0x84 = 0, then, when the DWORD at this+0x64 is non-null, calls FlagFieldBitManipulation(1, 1, 1, 0) and returns its result. When this+0x64 is null the field writes still execute but the raw source returns an uninitialized value, so the return value on that path is undefined. Single caller is sub_4A00A0 (0x004A00A0).
    // ASSIGNMENT: Write 1 into DWORD field this+0x78 (this[30]); unconditional, executes before the guard. [field:this:0x00000078, source:raw]
    // ASSIGNMENT: Write 0 into DWORD field this+0x84 (this[33]); unconditional, executes before the guard. [field:this:0x00000084, source:raw]
    // GUARD: Guard on the DWORD at this+0x64 (this[25]): only when it is non-null is FlagFieldBitManipulation invoked; otherwise only the two field writes occur. [field:this:0x00000064, source:raw]
    // CALL: Call FlagFieldBitManipulation (0x0054C030) with constant arguments (1, 1, 1, 0) on the guard-true path. [callee:0x0054C030, source:raw]
    // RETURN: Return the FlagFieldBitManipulation result on the guard-true path; on the guard-false path the raw source returns the never-assigned local 'result', so the return value is undefined there. [source:raw]
    // CALL: Invoked by sub_4A00A0 (0x004A00A0), the only known caller. [caller:0x004A00A0, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall sub_4A4000(_DWORD *this) {
    //     this[30] = 1;   // this+0x78
    //     this[33] = 0;   // this+0x84
    //     if (this[25]) { // this+0x64 non-null
    //       return FlagFieldBitManipulation(1, 1, 1, 0);
    //     }
    //     return result;  // uninitialized in the raw decompilation
    //   }
    // UNRESOLVED: The meaning of the constant FlagFieldBitManipulation arguments (1, 1, 1, 0) is not established by the packet.
    // UNRESOLVED: The purpose of the this+0x64 guard and the semantics of the two written fields (0x78, 0x84) are not evidenced beyond the raw writes; the existing-analysis prose labels this+0x64 a 'sound source handle' at DERIVED trust, which is not adopted here.
    // UNRESOLVED: On the guard-false path the raw decompilation returns the never-assigned local 'result', leaving the return value undefined.
    // UNRESOLVED: The legacy ABI label 'General_utility_function_See_decompiled_code_for_4a4000' (abi:lead) carries no semantic signal; the proposed name follows the existing-analysis fill.
}
