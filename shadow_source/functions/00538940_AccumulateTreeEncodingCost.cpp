// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00538940
// Canonical corpus name: PerformanceSectorTimeAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerformanceSectorTimeAccumulator_00538940.c

void UnknownObject::AccumulateTreeEncodingCost()
{
    // Run-length frequency analysis followed by a tree-encoding cost accumulation. Calls RunLengthAnalyzer on the two frequency tables at this+2834 and this+2846, then builds the encoding tree via sub_5383D0(this, this+2854). Scans the code-length alphabet using the lookup byte_5B7DEC from 18 down to 3, breaking at the highest code length whose WORD frequency (this + 4*byte_5B7DEC[result] + 2676) is non-zero, and accumulates the tree-description cost 3*result + 17 into this+5787. Returns the found code length.
    // CALL: RunLengthAnalyzer(*(this + 2834)): run-length frequency analysis of the first tree frequency table. [callee:0x005389B0, field:this:0x00000B12]
    // CALL: RunLengthAnalyzer(*(this + 2846)): run-length frequency analysis of the second tree frequency table. [callee:0x005389B0, field:this:0x00000B1E]
    // CALL: sub_5383D0(this, this + 2854): builds the encoding tree from the analyzed frequency tables; the second argument points into the same object (this + 2854), an offset that is read by the raw source but not declared as a packet field. [callee:0x005383D0]
    // LOOP: Code-length scan: for result = 18 down to 3, read the WORD frequency at this + 4*byte_5B7DEC[result] + 2676 and break at the first non-zero entry, identifying the highest used code length; when no entry is non-zero the loop falls through with result == 2. [global:0x005B7DEC, source:raw]
    // CALCULATION: Tree-description cost: cost = 3*result + 17; accumulate it into the bit-cost counter at this + 5787 (this[5787] += 3*result + 17). [field:this:0x0000169B, source:raw]
    // RETURN: Returns the found code length (result, 2..18). [source:raw]

    // Conservative worker pseudocode:
    //   RunLengthAnalyzer(*(this + 2834));  // first tree table
    //   RunLengthAnalyzer(*(this + 2846));  // second tree table
    //   sub_5383D0(this, this + 2854);      // build encoding tree
    //   result = 18;
    //   for (; result >= 3; --result) {
    //     if (*(WORD*)(this + 4*byte_5B7DEC[result] + 2676)) break;  // highest used code length
    //   }
    //   *(DWORD*)(this + 5787) += 3*result + 17;  // tree-description bit cost
    //   return result;
    // UNRESOLVED: The legacy ABI label 'Performance_Sector_Time_Accumulator' (abi:lead) is inconsistent with the raw source, which performs frequency/tree cost analysis; the existing analysis fill proposes a DEFLATE-style Huffman tree cost estimator, which is consistent with the raw source but not independently evidenced at runtime.
    // UNRESOLVED: When no scanned entry is non-zero the for-loop exits with result == 2, so the minimum accumulated cost is 3*2 + 17; the existing fill states the minimum result is 3, which does not match the raw source.
    // UNRESOLVED: The exact contents and layout of byte_5B7DEC (a code-length-to-index lookup) and of the WORD frequency table at this + 2676 are unknown; the object type owning the this fields (0xB12, 0xB1E, 0x169B) is not identified.
    // UNRESOLVED: this + 2854, passed to sub_5383D0, is not declared as a packet field and therefore has no field evidence ref.
}
