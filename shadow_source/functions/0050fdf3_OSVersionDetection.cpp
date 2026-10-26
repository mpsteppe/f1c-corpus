// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FDF3
// Canonical corpus name: OSVersionDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OSVersionDetection_0050fdf3.c

void UnknownObject::OSVersionDetection()
{
    // OS platform and CPU-feature detection. Queries the OS via GetVersionExA and dispatches on ProcessorFeature: on Win9x (platform id 1) or when GetVersionExA fails it uses CPUID helpers (CPUID3DNowDetection for feature 7, sub_50FD4E for SSE feature 6/10), while on NT (platform id 2) with a working API it falls back to IsProcessorFeaturePresent for feature values other than 10.
    // ASSIGNMENT: Zero the OSVERSIONINFOA buffer and set dwOSVersionInfoSize to 148. [source:raw]
    // CALL: Call GetVersionExA; when it fails, set flags v1 and v4 to 1 to force the legacy detection path. [global:0x0059E198]
    // GUARD: When platform id is 1 (Win9x): mark v4=1 for old builds (major below 4, or major 4 with minor below 0xA, or build below 0x55D) and continue at the legacy path. [source:raw]
    // GUARD: When platform id is neither 1 nor 2, return 0 immediately. [source:raw]
    // STATE_TRANSITION: When GetVersionExA failed (v1 set), route through the legacy CPUID detection path for all feature ids. [global:0x0059E198]
    // GUARD: On the legacy path, dispatch on ProcessorFeature: 6 (SSE), 7 (3DNow!), and 10 (SSE2) are handled; any other value returns 0. [source:raw]
    // CALL: For ProcessorFeature 7, call CPUID3DNowDetection to detect 3DNow! support. [callee:0x0050FD16]
    // CALL: For SSE feature 6 (with v4 clear) call sub_50FD4E on the service-pack string offset and return the bit-4 mask; for feature 10 return the bit-8 mask; on NT path feature 10 likewise returns sub_50FD4E bit-8 mask. [callee:0x0050FD4E]
    // CALL: On the NT path with a working GetVersionExA, delegate ProcessorFeature values other than 10 to the IsProcessorFeaturePresent API. [global:0x0059E22C]
    // RETURN: Return 0 for legacy builds (v4 set) or unsupported feature id combinations. [source:raw]

    // Conservative worker pseudocode:
    //   int OSVersionDetection(DWORD ProcessorFeature) {
    //     OSVERSIONINFOA vi; memset(&vi, 0, sizeof(vi));
    //     int legacy = 0, oldBuild = 0;
    //     vi.dwOSVersionInfoSize = 148;
    //     if (!GetVersionExA(&vi)) { legacy = 1; oldBuild = 1; }
    //     if (vi.dwPlatformId == 1) {
    //       if (vi.dwMajorVersion <= 4 && !(vi.dwMajorVersion == 4 && vi.dwMinorVersion >= 0xA && LOWORD(vi.dwBuildNumber) >= 0x55D)) oldBuild = 1;
    //     } else if (vi.dwPlatformId != 2) return 0;
    //     if (legacy) {
    //       if (ProcessorFeature == 7) return CPUID3DNowDetection();
    //       if (ProcessorFeature == 6) return oldBuild ? 0 : sub_50FD4E(&vi.szCSDVersion[16]) & 4;
    //       if (ProcessorFeature == 10 && !oldBuild) return sub_50FD4E(&vi.szCSDVersion[16]) & 8;
    //       return 0;
    //     }
    //     if (ProcessorFeature == 10) return sub_50FD4E(&vi.szCSDVersion[16]) & 8;
    //     return IsProcessorFeaturePresent(ProcessorFeature);
    //   }
    // UNRESOLVED: The byte_FF00000000005370..5374 globals are decompiler artifacts of the szCSDVersion[16] pointer arithmetic, not real module globals; they are listed for evidence completeness only.
    // UNRESOLVED: The exact semantics of sub_50FD4E's returned bitmask (bit 4 vs bit 8 for SSE vs SSE2) are inferred from the two distinct mask constants, not confirmed.
    // UNRESOLVED: The meaning of the v1/v4 dual flag when GetVersionExA succeeds on Win9x is not fully resolved.
}
