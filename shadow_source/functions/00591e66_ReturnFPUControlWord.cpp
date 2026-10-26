// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591E66
// Canonical corpus name: ReturnFPUControlWord
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReturnFPUControlWord_00591e66.c

void UnknownObject::ReturnFPUControlWord()
{
    // Identity pass-through (__fastcall) on a __int16 argument a1, named for the FPU control-word semantics inferred from its callers. It performs no computation: the input value is returned unchanged, consistent with a helper that surfaces the current FPU control word for inspection.
    // ASSIGNMENT: Receive the 16-bit argument a1 unchanged; no transformation is applied to it. [source:raw, function:0x00591E66]
    // RETURN: Return a1 as the function result (identity on the __int16 value). [source:raw, abi:lead]
    // CALL: Called by sub_5895A2 (0x005895A2), MathDispatchWithErrorFallback (0x0059163B), ConditionalMathWithDAT005e9ad0Flag (0x0059168F), FloatParsingWithErrorHandling (0x00591BF1) and sub_596175 (0x00596175), consistent with an FPU-state query helper. [caller:0x005895A2, caller:0x0059163B, caller:0x0059168F, caller:0x00591BF1, caller:0x00596175, source:raw]

    // Conservative worker pseudocode:
    //   int sub_591E66(__int16 a1) { return a1; }
    // UNRESOLVED: The FPU-control-word purpose is inferred from the __int16 argument and the calling contexts; the function body only passes a1 through.
}
