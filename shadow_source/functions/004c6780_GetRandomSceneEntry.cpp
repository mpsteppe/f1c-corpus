// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6780
// Canonical corpus name: LinkedListRandomAccess
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListRandomAccess_004c6780.c

void UnknownObject::GetRandomSceneEntry()
{
    // Generates a random index from the 64-bit random state read at this+0x14, bounds-checks it against the linked-list count at this+20, walks the list to the selected node via next pointers at node+4, and returns the corresponding scene entry pointer from the global scene array dword_8AC490 using the node's scene index if it lies in [0, dword_8AC488). Returns 0 on any guard failure.
    // ASSIGNMENT: Initialize the default result v2 to 0. [source:raw]
    // GUARD: Guard on a2: if a2 < 0, return the default 0. [source:raw]
    // CALL: Call ReadFieldAtOffset0x14(this) to read the 64-bit random state stored at this+0x14. [callee:0x005871F0, source:raw]
    // GUARD: Guard on the random range: if the high dword of the random value is >= the low dword, return 0 (invalid range). [source:raw]
    // CALL: Call BoundsCheckedIndexSetter_6760 with the high dword of the random state; its derived candidate index v5 is kept in v7. [callee:0x004C6760, source:raw]
    // GUARD: Guard on the list count: if the candidate index v5 >= the count at this+20, return 0. [source:raw]
    // ASSIGNMENT: Load the head pointer of the linked list from this+8 into v8. [source:raw]
    // LOOP: Walk the linked list from the head, following the next pointer at node+4 while decrementing the remaining index v7. [source:raw]
    // GUARD: Guard on the selected node: if the node or its first dword (scene index) is null, return 0. [source:raw]
    // ASSIGNMENT: Read the scene index v11 from the first dword of the selected node. [source:raw]
    // GUARD: Guard on the scene index range: return 0 unless v11 is within [0, dword_8AC488). [global:0x008AC488, source:raw]
    // CALCULATION: Compute the scene entry address as dword_8AC490 + 396 * v11 and return it. [global:0x008AC490, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C6780(void* this, int a2) {
    //     if (a2 < 0) return 0;
    //     __int64 rnd = ReadFieldAtOffset0x14(this);
    //     if ((int)(rnd >> 32) >= (int)rnd) return 0;
    //     int idx = BoundsCheckedIndexSetter_6760((void*)0, (int)(rnd >> 32));
    //     if (idx >= *(int*)(this + 20)) return 0;
    //     int* node = *(int**)(this + 8);
    //     int remain = idx;
    //     while (node && --remain > 0) node = (int*)node[1];
    //     if (!node || !*node) return 0;
    //     int sceneIndex = *node;
    //     if (sceneIndex < 0 || sceneIndex >= dword_8AC488) return 0;
    //     return dword_8AC490 + 396 * sceneIndex;
    //   }
    // UNRESOLVED: Object type of this is unknown; offsets 0x14 (random state), 20 (list count) and 8 (list head) are decompiler-grounded but the container semantics are unnamed.
    // UNRESOLVED: What BoundsCheckedIndexSetter_6760 computes exactly (e.g. modulo reduction of the random value) is unverified.
    // UNRESOLVED: Whether the linked list nodes are filtered/selected before this call is not established by this function alone.
    // UNRESOLVED: The stride 396 of the scene array and the global names dword_8AC488/dword_8AC490 are DERIVED labels, not proven field names.
}
