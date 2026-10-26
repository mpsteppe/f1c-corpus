// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DED20
// Canonical corpus name: DualArrayDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualArrayDestructor_004ded20.c

void UnknownObject::DualArrayDestructor()
{
    // Destructor for an object holding two heap arrays whose element counts live in the allocation header (count DWORD immediately before the block base, i.e. block-4). Each array is a packed stride of fixed-width elements: the first array uses a 3-DWORD (12-byte) element stride and per-element teardown via sub_4DD4C0; the second uses a 6-DWORD (24-byte) stride and per-element processing via ShortComputation_d4d0. Both arrays are cleared from the last element down to the first, the backing block is released through FreeWrapper_7bcf at its header base, and the object's array-pointer fields are zeroed. The two head fields at offsets 0x4 and 0x8 are zeroed first. Always returns 0.
    // ASSIGNMENT: Zero the head fields at offsets 0x4 and 0x8 before the first array teardown. [field:this:0x00000004, field:this:0x00000008]
    // GUARD: Guard: first array pointer at offset 0xC (this[3]); if non-null, tear down the first array block. [field:this:0x0000000C]
    // CALCULATION: Element count read from the allocation header four bytes before the block (block-4); start pointer computed one past the last element using a 3-DWORD (12-byte) element stride. [field:this:0x0000000C]
    // LOOP: Iterate the first array from the last element down to the first (stride 3 DWORDs, 12 bytes) calling the per-element teardown sub_4DD4C0 on each element. [callee:0x004DD4C0, field:this:0x0000000C]
    // CALL: Release the first array backing allocation through FreeWrapper_7bcf at its header base (block-4). [callee:0x00587BCF]
    // ASSIGNMENT: Zero the first array pointer at offset 0xC and its companion field at offset 0x10. [field:this:0x0000000C, field:this:0x00000010]
    // GUARD: Guard: second array pointer at offset 0x14 (this[5]); if non-null, tear down the second array block. [field:this:0x00000014]
    // CALCULATION: Second array element count read from header (block-4); start pointer computed one past the last element using a 6-DWORD (24-byte) element stride. [field:this:0x00000014]
    // LOOP: Iterate the second array from the last element down to the first (stride 6 DWORDs, 24 bytes) calling ShortComputation_d4d0 on each element. [callee:0x004DD4D0, field:this:0x00000014]
    // CALL: Release the second array backing allocation through FreeWrapper_7bcf at its header base (block-4). [callee:0x00587BCF]
    // ASSIGNMENT: Zero the second array pointer at offset 0x14 and its companion field at offset 0x18. [field:this:0x00000014, field:this:0x00000018]
    // STATE_TRANSITION: Object teardown reached from caller lifecycle paths: F_2FieldInitCall, DualArrayDestructorLoopFree, VehicleResetClear, TimerClampAndProcess. [caller:0x004DE5F0, caller:0x004DFCA0, caller:0x004E09E0, caller:0x004E38D0]
    // RETURN: Return 0 on both teardown paths and the fall-through path. [function:0x004DED20, source:raw]

    // Conservative worker pseudocode:
    //   int DualArrayDestructor(void *this) {
    //     this[0x4] = 0;
    //     this[0x8] = 0;
    //     if (this[0xC]) {
    //       int n = *(this[0xC] - 4);
    //       for (int i = n - 1; i >= 0; --i) sub_4DD4C0((char*)this[0xC] + i * 12);
    //       FreeWrapper_7bcf((char*)this[0xC] - 4);
    //     }
    //     this[0xC] = 0;
    //     this[0x10] = 0;
    //     if (this[0x14]) {
    //       int n = *(this[0x14] - 4);
    //       for (int i = n - 1; i >= 0; --i) ShortComputation_d4d0((char*)this[0x14] + i * 24);
    //       FreeWrapper_7bcf((char*)this[0x14] - 4);
    //     }
    //     this[0x14] = 0;
    //     this[0x18] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Owner class is unidentified (UnknownObject); the dual-array layout and the callers suggest a vehicle/timer-managed object but there is no naming evidence in this packet.
    // UNRESOLVED: Companion fields at offsets 0x10 and 0x18 are zeroed but never read; whether they hold a second pointer (capacity/end) or separate state is not evidenced.
    // UNRESOLVED: Head fields at offsets 0x4 and 0x8 are zeroed but never read or written elsewhere in this function; their meaning is undetermined.
    // UNRESOLVED: Element count is read from the allocation header at block-4; this MSVC-style header convention is inferred from the code, not independently evidenced.
    // UNRESOLVED: sub_4DD4C0 and ShortComputation_d4d0 are treated as per-element teardown/processing helpers; their exact behavior is outside this packet.
}
