// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7B00
// Canonical corpus name: sub_4D7B00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D7B00_004d7b00.c

void UnknownObject::TrackReferenceFinder()
{
    // Initializes and fills three track-reference slots. For each slot j in 0..2 it clears the two index dwords (this+4*j and this+4*j+12) to -1, sets a lower value bound (this+24 for slot 0 from flt_5EA404, this+28 hardcoded to 0 for slot 1, this+32 from flt_5EA3F8[2] for slot 2), and sets an upper value bound at this+4*j+36 from flt_5EA3FC[j]. It then scans the track data array dword_8ACFF0 (count dword_8ACFEC, 8-byte entries with a float at +4) and, for entries whose value lies inside the slot's lower/upper bounds, records the bracketing entry indices: the smallest such index into this+4*j and the largest into this+4*j+12. Called once by Game_Restart.
    // LOOP: First pass over slots i=0..2: writes -1 to this+4*i and this+4*i+12, clearing the slot index fields [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Slot 1 (j==1): writes 0 to this+28, the lower value bound dword at this+0x1C [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Slot 0 (j==0): writes flt_5EA404 into the float lower bound at this+24 [field:this:0x00000018, global:0x005EA404, source:raw]
    // ASSIGNMENT: Slot 2 (j==2): writes flt_5EA3F8[2] into the float lower bound at this+32 [global:0x005EA3F8, source:raw]
    // ASSIGNMENT: Every slot j: writes flt_5EA3FC[j] into the float upper bound at this+4*j+36 [global:0x005EA3FC, source:raw]
    // GUARD: The search loop body runs only while dword_8ACFEC > 0 (the track data array is non-empty) [global:0x008ACFEC, source:raw]
    // LOOP: Walks every entry v3 of the track data array dword_8ACFF0 and reads the entry value at v5 + 8*v3 + 4 [global:0x008ACFF0, global:0x008ACFEC, source:raw]
    // GUARD: Considers entry v3 only when its value lies inside the slot bounds: lower bound <= v7 <= upper bound [field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Records the smallest matching entry index into this+4*j when the slot index is -1 or the new entry value is smaller than the recorded one [source:raw]
    // ASSIGNMENT: Records the largest matching entry index into this+4*j+12 when the slot index is -1 or the recorded minimum's value is smaller than the new entry value [source:raw]
    // RETURN: Returns the final track entry count (dword_8ACFEC) [global:0x008ACFEC, function:0x004D7B00, source:raw]
    // CALL: Invoked from Game_Restart to (re)establish the track reference slots on restart [caller:0x0042D7A0]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 3; i++) { this[4*i] = -1; this[4*i+12] = -1; }
    //   for (j = 0; j < 3; j++) {
    //     if (j == 1) this[28] = 0;
    //     else if (j) this[4*j+24] = flt_5EA3F8[j];
    //     else this[24] = flt_5EA404;
    //     this[4*j+36] = flt_5EA3FC[j];
    //     for (v3 = 0; v3 < dword_8ACFEC; v3++) {
    //       v7 = dword_8ACFF0[8*v3+4];
    //       if (this[4*j+24] <= v7 && v7 <= this[4*j+36]) {
    //         if (this[4*j] == -1 || dword_8ACFF0[8*this[4*j]+4] > v7) this[4*j] = v3;
    //         if (this[4*j+12] == -1 || dword_8ACFF0[8*this[4*j]+4] < v7) this[4*j+12] = v3;
    //       }
    //     }
    //   }
    //   return dword_8ACFEC;
    // UNRESOLVED: The track data entry layout (8-byte stride with the compared value at +4) and the meaning of the float at dword_8ACFF0[v3*8+4] are inferred from the raw source; what the value represents is not established by this packet
    // UNRESOLVED: The exact role of the bracketing index pair this+4*j and this+4*j+12 (minimum and maximum matching track entry) follows the existing analysis naming and is not independently proven
    // UNRESOLVED: Field offsets this+0x18 and this+0x1C are the only lower bounds with packet field entries; the remaining slot offsets (this+24, this+28, this+32, index dwords) are reachable only through the raw source text
}
