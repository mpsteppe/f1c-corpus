// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562C50
// Canonical corpus name: NetworkCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkCleanup_00562c50.c

void UnknownObject::NetworkCleanup()
{
    // Tears down a network-session-style object: runs a batch cleanup loop over the sub-object at this+0x4, frees the audio array elements and container at this+0x94, deallocates the sub-object at this+0x8, deallocates the object itself, then returns the result of a WSACleanup thunk call.
    // CALL: Call BatchLoopWithMemoryCleanup(lpMem[1]) on the sub-object pointer stored at this+0x4 to clean up its memory entries. [callee:0x00564860, field:this:0x00000004, source:raw]
    // CALL: Call DestroyAudioArrayFreeElementsThenContainer(lpMem[37]) on the audio element array pointer stored at this+0x94 to free its elements and container. [callee:0x00564740, field:this:0x00000094, source:raw]
    // CALL: Call sub_58AA6F(lpMem[2]) to deallocate the sub-object pointer stored at this+0x8. [callee:0x0058AA6F, field:this:0x00000008, source:raw]
    // CALL: Call sub_58AA6F(lpMem) to deallocate the object itself. [callee:0x0058AA6F, source:raw]
    // RETURN: Return the result of the WSACleanup thunk call. [source:raw]

    // Conservative worker pseudocode:
    //   int NetworkCleanup(LPVOID *lpMem) {
    //     BatchLoopWithMemoryCleanup(lpMem[1]);
    //     DestroyAudioArrayFreeElementsThenContainer(lpMem[37]);
    //     sub_58AA6F(lpMem[2]);
    //     sub_58AA6F(lpMem);
    //     return WSACleanupThunk();
    //   }
    // UNRESOLVED: The WSACleanup thunk is called in the raw source but has no callee entry in the packet, so its address is not recorded.
    // UNRESOLVED: Whether this is a destructor-like teardown of a network session object or a general-purpose cleanup path is not established; field semantics at 0x4, 0x8 and 0x94 rest on the callee names only.
}
