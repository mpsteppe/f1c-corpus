// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00406790
// Canonical corpus name: sub_406790
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_406790_00406790.c

void UnknownObject::OpenAndStartAudioStream()
{
    // Opens a Miles audio stream for an audio-stream slot and starts playback. Two modes keyed on the mode byte at this+32 (0x20): first-time data-driven open (builds an MP3 filename from a resolved data object, or opens the stored path directly) and a track-update path (validates the path with sub_4069F0 and rebuilds the filename from the slot/track indices). On success registers a settings-save callback, starts the stream, sets left/right volume from this+4, and enters the mutex. On open failure resets the three 20-byte slot entries and enters the mutex.
    // ASSIGNMENT: Load the audio driver handle used for opening: dereference the driver object at this+8 and read field +144 into the stream open argument. [field:this:0x00000008, field:*(this+0x8):0x00000090]
    // ASSIGNMENT: Load the requested audio path pointer from this+16, defaulting to the blank path byte_5EA438 when null. [field:this:0x00000010, global:0x005EA438]
    // GUARD: Branch on the mode byte at this+32 (field 0x20): zero selects the first-time data-driven open, non-zero selects the path-based track update. [field:this:0x00000020]
    // GUARD: On first-time open, when the stored path equals the default blank byte_5EA438, resolve a data object for track index this+28 via sub_4080B0. [callee:0x004080B0, field:this:0x0000001C, global:0x005EA438]
    // CALL: Deserialize the resolved data object with BinaryDataDeserialization using the sub-struct parameter at this+24; a null object or deserialization failure skips the open. [callee:0x004054E0, field:this:0x00000018, source:raw]
    // CALCULATION: Build the stream filename with StringFormatWithBufferOverflowCheck: base prefix asc_5BE820 plus the object audio id v6[4], and when the type word v6[11] equals 2 append the track v6[9] and the .mp3 suffix; otherwise use the single-index format string. [callee:0x0058815F, global:0x005BE820, global:0x005BE84C, global:0x005BE854]
    // CALL: Data-driven open: AIL_open_stream on the driver handle with the built filename buffer; store the returned stream handle at this+12. [global:0x0059E388, field:this:0x0000000C]
    // CALL: Direct-path open when the stored path differs from the default: AIL_open_stream on the driver handle with the path from this+16; store the handle at this+12. [global:0x0059E388, field:this:0x00000010, global:0x005EA438]
    // GUARD: Track-update path requires the path to differ from the default byte_5EA438 and the track index this+28 to be greater than zero. [guard:0, field:this:0x0000001C, global:0x005EA438]
    // CALL: Update open: when sub_4069F0(path, this+24) validates, rebuild the '%s%d,%d.mp3' filename from asc_5BE820, slot index this+92 and track this+28, call AIL_open_stream, and store the handle at this+12. [callee:0x004069F0, field:this:0x00000018, field:this:0x0000005C, field:this:0x0000001C, callee:0x0058815F, global:0x005BE820, global:0x005BE854, global:0x0059E388, field:this:0x0000000C]
    // GUARD: After the open attempt, branch on the stream handle at this+12: non-null takes the start/volume path, null takes the slot-reset path. [field:this:0x0000000C, source:raw]
    // CALL: Success path: register SettingsSaveWrapper with AIL_register_stream_callback, start the stream with AIL_start_stream, and set left/right volume with AIL_set_stream_volume_levels using the float at this+4 for both channels. [global:0x00405030, global:0x0059E384, global:0x0059E380, global:0x0059E378, field:this:0x00000004]
    // CALL: Success path: enter the object mutex with MutexLockWithTimeout(this, 2) and return its result. [callee:0x00406700]
    // CALL: Failure path: enter the mutex with MutexLockWithTimeout(this, 0), then reset three slot groups stepping 20 bytes: write -1 to offsets 0x18 and 0x1C, clear the byte at 0x20, and refresh each path with StringCopyWithBufferRealloc of the blank byte_5EA438. [callee:0x00406700, callee:0x00566650, global:0x005EA438, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020]

    // Conservative worker pseudocode:
    //   char OpenAndStartAudioStream(void *this) {
    //     unsigned char *driver = *(unsigned char **)(this + 8);
    //     const char *path = *(const char **)(this + 16);
    //     if (path == 0) path = (const char *)&byte_5EA438;
    //     if (*(unsigned char *)(this + 32) == 0) {
    //       if (strcmp(path, (const char *)&byte_5EA438) == 0) {
    //         unsigned int *data = (unsigned int *)sub_4080B0(*(int *)(this + 28));
    //         if (data && !BinaryDataDeserialization(data, *(int *)(this + 24))) {
    //           char name[32];
    //           if (data[11] == 2)
    //             StringFormatWithBufferOverflowCheck(name, "%s%d,%d.mp3", asc_5BE820, data[4], data[9]);
    //           else
    //             StringFormatWithBufferOverflowCheck(name, "%s%d", asc_5BE820, data[4]);
    //           *(int *)(this + 12) = AIL_open_stream(*(int *)(driver + 144), name, 0);
    //         }
    //       } else {
    //         *(int *)(this + 12) = AIL_open_stream(*(int *)(driver + 144), path, 0);
    //       }
    //     } else if (strcmp(path, (const char *)&byte_5EA438) != 0 && *(int *)(this + 28) > 0) {
    //       if (sub_4069F0(*(char **)(this + 16), *(int *)(this + 24))) {
    //         char name[32];
    //         StringFormatWithBufferOverflowCheck(name, "%s%d,%d.mp3", asc_5BE820, *(int *)(this + 92), *(int *)(this + 28));
    //         *(int *)(this + 12) = AIL_open_stream(*(int *)(driver + 144), name, 0);
    //       }
    //     }
    //     if (*(int *)(this + 12)) {
    //       AIL_register_stream_callback(*(int *)(this + 12), SettingsSaveWrapper);
    //       AIL_start_stream(*(int *)(this + 12));
    //       AIL_set_stream_volume_levels(*(int *)(this + 12), *(float *)(this + 4), *(float *)(this + 4));
    //       return MutexLockWithTimeout(this, 2);
    //     } else {
    //       MutexLockWithTimeout(this, 0);
    //       for (int n = 3, p = this + 28; n != 0; --n, p += 20) {
    //         StringCopyWithBufferRealloc(&byte_5EA438);
    //         *(int *)(p - 4) = -1; *(int *)p = -1; *(unsigned char *)(p + 4) = 0;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Byte-level contents of the format constants aSD_1 and aSDDMp3 are inferred from the decompiled format arguments, not verified against data.
    // UNRESOLVED: The field at this+92 (offset 0x5C) is used only on the track-update filename path; its exact semantic role (slot index) is DERIVED.
    // UNRESOLVED: The three 20-byte slot groups reset on failure span offsets 24-52, 44-72 and 64-92 decimal; only the first write site is named by the field table.
}
