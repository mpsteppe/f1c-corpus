// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D3740
// Canonical corpus name: TimerFrameRateThrottle
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerFrameRateThrottle_004d3740.c

void UnknownObject::TimerFrameRateThrottle()
{
    // Periodic timing dispatch using a flag property as the vehicle selector. Reads property 2048 via FlagPropertyGetter into v3, dispatches LapSplitTimeEvent on the unk_5F070C array slot v3 with this as argument, reads property 2048 again into v4, dispatches AICommandMessageQueueDispatcher on the unk_5EC6D8 array slot v4 with arguments v4+1 and 0, then clears the buffer entry at this+0x14 and returns 0.
    // CALL: Read property with flag index 2048 into v3 via FlagPropertyGetter(&v3, 2048). [callee:0x0054C150, source:raw]
    // CALL: Dispatch LapSplitTimeEvent on the slot selected by v3: address is the unk_5F070C base advanced by 4656 * v3 dword elements, passing this as the event argument. [callee:0x004BC390, global:0x005F070C, source:raw]
    // CALL: Read property with flag index 2048 a second time into v4 via FlagPropertyGetter(&v4, 2048). [callee:0x0054C150, source:raw]
    // CALL: Dispatch AICommandMessageQueueDispatcher on the slot selected by v4: address is the unk_5EC6D8 base advanced by 4656 * v4 dword elements, with arguments v4 + 1 and 0. [callee:0x00424CD0, global:0x005EC6D8, source:raw]
    // CALL: Clear the buffer entry stored at this+0x14 via BufferEntryClear(this[5]). [callee:0x0054FAE0, field:this:0x00000014, source:raw]
    // RETURN: Return 0 after all dispatch and cleanup calls. [function:0x004D3740, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D3740(DWORD *this) {
    //     int v3, v4;
    //     FlagPropertyGetter(&v3, 2048);
    //     LapSplitTimeEvent((float *)&unk_5F070C + 4656 * v3, (int)this);
    //     FlagPropertyGetter(&v4, 2048);
    //     AICommandMessageQueueDispatcher((int *)&unk_5EC6D8 + 4656 * v4, v4 + 1, 0);
    //     BufferEntryClear(this[5]);
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the flag property 2048 (which driver/vehicle selector it resolves) is not documented in this packet.
    // UNRESOLVED: The semantics of the v4 + 1 argument passed to AICommandMessageQueueDispatcher depend on the callee and cannot be confirmed here.
    // UNRESOLVED: The 4656 stride selects per-vehicle slots of the unk_5F070C and unk_5EC6D8 arrays, but the exact struct layout of those slots is not evidenced in this packet.
}
