// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FC58
// Canonical corpus name: sub_50FC58
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FC58_0050fc58.c

void UnknownObject::CPUFeatureCheck()
{
    // CPU feature probe (stdcall): executes the cpuid instruction with EAX = 1 and returns whether EDX bit 23 (the mask 0x800000) is set, i.e. whether the probed feature flag is present.
    // ASSIGNMENT: Set EAX = 1 to select cpuid leaf 1 before executing cpuid. [source:raw]
    // CALL: Execute the cpuid instruction (inline asm); the feature flags are returned in EDX. [source:raw]
    // GUARD: Test (EDX & 0x800000) != 0, where 0x800000 is the bit mask taken from the constant global unk_800000 at 0x00800000; the boolean result is returned. [global:0x00800000, source:raw]
    // RETURN: Return TRUE when the 0x800000 feature bit is set in cpuid leaf-1 EDX, otherwise FALSE. [source:raw]
    // CALL: Called by sub_50FC7D (0x0050FC7D), which relies on this probe when checking CPU capabilities. [caller:0x0050FC7D, function:0x0050FC58, source:raw]

    // Conservative worker pseudocode:
    //   BOOL __stdcall CPUFeatureCheck(void) {
    //     _EAX = 1;
    //     __asm { cpuid }
    //     return ((unsigned int)&unk_800000 & _EDX) != 0;
    //   }
    // UNRESOLVED: The specific CPU feature named by EDX bit 23 (0x800000) is not identified in the packet; the raw source references it only through the constant global unk_800000.
    // UNRESOLVED: Whether sub_50FC7D branches on this result to a specific code path or data path is outside this function's evidence.
}
