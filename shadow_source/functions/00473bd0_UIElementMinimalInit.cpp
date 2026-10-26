// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00473BD0
// Canonical corpus name: sub_473BD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_473BD0_00473bd0.c

void UnknownObject::UIElementMinimalInit()
{
    // Minimal UI element constructor: calls the base initialization helper sub_48C070(this, 0), then assigns the vtable pointer off_5A2E80 to this[0]. Returns the object pointer this.
    // CALL: Call sub_48C070(this, 0), the base initialization helper with parameter 0. [abi:lead, callee:0x0048C070]
    // ASSIGNMENT: Set the vtable pointer at this+0x0 to &off_5A2E80. [field:this:0x00000000, global:0x005A2E80]
    // RETURN: Return the initialized object pointer this. [function:0x00473BD0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *UIElementMinimalInit(_DWORD *this) {
    //     sub_48C070(this, 0);
    //     *this = &off_5A2E80;
    //     return this;
    //   }
    // UNRESOLVED: Semantics of the off_5A2E80 vtable and the exact UI element type it identifies are not evidenced.
    // UNRESOLVED: Role of parameter 0 to sub_48C070 is not evidenced.
}
