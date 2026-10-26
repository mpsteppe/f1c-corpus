// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431930
// Canonical corpus name: SetContactConstraint
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetContactConstraint_00431930.c

void UnknownObject::SetContactConstraint()
{
    // Stores a per-entry contact-constraint value and marks the entry active. Given an entry index a2 and a value a3, the function writes a3 into the float slot at dword index a2 + 1841 of the float-typed object and sets the byte flag at byte offset a2 + 7360 to 1, then returns a2. The value and flag live in two parallel indexed arrays of the same object.
    // CALCULATION: Entry selection: a2 indexes the constraint slot; the value lands at dword index a2 + 1841 and its active byte flag at byte offset a2 + 7360. [source:raw]
    // ASSIGNMENT: Write the constraint value a3 into this[a2 + 1841]. [source:raw]
    // ASSIGNMENT: Set the byte at offset a2 + 7360 to 1, marking the entry active. [source:raw]
    // RETURN: Return the entry index a2. [source:raw]
    // CALL: Called by WheelDynamicsInit (0x0043E230) to set one wheel contact constraint during wheel-dynamics initialisation. [caller:0x0043E230, source:raw]

    // Conservative worker pseudocode:
    //   int sub_431930(float *this, int a2, float a3) {
    //     this[a2 + 1841] = a3;
    //     *((char *)this + a2 + 7360) = 1;
    //     return a2;
    //   }
    // UNRESOLVED: The float slot array (index a2 + 1841) and the byte flag array (offset a2 + 7360) are parallel arrays keyed by entry index a2, but the enclosing object layout and stride are unknown.
    // UNRESOLVED: Semantic meaning of the stored value and of the 1.0 flag depends on the caller's contact model.
}
