// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A103
// Canonical corpus name: sub_59A103
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A103_0059a103.c

void UnknownObject::StreamGetWideCharWithLocaleConversion()
{
    // Locale-aware wide-character extraction from an input stream. Fast path: when a buffered character is available (buffer char count at +0x1C vs capacity at +0x2C) it returns the buffered code unit via StdGninc. Otherwise, with a locale format facet at +0x38 present, it drains the stream (+0x50) one byte at a time through a conversion buffer at +0x44, calling the facet's virtual format-conversion slot (vtable offset +0x10) to produce the wide code unit; on the facet's copy-back result it memcpy's 2 bytes from the buffer data pointer (+0x44 +4) when capacity (+0x44 +8) is at least 2. Without a facet it delegates to IOFormatWrapper and returns its result, mapping -1 to failure.
    // GUARD: Fast path: if the buffered char count (via +0x1C) is nonzero and strictly below count + 2 * capacity (via +0x2C), return the buffered character from StdGninc(this). [field:this:0x0000001C, field:this:0x0000002C, field:*(this+0x1C):0x00000000, field:*(this+0x2C):0x00000000, callee:0x0059A418, source:raw]
    // GUARD: If there is no input stream at +0x50 (this+80), return -1 immediately. [field:this:0x00000050, source:raw]
    // GUARD: Main conversion path only runs when a locale format facet is present at +0x38 (this+56); otherwise fall through to the IOFormatWrapper delegation. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Save the current marker: *(this+0x3C) = *(this+0x40), then truncate the conversion buffer at +0x44 via BufferTruncationShrink(buffer, 0, 0xFFFFFFFF) to reset it. [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, callee:0x00599348, source:raw]
    // LOOP: Read bytes from the input stream (+0x50) with StreamGetcWithUnderflowHandler; a return of -1 terminates the loop. [callee:0x00589FCC, field:this:0x00000050, source:raw]
    // CALL: Append each read byte to the conversion buffer at +0x44 with BufferAppendWithMemset(buffer, 1, byte). [field:this:0x00000044, callee:0x005992EF, source:raw]
    // ASSIGNMENT: Refresh the marker: *(this+0x40) = *(this+0x3C), and run BufferBoundaryMarkerCheckSet on the buffer after each byte append. [field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, callee:0x00599534, source:raw]
    // CALL: Invoke the virtual format-conversion method at vtable slot +0x10 of the facet (facet vtable pointer at +0x38, base +0), passing the buffer state (+0x3C/+0x40 markers), buffer data pointer and capacity (at +0x44 +4 / +0x44 +8) plus output slots; a zero return means the conversion succeeded. [field:*(*(this+0x38)+0x0):0x00000010, field:*(this+0x38):0x00000000, field:this:0x00000038, field:*(this+0x44):0x00000004, field:*(this+0x44):0x00000008, source:raw]
    // RETURN: On a zero return from the format-conversion callback, return the converted wide code unit v15. [source:raw]
    // GUARD: If the conversion result (callback return minus 1) is neither 0 nor 2, return -1 as an unrecognized-result failure. [source:raw]
    // GUARD: Copy-back path requires the conversion buffer capacity at +0x44 +8 to be at least 2. [guard:0, field:*(this+0x44):0x00000008, source:raw]
    // RETURN: Copy 2 bytes from the buffer data pointer (at +0x44 +4) into v15 with MemoryCopy_cc00 and return v15. [field:*(this+0x44):0x00000004, field:this:0x00000044, callee:0x0058CC00, source:raw]
    // RETURN: Loop exhaustion (stream ends before a code unit is produced) returns -1. [source:raw]
    // RETURN: Without a format facet: delegate to IOFormatWrapper(input stream at +0x50); return its result, or -1 when it returns -1. [callee:0x0059BDE9, field:this:0x00000050, source:raw]

    // Conservative worker pseudocode:
    //   if (bufferedChars(*+0x1C) && bufferedChars < bufferedChars + 2 * capacity(*+0x2C))
    //       return StdGninc(this);
    //   if (!this->stream /*+0x50* /) return -1;
    //   if (this->facet /*+0x38* /) {
    //       this->pos3C = this->pos40;
    //       BufferTruncationShrink(this->buffer /*+0x44* /, 0, 0xFFFFFFFF);
    //       for (;;) {
    //           c = StreamGetcWithUnderflowHandler(this->stream);
    //           if (c == -1) break;
    //           BufferAppendWithMemset(this->buffer, 1, c);
    //           this->pos40 = this->pos3C;
    //           BufferBoundaryMarkerCheckSet(this->buffer);
    //           r = facetVtable[+0x10](facet, this->pos3C, ...);
    //           if (!r) return wideChar;
    //           if (r != 2) return -1;
    //           if (this->buffer->capacity /*+8* / >= 2) {
    //               MemoryCopy_cc00(&wideChar, this->buffer->data /*+4* /, 2);
    //               return wideChar;
    //           }
    //       }
    //       return -1;
    //   }
    //   r = IOFormatWrapper(this->stream);
    //   return r == -1 ? -1 : r;
    // UNRESOLVED: The exact buffer-object layout behind +0x44 (data pointer at +4, capacity at +8) is DERIVED from the dword-indexed access in the raw source.
    // UNRESOLVED: Semantics of the format-conversion callback return codes (0 success, 2 copy-back) are inferred from control flow, not from a named enum.
    // UNRESOLVED: Global dword_5B9C38 is listed as read but does not appear in the raw source text of this function.
}
