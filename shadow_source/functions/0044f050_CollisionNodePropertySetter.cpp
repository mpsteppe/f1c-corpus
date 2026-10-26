// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F050
// Canonical corpus name: CollisionNodePropertySetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNodePropertySetter_0044f050.c

void UnknownObject::CollisionNodePropertySetter()
{
    // Byte-property setter (thiscall): writes the byte value a3 into the object at byte offset (a2 + 636) and returns a3. Operates on a byte-indexed property region whose base lies at offset 636 (0x27C) of the caller-supplied object.
    // ASSIGNMENT: Store byte a3 at this[a2 + 636]: the caller-supplied byte value is written into the byte property indexed by a2 at base offset 636 of the object. [function:0x0044F050, source:raw]
    // RETURN: Return a3 in the low byte of the result (LOBYTE(result) = a3), propagating the written value to the caller. [source:raw]
    // CALL: Invoked by SwapAndReinit (0x00452740), ConditionalCollisionDispatch (0x004527C0) and CameraViewportConfigBatch (0x00453560) to set individual byte properties in the object's 636-offset region. [caller:0x00452740, caller:0x004527C0, caller:0x00453560, source:raw]

    // Conservative worker pseudocode:
    //   int sub_44F050(BYTE *obj, int a2, char value) {
    //     obj[a2 + 636] = value;
    //     return value;
    //   }
    // UNRESOLVED: Identity of the owning object and the exact type of the 636-offset byte-property region.
    // UNRESOLVED: Semantic meaning of a2 (index within the property region versus absolute sub-offset).
}
