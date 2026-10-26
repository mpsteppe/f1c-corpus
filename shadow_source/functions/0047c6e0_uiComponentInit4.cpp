// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C6E0
// Canonical corpus name: UIComponentInit4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIComponentInit4_0047c6e0.c

void UnknownObject::uiComponentInit4()
{
    // UI component initializer: calls sub_48C070 on this with argument 1 (base component initialization), then writes the vtable pointer off_5A68F0 to offset 0 and returns this. No guards; always executes fully.
    // CALL: Call sub_48C070 (0x0048C070) with this and argument 1 to run base UI component initialization [callee:0x0048C070, source:raw]
    // ASSIGNMENT: Write the vtable pointer off_5A68F0 to offset 0, installing the vtable for this component type [field:this:0x00000000, global:0x005A68F0, source:raw]
    // RETURN: Return this [source:raw]

    // Conservative worker pseudocode:
    //   sub_48C070(this, 1);
    //   this[0] = &off_5A68F0;
    //   return this;
    // UNRESOLVED: The base initialization contract of sub_48C070 and the meaning of argument 1 are not documented in this function
    // UNRESOLVED: The owning UI component class behind vtable off_5A68F0 is not established from this packet alone
}
