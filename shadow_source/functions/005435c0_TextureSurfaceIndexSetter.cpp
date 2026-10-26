// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005435C0
// Canonical corpus name: sub_5435C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5435C0_005435c0.c

void UnknownObject::TextureSurfaceIndexSetter()
{
    // Simple index setter: writes the argument a2 into this[13] (offset 0x34) and returns a2 unchanged. No guard, no callees, no globals. Existing analysis names the field a texture-surface index used for later rendering and lists D3DTextureCreation among the callers, but the field's exact meaning is DERIVED, not confirmed by this packet.
    // ASSIGNMENT: Write the argument into the this field at offset 0x34: this[13] = a2. [field:this:0x00000034, source:raw]
    // RETURN: Return the stored value a2. [function:0x005435C0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5435C0(_DWORD *this, int a2) {
    //     int result = a2;
    //     this[13] = a2;
    //     return result;
    //   }
    // UNRESOLVED: The meaning of the integer stored at this+0x34 (texture-surface index per the existing skeleton analysis) is DERIVED from the LLM fill and is not independently confirmed by this packet's evidence.
    // UNRESOLVED: The owning class of the this object is unknown (UnknownObject); one recorded caller is D3DTextureCreation (0x00550080), which is consistent with a texture-surface association but not conclusive.
}
