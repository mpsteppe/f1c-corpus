// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005115EE
// Canonical corpus name: sub_5115EE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5115EE_005115ee.c

void UnknownObject::JpegAppDispatchTableInit()
{
    // Allocates a 92-byte JPEG APP-marker state dispatch table through an allocator vfunc reached at this+0x4, stores it at this+0x190, then fills its slots: slot 0 StateReset, slot 1 CommandDispatchStateMachine, slot 2 StateCounterWithDispatch, slot 3 StreamingDataReader, slots 4..18 default StreamingDataReader, slot 4 overridden to JPEGMarkerParsing and slot 18 to AdobePSDHeaderParser. Ends by calling StateReset on the receiver. Called from sub_50F632.
    // CALL: Calls the allocator vfunc read from *(this+4) with receiver a1 and arguments 0, 92 to obtain a new 92-byte state table [field:this:0x00000004, field:*(this+0x4):0x00000000, source:raw]
    // ASSIGNMENT: Stores the allocated table pointer at this+0x190 [field:this:0x00000190, source:raw]
    // ASSIGNMENT: Fills the first four table slots: table+0 StateReset, table+4 CommandDispatchStateMachine, table+8 StateCounterWithDispatch, table+12 StreamingDataReader [global:0x005115C4, global:0x0051126A, global:0x00511457, global:0x00511060, field:*(this+0x190):0x00000004, field:*(this+0x190):0x00000008, field:*(this+0x190):0x0000000C, source:raw]
    // LOOP: Walks table byte offsets 16 through below 80 in steps of 4, writing StreamingDataReader as the default handler into every slot [global:0x00511060, source:raw]
    // ASSIGNMENT: Overrides table+16 with JPEGMarkerParsing (APP0/JFIF marker handler) [field:*(this+0x190):0x00000010, global:0x005105BF, source:raw]
    // ASSIGNMENT: Overrides table+72 with AdobePSDHeaderParser (Adobe APP14 marker handler) [field:*(this+0x190):0x00000048, global:0x005107FB, source:raw]
    // CALL: Returns the result of StateReset invoked on the receiver; the function is itself called from sub_50F632 [callee:0x005115C4, caller:0x0050F632, source:raw]

    // Conservative worker pseudocode:
    //   table = (allocator at *(this+4))(this, 0, 92);
    //   this[0x190/4] = table;
    //   table[0x0/4] = StateReset;
    //   table[0x4/4] = CommandDispatchStateMachine;
    //   table[0x8/4] = StateCounterWithDispatch;
    //   table[0xC/4] = StreamingDataReader;
    //   for (i = 16; i < 80; i += 4)
    //     table[i/4] = StreamingDataReader;
    //   table[0x10/4] = JPEGMarkerParsing;
    //   table[0x48/4] = AdobePSDHeaderParser;
    //   return StateReset(this);
    // UNRESOLVED: The receiver object owning this+0x190 is not named in the packet; the allocator vfunc contract (arguments 0, 92) is only inferred from this call site
    // UNRESOLVED: table+0 is written with StateReset but has no dedicated packet field evidence ref, so the first slot is grounded on source and the global only
    // UNRESOLVED: Slot semantics (which APP markers route to which handler) are implied by the handler names but not proven here
}
