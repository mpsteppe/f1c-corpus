// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044CC20
// Canonical corpus name: CollisionGlobalsInit4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionGlobalsInit4_0044cc20.c

void UnknownObject::CollisionGlobalsInit4()
{
    // Initializes collision subsystem globals: sets dword_7CA3B8 to 30, clears flt_7CA3BC to 0.0, then calls CameraViewZoomInitializer(). No arguments, no return value.
    // ASSIGNMENT: dword_7CA3B8 = 30 [global:0x007CA3B8]
    // ASSIGNMENT: flt_7CA3BC = 0.0 [global:0x007CA3BC]
    // CALL: Call CameraViewZoomInitializer() with no arguments [source:raw]

    // Conservative worker pseudocode:
    //   void CollisionGlobalsInit4()
    //   {
    //     dword_7CA3B8 = 30;
    //     flt_7CA3BC = 0.0;
    //     CameraViewZoomInitializer();
    //   }
    // UNRESOLVED: Callee CameraViewZoomInitializer appears in raw source but has no address or evidence ref in the packet (callees list empty).
    // UNRESOLVED: Semantic meaning of 30 stored in dword_7CA3B8 is unknown.
}
