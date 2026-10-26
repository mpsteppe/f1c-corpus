// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FD4E
// Canonical corpus name: sub_50FD4E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50FD4E_0050fd4e.c

void UnknownObject::DetectCPUSSEFeatures()
{
    // CPU feature detection (__usercall, ebp-anchored locals): installs a structured exception handler via SEHHandlerInit so the CPUID instruction is guarded against faulting on CPUs without CPUID support, writes the literal "GenuineIntel" into a stack-local vendor buffer, then runs CPUID leaf 0. If the returned max basic leaf is 0 the function returns the feature flags (still 0). Otherwise it runs CPUID leaf 1 and sets flag bit 0x4 when EDX bit 0x2000000 (SSE) is set and flag bit 0x8 when EDX bit 0x4000000 (SSE2) is set, returning the accumulated flags.
    // CALL: Call SEHHandlerInit to install a structured exception handler before executing CPUID, guarding against faults on CPUs that lack CPUID support. [callee:0x0058A5D8, source:raw]
    // ASSIGNMENT: Initialize the feature-flags result slot to 0 and set up the SEH registration chain (stack-local frame variables below the ebp anchor). [source:raw]
    // ASSIGNMENT: Copy the literal "GenuineIntel" (aGenuineIntel, 0x005ADE74) into a stack-local vendor buffer. [global:0x005ADE74, source:raw]
    // CALL: Execute CPUID leaf 0 with EAX = 0 and store EAX (max basic leaf), EBX, EDX and ECX into stack-local slots. [source:raw]
    // UNKNOWN: Code targets loc_50FD9A (0x0050FD9A) and loc_59C724 (0x0059C724) are referenced as SEH filter/continuation targets; the exact fault-handling behavior they implement is not modeled here. [global:0x0050FD9A, global:0x0059C724, source:raw]
    // GUARD: Guard: if CPUID leaf 0 EAX (max basic leaf) is 0, return the current feature flags (0) without probing leaf 1. [source:raw]
    // CALL: Execute CPUID leaf 1 with EAX = 1 and store EAX and EDX into stack-local slots. [source:raw]
    // CALCULATION: If CPUID leaf 1 EDX bit 0x2000000 is set (SSE support), OR flag 0x4 into the feature flags. [source:raw]
    // CALCULATION: If CPUID leaf 1 EDX bit 0x4000000 is set (SSE2 support), OR flag 0x8 into the feature flags. [source:raw]
    // RETURN: Return the accumulated feature-flag bitmask. [source:raw]
    // CALL: Called by OSVersionDetection (0x0050FDF3) to query CPU instruction-set features. [caller:0x0050FDF3, source:raw]

    // Conservative worker pseudocode:
    //   int sub_50FD4E(void) {
    //     int flags = 0;
    //     SEHHandlerInit();
    //     char vendor_buf[13]; strcpy(vendor_buf, "GenuineIntel");
    //     _EAX = 0; __asm { cpuid }
    //     int max_leaf = _EAX;
    //     if (max_leaf == 0) return flags;
    //     _EAX = 1; __asm { cpuid }
    //     int edx1 = _EDX;
    //     if (edx1 & 0x2000000) flags |= 4;
    //     if (edx1 & 0x4000000) flags |= 8;
    //     return flags;
    //   }
    // UNRESOLVED: The strcpy of "GenuineIntel" fills a stack-local vendor buffer, but no comparison against the CPUID leaf 0 vendor registers (EBX/EDX/ECX) is visible in this fragment, so the buffer's consumer is unknown.
    // UNRESOLVED: loc_50FD9A and loc_59C724 are SEH filter/continuation code targets whose exception-handling semantics are not modeled.
    // UNRESOLVED: The ebp-anchored stack slots (a1 offsets) are __usercall frame locals, not object fields; their exact types are unknown.
    // UNRESOLVED: Meaning of the returned flags beyond the SSE/SSE2 bits is not established.
}
