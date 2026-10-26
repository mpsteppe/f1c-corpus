// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC0E0
// Canonical corpus name: DisqualificationHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DisqualificationHandler_004bc0e0.c

void UnknownObject::DisqualificationHandler()
{
    // Disqualification handler: when the disqualification state at this+0x30 is not already 3, shows a "Disqualified: <driver>" message on the HUD and logs a disqualification event (type 4, ID 28) into the ring buffer. The message path only runs when a driver-name string a2 is supplied and the penalty-state flag at obj+0x32C8 (obj = *this) is clear. this+0x30 is only read, never written, so this routine cannot re-arm itself.
    // GUARD: Top-level anti-double-DQ guard on this[12] (this+0x30) != 3; when the disqualification state already equals 3 the whole body is skipped. The state is read only, never written here. [guard:0, field:this:0x00000030, source:raw]
    // GUARD: Message-path guard on (a2 != NULL) AND (*(_DWORD *)(*this + 13000) == 0), i.e. a driver-name string is supplied and the penalty-state flag at obj+0x32C8 (obj = *this) is clear. [field:this:0x00000000, field:obj:0x000032C8, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aDisqualified, byte_5EC4CC) looks up the 'Disqualified' label in the message string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005D2588, global:0x005EC4CC, source:raw]
    // LOOP: do-while copy loop copies aDisqualified into byte_5EC4CC one byte at a time, including the NUL terminator. [global:0x005D2588, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v7, byte_5EC4CC, 63) formats the label buffer into local buffer v7 with max length 63; v7[63] is then NUL-terminated. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) looks up the driver name a2 in the message string table; on success the driver name is strcpy'd into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v8, byte_5EC4CC, 63) formats the driver-name buffer into local buffer v8 with max length 63; v8[63] is then NUL-terminated. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v9, "%s %s", v7, v8) combines the 'Disqualified' label and the driver name into the 192-byte render buffer v9. [callee:0x0058815F, source:raw]
    // CALL: TextLineWrappingAndRendering(&dword_7CD204, (int)v9, 3, 16909060) renders the combined message to the HUD text resource. [callee:0x0045BD10, global:0x007CD204, source:raw]
    // CALCULATION: Ring-buffer slot selection: when dword_83EE60 >= 1023 the write pointer stays at dword_8AAE64 without advancing; otherwise the counter is incremented and the write pointer advances by 432 bytes per slot. [global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALCULATION: v6 is initialized from dbl_8AFEA0 (session-time value) and passed as the event timestamp. [global:0x008AFEA0, source:raw]
    // CALL: ProgressBarEventEncode(v5, 4, 28, 0, this[1], v6, 0) encodes a disqualification event (type 4, ID 28) into the selected ring-buffer slot, tagged with the driver/vehicle identifier this[1] and the timestamp v6. [callee:0x004B33B0, field:this:0x00000004, global:0x008AFEA0, source:raw]
    // CALL: sub_41A940(*this, a2) dispatches the disqualification to the object pointed to by this[0] with the driver-name string a2. [callee:0x0041A940, field:this:0x00000000, source:raw]
    // CALL: Called on the frame path by sub_4A5EA0, sub_4A5F20, LapCompletion, sub_4BC9B0 and sub_4BCCC0. [caller:0x004A5EA0, caller:0x004A5F20, caller:0x004BC4E0, caller:0x004BC9B0, caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4BC0E0(int *this, const char *driverName) {
    //     if (this[12] != 3) {
    //       if (driverName && *(int *)((char *)*this + 13000) == 0) {
    //         if (BinarySearchInStringTable(byte_5EC4C0, aDisqualified, byte_5EC4CC))
    //           copy aDisqualified into byte_5EC4CC including the NUL terminator;
    //         sub_587DD0(v7, byte_5EC4CC, 63);
    //         v7[63] = 0;
    //         if (BinarySearchInStringTable(byte_5EC4C0, driverName, byte_5EC4CC))
    //           strcpy(byte_5EC4CC, driverName);
    //         sub_587DD0(v8, byte_5EC4CC, 63);
    //         v8[63] = 0;
    //         StringFormatWithBufferOverflowCheck(v9, "%s %s", v7, v8);
    //         TextLineWrappingAndRendering(&dword_7CD204, (int)v9, 3, 16909060);
    //       }
    //       if (dword_83EE60 < 1023) {
    //         ++dword_83EE60;
    //         v5 = (_DWORD *)dword_8AAE64;
    //         dword_8AAE64 += 432;
    //       } else {
    //         v5 = (_DWORD *)dword_8AAE64;
    //       }
    //       v6 = dbl_8AFEA0;
    //       ProgressBarEventEncode(v5, 4, 28, 0, this[1], v6, 0);
    //       sub_41A940(*this, driverName);
    //     }
    //   }
    // UNRESOLVED: Globals aSS_2 (0x005C5D30) and dword_5EB978 (0x005EB978) are listed in the packet global set but do not appear in the raw function body; their role in this function is unknown.
    // UNRESOLVED: Semantics of the driver-name parameter a2 and of the message string-table lookups (byte_5EC4C0) are defined by the string table and callers.
    // UNRESOLVED: Disqualification state this[12] (this+0x30) value 3 is treated as 'already disqualified', but the value is only read here; the writer that sets it to 3 is elsewhere.
    // UNRESOLVED: The penalty-state flag at obj+0x32C8 (offset 13000) is only checked for being clear; its writer is elsewhere.
}
