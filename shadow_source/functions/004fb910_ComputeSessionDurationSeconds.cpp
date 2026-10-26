// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FB910
// Canonical corpus name: sub_4FB910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FB910_004fb910.c

void UnknownObject::ComputeSessionDurationSeconds()
{
    // Selects a day count v3 and hour offset v4 from the session index passed as the integer this via jump table jpt_4FB921, then, when session type dword_7C56A4 is 1 or 2 and the current track path matches Monaco, subtracts one day. Returns days * 86400 + hours * 3600 seconds.
    // CALCULATION: Dispatch on the integer this (session index) through jump table jpt_4FB921 to select the day count and hour offset. [global:0x004FB9F0, source:raw]
    // ASSIGNMENT: Case table maps session index to (days v3, hours v4): 0 to (1, 12), 1 to (2, 11), 2 to (2, 13), 3 to (3, 9), 4 to (3, 10.25), 5 to (3, 13), 6 to (4, 9.5), 7 to (4, 14); default leaves both values unchanged. [source:raw]
    // GUARD: Monaco adjustment applies only when session type dword_7C56A4 equals 1 or 2. [global:0x007C56A4, source:raw]
    // GUARD: v1 = current track path dword_7CE5D0; when dword_7CE5D0 is null, fall back to default path byte_5EA438. [global:0x007CE5D0, global:0x005EA438, source:raw]
    // CALL: sub_566810 compares the track path v1 against the Monaco token aMonaco. [callee:0x00566810, global:0x005D6F00, source:raw]
    // CALCULATION: When the track path matches Monaco, decrement the day count v3 by one. [callee:0x00566810, global:0x005D6F00, source:raw]
    // RETURN: Return the session duration in seconds as (double)v3 * 86400.0 + v4 * 3600.0. [source:raw]

    // Conservative worker pseudocode:
    //   switch (session_index) {
    //       0: days=1, hours=12; 1: days=2, hours=11; 2: days=2, hours=13;
    //       3: days=3, hours=9;  4: days=3, hours=10.25; 5: days=3, hours=13;
    //       6: days=4, hours=9.5; 7: days=4, hours=14; default: unchanged;
    //   }
    //   if (session_type == 1 || session_type == 2) {
    //       path = track_path ? track_path : default_path;
    //       if (sub_566810(path, aMonaco)) days--;
    //   }
    //   return days * 86400.0 + hours * 3600.0;
    // UNRESOLVED: Read globals dbl_59FB48 and flt_5AD28C appear in the deterministic facts but not in the raw source text; they likely back the 86400.0 and 3600.0 conversion constants, but the mapping is not proven.
    // UNRESOLVED: Interpretation as session duration in seconds is inferred from the 86400 and 3600 day/hour factors; the caller WeatherConditionsFileWriter usage is not visible in this packet.
    // UNRESOLVED: The integer this is used as the switch key, which indicates the decompiler's this pointer is actually a session/event index; the calling convention detail is unverified.
}
