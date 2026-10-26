// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BB50
// Canonical corpus name: DualFieldSetToSameValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DualFieldSetToSameValue_0055bb50.c

void UnknownObject::DualFieldSetToSameValue()
{
    // Zero-initializes the target struct via GlobalZeroInit_c2a0, then writes the same value a2 into both fields at offsets 0x104 and 0x108, and returns the struct pointer. Used during display-mode/sound-manager node initialization; invoked by sub_55BE80.
    // CALL: GlobalZeroInit_c2a0(this): zero-initialize the entire struct before writing any field. [callee:0x0053C2A0]
    // ASSIGNMENT: this[0x104] = a2: write the first copy of the value into field at offset 0x104. [field:this:0x00000104]
    // ASSIGNMENT: this[0x108] = a2: write the second copy of the value into field at offset 0x108. [field:this:0x00000108]
    // RETURN: Return the struct pointer (this). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* sub_55BB50(DualField* this, int value) {
    //     GlobalZeroInit_c2a0(this);
    //     this[0x104] = value;
    //     this[0x108] = value;
    //     return this;
    //   }
    // UNRESOLVED: Owner type of the struct is unknown; only offsets 0x104 and 0x108 are visible.
    // UNRESOLVED: Why both fields hold the same value is caller-dependent; sub_55BE80 stores an entry index here.
}
