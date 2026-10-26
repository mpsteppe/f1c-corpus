// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005408F0
// Canonical corpus name: GraphicsConfigStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GraphicsConfigStateSetter_005408f0.c

void UnknownObject::GraphicsConfigStateSetter()
{
    // State setter on a _DWORD array (this): writes two adjacent state fields this[1271] (offset 0x13DC) and this[1272] (offset 0x13E0) based on the mode argument a2. Mode 0 clears both to 0, mode 1 sets both to 1, mode 2 sets this[1272] to 2 and this[1271] to 1. Returns a2. Only caller is VidMan_Enter.
    // ASSIGNMENT: result = a2: the mode argument is preserved and becomes the return value. [source:raw]
    // GUARD: Branch on a2: 0 clears both state fields, 1 sets both to 1, 2 sets this[1272]=2 / this[1271]=1; other values leave the fields untouched. [source:raw]
    // ASSIGNMENT: When a2 == 0: this[1271] (offset 0x13DC) = 0. [field:this:0x000013DC, source:raw]
    // ASSIGNMENT: When a2 == 0: this[1272] (offset 0x13E0) = 0. [field:this:0x000013E0, source:raw]
    // ASSIGNMENT: When a2 == 1: this[1272] (offset 0x13E0) = 1. [field:this:0x000013E0, source:raw]
    // ASSIGNMENT: When a2 == 1: this[1271] (offset 0x13DC) = 1. [field:this:0x000013DC, source:raw]
    // ASSIGNMENT: When a2 == 2: this[1272] (offset 0x13E0) = 2. [field:this:0x000013E0, source:raw]
    // ASSIGNMENT: When a2 == 2: this[1271] (offset 0x13DC) = 1. [field:this:0x000013DC, source:raw]
    // RETURN: Returns result, i.e. the original a2 mode value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5408F0(_DWORD *this, int a2) {
    //     int result = a2;
    //     if (a2 == 1) { this[1272] = 1; this[1271] = 1; }
    //     else if (a2 == 2) { this[1272] = 2; this[1271] = 1; }
    //     else { this[1272] = 0; this[1271] = 0; }
    //     return result;
    //   }
    // UNRESOLVED: Exact meaning of the two state fields at 0x13DC and 0x13E0 is unknown; they are only ever written 0/1 and 0/1/2 respectively.
    // UNRESOLVED: Field 0x13E0 accepts 2 while field 0x13DC never exceeds 1; the asymmetry is unexplained.
    // UNRESOLVED: The owning object type is unknown; the caller VidMan_Enter suggests a graphics/video configuration object.
}
