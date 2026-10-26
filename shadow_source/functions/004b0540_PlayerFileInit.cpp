// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B0540
// Canonical corpus name: PlayerFileInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlayerFileInit_004b0540.c

void UnknownObject::PlayerFileInit()
{
    // Loads and initializes a player file. Opens an audio stream on the object's file path (this+20), marks the file read-only (this+0x114) when the read-only attribute is set, then on success runs the full initialization chain: mode-variant init (sub_4AE750), linked-list walk, normalization of this+0x1F00 to a truth value, clamping of this+0x2F8C to 33/34 by two condition flags, scene-data parse, a gate-adjusted count stored to dword_5C329C (forced to 0 in game mode 5), active-vehicle array build, 5-step init, autoload entry loading, and a path-scoped computation into dword_5EA5E8. Returns 0 on success and -1 when the audio stream cannot be opened. Dispatched from StringCopyFileCheckDispatch (004b04e0) and PlayerFile_Setup (004b1870).
    // ASSIGNMENT: Initialize local path buffer: v10[0] = byte_5EA438[0]; zero-fill the remaining 0x1FC bytes; v11 = 0; v12 = 0 [global:0x005EA438, source:raw]
    // CALL: ZeroInitSmallStruct(v9): zero-initialize the 28-byte local scratch struct [callee:0x005668B0, source:raw]
    // GUARD: If GetFileAttributesA(path at this+20) has bit 0 (FILE_ATTRIBUTE_READONLY) set, the file is treated as read-only [global:0x0059E0D8, source:raw]
    // ASSIGNMENT: Set this+0x114 = 1 (read-only marker) when the attribute check passed [field:this:0x00000114, global:0x0059E0D8, source:raw]
    // CALL: sub_568620(512): acquire a 512-unit resource/stream slot before opening [callee:0x00568620, source:raw]
    // CALL: AudioStreamOpen(v10, 1): open an audio stream into the local path buffer with mode 1 [callee:0x00566B20, source:raw]
    // GUARD: Branch on the AudioStreamOpen result: nonzero proceeds with the full player-file load; zero takes the failure cleanup path [callee:0x00566B20, source:raw]
    // CALL: sub_568910(512): release/balance the previously acquired 512-unit slot [callee:0x00568910, source:raw]
    // CALL: strcpy(this+20, v10): copy the opened stream path back into the object [source:raw]
    // GUARD: Mode selection on byte_7CB710 bit 0: set selects variant 2, clear selects variant 1 [global:0x007CB710, source:raw]
    // CALL: sub_4AE750(this, 2): init variant when byte_7CB710 bit 0 is set [callee:0x004AE750, global:0x007CB710, source:raw]
    // CALL: sub_4AE750(this, 1): init variant when byte_7CB710 bit 0 is clear [callee:0x004AE750, source:raw]
    // CALL: LinkedListWalker(this, v9): walk this's linked list, collecting results through v9 [callee:0x004A1D10, source:raw]
    // ASSIGNMENT: Normalize this+0x1F00 to its truth value: this+0x1F00 = (this+0x1F00) > 0 [field:this:0x00001F00, guard:0, source:raw]
    // ASSIGNMENT: Load v4 = byte at this+0x2F08 (first condition flag) [field:this:0x00002F08, source:raw]
    // GUARD: If v4 (this+0x2F08) is set and this+0x2F8C < 34, clamp the value at this+0x2F8C to a floor of 34 [field:this:0x00002F08, field:this:0x00002F8C, guard:2, source:raw]
    // ASSIGNMENT: this+0x2F8C = 34 (clamp floor for the first condition flag) [field:this:0x00002F8C, field:this:0x00002F08, guard:2, source:raw]
    // GUARD: If the this+0x2ED8 flag is set and this+0x2F8C < 33, clamp the value at this+0x2F8C to a floor of 33 [field:this:0x00002ED8, field:this:0x00002F8C, guard:3, source:raw]
    // ASSIGNMENT: this+0x2F8C = 33 (clamp floor for the second condition flag) [field:this:0x00002ED8, field:this:0x00002F8C, guard:3, source:raw]
    // ASSIGNMENT: v5 = scene data path at this+0x138; fall back to byte_5EA438 when null [field:this:0x00000138, global:0x005EA438, source:raw]
    // CALL: SceneDataParser(v5): parse scene data from the selected path [callee:0x004C5690, field:this:0x00000138, global:0x005EA438, source:raw]
    // CALCULATION: v6 = dword at byte offset this + 36 * (this+0x1F78) + 9464 (game-mode-indexed table lookup) [field:this:0x00001F78, source:raw]
    // CALL: ScoringGateCheck(): evaluate the scoring gate [callee:0x0042BC10, source:raw]
    // CALCULATION: v7 = v6 + ScoringGateCheck() (gate-adjusted value) [callee:0x0042BC10, field:this:0x00001F78, source:raw]
    // GUARD: Clamp v7: floor at 1 when v7 < 1, cap at 104 when v7 > 104 [callee:0x0042BC10, source:raw]
    // ASSIGNMENT: v7 = 1 when the gate-adjusted value fell below the floor [callee:0x0042BC10, source:raw]
    // ASSIGNMENT: v7 = 104 when the gate-adjusted value exceeded the cap [callee:0x0042BC10, source:raw]
    // GUARD: If this+0x1F78 == 5 (test/special game mode) force v7 = 0 [field:this:0x00001F78, guard:1, source:raw]
    // ASSIGNMENT: dword_5C329C = v7 (store the resolved count/value globally) [global:0x005C329C, field:this:0x00001F78, source:raw]
    // CALL: BuildActiveVehiclePointerArray(): rebuild the active vehicle pointer array [callee:0x0042BC80, source:raw]
    // CALL: F_5StepInit(this): run the 5-step initialization pass on the object [callee:0x004B0720, source:raw]
    // CALL: sub_4B0EF0(this+0x1F78): mode-specific follow-up initialization [callee:0x004B0EF0, field:this:0x00001F78, source:raw]
    // CALL: AutoLoadEntryListLoader(&dword_7C73E8): load the autoload entry list [callee:0x00432E70, global:0x007C73E8, source:raw]
    // ASSIGNMENT: v8 = path at this+0x1B4; fall back to byte_5EA438 when null [field:this:0x000001B4, global:0x005EA438, source:raw]
    // CALL: ShortComputation_5730(&dword_5EA5E8, v8): compute over the selected path into global dword_5EA5E8 [callee:0x00415730, global:0x005EA5E8, field:this:0x000001B4, global:0x005EA438, source:raw]
    // CALL: SubCallWithConditionalFieldFree(v9): teardown of the scratch struct on the success path [callee:0x005668D0, source:raw]
    // RETURN: Return 0 on successful player-file load [source:raw]
    // CALL: SubCallWithConditionalFieldFree(v9): teardown of the scratch struct on the failure path [callee:0x005668D0, source:raw]
    // RETURN: Return -1 when AudioStreamOpen failed [source:raw]
    // CALL: Entry points: invoked by StringCopyFileCheckDispatch (004b04e0) and PlayerFile_Setup (004b1870) [caller:0x004B04E0, caller:0x004B1870, source:raw]

    // Conservative worker pseudocode:
    //   v10[0] = byte_5EA438[0];
    //   memset(&v10[1], 0, 0x1FC); v11 = 0; v12 = 0;
    //   ZeroInitSmallStruct(v9);
    //   if ((GetFileAttributesA(this + 20) & 1) != 0) this->0x114 = 1;
    //   sub_568620(512);
    //   if (AudioStreamOpen(v10, 1)) {
    //     sub_568910(512);
    //     strcpy(this + 20, v10);
    //     sub_4AE750(this, (byte_7CB710 & 1) ? 2 : 1);
    //     LinkedListWalker(this, v9);
    //     this->0x1F00 = this->0x1F00 > 0;
    //     if (this->0x2F08 && this->0x2F8C < 34) this->0x2F8C = 34;
    //     if (this->0x2ED8 && this->0x2F8C < 33) this->0x2F8C = 33;
    //     v5 = this->0x138 ? this->0x138 : byte_5EA438;
    //     SceneDataParser(v5);
    //     v6 = *(int*)(this + 36 * this->0x1F78 + 9464);
    //     v7 = v6 + ScoringGateCheck();
    //     if (v7 < 1) v7 = 1; else if (v7 > 104) v7 = 104;
    //     if (this->0x1F78 == 5) v7 = 0;
    //     dword_5C329C = v7;
    //     BuildActiveVehiclePointerArray();
    //     F_5StepInit(this);
    //     sub_4B0EF0(this->0x1F78);
    //     AutoLoadEntryListLoader(&dword_7C73E8);
    //     v8 = this->0x1B4 ? this->0x1B4 : byte_5EA438;
    //     ShortComputation_5730(&dword_5EA5E8, v8);
    //     SubCallWithConditionalFieldFree(v9);
    //     return 0;
    //   } else {
    //     SubCallWithConditionalFieldFree(v9);
    //     return -1;
    //   }
    // UNRESOLVED: Packet globals unk_5EC6D0 and unk_8AC368 appear in the fact tables but are absent from the raw decompiled source of this function; their connection to this function cannot be verified here
    // UNRESOLVED: Parameter a2 appears in the signature but is never referenced in the raw source
    // UNRESOLVED: The exact meaning of the mode values 1 and 2 passed to sub_4AE750, and of the paired sub_568620/sub_568910 calls with 512, is not determinable from this function alone
    // UNRESOLVED: The identity of the 'this' struct (fields 0x114/0x138/0x1B4/0x1F00/0x1F78/0x2ED8/0x2F08/0x2F8C) is unknown; equal offsets on unrelated objects are not proof of a shared type
}
