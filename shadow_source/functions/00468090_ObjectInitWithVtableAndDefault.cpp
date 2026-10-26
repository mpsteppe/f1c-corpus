// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00468090
// Canonical corpus name: ShortComputation_8090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_8090_00468090.c

void UnknownObject::ObjectInitWithVtableAndDefault()
{
    // Object constructor: calls base initializer sub_466090, installs vtable off_59F668 at this[0], and writes sentinel -1 at offset 0x128 (this[74]); returns the initialized pointer.
    // CALL: Calls sub_466090(this) to perform base object initialization. [callee:0x00466090, source:raw]
    // ASSIGNMENT: Sets this[0] (offset 0x0, vtable pointer) to off_59F668. [field:this:0x00000000, global:0x0059F668, source:raw]
    // ASSIGNMENT: Writes sentinel value -1 to this[74] (offset 0x128). [field:this:0x00000128, source:raw]
    // RETURN: Returns the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   sub_466090(this);
    //   this[0] = &off_59F668;
    //   this[74] = -1;
    //   return this;
    // UNRESOLVED: Semantic type of the object being constructed is unknown; owner evidence is absent.
}
