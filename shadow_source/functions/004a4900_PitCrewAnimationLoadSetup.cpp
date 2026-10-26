// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4900
// Canonical corpus name: sub_4A4900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A4900_004a4900.c

void UnknownObject::PitCrewAnimationLoadSetup()
{
    // Loads pit crew animation MAS files for the current vehicle/track context. Runs only when the scoring gate dword_8AB6E4 is not 2 and either the target vehicle is the player vehicle (dword_7C54E8) or the detail level dword_7CF884 is >= 3. Builds directory-relative file paths from byte_5EA438 with per-track subdirectory names, allocates the pit crew 10sec, normal and (player-only) pit director animation objects, stores them in this[4], this[3] and this[5], then frees temporary buffers and returns the arithmetic comparison of the argument struct.
    // CALL: Call UIComponentCleanup() first. [callee:0x004A4DB0]
    // GUARD: Exit early when dword_8AB6E4 == 2. [global:0x008AB6E4]
    // ASSIGNMENT: Record result = (*this == dword_7C54E8) into v33, flagging whether the target vehicle is the player vehicle. [field:this:0x00000000, global:0x007C54E8]
    // GUARD: Run the load only when *this == dword_7C54E8 or dword_7CF884 >= 3. [field:this:0x00000000, global:0x007C54E8, global:0x007CF884]
    // CALL: Call sub_4A1F60(v44) to initialize the argument struct, then sub_4A51C0(a2, v44) to populate it from a2. [callee:0x004A1F60, callee:0x004A51C0]
    // CALL: Allocate a 256-byte buffer v38 via OperatorNewNhMallocWrapper, zero it, then call StringCopyWithBufferRealloc on (*this + 18196) to copy the current path. [callee:0x00587C03, callee:0x00566650, field:this:0x00000000]
    // CALCULATION: Compute v5 = strlen(byte_5EA438) + 1 as the length of the working path string. [global:0x005EA438]
    // LOOP: Back-scan byte_5EA438 from its end for the path separator byte 92 ('\'), truncate the string at that byte, and fall back to the whole string when no separator is found. [global:0x005EA438]
    // CALL: Call StringRegistry(v4) to register the truncated directory path. [callee:0x0053C800, global:0x005EA438]
    // CALL: Allocate a 256-byte buffer v40, zero it, and StringCopyWithBufferRealloc the value of dword_5EC3D8, falling back to byte_5EA438 when it is null. [callee:0x00587C03, callee:0x00566650, global:0x005EC3D8, global:0x005EA438]
    // CALL: Call sub_5665B0 on the dword_5EC420 path (or byte_5EA438 fallback) and on the literal aPits, registering the pits directory. [callee:0x005665B0, global:0x005EC420, global:0x005EA438, global:0x005CD5E4]
    // CALL: Call StringRegistry on the v40 buffer (or byte_5EA438 fallback). [callee:0x0053C800, global:0x005EA438]
    // CALL: Call sub_53CBC0(&v37, aTeamMas) and sub_53CBC0(&v36, aPitsMas) to assemble the team and pits MAS file names. [callee:0x0053CBC0, global:0x005CD5D8, global:0x005CD5CC]
    // CALL: Call StringCopyWithBufferRealloc on dword_5EC3D8 (or fallback), sub_5665B0 on the dword_5EC428 path (or fallback), and sub_5665B0(aCdbMas) to build the cdb MAS name. [callee:0x00566650, callee:0x005665B0, global:0x005EC3D8, global:0x005EC428, global:0x005CD5C4, global:0x005EA438]
    // CALL: Call sub_53CBC0(&v34, v38-or-fallback) to complete the cdb path. [callee:0x0053CBC0, global:0x005EA438]
    // CALL: Call StringCopyWithBufferRealloc on dword_5EC3D8 (or fallback), sub_5665B0 on the dword_5EC428 path (or fallback), and sub_5665B0(aCmapsMas) to build the cmaps MAS name. [callee:0x00566650, callee:0x005665B0, global:0x005EC3D8, global:0x005EC428, global:0x005CCEB0, global:0x005EA438]
    // CALL: Call sub_53CBC0(&v35, v38-or-fallback) to complete the cmaps path. [callee:0x0053CBC0, global:0x005EA438]
    // CALL: Call StringCopyWithBufferRealloc on dword_5EC3D8 (or fallback), sub_5665B0 on the dword_5EC420 path (or fallback), and sub_5665B0(aPits10secPitcr) to build the 10sec pits MAS name. [callee:0x00566650, callee:0x005665B0, global:0x005EC3D8, global:0x005EC420, global:0x005CD5AC, global:0x005EA438]
    // CALL: Call StringFormatWithBufferOverflowCheck(v45, aPitcrew10sec02, *(*this + 18580)) to format the 'PITCREW10SEC%02d' file name from the car number field. [callee:0x0058815F, global:0x005CD598, field:obj:0x00004894]
    // CALL: Allocate a 24-byte object, initialize it with StructInitCall, store it in this[4], and call PITANIMSMASAnimationFileLoader(this[4], v38-or-fallback, v44, v45) to load the 10sec animation. [callee:0x00587C03, callee:0x004A2980, field:this:0x00000010, callee:0x004A3220, global:0x005EA438]
    // CALL: Call StringCopyWithBufferRealloc on dword_5EC3D8 (or fallback), sub_5665B0 on the dword_5EC420 path (or fallback), and - selected by byte_5EA3EC - sub_5665B0(aPitsLeftPitcre) when set else sub_5665B0(aPitsNormalPitc) for the normal pits MAS name. [callee:0x00566650, callee:0x005665B0, global:0x005EC3D8, global:0x005EC420, global:0x005EA3EC, global:0x005CD580, global:0x005CD568, global:0x005EA438]
    // CALL: Call StringFormatWithBufferOverflowCheck(v45, aPitcrewnormal0, *(*this + 18580)) to format the 'PITCREWNORMAL%02d' file name. [callee:0x0058815F, global:0x005CD554, field:obj:0x00004894]
    // CALL: Allocate a 24-byte object, initialize it with StructInitCall, store it in this[3], and call PITANIMSMASAnimationFileLoader(this[3], v38-or-fallback, v44, v45) to load the normal pit crew animation. [callee:0x00587C03, callee:0x004A2980, field:this:0x0000000C, callee:0x004A3220, global:0x005EA438]
    // GUARD: Only for the player vehicle (v33 set) additionally load the pit director animation. [source:raw]
    // CALL: Format 'PITDIRECTOR%02d' with StringFormatWithBufferOverflowCheck, allocate a 136-byte object, initialize fields and call sub_4A2220 then sub_4A3B30 on it, store it in this[5], and call PitCrewAnimationMASSetup(this[5], v45). [callee:0x0058815F, global:0x005CD544, callee:0x00587C03, callee:0x004A2220, callee:0x004A3B30, field:this:0x00000014, callee:0x004A3910]
    // CALL: Remove the temporary file-name structs v34, v35, v36 and v37 via PhysicsObjectLinkedListRemoval when each is non-null. [callee:0x0053CE40]
    // CALL: Call StringMatchWithFlagSet on the v40 buffer (or fallback) and on the v42 buffer (or fallback). [callee:0x0053C900, global:0x005EA438]
    // CALL: Free the temporary buffers v40, v42 and v38 via FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return the result of ArithmeticComparison_1f80(v44). [callee:0x004A1F80]
    // RETURN: Return the previously recorded result on the early-exit paths. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned __int8 sub_4A4900(_DWORD *this, int a2) {
    //     result = UIComponentCleanup();
    //     if (dword_8AB6E4 == 2) return result;
    //     bool isPlayer = (*this == dword_7C54E8);
    //     if (isPlayer || dword_7CF884 >= 3) {
    //       sub_4A1F60(v44); sub_4A51C0(a2, v44);
    //       v38 = malloc(256); *v38 = 0; StringCopyWithBufferRealloc(*this + 18196);
    //       len = strlen(byte_5EA438) + 1;
    //       for (p = &byte_5EA438[len - 2]; p > byte_5EA438 && *p != '\\'; --p) {}
    //       *p = 0; StringRegistry(byte_5EA438);
    //       v40 = malloc(256); *v40 = 0; StringCopyWithBufferRealloc(dword_5EC3D8 ? dword_5EC3D8 : byte_5EA438);
    //       sub_5665B0(dword_5EC420 ? dword_5EC420 : byte_5EA438); sub_5665B0(aPits); StringRegistry(v40 ? v40 : byte_5EA438);
    //       sub_53CBC0(&v37, aTeamMas); sub_53CBC0(&v36, aPitsMas);
    //       ... (build cdb / cmaps / 10sec / normal path names via sub_53CBC0 + sub_5665B0) ...
    //       StringFormatWithBufferOverflowCheck(v45, "PITCREW10SEC%02d", *(*this + 18580));
    //       this[4] = StructInitCall(malloc(24));
    //       PITANIMSMASAnimationFileLoader(this[4], v38 ? v38 : byte_5EA438, v44, v45);
    //       StringFormatWithBufferOverflowCheck(v45, "PITCREWNORMAL%02d", *(*this + 18580));
    //       this[3] = StructInitCall(malloc(24));
    //       PITANIMSMASAnimationFileLoader(this[3], v38 ? v38 : byte_5EA438, v44, v45);
    //       if (isPlayer) {
    //         StringFormatWithBufferOverflowCheck(v45, "PITDIRECTOR%02d", *(*this + 18580));
    //         this[5] = allocate_and_init_136();
    //         PitCrewAnimationMASSetup(this[5], v45);
    //       }
    //       if (v34) PhysicsObjectLinkedListRemoval(v34);
    //       if (v35) PhysicsObjectLinkedListRemoval(v35);
    //       if (v36) PhysicsObjectLinkedListRemoval(v36);
    //       if (v37) PhysicsObjectLinkedListRemoval(v37);
    //       StringMatchWithFlagSet(v40 ? v40 : byte_5EA438);
    //       StringMatchWithFlagSet(v42 ? v42 : byte_5EA438);
    //       if (v40) FreeWrapper_7bcf(v40);
    //       if (v42) FreeWrapper_7bcf(v42);
    //       if (v38) FreeWrapper_7bcf(v38);
    //       return ArithmeticComparison_1f80(v44);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Global dword_8AFE64 is referenced per the IDB but does not appear in the decompiled source text; its role here is unknown.
    // UNRESOLVED: The exact semantics of sub_4A1F60, sub_4A51C0 and ArithmeticComparison_1f80 (argument struct v44) are not resolved.
    // UNRESOLVED: Owner class is unknown; name PitCrewAnimationLoadSetup is DERIVED from existing analysis.
}
