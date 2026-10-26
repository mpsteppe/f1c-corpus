// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD030
// Canonical corpus name: TextRenderDispatcher
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextRenderDispatcher_004dd030.c

void UnknownObject::TextRenderDispatcher()
{
    // Renders a text string with scale, alignment and bounds-aware clipping/truncation. Copies the source text a2 into a local buffer seeded from byte_5EA438, resolves the font string a9 from this+0x28 (defaulting to byte_5EA438), persists positive scale arguments to this+0x30 and this+0x34, and reads the object anchor via TripleFieldGetter and TwinFieldGetter_cf30. A clip loop queries the text surface size via SurfaceSizeQuery, computes the aligned placement via AlignmentPositionSwitch, and truncates overflowing text left or right using an 'AbCd' per-character width heuristic. Final rendering delegates to ScaledTextureRender. Called by CollisionDamageDecayProcessor (0045B840).
    // GUARD: The whole body runs only when the source text pointer a2 is non-null [source:raw]
    // ASSIGNMENT: Initializes the local copy buffer v40 from byte_5EA438[0] then zero-fills the remaining 124 bytes [global:0x005EA438, source:raw]
    // ASSIGNMENT: Fallback chain for the font string a9: defaulted from the pointer at this+0x28, then byte_5EA438 when still null [field:this:0x00000028, global:0x005EA438, source:raw]
    // ASSIGNMENT: Scale persistence: this+0x30 is set to a7 and this+0x34 to a8 whenever the incoming scale is positive [field:this:0x00000030, field:this:0x00000034, source:raw]
    // CALL: Copies the source text into the local buffer via sub_587DD0(v40, a2, 127) [callee:0x00587DD0, source:raw]
    // CALL: Reads the object anchor fields: TripleFieldGetter and TwinFieldGetter_cf30, combined into the aligned anchor (v27, v29) and the requested draw position (v46, v47) [callee:0x004DCF50, callee:0x004DCF30, source:raw]
    // LOOP: Clip loop: SurfaceSizeQuery measures the text, AlignmentPositionSwitch computes the aligned placement, and bounds tests against the anchor either accept the placement or drive truncation [callee:0x004DC600, callee:0x004DC340, source:raw]
    // CALCULATION: Truncation: the 'AbCd' probe string measures per-character width v17; the overflowing width is derived and applied either as right truncation (terminating the tail) or left truncation (shifting the remaining text via the temporary buffer v43) [source:raw]
    // RETURN: Early returns when the text fits within the anchor bounds or truncation consumes the entire string [source:raw]
    // CALL: Final render: ScaledTextureRender(a9, v40, v46, v47, a5, a6, scale X, scale Y, 0) [callee:0x004DC660, source:raw]
    // CALL: Invoked by CollisionDamageDecayProcessor (0045B840) as a rendering side-effect [caller:0x0045B840, source:raw]

    // Conservative worker pseudocode:
    //   if (!a2) return;
    //   buf[0] = byte_5EA438[0]; memset(buf + 1, 0, 0x7C);
    //   if (!a9) { a9 = *(char**)(this + 40); if (!a9) a9 = byte_5EA438; }
    //   if (a7 > 0.0) *(float*)(this + 48) = a7;
    //   if (a8 > 0.0) *(float*)(this + 52) = a8;
    //   sub_587DD0(buf, a2, 127);
    //   TripleFieldGetter(this, &ax, &ay, 0);
    //   TwinFieldGetter_cf30(this, &bx, &by);
    //   anchorX = ax + bx; anchorY = ay + by;
    //   posX = ax + a3; posY = ay + a4;
    //   while (buf[0]) {
    //     SurfaceSizeQuery(a9, buf, &w, &h, *(float*)(this + 48), *(float*)(this + 52));
    //     AlignmentPositionSwitch(posX, posY, w, h, a6, &alX, &alY);
    //     right = alX + w; bottom = alY + h;
    //     if (alX >= ax) { if (alY >= ay && right <= anchorX && bottom <= anchorY) break; }
    //     if (alY < ay || bottom > anchorY || w <= 0) return;
    //     probe = 'AbCd'; SurfaceSizeQuery(a9, probe, &pw, &ph, scaleX, scaleY);
    //     cw = clamp(pw / 4, 1, 1000);
    //     if (alX >= ax) {
    //       over = clamp((right - anchorX) / cw, 1, 1000);
    //       if (over >= strlen(buf)) return;
    //       buf[strlen(buf) - over] = 0;
    //     } else {
    //       over = clamp((ax - alX) / cw, 1, 1000);
    //       if (over >= strlen(buf)) return;
    //       copy buf to tmp; shift tmp[over..] left over the buffer;
    //     }
    //     if (!buf[0]) return;
    //   }
    //   ScaledTextureRender(a9, buf, posX, posY, a5, a6, *(int*)(this + 48), *(int*)(this + 52), 0);
    // UNRESOLVED: flt_59E440 is flagged in the packet globals but appears nowhere in the raw decompiled source; the skeleton fill labels it ZeroThreshold
    // UNRESOLVED: dword_5D4C04 is flagged in the packet globals but appears nowhere in the raw decompiled source
    // UNRESOLVED: byte_5D4C08 is flagged in the packet globals but appears nowhere in the raw decompiled source; the skeleton fill labels it ByteFontData
    // UNRESOLVED: The local stack buffers v36/v43 and the truncation probe 'AbCd' are compiler stack artifacts; their exact relationship to font metrics is inferred, not evidenced
}
