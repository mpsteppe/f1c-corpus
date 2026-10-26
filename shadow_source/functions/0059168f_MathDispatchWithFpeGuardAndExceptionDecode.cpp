// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059168F
// Canonical corpus name: ConditionalMathWithDAT005e9ad0Flag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalMathWithDAT005e9ad0Flag_0059168f.c

void UnknownObject::MathDispatchWithFpeGuardAndExceptionDecode()
{
    // Floating-point math dispatch with exception-code decode and an FPE guard. When sub_5919DA(dwExceptionCode, &a4, a5) reports failure, clears bit 0 of the uninitialized local v8 and calls sub_591727 to set up the exception-handling argument array. Then decodes dwExceptionCode into operation bit flags via BitFlagDecoderViaBitTests (v5). If the FPE flag dword_5E9AD0 is set or v5 is zero, takes the error path: sets a TLS error code based on v5 through SetErrorCodeBasedOnInputRange, resets the FPU control word to mask 0xFFFF via ReturnFPUControlWord, and returns the fallback value a4. Otherwise returns a3 as the result after forwarding the double a3 (as two DWORD halves) plus a4 and a5 to FloatParsingWithErrorHandling.
    // CALL: sub_5919DA(dwExceptionCode, &a4, a5) checks the exception code and parameters; the zero return selects the setup path [callee:0x005919DA, source:raw]
    // GUARD: If sub_5919DA returns 0 (false), continue into exception-context setup instead of skipping it [source:raw]
    // ASSIGNMENT: v8 &= ~1u clears bit 0 of the (uninitialized) stack local v8 [source:raw]
    // CALL: sub_591727(Arguments, &a5, dwExceptionCode, a2, &a3, &a4) fills the exception-handling argument array on the setup path [callee:0x00591727, source:raw]
    // CALL: v5 = BitFlagDecoderViaBitTests(dwExceptionCode) decodes the exception code into operation mode bit flags [callee:0x00591CC6, source:raw]
    // GUARD: Error-path guard: if dword_5E9AD0 (FPE flag) is non-zero OR v5 (decoded mode) is zero, take the error path instead of parsing [global:0x005E9AD0, source:raw]
    // CALL: SetErrorCodeBasedOnInputRange(v5) writes the TLS error code derived from the decoded mode value [callee:0x00591C79, source:raw]
    // CALL: ReturnFPUControlWord(a5, 0xFFFF) resets the FPU control word with mask 0xFFFF [callee:0x00591E66, source:raw]
    // RETURN: Error path returns a4 as the fallback value [source:raw]
    // ASSIGNMENT: result = a3 selects a3 as the return value on the parse path [source:raw]
    // CALL: FloatParsingWithErrorHandling(v5, a2, low DWORD of a3, high DWORD of a3, 0.0 as a 64-bit zero, high half of that zero, a4, a5) performs the actual floating-point parse [callee:0x00591BF1, source:raw]
    // RETURN: Parse path returns result (a3) [source:raw]
    // CALL: Called per-frame tick from sub_5895A2 (005895a2) [caller:0x005895A2]

    // Conservative worker pseudocode:
    //   double MathDispatchWithFpeGuardAndExceptionDecode(DWORD dwExceptionCode, int a2, double a3, double a4, int a5) {
    //     if (!sub_5919DA(dwExceptionCode, &a4, a5)) {
    //       v8 &= ~1u;
    //       sub_591727(Arguments, &a5, dwExceptionCode, a2, &a3, &a4);
    //     }
    //     int v5 = BitFlagDecoderViaBitTests(dwExceptionCode);
    //     if (dword_5E9AD0 || !v5) {
    //       SetErrorCodeBasedOnInputRange(v5);
    //       ReturnFPUControlWord(a5, 0xFFFF);
    //       return a4;
    //     }
    //     double result = a3;
    //     FloatParsingWithErrorHandling(v5, a2, LOW(a3), HIGH(a3), 0.0, 0, a4, a5);
    //     return result;
    //   }
    // UNRESOLVED: v8 is an uninitialized stack local in the raw source; the &= ~1u is a decompiler artifact whose intended meaning is unclear
    // UNRESOLVED: The semantics of each decoded bit flag from BitFlagDecoderViaBitTests and how it maps to SetErrorCodeBasedOnInputRange is not documented
    // UNRESOLVED: The identity of dword_5E9AD0 as an FPE exception flag is DERIVED from the existing fill analysis, not established by the packet
    // UNRESOLVED: Why the 64-bit zero argument is passed as two halves to FloatParsingWithErrorHandling is a decompiler artifact
    // UNRESOLVED: Owner class identity is not established by the packet
}
