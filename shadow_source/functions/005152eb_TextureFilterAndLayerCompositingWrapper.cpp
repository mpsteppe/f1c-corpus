// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005152EB
// Canonical corpus name: FileIOWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileIOWrapper_005152eb.c

void UnknownObject::TextureFilterAndLayerCompositingWrapper()
{
    // Cdecl wrapper around TextureFilterAndLayerCompositing(a2, a1, 1) that returns 0 on any non-negative result and otherwise propagates the negative result.
    // CALL: Calls TextureFilterAndLayerCompositing(a2, a1, 1), passing the float pointer first, the integer second, and the literal constant 1. [callee:0x005147EA, source:raw]
    // GUARD: Branches on the callee result: when it is greater than or equal to 0, the wrapper returns 0. [source:raw, function:0x005152EB]
    // RETURN: When the callee result is negative, returns that negative result unmodified (treated as a propagated error/status code). [source:raw]

    // Conservative worker pseudocode:
    //   int result = TextureFilterAndLayerCompositing(a2, a1, 1);
    //   if (result >= 0)
    //     return 0;
    //   return result;
    // UNRESOLVED: Meaning of the constant argument 1 and the exact contract of TextureFilterAndLayerCompositing (0x005147EA) are outside this packet.
}
