// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599465
// Canonical corpus name: RefCountIncDec
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RefCountIncDec_00599465.c

void UnknownObject::RefCountIncDec()
{
    // Adjusts two counters through double-indirect pointers on this: increments the dword at the pointer stored in this+0x2C and decrements the dword at the pointer stored in this+0x1C, returning the decremented value. Shape matches a putback of one narrow character into a buffered stream (available count up, read position back one). Invoked on the putback path from CharValidationAgainstEncodingTableWithLocaleFall.
    // ASSIGNMENT: Increments the dword value at the pointer stored in this+0x2C by one; interpreted as raising an available/remaining count for a one-character putback. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Decrements the dword value at the pointer stored in this+0x1C by one; interpreted as stepping a read-position offset back one position. [field:this:0x0000001C, source:raw]
    // RETURN: Returns the post-decrement value read through this+0x1C. [function:0x00599465, source:raw]
    // CALL: Called on the putback path by CharValidationAgainstEncodingTableWithLocaleFall (0x00598FD4), which supplies the this object. [caller:0x00598FD4, source:raw]

    // Conservative worker pseudocode:
    //   ++**(this + 0x2C);
    //   return --**(this + 0x1C);
    // UNRESOLVED: The exact object contract behind this+0x1C and this+0x2C (position vs count semantics) is DERIVED from the raw body and the prior analysis, not independently confirmed.
    // UNRESOLVED: Equal offsets on unrelated this pointers elsewhere are not proof the fields or owner class are identical.
}
