// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486320
// Canonical corpus name: StructFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldAccessor_00486320.c

void UnknownObject::StructFieldAccessor()
{
    // __thiscall getter: returns the int field at this[35] (offset 0x8C). No side effects. Heavily reused by list/render/destruction paths that need to read a single int field off an unknown object.
    // RETURN: Read and return this[35] (offset 0x8C). [source:raw, field:this:0x0000008C]
    // CALL: Called by MultiListDestructorWithCleanup (0x00486080), StateChangeNotification (0x00486660), UIWidgetPropertyPropagator (0x004866AD), UIWidgetPropagateState (0x0048741B), StateChangeHandlerWithSubscriberNotification (0x00487900), ObjectSearchWithDoubleIteration (0x00495980), DualListDestruction (0x00498D90), LinkedListIterationVirtualCall (0x00498F80), ListIterationWithVTableDispatch (0x00498FB0), GuardedDrawRenderDispatch (0x00498FE0), DestructorWithListWalk (0x00499280), ObjectRegistration (0x00499360) and RenderDispatchWithIteration (0x004993D0) to read the same int field on an unknown owner. [caller:0x00486080, caller:0x00486660, caller:0x004866AD, caller:0x0048741B, caller:0x00487900, caller:0x00495980, caller:0x00498D90, caller:0x00498F80, caller:0x00498FB0, caller:0x00498FE0, caller:0x00499280, caller:0x00499360, caller:0x004993D0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_486320(int *this) {
    //     return this[35];
    //   }
    // UNRESOLVED: Meaning of the int field at offset 0x8C depends on the unknown owner type; the wide caller set (UI, list, render dispatch) gives no single interpretation.
    // UNRESOLVED: Identity and purpose of the owner object are unknown.
}
