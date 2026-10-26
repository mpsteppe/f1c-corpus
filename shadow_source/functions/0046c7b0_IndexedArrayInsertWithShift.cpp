// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046C7B0
// Canonical corpus name: IndexedArrayInsertWithShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IndexedArrayInsertWithShift_0046c7b0.c

void UnknownObject::IndexedArrayInsertWithShift()
{
    // Insert-or-append helper (stdcall) over one of two 104-entry global arrays. Selects the array by a1 (zero selects dword_7CD470, non-zero selects dword_7CD2B8), scans for the first -1 sentinel to derive the used count, then either appends a2 at the first free slot when a3 is negative, or clamps a3 to the used count and shifts the tail right one slot to insert a2. Returns 1 on success and 0 when the array is full. Called by UIMouseClickHandler.
    // ASSIGNMENT: Select the array base: v3 = &dword_7CD2B8, overridden to &dword_7CD470 when a1 is zero. [global:0x007CD2B8, global:0x007CD470, source:raw]
    // LOOP: Scan the first 104 entries of the selected array, counting v4 until the first entry equal to -1 (the sentinel) is found. [global:0x007CD2B8, global:0x007CD470, source:raw]
    // GUARD: When a3 is negative, append: write a2 at the first free slot v3[v4] and return 1. [source:raw]
    // ASSIGNMENT: Append path: v3[v4] = a2. [source:raw]
    // CALCULATION: When a3 is non-negative it is clamped: v6 = a3, or v6 = v4 when a3 exceeds the used count. [source:raw]
    // ASSIGNMENT: Save the displaced entry v8 = v3[v6], then write the new value v3[v6] = a2. [source:raw]
    // LOOP: Shift walk from v9 = v6 + 1 while v9 < 104: carry the previous displaced value into each slot (v3[v9] = v8), stopping at the -1 sentinel; the walk is bounded by the array size. [source:raw]
    // GUARD: The shift walk only starts when v6 + 1 is below 104; the walk terminates with return 1 on sentinel hit or return 0 when v9 reaches the array bound. [source:raw]
    // RETURN: Return 1 for append/insert success and 0 when the array has no room (walk overflow); invoked by UIMouseClickHandler. [caller:0x0046C8B0, function:0x0046C7B0, source:raw]

    // Conservative worker pseudocode:
    //   char sub_46C7B0(char selector, int value, int index) {
    //     int *arr = selector ? &dword_7CD2B8 : &dword_7CD470;
    //     int used = 0;
    //     for (int i = 0; i < 104; ++i) { if (arr[i] == -1) break; ++used; }
    //     if (index < 0) { arr[used] = value; return 1; }
    //     if (index > used) index = used;
    //     int displaced = arr[index];
    //     arr[index] = value;
    //     int pos = index + 1;
    //     if (pos < 104) {
    //       while (1) {
    //         int next = arr[pos];
    //         arr[pos] = displaced;
    //         if (next == -1) return 1;
    //         ++pos; displaced = next;
    //         if (pos >= 104) return 0;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The element semantics of the two selected arrays (capacity 104) and the meaning of the values they hold are not documented by this packet; both globals are read as array bases only.
    // UNRESOLVED: Why a1 zero selects dword_7CD470 while non-zero selects dword_7CD2B8 (which list the selection inverts) is unknown here.
}
