// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C85D0
// Canonical corpus name: AudioMixerDeviceInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioMixerDeviceInit_004c85d0.c

void UnknownObject::AudioMixerDeviceInit()
{
    // Initializes an audio mixer device on this: if the global mixer pointer dword_8AC4C8 is already set, or if the init-status global dword_8AC4C4 is non-null (in which case the mixer is created through the vtable+96 dispatch and its volume set through the vtable+28 dispatch with the float at flt_7CF380), then marks this+0x10 as active (1), resets the state at this+0x14 to 0, and re-applies the volume through the vtable+28 dispatch. Returns 0 when creation was not performed or failed. Called by ConditionalSoundRenderDispatchOnParamCheck, sub_485B90 and SystemOSAPICall.
    // GUARD: Short-circuit guard: proceed to the field-initialization body if the mixer pointer dword_8AC4C8 is already non-null, or if dword_8AC4C4 is non-null AND the creation/setup below leaves dword_8AC4C8 non-zero; otherwise return the result unchanged. [global:0x008AC4C8, global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Create the mixer instance: dword_8AC4C8 = (vtable+96)(dword_8AC4C4), dispatching through the vtable method pointer at offset 96 on the init-status object. [global:0x008AC4C8, global:0x008AC4C4, source:raw]
    // CALL: Set the initial volume: (vtable+28)(dword_8AC4C8, flt_7CF380), dispatching the vtable method at offset 28 on the new mixer with the float value from flt_7CF380. [global:0x008AC4C8, global:0x007CF380, source:raw]
    // ASSIGNMENT: Mark the device active: write byte 1 to this+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Reset the fade/transition state: write dword 0 to this+0x14. [field:this:0x00000014, source:raw]
    // RETURN: Re-apply the volume with (vtable+28)(dword_8AC4C8, flt_7CF380) as the return value; when the guard fails, return the previously captured result instead. [global:0x008AC4C8, global:0x007CF380, source:raw]

    // Conservative worker pseudocode:
    //   int AudioMixerDeviceInit(this) {
    //     result = dword_8AC4C8;
    //     if (dword_8AC4C8 ||
    //         dword_8AC4C4 &&
    //         (dword_8AC4C8 = (*(vtable**)dword_8AC4C4)[96](dword_8AC4C4),
    //          (*(vtable**)dword_8AC4C8)[28](dword_8AC4C8, flt_7CF380),
    //          (result = dword_8AC4C8) != 0)) {
    //       this[16] = 1;
    //       this[20] = 0;
    //       return (*(vtable**)dword_8AC4C8)[28](dword_8AC4C8, flt_7CF380);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The mixer and init-status object types, and the exact role of the vtable methods at offsets 96 and 28, are inferred only from the raw dispatch pattern.
    // UNRESOLVED: The meaning of flt_7CF380 (volume vs. some other float) and the semantics of this+0x14 as a fade/transition state are DERIVED from the analysis fill, not proven here.
    // UNRESOLVED: Why the volume dispatch runs twice on the creation path is not explained by this packet.
}
