// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BB20
// Canonical corpus name: VehicleFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleFlagCheck_0049bb20.c

void UnknownObject::VehicleFlagCheck()
{
    // Returns whether a byte flag at offset 16648 of the object pointed to by global dword_7C54E0 (0x007C54E0) is nonzero. Pure read, no side effects. Called by HUDFlagRendererMain (004D82D0), HUDFlagRendererSecondary (004DBAC3) and sub_49D4C0, so it gates a vehicle flag value used by HUD flag rendering.
    // RETURN: Read the byte at dword_7C54E0 + 16648 and return whether it is nonzero [global:0x007C54E0, source:raw]
    // CALL: Called by sub_49D4C0 (0049D4C0) to check the flag value [caller:0x0049D4C0, source:raw]
    // CALL: Called by HUDFlagRendererMain (004D82D0) while rendering HUD flags [caller:0x004D82D0, source:raw]
    // CALL: Called by HUDFlagRendererSecondary (004DBAC3) while rendering HUD flags [caller:0x004DBAC3, source:raw]

    // Conservative worker pseudocode:
    //   return *(byte*)(dword_7C54E0 + 16648) != 0;
    // UNRESOLVED: The object type behind dword_7C54E0 and the meaning of the flag at offset 16648 are not established; subsystem metadata tags the function 'vehicle' and its callers are HUD flag renderers, but the flag's semantic role is not verifiable here
    // UNRESOLVED: Whether dword_7C54E0 must be non-null before the read is not checked inside this function
}
