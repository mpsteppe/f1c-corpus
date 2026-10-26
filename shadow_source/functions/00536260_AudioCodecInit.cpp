// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536260
// Canonical corpus name: sub_536260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_536260_00536260.c

void UnknownObject::AudioCodecInit()
{
    // Initializes an audio codec context. Computes the internal buffer size as twice the parameter field (this+0x22), zeroes the buffer at this+0x3A except its last word, then loads four codec configuration words (word_5B77E8/EA/EC/EE) indexed by the codec type at this+0x7A (times 6) into fields this+0x82/0x76/0x86/0x72. Clears state counters and flags, sets two fields to the literal 2, and returns 2. Called from ConditionalMultiFieldReset (0x00535E10).
    // ASSIGNMENT: Write this+0x32 = 2 * this[0x22]; the buffer size is derived from the parameter field [field:this:0x00000022, field:this:0x00000032, source:raw]
    // CALL: memset the buffer at this+0x3A to zero for 2*this[0x42]-2 bytes, leaving only the final 2-byte word untouched [field:this:0x0000003A, field:this:0x00000042, source:raw]
    // ASSIGNMENT: Write 0 to the last 2-byte word of the buffer, at address this+0x3A + 2*this[0x42] - 2 [field:this:0x0000003A, field:this:0x00000042, source:raw]
    // CALCULATION: Compute the lookup index v4 = 6 * this[0x7A], treating the codec type field as the row selector into 6-byte codec entries [field:this:0x0000007A, source:raw]
    // ASSIGNMENT: Store this+0x76 = (unsigned short)word_5B77EA[v4], the codec decode-tab size from the lookup table [field:this:0x00000076, global:0x005B77EA, source:raw]
    // ASSIGNMENT: Store this+0x82 = (unsigned short)word_5B77E8[v4], a codec decode parameter from the lookup table [field:this:0x00000082, global:0x005B77E8, source:raw]
    // ASSIGNMENT: Store this+0x86 = (unsigned short)word_5B77EC[v4], a codec decode parameter from the lookup table [field:this:0x00000086, global:0x005B77EC, source:raw]
    // ASSIGNMENT: Store this+0x72 = (unsigned short)word_5B77EE[v4], the codec mode tag from the lookup table [field:this:0x00000072, global:0x005B77EE, source:raw]
    // ASSIGNMENT: Clear state counters: this+0x62, this+0x52 and this+0x6A are all set to 0 [field:this:0x00000052, field:this:0x00000062, field:this:0x0000006A, source:raw]
    // ASSIGNMENT: Clear state flags: this+0x5E and this+0x3E are both set to 0 [field:this:0x0000003E, field:this:0x0000005E, source:raw]
    // ASSIGNMENT: Set channel/format fields: this+0x6E and this+0x56 are both set to the literal 2 [field:this:0x00000056, field:this:0x0000006E, source:raw]
    // RETURN: Return the literal 2, the initializer's success marker; invoked by ConditionalMultiFieldReset (0x00535E10) [function:0x00536260, caller:0x00535E10, source:raw]

    // Conservative worker pseudocode:
    //   this[0x32] = 2 * this[0x22];
    //   memset(this[0x3A], 0, 2 * this[0x42] - 2);
    //   *(word*)(this[0x3A] + 2*this[0x42] - 2) = 0;
    //   idx = 6 * this[0x7A];
    //   this[0x76] = word_5B77EA[idx];
    //   this[0x82] = word_5B77E8[idx];
    //   this[0x86] = word_5B77EC[idx];
    //   this[0x72] = word_5B77EE[idx];
    //   this[0x62] = this[0x52] = this[0x6A] = 0;
    //   this[0x5E] = this[0x3E] = 0;
    //   this[0x6E] = this[0x56] = 2;
    //   return 2;
    // UNRESOLVED: The exact meaning of the two fields forced to 2 (this+0x6E, this+0x56) is not established by this packet; the skeleton fill calls the object an audio codec context, which is DERIVED
    // UNRESOLVED: The codec lookup tables word_5B77E8/EA/EC/EE carry no per-entry semantic in this packet beyond the naming in the skeleton fill
    // UNRESOLVED: The memset is a CRT call with no callgraph entry, so no callee evidence reference exists for it
}
