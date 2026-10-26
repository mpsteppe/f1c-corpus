// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7BD0
// Canonical corpus name: sub_4C7BD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C7BD0_004c7bd0.c

void UnknownObject::IsPlayerVehicle()
{
    // Player-vehicle identity check. Returns true when this vehicle's grid slot index (dword at this+0x4894) equals the dword at +18580 of the current player vehicle, resolved through the vehicle pointer array dword_7C54F0 indexed by the current-vehicle index dword_7C54E4. Pure comparison with no side effects. Called by AIVehicleDamageEvent (0041a170), OpponentProximityScanTeamRecognition (0042a7d0) and SuspensionForceComputationWithPerCornerVirtualDi (004f8440) to recognize the player's car.
    // CALCULATION: Resolves the current player vehicle: reads the vehicle pointer array dword_7C54F0 at index dword_7C54E4, then reads the dword at +18580 of that vehicle [global:0x007C54E4, global:0x007C54F0, source:raw]
    // CALCULATION: Reads this vehicle's grid slot / starting position index at this+0x4894 [field:this:0x00004894, source:raw]
    // RETURN: Returns true when this+0x4894 equals the current player vehicle's dword at +18580, otherwise false [source:raw]
    // CALL: Used as an is-player-vehicle check by AIVehicleDamageEvent (0041a170), OpponentProximityScanTeamRecognition (0042a7d0) and SuspensionForceComputationWithPerCornerVirtualDi (004f8440) [caller:0x0041A170, caller:0x0042A7D0, caller:0x004F8440, source:raw]

    // Conservative worker pseudocode:
    //   bool IsPlayerVehicle(int *this) {
    //     return this[4645] == *(DWORD*)(dword_7C54F0[dword_7C54E4] + 18580);
    //   }
    // UNRESOLVED: The player-side comparison field at current-vehicle+18580 has no dedicated field evidence ref in the packet (only the this-side offset +0x4894 is evidenced); its exact meaning is carried by the raw literal
    // UNRESOLVED: The equality meaning of the two grid-slot values (grid position vs starting slot) is a DERIVED interpretation from prior analysis, not confirmed by this packet
}
