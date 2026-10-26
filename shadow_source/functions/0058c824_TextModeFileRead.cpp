// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C824
// Canonical corpus name: sub_58C824
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58C824_0058c824.c

void UnknownObject::TextModeFileRead()
{
    // Low-level file-read wrapper with optional text-mode newline translation, structurally a twin of sub_58AD08 (0058ad08). Reads the file handle from this+0x10, clamps the position counter at this+0x4 to non-negative, queries the cursor via sub_595F11 and returns an early cursor-delta result when the translation flags (this+0xC) do not have 0x108 set. Otherwise computes a pending byte count from the buffered range (base this+0x8 to limit this+0x0), scans for newline (10) bytes when the per-handle lowio entry (dword_8D4920) enables translation, raises TLS error 22 when the 0x80 flag is clear, and on the translation path re-queries the cursor and recounts newlines, applying an extra +1 depending on the this+0xD flag bit.
    // ASSIGNMENT: Load the file handle from this+0x10 into v2 (retained as v19). [field:this:0x00000010, source:raw]
    // GUARD: Guard: if the position counter at this+0x4 is negative, clamp it to 0. [guard:1, field:this:0x00000004, source:raw]
    // CALL: sub_595F11(handle, 0, 0, 1u) queries/advances the file cursor; the 64-bit result is retained as v18 and a negative result returns -1. [callee:0x00595F11, field:this:0x00000010, source:raw]
    // GUARD: Guard: when (flags at this+0xC) & 0x108 == 0 (no translation flags), return the cursor delta minus the position counter at this+0x4. [field:this:0x0000000C, field:this:0x00000004, source:raw]
    // CALCULATION: Pending byte count v20 = *(this+0x0) - *(this+0x8) (limit minus buffer base). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Guard: (flags at this+0xC) & 3 != 0 selects the text-translation path. [field:this:0x0000000C, source:raw]
    // GUARD: Guard: when the per-handle lowio table entry (dword_8D4920[handle >> 5] + 36 * (handle & 0x1F) + 4) marks text mode, scan the buffered bytes from this+0x8 up to the limit this+0x0 and add the newline (byte 10) count to the pending total. [global:0x008D4920, field:this:0x00000008, field:*(this+0x8):0x00000000, guard:0, field:this:0x00000000, source:raw]
    // CALL: Guard-fail path: when (flags at this+0xC) & 0x80 == 0, store error code 22 through TLSOffsetGetter() and return -1. [callee:0x0058AFCF, field:this:0x0000000C, source:raw]
    // GUARD: Guard: when the full 64-bit cursor result is zero, return the pending count v20 (end of data). [source:raw]
    // GUARD: Guard: when the low bit of the flags at this+0xC is set and the position counter at this+0x4 is non-zero, compute the adjusted byte count v21 = position + limit - buffer base. [field:this:0x0000000C, field:this:0x00000004, field:this:0x00000000, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Record whether flag bit 0x20 of the byte at this+0xD is clear (v15), which drives whether the pending count is incremented by one on the translation path. [field:this:0x0000000D, source:raw]
    // CALL: When text translation is enabled for this handle, re-query via sub_595F11(handle, 0, 0, 2u); on a match recount newline (10) bytes over the buffered range from this+0x8, otherwise reposition the cursor with sub_595F11(handle, v18 low, v18 high, 0). [callee:0x00595F11, global:0x008D4920, field:this:0x00000008, field:*(this+0x8):0x00000000, source:raw]
    // CALL: Invoked by FileIOThreeStepSequence (0058C7FC) and FileSeekWithModeFlagValidation (0059C156) in the file I/O sequence. [caller:0x0058C7FC, caller:0x0059C156]
    // UNRESOLVED: The packet's raw-source excerpt is truncated at 'v16 = ...'; the tail of the function (fallback byte-count source at this+0x18, the final subtraction, the zero-out branch and the return computation) is not evidenced here.
    // UNRESOLVED: sub_595F11's exact semantics for modes 0, 1 and 2 (query vs reposition) are not established from this packet.
}
