// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00418970
// Canonical corpus name: ThresholdGatedVirtualDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThresholdGatedVirtualDispatch_00418970.c

void UnknownObject::ThresholdGatedVirtualDispatch()
{
    // Range-gated virtual dispatch. Loads the object pointer at this+0xAF4 (dword index 701). If it is non-null and the float parameter a2 lies within [0.0, 1.0] (bounds shown as literals in the raw source), calls the __thiscall method stored at vtable offset +28 (0x1C) on that object, passing a2. Otherwise does nothing. Called from LazyRendererAudioInitCheck (0x004184F0) and UILoadingPercentDisplay (0x0047C860).
    // ASSIGNMENT: v2 = this[701], i.e. the dword at byte offset 0xAF4; the target object pointer for the virtual call. [field:this:0x00000AF4, source:raw]
    // GUARD: Guard: v2 (this+0xAF4) must be non-null. [field:this:0x00000AF4, source:raw]
    // GUARD: Guard: a2 must satisfy 0.0 <= a2 <= 1.0 (range bounds appear as literals in the raw source). [source:raw]
    // CALL: Virtual dispatch: call the __thiscall method stored at vtable offset +28 (0x1C) of object v2, passing a2. [field:*(this+0xAF4):0x0000001C, field:this:0x00000AF4, source:raw]
    // CALL: Called by LazyRendererAudioInitCheck (0x004184F0) and UILoadingPercentDisplay (0x0047C860) (legacy ABI lead: FAIL_418970). [caller:0x004184F0, caller:0x0047C860, function:0x00418970, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   void sub_418970(DWORD *self, float a2) {
    //     DWORD *obj = (DWORD *)self[701];
    //     if (obj && a2 >= 0.0f && a2 <= 1.0f)
    //       (*(void (__thiscall **)(DWORD *, DWORD))(*(DWORD *)obj + 28))(obj, (DWORD)a2);
    //   }
    // UNRESOLVED: Packet lists globals flt_59E43C and flt_59E440, but the decompiled body does not reference them directly; existing analysis (DERIVED) suggests they may back the 0.0/1.0 range bounds. Their actual role is unresolved.
    // UNRESOLVED: Identity of the virtual method at vtable slot +28 (0x1C) and the semantics of the normalized a2 parameter are unknown here; existing analysis suggests an audio-parameter update (DERIVED only).
}
