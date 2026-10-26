// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00598690
// Canonical corpus name: __WSAFDIsSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/__WSAFDIsSet_00598690.c

void UnknownObject::wsaFdIsSetThunk()
{
    // WinSock import thunk (stdcall): forwards the fd_set membership test to the imported WSAFDIsSet entry by jumping through the IAT slot __imp___WSAFDIsSet at 0x0059E30C, returning the imported function's result unchanged. An opaque system API wrapper with no game-side logic.
    // ASSIGNMENT: Resolve the forwarding target by reading the import address table slot __imp___WSAFDIsSet at 0x0059E30C (read access). [global:0x0059E30C, source:raw]
    // CALL: Tail-call the imported WSAFDIsSet(fd, a2), passing the socket handle and fd_set pointer through unchanged. [abi:lead, source:raw]
    // RETURN: Return the imported WSAFDIsSet result; the function is a pure forwarding thunk. [source:raw]
    // CALL: Reached from sub_563AB0 (0x00563AB0), which routes a socket/fd-set query through this thunk. [caller:0x00563AB0, abi:lead]

    // Conservative worker pseudocode:
    //   int __stdcall wsaFdIsSetThunk(SOCKET fd, fd_set *set) {
    //     return WSAFDIsSet(fd, set); // via IAT slot __imp___WSAFDIsSet at 0x0059E30C
    //   }
    // UNRESOLVED: The ws2_32 imported implementation and the exact fd_set layout are external to the corpus; only the forwarding contract is evident here.
}
