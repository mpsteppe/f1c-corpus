// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059B250
// Canonical corpus name: Direct3DCreate8
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Direct3DCreate8_0059b250.c

void UnknownObject::Direct3DCreate8()
{
    // Thunk forwarding the Direct3DCreate8 call to the imported D3D8 entry point at global 0x0059E370, passing the argument unchanged and returning its result. No logic of its own; the imported symbol is resolved at load time by the import table.
    // CALL: Call the imported Direct3DCreate8 entry point stored at 0x0059E370 with argument a1. [global:0x0059E370, source:raw]
    // RETURN: Return the imported function's result unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int Direct3DCreate8(int sdkVersion) {
    //     return __imp_Direct3DCreate8(sdkVersion);
    //   }
    // UNRESOLVED: No unresolved evidence; the sole global (0x0059E370) is consumed by the forward call.
}
