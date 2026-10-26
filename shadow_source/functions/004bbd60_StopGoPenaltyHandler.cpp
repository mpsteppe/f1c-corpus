// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BBD60
// Canonical corpus name: StopGoPenaltyHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StopGoPenaltyHandler_004bbd60.c

void UnknownObject::StopGoPenaltyHandler()
{
    // HUD penalty-message and ring-buffer event handler. When the penalty-state flag at this+0x30 is clear, it resolves the penalty message text ('Stop Go Penalty' plus driver name) through the message string table, renders it to the HUD text line, records a penalty event (type 4, id 23) with the driver identifier and current session time into the 432-byte-stride ring buffer, and finally dispatches the penalty to the vehicle object. Skipped entirely while the penalty-state flag is set.
    // GUARD: Outer guard: the whole body runs only while the penalty-state flag this+0x30 is zero. [field:this:0x00000030, source:raw]
    // GUARD: Nested guard: run the HUD message path only when a2 (driver name) is non-null and the vehicle object at *this has an empty driver-name field at offset 13000. [field:this:0x00000000, source:raw]
    // GUARD: If BinarySearchInStringTable(byte_5EC4C0, aStopGoPenalty, byte_5EC4CC) finds the penalty string, copy aStopGoPenalty into the message display buffer byte_5EC4CC. [callee:0x00423A00, global:0x005D2574, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // LOOP: do-while byte copy of the aStopGoPenalty string into byte_5EC4CC, terminating on the NUL byte. [global:0x005D2574, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v8, byte_5EC4CC, 63): copy up to 63 bytes of the buffer into local v8, then force v8[63] = 0. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // GUARD: If BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) finds the driver string, strcpy(byte_5EC4CC, a2) replaces the buffer with the driver name. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v9, byte_5EC4CC, 63): copy up to 63 bytes of the buffer into local v9, then force v9[63] = 0. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%s %s", v8, v9): format the combined 'penalty text driver' message into local v10. [callee:0x0058815F, source:raw]
    // CALL: TextLineWrappingAndRendering(&dword_7CD204, v10, 3, 16909060): render the message to the HUD text line via the resource dispatch object dword_7CD204. [callee:0x0045BD10, global:0x007CD204, source:raw]
    // ASSIGNMENT: v6 = dword_8AAE64: read the ring buffer write pointer. [global:0x008AAE64, source:raw]
    // GUARD: When the ring buffer counter dword_83EE60 is below 1023, increment it and advance the write pointer dword_8AAE64 by 432 (one ring-buffer entry stride). [global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALCULATION: *(float*)&v7 = dbl_8AFEA0: load the current session time into the value slot. [global:0x008AFEA0, source:raw]
    // CALL: ProgressBarEventEncode(v6, 4, 23, 1, this[1], v7, 0): encode a penalty event (type 4, id 23, slot 1) carrying the driver identifier this[1] and session time into the ring buffer at the write pointer. [callee:0x004B33B0, field:this:0x00000004, global:0x008AFEA0, source:raw]
    // ASSIGNMENT: *(_BYTE *)(v6 + 8) = a3: store the caller-supplied flag byte at offset 8 of the ring-buffer entry. [global:0x008AAE64, source:raw]
    // CALL: sub_41A720(*this, a2): dispatch the penalty to the vehicle object with the driver name. [callee:0x0041A720, field:this:0x00000000, source:raw]
    // RETURN: Function is void; exits when the outer guard is false or after dispatch. [source:raw]
    // CALL: Invoked by sub_4BC9B0 and sub_4BCCC0. [caller:0x004BC9B0, caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4BBD60(void *this, const char *driverName, char flag) {
    //     if (*(int*)(this+0x30) != 0) return;
    //     if (driverName && !*(_DWORD*)(*(_DWORD*)this + 13000)) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aStopGoPenalty, byte_5EC4CC))
    //         copyString(aStopGoPenalty, byte_5EC4CC);
    //       sub_587DD0(v8, byte_5EC4CC, 63); v8[63] = 0;
    //       if (BinarySearchInStringTable(byte_5EC4C0, driverName, byte_5EC4CC))
    //         strcpy(byte_5EC4CC, driverName);
    //       sub_587DD0(v9, byte_5EC4CC, 63); v9[63] = 0;
    //       StringFormatWithBufferOverflowCheck(v10, "%s %s", v8, v9);
    //       TextLineWrappingAndRendering(&dword_7CD204, v10, 3, 16909060);
    //     }
    //     v6 = dword_8AAE64;
    //     if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //     *(float*)&v7 = dbl_8AFEA0;
    //     ProgressBarEventEncode(v6, 4, 23, 1, *(int*)(this+0x4), v7, 0);
    //     *(BYTE*)(v6 + 8) = flag;
    //     sub_41A720(*(_DWORD*)this, driverName);
    //   }
    // UNRESOLVED: field obj+0x32C8 is packet-marked read but the raw listing guards on this+0x30 instead; the mapping between them is from the fill, not the raw source.
    // UNRESOLVED: globals aSS_2 (0x5C5D30) and dword_5EB978 (0x5EB978) are packet-marked read but do not appear in the raw listing; their role here is unknown.
    // UNRESOLVED: The 13000 offset into the *this object is asserted by the raw listing to be the driver-name field; its type is not confirmed in this packet.
}
