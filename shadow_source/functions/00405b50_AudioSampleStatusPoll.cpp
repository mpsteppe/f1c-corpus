// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405B50
// Canonical corpus name: FAILTriageMathUtilButIsAudioStatusPolling
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILTriageMathUtilButIsAudioStatusPolling_00405b50.c

void UnknownObject::AudioSampleStatusPoll()
{
    // Polls Miles audio sample playback status through AIL_sample_status (0x0059E3C8). Loads the sample-handle pointer from this[22] (offset 0x58); if non-null, queries the sample handle stored at the indirection offset 0x68 (this[0x58] + 16). If the status is 4 (DONE) or 16 (STOPPED), returns the loop-mode flag this[5] (offset 0x14) as a non-zero verdict; otherwise returns 2.
    // ASSIGNMENT: Load v2 = this[22], the sample-handle struct pointer at offset 0x58 [field:this:0x00000058, source:raw]
    // GUARD: If v2 is non-null, proceed to query the sample status; otherwise fall through to the blocking return of 2 [field:this:0x00000058, source:raw]
    // CALL: Call AIL_sample_status (0x0059E3C8) with the sample handle read at the indirection this[0x58] + 16 (offset 0x68); store the status into v3 [global:0x0059E3C8, field:this:0x00000068, field:this:0x00000058, source:raw]
    // GUARD: If the status v3 equals 4 (DONE) or 16 (STOPPED), return the loop-mode flag; otherwise return 2 [guard:0, source:raw]
    // RETURN: On DONE/STOPPED return this[5] != 0, the loop-mode flag read at offset 0x14 (non-zero means continuous/loop) [guard:0, field:this:0x00000014, source:raw]
    // RETURN: Otherwise (null handle or status still active/other) return 2 [field:this:0x00000058, source:raw]

    // Conservative worker pseudocode:
    //   int AudioSampleStatusPoll(DWORD* this) {
    //     int v2 = this[22];
    //     if (v2) {
    //       int v3 = AIL_sample_status(*(DWORD*)(v2 + 16));
    //       if (v3 == 4 || v3 == 16)
    //         return this[5] != 0;
    //     }
    //     return 2;
    //   }
    // UNRESOLVED: Meaning of the return value 2 (still playing or unknown status) is not grounded from the packet.
    // UNRESOLVED: The object class owning this audio polling state is unknown.
}
