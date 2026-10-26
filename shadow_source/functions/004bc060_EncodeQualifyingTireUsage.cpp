// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BC060
// Canonical corpus name: sub_4BC060
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BC060_004bc060.c

void UnknownObject::EncodeQualifyingTireUsage()
{
    // During a qualifying session (dword_7C56A4 == 7) encodes a tire-usage ring-buffer event (message type 4, event id 26 or 27) via ProgressBarEventEncode. The ring-buffer count/write-pointer pair is advanced when below a hard bound, the low 32 bits of the session-time double form the event payload, and a tire-compound byte from the vehicle struct is written into the encoded record. Returns the encoder result only on the event-id-27 path; the non-qualifying path leaves the result undefined.
    // GUARD: if dword_7C56A4 != 7 (session type is not qualifying) the whole body is skipped [global:0x007C56A4, source:raw]
    // GUARD: if ring-buffer count dword_83EE60 < 1023 the counter and write pointer are advanced [global:0x0083EE60, source:raw]
    // ASSIGNMENT: increment ring-buffer count dword_83EE60 [global:0x0083EE60, source:raw]
    // ASSIGNMENT: advance ring-buffer write pointer dword_8AAE64 by 432 bytes [global:0x008AAE64, source:raw]
    // CALCULATION: take the low 32 bits of session-time double dbl_8AFEA0 as the float event payload v5 [global:0x008AFEA0, source:raw]
    // GUARD: branch on a2: non-zero selects event id 26 (tire set in use), zero selects event id 27 (tire set discarded) [source:raw]
    // CALL: a2 non-zero: ProgressBarEventEncode(writePtr, 4, 26, 1, *(this+0x4), v5, 0) then store the tire-compound byte *(this+0x34) into the encoded record at writePtr+0x8 [callee:0x004B33B0, field:this:0x00000004, field:this:0x00000034, source:raw]
    // CALL: a2 zero: return ProgressBarEventEncode(writePtr, 4, 27, 0, *(this+0x4), v5, 0) [callee:0x004B33B0, field:this:0x00000004, source:raw]
    // RETURN: the event-id-27 path returns the ProgressBarEventEncode result; the non-qualifying path has no explicit return, so its result is undefined [function:0x004BC060, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C56A4 != 7) return; /* undefined result * /
    //   if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //   float t = low32(dbl_8AFEA0);
    //   if (a2) {
    //     ProgressBarEventEncode(dword_8AAE64, 4, 26, 1, *(int*)(this+0x4), t, 0);
    //     *(byte*)(dword_8AAE64+0x8) = *(byte*)(this+0x34);
    //   } else {
    //     return ProgressBarEventEncode(dword_8AAE64, 4, 27, 0, *(int*)(this+0x4), t, 0);
    //   }
    // UNRESOLVED: Semantic labels for event ids 26 (in use) vs 27 (discarded) come from existing_analysis prose, not from the raw source, and are not independently confirmed.
    // UNRESOLVED: ABI lead name Vehicle_Audio_Event_Dispatch conflicts with the tire-usage interpretation of this body; the legacy lead is unconfirmed.
    // UNRESOLVED: The non-qualifying return path reads an uninitialized register, so the returned value there is undefined.
}
