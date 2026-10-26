// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00552F20
// Canonical corpus name: TexturePathParsingAndDimensionCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TexturePathParsingAndDimensionCalculation_00552f20.c

void UnknownObject::texturePathParseAndComputeDimensions()
{
    // Parses a texture file path and computes texture-coordinate scale factors. Dispatches on the pixel format at the loader object (this+0x64) offset +0x30: cases 5/6 run sub_552BA0, cases 7/8 run sub_552D70 (jump table at 0x00552FAC). Strips the directory prefix with CRTStrrchr on the backslash and copies the file name into the buffer at this+0x14 until the '.' extension separator. Reads the loader's width (offset +0x1C) and height (offset +0x20), stores 1.0/width at this+0x0 and 1.0/height at this+0x4 as floats, and copies the key color from this+0x2C into the loader field at offset +0x34. Returns 0. Called from sub_552470.
    // CALL: Switch dispatch on the pixel format at the loader object (this+0x64) offset +0x30 using the jump table at 0x00552FAC: cases 5 and 6 call sub_552BA0(this), cases 7 and 8 call sub_552D70(this), default does nothing. The ABI lead names this texture path parsing and dimension calculation. [field:*(this+0x64):0x00000030, global:0x00552FAC, callee:0x00552BA0, callee:0x00552D70, caller:0x00552470, abi:lead, source:raw]
    // CALCULATION: Calls CRTStrrchr(a2, 92) to find the last backslash; if found the file name starts at the character after it, otherwise the whole path is the file name. [callee:0x0058B050, source:raw]
    // LOOP: Copies the file name into the buffer at this+0x14 character by character until the '.' separator (46), then NUL-terminates it at the stopping position. [source:raw]
    // ASSIGNMENT: Reads the loader pointer v7 from this+0x64 and the key color v8 from this+0x2C. [field:this:0x00000064, field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Computes texture-coordinate scale factors: *(float*)this = 1.0 / loader field +0x1C (width), and *(float*)(this+0x4) = 1.0 / loader field +0x20 (height). [field:this:0x00000000, field:this:0x00000004, field:*(this+0x64):0x0000001C, field:*(this+0x64):0x00000020, source:raw]
    // ASSIGNMENT: Writes the key color v8 into the loader's field 13 (offset +0x34). [field:*(this+0x64):0x00000034, field:this:0x0000002C, source:raw]
    // RETURN: Returns constant 0. [function:0x00552F20, source:raw]

    // Conservative worker pseudocode:
    //   int texturePathParseAndComputeDimensions(void *this, const char *path) {
    //     switch (*(int*)(*(char**)((char*)this + 0x64) + 0x30)) {
    //       case 5: case 6: sub_552BA0(this); break;
    //       case 7: case 8: sub_552D70(this); break;
    //       default: break;
    //     }
    //     const char *name = path;
    //     if (char *slash = CRTStrrchr(path, 92)) name = slash + 1;
    //     int i = 0;
    //     while (name[i] != '.') { *((char*)this + 0x14 + i) = name[i]; i++; }
    //     *((char*)this + 0x14 + i) = 0;
    //     int *loader = *(int**)((char*)this + 0x64);
    //     int keyColor = *(int*)((char*)this + 0x2C);
    //     *(float*)this = 1.0f / (float)loader[7];
    //     *(float*)((char*)this + 4) = 1.0f / (float)loader[8];
    //     loader[13] = keyColor;
    //     return 0;
    //   }
    // UNRESOLVED: The file-name copy target buffer at this+0x14 has no packet field evidence reference and its exact size/layout is unknown.
    // UNRESOLVED: Global flt_59E43C appears in the packet's global list but is not referenced anywhere in the raw body.
    // UNRESOLVED: The semantic meaning of the pixel-format values (5/6 vs 7/8) and of the field written at loader+0x34 is not established by the packet.
}
