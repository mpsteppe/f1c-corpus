// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042E4A0
// Canonical corpus name: WeightedSumComparatorWithBinaryAdjustment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeightedSumComparatorWithBinaryAdjustment_0042e4a0.c

void UnknownObject::adjustWeightedBalance()
{
    // Balances two weighted-sum structs. While a2's weighted sum (baseValue + index*coefficient) exceeds a1's weighted sum beyond a tolerance multiplier, either decrements a2's current index (when flag set and index > 0) or increments a1's current index (while it stays below maxIndex - 1), then re-reads indices and re-checks the condition.
    // ASSIGNMENT: Load a2's current index (field +0x14) into v3. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Load a1's current index (field +0x14) into i. [field:this:0x00000014, source:raw]
    // LOOP: While a2's weighted sum (baseValue at +0x0 + current index * coefficient at +0x8) is greater than a1's weighted sum multiplied by the tolerance multiplier (global dbl_59E9F0), keep adjusting. [field:this:0x00000000, field:this:0x00000008, global:0x0059E9F0, source:raw]
    // GUARD: Decrement path requires flag a3 set AND v3 (a2's current index) > 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Decrement a2's current index (+0x14) by 1. [field:this:0x00000014, source:raw]
    // GUARD: Else path: if i (a1's current index) is not below a1's maxIndex (+0x10) minus 1, return immediately. [field:this:0x00000010, source:raw]
    // RETURN: Early return when a1's index is at the upper bound; no further adjustment possible. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Increment a1's current index (+0x14) by 1. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Re-read a1's current index after increment and continue loop. [field:this:0x00000014, source:raw]

    // Conservative worker pseudocode:
    //   v3 = a2->currentIndex;
    //   for (i = a1->currentIndex;
    //        a2->baseValue + v3 * a2->coefficient > (a1->baseValue + i * a1->coefficient) * tolerance;
    //        v3 = a2->currentIndex) {
    //     if (a3 && v3 > 0) a2->currentIndex = v3 - 1;
    //     else if (i >= a1->maxIndex - 1) return;
    //     else a1->currentIndex = i + 1;
    //     i = a1->currentIndex;
    //   }
    // UNRESOLVED: Exact role and value of global dbl_59E9F0 (0x0059E9F0) as the tolerance multiplier is inferred from context, not visible in the raw source.
}
