// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507473
// Canonical corpus name: UtilityFunction_7473
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_7473_00507473.c

void UnknownObject::ColorGlobalValueStore()
{
    // Trivial global store shared by the color/texture encoding subsystem. Copies the incoming value v1 into the global dword_8B009C (0x008B009C) and returns it. The raw decompilation shows v1 as an uninitialized stack local, so the value likely arrives via a register-passed parameter that the decompiler did not recover; all 29 static callers are color/texture conversion helpers (VertexColorFloatToByte, TextureFloatTo32bitARGBPack, TextureEncode16Bit, DXTColorEncoder, etc.) that use this helper to publish a value to the shared global.
    // ASSIGNMENT: result = v1 copies the incoming value into the return slot. [source:raw]
    // ASSIGNMENT: dword_8B009C (global at 0x008B009C) = v1 publishes the value to the shared color/texture scratch global. [global:0x008B009C, source:raw]
    // RETURN: Return result, which holds the same value stored into the global. [function:0x00507473, source:raw]

    // Conservative worker pseudocode:
    //   int ColorGlobalValueStore(int v1) {
    //       dword_8B009C = v1;
    //       return v1;
    //   }
    // UNRESOLVED: v1 is an uninitialized stack local in the raw decompilation; the real argument source (likely a register-passed parameter) is not visible from this packet.
    // UNRESOLVED: The purpose of dword_8B009C is not determinable from this packet alone; the caller set (all color/texture encoders) suggests a shared scratch/state global but that is only a weak inference.
}
