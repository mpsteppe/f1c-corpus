// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC650
// Canonical corpus name: StringCopyWithRingBuffer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithRingBuffer_004fc650.c

void UnknownObject::StringCopyWithRingBuffer()
{
    // Advances a global ring-buffer cursor (dword_8AAE64 by 432, capped by a count in dword_83EE60) and encodes two strings from the this object (at +80 and +132) into a progress-bar event at the cursor: total length arg is strlen(+132) + 1 + strlen(+80) + 1. Called by sub_4FCEE0.
    // ASSIGNMENT: Read the current ring-buffer cursor into v7: v7 = dword_8AAE64. [global:0x008AAE64, source:raw]
    // GUARD: Guard on the ring count: only advance when dword_83EE60 < 1023. [global:0x0083EE60, source:raw]
    // STATE_TRANSITION: Bump the stored count and cursor: ++dword_83EE60; dword_8AAE64 += 432. [global:0x0083EE60, global:0x008AAE64, source:raw]
    // ASSIGNMENT: Bind source strings and length: v2 = this + 80, v3 = strlen(this + 80) + 1, v4 = this + 132. [source:raw]
    // CALL: Encode a progress-bar event: ProgressBarEventEncode(v7, 2, 5, strlen(v4) + 1 + v3, 255, v6, 1), where v6 carries the value of dbl_8AFEA0. [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // CALL: Copy the first string into the ring slot: strcpy(v7 + 8, v2). [source:raw]
    // CALL: Copy the second string after the first: strcpy(v3 + v7 + 8, v4). [source:raw]
    // RETURN: Return the result register, which is left uninitialized by the decompiled body. [source:raw]

    // Conservative worker pseudocode:
    //   int StringCopyWithRingBuffer(const char *obj) {
    //     int cursor = dword_8AAE64;
    //     if (dword_83EE60 < 1023) {
    //       ++dword_83EE60;
    //       dword_8AAE64 += 432;
    //     }
    //     const char *s1 = obj + 80;
    //     unsigned int len1 = strlen(obj + 80) + 1;
    //     const char *s2 = obj + 132;
    //     float f = *(float *)&dbl_8AFEA0;
    //     ProgressBarEventEncode(cursor, 2, 5, strlen(s2) + 1 + len1, 255, f, 1);
    //     strcpy(cursor + 8, s1);
    //     strcpy(len1 + cursor + 8, s2);
    //   }
    //   
    // UNRESOLVED: Return value result is never assigned in the decompiled body; actual return is undefined.
    // UNRESOLVED: dbl_8AFEA0 is a double global but the raw source aliases it as a float load into v6.
    // UNRESOLVED: Semantics of the encode constants 2, 5, 255, 1 and the ring step 432 / cap 1023.
}
