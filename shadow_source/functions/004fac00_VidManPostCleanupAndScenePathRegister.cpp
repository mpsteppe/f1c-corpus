// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FAC00
// Canonical corpus name: VidMan_Post
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VidMan_Post_004fac00.c

void UnknownObject::VidManPostCleanupAndScenePathRegister()
{
    // VidMan post-processing entry (called from Game_Post). It optionally writes an 'entered VidMan' debug log line, resets the frame-rate counter via FrameRateCounterInitReset, releases and clears the global mutex/semaphore handle dword_8AFE88, resets a global via SingleGlobalSetter(0), then, when a scene struct exists at 396 * dword_8AC48C + dword_8AC490, copies the scene's path string from result + 4 into a local buffer, trims trailing backslash segments, and registers the resulting directory path via StringMatchWithFlagSet. Returns the StringMatchWithFlagSet result on the active-scene path, otherwise the null scene pointer (0).
    // CALL: Format the log prefix into the debug buffer: StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1426). [callee:0x004D7A50, global:0x008AD25C, global:0x005D6DC4, source:raw]
    // GUARD: If the format call returned nonzero, write the entry log line. [source:raw]
    // CALL: Log entry: DebugLogWrite(dword_8AD25C, aEnteredVidmanP). [callee:0x004D7AA0, global:0x008AD25C, global:0x005D6ED0, source:raw]
    // CALL: Reset the frame-rate counter: FrameRateCounterInitReset(&dword_8AFCA8). [callee:0x004F8EA0, global:0x008AFCA8, source:raw]
    // CALL: Release the mutex/semaphore handle: MutexSemaphoreCleanup(dword_8AFE88). [callee:0x005461B0, global:0x008AFE88, source:raw]
    // ASSIGNMENT: Clear the handle: dword_8AFE88 = 0. [global:0x008AFE88, source:raw]
    // CALL: Reset a global state flag: SingleGlobalSetter(0). [callee:0x0053D400, source:raw]
    // CALCULATION: Resolve the current scene struct: result = 396 * dword_8AC48C + dword_8AC490 (index times stride plus array base). [global:0x008AC48C, global:0x008AC490, source:raw]
    // GUARD: If no scene is active (result == 0), skip path extraction and registration and return result. [source:raw]
    // LOOP: Copy the scene path string from *(result + 4) into the 512-byte local buffer v8. [source:raw]
    // CALCULATION: Trim the path tail: walk backwards from the end zeroing characters until the first backslash (value 92), leaving the backslash in place. [source:raw]
    // CALCULATION: Drop a single trailing backslash left by the trim: if the last character is 92, clear it. [source:raw]
    // RETURN: Register the extracted scene directory path: return StringMatchWithFlagSet(v8). [callee:0x0053C900, source:raw]
    // RETURN: Null-scene path returns the earlier computed result (0). [source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(dword_8AD25C, 2, aDDevF119992002_26, 1426))
    //       DebugLogWrite(dword_8AD25C, aEnteredVidmanP);
    //   FrameRateCounterInitReset(&dword_8AFCA8);
    //   MutexSemaphoreCleanup(dword_8AFE88);
    //   dword_8AFE88 = 0;
    //   SingleGlobalSetter(0);
    //   int result = 396 * dword_8AC48C + dword_8AC490;
    //   if (result) {
    //       char v8[512];
    //       const char* src = (const char*)(result + 4);
    //       strcpy(v8, src);
    //       v4 = strlen(v8);
    //       if (v4 > 0)
    //           for (i = &v8[v4 - 1]; i >= v8; *i-- = 0)
    //               if (*i == 92) break;
    //       v6 = strlen(v8);
    //       if (v6 > 0 && v8[v6 - 1] == 92) v8[v6 - 1] = 0;
    //       return StringMatchWithFlagSet(v8);
    //   }
    //   return result;
    // UNRESOLVED: Global dword_8AFE64 is listed in the packet but absent from the raw source; its role here is unknown.
    // UNRESOLVED: The 1426 parameter passed to StringSplitLoop is a fixed message/length token; its meaning is unknown.
    // UNRESOLVED: The byte value 92 (backslash) tail-trim implements directory-path extraction; other path separator conventions are not handled.
    // UNRESOLVED: StringMatchWithFlagSet registers the trimmed path and sets an associated flag; the exact match semantics are DERIVED from the existing analysis.
    // UNRESOLVED: The scene struct layout (stride 396 per dword_8AC48C index, path string at offset 4) is a DERIVED interpretation, not confirmed by the packet.
}
