// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DE590
// Canonical corpus name: sub_4DE590
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DE590_004de590.c

void UnknownObject::CompareFloatFieldC()
{
    // Two-pointer comparator: compares the float at offset 0xC of object a1 with the float at offset 0xC of object a2, returning 1 when a1's value is greater, 0 when equal, and -1 when less. A qsort-style ordering callback.
    // GUARD: tests whether the float at this+0xC of a1 is greater than the float at this+0xC of a2 [field:this:0x0000000C, source:raw]
    // RETURN: returns 1 when a1's field value exceeds a2's [function:0x004DE590, source:raw]
    // GUARD: after the greater-than check fails, tests equality of the same two field floats [field:this:0x0000000C, source:raw]
    // RETURN: returns 0 when the two field values are equal [function:0x004DE590, source:raw]
    // RETURN: returns -1 when a1's field value is less than a2's [function:0x004DE590, source:raw]

    // Conservative worker pseudocode:
    //   if (float(a1 + 12) > float(a2 + 12)) return 1;
    //   if (float(a1 + 12) >= float(a2 + 12)) return 0;
    //   return -1;
    // UNRESOLVED: The template prelabel describes a one-operand getter of field 0xC with no side effects, but the raw source shows a two-pointer comparator; the template label is superseded by the source.
    // UNRESOLVED: Both a1 and a2 are read through the single evidenced field (offset 0xC); whether they are two instances of the same class, and which object type owns this comparator, is unproven.
}
