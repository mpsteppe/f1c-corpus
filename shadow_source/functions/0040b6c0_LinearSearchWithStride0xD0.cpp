// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B6C0
// Canonical corpus name: ShortComputation_b6c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_b6c0_0040b6c0.c

void UnknownObject::LinearSearchWithStride0xD0()
{
    // Linear address search over an array of fixed-size records. Reads the array start pointer from this+0x0C and the element count from this+0x10, then walks records forward by stride 208 (0xD0) until the record address equals a2 or the count is exhausted. Returns the zero-based record index when found, -1 when not found or when the count is not positive.
    // ASSIGNMENT: Read element count v2 from this+0x10. [field:this:0x00000010]
    // ASSIGNMENT: Initialize result to -1 (not-found sentinel) and index counter v4 to 0. [source:raw]
    // GUARD: Guard on element count v2 > 0; when the count is not positive, skip the search and return the -1 sentinel. [source:raw]
    // ASSIGNMENT: Read search pointer i from this+0x0C (start of the record array). [field:this:0x0000000C]
    // LOOP: Iterate while the record pointer i does not equal the target a2, advancing i by stride 208 (0xD0) each step. [source:raw]
    // GUARD: Increment counter v4; if it reaches the element count before a match, return the -1 sentinel. [source:raw]
    // RETURN: Return the record index v4 when the pointer i matches the target a2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40B6C0(struct T *this, int target) {
    //     int count = this->count;   // this+0x10
    //     int result = -1;
    //     int idx = 0;
    //     if (count > 0) {
    //       char *p = this->records; // this+0x0C
    //       for (; p != (char*)target; p += 0xD0) {
    //         if (++idx >= count) return result;
    //       }
    //       return idx;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Record element layout and stride 0xD0 semantics depend on the caller (0x0040BCD0).
    // UNRESOLVED: Whether a2 is a record pointer or a field address embedded in records is unresolved; only the address equality test is known.
}
