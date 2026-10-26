// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1CF0
// Canonical corpus name: RingBufferAccessWithWrap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RingBufferAccessWithWrap_004d1cf0.c

void UnknownObject::RingBufferAccessWithWrap()
{
    // Maps a float index a2 onto a ring buffer: truncates a2 * this[264] - 1, wraps a negative raw index by adding buffer size this[268], clamps into [0, this[268]-1], and reads the 8-byte-stride element at this[272]. Used by AIAbility and ShortComputation_bad0 on the per-frame path.
    // CALCULATION: v3 = CRTFtol(a2 * *(float *)(this + 264)) - 1; scale float index by this+0x108 and truncate [callee:0x00587BDC, field:this:0x00000108, function:0x004D1CF0, source:raw]
    // GUARD: if (v3 < 0) v3 += *(_DWORD *)(this + 268); wrap by adding buffer size this+0x10C [field:this:0x0000010C, function:0x004D1CF0, source:raw]
    // CALCULATION: v4 = *(_DWORD *)(this + 268) - 1; maximum valid index [field:this:0x0000010C, function:0x004D1CF0, source:raw]
    // GUARD: if (v3 < 0) return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * 0); still negative after wrap -> clamp to index 0 [field:this:0x00000110, function:0x004D1CF0, source:raw]
    // GUARD: if (v3 <= v4) return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v3); in-range element read at 8-byte stride [field:this:0x00000110, function:0x004D1CF0, source:raw]
    // RETURN: return *(_DWORD *)(*(_DWORD *)(this + 272) + 8 * v4); index above max -> clamp to size-1 [field:this:0x00000110, function:0x004D1CF0, source:raw]

    // Conservative worker pseudocode:
    //   v3 = CRTFtol(a2 * this->scale_0x108) - 1;
    //   if (v3 < 0) v3 += this->size_0x10C;
    //   v4 = this->size_0x10C - 1;
    //   if (v3 < 0) v3 = 0;
    //   if (v3 > v4) v3 = v4;
    //   return *(DWORD *)(this->buffer_0x110 + 8 * v3);
    // UNRESOLVED: elements are 8-byte stride but only the first DWORD at +0 is returned; the second word at +4 is ignored by this accessor
    // UNRESOLVED: this+0x108 scaling factor and this+0x10C size semantics inferred from ring-buffer role; no structural confirmation
}
