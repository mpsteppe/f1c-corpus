// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00401000
// Canonical corpus name: sub_401000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_401000_00401000.c

void UnknownObject::ApplyCallbackNStrided()
{
    // Generic strided iteration helper: invokes a __thiscall callback a4 exactly a3 times, starting at pointer a1 and advancing it by byte stride a2 each step, returning the last callback result. Used by NamedEntryLookupInFormatList, VehicleListBuilderFromGlobalArray, NameListBuilderFromVehicleArray, LargeStructInitialization and UIControlWindowInitialization to walk element lists applying a per-element operation.
    // GUARD: If count-1 >= 0 (count >= 1) the iteration loop runs; a non-positive count returns immediately. [source:raw]
    // LOOP: Repeat a3 times: invoke callback a4(a1), then advance the current pointer a1 by stride a2. [source:raw]
    // CALL: Per-iteration thiscall into a4; used by list-building/lookup callers (NamedEntryLookupInFormatList, VehicleListBuilderFromGlobalArray, NameListBuilderFromVehicleArray, LargeStructInitialization, UIControlWindowInitialization) for element processing. [source:raw, caller:0x00415230, caller:0x00415780, caller:0x004159B0, caller:0x00464C10, caller:0x004A70E0]
    // RETURN: Return the value of the last callback invocation (or count-1 sentinel when the loop never ran). [source:raw]

    // Conservative worker pseudocode:
    //   result = count - 1;
    //   if (count - 1 >= 0) { v6 = count; do { result = a4(a1); a1 += a2; --v6; } while (v6); }
    //   return result;
}
