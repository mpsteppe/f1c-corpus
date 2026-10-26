// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BFD90
// Canonical corpus name: AIDriverCountSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDriverCountSetup_004bfd90.c

void UnknownObject::AIDriverCountSetup()
{
    // Configures the AI opponent count and per-driver nationality/team assignment at dynamic-manager init. Builds a driver-name path from the game filter path (falling back to the default directory), applies a championship single-vehicle override or a deterministic random count, selects opponents via AIOpponentSelection, and walks the vehicle array assigning nationality and team id per slot. Always ends with the single-player fallback: look up the vehicle by name, load nationality and team 0, then perform the final session transition.
    // GUARD: Skip the opponent setup block when the vehicle count dword_5C329C is not greater than 0; the single-player fallback at LABEL_21 still runs. [global:0x005C329C, source:raw]
    // CALL: Zero-initialize the local 4-int list v13 with ZeroInit4Ints before use. [callee:0x004BF630, source:raw]
    // GUARD: Build the driver-name path into v14: when ScoringGateCheck is active, copy up to 255 bytes from dword_7CE64C (falling back to byte_5EA438) with sub_587DD0 and NUL-terminate; otherwise copy the byte_5EA438 string directly. [callee:0x0042BC10, callee:0x00587DD0, global:0x007CE64C, global:0x005EA438, source:raw]
    // GUARD: In championship mode (dword_7D0410 == 1) the single-vehicle override flag dword_7D00C8 forces the count dword_5C329C to 1 before rebuilding the active vehicle pointer array. [global:0x007D0410, global:0x007D00C8, global:0x005C329C, callee:0x0042BC80, source:raw]
    // ASSIGNMENT: Otherwise the AI count is randomized deterministically: dword_5C329C = DeterministicHashPseudoRandomGenerator(&dword_8AAE70) % 3 + 3, then the active vehicle pointer array is rebuilt. [callee:0x004B3C60, global:0x008AAE70, global:0x005C329C, callee:0x0042BC80, source:raw]
    // CALCULATION: The opponent list target count v4 is dword_5C329C minus 1 when ScoringGateCheck is active, else dword_5C329C. [callee:0x0042BC10, global:0x005C329C, source:raw]
    // CALL: AIOpponentSelection(v13, v4, v14, a1) fills the opponent list; per-driver setup runs only when its result equals v4. [callee:0x004BF790, source:raw]
    // LOOP: For each selected opponent slot, transition the session (SessionStateTransition(1, 0)), fetch the entry with IndexedListLookup, load nationality with NationalityDriverInfoLoader, and assign a team with TeamIDSetter; the vehicle-array walk pointer advances by the 18624-byte stride from unk_5EC6D8. [callee:0x004EF5A0, callee:0x004BFD40, callee:0x004C78F0, callee:0x004C6960, global:0x005EC6D8, source:raw]
    // CALL: Release the local list v13 with LinkedListDestruction_f640 before entering the single-player fallback path. [callee:0x004BF640, source:raw]
    // CALL: The single-player fallback looks up the vehicle by name (VehicleLookupByName) using dword_7CE64C or byte_5EA438, loads nationality from dword_8AC38C, and assigns team 0 via TeamIDSetter. [callee:0x004C3F80, global:0x007CE64C, global:0x005EA438, callee:0x004C78F0, global:0x008AC38C, callee:0x004C6960, source:raw]
    // STATE_TRANSITION: Final session transition is SessionStateTransition(0, 0) when ScoringGateCheck is active, otherwise SessionStateTransition(1, 0); the function then returns 0. [callee:0x004EF5A0, callee:0x0042BC10, source:raw]
    // CALL: Invoked once by DynMan_Init (0042C1A0) during dynamic-manager initialization. [caller:0x0042C1A0, source:raw]
    // UNKNOWN: The legacy ABI label 'AI_Driver_Count_Setup' supports the proposed name but no owner or class is established for this function. [abi:lead, function:0x004BFD90, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_4BFD90(const char *a1) {
    //     char path[256];
    //     int list[4];
    //     if (dword_5C329C > 0) {
    //       ZeroInit4Ints(list);
    //       if (ScoringGateCheck()) {
    //         const char *src = dword_7CE64C ? dword_7CE64C : byte_5EA438;
    //         sub_587DD0(path, src, 255); path[255] = 0;
    //       } else strcpy(path, byte_5EA438);
    //       if (dword_7D0410 == 1) {
    //         if (dword_7D00C8) {
    //           dword_5C329C = 1; BuildActiveVehiclePointerArray(); goto cleanup;
    //         }
    //         dword_5C329C = DeterministicHashPseudoRandomGenerator(&dword_8AAE70) % 3 + 3;
    //         BuildActiveVehiclePointerArray();
    //       }
    //       count = ScoringGateCheck() ? dword_5C329C - 1 : dword_5C329C;
    //       if (AIOpponentSelection(list, count, path, a1) == count) {
    //         base = ScoringGateCheck();
    //         for (i = base; i < base + count; ++i) {
    //           SessionStateTransition(1, 0);
    //           NationalityDriverInfoLoader(IndexedListLookup(list, i - base));
    //           TeamIDSetter(i);
    //         }
    //       }
    //     cleanup:
    //       LinkedListDestruction_f640(list);
    //     }
    //     VehicleLookupByName(dword_7CE64C ? dword_7CE64C : byte_5EA438);
    //     NationalityDriverInfoLoader(dword_8AC38C);
    //     TeamIDSetter(0);
    //     SessionStateTransition(ScoringGateCheck() ? 0 : 1, 0);
    //     return 0;
    //   }
    // UNRESOLVED: unk_5EC6D0, unk_5EC6E4 and unk_8AC388 are flagged as read by packet facts but never appear in the raw decompiled source; the skeleton's roles (vehicle array base, per-vehicle field, vehicle file path buffer) are unverifiable from this packet.
    // UNRESOLVED: The 18624-byte stride identifies the vehicle array element size but the per-slot field touched by TeamIDSetter is not visible here.
    // UNRESOLVED: The relationship between the dword_8AC38C nationality parameter and the per-slot IndexedListLookup entries is not established by this packet.
}
