// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FC10
// Canonical corpus name: SelfRelativeCopyNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SelfRelativeCopyNormalize_0054fc10.c

void UnknownObject::SelfRelativeCopyNormalize()
{
    // Copies the input string a2 into the destination buffer lpSrcStr via strcpy, then hands the copied buffer to sub_589901 and returns its result. The legacy ABI label names this a self-relative copy-and-normalize helper; the actual normalization behavior lives in sub_589901, which is outside this packet.
    // ASSIGNMENT: strcpy(lpSrcStr, a2): copy the source string a2 into the destination buffer lpSrcStr. [source:raw, function:0x0054FC10]
    // CALL: Call sub_589901(lpSrcStr) with the freshly copied buffer; per the legacy ABI name this normalizes the self-relative string in place. [callee:0x00589901, source:raw]
    // RETURN: Return the result of sub_589901(lpSrcStr). [source:raw]

    // Conservative worker pseudocode:
    //   int SelfRelativeCopyNormalize(char *lpSrcStr, const char *a2)
    //   {
    //       strcpy(lpSrcStr, a2);
    //       return sub_589901(lpSrcStr);
    //   }
    // UNRESOLVED: What sub_589901 does to the copied buffer (the actual normalization) is not defined in this packet.
    // UNRESOLVED: Why the result of sub_589901 is returned as the function's int value is not explained by any packet evidence.
    // UNRESOLVED: Callers (sub_546AA0, ResourceObjectCreationWithConfig, DirectXMeshVertexBufferParsingAndLoading) all use this via a self-relative resource path, but no packet evidence shows how the return value is consumed.
}
