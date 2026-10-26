// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566B20
// Canonical corpus name: AudioStreamOpen
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamOpen_00566b20.c

void UnknownObject::OpenAudioStream()
{
    // Opens an audio stream on the receiver this: closes any previous handle, prepares a 1024-byte scratch buffer, opens the file via sub_534B00, stores the handle and stream parameter, sets two initialized/active flags, and copies filename string data when the handle is valid. Returns whether the handle was obtained.
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(this): close previous file handle on this if its flag says so. [callee:0x00566B90, source:raw]
    // CALL: sub_568620(1024): prepare a 1024-byte scratch buffer for the filename copy. [callee:0x00568620, source:raw]
    // CALL: sub_534B00(): open the audio file/stream and store the returned handle into this+0x0. [callee:0x00534B00, field:this:0x00000000, source:raw]
    // CALCULATION: Set success flag v5 = (handle != 0). [source:raw]
    // ASSIGNMENT: Set this+0x10 (initialized flag) to 1. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Store caller stream parameter a3 into this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set this+0x18 (stream active flag, byte) to 1. [field:this:0x00000018, source:raw]
    // GUARD: Guard on handle != 0 before copying the filename string. [source:raw]
    // CALL: StringCopyWithBufferRealloc(this+4, v7): copy the 1024-byte filename buffer v7 into the string buffer at this+4. [callee:0x00566650, source:raw]
    // RETURN: Return success flag v5 (whether the stream handle was obtained). [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_566B20(int *this, int a2, int a3) {
    //     ConditionalFileHandleCloseWithFlagDispatch(this);
    //     sub_568620(1024);
    //     int h = sub_534B00();
    //     bool ok = h != 0;
    //     *this = h;
    //     this[4] = 1;
    //     this[3] = a3;
    //     *((char *)this + 24) = 1;
    //     if (h) StringCopyWithBufferRealloc((int)(this + 1), v7);
    //     return ok;
    //   }
    // UNRESOLVED: Global aRb (0x005BE828, read-only, 'rb' file-mode string) is consumed somewhere on the open path but its exact use site is not visible in the raw source.
    // UNRESOLVED: String buffer at this+4 is written but absent from the packet field evidence.
    // UNRESOLVED: Copy direction of StringCopyWithBufferRealloc (this+4 destination vs source) is not conclusively evidenced.
}
