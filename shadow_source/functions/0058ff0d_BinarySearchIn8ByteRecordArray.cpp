// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058FF0D
// Canonical corpus name: BinarySearchIn8ByteRecordArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BinarySearchIn8ByteRecordArray_0058ff0d.c

void UnknownObject::BinarySearchIn8ByteRecordArray()
{
    // Binary search over an array of 8-byte records. a1 is the array base, a2 is the high bound (element count derived as the inclusive index upper limit), and a3 is a pointer to the search key that also receives the matching record's value field on success. At each step the midpoint v5 = (v3 + a2) / 2 is computed and the comparator sub_588410 is called with the search key and the record pointer at a1 + 8*v5. A zero comparator result marks a hit and writes a1 + 8*v5 + 4 (the record's value field) into *a3; a positive result narrows the search to the upper half (v3 = v5 + 1), a negative result to the lower half (a2 = v5 - 1). The loop terminates when the bounds cross or a hit was recorded (result zero), and the last comparator result is returned (0 = found).
    // ASSIGNMENT: Initialize lower bound v3 = 0 and result = 1 before the loop. [source:raw]
    // LOOP: while (v3 <= a2): iterate while the search interval is non-empty. [source:raw]
    // GUARD: Break the loop when result is zero (a previous iteration found the record). [source:raw]
    // CALCULATION: Compute the midpoint index v5 = (v3 + a2) / 2. [source:raw]
    // CALL: Call comparator sub_588410(*a3, *(a1 + 8*v5)) comparing the search key against the record at the midpoint; store its return in result. [callee:0x00588410, source:raw]
    // STATE_TRANSITION: On a positive comparator result set v3 = v5 + 1 (search the upper half); on a negative result set a2 = v5 - 1 (search the lower half). [source:raw]
    // ASSIGNMENT: On a zero comparator result (match), write the matched record's value field address a1 + 8*v5 + 4 into *a3. [source:raw]
    // RETURN: Return the last comparator result (zero indicates a found record). [source:raw]
    // CALL: Invoked by sub_58FD90 (0x0058FD90), consistent with a shared string/record lookup helper. [caller:0x0058FD90]

    // Conservative worker pseudocode:
    //   int sub_58FF0D(int arrayBase, int highBound, _BYTE **keyOut) {
    //     int low = 0;
    //     int result = 1;
    //     while (low <= highBound) {
    //       if (!result) break;
    //       int mid = (low + highBound) / 2;
    //       result = sub_588410(**keyOut, *(arrayBase + 8*mid));
    //       if (result == 0)
    //         *keyOut = arrayBase + 8*mid + 4;
    //       else if (result > 0)
    //         low = mid + 1;
    //       else
    //         highBound = mid - 1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Comparator sub_588410 semantics are not visible in this packet; the sign convention (positive key vs record) is inferred from the bound adjustment.
    // UNRESOLVED: The layout of the 8-byte record (key field at record base, value field at base+4) is inferred from the *a3 write target and not independently proven.
    // UNRESOLVED: a2 is treated as an inclusive index bound; whether it is an element count minus one or a raw count is caller-dependent.
    // UNRESOLVED: Meaning of a non-zero return to the caller beyond found/not-found is unknown.
}
