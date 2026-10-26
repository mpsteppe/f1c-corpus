// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00593C24
// Canonical corpus name: SEHFrameOffsetCalculationHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SEHFrameOffsetCalculationHelper_00593c24.c

void UnknownObject::SEHFrameOffsetCalculationHelper()
{
    // Computes an adjusted frame offset used for SEH exception-handler dispatch. Given a base value a1 and a descriptor a2 (three dwords), the result is a1 + a2[0]; if a2[1] is non-negative the result additionally accumulates a2[1] plus a dword read through a pointer obtained by dereferencing (a2[1] + a1) and indexing with a2[2].
    // CALCULATION: Load v2 = a2[1], the second dword of the descriptor triple. [source:raw]
    // CALCULATION: Initialize result = a1 + a2[0] using the primary offset in the descriptor. [source:raw]
    // GUARD: When v2 (a2[1]) is non-negative, apply the conditional SEH frame adjustment; negative values skip the term. [source:raw]
    // CALCULATION: On the v2 >= 0 path, accumulate result += v2 + *(*(v2 + a1) + a2[2]): dereference the dword at (v2 + a1) to obtain a table pointer, index it with a2[2], and add the value found there together with v2 itself. [source:raw]
    // RETURN: Return the accumulated adjusted offset. [function:0x00593C24, source:raw]

    // Conservative worker pseudocode:
    //   v2 = a2[1];
    //   result = a1 + a2[0];
    //   if (v2 >= 0)
    //     result += v2 + *(*(v2 + a1) + a2[2]);
    //   return result;
    // UNRESOLVED: The exact structure of the descriptor a2 (offset/sub-offset/table-index semantics) and the meaning of the double-indirect read are not evidenced by the packet; the SEH interpretation follows the corpus canonical name and the legacy ABI label.
    // UNRESOLVED: The single static caller is sub_5939F9 (caller:0x005939F9); its use of the returned offset is not evidenced here.
    // UNRESOLVED: The legacy ABI label (abi:lead) truncates to 'Compute_adjusted_offset_for_SEH_exception_handli'; the corpus canonical name SEHFrameOffsetCalculationHelper is retained.
}
