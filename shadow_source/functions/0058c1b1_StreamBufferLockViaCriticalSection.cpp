// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C1B1
// Canonical corpus name: StreamBufferLockViaCriticalSection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamBufferLockViaCriticalSection_0058c1b1.c

void UnknownObject::StreamBufferLockViaCriticalSection()
{
    // Free-function dispatcher that acquires the lock guarding a file stream. Streams inside the CRT global stream-array range [off_5E6748, unk_5E69A8] take the lazy-init indexed critical-section path (index = ((stream - off_5E6748) >> 5) + 28 via CriticalSectionLazyInitEnter); streams outside that range are treated as external objects and lock their embedded CRITICAL_SECTION at stream + 32 via the EnterCriticalSection function pointer. Called by the 20 stream/file wrapper callers listed in the packet, so it is the common lock-entry point for the CRT stream wrappers.
    // GUARD: Range check on the stream pointer a1: the external-stream path is taken when a1 < &off_5E6748 (CRT internal file stream array base) or a1 > &unk_5E69A8 (array end bound); otherwise the stream is inside the CRT global array. [source:raw, global:0x005E6748, global:0x005E69A8]
    // CALL: External-stream path: call EnterCriticalSection (Win32 function pointer global 0x0059E174) on the embedded CRITICAL_SECTION located at a1 + 32. [source:raw, global:0x0059E174]
    // CALL: CRT-array-stream path: call CriticalSectionLazyInitEnter with the lazy-init CS index computed as ((a1 - off_5E6748) >> 5) + 28. [source:raw, callee:0x0058DFEA, global:0x005E6748]

    // Conservative worker pseudocode:
    //   void StreamBufferLockViaCriticalSection(unsigned int stream)
    //   {
    //       if (stream < (unsigned int)&off_5E6748 || stream > (unsigned int)&unk_5E69A8)
    //           EnterCriticalSection((LPCRITICAL_SECTION)(stream + 32));
    //       else
    //           CriticalSectionLazyInitEnter(((int)(stream - (_DWORD)&off_5E6748) >> 5) + 28);
    //   }
    // UNRESOLVED: The +28 index offset added to the CRT array slot index is unexplained by packet evidence; its meaning (index base into a lazy-init CS array) is DERIVED from structure, not proven.
    // UNRESOLVED: The >> 5 division implies 32-byte stream slots, but the 32-byte stride is inferred and not directly evidenced.
    // UNRESOLVED: Whether a1 is a CRT FILE* / stream object pointer or a pointer to the start of a stream struct is not distinguished by packet evidence; the +32 embedded CS location depends on that layout.
    // UNRESOLVED: The EnterCriticalSection target at 0x0059E174 is a read global (function pointer) per the packet, but its import binding is assumed.
}
