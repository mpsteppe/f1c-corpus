// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00463F70
// Canonical corpus name: SessionTypeSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionTypeSetter_00463f70.c

void UnknownObject::SessionTypeSetter()
{
    // Initializes the game session type and network configuration from stored state. Reads the session-type discriminant at obj+0x3FC4 and either delegates early to sub_45ECD0 (state zero) or selects online mode (state 1/2: writes dword_7C56A0 = 3) versus offline mode (writes dword_7C56A0 = 2). When not already configured (byte_7CE260 clear) it builds network communication strings from the session name and path defaults. Marks the session active (obj+0x28 = 1), sets session-config bytes (obj+0x3FD8 = 8, obj+0x3FD9 = 0), maps dword_7D0E50 through a jump table to a clamped size value, copies online-mode configuration, calls CollisionInvDistanceStore, clears obj+0x30, initializes flags via GlobalFlagBasedStateSetter, and returns sub_45ECD0. Called from Game_Init (0042d6b0).
    // GUARD: Read the session-type discriminant at obj+0x3FC4 through the base pointer at this+0; if zero, delegate to sub_45ECD0 and return its result. [field:this:0x00000000, field:obj:0x00003FC4, callee:0x0045ECD0, source:raw]
    // ASSIGNMENT: Select online vs offline mode: state 1 or 2 sets the local flag v14 = 1 and writes dword_7C56A0 = 3; otherwise v14 = 0 and dword_7C56A0 = 2. [global:0x007C56A0, source:raw]
    // GUARD: Only when byte_7CE260 is clear, build the network-communication string block. [global:0x007CE260, source:raw]
    // CALL: Obtain a configuration value via ThunkToFUN00461480 (v16 = 2), then copy the session name from *this+71, or from byte_5EA438 via sub_4B0B20 when empty, into the name buffer using sub_587DD0. [callee:0x00461470, callee:0x00587DD0, callee:0x004B0B20, global:0x005EA438, source:raw]
    // CALL: Copy the communication string from dword_7CE684 (falling back to byte_5EA438) via sub_587DD0; then, if NameComparisonAt0x1b4 succeeds, derive a path suffix from dword_7CFE0C up to the last backslash and copy it into the final string buffer. [callee:0x00587DD0, callee:0x004B0390, global:0x007CE684, global:0x005EA438, global:0x007CFE0C, source:raw]
    // CALL: Finalize the configuration block via ShortComputation_23b0 and set the float at obj+0x37C (float index 223 of the session object) to 5.0. [callee:0x004623B0, field:obj:0x0000037C, source:raw]
    // ASSIGNMENT: Mark the session active: set obj+0x28 = 1, obj+0x3FD8 = 8 and obj+0x3FD9 = 0. [field:obj:0x00000028, field:obj:0x00003FD8, field:obj:0x00003FD9, source:raw]
    // CALCULATION: Dispatch on dword_7D0E50 (jump table jpt_464127) mapping 1 to 8, 2 to 12, 3 to 14, 4 to 32 and default to 6; clamp the result into the bounds [dword_7D0EA0, dword_7D0EA4] and store it in dword_7D0E98. [global:0x00464278, global:0x007D0E50, global:0x007D0E98, global:0x007D0EA0, global:0x007D0EA4, source:raw]
    // GUARD: Online branch (v14 set): invoke SingleCallWrapper with dword_7D0E50 and WheelSpeedConversionWithZeroGuard with dword_7D10EC and -1; copy the strings at dword_7D0E88 and dword_7D0E90 via StringCopyWithBufferRealloc; then store configuration values dword_7D0EC0 = dword_7D0E9C, dword_7D0EC4 = dword_7D0EA0, dword_7D0EBC = dword_7D0E98 and dword_7D0EC8 = dword_7D0EA4. [callee:0x00465150, global:0x007D0E50, callee:0x00465160, global:0x007D10EC, global:0x007D0E88, global:0x007D0E90, callee:0x00566650, global:0x007D0E9C, global:0x007D0EA0, global:0x007D0E98, global:0x007D0EBC, global:0x007D0EC0, global:0x007D0EC4, global:0x007D0EC8, global:0x007D0EA4, source:raw]
    // CALCULATION: Offline branch keeps v10 = dword_7D0EBC; both branches clamp the effective value to at least 4, choose v15 = max(v7, 4) when v10 >= v11 else v15 = v10, convert v15 to float, and pass it to CollisionInvDistanceStore on the session object. [global:0x007D0EBC, callee:0x0045F2A0, source:raw]
    // CALL: Invoke SingleFunctionCallWrapper_a750 with dword_7D0EE0, clear obj+0x30 = 0, initialize session flags via GlobalFlagBasedStateSetter on a sub-region of the session object, and return the result of sub_45ECD0(*this). [callee:0x0057A750, global:0x007D0EE0, field:obj:0x00000030, callee:0x0045D490, callee:0x0045ECD0, source:raw]
    // CALL: Session-startup entry: invoked from Game_Init (0042d6b0). [caller:0x0042D6B0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_463F70(float** this) {
    //     int mode = *((int*)*this + 4081);
    //     if (!mode) return sub_45ECD0(*this);
    //     int online = (mode == 1 || mode == 2) ? 1 : 0;
    //     dword_7C56A0 = online ? 3 : 2;
    //     if (!byte_7CE260) {
    //       buildNetworkStrings();  // ThunkToFUN00461480, sub_587DD0 copies, sub_4B0B20 default
    //       ShortComputation_23b0(&v16);
    //       (*this)[223] = 5.0f;
    //     }
    //     *((char*)*this + 40) = 1;
    //     *((char*)*this + 16344) = 8;
    //     *((char*)*this + 16345) = 0;
    //     int v7 = mapSessionOption(dword_7D0E50);  // jpt_464127: 1->8, 2->12, 3->14, 4->32, default->6
    //     clamp v7 into [dword_7D0EA0, dword_7D0EA4];
    //     dword_7D0E98 = v7;
    //     if (online) {
    //       SingleCallWrapper(dword_7D0E50);
    //       WheelSpeedConversionWithZeroGuard(dword_7D10EC, -1);
    //       StringCopyWithBufferRealloc(dword_7D0E88 ? dword_7D0E88 : byte_5EA438);
    //       StringCopyWithBufferRealloc(dword_7D0E90 ? dword_7D0E90 : byte_5EA438);
    //       dword_7D0EC0 = dword_7D0E9C; dword_7D0EC4 = dword_7D0EA0;
    //       dword_7D0EBC = dword_7D0E98; dword_7D0EC8 = dword_7D0EA4;
    //       v10 = dword_7D0E98;
    //     } else {
    //       v10 = dword_7D0EBC;
    //     }
    //     int v11 = v7 <= 4 ? 4 : v7;
    //     int v15 = (v10 >= v11) ? v11 : v10;
    //     CollisionInvDistanceStore(*this, (float)v15);
    //     SingleFunctionCallWrapper_a750(dword_7D0EE0);
    //     *((char*)*this + 48) = 0;
    //     GlobalFlagBasedStateSetter((int)(*this + 28132));
    //     return sub_45ECD0(*this);
    //   }
    // UNRESOLVED: Globals dword_59F0A8, dword_7CD2A8, byte_7CE498, unk_7D0EAC and unk_7D0EB4 are extracted as reads but do not appear in the decompiled body; roles unknown.
    // UNRESOLVED: The GlobalFlagBasedStateSetter target region (*this + 28132) falls outside the declared field offsets; its byte offset is not mapped to a named field.
    // UNRESOLVED: Semantic meaning of the dword_7D0E50 dispatch values (session/network option selector) is unconfirmed.
}
