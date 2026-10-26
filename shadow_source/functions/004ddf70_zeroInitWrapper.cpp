// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DDF70
// Canonical corpus name: ZeroInitWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInitWrapper_004ddf70.c

void UnknownObject::zeroInitWrapper()
{
    // Indexed pit-crew instance initialization wrapper: computes the element address dword_8AC394 + 1060 * a1 inside a per-index pit-crew array and forwards a2 and a3 to PitCrewInstanceSetup with a constant 0 argument. Called by VehicleSceneLoadAndPositionTires (sub_4681B0).
    // CALCULATION: Computes the target element address as dword_8AC394 + 1060 * a1, applying the 1060-byte stride over the pit-crew instance array. [global:0x008AC394, source:raw]
    // CALL: Calls PitCrewInstanceSetup on the computed element address with a2, constant 0, and a3. [callee:0x004DDAD0, global:0x008AC394, source:raw]

    // Conservative worker pseudocode:
    //   PitCrewInstanceSetup(dword_8AC394 + 1060 * a1, a2, 0, a3);
    // UNRESOLVED: Stride 1060 and base dword_8AC394 imply a pit-crew instance struct/array, but PitCrewInstanceSetup's body is not in the packet, so the layout and the meaning of arguments a2/a3 and the constant 0 are not evidenced.
    // UNRESOLVED: Why a2/a3 are forwarded unchanged while the third argument is fixed to 0 is not determinable from this packet.
}
