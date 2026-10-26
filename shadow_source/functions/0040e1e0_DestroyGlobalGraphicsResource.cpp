// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E1E0
// Canonical corpus name: WrapperSub40FB30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WrapperSub40FB30_0040e1e0.c

void UnknownObject::DestroyGlobalGraphicsResource()
{
    // Parameterless wrapper that calls GraphicsResourceDestructor with the address of the global object at 0x005EA560 and returns its integer result.
    // CALCULATION: Take the address of the global dword_5EA560 as the single argument to the destructor. [global:0x005EA560]
    // CALL: Call GraphicsResourceDestructor(&dword_5EA560). [global:0x005EA560, source:raw]
    // RETURN: Return the integer result of GraphicsResourceDestructor. [source:raw]

    // Conservative worker pseudocode:
    //   // Parameterless wrapper around GraphicsResourceDestructor for the global object.
    //   int DestroyGlobalGraphicsResource() {
    //       return GraphicsResourceDestructor(&dword_5EA560);
    //   }
    // UNRESOLVED: Identity, type, and ownership of the global object at 0x005EA560 are unknown.
    // UNRESOLVED: GraphicsResourceDestructor is not in the packet callee list; its address and return contract are unknown.
}
