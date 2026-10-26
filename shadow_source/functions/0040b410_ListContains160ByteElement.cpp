// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B410
// Canonical corpus name: ListContains160ByteElement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListContains160ByteElement_0040b410.c

void UnknownObject::ListContains160ByteElement()
{
    // Linear membership test over a fixed-stride list. When a2 is non-zero, walks records starting at the head this[3] (this+0x0C), advancing by 160 bytes per element, bounded by the count this[4] (this+0x10); returns 1 if a record address equals a2 and 0 otherwise, including the empty-list and null-argument cases.
    // ASSIGNMENT: Initialize result to 0 as the not-found default. [source:raw]
    // GUARD: If a2 is zero, skip the search and return 0. [source:raw]
    // ASSIGNMENT: Load the list length v3 from this[4] (this+0x10) and reset the visited counter v4 to 0. [field:this:0x00000010, source:raw]
    // GUARD: If v3 is not greater than 0, the empty-list case returns 0 without iterating. [source:raw]
    // LOOP: Iterate i starting at this[3] (this+0x0C), advancing by 160 bytes per step, until i equals a2. [field:this:0x0000000C, source:raw]
    // GUARD: Inside the loop, if ++v4 >= v3 (the count limit is reached without a match), return 0. [source:raw]
    // RETURN: Return 1 when an element whose address equals a2 is found. [source:raw]

    // Conservative worker pseudocode:
    //   bool ListContains160ByteElement(void *this, void *a2) {
    //     if (!a2) return false;
    //     int count = this[4];
    //     if (count <= 0) return false;
    //     int visited = 0;
    //     for (void *i = this[3]; i != a2; i = (char *)i + 160) {
    //       if (++visited >= count) return false;
    //     }
    //     return true;
    //   }
    // UNRESOLVED: Element record type and what the 160-byte stride contains.
    // UNRESOLVED: Relationship between the head at this+0x0C and the length at this+0x10.
    // UNRESOLVED: Whether records are a contiguous array or another layout (the loop advances by a constant 160-byte stride, implying contiguous records).
}
