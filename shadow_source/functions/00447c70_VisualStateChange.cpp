// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00447C70
// Canonical corpus name: VisualStateChange
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VisualStateChange_00447c70.c

void UnknownObject::VisualStateChange()
{
    // HUD visual-state transition with noise-modulated alpha/scale. When the byte at this+0x1C58 differs from the incoming state a2, it stores a2. If the HUD activation dword at this+0x1F00 is nonzero and a3 is 0, it indexes two lookup tables through a shared byte counter (dword_8AAE70, post-incremented twice): a noise table (flt_8AB274) feeds scale v8 = noise*0.1 + 1.0 and a trig table (flt_8AAE74) feeds alpha v7 = 1.0 - trig*0.15000001, then calls HUDElementConfig(40, 2, v7, v8). Returns a2 normally, or a3 on the HUD-config path.
    // GUARD: Only proceed if the byte at this+0x1C58 differs from the incoming state a2; otherwise return a2 unchanged. [field:this:0x00001C58, source:raw]
    // ASSIGNMENT: Store the new state a2 into the byte at this+0x1C58. [field:this:0x00001C58, source:raw]
    // GUARD: Only proceed if the dword at this+0x1F00 (HUD element activation flag) is nonzero. [field:this:0x00001F00, source:raw]
    // GUARD: Only proceed on the noise-modulated HUD path when a3 is 0; otherwise return a3. [source:raw]
    // ASSIGNMENT: v4 = flt_8AB274 indexed by byte value of dword_8AAE70, then dword_8AAE70 post-incremented (noise sample). [global:0x008AB274, global:0x008AAE70, source:raw]
    // ASSIGNMENT: v6 = flt_8AAE74 indexed by byte value of dword_8AAE70, then dword_8AAE70 post-incremented a second time (trig sample). [global:0x008AAE74, global:0x008AAE70, source:raw]
    // CALCULATION: Compute scale v8 = noise*0.1 + 1.0 and alpha v7 = 1.0 - trig*0.15000001. [source:raw]
    // CALL: Call HUDElementConfig with element id 40, sub-type 2, and the computed alpha v7 / scale v8; return its result. [callee:0x004F87C0, source:raw]
    // RETURN: Return result (a2 when the state byte was unchanged or the HUD flag was clear, a3 when the noise path was skipped by the a3 test). [source:raw]

    // Conservative worker pseudocode:
    //   if (*(byte*)(this+7256) == a2) return a2;
    //   *(byte*)(this+7256) = a2;
    //   if (*(dword*)(this+7936) && a3 == 0) {
    //     noise = flt_8AB274[dword_8AAE70++];
    //     trig = flt_8AAE74[dword_8AAE70++];
    //     return HUDElementConfig(40, 2, 1.0 - trig*0.15000001, noise*0.1 + 1.0);
    //   }
    //   return a3;
    // UNRESOLVED: Globals flt_59E43C, flt_59E84C, flt_59E868 are listed as read but do not appear in the raw source text; their roles here are unclear.
    // UNRESOLVED: Table semantics (noise vs trig) and the HUD element constants (id 40, sub-type 2) are DERIVED from existing analysis; the packet carries no table metadata.
}
