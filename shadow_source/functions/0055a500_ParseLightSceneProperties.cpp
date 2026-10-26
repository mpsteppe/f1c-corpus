// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055A500
// Canonical corpus name: sub_55A500
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55A500_0055a500.c

void UnknownObject::ParseLightSceneProperties()
{
    // __thiscall scene-file light parser. Reads lines from the scene buffer a3 via LineReaderFromBuffer; on each non-comment line it fetches the Type token and parses View, Dir, Color, Range, Intensity and Active values with the PRNG/float helpers. Maps the Type string to a light kind code v7 (Directional=1, StaticOmni=4, MovingOmni=2), creates the scene node via sub_545430 (returns -1 on failure), applies the parsed values through directional or omnidirectional setter paths, then pushes color/intensity into UI property slots and toggles the Active flag. Returns 0 on success.
    // ASSIGNMENT: Initialize parser state: v7 (light kind code) = 0, v4 (active flag, default true) = 1, all output locals zeroed, default range v11 = 1120403456, default intensity v18[0] = 1.0. [source:raw]
    // ASSIGNMENT: Store the this pointer into the stack scratch slot v18[1] (LODWORD(v18[1]) = this); decompiler artifact reused as a float slot later. [source:raw]
    // LOOP: Loop while LineReaderFromBuffer(v3) != 1, i.e. until the line reader signals no more lines. [callee:0x00559A70, source:raw]
    // GUARD: Break out of the read loop when the token type at *v3 equals 3; skip the token block when *v3 equals 2. [source:raw]
    // CALL: Fetch the Type token string into v20 via sub_559E20(v3, aType, v20, 0). [callee:0x00559E20, global:0x005DC274, source:raw]
    // CALL: Parse four float values for the View entry off_5DC230 into v10/v9/v8 via PRNG4UniformFloatsFromSeed. [callee:0x00559FB0, global:0x005DC230, source:raw]
    // CALL: Parse the Dir (direction) floats into v14/v13/v12 via PRNG4UniformFloatsFromSeed(v3, aDir, ...). [callee:0x00559FB0, global:0x005DC224, source:raw]
    // CALL: Parse the Color token into packed integer slots v15/v16/v17 via sub_559F00(v3, aColor, ...). [callee:0x00559F00, global:0x005C57F4, source:raw]
    // CALL: Parse the Range token into v19 and v11 via PRNG4UniformFloatsFromSeed(v3, aRange, ...). [callee:0x00559FB0, global:0x005DC26C, source:raw]
    // CALL: Parse the Intensity token into v18 via PRNG4UniformFloatsFromSeed(v3, aIntensity, ...). [callee:0x00559FB0, global:0x005DC260, source:raw]
    // GUARD: If sub_559E20(v3, aActive, v21, 0) finds an Active token, set v4=1 when v21 equals the 'true' string or v4=0 when v21 equals the 'false' string. [callee:0x00559E20, global:0x005D267C, global:0x005C596C, global:0x005C5798, source:raw]
    // CALCULATION: Map the Type string to a light kind code: 'Directional' -> v7=1, 'StaticOmni' -> v7=4, 'MovingOmni' -> v7=2. [global:0x005DC254, global:0x005DC248, global:0x005DC23C, source:raw]
    // CALL: Create the scene node with kind code v7 by calling sub_545430((int*)&a3, a2, v7); if it returns non-zero, return -1 immediately. [callee:0x00545430, function:0x0055A500, source:raw]
    // CALL: For a directional light (v7==1), apply the parsed direction via sub_55D460(v14, v13, v12). [callee:0x0055D460, source:raw]
    // CALL: For omnidirectional lights (v7==2 or v7==4), apply the View values through SetUIPropertyGroupWithChainUpdate(v10, v9, v8) and push the range via StateFieldSetterWithGlobalDirtyFlag(v11). [callee:0x0055D4F0, callee:0x0055D530, source:raw]
    // CALL: Extract the packed color (v17 | ((v16 | (v15 << 8)) << 8)) into a channel via ByteExtractionFromUint(2, ...). [callee:0x0055D3F0, source:raw]
    // CALL: Publish the intensity to three UI property slots: UIPropertyValueSetter(1, v18[0]), UIPropertyValueSetter(2, v18[0]), UIPropertyValueSetter(3, v18[0]). [callee:0x0055D410, source:raw]
    // CALL: Toggle the light active state via BitFlagSetterWithDXUpdate(v4). [callee:0x0055D2F0, source:raw]
    // RETURN: Return 0 on success; -1 when node creation sub_545430 fails. [source:raw]

    // Conservative worker pseudocode:
    //   int ParseLightSceneProperties(void *this, int a2, _DWORD *buf) {
    //     int kind = 0;
    //     int active = 1;
    //     int range = 1120403456;
    //     float intensity[2] = { 1.0f, (float)(int)this };
    //     int view[3] = {0,0,0};
    //     int dir[3] = {0,0,0};
    //     int color[3] = {0,0,0};
    //     char typeStr[16] = {0};
    //     char activeStr[16] = {0};
    //     while (LineReaderFromBuffer(buf) != 1) {
    //       if (*buf == 3) break;
    //       if (*buf != 2) {
    //         sub_559E20((int)buf, (int)aType, typeStr, 0);
    //         PRNG4UniformFloatsFromSeed(buf, (int)&off_5DC230, &view[2], &view[1], &view[0], 0);
    //         PRNG4UniformFloatsFromSeed(buf, (int)aDir, &dir[0], &dir[1], &dir[2], 0);
    //         sub_559F00(buf, (int)aColor, &color[0], &color[1], &color[2], 0);
    //         PRNG4UniformFloatsFromSeed(buf, (int)aRange, &intensity[0], &range, 0, 0);
    //         PRNG4UniformFloatsFromSeed(buf, (int)aIntensity, intensity, 0, 0, 0);
    //         if (sub_559E20((int)buf, (int)aActive, activeStr, 0)) {
    //           if (!strcmp(activeStr, aTrue)) active = 1;
    //           else if (!strcmp(activeStr, aFalse)) active = 0;
    //         }
    //       }
    //     }
    //     if (!strcmp(typeStr, aDirectional)) kind = 1;
    //     else if (!strcmp(typeStr, aStaticomni)) kind = 4;
    //     else if (!strcmp(typeStr, aMovingomni)) kind = 2;
    //     if (sub_545430((int*)&buf, a2, kind)) return -1;
    //     if (kind == 1) {
    //       sub_55D460(dir[0], dir[1], dir[2]);
    //     } else if (kind == 2 || kind == 4) {
    //       SetUIPropertyGroupWithChainUpdate(view[2], view[1], view[0]);
    //       StateFieldSetterWithGlobalDirtyFlag(range);
    //     }
    //     ByteExtractionFromUint(2, color[2] | ((color[1] | (color[0] << 8)) << 8));
    //     UIPropertyValueSetter(1, intensity[0]);
    //     UIPropertyValueSetter(2, intensity[0]);
    //     UIPropertyValueSetter(3, intensity[0]);
    //     BitFlagSetterWithDXUpdate(active);
    //     return 0;
    //   }
    // UNRESOLVED: Global string names (aType, aDir, aColor, aRange, aIntensity, aActive, aTrue, aFalse, directional/staticomni/movingomni) come from the DERIVED analysis layer; the exact token text is not visible in the packet's raw source.
    // UNRESOLVED: Meaning of the token-type codes 2 and 3 in *v3 (comment/end markers) is inferred from control flow only.
    // UNRESOLVED: The exact semantics of sub_545430's return and the role of a2 (scene context) are not established.
    // UNRESOLVED: Which member the UI property setters and BitFlagSetterWithDXUpdate address (the light object vs the scene UI context) is unproven.
    // UNRESOLVED: The View/off_5DC230 value set appears redundant with the SetUIPropertyGroupWithChainUpdate path; whether it feeds a different object is unknown.
}
