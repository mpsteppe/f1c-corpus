// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00452740
// Canonical corpus name: SwapAndReinit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SwapAndReinit_00452740.c

void UnknownObject::SwapAndReinit()
{
    // thiscall helper that re-initializes a collision-node property pair: it first calls CollisionNodePropertySetter(byte_7CA594, *this, 0) to retire the old property value, then stores the new pair (this[1] = a3, this[0] = a2), and finally calls CollisionNodePropertySetter(byte_7CA594, a2, a3) to apply the new values, returning that call's result.
    // CALL: Call CollisionNodePropertySetter(byte_7CA594, *this, 0) with the old property value read from this+0 and constant 0. [callee:0x0044F050, field:this:0x00000000, global:0x007CA594, source:raw]
    // ASSIGNMENT: Write the new associated value a3 into this[1] (offset +4). [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the new property value a2 into this[0] (offset +0). [field:this:0x00000000, source:raw]
    // CALL: Call CollisionNodePropertySetter(byte_7CA594, a2, a3) to apply the new property pair. [callee:0x0044F050, field:this:0x00000000, field:this:0x00000004, global:0x007CA594, source:raw]
    // RETURN: Return the result of the final CollisionNodePropertySetter call. [source:raw]

    // Conservative worker pseudocode:
    //   CollisionNodePropertySetter(byte_7CA594, *this, 0);
    //   this[1] = a3;
    //   *this = a2;
    //   return CollisionNodePropertySetter(byte_7CA594, a2, a3);
    // UNRESOLVED: The global byte_7CA594 is flagged in packet analysis as WheelBrakeBiasThreshold (DERIVED); its exact role as the property-setter target is not documented in this function.
    // UNRESOLVED: Meaning of the property-setter arguments (0 on retire, a3 on apply) and the object owning this+0 / this+4 is caller-supplied context only.
    // UNRESOLVED: Callers StructInitWithFixedValues (00452780), StructInitWithSubCall (004527e0), DeviceObjectSelector (00452810) and sub_452B10 (00452b10) are known but their intent is not resolved here.
}
