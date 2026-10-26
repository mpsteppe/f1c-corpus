// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051E1EF
// Canonical corpus name: CombinatorialPermutationGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CombinatorialPermutationGenerator_0051e1ef.c

void UnknownObject::CombinatorialPermutationGenerator()
{
    // Generates and advances combinatorial permutations of a dimension set. Computes the smallest factorial that meets the target count (this+0x54), reports error 55 through the object vtable if the base (this+0x64) is below 2, fills the permutation state array, then advances positions in mixed-radix fashion until the total exceeds the target. In mode 2 (this+0x28 == 2) indices are remapped through global dword_5B06C8.
    // ASSIGNMENT: Load permutation base v3 = a1[25] (this+0x64). [field:this:0x00000064]
    // ASSIGNMENT: Load target count v14 = a1[21] (this+0x54). [field:this:0x00000054]
    // LOOP: Grow base v4 and factorial v5 until factorial exceeds target count this+0x54. [field:this:0x00000054, source:raw]
    // GUARD: If minimumBase v7 < 2, take the error path through the object vtable. [source:raw]
    // ASSIGNMENT: Write error code 55 to obj+0x14. [field:obj:0x00000014]
    // ASSIGNMENT: Write computed factorial to obj+0x18. [field:obj:0x00000018]
    // CALL: Indirect call through object vtable pointer *a1 (this+0x0 / obj+0x0) passing a1. [field:this:0x00000000, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Fill permutation state array a2 with minimumBase using memset32 for dimensionCount entries. [source:raw]
    // CALCULATION: Compute accumulator v15 = minimumBase^dimensionCount via repeated multiplication loop. [source:raw]
    // GUARD: If mode a1[10] (this+0x28) == 2, remap index through global lookup table dword_5B06C8. [guard:0, field:this:0x00000028]
    // ASSIGNMENT: Read remap value dword_5B06C8[index] for the permutation index. [global:0x005B06C8]
    // LOOP: Advance positions: increment current base, recompute accumulator as product, and stop when accumulator exceeds target count this+0x54 or all dimensionCount positions are exhausted. [field:this:0x00000054, source:raw]
    // LOOP: Repeat the advance loop until no position changed (changedFlag unset) or dimensionCount <= 0. [source:raw]
    // RETURN: Return final accumulator v15. [source:raw]

    // Conservative worker pseudocode:
    //   int CombinatorialPermutationGenerator(this, permArray) {
    //     dims = this[25];
    //     target = this[21];
    //     base = 1;
    //     do { factorial *= ++base; } while (factorial <= target);
    //     minBase = base - 1;
    //     if (minBase < 2) {
    //       (*this)[5] = 55;
    //       (*this)[6] = factorial;
    //       (**this)(this);
    //     }
    //     acc = 1;
    //     if (dims > 0) { memset32(permArray, minBase, dims); for (i=dims; i!=0; i--) acc *= minBase; }
    //     do {
    //       changed = 0;
    //       if (dims <= 0) break;
    //       for (i = 0; i < dims; i++) {
    //         idx = (this[10] == 2) ? dword_5B06C8[i] : i;
    //         next = permArray[idx] + 1;
    //         prod = next * (acc / permArray[idx]);
    //         if (prod > target) break;
    //         permArray[idx] = next;
    //         acc = prod;
    //         changed = 1;
    //       }
    //     } while (changed);
    //     return acc;
    //   }
    // UNRESOLVED: indirect vtable call is through the object referenced by *a1; callee identity and error-handling side effects unknown (packet lists no callees).
    // UNRESOLVED: dword_5B06C8 remap table semantics (index-to-index permutation mapping) unproven beyond its use in mode 2.
    // UNRESOLVED: Error code literal 55 and factorial write semantics are DERIVED from the raw source only.
}
