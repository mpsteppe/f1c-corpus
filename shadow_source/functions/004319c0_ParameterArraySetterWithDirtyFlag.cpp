// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004319C0
// Canonical corpus name: ParameterArraySetterWithDirtyFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ParameterArraySetterWithDirtyFlag_004319c0.c

void UnknownObject::ParameterArraySetterWithDirtyFlag()
{
    // Stores a float value into a parameter array on a this-object at element index a2 + 1846 and sets the parallel per-element dirty byte at byte offset a2 + 7380 to 1, then returns the element index a2. Called by WheelDynamicsInit (0x0043E230), consistent with an initializer that writes a wheel/vehicle parameter and marks it dirty.
    // ASSIGNMENT: Initialize result to the element index a2. [source:raw]
    // ASSIGNMENT: Write the float a3 into the parameter array: this[a2 + 1846] = a3 (element a2 of a float array whose base is at element offset 1846). [source:raw]
    // STATE_TRANSITION: Set the per-element dirty flag: *((_BYTE*)this + a2 + 7380) = 1, marking the parameter at index a2 as modified. [source:raw]
    // RETURN: Return the element index a2. [source:raw]

    // Conservative worker pseudocode:
    //   int ParameterArraySetterWithDirtyFlag(float* this_, int a2, float a3) {
    //     this_[a2 + 1846] = a3;
    //     *((unsigned char*)this_ + a2 + 7380) = 1;
    //     return a2;
    //   }
    // UNRESOLVED: Ownership: the this-object type is unknown; the byte flag array at offset 7380 and the float array at element offset 1846 (byte offset 7384 + 4*a2) are treated as separate parallel arrays without an independently proven layout.
}
