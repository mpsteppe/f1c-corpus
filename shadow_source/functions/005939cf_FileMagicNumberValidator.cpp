// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005939CF
// Canonical corpus name: FileMagicNumberValidator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileMagicNumberValidator_005939cf.c

void UnknownObject::FileMagicNumberValidator()
{
    // Validates a double-indirected pointer as a well-formed C++ exception record header: exception code 0xE06D7363 at record +0x0, NumberParameters == 3 at +0x10, magic 0x19930520 in ExceptionInformation[0] at +0x14, and no nested continuation (ExceptionInformation[2] == 0 at +0x1C). Returns TRUE only when all four checks pass, otherwise FALSE.
    // ASSIGNMENT: Load the exception record pointer v1 from the double-indirected argument (*a1). [field:this:0x00000000, source:raw]
    // GUARD: Guard: exception code at record +0x0 equals 0xE06D7363, the MSVC C++ exception signature. [guard:0, field:obj:0x00000000, source:raw]
    // GUARD: Guard: NumberParameters at record +0x10 equals 3. [guard:1, field:obj:0x00000010, source:raw]
    // GUARD: Guard: ExceptionInformation[0] at record +0x14 equals the magic 0x19930520. [guard:2, field:obj:0x00000014, source:raw]
    // GUARD: Guard: ExceptionInformation[2] at record +0x1C is zero, meaning there is no nested continuation record. [field:obj:0x0000001C, source:raw]
    // RETURN: Return the logical AND of all four checks: TRUE when every guard passes, FALSE otherwise. [source:raw]
    // CALL: Called by SEHWrapperAroundCRTFunctionCall (0x005938B4) as the gate before dispatch through the C++ exception path. [caller:0x005938B4, source:raw]

    // Conservative worker pseudocode:
    //   bool sub_5939CF(void** a1) {
    //     unsigned int* rec = (unsigned int*)*a1;
    //     return rec[0] == 0xE06D7363 && rec[4] == 3 && rec[5] == 0x19930520 && rec[7] == 0;
    //   }
    // UNRESOLVED: The EXCEPTION_RECORD layout is inferred from the field offsets 0x0/0x10/0x14/0x1C; the record pointer itself is supplied by the caller.
    // UNRESOLVED: The interpretation of ExceptionInformation[2] as a nested-continuation pointer is DERIVED from the zero-check pattern, not proven by the raw source.
}
