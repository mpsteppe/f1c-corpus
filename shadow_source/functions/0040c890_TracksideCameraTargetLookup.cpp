// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C890
// Canonical corpus name: TracksideCameraTargetLookup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TracksideCameraTargetLookup_0040c890.c

void UnknownObject::TracksideCameraTargetLookup()
{
    // Resolves a camera target by querying three registered loader objects in sequence. If the lookup key a2 is non-zero, invokes the virtual slot at vtable offset +28 (0x1C) on the loader object at this+0x18, then this+0x1C if the first returned zero, then this+0x20 if the second returned zero. Returns the first non-zero result, else 0.
    // ASSIGNMENT: Initialize result to 0 (not found). [source:raw]
    // GUARD: If the lookup key a2 is zero, skip all loader queries and return the zero result. [function:0x0040C890, source:raw]
    // CALL: Indirect thiscall on the loader object at this+0x18 (this[6]): dispatch the virtual slot at its vtable + 0x1C (28) with argument a2 and store the result. [field:this:0x00000018, field:*(this+0x18):0x0000001C, source:raw]
    // GUARD: If the first loader returned zero, query the fallback loader at this+0x1C. [function:0x0040C890, source:raw]
    // CALL: Indirect thiscall on the loader object at this+0x1C (this[7]): dispatch the virtual slot at its vtable + 0x1C (28) with argument a2 and store the result. [field:this:0x0000001C, field:*(this+0x1C):0x0000001C, source:raw]
    // GUARD: If the second loader also returned zero, query the final loader at this+0x20 and return its result directly. [function:0x0040C890, source:raw]
    // CALL: Indirect thiscall on the loader object at this+0x20 (this[8]): dispatch the virtual slot at its vtable + 0x1C (28) with argument a2; its return becomes the function result. [field:this:0x00000020, field:*(this+0x20):0x0000001C, source:raw]
    // RETURN: Return the first non-zero loader result, or 0 when a2 is zero or all three loaders returned zero. [function:0x0040C890, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int TracksideCameraTargetLookup(this, int key) {
    //     int result = 0;
    //     if (key) {
    //       result = this[6]->vtable[+28](this[6], key);
    //       if (!result) {
    //         result = this[7]->vtable[+28](this[7], key);
    //         if (!result)
    //           return this[8]->vtable[+28](this[8], key);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity and roles of the three loader objects (config/scene/module are proposed by prior analysis, not evidenced) are unknown.
    // UNRESOLVED: The virtual method at vtable offset +28 (0x1C) on each loader is dispatched through raw vtable slots with no concrete callee target listed.
    // UNRESOLVED: The exact meaning of the lookup key a2 (name vs id) is caller-supplied and not evidenced here.
}
