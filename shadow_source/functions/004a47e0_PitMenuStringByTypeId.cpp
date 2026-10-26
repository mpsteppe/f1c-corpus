// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A47E0
// Canonical corpus name: sub_4A47E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A47E0_004a47e0.c

void UnknownObject::PitMenuStringByTypeId()
{
    // Maps an integer type id in the range 0-4 to a pit/garage menu string literal via a jump table: 0 -> StopGo, 1 -> Fuel, 2 -> Tyres, 3 -> Wing, 4 -> Damage, and any other value to the Error string. Returns the selected string pointer. Part of the pit strategy / HUD menu string system; called from sub_49F1C0 (0x0049F1C0).
    // GUARD: Dispatch on the integer type id via the switch jump table at 0x004A4810; values outside 0-4 fall through to the default case. [global:0x004A4810, source:raw]
    // ASSIGNMENT: Case 0: select the StopGo string literal (0x005CD4D4). [global:0x005CD4D4, source:raw]
    // ASSIGNMENT: Case 1: select the Fuel string literal (0x005CCC78). [global:0x005CCC78, source:raw]
    // ASSIGNMENT: Case 2: select the Tyres string literal (0x005CD4F0). [global:0x005CD4F0, source:raw]
    // ASSIGNMENT: Case 3: select the Wing string literal (0x005CD4E8). [global:0x005CD4E8, source:raw]
    // ASSIGNMENT: Case 4: select the Damage string literal (0x005CD4E0). [global:0x005CD4E0, source:raw]
    // ASSIGNMENT: Default: select the Error string literal (0x005CD4CC). [global:0x005CD4CC, source:raw]
    // RETURN: Return the selected string literal pointer. [source:raw]

    // Conservative worker pseudocode:
    //   switch (typeId) {
    //     case 0: return aStopGo;
    //     case 1: return aFuel;
    //     case 2: return aTyres;
    //     case 3: return aWing_1;
    //     case 4: return aDamage;
    //     default: return aError_0;
    //   }
    // UNRESOLVED: The semantic meaning of each type id (0-4) in the pit menu and how callers populate the id are not established from this packet.
    // UNRESOLVED: The proposed name PitMenuStringByTypeId is DERIVED from the existing analysis; the string literals' exact display context (pit stop / garage menu) is unverified.
    // UNRESOLVED: The parameter is delivered in the thiscall register but is treated as a plain integer, not an object pointer.
}
