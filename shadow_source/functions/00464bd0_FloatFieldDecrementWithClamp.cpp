// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464BD0
// Canonical corpus name: FloatFieldDecrementWithClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFieldDecrementWithClamp_00464bd0.c

void UnknownObject::FloatFieldDecrementWithClamp()
{
    // Decrements the float field this[26] (offset 0x68) by a2, then clamps the result into [0.0, a2]: a negative result is forced to 0.0 and a result above a2 is forced back to a2. Always writes the field; no guard skips the update.
    // CALCULATION: Subtract a2 from this[26] (offset 0x68) and store the result back into the same field. [field:this:0x00000068, source:raw]
    // GUARD: Branch on whether the decremented this[26] is >= 0.0; a negative value is clamped to 0.0. [field:this:0x00000068, source:raw]
    // GUARD: On the non-negative path, branch on whether this[26] is greater than a2; if so, clamp the field to a2. [field:this:0x00000068, source:raw]
    // ASSIGNMENT: Write 0.0 to this[26] when the decremented value is negative. [field:this:0x00000068, source:raw]
    // ASSIGNMENT: Write a2 to this[26] when the decremented value exceeds a2. [field:this:0x00000068, source:raw]
    // CALL: Invoked by EntityVisibilityGridManager (0x00465460). [caller:0x00465460]

    // Conservative worker pseudocode:
    //   this[26] = this[26] - a2;
    //   if (this[26] < 0.0)
    //     this[26] = 0.0;
    //   else if (this[26] > a2)
    //     this[26] = a2;
    // UNRESOLVED: The packet lists the float global flt_59E440 (0x0059E440) as referenced, but the raw source text only uses the literal 0.0; flt_59E440 may be the zero threshold backing that comparison but its role here is not shown in the raw text.
    // UNRESOLVED: The meaning of the field at offset 0x68 (decremented timer or resource counter) and the caller EntityVisibilityGridManager's usage context are not established.
}
