// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495B60
// Canonical corpus name: sub_495B60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_495B60_00495b60.c

void UnknownObject::AnimationSlotCompactAndProcess()
{
    // Processes a fixed array of four 12-byte slots (base a1+5628, stride 12). On every iteration decrements the float timer at a1+192 (offset 0xC0) via FloatFieldDecrement, then tests the current slot pointer with FloatThresholdCheck. A slot that passes the check is retained: if a compaction gap exists (retained counter v2 != iteration counter v3) the slot data is copied out with DataEntryCopy and the slot reset to empty with SmallStructInit_9a00, then the retained counter and compact write position advance by one slot. Called by sub_496E90 (00496e90) and SpriteTextureEnumeration (00498950).
    // LOOP: Runs four iterations over the 12-byte slot array starting at a1+5628; each iteration advances the slot pointer by 12 and the loop exits when the iteration counter reaches 4. [source:raw]
    // CALL: FloatFieldDecrement decrements the float timer at a1+192 (offset 0xC0) once per slot iteration, regardless of slot state. [callee:0x00499A20, field:this:0x000000C0]
    // CALL: FloatThresholdCheck(v1) tests the current 12-byte slot; its byte result selects whether the slot is retained. [callee:0x00499A50, source:raw]
    // GUARD: When the threshold check passes and a compaction gap exists (v2 != v3), the slot data is copied out with DataEntryCopy(v1) and the slot is reset to empty with SmallStructInit_9a00(v1). [callee:0x00499A70, callee:0x00499A00, source:raw]
    // CALCULATION: For each slot that passes the check, the retained counter v2 is incremented and the compact write position v5 is advanced by 12 bytes. [source:raw]
    // RETURN: Returns the last value written to result: either the final FloatThresholdCheck outcome or the compact position plus 12, depending on whether the last iteration passed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_495B60(int a1) {
    //     int slot = a1 + 5628;
    //     int writePos = a1 + 5628;
    //     int retained = 0;
    //     int result;
    //     for (int i = 0; i < 4; i++) {
    //       FloatFieldDecrement(*(float *)(a1 + 192));
    //       result = FloatThresholdCheck(slot);
    //       if (result) {
    //         if (retained != i) {
    //           DataEntryCopy(slot);
    //           SmallStructInit_9a00(slot);
    //         }
    //         retained++;
    //         result = writePos + 12;
    //         writePos += 12;
    //       }
    //       slot += 12;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Whether a slot that passes FloatThresholdCheck is retained/active or expired/consumed is not deterministically evidenced; the fill's interpretation of the check selecting expired slots is DERIVED prose.
    // UNRESOLVED: The +12 stride, the 4-slot bound and the 5628 (0x15FC) base come from raw-source literals; the caller-side meaning of the slot array is not evidenced in this packet.
    // UNRESOLVED: DataEntryCopy and SmallStructInit_9a00 are called with a single slot argument, so the copy destination is implicit or stateful and is not visible in this body.
}
