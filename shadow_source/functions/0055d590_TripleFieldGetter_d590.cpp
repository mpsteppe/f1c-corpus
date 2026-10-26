// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D590
// Canonical corpus name: TripleFieldGetter_d590
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldGetter_d590_0055d590.c

void UnknownObject::TripleFieldGetter_d590()
{
    // Thiscall getter that reads three consecutive dword fields at offsets 0x44, 0x48 and 0x4C (this[17], this[18], this[19]) and writes each to the corresponding non-null output pointer a2, a3, a4. Returns a4 as result. Getter counterpart to the vector store at sub_55D460. Each output is independently gated by a null-pointer check.
    // GUARD: If a2 is non-null, write this[17] (offset 0x44) into *a2. [field:this:0x00000044]
    // GUARD: If a3 is non-null, write this[18] (offset 0x48) into *a3. [field:this:0x00000048]
    // GUARD: If a4 is non-null, write this[19] (offset 0x4C) into *a4. [field:this:0x0000004C]
    // RETURN: Return a4 as the result pointer. [source:raw]
    // CALL: Invoked by sub_560C10 (0x00560C10) and sub_560FE0 (0x00560FE0), consistent with a vector-component accessor used by vehicle/physics consumers. [caller:0x00560C10, caller:0x00560FE0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *TripleFieldGetter_d590(_DWORD *this, _DWORD *outX, _DWORD *outY, _DWORD *outZ) {
    //     if (outX) *outX = this[17];
    //     if (outY) *outY = this[18];
    //     if (outZ) *outZ = this[19];
    //     return outZ;
    //   }
    // UNRESOLVED: Whether the three fields are float vector components or integer triple is not provable from the packet (no arithmetic consumes them here).
    // UNRESOLVED: Concrete type of `this` is unproven; the packet owner is UnknownObject.
    // UNRESOLVED: Relationship to the counterpart store sub_55D460 is asserted only by the existing analysis, not by this packet's evidence.
}
