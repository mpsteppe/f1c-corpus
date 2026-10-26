// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00510ACC
// Canonical corpus name: sub_510ACC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_510ACC_00510acc.c

void UnknownObject::ParseJpegHuffmanTable()
{
    // JPEG Huffman table (DHT) parser driven by a refillable byte stream. Reads a two-byte segment length via the stream struct at this+0x14 (this+0: buffer read pointer, +4: bytes remaining, +12: refill callback), then for each table in the segment: reads the table-id byte, dispatches state 79 with (this,1), reads 16 code-length count bytes, stores them in two batches at obj+0x18 (state 85, dispatch arg 2 each), validates the total symbol count against 256 and the remaining segment length (state 28 on overflow), reads that many symbol bytes into a local 256-byte buffer, selects a table slot from the this+0x70/0xA0-area slot arrays using the table-id bits (state 29 on out-of-range id), lazily allocates the slot buffer via BufferAccessNullTerminate, writes the 17-byte header (zero pad byte + 16 counts) followed by the 256 symbol bytes, and finally writes the updated stream read pointer and remaining count back into the stream struct.
    // ASSIGNMENT: Load stream state: v1 = this+0x14, buffer read pointer from stream+0 and bytes remaining from stream+4; if the buffer is empty, call the refill callback at stream+12 and abort with 0 on failure [field:this:0x00000014, field:*(this+0x14):0x00000000, source:raw]
    // CALCULATION: Consume two bytes and build the remaining-length counter: v32 = (first_byte << 8) + second_byte - 2, i.e. the two-byte segment length field minus the two length bytes themselves [field:*(this+0x14):0x00000000, source:raw]
    // LOOP: Per-table loop while the remaining segment length v32 is greater than 0; each iteration refills the stream buffer through the callback at stream+12 whenever v34 reaches zero [field:*(this+0x14):0x00000000, source:raw]
    // ASSIGNMENT: Read the table-id byte, set the state code at obj+0x14 to 79, store the id value at obj+0x18, and dispatch through the parameterized vtable entry obj+0x4 with (this, 1) [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000004, field:this:0x00000000, source:raw]
    // LOOP: Inner loop reading 16 code-length count bytes into the local header storage, accumulating their sum into v30 (the total symbol count) [field:*(this+0x14):0x00000000, source:raw]
    // ASSIGNMENT: Write the count bytes to the obj+0x18 value window in two batches (four words each), raising the state code to 85 and dispatching through obj+0x4 with (this, 2) after each batch [field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, field:obj:0x00000024, field:obj:0x00000028, field:obj:0x0000002C, field:obj:0x00000030, field:obj:0x00000034, field:obj:0x00000014, field:obj:0x00000004, source:raw]
    // GUARD: When the accumulated symbol count v30 exceeds 256 or the remaining segment length v32, set the state code to 28 and dispatch through the no-arg vtable entry obj+0x0 (size error) [field:obj:0x00000014, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // LOOP: Read v30 symbol bytes from the stream into the local 256-byte buffer, decrementing the segment counter and refilling through the callback as needed [field:*(this+0x14):0x00000000, source:raw]
    // CALCULATION: Select the table slot: when the table id has bit 0x10 set, the slot pointer is derived from &this + 28 table slots (v23-16 selector), otherwise from &this + 40 table slots; out-of-range ids set the state to 29, store the selector at obj+0x18 and dispatch through obj+0x0 [field:obj:0x00000014, field:obj:0x00000018, field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALL: Lazily allocate the slot buffer when the slot pointer is null by calling BufferAccessNullTerminate(this) [callee:0x00516990, source:raw]
    // ASSIGNMENT: Write the 17-byte table header (zero pad byte + the 16 count bytes) at the start of the slot buffer, then copy the 256 symbol bytes to slot+17 via qmemcpy [source:raw]
    // ASSIGNMENT: Persist the advanced stream read pointer and remaining count back into the stream struct (stream+0 and stream+4), then continue the segment loop [field:*(this+0x14):0x00000000, source:raw]
    // RETURN: Return 1 on success, or 0 early when a stream refill callback fails; invoked by CommandDispatchStateMachine (0051126a) [function:0x00510ACC, caller:0x0051126A, source:raw]

    // Conservative worker pseudocode:
    //   stream = this+0x14;
    //   buf = *stream; remaining = *(stream+4);
    //   if (!remaining && !refill(stream+12, this)) return 0;
    //   len = (byte(buf[0]) << 8) | byte(buf[1]);
    //   v32 = len - 2; buf += 2; remaining -= 2;
    //   while (v32 > 0) {
    //     id = read_byte(refill);
    //     dispatcher->state = 79; *(dispatcher+0x18) = id; dispatcher->dispatch(this, 1);
    //     total = 0;
    //     for (i = 1; i <= 16; ++i) { cnt[i] = read_byte(refill); total += cnt[i]; }
    //     store counts to dispatcher+0x18 in two batches;
    //     dispatcher->state = 85; dispatcher->dispatch(this, 2); (x2)
    //     if (total > 256 || total > v32) { dispatcher->state = 28; dispatcher->dispatch0(this); }
    //     for (i = 0; i < total; ++i) symbols[i] = read_byte(refill);
    //     v32 -= 17 + total;
    //     slot = (id & 0x10) ? &this[28+id-16] : &this[40+id];
    //     if (id_selector >= 4) { dispatcher->state = 29; *(dispatcher+0x18) = id_selector; dispatcher->dispatch0(this); }
    //     if (!*slot) *slot = BufferAccessNullTerminate(this);
    //     write 17-byte header (0 pad + 16 counts) to *slot;
    //     qmemcpy(*slot + 17, symbols, 256);
    //   }
    //   *(stream+4) = remaining; *stream = buf;
    //   return 1;
    // UNRESOLVED: The slot table offsets derived from &this[28+...] and &this[40+...] are computed from DWORD-indexed this arithmetic and have no packet field references
    // UNRESOLVED: The byte-order mapping between the local count-byte storage (v25..v29) and the two obj+0x18 write batches is ambiguous from the decompiler output; the header writes are described at batch granularity
    // UNRESOLVED: field:this:0x00000018 and field:this:0x00000020 are declared RW in the packet facts but appear nowhere in the raw decompiled source
}
