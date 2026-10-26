// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00408420
// Canonical corpus name: ReciprocalWithSignCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ReciprocalWithSignCheck_00408420.c

void UnknownObject::ReciprocalWithSignCheck()
{
    // Always writes 1.0f to this+4. Writes 1.0f to this+8 when a2 is not positive; when a2 is greater than 0.0f, writes the reciprocal 1.0f / a2 to this+8 instead.
    // ASSIGNMENT: this+4 is always set to 1.0f (bit pattern 1065353216). [field:this:0x00000004]
    // GUARD: Branch on whether a2 is greater than 0.0f. [source:raw]
    // CALCULATION: When a2 > 0.0f, this+8 receives 1.0f / a2. [field:this:0x00000008]
    // ASSIGNMENT: Otherwise this+8 is set to 1.0f (bit pattern 1065353216). [field:this:0x00000008]

    // Conservative worker pseudocode:
    //   this[1] = 1.0f;
    //   this[2] = (a2 > 0.0f) ? (1.0f / a2) : 1.0f;
    // UNRESOLVED: flt_59E43C and flt_59E440 are listed as read globals for this function but do not appear in the raw source; their role is not evidenced here.
}
