// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491770
// Canonical corpus name: sub_491770
// Owner: IteratorArrayContainer [DERIVED]
// Raw source: functions/sub_491770_00491770.c

void IteratorArrayContainer::DestroyAllIterators()
{
    // Destroys every list iterator owned by the container reached through the pointer-to-pointer *this. If the element count stored at the container head (obj+0x0) is greater than zero, iterates over the array at obj+0x8 with a 16-byte stride, calling ListIteratorFullDestruction on each element and re-reading the count from *this each pass. Afterwards unconditionally destroys the two embedded iterators at (*this + 3) and (*this + 7), returning the result of the final destruction call. Called only from sub_485B90 (00485b90).
    // ASSIGNMENT: Dereference *this to reach the container and read its element count from the container head (obj+0x0). [field:this:0x00000000, field:obj:0x00000000]
    // GUARD: Guard: only iterate the array when the count stored at obj+0x0 is greater than zero. [field:obj:0x00000000, guard:0]
    // LOOP: For each array element at base v2[2] (offset 0x8) with a 16-byte stride, call ListIteratorFullDestruction(v4 + v2[2]); re-read the count from *this each iteration. [field:obj:0x00000008, callee:0x004910D0]
    // CALL: Destroy the embedded iterator located by pointer arithmetic at (*this + 3) via ListIteratorFullDestruction. [callee:0x004910D0, field:this:0x00000000]
    // RETURN: Destroy the embedded iterator at (*this + 7) via ListIteratorFullDestruction and return its result. [callee:0x004910D0, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   int DestroyAllIterators(int **this) {
    //     int *container = *this;
    //     int index = 0;
    //     if (*container > 0) {
    //       int offset = 0;
    //       do {
    //         ListIteratorFullDestruction(offset + container[2]);
    //         container = *this;
    //         ++index;
    //         offset += 16;
    //       } while (index < **this);
    //     }
    //     ListIteratorFullDestruction((int)(*this + 3));
    //     return ListIteratorFullDestruction((int)(*this + 7));
    //   }
    // UNRESOLVED: The two embedded iterators are reached only through pointer arithmetic (*this + 3 and *this + 7); their exact offsets are not listed as packet fields and their layout is unverified.
    // UNRESOLVED: Container type and ownership lifecycle are unknown; the sole caller is sub_485B90 (00485b90).
}
