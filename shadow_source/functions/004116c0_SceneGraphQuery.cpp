// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004116C0
// Canonical corpus name: SceneGraphQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneGraphQuery_004116c0.c

void UnknownObject::SceneGraphQuery()
{
    // Queries audio commentary channel configuration through AudioCommentaryChannelConfiguration(), which fills four out-parameters. If the object at global dword_8AC4C4 is non-null and the query succeeds, dispatches two __thiscall calls through that object's vtable method at offset 72: one with (v5, v4) and one with (v7, v6). Returns the query result v3, or 1 when the global object is null.
    // ASSIGNMENT: Load v1 from the global dword_8AC4C4 and preset the default result to 1. [global:0x008AC4C4, source:raw]
    // GUARD: Guard: skip the whole body when the global object dword_8AC4C4 is null. [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Initialize the four out-parameters: v4 = -1, v6 = -1, v5 = 0, v7 = 0. [source:raw]
    // CALL: Call AudioCommentaryChannelConfiguration(a1, &v4, &v6, &v5, &v7) and store its return value in v3. [callee:0x004117B0, source:raw]
    // GUARD: Guard: only dispatch the two vtable calls when the query result v3 is zero (success). [source:raw]
    // CALL: Dispatch two __thiscall calls through the vtable method at offset 72 of the object v1, first with (v1, v5, v4), then with (v1, v7, v6), forwarding the filled channel parameters. [source:raw]
    // RETURN: Return v3 on the success path, otherwise return the default result 1. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneGraphQuery(int a1) {
    //     int v1 = dword_8AC4C4;
    //     if (v1) {
    //       int v4 = -1, v6 = -1, v5 = 0, v7 = 0;
    //       int v3 = AudioCommentaryChannelConfiguration(a1, &v4, &v6, &v5, &v7);
    //       if (!v3) {
    //         (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v1 + 72))(v1, v5, v4);
    //         (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v1 + 72))(v1, v7, v6);
    //       }
    //       return v3;
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Identity of the object at global dword_8AC4C4 and the semantic of its vtable method at offset 72 are unknown; the two calls likely configure audio commentary channels from the queried parameters.
    // UNRESOLVED: Meaning of the two out-parameter pairs (v5, v4) and (v7, v6) filled by AudioCommentaryChannelConfiguration is not established.
    // UNRESOLVED: The canonical name SceneGraphQuery does not match the audio-commentary character of the body; the mismatch is unresolved.
}
