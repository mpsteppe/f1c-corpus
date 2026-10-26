// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411A50
// Canonical corpus name: ShortComputation_1a50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1a50_00411a50.c

void UnknownObject::GlyphCircularBufferIndexIncrement()
{
    // Dispatch over a word index a2 into a circular buffer owned by this. Values within 0..0x218 advance the buffer via CircularBufferIndexIncrement at this[2*a2], except reserved sentinel indexes (0, 397, 291, 292, 426, 536) that return 0 or -1 without advancing. Values above 0x218 return 0. Called from FontRenderingPrep, so a2 is likely a glyph/font slot index with reserved holes.
    // GUARD: result = 0; if ((unsigned)a2 > 0x218) return 0 (index out of range) [source:raw]
    // GUARD: a2 == 426 or a2 == 536: v3 true, falls to LABEL_12 and returns -1 without advancing [source:raw]
    // GUARD: a2 == 397: return 0 without advancing [source:raw]
    // GUARD: a2 in [291,292]: return -1 without advancing [source:raw]
    // GUARD: a2 == 0: v3 true, falls to LABEL_12 and returns -1 without advancing [source:raw]
    // CALL: otherwise: return CircularBufferIndexIncrement(&this[2 * a2]) to advance the buffer slot [source:raw, callee:0x00411650]
    // RETURN: return the incremented index, or sentinel 0/-1 for reserved indexes [source:raw]

    // Conservative worker pseudocode:
    //   unsigned short GlyphCircularBufferIndexIncrement(unsigned short* this, int idx) {
    //     if ((unsigned)idx > 0x218) return 0;
    //     if (idx == 397) return 0;
    //     if (idx == 291 || idx == 292 || idx == 426 || idx == 536 || idx == 0) return -1;
    //     return CircularBufferIndexIncrement(&this[2 * idx]);
    //   }
    // UNRESOLVED: Exact semantic of sentinel indexes (reserved glyphs vs invalid slots) not established
    // UNRESOLVED: Buffer element size and stride at this[2*a2] are not evidenced in the packet
}
