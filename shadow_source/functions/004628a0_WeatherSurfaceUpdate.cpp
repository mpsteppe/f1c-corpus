// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004628A0
// Canonical corpus name: WeatherSurfaceUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WeatherSurfaceUpdate_004628a0.c

void UnknownObject::WeatherSurfaceUpdate()
{
    // Weather surface / session UI update: initializes a description buffer via FAILWRONGDESCRIPTION, returns 0 early when UniqueID fails, then dispatches a state with argument 0, builds session config via SessionConfigBuilder, sends the buffer through BufferSendWithLocks, encodes a progress-bar event (type 4, stage 5) seeded with the session-time double dbl_8AFEA0, creates textures via TextureCreationWrapper, and issues a system OS API call on unk_7CE24D. Returns 1 on success.
    // CALL: FAILWRONGDESCRIPTION(v2) initializes or validates the description buffer v2. [callee:0x00461550, source:raw]
    // GUARD: UniqueID(v2) returns 0 for an invalid identifier; the whole update is blocked. [callee:0x004630D0, source:raw]
    // RETURN: Return 0 immediately when UniqueID reports the identifier invalid. [callee:0x004630D0, source:raw]
    // CALL: ConditionalStateDispatch(0) dispatches the current state with argument 0. [callee:0x00463760, source:raw]
    // CALL: SessionConfigBuilder(v2) builds the session configuration data from the description buffer. [callee:0x00461610, source:raw]
    // CALL: BufferSendWithLocks(dword_7CD25C, v2) sends the prepared buffer to the module manager under locks. [callee:0x00462760, global:0x007CD25C, source:raw]
    // ASSIGNMENT: Load the session time double into v1 from dbl_8AFEA0. [global:0x008AFEA0, source:raw]
    // CALL: ProgressBarEventEncode(4, 5, 0, 0, v1, 1) encodes a progress-bar event (type 4, stage 5) using the session time. [callee:0x004B33B0, source:raw]
    // CALL: TextureCreationWrapper(dword_7CD25C, v3, 2, -1, -1) creates or updates the texture resources for the weather display. [callee:0x00462250, global:0x007CD25C, source:raw]
    // CALL: SystemOSAPICall_0dc0(&unk_7CE24D) issues the OS/system API call against the transition flag global. [callee:0x004A0DC0, global:0x007CE24D, source:raw]
    // RETURN: Return 1 once the full update sequence has completed. [source:raw]

    // Conservative worker pseudocode:
    //   int WeatherSurfaceUpdate() {
    //     char desc[128]; int tex[108];
    //     FAILWRONGDESCRIPTION(desc);
    //     if (!UniqueID(desc)) return 0;
    //     ConditionalStateDispatch(0);
    //     SessionConfigBuilder(desc);
    //     BufferSendWithLocks(dword_7CD25C, desc);
    //     double t = dbl_8AFEA0;
    //     ProgressBarEventEncode(4, 5, 0, 0, (int)t, 1);
    //     TextureCreationWrapper(dword_7CD25C, tex, 2, -1, -1);
    //     SystemOSAPICall_0dc0(&unk_7CE24D);
    //     return 1;
    //   }
    // UNRESOLVED: Contents and layout of the description buffer v2 and texture array v3 are unknown.
    // UNRESOLVED: The meaning of the progress-bar event parameters (type 4, stage 5, flags) is derived only from the call site.
    // UNRESOLVED: The semantics of unk_7CE24D and how the system OS API call uses it are not explained by the raw source.
}
