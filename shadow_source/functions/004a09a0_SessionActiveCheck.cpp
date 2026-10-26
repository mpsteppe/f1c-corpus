// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A09A0
// Canonical corpus name: SessionActiveCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionActiveCheck_004a09a0.c

void UnknownObject::SessionActiveCheck()
{
    // Checks whether a session is active by dereferencing the linked-list buffer global dword_7D2DB0 via LinkedListDereference. When the dereference yields non-null, marks the session active (return value 0), resolves a vehicle setup path from the same buffer through DelegationChain, loads the track scene from that path via TrackSceneLoader (falling back to the default byte_5EA438 path when the chain result is null), and runs the session scene sub-initializer sub_4A09F0 on this. Returns 1 when no session is active, 0 after the active-session scene setup path. Invoked by sub_4A0590.
    // ASSIGNMENT: Initializes the return value v2 to 1 (inactive) before the session-activity check [source:raw]
    // GUARD: Dereferences the linked-list buffer global dword_7D2DB0 via LinkedListDereference; a non-null result means a session is active and execution proceeds to scene setup, a null result keeps the inactive default [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Marks the session active by setting the return value v2 to 0 [source:raw]
    // CALL: Calls DelegationChain on the same dword_7D2DB0 buffer to resolve the vehicle setup path [callee:0x004C29D0, global:0x007D2DB0, source:raw]
    // GUARD: The delegation chain result must be non-null; when null the scene load and session sub-initializer are skipped while the active (0) result is still returned [source:raw]
    // ASSIGNMENT: Reads the path string from the delegation chain result; when null, falls back to the default byte_5EA438 path [global:0x005EA438, source:raw]
    // CALL: Loads the track scene from the resolved path string via TrackSceneLoader [callee:0x004C55B0, source:raw]
    // CALL: Runs the session scene sub-initializer sub_4A09F0 on this [callee:0x004A09F0, source:raw]
    // RETURN: Returns v2: 1 when no session was active, 0 after the active-session scene setup path [source:raw]
    // CALL: Invoked by sub_4A0590 (004A0590), which consumes the result to gate subsequent session setup [caller:0x004A0590]

    // Conservative worker pseudocode:
    //   v2 = 1;
    //   if (LinkedListDereference(&dword_7D2DB0) != null) {
    //     v2 = 0;
    //     v3 = DelegationChain(&dword_7D2DB0);
    //     if (v3 != null) {
    //       v4 = *v3;
    //       if (v4 == null) v4 = byte_5EA438;
    //       TrackSceneLoader(v4);
    //       sub_4A09F0(this);
    //     }
    //   }
    //   return v2;
    // UNRESOLVED: Object type behind `this` is unknown; the ABI label is LEGACY Session_Active_Check, so the owner remains UnknownObject/UNKNOWN
    // UNRESOLVED: Global unk_8AC368 is flagged as read by packet facts but never appears in the raw decompiled source
    // UNRESOLVED: Exact semantics of the dword_7D2DB0 buffer (existing analysis names it RaceStandingsSortBuffer) and of DelegationChain's returned path are not verifiable from this packet alone
}
