// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051126A
// Canonical corpus name: CommandDispatchStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CommandDispatchStateMachine_0051126a.c

void UnknownObject::CommandDispatchStateMachine()
{
    // Main JPEG marker parsing dispatcher. While the current marker slot a1[94] (offset this+0x178) is non-zero it dispatches on the marker value: markers 192..204 and 1 route through ImageFormatStreamDecoder, sub_510975, or sub_510ACC; markers 205..207, 197..200 and 195 route to the error dispatch (state code 59 via obj vfunc0); markers 1 and 208..215 route to the parameterized dispatch (state code 91 via obj vfunc1); 216 (SOI) calls sub_50FF84; 217 sets state code 84 via obj vfunc1 and returns 2; 219 calls MP3HuffmanDecoder; 220/221 call StreamingDataReader / StreamRead2ByteTokenParser; 224..239 (APP) dispatch through a function table at this+0x190; 254 (COM) dispatches through the handler at *(this+0x190+12) (this+0x19C); unrecognized markers write state code 67 and dispatch through obj vfunc0. When a1[94] is zero the next marker is read through BitstreamTokenReader or JPEGMarkerReader selected by the byte-stuffing flag at *(this+0x190+0x50). The marker slot is reset to 0 after every dispatch.
    // CALL: Read the next marker when the marker slot a1[94] is zero: select BitstreamTokenReader when the byte-stuffing flag byte at *(a1[100]+80) is set, otherwise JPEGMarkerReader [field:this:0x00000178, field:this:0x00000190, field:this:0x000001E0, callee:0x005110FC, callee:0x005111D3, source:raw]
    // RETURN: Return 0 when the marker reader returns 0 [source:raw]
    // GUARD: Branch on the current marker value a1[94]: values above 207 leave the inner loop for the high-marker dispatch block [field:this:0x00000178, source:raw]
    // STATE_TRANSITION: Error dispatch for markers 205..207, 197..200 and 195: write state code 59 to obj+0x14, the marker to obj+0x18, and dispatch through obj vtable slot 0 [field:this:0x00000000, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000178, source:raw]
    // CALL: Marker 202 dispatches to ImageFormatStreamDecoder(1, this, 1) and marker 204 to sub_510975 [field:this:0x00000178, callee:0x00510012, callee:0x00510975, source:raw]
    // CALL: Markers 192 and 193 dispatch to ImageFormatStreamDecoder(0, this, 0) and marker 201 to ImageFormatStreamDecoder(0, this, 1) [field:this:0x00000178, callee:0x00510012, source:raw]
    // CALL: Marker 194 dispatches to ImageFormatStreamDecoder(1, this, 0) and marker 196 to sub_510ACC [field:this:0x00000178, callee:0x00510012, callee:0x00510ACC, source:raw]
    // GUARD: Return 0 when the selected per-marker parser returns 0 [source:raw]
    // ASSIGNMENT: Reset the marker slot a1[94] to 0 after each dispatch, forcing a new marker read on the next loop iteration [field:this:0x00000178, source:raw]
    // CALL: High markers 220 and 221 dispatch to StreamingDataReader and StreamRead2ByteTokenParser, and marker 219 to MP3HuffmanDecoder [field:this:0x00000178, callee:0x00511060, callee:0x00510F89, callee:0x00510D60, source:raw]
    // CALL: APP markers 224..239 dispatch through the function table at this+0x190 indexed by (4*marker - 880), and marker 254 (COM) dispatches through the handler pointer at *(this+0x190+12) (this+0x19C) [field:this:0x00000178, field:this:0x00000190, field:this:0x0000019C, source:raw]
    // CALL: Marker 216 (SOI) dispatches to sub_50FF84 for context initialization [field:this:0x00000178, callee:0x0050FF84, source:raw]
    // STATE_TRANSITION: Markers 1 and 208..215 use the parameterized dispatch: write state code 91 to obj+0x14, the marker to obj+0x18, and dispatch through obj vtable slot 1 with argument 1 [field:this:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000178, source:raw]
    // STATE_TRANSITION: Marker 217 writes state code 84 to obj+0x14, dispatches through obj vtable slot 1 with argument 1, and returns 2 [field:this:0x00000000, field:obj:0x00000004, field:obj:0x00000014, field:this:0x00000178, source:raw]
    // CALL: Remaining markers in the 208..218 range (default path) dispatch to sub_51030D; a non-zero result returns 1, otherwise 0 [field:this:0x00000178, callee:0x0051030D, source:raw]
    // STATE_TRANSITION: Unrecognized markers (2..191, 222/223, 240..253, 255): write state code 67 to obj+0x14, the marker to obj+0x18, and dispatch through obj vtable slot 0 [field:this:0x00000000, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000178, source:raw]

    // Conservative worker pseudocode:
    //   for (;;) {
    //     if (this[94] == 0) {
    //       if (!(*(*(this[100]+80)) ? BitstreamTokenReader(this) : JPEGMarkerReader(this))) return 0;
    //     }
    //     marker = this[94];
    //     if (marker > 207) break;
    //     if (marker >= 205 || (marker >= 197 && marker <= 200) || marker == 195) goto error_59;
    //     if (marker > 200) {
    //       if (marker == 201) flag = 1;
    //       else if (marker == 202) r = ImageFormatStreamDecoder(1, this, 1);
    //       else if (marker == 204) r = sub_510975(this);
    //       else goto error_59;
    //     } else {
    //       if (marker == 1 || (marker >= 208 && marker <= 215)) goto dispatch_91;
    //       if (marker <= 191) goto error_67;
    //       if (marker == 192 || marker == 193) r = ImageFormatStreamDecoder(0, this, 0);
    //       else if (marker == 194) r = ImageFormatStreamDecoder(1, this, 0);
    //       else if (marker == 196) r = sub_510ACC(this);
    //       else goto error_59;
    //     }
    //     if (marker == 201) r = ImageFormatStreamDecoder(0, this, 1);
    //     if (r == 0) return 0;
    //     this[94] = 0;
    //     continue;
    //   error_59:
    //     (*this)[5] = 59; (*this)[6] = marker; (*(**this))(this); this[94] = 0; continue;
    //   error_67:
    //     (*this)[5] = 67; (*this)[6] = marker; (*(**this))(this); this[94] = 0; continue;
    //   dispatch_91:
    //     (*this)[5] = 91; (*this)[6] = marker; (*(*this+4))(this, 1); this[94] = 0; continue;
    //   }
    //   if (marker > 219) {
    //     if (marker == 220) r = StreamingDataReader(this);
    //     else if (marker == 221) r = StreamRead2ByteTokenParser(this);
    //     else if (marker > 223 && marker <= 239) r = (*(this[100] + 4*marker - 880))(this);
    //     else if (marker == 254) r = (*(this[100] + 12))(this);
    //     else goto error_67;
    //   } else if (marker == 219) {
    //     r = MP3HuffmanDecoder(this);
    //   } else if (marker <= 215) {
    //     goto dispatch_91;
    //   } else if (marker == 216) {
    //     r = sub_50FF84(this);
    //   } else if (marker == 217) {
    //     (*this)[5] = 84; (*(*this+4))(this, 1); this[94] = 0; return 2;
    //   } else {
    //     if (sub_51030D(this)) { this[94] = 0; return 1; }
    //     return 0;
    //   }
    //   if (r == 0) return 0;
    //   this[94] = 0;
    // UNRESOLVED: The dispatch-table walk for markers 224..239 at (this[100] + 4*marker - 880) references table entries not statically known from this packet; the table content and per-APP-handler behavior are unresolved
    // UNRESOLVED: Marker 217 returns 2 while marker 1 / 208..215 path returns through the outer loop; the return-value contract (0/1/2) across callers is not established here
    // UNRESOLVED: The reader-config object at this+0x190 also serves as the dispatch base and byte-stuffing flag holder; whether it is a dedicated config struct or a shared context is unresolved
    // UNRESOLVED: The marker-distance arithmetic (201..205) leaves the 204-to-sub_510975 and 205-or-above-to-error routes overlapping in a way that suggests the decompiler structure, not clearly distinct semantic states
}
