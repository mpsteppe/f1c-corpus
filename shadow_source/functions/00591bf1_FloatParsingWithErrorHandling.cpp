// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591BF1
// Canonical corpus name: FloatParsingWithErrorHandling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatParsingWithErrorHandling_00591bf1.c

void UnknownObject::FloatParsingWithErrorHandling()
{
    // Parsing wrapper that always restores the FPU control word (ReturnFPUControlWord with 0xFFFF), then branches on the constant-table lookup IDToValueTableLookupInConstantTable(a2). On the success path it clears the error state only when StubReturning0() is false; on the fallback path it unconditionally sets the error code from the input range. Both branches return the input double a7 unchanged.
    // CALL: Query the constant-table lookup: IDToValueTableLookupInConstantTable(a2); a non-zero result selects the success path. [callee:0x00591CA1, source:raw]
    // GUARD: Branch on the table-lookup result; both branches converge on returning a7. [callee:0x00591CA1, source:raw]
    // CALL: Restore the FPU control word: ReturnFPUControlWord(a8, 0xFFFF); executed on both branches. [callee:0x00591E66, source:raw]
    // CALL: Success path: query StubReturning0(); when it returns 0, set the error code from the input range via SetErrorCodeBasedOnInputRange(a1). [callee:0x0058FB7E, callee:0x00591C79, source:raw]
    // CALL: Fallback path: unconditionally set the error code from the input range via SetErrorCodeBasedOnInputRange(a1). [callee:0x00591C79, source:raw]
    // RETURN: Return the input double a7 unchanged on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   double FloatParsingWithErrorHandling(int a1, int a2, int a3, int a4, int a5, int a6, double a7, int a8) {
    //     ReturnFPUControlWord(a8, 0xFFFF);
    //     if (IDToValueTableLookupInConstantTable(a2)) {
    //       if (!StubReturning0())
    //         SetErrorCodeBasedOnInputRange(a1);
    //     } else {
    //       SetErrorCodeBasedOnInputRange(a1);
    //     }
    //     return a7;
    //   }
    // UNRESOLVED: Parameter roles (a1 input range, a2 lookup selector, a8 FPU context) are inferred from the call pattern; the packet provides no owner or parameter evidence.
    // UNRESOLVED: StubReturning0 (0x0058FB7E) is named by its known stub behavior; its semantic role (exception/domain guard) is not established.
    // UNRESOLVED: SetErrorCodeBasedOnInputRange (0x00591C79) is a usage-derived name; the exact error-code enum is not recovered.
    // UNRESOLVED: The prelabel marks this as a structural twin of sub_45B5C0 (cluster_copy), but no evidence for that relationship is present in the packet.
}
