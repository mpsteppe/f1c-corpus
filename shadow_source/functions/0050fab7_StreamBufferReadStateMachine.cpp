// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050FAB7
// Canonical corpus name: StreamBufferReadStateMachine
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamBufferReadStateMachine_0050fab7.c

void UnknownObject::StreamBufferReadStateMachine()
{
    // Stream buffer read state dispatcher. Sets up a state object when its discriminator is not the expected initial value, then advances a read position through a dispatch-object callback until the buffer is exhausted, at which point it signals completion through the state object vtable and returns 0.
    // GUARD: if this+0x10 != 205 the state object is not in the expected initial state, so initialize it [guard:0, field:this:0x00000010]
    // ASSIGNMENT: write state code 18 into obj+0x14 (via this+0x0) marking active processing [field:obj:0x00000014, field:this:0x00000000, source:raw]
    // ASSIGNMENT: copy the source discriminator this+0x10 into obj+0x18 for tracking [field:obj:0x00000018, field:this:0x00000010, source:raw]
    // CALL: invoke state-object vtable slot 0 (obj+0x0) with this as argument [field:obj:0x00000000, field:this:0x00000000]
    // GUARD: if read position this+0x78 < buffer size this+0x60, more data is available to read [field:this:0x00000078, field:this:0x00000060, source:raw]
    // GUARD: if secondary callback object this+0x8 is non-null, prime it with current read state [field:this:0x00000008, source:raw]
    // ASSIGNMENT: write read position this+0x78 and buffer size this+0x60 into the callback object at +4 and +8 [field:this:0x00000078, field:this:0x00000060, field:this:0x00000008, source:raw]
    // CALL: invoke callback-object vtable slot 0 (this+0x8) with this as argument [field:this:0x00000008, source:raw]
    // CALL: invoke dispatch-object vtable slot 1 (this+0x180 plus 4) with (this, a2, address of out-pointer, a3); result is returned through the out-pointer [field:this:0x00000180, source:raw]
    // ASSIGNMENT: advance read position this+0x78 by the byte count returned through the out-pointer [field:this:0x00000078, source:raw]
    // STATE_TRANSITION: buffer exhausted: set obj+0x14 = 119 (done) and invoke completion handler at obj+0x4 with (this, -1) [field:obj:0x00000014, field:obj:0x00000004, source:raw]
    // RETURN: return the out-pointer result from the read branch, or 0 from the done branch [source:raw]

    // Conservative worker pseudocode:
    //   // object prep when the discriminator is not the expected initial value
    //   if (this->discriminator != 205) {
    //       state_obj->code = 18;                 // active processing
    //       state_obj->tracked = this->discriminator;
    //       state_obj->vtable[0](this);
    //   }
    //   if (this->read_pos < this->size) {
    //       if (this->callback) {
    //           this->callback->pos = this->read_pos;
    //           this->callback->size = this->size;
    //           this->callback->vtable[0](this);
    //       }
    //       out = 0;
    //       this->dispatch->vtable[1](this, a2, &out, a3);
    //       this->read_pos += out;
    //       return out;
    //   } else {
    //       state_obj->code = 119;                // done
    //       state_obj->vtable[1](this, -1);
    //       return 0;
    //   }
    // UNRESOLVED: this+0xC is not accessed by this function; external state, purpose unknown
    // UNRESOLVED: this+0x184 is not accessed by this function; purpose unknown
    // UNRESOLVED: the callback object offsets +4 and +8 have no field evidence refs; written through the this+0x8 pointer
    // UNRESOLVED: the dispatch object vtable slot 1 writes its result through a caller-provided out-pointer; type of result (byte count) is DERIVED from the position advance
}
