// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7F28
// Canonical corpus name: FieldZeroInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldZeroInitializer_004c7f28.c

void UnknownObject::FieldZeroInitializer()
{
    // Trivial __thiscall initializer: writes 0 into the member at this+0x4 (this[1]). Structural twin of FieldZero4 per the cluster_copy prelabel.
    // ASSIGNMENT: Write zero into this[1], the member at this+0x4. [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4C7F28(DWORD *this) {
    //     this[1] = 0;
    //   }
    // UNRESOLVED: Identity of the owning object and the meaning of the field at +0x4 are unknown; owner evidence is empty.
    // UNRESOLVED: Relationship to the FieldZero4 twin (cluster_rep 004c7dd0) is structural only (cluster_copy prelabel, DERIVED); no proof the fields or classes are identical.
}
