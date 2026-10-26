// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042EB60
// Canonical corpus name: ListSelectionClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ListSelectionClamp_0042eb60.c

void UnknownObject::ListSelectionClamp()
{
    // Clamps a list selection value for the row indexed by a2, then notifies the track configuration system. The previous selection is read from the a2 row; if the requested selection a3 is positive it is stored when below the row maximum, otherwise clamped to max-1; if a3 is not positive the selection is set to 0. After applying TrackConfig(this, 4, a2), the activation flag at this+0x0 and the change flag at this+0x19A4 are both set to 1 when the new selection differs from the previous one.
    // ASSIGNMENT: Read the current selection value for row a2 (offset 3012 within the 64-byte row stride) into the previous-selection variable. [source:raw]
    // GUARD: Branch on the requested selection a3: positive values go through the range clamp, non-positive values disable the selection. [source:raw]
    // ASSIGNMENT: When a3 is positive and below the row maximum (offset 3008), store a3 as the new selection; otherwise store max-1 to clamp it into range. [source:raw]
    // ASSIGNMENT: When a3 is not positive, write 0 to the selection field for row a2. [source:raw]
    // CALL: Call TrackConfig(this, 4, a2) to apply the updated configuration for the selection group. [callee:0x0042E530]
    // GUARD: Compare the new selection value with the previously read value; the dirty flags are only raised when they differ. [field:this:0x00000000, field:this:0x000019A4, source:raw]
    // ASSIGNMENT: Set the activation/dirty flag at this+0x0 to 1 on a selection change. [field:this:0x00000000]
    // ASSIGNMENT: Set the selection-change flag at this+0x19A4 to 1 on a selection change. [field:this:0x000019A4]

    // Conservative worker pseudocode:
    //   void ListSelectionClamp(char* this, int a2, int a3) {
    //     int prev = *(int*)&this[64 * a2 + 3012];
    //     if (a3 > 0) {
    //       int max = *(int*)&this[64 * a2 + 3008];
    //       this[64 * a2 + 3012] = (a3 < max) ? a3 : max - 1;
    //     } else {
    //       *(int*)&this[64 * a2 + 3012] = 0;
    //     }
    //     TrackConfig(this, 4, a2);
    //     if (*(int*)&this[64 * a2 + 3012] != prev) {
    //       this[6564] = 1;
    //       this[0] = 1;
    //     }
    //   }
    // UNRESOLVED: Meaning of the row stride group (TrackConfig group argument 4) and the row maximum field require the caller's row schema.
    // UNRESOLVED: The object owning the selection state and the significance of the two dirty flags are not identified from this packet.
}
