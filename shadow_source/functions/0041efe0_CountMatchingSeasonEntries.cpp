// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041EFE0
// Canonical corpus name: CountMatchingSeasonEntries
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CountMatchingSeasonEntries_0041efe0.c

void UnknownObject::CountMatchingSeasonEntries()
{
    // Counts how many dword entries in the array at a1+24 equal the value a2. Iterates v3 times, where v3 is the count read from the standings node at dword_7D2DB0 via LinkedListDereference and FlagsGetter; the count is re-read from the node at the end of every iteration. Returns 0 when the node is absent or the count is not greater than 0.
    // CALL: Dereference the standings node from dword_7D2DB0 via LinkedListDereference; when absent, skip the loop and return the count 0. [callee:0x004C2850, global:0x007D2DB0]
    // CALL: Dereference the node again and read the loop count v3 via FlagsGetter; proceed only when v3 is greater than 0. [callee:0x004C11D0]
    // LOOP: Iterate over the dwords starting at a1+24, once per count step, re-reading the node via LinkedListDereference and FlagsGetter at the end of each iteration to refresh the loop bound. [callee:0x004C2850, source:raw]
    // CALCULATION: Compare the dword at the current array position against a2 and increment the match counter v4 when they are equal. [source:raw]
    // RETURN: Return the accumulated match count v4. [source:raw]

    // Conservative worker pseudocode:
    //   int CountMatchingSeasonEntries(int a1, int a2) {
    //     int v4 = 0;
    //     if (!LinkedListDereference(&dword_7D2DB0)) return v4;
    //     int v5 = 0;
    //     if (FlagsGetter(LinkedListDereference(&dword_7D2DB0)) > 0) {
    //       int *v7 = (int *)(a1 + 24);
    //       do {
    //         if (*v7 == a2) ++v4;
    //         ++v5;
    //         ++v7;
    //       } while (v5 < FlagsGetter(LinkedListDereference(&dword_7D2DB0)));
    //     }
    //     return v4;
    //   }
    // UNRESOLVED: Whether the dword array at a1+24 and the value a2 are season/standings related beyond the ABI name is not independently confirmed.
    // UNRESOLVED: Why the node is dereferenced twice at entry (a null check and again for the loop count) and why the count is refreshed each iteration is a decompiler artifact not explained by this packet.
    // UNRESOLVED: The owning class of a1 and the role of the 24-byte prefix skipped before the counted array are unknown.
}
