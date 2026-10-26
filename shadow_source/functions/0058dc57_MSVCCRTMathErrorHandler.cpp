// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DC57
// Canonical corpus name: MSVCCRTMathErrorHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MSVCCRTMathErrorHandler_0058dc57.c

void UnknownObject::MSVCCRTMathErrorHandler()
{
    // Thin __usercall wrapper in the MSVC CRT math-error-handler pattern: packs the incoming register and stack arguments into a small stack struct and forwards them to sub_596175(a2, v9, &a5), then returns the incoming x87 value a4 (st0) unchanged. The register-split ABI (a1 in eax, a2 in edx, a3 in ecx, a4 in st0) is exactly the MSVC _matherr-style glue shape, so the function preserves the original floating-point value while a handler side-effect runs.
    // ASSIGNMENT: Pack the argument struct: v9[0] = a1 (from eax), v9[1] = a3 (from ecx), v9[2] = a7, v9[3] = a8. [source:raw]
    // ASSIGNMENT: Preserve the x87 input value: v10 = a4 (from st0) so it can be returned unchanged. [source:raw]
    // CALL: Forward to the actual handler sub_596175(a2, v9, &a5), passing edx as the first argument, the packed struct as the second, and the address of the __int16 stack argument a5 as the third. [callee:0x00596175, source:raw]
    // RETURN: Return v10, the preserved original st0 value, regardless of the handler call result. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_58DC57(int a1, int a2, int a3, double a4, __int16 a5, int a6, int a7, int a8) {
    //     _DWORD v9[6];
    //     v9[0] = a1; v9[1] = a3; v9[2] = a7; v9[3] = a8;
    //     sub_596175(a2, v9, &a5);
    //     return a4;
    //   }
    // UNRESOLVED: Only the first four slots of the six-slot stack array v9 are written; v9[4] and v9[5] are left uninitialized by this function, so their contents depend on whatever sub_596175 reads.
    // UNRESOLVED: The stack argument a6 is not referenced anywhere in this function; its role is unknown.
    // UNRESOLVED: The layout and semantics of the packed struct consumed by sub_596175 are not recoverable from this function alone.
}
