// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004870E0
// Canonical corpus name: sub_4870E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4870E0_004870e0.c

void UnknownObject::XOffsetLinkedLookupWithGuard()
{
    // Guarded indexed lookup: reads base X offset at this+0x4 (this[1]) and looks up an index a2 against a linked list whose boundary/count comes from this+28 via ShortComputation_adb0. If a2 is out of bounds, the read is additionally gated by the guard flag at this+0xC8 (this[50]). On a successful LinkedListIndexedFieldReader the result is the base offset plus the looked-up 16-bit value v5; otherwise returns -1.
    // ASSIGNMENT: Read base X offset into v3 from this+0x4 (this[1]). [source:raw, field:this:0x00000004]
    // CALL: Compute the linked-list boundary/count by calling ShortComputation_adb0(this + 28). [source:raw, callee:0x0049ADB0]
    // GUARD: Branch on a2 >= boundary: the out-of-bounds path requires the guard flag at this+0xC8 (this[50]) to be set before the indexed read is allowed. [source:raw, field:this:0x000000C8]
    // CALL: In the out-of-bounds path, call LinkedListIndexedFieldReader(a2, v6, &v5) to read the indexed field; returns nonzero on success. [source:raw, callee:0x0049AEC0]
    // CALCULATION: On success return v3 + v5 (base X offset plus the looked-up 16-bit value). [source:raw]
    // GUARD: Else branch for a2 < boundary: the indexed read is allowed directly without the this+0xC8 guard flag. [source:raw]
    // CALL: In the in-bounds path, call LinkedListIndexedFieldReader(a2, v6, &v5); returns nonzero on success. [source:raw, callee:0x0049AEC0]
    // RETURN: Return v3 + v5 when either lookup path succeeds. [source:raw]
    // RETURN: Return -1 when both guarded paths fail. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4870E0(int *this, int a2) {
    //     int base = this[1];
    //     if (a2 >= ShortComputation_adb0(this + 28)) {
    //       if (this[50] && LinkedListIndexedFieldReader(a2, outBuf, &v5)) return base + v5;
    //     } else if (LinkedListIndexedFieldReader(a2, outBuf, &v5)) {
    //       return base + v5;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: Identity of the linked-list object and the semantics of the looked-up 16-bit value v5 are unknown.
    // UNRESOLVED: Purpose of the guard flag at this+0xC8 (this[50]) is not established by the packet evidence.
    // UNRESOLVED: Relationship to the companion Y lookup (sub_487060) is asserted only in existing analysis prose, not by the packet itself.
}
