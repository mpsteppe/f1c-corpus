// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B130
// Canonical corpus name: F_10FloatStructInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_10FloatStructInitializer_0053b130.c

void UnknownObject::FloatStructInitializer()
{
    // Constructor/initializer for a 40-byte float-bearing structure. Zeroes the first seven dword fields, sets the last three dword fields to 1.0f (giving the trailing component an identity-like value), then calls Identity44MatrixInit to initialize an embedded 4x4 matrix, and returns the object. Called from seven sites including matrix/vertex transform helpers.
    // ASSIGNMENT: Zero the first four dword fields at offsets 0x0, 0x4, 0x8 and 0xC. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the next three dword fields at offsets 0x10, 0x14 and 0x18. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Set the final three dword fields at offsets 0x1C, 0x20 and 0x24 to 1.0f. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // CALL: Call Identity44MatrixInit() to initialize the embedded 4x4 matrix portion of the object. [callee:0x0053B3B0, source:raw]
    // RETURN: Return the object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_53B130(int *obj) {
    //     obj[0] = 0; obj[1] = 0; obj[2] = 0; obj[3] = 0;
    //     obj[4] = 0; obj[5] = 0; obj[6] = 0;
    //     obj[7] = 1.0f; obj[8] = 1.0f; obj[9] = 1.0f;
    //     Identity44MatrixInit();
    //     return obj;
    //   }
    // UNRESOLVED: The F_10 prefix in the canonical name suggests a class-scoped or mangled identifier; the owning class is not established.
    // UNRESOLVED: Where in the object the embedded 4x4 matrix lives is not shown by this function's field table; Identity44MatrixInit is called with no visible argument in the raw source.
    // UNRESOLVED: The role of the three trailing 1.0f fields (identity scale?) is DERIVED, not proven.
}
