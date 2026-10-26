// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561F80
// Canonical corpus name: SocketCloseAndCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SocketCloseAndCleanup_00561f80.c

void UnknownObject::SocketCloseAndCleanup()
{
    // Socket teardown and cleanup. When the passed socket-struct pointer is null it falls back to the global off_5E4DFC. Closes the primary handle at this+0x0 when it differs from -1 (0xFFFFFFFF) and the active flag at this+0xE4 (v1[57]) is non-zero, then closes the secondary handle at this+0x4 when it differs from both -1 and the primary handle. Resets both handles to -1, zeroes the field at this+0xD8, frees the struct via sub_58AA6F unless it is the default singleton at unk_5E4CF8, and returns the result of WSACleanupThunk.
    // ASSIGNMENT: Bind the socket-struct pointer: when lpMem is null, use the global default pointer off_5E4DFC instead. [global:0x005E4DFC, source:raw]
    // GUARD: Guard at this+0x0: closesocket(*v1) runs only when the primary socket handle differs from -1 (0xFFFFFFFF) and the flag at this+0xE4 (v1[57]) is non-zero. [field:this:0x00000000, field:this:0x000000E4, guard:0, source:raw]
    // CALL: Close the primary socket handle *v1 via closesocket. [callee:0x0059865A, field:this:0x00000000, source:raw]
    // GUARD: Guard at this+0x4: closesocket(v1[1]) runs only when the secondary handle differs from -1 (0xFFFFFFFF) and also differs from the primary handle at this+0x0. [field:this:0x00000004, field:this:0x00000000, source:raw]
    // CALL: Close the secondary socket handle v1[1] via closesocket. [callee:0x0059865A, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Reset both socket handles to -1 (0xFFFFFFFF): first v1[1] at this+0x4, then *v1 at this+0x0. [field:this:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the field at this+0xD8 (v1[54]). [field:this:0x000000D8, source:raw]
    // GUARD: Guard: the socket struct is released only when v1 is not the default singleton at unk_5E4CF8. [global:0x005E4CF8, source:raw]
    // CALL: Call sub_58AA6F(v1) to free the socket struct when it is not the default singleton at unk_5E4CF8. [callee:0x0058AA6F, global:0x005E4CF8, source:raw]
    // RETURN: Return the result of the WSACleanupThunk import wrapper. [source:raw]

    // Conservative worker pseudocode:
    //   int SocketCloseAndCleanup(SOCKET *lpMem) {
    //     SOCKET *v1 = lpMem ? lpMem : (SOCKET *)off_5E4DFC;
    //     if (*v1 != -1 && v1[57]) closesocket(*v1);
    //     if (v1[1] != -1 && v1[1] != *v1) closesocket(v1[1]);
    //     v1[1] = -1;
    //     *v1 = -1;
    //     v1[54] = 0;
    //     if (v1 != (SOCKET *)&unk_5E4CF8) sub_58AA6F(v1);
    //     return WSACleanupThunk();
    //   }
    // UNRESOLVED: Semantics of the fields at this+0xE4 (v1[57], read as the active flag before closing) and this+0xD8 (v1[54], reset to 0) are not established by this packet.
    // UNRESOLVED: The owning class is UnknownObject; the only listed caller is BooleanFlagResetWithSideEffects (0x0045D240).
    // UNRESOLVED: WSACleanupThunk is an import wrapper invoked at return; it has no callee evidence reference in this packet.
}
