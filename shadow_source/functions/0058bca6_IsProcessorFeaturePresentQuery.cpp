// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BCA6
// Canonical corpus name: sub_58BCA6
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BCA6_0058bca6.c

void UnknownObject::IsProcessorFeaturePresentQuery()
{
    // Queries a processor feature flag via the Win32 IsProcessorFeaturePresent API, resolved dynamically from kernel32.dll. Resolves the KERNEL32 module handle with GetModuleHandleA, then GetProcAddress for the IsProcessorFeaturePresent export, calling it with feature id 0. If the module handle or the export is unavailable, falls back to the internal CPU-feature probe sub_58BC68.
    // CALL: Call GetModuleHandleA with the module-name string literal "KERNEL32" to obtain the kernel32 module handle. [global:0x0059E21C, global:0x005B8D74, source:raw]
    // GUARD: If GetModuleHandleA returned null, skip API resolution and use the fallback path. [global:0x0059E21C, source:raw]
    // CALL: Call GetProcAddress with the module handle and the export-name string literal "IsProcessorFeaturePresent" to resolve the API function pointer. [global:0x0059E0CC, global:0x005B8D58, source:raw]
    // GUARD: If GetProcAddress returned null, the API is not available and the fallback path is used. [global:0x0059E0CC, source:raw]
    // CALL: Call the resolved IsProcessorFeaturePresent with feature id 0 and return its result. [source:raw]
    // RETURN: Return the result of the internal CPU-feature fallback probe when the dynamic API resolution failed. [source:raw]

    // Conservative worker pseudocode:
    //   int IsProcessorFeaturePresentQuery() {
    //     HMODULE h = GetModuleHandleA("KERNEL32");
    //     if (h) {
    //       IsProcessorFeaturePresentFn fn = (IsProcessorFeaturePresentFn)GetProcAddress(h, "IsProcessorFeaturePresent");
    //       if (fn) return fn(0);
    //     }
    //     return sub_58BC68();
    //   }
    // UNRESOLVED: The fallback probe sub_58BC68 is not detailed in this packet; its feature-detection semantics are unevidenced here.
    // UNRESOLVED: The exact meaning of feature id 0 (which PF_* flag it selects) is not evidenced in this packet.
    // UNRESOLVED: Caller is InitWrapperCalling3Subroutines (00587b7f); the initialization context that consumes the returned flag is outside this packet.
}
