// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005679A0
// Canonical corpus name: NullCheckWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NullCheckWrapper_005679a0.c

void UnknownObject::NullCheckWrapper()
{
    // Thunk wrapper (attributes: thunk): forwards both arguments (this, a2) unchanged to NullCheckedCallWrapper and performs no local logic, field access or global access. The legacy ABI name implies the forwarded target returns 0 when its parameter a2 is null, but that behavior lives in the callee, not in this thunk.
    // CALL: Forward (this, a2) to NullCheckedCallWrapper; the null-parameter check implied by the ABI name is performed by the forwarded target. [source:raw]
    // RETURN: Implicit void return; the thunk produces no value. Called by ten callers including SeasonScoring, SessionConfigReader, SeasonScoringInfoUpdater, RecursiveTreeTraversalFree and sub_424080. [caller:0x00424080, caller:0x0047D800, caller:0x004C0260, caller:0x004C02D0, caller:0x004C0910, caller:0x004C11E0, caller:0x004C2A80, caller:0x004C5940, caller:0x004C5CB0, caller:0x00567A90, source:raw]

    // Conservative worker pseudocode:
    //   void NullCheckWrapper(_DWORD* this, int a2) {
    //     NullCheckedCallWrapper(this, a2);
    //   }
    // UNRESOLVED: NullCheckedCallWrapper is not a tracked callee in the packet (no address evidence), so its implementation is unknown.
    // UNRESOLVED: The 0-on-null-parameter semantics come only from the legacy ABI name and are not confirmed by the raw source.
}
