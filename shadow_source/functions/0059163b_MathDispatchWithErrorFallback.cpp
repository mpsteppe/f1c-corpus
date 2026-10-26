// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059163B
// Canonical corpus name: MathDispatchWithErrorFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MathDispatchWithErrorFallback_0059163b.c

void UnknownObject::MathDispatchWithErrorFallback()
{
    // Floating-point parse dispatcher with an FPE guard. When the C-runtime FPE exception flag dword_5E9AD0 is non-zero, it writes error code 33 through the TLS slot returned by TLSOffsetGetter, resets the FPU control word via ReturnFPUControlWord(a3, 0xFFFF), and returns the input double a2 unchanged. When the flag is clear it delegates to FloatParsingWithErrorHandling(1, a1, low dword of a2, high dword of a2, 0, 0, a2, a3) and returns the resulting double.
    // GUARD: If dword_5E9AD0 (C-runtime FPE exception flag) is non-zero, take the short-circuit error path. [global:0x005E9AD0, source:raw]
    // CALL: Write error code 33 through the TLS slot returned by TLSOffsetGetter. [callee:0x0058AFCF, source:raw]
    // CALL: Reset the FPU control word with ReturnFPUControlWord(a3, 0xFFFF). [callee:0x00591E66, source:raw]
    // RETURN: Error path: return the input double a2 unchanged. [source:raw]
    // CALL: Parse path: delegate to FloatParsingWithErrorHandling with the flag 1, the string a1, the low and high dwords of a2, two zeroed dwords, the original double a2 and a3. [callee:0x00591BF1, source:raw]
    // RETURN: Return the double produced by FloatParsingWithErrorHandling. [source:raw]
    // CALL: Invoked by sub_5895A2 as the gated floating-point parse entry. [caller:0x005895A2, source:raw]

    // Conservative worker pseudocode:
    //   double MathDispatchWithErrorFallback(int a1, double a2, int a3) {
    //     if (dword_5E9AD0) {
    //       *(int*)TLSOffsetGetter() = 33;
    //       ReturnFPUControlWord(a3, 0xFFFF);
    //       return a2;
    //     }
    //     return FloatParsingWithErrorHandling(1, a1, LODWORD(a2), HIDWORD(a2), 0, 0, a2, a3);
    //   }
    // UNRESOLVED: The meaning of TLS error code 33 and the identity of the consumer of that TLS slot are established by the C-runtime error layer, not visible in this packet.
    // UNRESOLVED: The exact FPU-mask meaning of the constant 0xFFFF passed to ReturnFPUControlWord is owned by that callee.
    // UNRESOLVED: The pass-through semantics of the two zeroed dwords and the duplicate a2 argument in the FloatParsingWithErrorHandling call are defined by that callee.
}
