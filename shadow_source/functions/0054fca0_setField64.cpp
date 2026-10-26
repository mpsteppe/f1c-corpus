// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FCA0
// Canonical corpus name: FieldSetter_fca0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldSetter_fca0_0054fca0.c

void UnknownObject::setField64()
{
    // thiscall field setter: stores the int argument into this+0x64 (this[25]) and returns the stored value. No branches, no callees, no globals. Caller set is dominated by render-state setup helpers, suggesting this+0x64 is a render-state parameter, but no callee or global evidence grounds that role.
    // ASSIGNMENT: Write argument a2 into field this+0x64 (this[25]). ABI lead Field_Setter_54fca0 corroborates a setter role. [field:this:0x00000064, source:raw, abi:lead]
    // RETURN: Return the stored value (result = a2). [source:raw, function:0x0054FCA0]

    // Conservative worker pseudocode:
    //   // thiscall on unknown owner; argument a2 stored into the field at this+0x64
    //   this->field_0x64 = a2;
    //   return a2;
    // UNRESOLVED: Semantic role of this+0x64 is unknown; the caller set (sub_546F70, sub_546FE0, ConditionalRenderStateSetup, GuardedRenderStateSet, ConditionalCheckCall) hints at render-state setup, but no callee or global evidence confirms the field's meaning or the owner type.
}
