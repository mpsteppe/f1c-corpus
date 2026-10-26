// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BE80
// Canonical corpus name: sub_45BE80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45BE80_0045be80.c

void UnknownObject::AVIStreamGlobalCleanup()
{
    // Cleanup routine for a global AVI stream handle: passes the address of the global dword_7CD208 to AVIStreamCleanup to release the stream, snapshots the global value into a local, and when that value is non-null frees the object via FreeWrapper_7bcf. Returns the freed pointer's result on the non-null path, otherwise the (null) snapshot of the global.
    // CALL: Release the AVI stream: AVIStreamCleanup((int)&dword_7CD208) is called with the address of the global stream-handle slot. [callee:0x0045BEA0, global:0x007CD208, source:raw]
    // ASSIGNMENT: Snapshot the global stream-handle value: result = dword_7CD208 is read into a local for the null check and the null-path return. [global:0x007CD208, source:raw]
    // GUARD: Guard on the global stream-handle value: the object is only freed when dword_7CD208 is non-null. [global:0x007CD208, source:raw]
    // CALL: Free the object: FreeWrapper_7bcf((LPVOID)dword_7CD208) is invoked on the non-null global value. [callee:0x00587BCF, global:0x007CD208]
    // RETURN: Return the value of the FreeWrapper_7bcf call when the global was non-null, else the snapshotted (null) global value. [callee:0x00587BCF, function:0x0045BE80, source:raw]

    // Conservative worker pseudocode:
    //   int AVIStreamGlobalCleanup() {
    //     AVIStreamCleanup(&dword_7CD208);
    //     int result = dword_7CD208;
    //     if (dword_7CD208) return FreeWrapper_7bcf((LPVOID)dword_7CD208);
    //     return result;
    //   }
    // UNRESOLVED: The type and lifecycle of the object tracked by dword_7CD208 are not evidenced; it is only shown to be passed to AVIStreamCleanup and conditionally freed.
    // UNRESOLVED: Whether FreeWrapper_7bcf nulls the global after freeing is not evidenced by this packet.
    // UNRESOLVED: No static callers exist, so the shutdown/cleanup trigger that invokes this routine is unknown.
}
