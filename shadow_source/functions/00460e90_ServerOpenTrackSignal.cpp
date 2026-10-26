// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00460E90
// Canonical corpus name: ServerOpenTrackSignal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ServerOpenTrackSignal_00460e90.c

void UnknownObject::ServerOpenTrackSignal()
{
    // Server-side open-track signal handler: emits a progress event, fetches a COM object from the object at this+0x3FB8, marks and dispatches it over the network, sets an open-track flag byte, allocates an 8-byte string buffer filled with the opening track name, then appends a track-info node to a per-this linked list when the photo/free-camera mode flag (dword_7D0398) is set; otherwise it frees the temporary buffer. An optional debug log fires when a source-dev split condition holds.
    // CALL: ProgressBarEventEncode(4, 38, 0, 255, low32(dbl_8AFEA0), 1) emits a progress/loading event using the global double value. [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // CALL: COMVTableCallVia0x60(*(this+0x3FB8)) retrieves a COM object v2 from the interface stored in this+0x3FB8. [callee:0x0057A680, field:this:0x00003FB8, source:raw]
    // ASSIGNMENT: Set byte at v2+4 to 1, marking the COM object's open-track state. [source:raw]
    // CALL: NetworkSendDispatch(v10, ((v10[0]>>8)&0x3FF)+8, v2, 1, 1, -1, 0) dispatches a network packet referencing the COM object with the buffer size derived from v10[0]. [callee:0x0057A6A0, source:raw]
    // CALL: VirtualMethodDispatch(*(this+0x3FB8), v2) forwards the COM object to the stored interface dispatch. [callee:0x0057A690, field:this:0x00003FB8, source:raw]
    // ASSIGNMENT: Set open-track flag byte *(this+0x29) to 1. [field:this:0x00000029, source:raw]
    // CALL: OperatorNewNhMallocWrapper(8) allocates an 8-byte string buffer v4; when non-null initialize v4[0]=0 and v4[1]=-1. [callee:0x00587C03, source:raw]
    // CALL: StringCopyWithBufferRealloc(aOpening) loads the opening track name string into the reallocating string buffer. [callee:0x00566650, global:0x005C60E8, source:raw]
    // CALL: TrackNameReader(v9, 63) reads the current track name into a 64-byte stack buffer. [callee:0x004C5920, source:raw]
    // CALL: sub_5665B0(v9) processes or normalizes the read track name. [callee:0x005665B0, source:raw]
    // GUARD: Guard: dword_7C569C != 5 and StringSplitLoop(1, aDDevF119992002_1, 4833) selects the debug-log branch based on the source-dev path token and the split condition. [global:0x007C569C, callee:0x004D7A50, global:0x005C5CE4, source:raw]
    // CALL: DebugLogWrite(&dword_8AD25C, v5) logs the buffer contents; v5 is *v4, falling back to byte_5EA438 when v4 is null. [callee:0x004D7AA0, global:0x008AD25C, global:0x005EA438, source:raw]
    // GUARD: Guard on dword_7D0398 (photo/free-camera mode flag): when non-zero append the track-info node to the linked list; when zero and the buffer exists, free it. [global:0x007D0398, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a 12-byte linked-list node v7; when non-null initialize *v7=v4 (buffer pointer), *(v7+4)=0, *(v7+8)=0. [callee:0x00587C03, source:raw]
    // GUARD: Guard: *(this+0x1B770) head pointer decides between appending to an existing list tail and creating the first node. [field:this:0x0001B770, source:raw]
    // ASSIGNMENT: Append node: when a head exists, tail next *(*(this+0x1B774)+4)=v7; otherwise set head *(this+0x1B770) and end *(this+0x1B778) to v7; then set tail *(this+0x1B774)=v7. [field:this:0x0001B770, field:this:0x0001B774, field:this:0x0001B778, field:*(this+0x1B774):0x00000004, source:raw]
    // ASSIGNMENT: Increment the linked-list node count *(this+0x1B77C). [field:this:0x0001B77C, source:raw]
    // CALL: Else branch (dword_7D0398 zero and v4 non-null): FreeWrapper_7bcf(*v4) frees the inner buffer, then FreeWrapper_7bcf(v4) frees the outer allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return the updated node count, or the free result on the early-out path. [source:raw]

    // Conservative worker pseudocode:
    //   int ServerOpenTrackSignal(ServerSession* this) {
    //     ProgressBarEventEncode(4, 38, 0, 255, (int)dbl_8AFEA0, 1);
    //     int obj = COMVTableCallVia0x60(*(this + 0x3FB8));
    //     *(byte*)(obj + 4) = 1;
    //     NetworkSendDispatch(pkt, ((pkt[0] >> 8) & 0x3FF) + 8, obj, 1, 1, -1, 0);
    //     VirtualMethodDispatch(*(this + 0x3FB8), obj);
    //     *(byte*)(this + 0x29) = 1;
    //     char* buf = (char*)OperatorNewNhMallocWrapper(8);
    //     if (buf) { *(char**)buf = 0; ((char**)buf)[1] = (char*)-1; }
    //     StringCopyWithBufferRealloc(aOpening);
    //     TrackNameReader(name, 63); sub_5665B0(name);
    //     if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_1, 4833))
    //       DebugLogWrite(&dword_8AD25C, buf ? *(char**)buf : byte_5EA438);
    //     if (dword_7D0398) {
    //       if (buf) {
    //         TrackNode* node = (TrackNode*)OperatorNewNhMallocWrapper(12);
    //         if (node) { node->buffer = buf; node->next = 0; node->flags = 0; }
    //         if (*(this + 0x1B770)) *(*(this + 0x1B774) + 4) = node;
    //         else { *(this + 0x1B770) = node; *(this + 0x1B778) = node; }
    //         *(this + 0x1B774) = node;
    //         ++*(int*)(this + 0x1B77C);
    //       }
    //     } else if (buf) {
    //       if (*(char**)buf) FreeWrapper_7bcf(*(char**)buf);
    //       return FreeWrapper_7bcf(buf);
    //     }
    //     return *(int*)(this + 0x1B77C);
    //   }
    // UNRESOLVED: Object identity of this (a server/session object) is unknown; owner left UNKNOWN.
    // UNRESOLVED: Meaning of the byte set at obj+4 and the network packet layout built from v10 is not grounded here.
    // UNRESOLVED: unk_8AC368 is listed as a read global in the packet but has no direct reference in the raw source; its role is unplaced.
}
