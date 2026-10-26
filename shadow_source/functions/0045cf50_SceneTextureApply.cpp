// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045CF50
// Canonical corpus name: SceneTextureApply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneTextureApply_0045cf50.c

void UnknownObject::SceneTextureApply()
{
    // Builds a formatted network session display string: hostname, host port, map name, player count, max players, and game mode (open/closed). First validates the network entrant via NetworkEntrantSetupWithIDCheck; each field is emitted as a key-value pair through ShortComputation_ce30 with this as the output context. Map name is read from the current scene entry (dword_8AC490 + 396 * dword_8AC48C) via EventNameReader, falling back to a local buffer when event reading fails.
    // CALL: FAILWRONGDESCRIPTION(v11): initialize/validate the output buffer before formatting. [callee:0x00461550]
    // GUARD: If NetworkEntrantSetupWithIDCheck(v11, &v9) returns zero, skip all formatting and jump to the final cleanup call. [callee:0x004627C0]
    // CALL: ShortComputation_ce30(aHostname, v11, this): emit the hostname key-value pair. [callee:0x0045CE30, global:0x005C5C34]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%d", v9): format the host port number as a decimal string. [callee:0x0058815F]
    // CALL: ShortComputation_ce30(aHostport, v10, this): emit the host port key-value pair. [callee:0x0045CE30, global:0x005C5C28]
    // CALL: SceneDataParser(v12): parse scene/session data into the local buffer v12. [callee:0x004C5690]
    // CALCULATION: Compute the current scene entry pointer: v3 = dword_8AC490 + 396 * dword_8AC48C (array base plus 396-byte stride times scene index). [global:0x008AC490, global:0x008AC48C]
    // GUARD: If v3 is nonzero, resolve the map name from the scene entry. [source:raw]
    // ASSIGNMENT: Initialize the event-name buffer v13: seed the first byte from byte_5EA438, zero the remainder, and clear trailing fields. [global:0x005EA438]
    // CALL: EventNameReader(v13, 128): read the event/scene name; if it succeeds use the scene entry name at v3+260 instead. [callee:0x004C5900]
    // CALL: ShortComputation_ce30(aMapname, v5, this): emit the map name key-value pair, where v5 is the event-read buffer or the scene entry name. [callee:0x0045CE30, global:0x005C5C20]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%d", v12[68] + v12[69] + 1) then ShortComputation_ce30(aNumplayers, v10, this): emit the player count derived from parsed scene bytes. [callee:0x0058815F, callee:0x0045CE30, global:0x005C5C14]
    // CALL: StringFormatWithBufferOverflowCheck(v10, "%d", v12[70]) then ShortComputation_ce30(aMaxplayers_0, v10, this): emit the max-players count from parsed scene byte 70. [callee:0x0058815F, callee:0x0045CE30, global:0x005C5C08]
    // CALL: SingleFunctionCallWrapper_2a00(dword_7CD25C): query the session-open state; select aOpenplaying if true else aClosedplaying. [callee:0x00462A00, global:0x007CD25C, global:0x005C5BF0, global:0x005C5BE0]
    // CALL: ShortComputation_ce30(aGamemode, v7, this): emit the game-mode key-value pair with the open/closed string. [callee:0x0045CE30, global:0x005C5BFC]
    // RETURN: Return EmptyStub_0170(v11), the final output-buffer cleanup call. [callee:0x004B0170]

    // Conservative worker pseudocode:
    //   int sub_45CF50(char *this, int a2) {
    //     char out[32]; FAILWRONGDESCRIPTION(out);
    //     unsigned short port;
    //     if (NetworkEntrantSetupWithIDCheck(out, &port)) {
    //       ShortComputation_ce30(aHostname, out, this);
    //       char buf[16] = {0}; StringFormatWithBufferOverflowCheck(buf, "%d", port);
    //       ShortComputation_ce30(aHostport, buf, this);
    //       char scene[96]; SceneDataParser(scene);
    //       int entry = dword_8AC490 + 396 * dword_8AC48C;
    //       if (entry) {
    //         char name[125]; name[0] = byte_5EA438[0]; memset(name+1, 0, 124);
    //         const char *mapname = name;
    //         if (EventNameReader(name, 128)) mapname = (const char*)(entry + 260);
    //         ShortComputation_ce30(aMapname, mapname, this);
    //       }
    //       StringFormatWithBufferOverflowCheck(buf, "%d", scene[68] + scene[69] + 1);
    //       ShortComputation_ce30(aNumplayers, buf, this);
    //       StringFormatWithBufferOverflowCheck(buf, "%d", scene[70]);
    //       ShortComputation_ce30(aMaxplayers_0, buf, this);
    //       const char *mode = SingleFunctionCallWrapper_2a00(dword_7CD25C) ? aOpenplaying : aClosedplaying;
    //       ShortComputation_ce30(aGamemode, mode, this);
    //     }
    //     return EmptyStub_0170(out);
    //   }
    // UNRESOLVED: Raw source does not reference aD_1 (0x005C3280) or unk_8AC368 (0x008AC368); both appear only in the packet's global list and existing analysis.
    // UNRESOLVED: Semantics of the bytes v12[68], v12[69], v12[70] (player count / max players derivation) come from call order, not proven fields.
    // UNRESOLVED: Function parameter a2 is unused in the raw source.
    // UNRESOLVED: The owner object type and the meaning of 'this' (output context passed to ShortComputation_ce30) are unknown.
}
