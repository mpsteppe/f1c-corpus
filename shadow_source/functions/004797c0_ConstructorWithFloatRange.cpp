// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004797C0
// Canonical corpus name: ShortComputation_97c0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_97c0_004797c0.c

void UnknownObject::ConstructorWithFloatRange()
{
    // Object constructor with float range parameters: delegates to the base initializer VtableSetWithInitCall(this, 1056964608 = 0.5f, 1065353216 = 1.0f), installs the vtable pointer off_5A4FE0 at this+0x0, and returns the constructed this pointer.
    // CALL: Base initializer call: VtableSetWithInitCall(this, 1056964608, 1065353216) runs before the vtable is installed, passing float 0.5 (1056964608) and float 1.0 (1065353216). [callee:0x00466980, source:raw]
    // ASSIGNMENT: Install the vtable pointer: *this = &off_5A4FE0, writing the object vtable global into this+0x0 and overriding whatever VtableSetWithInitCall installed. [field:this:0x00000000, global:0x005A4FE0, source:raw]
    // RETURN: Return the constructed this pointer. [function:0x004797C0, source:raw]

    // Conservative worker pseudocode:
    //   ConstructorWithFloatRange(this) {
    //     VtableSetWithInitCall(this, 1056964608, 1065353216);
    //     *this = &off_5A4FE0;
    //     return this;
    //   }
    // UNRESOLVED: The meaning of the two float parameters (0.5 and 1.0) forwarded to VtableSetWithInitCall is owned by the base initializer; they may form a min/max range but the semantics are not documented by this packet.
    // UNRESOLVED: The concrete type of the object that owns the off_5A4FE0 vtable is not evidenced.
}
