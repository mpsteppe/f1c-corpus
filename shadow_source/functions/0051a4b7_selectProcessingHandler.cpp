// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051A4B7
// Canonical corpus name: ProtocolStateHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProtocolStateHandler_0051a4b7.c

void UnknownObject::selectProcessingHandler()
{
    // Selects a processing handler on a per-frame basis. Loads the handler state object pointer from this+0x184; when its enable flag (offset 16) is set, chooses AudioSubbandSynthesisFilterbank when the byte at this+0x49 is nonzero and RenderStateCopyWithValidation(this) succeeds, otherwise falls back to DrawableObjectBatchProcessor, storing the chosen handler function into the state slot at offset 12. Unconditionally zeroes the position counter at this+0x88.
    // ASSIGNMENT: Load the handler state object pointer into v1 from this+0x184. [field:this:0x00000184, source:raw]
    // GUARD: Guard on the enable flag at v1+16 (offset 16 of the handler state): only a nonzero flag proceeds to handler selection. [field:*(this+0x184):0x00000010, source:raw]
    // CALL: Invoke RenderStateCopyWithValidation(this); a nonzero return is required on the audio-handler path. [callee:0x00519EB7, source:raw]
    // GUARD: Guard combining the byte at this+0x49 with the RenderStateCopyWithValidation result: both must hold to select the audio handler. [field:this:0x00000049, callee:0x00519EB7, source:raw]
    // ASSIGNMENT: Write AudioSubbandSynthesisFilterbank (0x00519F9A) into the handler slot at v1+12 (state offset 12). [global:0x00519F9A, field:*(this+0x184):0x0000000C, source:raw]
    // ASSIGNMENT: Write DrawableObjectBatchProcessor (0x00519D51) into the handler slot at v1+12 as the default fallback. [global:0x00519D51, field:*(this+0x184):0x0000000C, source:raw]
    // ASSIGNMENT: Zero the position counter at this+0x88 unconditionally. [field:this:0x00000088, source:raw]

    // Conservative worker pseudocode:
    //   v1 = *(this + 0x184);
    //   if (*(v1 + 16)) {
    //     if (*(byte*)(this + 0x49) && RenderStateCopyWithValidation(this))
    //       *(v1 + 12) = AudioSubbandSynthesisFilterbank;
    //     else
    //       *(v1 + 12) = DrawableObjectBatchProcessor;
    //   }
    //   *(this + 0x88) = 0;
    // UNRESOLVED: The handler-state object type at this+0x184 and the semantics of the two handler targets are not identified by packet evidence.
    // UNRESOLVED: Why the byte at this+0x49 gates the audio path (render-state validity flag versus mode flag) is not established.
}
