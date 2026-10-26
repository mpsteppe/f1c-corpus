// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CEF30
// Canonical corpus name: sub_4CEF30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CEF30_004cef30.c

void UnknownObject::IndexedEffectFieldSetter()
{
    // Walks a global list reached via ValueGetter(dword_8AFE88), whose +16 field holds an element count, and for each index i builds a name buffer (sub_548850 + ArithmeticComparison_7370), looks it up in `this`'s string list (StringListLookup), retrieves the indexed element (IndexedArrayAccess) and stamps it with field key 4096 via DualFieldSetterByKey. Returns the count (or 0 when the list is absent). Called from SpecialFX_Init and VehicleGraphicsSceneLoader.
    // CALL: ValueGetter(dword_8AFE88) reads the global list base into v3 [callee:0x00545F40, global:0x008AFE88, source:raw]
    // GUARD: If v3 == 0 (list absent), skip the whole loop and return 0 [source:raw]
    // ASSIGNMENT: Read element count from the list node: result = *(v3 + 16) [source:raw]
    // LOOP: Loop i = 0..count-1: sub_548850(i) prepares the index context, then ArithmeticComparison_7370(v7) fills the 64-byte name buffer [callee:0x00548850, callee:0x00547370, source:raw]
    // CALL: StringListLookup(this, v7) resolves the built name against `this`'s string list, returning index v5 [callee:0x004CE860, source:raw]
    // CALL: IndexedArrayAccess(this, v5) retrieves the element v6 addressed by the resolved index [callee:0x004CE8D0, source:raw]
    // CALL: DualFieldSetterByKey(v6, 4096) writes a dual field identified by key 4096 onto the retrieved element [callee:0x00547280, source:raw]
    // ASSIGNMENT: Reload the count result = *(v3 + 16) at the end of each iteration, so the loop observes a live count [source:raw]
    // RETURN: Return the final count value (or 0 when the global list is absent) [function:0x004CEF30, source:raw]
    // CALL: Invocation context: called by SpecialFX_Init (004cf070) and VehicleGraphicsSceneLoader (004dfce0) while binding named effect entries into a scene/vehicle object [caller:0x004CF070, caller:0x004DFCE0, source:raw]

    // Conservative worker pseudocode:
    //   list = ValueGetter(dword_8AFE88);
    //   if (list == 0) return 0;
    //   count = *(int*)(list + 16);
    //   for (i = 0; i < count; i++) {
    //     sub_548850(i);
    //     ArithmeticComparison_7370(v7);            // fill name buffer
    //     idx = StringListLookup(this, v7);
    //     elem = IndexedArrayAccess(this, idx);
    //     DualFieldSetterByKey(elem, 4096);
    //     count = *(int*)(list + 16);               // live count reload
    //   }
    //   return count;
    // UNRESOLVED: The +16 count field on the global list and the 4096 field-setter key have no field evidence refs; their semantics derive only from the callee names and call context
    // UNRESOLVED: sub_548850 and ArithmeticComparison_7370 are not documented here; the exact encoding produced into the v7 name buffer is unverified
    // UNRESOLVED: The structural-twin claim against CollisionGeometryOperationSelector (0044bb60) comes from the prelabel cluster copy and is not independently verified in this packet
}
