// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406A90
// Canonical corpus name: ShortComputation_6a90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6a90_00406a90.c

void UnknownObject::GetIndexPair()
{
    // Reads two integer values from the object (this[6] at +0x18 and this[7] at +0x1C) and returns them through optional caller-supplied output pointers a2 and a3. Each output pointer is NULL-checked before the store; the function always returns the a3 pointer (result). Called by LinkedListNodeSearchByIDOperation (0x00408050), consistent with retrieving a per-entry ID/index pair.
    // GUARD: Guard on a2 being non-NULL; when non-NULL, write this[6] (the value at +0x18) to *a2. [field:this:0x00000018]
    // ASSIGNMENT: Initialize the result pointer to a3. [source:raw]
    // GUARD: Guard on a3 being non-NULL; when non-NULL, write this[7] (the value at +0x1C) to *a3. [field:this:0x0000001C]
    // RETURN: Return the result pointer (a3) as the function value. [function:0x00406A90, source:raw]

    // Conservative worker pseudocode:
    //   int *sub_406A90(int *this, int *a2, int *a3) {
    //     if (a2) *a2 = this[6];
    //     if (a3) *a3 = this[7];
    //     return a3;
    //   }
    // UNRESOLVED: Semantics of the two values at +0x18 and +0x1C (proposed as an index pair by the caller context, not proven).
    // UNRESOLVED: How the caller (LinkedListNodeSearchByIDOperation, 0x00408050) interprets the returned pointers is outside this packet.
}
