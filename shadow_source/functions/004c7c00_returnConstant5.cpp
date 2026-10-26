// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C00
// Canonical corpus name: Constant5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Constant5_004c7c00.c

void UnknownObject::returnConstant5()
{
    // Trivial constant function: returns the integer constant 5 with no arguments, side effects, or guards. Called by SetupCarLightingAndRender (0x004C71C0).
    // RETURN: Returns the constant integer 5 immediately; no parameters are read and no state is accessed. [source:raw]

    // Conservative worker pseudocode:
    //   int returnConstant5() {
    //       return 5;
    //   }
    // UNRESOLVED: semantic meaning of constant 5 is unestablished; caller SetupCarLightingAndRender (0x004C71C0) uses the value but the packet provides no field/global context to name it
}
