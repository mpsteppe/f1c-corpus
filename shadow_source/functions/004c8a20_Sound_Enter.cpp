// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8A20
// Canonical corpus name: Sound_Enter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Sound_Enter_004c8a20.c

void UnknownObject::Sound_Enter()
{
    // Sound-system entry called from Game_Enter. Conditionally logs an 'entered sound env' message, lazily initializes the sound system and its context (this), dispatches a guarded global event with the fade-alpha float, lazily checks the renderer audio component, queries two scene-graph node types, and returns 0.
    // CALL: StringSplitLoop(2, aDDevF119992002_24, 661): parse the default-device/command string; if it returns nonzero, DebugLogWrite(&dword_8AD25C, aEnteredSoundEn) writes the 'entered sound env' message. [callee:0x004D7A50, callee:0x004D7AA0, global:0x005D3398, global:0x005D3380, global:0x008AD25C, source:raw]
    // CALL: InitWithStatusCheck(): if it returns 0 (sound system not yet initialized), call sub_4C82F0() as the fallback init path. [callee:0x004C82C0, callee:0x004C82F0, source:raw]
    // CALL: sub_4C83B0(this): initialize the sound context object. [callee:0x004C83B0, source:raw]
    // CALL: LazyAudioResourceInit(): lazily initialize the audio resources. [callee:0x004C8560, source:raw]
    // CALL: GlobalDispatchWithGuard(flt_7CF380): dispatch a guarded global event with the fade-alpha float value. [callee:0x004C8900, global:0x007CF380, source:raw]
    // CALL: LazyRendererAudioInitCheck(flt_5EA618): lazily check/initialize the renderer audio component with the pointer-table value. [callee:0x004184F0, global:0x005EA618, source:raw]
    // CALL: SceneGraphQuery(0): query scene-graph node type 0 (background). [callee:0x004116C0, source:raw]
    // CALL: SceneGraphQuery(1): query scene-graph node type 1 (foreground). [callee:0x004116C0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (StringSplitLoop(2, aDDevF119992002_24, 661)) DebugLogWrite(&dword_8AD25C, aEnteredSoundEn);
    //   if (!InitWithStatusCheck()) sub_4C82F0();
    //   sub_4C83B0(this);
    //   LazyAudioResourceInit();
    //   GlobalDispatchWithGuard(flt_7CF380);
    //   LazyRendererAudioInitCheck(flt_5EA618);
    //   SceneGraphQuery(0); SceneGraphQuery(1);
    //   return 0;
    // UNRESOLVED: The constants 2 and 661 passed to StringSplitLoop come only from the raw source; their meaning is not named in the packet.
    // UNRESOLVED: flt_7CF380 and flt_5EA618 semantics come only from the raw source and the fill (RenderFadeAlpha / PointerTableEntry, both DERIVED).
    // UNRESOLVED: dword_8AD25C (DebugMessageBuffer per the fill, DERIVED) is passed as the log destination; no writer/role evidence is in the packet.
    // UNRESOLVED: No field offsets are read from this beyond passing it to sub_4C83B0, so no field evidence refs exist.
}
