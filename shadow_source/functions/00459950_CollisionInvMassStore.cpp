// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459950
// Canonical corpus name: CollisionInvMassStore
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionInvMassStore_00459950.c

void UnknownObject::CollisionInvMassStore()
{
    // Stores a double-precision value and its reciprocal (1.0 / value) into two adjacent fields of a collision/body object at this+0x180 and this+0x188, then forwards a third argument to StructCopyWithReciprocalDivision and returns its result. The field pair is consistent with storing body mass and inverse mass.
    // ASSIGNMENT: Store the incoming double a2 at this+0x180 (this + 212 + 172). [field:this:0x00000180, source:raw]
    // CALCULATION: Compute the reciprocal 1.0 / a2; the 1.0 constant is read from the double constant at 0x0059E420. [field:this:0x00000188, global:0x0059E420, source:raw]
    // ASSIGNMENT: Store the reciprocal (1.0 / a2) at this+0x188 (this + 212 + 180). [field:this:0x00000188, source:raw]
    // CALL: Call StructCopyWithReciprocalDivision with argument a3 and return its result unchanged. [callee:0x005697A0, source:raw]

    // Conservative worker pseudocode:
    //   int CollisionInvMassStore(char* this, double mass, int arg3) {
    //     this->field_0x180 = mass;
    //     this->field_0x188 = 1.0 / mass;
    //     return StructCopyWithReciprocalDivision(arg3);
    //   }
    // UNRESOLVED: Semantic role of a3 and of StructCopyWithReciprocalDivision's return value is unknown from this function alone.
    // UNRESOLVED: Whether field 0x180/0x188 is mass/inverse-mass is an interpretation; the packet names it CollisionInvMassStore.
}
