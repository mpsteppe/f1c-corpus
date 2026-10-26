// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588864
// Canonical corpus name: GlobalUnwind2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalUnwind2_00588864.c

void UnknownObject::GlobalUnwind2()
{
    // MSVC CRT SEH helper that performs a global unwind: calls RtlUnwind(TargetFrame, &loc_58887C, 0, 0), passing the caller-supplied target frame, the local return-address label loc_58887C as the unwinding handler position, and null exception/context records. Used by ScriptFrameProcessor (0x0058895C) and LongjmpMSVCCRT (0x0058A770).
    // CALL: Call RtlUnwind with the caller-supplied TargetFrame, the local label loc_58887C as the exception-handler return address, and null exception and context records, performing the global unwind pass of the enclosing SEH frame. [callee:0x0059B24A, global:0x0058887C, source:raw]
    // RETURN: Return after RtlUnwind completes; the routine has no post-unwind code. [function:0x00588864, source:raw]

    // Conservative worker pseudocode:
    //   void GlobalUnwind2(PVOID TargetFrame) {
    //       RtlUnwind(TargetFrame, &loc_58887C, NULL, NULL);
    //   }
    // UNRESOLVED: The exact SEH frame state that makes loc_58887C the unwind return target is CRT-internal and not evidenced in the raw text.
    // UNRESOLVED: Whether TargetFrame is always a valid frame and how callers ensure that is not evidenced here.
}
