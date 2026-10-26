// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0DB0
// Canonical corpus name: GameFilterDataLoader
// Owner: GameFilterSessionState [GUESS]
// Raw source: functions/GameFilterDataLoader_004c0db0.c

void GameFilterSessionState::LoadGameFilterData()
{
    // Game-filter and career-session data loader. Captures the driver count from dword_7D0A20, sets session status fields (0xB144 to 2, 0xB148 to 0), initializes the session data array at this+44908 and 103 stride-436 entries starting at this, resolves default directory strings from globals (dword_7CE64C / dword_7D0DCC with byte_5EA438 fallback), writes the vehicle-count/active fields 0xB110/0xB114/0xB118/0xB11C, dispatches the aGameFilter configuration, builds the AI opponent selection list, then fills per-driver entries (stride 436) with index and flag fields 0x1A4/0x1A8/0x1AC/0x1B0. Returns 0.
    // ASSIGNMENT: Capture the driver/vehicle count v1 from global dword_7D0A20. [global:0x007D0A20, source:raw]
    // ASSIGNMENT: Set session status at offset 0xB144 to 2 and current-race index at offset 0xB148 to 0. [field:this:0x0000B144, field:this:0x0000B148]
    // CALL: Initialize the main session data region at this+44908 via LapSessionDataArrayInitializer. [callee:0x004C07F0, source:raw]
    // LOOP: Loop 103 times over entries with a 436-byte stride starting at this, calling LapSessionDataArrayInitializer on each. [callee:0x004C07F0, source:raw]
    // CALL: Fill a local string buffer from byte_7CE498 via sub_4B0B20, then reallocate/copy it through StringCopyWithBufferRealloc. [global:0x007CE498, callee:0x004B0B20, callee:0x00566650]
    // ASSIGNMENT: Resolve the driver-name source string as dword_7CE64C when non-null else byte_5EA438, then copy it via StringCopyWithBufferRealloc. [global:0x007CE64C, global:0x005EA438, callee:0x00566650]
    // ASSIGNMENT: Write the session vehicle-count fields at offsets 0xB110 and 0xB114 from the captured count, zero the field at 0xB118, and set the active flag byte at 0xB11C to 1. [field:this:0x0000B110, field:this:0x0000B114, field:this:0x0000B118, field:this:0x0000B11C, global:0x007D0A20]
    // ASSIGNMENT: Resolve the default directory from dword_7D0DCC or byte_5EA438 fallback, then copy it via StringCopyWithBufferRealloc. [global:0x007D0DCC, global:0x005EA438, callee:0x00566650]
    // CALL: Pass word_5C32D8 through sub_5665B0. [global:0x005C32D8, callee:0x005665B0]
    // CALL: Dispatch the aGameFilter configuration via ConditionalDispatch_81f0 and wrap the result through sub_5665B0. [global:0x005C7130, callee:0x005681F0, callee:0x005665B0]
    // CALL: Zero the 4-int local selection buffer v15 via ZeroInit4Ints, then run AIOpponentSelection(v15, count, resolved string, byte_5EA438). [callee:0x004BF630, callee:0x004BF790, global:0x005EA438]
    // LOOP: For each of the count drivers: index the selected vehicle array entry via VehicleArrayIndexAccessor(v15, index), copy the entry name and fallback strings through StringCopyWithBufferRealloc, then write the per-entry fields at 0x1A4 and 0x1A8 (set to the index), 0x1AC (set to 1) and 0x1B0 (byte flag set to 1), advancing the record pointer by 436 bytes per entry. [callee:0x004BFCD0, callee:0x00566650, field:this:0x000001A4, field:this:0x000001A8, field:this:0x000001AC, field:this:0x000001B0]
    // CALL: Destroy the v15 selection list via LinkedListDestruction_f640. [callee:0x004BF640]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   char LoadGameFilterData() {
    //     int count = dword_7D0A20;
    //     *(DWORD*)(this+45380) = 2; *(DWORD*)(this+45384) = 0;
    //     LapSessionDataArrayInitializer(this+44908);
    //     for (int n = 103; n; --n, p += 436) LapSessionDataArrayInitializer(p);
    //     StringCopyWithBufferRealloc(sub_4B0B20(byte_7CE498, buf, 31));
    //     StringCopyWithBufferRealloc(dword_7CE64C ? dword_7CE64C : byte_5EA438);
    //     *(DWORD*)(this+45328) = count; *(DWORD*)(this+45332) = count;
    //     *(DWORD*)(this+45336) = 0; *(BYTE*)(this+45340) = 1;
    //     StringCopyWithBufferRealloc(dword_7D0DCC ? dword_7D0DCC : byte_5EA438);
    //     sub_5665B0(&word_5C32D8); sub_5665B0(ConditionalDispatch_81f0(aGameFilter));
    //     ZeroInit4Ints(v15); AIOpponentSelection(v15, count, dword_7CE64C?dword_7CE64C:byte_5EA438, byte_5EA438);
    //     for (int i = 0; i < count; ++i, p += 436) {
    //       VehicleArrayIndexAccessor(v15, i); StringCopyWithBufferRealloc(...);
    //       *(DWORD*)(p+404) = i; *(DWORD*)(p+408) = i; *(DWORD*)(p+412) = 1; *(BYTE*)(p+416) = 1;
    //     }
    //     LinkedListDestruction_f640(v15);
    //     return 0;
    //   }
    // UNRESOLVED: Callee FreeWrapper_7bcf (0x00587BCF) is listed in the packet callee table but does not appear in the raw source body; role unconfirmed.
    // UNRESOLVED: Global dword_8AD3B4 is listed in the packet globals but not referenced in the raw source body; purpose unconfirmed.
    // UNRESOLVED: In the 103-entry initializer loop the first iteration uses `this` itself and the loop pointer v5 is not initialized in the raw source; this is a Hex-Rays artifact, so the exact entry range (this .. this+102*436) is DERIVED.
    // UNRESOLVED: The two stride-436 iteration paths (103-entry session array and per-driver record fill) overlap the same address range; the record layout and whether they address the same objects is unresolved.
}
