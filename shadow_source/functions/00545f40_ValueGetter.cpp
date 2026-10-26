// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545F40
// Canonical corpus name: ValueGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ValueGetter_00545f40.c

void UnknownObject::ValueGetter()
{
    // Thiscall getter that returns this[68], i.e. the dword field at offset 0x110 of the this object. Pure read, no side effects. Called across rendering, cockpit/gauge setup, vehicle-graphics scene loading, render-target cleanup, queue resource cleanup and flag-set rendering paths (00409890, 00448140, 0049CA00, 0049CD80, 004CEF30, 004DFCE0, 004FBA10, 0053EB70, 0053F270, 0054C410, 0054E080, 00554F80, 005574B0, 00557670, 00557CE0), indicating a widely shared field on a graphics/resource object.
    // RETURN: Return this[68], i.e. the dword field at offset 0x110 of this [field:this:0x00000110, source:raw]
    // CALL: Called by sub_409890 (00409890) [caller:0x00409890, source:raw]
    // CALL: Called by sub_448140 (00448140) [caller:0x00448140, source:raw]
    // CALL: Called by CockpitDashboardLEDGaugeSetup (0049CA00) [caller:0x0049CA00, source:raw]
    // CALL: Called by sub_49CD80 (0049CD80) [caller:0x0049CD80, source:raw]
    // CALL: Called by sub_4CEF30 (004CEF30) [caller:0x004CEF30, source:raw]
    // CALL: Called by VehicleGraphicsSceneLoader (004DFCE0) [caller:0x004DFCE0, source:raw]
    // CALL: Called by sub_4FBA10 (004FBA10) [caller:0x004FBA10, source:raw]
    // CALL: Called by sub_53EB70 (0053EB70) [caller:0x0053EB70, source:raw]
    // CALL: Called by RenderTargetCleanup (0053F270) [caller:0x0053F270, source:raw]
    // CALL: Called by QueueResourceCleanup (0054C410) [caller:0x0054C410, source:raw]
    // CALL: Called by FlagSetLoop (0054E080) [caller:0x0054E080, source:raw]
    // CALL: Called by sub_554F80 (00554F80) [caller:0x00554F80, source:raw]
    // CALL: Called by sub_5574B0 (005574B0) [caller:0x005574B0, source:raw]
    // CALL: Called by sub_557670 (00557670) [caller:0x00557670, source:raw]
    // CALL: Called by sub_557CE0 (00557CE0) [caller:0x00557CE0, source:raw]

    // Conservative worker pseudocode:
    //   return this->dword_0x110;
    // UNRESOLVED: The class of the this object and the meaning of the dword at 0x110 are not established; the caller set spans cockpit gauge setup, vehicle-graphics loading, render/resource cleanup and flag-set rendering, so the field role cannot be pinned down from this packet
}
