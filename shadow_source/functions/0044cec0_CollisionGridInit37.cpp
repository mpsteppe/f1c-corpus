// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CEC0
// Canonical corpus name: CollisionGridInit37
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGridInit37_0044cec0.c

void UnknownObject::CollisionGridInit37()
{
    // Straight-line initializer for the 0x7CCBF4 collision-grid block: sets the grid size to 37, zeroes one float field, then calls InitFloatConstants(). No branches.
    // ASSIGNMENT: Set dword_7CCBF4 = 37, the collision grid size for this block. [global:0x007CCBF4, source:raw]
    // ASSIGNMENT: Set flt_7CCBF8 = 0.0. [global:0x007CCBF8, source:raw]
    // CALL: Invoke InitFloatConstants(), the named callee in the raw source. [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGridInit37() {
    //     dword_7CCBF4 = 37;
    //     flt_7CCBF8 = 0.0;
    //     InitFloatConstants();
    //   }
    // UNRESOLVED: The address and identity of the InitFloatConstants() callee are not present in the packet's callee facts; only its name appears in the raw source.
    // UNRESOLVED: No static callers or frame-path evidence exist in the packet, so when this initializer runs is unknown.
}
