// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC600
// Canonical corpus name: SurfaceSizeQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SurfaceSizeQuery_004dc600.c

void UnknownObject::SurfaceSizeQuery()
{
    // Looks up a wide-string key in a linked list, and if found, writes surface dimensions into a3/a4 scaled by per-entry factors (v8+92, v8+96) and caller-supplied float factors a5/a6. Outputs are zeroed when the key is not found. Callers: TextRenderDispatcher (0x004DD030) and TwoOutputPassthrough (0x004DD3A0).
    // CALL: Search the wide-string linked list with a1; keep the returned node in v8. [callee:0x0053D1F0, source:raw]
    // ASSIGNMENT: Zero both output parameters before any lookup result is applied: *a4 = 0 and *a3 = 0. [source:raw]
    // GUARD: Guard on the search result: the scaling block only runs when the list node v8 is non-null. [source:raw]
    // CALL: Fill a3/a4 with base surface dimensions via sub_5531F0(a2, a3, a4, 0). [callee:0x005531F0, source:raw]
    // CALCULATION: Scale the first output: *a3 = CRTFtol(*a3 * *(float *)(v8 + 92) * a5). [callee:0x00587BDC, source:raw]
    // CALCULATION: Scale the second output: result = CRTFtol(*a4 * *(float *)(v8 + 96) * a6); *a4 = result. [callee:0x00587BDC, source:raw]
    // RETURN: Return the linked-list search result (null when the key was absent, otherwise the found node). [source:raw]

    // Conservative worker pseudocode:
    //   int SurfaceSizeQuery(int key, int ctx, int *out_w, int *out_h, float fw, float fh) {
    //     void *node = WideStringLinkedListSearch(key);
    //     *out_w = 0;
    //     *out_h = 0;
    //     if (node) {
    //       sub_5531F0(ctx, out_w, out_h, 0);
    //       *out_w = CRTFtol(*out_w * *(float *)(node + 92) * fw);
    //       *out_h = CRTFtol(*out_h * *(float *)(node + 96) * fh);
    //     }
    //     return (int)node;
    //   }
    // UNRESOLVED: Semantics of the per-node scale factors at v8+92 and v8+96 (no field evidence in packet).
    // UNRESOLVED: Meaning of the sub_5531F0 fourth argument 0.
    // UNRESOLVED: dword_8AFE64 is listed as a read global but does not appear in the raw source.
}
