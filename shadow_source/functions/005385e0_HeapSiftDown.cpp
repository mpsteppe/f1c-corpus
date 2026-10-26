// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005385E0
// Canonical corpus name: HeapSiftDown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HeapSiftDown_005385e0.c

void UnknownObject::HeapSiftDown()
{
    // Binary min-heap sift-down (__fastcall; ABI lead HeapSiftDown). a1 is a heap object holding a dword element array at a1 + 4*idx + 2898 and its count at a1 + 5190; a2 points to a parallel key array whose 16-bit key per element sits at a2 + 4*elem; a byte tie-break per element sits at a1 + elem + 5198. Starting from index a3, bubbles the stored element downward while a child has a smaller key (or an equal key with a lower tie-break byte), moving children up one slot, and returns the position last examined once the element settles.
    // ASSIGNMENT: Load heap count v4 = *(int *)(a1 + 5190), the element at the start index v5 = *(int *)(a1 + 4*a3 + 2898), and seed result = 2*a3 (index of the first child). [source:raw]
    // GUARD: If 2*a3 > v4 the element has no children: write v5 back into *(int *)(a1 + 4*a3 + 2898) and return result = 2*a3. [source:raw]
    // LOOP: Sift-down loop over child indices while result <= v4, comparing the two children when both exist (result < v4) and advancing to the preferred child. [source:raw]
    // CALCULATION: Compare children via 16-bit keys at a2 + 4*elem; on equal keys prefer the child whose byte at a1 + elem + 5198 is smaller-or-equal (<=), advancing result by one. [source:raw]
    // ASSIGNMENT: Move the chosen child element v12 up into the parent slot: *(int *)(a1 + 4*parent + 2898) = v12, then descend with result *= 2. [source:raw]
    // STATE_TRANSITION: Settle when the element's key no longer beats the child (v13 < v14, or equal keys with the element's tie-break byte <= the child's): write v5 into *(int *)(a1 + 4*a3 + 2898) and return, where the early-settle path returns a3 and the loop-exit path returns the last examined child index (result). [source:raw]
    // CALL: Invoked by sub_5383D0 (0x005383D0) as part of heap maintenance. [caller:0x005383D0]

    // Conservative worker pseudocode:
    //   int sub_5385E0(int heap, int keys, int index) {
    //     int count = *(int *)(heap + 5190);
    //     int elem  = *(int *)(heap + 4*index + 2898);
    //     int child = 2 * index;
    //     while (child <= count) {
    //       if (child < count) {
    //         int l = *(int *)(heap + 4*child + 2902);
    //         int r = *(int *)(heap + 4*child + 2898);
    //         int lk = *(unsigned short *)(keys + 4*l);
    //         int rk = *(unsigned short *)(keys + 4*r);
    //         if (lk < rk || (lk == rk && *(unsigned char *)(heap + l + 5198) <= *(unsigned char *)(heap + r + 5198)))
    //           ++child;
    //       }
    //       int c = *(int *)(heap + 4*child + 2898);
    //       int ke = *(unsigned short *)(keys + 4*elem);
    //       int kc = *(unsigned short *)(keys + 4*c);
    //       if (ke < kc) break;
    //       if (ke == kc && *(unsigned char *)(heap + elem + 5198) <= *(unsigned char *)(heap + c + 5198)) break;
    //       *(int *)(heap + 4*index + 2898) = c;
    //       index = child;
    //       child *= 2;
    //     }
    //     *(int *)(heap + 4*index + 2898) = elem;
    //     return child;  /* position last examined; the early-settle path returns the parent index instead * /
    //   }
    // UNRESOLVED: Heap object layout at a1 (count at +5190, element array at +2898, tie-break bytes at +5198) is read from the raw source and not independently confirmed.
    // UNRESOLVED: Min-heap ordering (16-bit key, byte tie-break) is inferred from the comparison direction; the key array and element value relationship are not separately documented.
}
