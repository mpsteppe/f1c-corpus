// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431A50
// Canonical corpus name: SimpleSetterWithFlag
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SimpleSetterWithFlag_00431a50.c

void UnknownObject::SimpleSetterWithFlag()
{
    // Unconditional flagged value setter. Stores the input value a2 as a dword at this+0x1CBC and raises a byte changed/dirty flag at this+0x1CB8 to 1. Returns the input value. Called by WheelDynamicsInit (0043E230) on the per-frame path.
    // ASSIGNMENT: result = a2: initialize the return value with the input [source:raw]
    // ASSIGNMENT: *(this + 7356) = a2: store the input value as a dword at this+0x1CBC (the target value field) [field:this:0x00001CBC, source:raw]
    // ASSIGNMENT: *(this + 7352) = 1: set the byte at this+0x1CB8 to 1, marking the value as changed/dirty [field:this:0x00001CB8, source:raw]
    // RETURN: Return result (the input value) [source:raw]
    // CALL: Invoked from WheelDynamicsInit (0043E230) on the per-frame tick path [caller:0x0043E230]

    // Conservative worker pseudocode:
    //   int SimpleSetterWithFlag(int this, int a2) {
    //     int result = a2;
    //     *(_DWORD *)(this + 7356) = a2;
    //     *(_BYTE *)(this + 7352) = 1;
    //     return result;
    //   }
    // UNRESOLVED: The changed/dirty flag semantics of this+0x1CB8 and the target-value role of this+0x1CBC are DERIVED from the existing analysis; the raw source only shows two unconditional writes.
}
