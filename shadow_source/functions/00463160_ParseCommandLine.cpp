// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463160
// Canonical corpus name: NetCommParseCommandLine
// Owner: NetComm [DERIVED]
// Raw source: functions/NetCommParseCommandLine_00463160.c

void NetComm::ParseCommandLine()
{
    // Parses the process command-line string (a2) for NetComm network options (--password, --dedicated, --host, --gamename, --connect, --name, --maxplayers) and populates a NetComm configuration object: host/connect flags, connect address buffer with a defaulted port, game name, player name, and a clamped maximum player count. Development logging is gated on dword_7C569C != 5 and a StringSplitLoop condition.
    // GUARD: If dword_7C569C != 5 and StringSplitLoop(1, aDDevF119992002_1, 6949) returns nonzero, enable the NetComm check-in debug log. [global:0x007C569C, global:0x005C5CE4, callee:0x004D7A50]
    // CALL: DebugLogWrite(&dword_8AD25C, aNetcommCheckin) logs that NetComm command-line parsing is starting. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C64E4]
    // GUARD: sub_566810(a2, aPassword) searches the command line for the password token; if absent, the password block is skipped. [callee:0x00566810, global:0x005C64D8]
    // ASSIGNMENT: sub_587DD0(v28, token_value + strlen(aPassword), 15) copies at most 15 characters of the password value into local buffer v28, then v28[15] = 0 terminates it. [callee:0x00587DD0, global:0x005C64D8]
    // ASSIGNMENT: sub_587C20(v28, asc_5C64D4) locates a separator character in the password buffer; if found, that position is zeroed to truncate the password. [callee:0x00587C20, global:0x005C64D4]
    // CALL: StringCopyToStructField(v28) copies the parsed password into a configuration struct field managed by that routine. [callee:0x00463710]
    // GUARD: If dword_7C569C != 5 and StringSplitLoop(1, aDDevF119992002_1, 6970) returns nonzero, enable the game-password debug log. [global:0x007C569C, global:0x005C5CE4, callee:0x004D7A50]
    // CALL: DebugLogWrite(&dword_8AD25C, aSettingGamePas) logs that the game password is being set. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C64B4]
    // GUARD: If sub_566810(a2, aDedicated) finds the dedicated token, the entire host/connect block is skipped: dedicated servers do not parse host or connect arguments. [callee:0x00566810, global:0x005C64A8]
    // GUARD: If sub_566810(a2, aHost) finds the host token, parse host configuration; otherwise fall through to the connect branch. [callee:0x00566810, global:0x005C64A0]
    // ASSIGNMENT: Set the object byte field at offset 197 to 1, marking the session as host. [field:obj:0x000000C5]
    // CALL: DebugLogWrite(&dword_8AD25C, aNetcommActivat) logs that NetComm host mode is being activated. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C6480]
    // GUARD: If sub_566810(a2, aGamename) finds the game-name token, parse the game name. [callee:0x00566810, global:0x005C6474]
    // ASSIGNMENT: sub_587DD0(v28, token_value + strlen(aGamename), 63) copies at most 63 characters of the game-name value into v28, then v28[63] = 0 terminates it. [callee:0x00587DD0, global:0x005C6474]
    // ASSIGNMENT: sub_5897CA(v28, asc_5C64D4) cleans the game-name buffer; if the result is non-empty, strcpy copies it into the object buffer at offset 364. [callee:0x005897CA, global:0x005C64D4, field:this:0x00000000]
    // CALL: DebugLogWrite(&dword_8AD25C, aSettingGameNam) logs that the game name is being set. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C6458]
    // GUARD: If sub_566810(a2, aConnect) finds the connect token, parse the connect address and port. [callee:0x00566810, global:0x005C644C]
    // ASSIGNMENT: sub_587DD0(object_buffer_at_offset_200, connect_value, 79) copies at most 79 characters of the connect argument into the object address buffer at offset 200, then the byte at +79 is zeroed. [callee:0x00587DD0, field:obj:0x000000C8]
    // ASSIGNMENT: Skip leading space characters and terminate the copied address buffer at the first space, leaving only the address portion. [field:obj:0x000000C8]
    // ASSIGNMENT: sub_587C20(address_buffer, byte_5C3F6C) searches the address buffer for the port separator; returns a pointer to the separator or null. [callee:0x00587C20, field:obj:0x000000C8, global:0x005C3F6C]
    // ASSIGNMENT: If the separator is found, set the object byte field at offset 198 to 1, marking the session as an active client/connect. [field:obj:0x000000C6]
    // CALL: DebugLogWrite(&dword_8AD25C, aNetcommActivat_0) logs that NetComm connect mode is being activated. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C642C]
    // ASSIGNMENT: If sub_587ECE(port_string) returns 0 (empty or non-numeric port), format the default port word_7D1004 as a string via StringFormatWithBufferOverflowCheck(v28, "%d", word_7D1004) and strcpy it into the port portion of the address buffer. [callee:0x00587ECE, callee:0x0058815F, global:0x007D1004]
    // CALL: DebugLogWrite(&dword_8AD25C, aAutojoinAddres) logs the auto-join address default-port substitution. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C63E8]
    // CALL: DebugLogWrite(&dword_8AD25C, aNewAddressStri) logs the new address string after the default port is appended. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C63C8]
    // CALL: DebugLogWrite(&dword_8AD25C, aNoPortSpecifie) logs that no port was specified in the connect argument. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C638C]
    // GUARD: If sub_566810(a2, aName_1) finds the player-name token, parse the player name. [callee:0x00566810, global:0x005C6384]
    // LOOP: Parse the player-name value: skip leading spaces; if the value is quoted, read until the closing quote, otherwise read until a space; copy at most 30 characters into v28 and NUL-terminate it. [source:raw]
    // ASSIGNMENT: If the parsed name buffer is non-empty, strcpy copies it into the object buffer at offset 284 (the player-name field). [field:this:0x00000000]
    // CALL: DebugLogWrite(&dword_8AD25C, aNetcommSetNetw) logs that the network/player name was set. [callee:0x004D7AA0, global:0x008AD25C, global:0x005C6360]
    // GUARD: If sub_566810(a2, aMaxplayers) finds the max-players token, parse the maximum player count. [callee:0x00566810, global:0x005C6350]
    // ASSIGNMENT: Skip leading spaces in the max-players value, convert it with sub_587ECE, and store the result in the object dword field at offset 428. [callee:0x00587ECE, field:obj:0x000001AC]
    // GUARD: Clamp the parsed max-players field to the range [2, 104]: values below 2 are raised to 2, values above 104 are lowered to 104. [field:obj:0x000001AC]
    // RETURN: Return result, the value left from the max-players parse (or null if the token was absent). [function:0x00463160]

    // Conservative worker pseudocode:
    //   // parse command-line tokens into the NetComm configuration object
    //   if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 6949))
    //       DebugLogWrite(&dword_8AD25C, aNetcommCheckin);
    //   if (v3 = find(a2, aPassword)) {
    //       copy_bounded(token_buffer, v3 + strlen(aPassword), 15); token_buffer[15] = 0;
    //       p = find_sep(token_buffer, asc_5C64D4); if (p) *p = 0;
    //       StringCopyToStructField(token_buffer);
    //   }
    //   if (!find(a2, aDedicated)) {
    //       if (find(a2, aHost)) {
    //           obj[197] = 1;
    //           if (v5 = find(a2, aGamename)) {
    //               copy_bounded(token_buffer, v5 + strlen(aGamename), 63); token_buffer[63] = 0;
    //               s = clean(token_buffer, asc_5C64D4);
    //               if (s && strlen(s)) strcpy(obj + 364, s);
    //           }
    //       } else if (v7 = find(a2, aConnect)) {
    //           copy_bounded(obj + 200, v7, 79); obj[279] = 0;
    //           cut_at_space(obj + 200);
    //           if (sep = find_sep(obj + 200, byte_5C3F6C)) {
    //               obj[198] = 1;
    //               if (!atoi(sep + 1)) {
    //                   StringFormatWithBufferOverflowCheck(token_buffer, "%d", word_7D1004);
    //                   strcpy(sep + 1, token_buffer);
    //               }
    //           } else { DebugLogWrite(&dword_8AD25C, aNoPortSpecifie); }
    //       }
    //   }
    //   if (v17 = find(a2, aName_1)) {
    //       parse_name(v17, token_buffer);
    //       if (strlen(token_buffer)) strcpy(obj + 284, token_buffer);
    //   }
    //   if (result = find(a2, aMaxplayers)) {
    //       obj[428] = atoi(result);
    //       clamp(obj[428], 2, 104);
    //   }
    //   return result;
    // UNRESOLVED: sub_566810 token-search return-value convention (pointer after the token) is inferred from usage, not confirmed.
    // UNRESOLVED: StringCopyToStructField (0x463710) writes the password into a struct field whose target offset is not visible in this function.
    // UNRESOLVED: Exact bytes/meaning of separator literals asc_5C64D4 and byte_5C3F6C are not confirmed from this function alone.
    // UNRESOLVED: word_7D1004 default-port source and the full address:port composition are unconfirmed.
    // UNRESOLVED: The object write targets at offsets 364 (game name) and 284 (player name) are not present in the packet field list.
    // UNRESOLVED: Packet field obj+0x117 has no visible read or write in this function's raw source; its role here is unknown.
    // UNRESOLVED: Global aD_1 at 0x005C3280 appears in the packet's global list but is not referenced by this function's raw source.
}
