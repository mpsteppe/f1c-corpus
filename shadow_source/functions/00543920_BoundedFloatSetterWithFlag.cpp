// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543920
// Canonical corpus name: BoundedFloatSetterWithFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedFloatSetterWithFlag_00543920.c

void UnknownObject::BoundedFloatSetterWithFlag()
{
    // Writes parameter a2 into the float field at this+0x190 only when a2 is in [0.0, 1.0] (bounds compared against the double constants dbl_59E420 = 1.0 and dbl_59E430 = 0.0), and sets flag bit 0x10000 in the flags dword at this+0xEC on success. Out-of-range values are rejected silently: no write and no flag set.
    // GUARD: Range check: the write proceeds only when a2 >= 0.0 (compared against dbl_59E430) and a2 <= 1.0 (compared against dbl_59E420); out-of-range values skip both the write and the flag set [global:0x0059E420, global:0x0059E430, source:raw]
    // ASSIGNMENT: Write the accepted a2 value into the float field at this+0x190 [field:this:0x00000190, source:raw]
    // ASSIGNMENT: OR flag bit 0x10000 into the flags dword at this+0xEC to mark the value as updated [field:this:0x000000EC, source:raw]
    // CALL: Called by sub_4FCEE0 (004fccee0) [caller:0x004FCEE0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 >= dbl_59E430 /* 0.0 * / && a2 <= dbl_59E420 /* 1.0 * /) {
    //       *(float*)(this + 0x190) = a2;
    //       *(_DWORD*)(this + 0xEC) |= 0x10000;
    //   }
    // UNRESOLVED: The dbl_59E420 / dbl_59E430 constants are named with a double-precision prefix while the stored value is a 32-bit float; whether the comparison actually happens in double precision is not established from this packet
    // UNRESOLVED: The meaning of flag bit 0x10000 in the word at this+0xEC and the semantic role of the bounded float at this+0x190 are unknown; the owning object type is not identified
    // UNRESOLVED: Only the values within [0.0, 1.0] are accepted; there is no clamping write for out-of-range inputs
}
