// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC700
// Canonical corpus name: StringNameMatching
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringNameMatching_004fc700.c

void UnknownObject::MatchAndUpdateCloudSceneNames()
{
    // Matches two packed name strings from an input packet against stored cloud-scene name buffers on the object; when the names differ it copies both names into the object buffers, then either triggers cloud texture setup (sub_4FC550) or stores a session-type code at this+0x44. When the names already match it refreshes the stored type code unless it is -1. Execution is gated by a multiplayer flag bit and a scoring-gate packed-flag read.
    // GUARD: Match/update path runs only when bit0 of dword_7C56A0 is clear OR the scoring-gate condition holds (dword_8AB6E4 equals 2 and PackedFlagRead_9a00 of dword_8AB6EC returns 0). [global:0x007C56A0, global:0x008AB6E4, global:0x008AB6EC, callee:0x004B9A00, caller:0x004B3400]
    // CALCULATION: Compute input string pointers from packet a2: first name at a2+8, second name starting right after its NUL, and extract the type code v12 = byte(a2+3) & 7. [function:0x004FC700, source:raw]
    // GUARD: Names differ when strcmp of the stored first-name buffer (this+0x50) with the input first name is non-zero OR strcmp of the stored second-name buffer (this+0x84) with the input second name is non-zero. [field:this:0x0000006F, field:this:0x000000A3]
    // ASSIGNMENT: Copy 31 bytes of the input first name into the first buffer (this+0x50) via sub_587DD0 and write the NUL terminator at this+0x6F. [callee:0x00587DD0, field:this:0x0000006F]
    // ASSIGNMENT: Copy 31 bytes of the input second name into the second buffer (this+0x84) via sub_587DD0 and write the NUL terminator at this+0xA3. [callee:0x00587DD0, field:this:0x000000A3]
    // STATE_TRANSITION: After updating names: when the scoring-gate flag v10 is set or the extracted type code equals dword_7C56A4 (session type), call sub_4FC550 to load cloud textures; otherwise store the extracted type code into this+0x44. [callee:0x004FC550, global:0x007C56A4, field:this:0x00000044]
    // ASSIGNMENT: When names already match and the stored type code at this+0x44 is not -1 (guard), refresh it with the extracted type code. [field:this:0x00000044, guard:0]
    // RETURN: Return the last computed status value (effectively void semantics). [function:0x004FC700]

    // Conservative worker pseudocode:
    //   session_flag = dword_7C56A0 & 1;
    //   gate_flag = (dword_8AB6E4 == 2) && !PackedFlagRead_9a00(&dword_8AB6EC);
    //   if (!session_flag || gate_flag) {
    //       first = (const char*)(packet + 8);
    //       second = first + strlen(first) + 1;
    //       type_code = *(packet + 3) & 7;
    //       if (strcmp(this + 0x50, first) || strcmp(this + 0x84, second)) {
    //           sub_587DD0(this + 0x50, first, 31);
    //           *(this + 0x6F) = 0;
    //           sub_587DD0(this + 0x84, second, 31);
    //           *(this + 0xA3) = 0;
    //           if (gate_flag || type_code == dword_7C56A4)
    //               sub_4FC550(this, 0);
    //           else
    //               *(this + 0x44) = type_code;
    //       } else if (*(this + 0x44) != -1) {
    //           *(this + 0x44) = type_code;
    //       }
    //   }
    // UNRESOLVED: Exact meaning of bit0 of dword_7C56A0 (multiplayer flag) and of the packed flag read via dword_8AB6EC is not established.
    // UNRESOLVED: Semantics of the extracted type code (byte(a2+3) & 7) and its relation to dword_7C56A4 are unknown.
    // UNRESOLVED: sub_4FC550 confirmed as cloud-texture setup only from existing analysis, not from this function alone.
}
