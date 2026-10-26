// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431A70
// Canonical corpus name: PhysicsGridValueSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsGridValueSet_00431a70.c

void UnknownObject::PhysicsGridValueSet()
{
    // Writes a float value into a physics grid and sets a per-entry flag. Computes the float-grid index as a3 + 3*(a2+617), stores parameter a4 there, sets the byte at this + a2 + 7400 to 1, and returns the computed index. Called by WheelDynamicsInit.
    // CALCULATION: Compute the float-grid index as a3 + 2*(a2+617) + (a2+617), i.e. a3 + 3*(a2+617). [source:raw]
    // ASSIGNMENT: Store parameter a4 into this[computed_index], writing the value into the float grid array. [source:raw]
    // ASSIGNMENT: Set the per-entry occupancy flag byte at this + a2 + 7400 to 1. [source:raw]
    // RETURN: Return the computed grid index. [source:raw]

    // Conservative worker pseudocode:
    //   index = a3 + 3 * (a2 + 617);
    //   this[index] = a4;
    //   ((byte*)this)[a2 + 7400] = 1;
    //   return index;
    // UNRESOLVED: The 617 constant's meaning and the grid dimensions are unknown; a2 appears to be a row/entry index.
    // UNRESOLVED: The relation between the float array and the byte-flag region at +7400 is not constrained by evidence.
    // UNRESOLVED: The overall object type is unknown; the ABI lead PhysicsGridValueSet and the single caller WheelDynamicsInit suggest a per-wheel physics value table.
}
