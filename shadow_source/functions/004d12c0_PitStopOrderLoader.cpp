// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D12C0
// Canonical corpus name: PitStopOrderLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitStopOrderLoader_004d12c0.c

void UnknownObject::PitStopOrderLoader()
{
    // Loads and parses pit stop order data for teams. Gated on AudioChannelStop(aPitorder) returning nonzero. Clears the team entry count (this+0x1A8), walks the string-keyed team linked list (StringKeyedLinkedListSearch on aTeam, advancing via ShortComputation_adb0), and stores each DataEntryAccessor result into a local stack buffer. Allocates a count-strided array (OperatorNewNhMallocWrapper, entries initialized to {0, -1}) and stores the pointer in this+0x1AC (or 0 on allocation failure). Reads the reverse-pit-order setting by comparing aReversepitorde / aFalse_0; when reverse is enabled iterates teams in reverse order, otherwise forward, calling StringCopyWithBufferRealloc per entry to realloc each team string.
    // CALL: Entry gate: call AudioChannelStop(aPitorder) and use its result to decide whether to run the loader body. [callee:0x00568210, global:0x005D3A28, source:raw]
    // GUARD: Proceed with the load only when AudioChannelStop(aPitorder) returned nonzero. [callee:0x00568210, global:0x005D3A28, source:raw]
    // ASSIGNMENT: Reset the team entry count field this[106] (this+0x1A8) to 0. [field:this:0x000001A8, source:raw]
    // LOOP: Iterate the team list: seed with StringKeyedLinkedListSearch(aTeam), advance each element with ShortComputation_adb0(i) until the list is exhausted. [callee:0x005679C0, callee:0x0049ADB0, global:0x005D3A34, source:raw]
    // ASSIGNMENT: Each iteration stores DataEntryAccessor(i) into the local buffer at v13[64 + 4*count] and increments this[0x1A8]. [callee:0x00567970, field:this:0x000001A8, source:raw]
    // CALL: Allocate the team data array with OperatorNewNhMallocWrapper(8*count + 4); on success store count in the leading slot then fill count entries with the pair {0, -1}. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the allocated array pointer, or 0 on allocation failure, into this[107] (this+0x1AC). [field:this:0x000001AC, source:raw]
    // GUARD: Select iteration direction: forward order when StringCopyWithValidation(v13, 64, aReversepitorde, 0) is nonzero OR sub_588410(v13, aFalse_0) is zero; otherwise reverse order. [callee:0x004C58A0, callee:0x00588410, global:0x005D3BE0, global:0x005D3BD8, source:raw]
    // LOOP: Forward order: for j in 0..count call StringCopyWithBufferRealloc(v13[64 + 4*j]) on each stored team entry. [callee:0x00566650, source:raw]
    // LOOP: Reverse order: for k in 0..count call StringCopyWithBufferRealloc(v13[60 + 4*(count-k)]) on each stored team entry. [callee:0x00566650, source:raw]
    // RETURN: Return the final count (or the AudioChannelStop gate result when the body was skipped). [source:raw]

    // Conservative worker pseudocode:
    //   int PitStopOrderLoader(dword* this) {
    //     int result = AudioChannelStop(aPitorder);
    //     if (result) {
    //       this[106] = 0;
    //       for (i = StringKeyedLinkedListSearch(aTeam); i; i = ShortComputation_adb0(i))
    //         v13[64 + 4*this[106]++] = DataEntryAccessor(i);
    //       v10 = OperatorNewNhMallocWrapper(8*this[106] + 4);
    //       if (v10) { *v10 = this[106]; for (n = this[106]; n; --n) { v10[2*n-1] = 0; v10[2*n] = -1; } }
    //       else v10 = 0;
    //       this[107] = v10;
    //       if (StringCopyWithValidation(v13, 64, aReversepitorde, 0) || !sub_588410(v13, aFalse_0)) {
    //         for (j = 0; j < this[106]; ++j) StringCopyWithBufferRealloc(v13[64 + 4*j]);
    //       } else {
    //         for (k = 0; k < this[106]; ++k) StringCopyWithBufferRealloc(v13[60 + 4*(this[106]-k)]);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The reverse-order index v13[60 + 4*(count-k)] is offset one element back from the forward v13[64 + 4*j]; the intent of that gap is not explained by the packet.
    // UNRESOLVED: The exact element layout and runtime use of the allocated this+0x1AC array (entries initialized {0, -1}) is not described by this packet.
    // UNRESOLVED: Packets globals unk_8AC368 and dword_8AD3B4 do not appear in the raw source text; they are most likely consumed by a callee (e.g. the data-file search), which this packet does not show.
    // UNRESOLVED: AudioChannelStop is used as a gate even though its name suggests audio: the pairing with the 'pitorder' string and team loading is not fully explained.
}
