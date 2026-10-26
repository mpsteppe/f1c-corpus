// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005426E0
// Canonical corpus name: sub_5426E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5426E0_005426e0.c

void UnknownObject::StreamModeConfigSetter()
{
    // Maps a stream-mode value (1-13) to a bitmask flag and stores both in the object: the raw mode value at this[12] (offset 0x30) and the derived mask at this[9] (offset 0x24). When the video stream mode is undefined (a3 >= 0, a2 == 0 and global dword_8B8DE4 == 255) it reports "UndefinedVideo" through sub_53C590(-1, ...) and returns -1; otherwise it returns 0.
    // GUARD: Validate the video stream mode: if a3 >= 0 and a2 is zero and the global dword_8B8DE4 equals 255, the video stream mode is undefined and the error path is taken. [global:0x008B8DE4]
    // CALL: Report the undefined video stream mode by calling sub_53C590(-1, aUndefinedVideo). [callee:0x0053C590, global:0x005DBD7C]
    // RETURN: Return -1 after reporting the undefined video stream mode. [source:raw]
    // STATE_TRANSITION: Dispatch on v3 (a2, or dword_8B8DE4 when a2 is zero) through the switch jump table jpt_542716. [global:0x0054279C]
    // ASSIGNMENT: Store the resolved mode value v3 into this[12] (byte offset 0x30); the default case stores 255 instead. [field:this:0x00000030]
    // ASSIGNMENT: Store the mode-derived bitmask into this[9] (byte offset 0x24): mask 1 for modes 1, 9, 10, 11, 12 and 13; 2 for mode 2; 4 for mode 3; 8 for mode 4; 16 for modes 5 and 6; 24 for mode 7; 32 for mode 8; 0 in the default case. [field:this:0x00000024]
    // RETURN: Return 0 on the successful switch path after assigning mode and mask. [source:raw]

    // Conservative worker pseudocode:
    //   int StreamModeConfigSetter(int* this, int a2, short a3) {
    //     int v3 = a2;
    //     if (a3 < 0 || a2 || (v3 = dword_8B8DE4, dword_8B8DE4 != 255)) {
    //       switch (v3) {
    //         case 1: case 9: case 10: case 11: case 12: case 13: this[12] = v3; this[9] = 1; break;
    //         case 2: this[12] = v3; this[9] = 2; break;
    //         case 3: this[12] = v3; this[9] = 4; break;
    //         case 4: this[12] = v3; this[9] = 8; break;
    //         case 5: case 6: this[12] = v3; this[9] = 16; break;
    //         case 7: this[12] = v3; this[9] = 24; break;
    //         case 8: this[12] = v3; this[9] = 32; break;
    //         default: this[12] = 255; this[9] = 0; break;
    //       }
    //       return 0;
    //     }
    //     sub_53C590(-1, aUndefinedVideo);
    //     return -1;
    //   }
    // UNRESOLVED: Concrete class and type of `this` are unknown; only dword slots 9 and 12 (byte offsets 0x24 and 0x30) are evidenced.
    // UNRESOLVED: The guard permits a3 < 0, which falls through to the switch default case; the meaning of a negative mode value is unclear.
    // UNRESOLVED: That dword_8B8DE4 is the current video-stream-mode global is inferred from the existing analysis fill, not independently proven by this packet.
    // UNRESOLVED: Callers UtilityFunction_2950 (0x00542950) and sub_5429B0 (0x005429B0) are not analyzed here; how they interpret the mode and mask fields is unknown.
}
