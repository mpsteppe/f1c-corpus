// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FE50
// Canonical corpus name: sub_54FE50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54FE50_0054fe50.c

void UnknownObject::audioEmitterCreateFromPath()
{
    // Creates an audio emitter (60-byte allocation via OperatorNewNhMallocWrapper, initialized by AudioEmitterCreate) and stores its pointer at offset 0x54, then extracts the filename portion after the last backslash from a resource path and copies it into the string buffer at this+4, post-processing it via sub_589901, and returns 0.
    // CALL: Allocate a 60-byte block for the audio emitter via OperatorNewNhMallocWrapper [callee:0x00587C03, source:raw]
    // GUARD: If the allocation returned null, use a null emitter pointer instead of creating an emitter [source:raw]
    // CALL: Create the audio emitter object on the allocated block via AudioEmitterCreate [callee:0x005426A0, source:raw]
    // ASSIGNMENT: Store the emitter pointer into the DWORD field at offset 0x54 [field:this:0x00000054, source:raw]
    // CALCULATION: Compute the length of the path including the null terminator (strlen(a2) + 1) [source:raw]
    // LOOP: Scan backward from the end of the path for the last backslash separator (ASCII 92) [source:raw]
    // CALCULATION: Compute the start of the filename portion immediately after the last backslash [source:raw]
    // LOOP: Copy the filename characters into the string buffer at this+4 up to the null terminator [source:raw]
    // CALL: Post-process the extracted filename buffer via sub_589901 [callee:0x00589901, source:raw]
    // RETURN: Return 0 to signal success [function:0x0054FE50, source:raw]

    // Conservative worker pseudocode:
    //   int create(const CHAR* this, const char* path) {
    //     void* mem = OperatorNewNhMallocWrapper(60);
    //     this[21] = mem ? AudioEmitterCreate(mem) : 0;
    //     unsigned int len = strlen(path) + 1;
    //     int end = len - 2;
    //     if (path[end] != 92) {
    //       do { --end; } while (end >= 0 && path[end] != 92);
    //     }
    //     char* dst = (char*)this + 4;
    //     const char* src = &path[end + 1];
    //     do {
    //       char c = *src;
    //       *dst++ = c;
    //       ++src;
    //     } while (c);
    //     sub_589901((char*)this + 4);
    //     return 0;
    //   }
}
