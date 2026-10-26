// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562D20
// Canonical corpus name: SocketArrayCreate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketArrayCreate_00562d20.c

void UnknownObject::SocketArrayCreate()
{
    // Creates a pre-allocated array of sockets. Guarded by the count field at this+0x6C (this[27]): if it is not > 0 the function returns 0 immediately. Otherwise it loops over 28-byte entries addressed off the array base pointer this[2] (this+0x8), calling socket(2, 2, 17) for each and storing the handle at entry+0, zero-initializing entry+4 and entry+8. If socket() returns -1 the loop breaks: with no successful sockets it returns 1, otherwise it truncates this+0x6C to the count already created and returns 0. Returns 0 when the full requested count is reached.
    // GUARD: guard:0 — enter the creation loop only when this[27] (this+0x6C, socket count) is > 0; otherwise skip and return 0 [guard:0, field:this:0x0000006C, source:raw]
    // ASSIGNMENT: Initialize v2 (successfully created socket count) to 0 [source:raw]
    // LOOP: Loop over 28-byte entries (i += 28) until v2 reaches the requested count this[27] [field:this:0x0000006C, source:raw]
    // CALL: Call socket(2, 2, 17) (AF_INET, SOCK_DGRAM, IPPROTO_UDP) and store the handle at this[2]+i (entry +0 of the current 28-byte entry) [callee:0x00598648, field:this:0x00000008, source:raw]
    // GUARD: If the just-created socket handle at this[2]+i equals -1, break out of the creation loop [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero-initialize entry+4 and entry+8 of the current entry [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Increment v2 after each successful socket creation [source:raw]
    // GUARD: If v2 has reached the requested count this[27], return 0 (success) [field:this:0x0000006C, source:raw]
    // STATE_TRANSITION: On an early break with v2 == 0 return 1 (no sockets created); on a break with v2 > 0 truncate this[27] (this+0x6C) to v2 and return 0 [field:this:0x0000006C, source:raw]
    // RETURN: Return 0 when the requested count is not > 0, when the full count is reached, or after truncation on a partial failure [source:raw]
    // CALL: Called by DeviceInitializationWithStateSetup (0x00562C90), MultiStageInitializationChainWithErrorChecking (0x00563020), and NetworkConnection (0x00563260) [caller:0x00562C90, caller:0x00563020, caller:0x00563260]

    // Conservative worker pseudocode:
    //   int SocketArrayCreate(_DWORD *this) {
    //     int v2 = 0;
    //     if ((int)this[27] <= 0)
    //       return 0;
    //     for (int i = 0; ; i += 28) {
    //       *(int*)(i + this[2]) = socket(2, 2, 17);
    //       if (*(int*)(this[2] + i) == -1)
    //         break;
    //       *(int*)(this[2] + i + 4) = 0;
    //       ++v2;
    //       *(int*)(this[2] + i + 8) = 0;
    //       if (v2 >= this[27])
    //         return 0;
    //     }
    //     if (!v2)
    //       return 1;
    //     this[27] = v2;
    //     return 0;
    //   }
    // UNRESOLVED: The packet does not evidence the socket-array buffer's allocation site or the meaning of entry+4 and entry+8 of each 28-byte entry
    // UNRESOLVED: Constants 2/2/17 as AF_INET/SOCK_DGRAM/IPPROTO_UDP are a Winsock interpretation of the raw-source literals; the packet provides no independent confirmation
}
