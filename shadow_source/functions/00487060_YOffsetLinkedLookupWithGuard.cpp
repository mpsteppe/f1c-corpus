// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487060
// Canonical corpus name: sub_487060
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_487060_00487060.c

void UnknownObject::YOffsetLinkedLookupWithGuard()
{
    // Loads the base Y-offset v3 from this[3] (offset 0xC) and computes a boundary with ShortComputation_adb0(this + 28). When a2 is below the boundary, reads a short value at index a2 through LinkedListIndexedFieldReader; when a2 is at or above the boundary, the read additionally requires the guard flag this[50] (offset 0xC8) to be non-zero. On a successful read returns v3 + v5; otherwise returns -1.
    // ASSIGNMENT: v3 = this[3] loads the base Y-offset at offset 0xC. [field:this:0x0000000C]
    // CALL: ShortComputation_adb0(this + 28) computes the boundary/count used to select the guarded path. [callee:0x0049ADB0]
    // GUARD: When a2 >= boundary, the read additionally requires this[50] (guard flag at offset 0xC8) to be non-zero. [field:this:0x000000C8]
    // CALL: LinkedListIndexedFieldReader(a2, &v5, v6) reads the short value at index a2; both branches require its boolean success. [callee:0x0049AEC0]
    // CALCULATION: On success return v3 + v5 (base Y-offset plus the looked-up value). [source:raw]
    // RETURN: Return -1 when the guard flag blocks the read or LinkedListIndexedFieldReader fails. [source:raw]

    // Conservative worker pseudocode:
    //   v3 = this[3];
    //   if (a2 >= ShortComputation_adb0(this + 28)) {
    //     if (this[50] && LinkedListIndexedFieldReader(a2, &v5, v6)) return v3 + v5;
    //   } else {
    //     if (LinkedListIndexedFieldReader(a2, &v5, v6)) return v3 + v5;
    //   }
    //   return -1;
    // UNRESOLVED: The meaning of the this[50] guard flag and of the boundary produced by ShortComputation_adb0(this + 28) are not evidenced by this packet.
}
