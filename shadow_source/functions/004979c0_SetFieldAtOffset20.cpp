// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004979C0
// Canonical corpus name: Setter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Setter_004979c0.c

void UnknownObject::SetFieldAtOffset20()
{
    // Trivial __thiscall setter: stores the caller-provided integer a2 into the field at this+0x20 (this[8]) and returns that same stored value. No guard, no callee, no global. Called from rendering, data-processing, and network paths (UILargeRender, sub_4988D0, sub_49A5D0, FileDataProcessor, sub_57BF00, NetworkAccept).
    // ASSIGNMENT: Store parameter a2 into the field at this+0x20 (this[8]). [field:this:0x00000020, source:raw]
    // RETURN: Return the stored value (a2) as the function result. [source:raw, caller:0x00496930, caller:0x004988D0, caller:0x0049A5D0, caller:0x00567FB0, caller:0x0057BF00, caller:0x00580190]

    // Conservative worker pseudocode:
    //   int SetFieldAtOffset20(void* this, int a2) {
    //     this[8] = a2;  // this+0x20
    //     return a2;
    //   }
    // UNRESOLVED: Owner class is unknown (packet owner trust is UNKNOWN with no evidence); equal offsets on unrelated 'this' pointers are not proof of identical classes.
    // UNRESOLVED: Semantics of the stored field at this+0x20 are caller-dependent and unresolved from this packet alone.
}
