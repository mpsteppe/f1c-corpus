// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542200
// Canonical corpus name: sub_542200
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_542200_00542200.c

void UnknownObject::ViewportWindowSizeConfiguration()
{
    // Computes a viewport/window rectangle in pixels from normalized inputs. Reads a global screen scale pair (dword_8B8DD4 / dword_8B8DD8) or falls back to unity scale when a6 is set. Scales the normalized width/height/travel inputs by the scale factors when they are <= 1.0, converts to integer pixels via CRTFtol, writes width/height/center to integer fields (this+0x54/+0x58/+0x5C/+0x60/+0x64/+0x68) and float copies (this+0x14/+0x18), then derives projection terms: half-width this+0xC = 0.5*width/this+0x1C, half-height this+0x10 = 0.5*height/this+0x20, and aspect ratio this+0x74 = width/height. A flag bit at this+0x80 (0x10) controls whether the half-width term is negated.
    // GUARD: a6 selects the scale source: non-zero uses unity scale (v7=1.0, v18=1.0), zero reads the width/height scale globals dword_8B8DD4 and dword_8B8DD8 [global:0x008B8DD4, global:0x008B8DD8, source:raw]
    // CALCULATION: Normalized width a4 is multiplied by the width scale when a4 <= 1.0; normalized height a5 is multiplied by the height scale when a5 <= 1.0 [global:0x008B8DD4, global:0x008B8DD8, source:raw]
    // GUARD: Viewport width field this+0x54 is written with CRTFtol(width scale) when a4 >= 0.0, otherwise with literal 0 [field:this:0x00000054, callee:0x00587BDC, source:raw]
    // GUARD: Viewport height field this+0x58 is written with CRTFtol(width scale) unless a5 < 0.0, in which case it is written with literal 0 [field:this:0x00000058, callee:0x00587BDC, source:raw]
    // CALCULATION: Center input a3 is scaled by the height scale when a3 <= 1.0, then rounded twice via CRTFtol producing the integer center base [global:0x008B8DD8, callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Write integer center X: this+0x5C = base + (width >> 1), and the float copy this+0x14 = same value; this+0x68 receives the first CRTFtol result [field:this:0x0000005C, field:this:0x00000014, field:this:0x00000068, source:raw]
    // ASSIGNMENT: Write integer center Y: this+0x60 = (height >> 1) + second CRTFtol result, this+0x18 = float copy, this+0x64 receives the second CRTFtol result [field:this:0x00000060, field:this:0x00000018, field:this:0x00000064, source:raw]
    // CALCULATION: Half-width projection: this+0xC = 0.5 * width / this+0x1C; half-height projection: this+0x10 = 0.5 * height / this+0x20 [field:this:0x0000000C, field:this:0x00000010, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALCULATION: Aspect ratio this+0x74 = width / height computed from the two integer viewport dimensions [field:this:0x00000074, source:raw]
    // GUARD: Flag test on byte this+0x80 bit 0x10: when bit 4 is clear, this+0xC is negated to -half-width [field:this:0x00000080, field:this:0x0000000C, source:raw]
    // RETURN: Returns the computed center Y integer value; invoked by ViewportRectangleRenderSetup (0048E750), SuspensionPhysicsParameterSet (00542560), sub_553700 (00553700), sub_55A060 (0055A060) and sub_560C10 (00560C10) [caller:0x0048E750, caller:0x00542560, caller:0x00553700, caller:0x0055A060, caller:0x00560C10, source:raw]

    // Conservative worker pseudocode:
    //   if (a6) { width_scale = 1.0; height_scale = 1.0; }
    //   else { width_scale = dword_8B8DD4; height_scale = dword_8B8DD8; }
    //   if (a4 <= 1.0) a4 = a4 * width_scale;
    //   if (a5 <= 1.0) a5 = a5 * height_scale;
    //   width  = (a4 >= 0.0) ? CRTFtol(width_scale) : 0;
    //   height = (a5 <  0.0) ? 0 : CRTFtol(width_scale);
    //   base = a3;
    //   if (a3 <= 1.0) base = base * height_scale;
    //   this->center_x_int = CRTFtol(base) + (width >> 1);
    //   this->center_y_int = (height >> 1) + CRTFtol(base);
    //   this->width_int = CRTFtol(base); this->height_int = CRTFtol(base);
    //   this->half_width  = 0.5 * width  / this->fov_denom;
    //   this->half_height = 0.5 * height / this->aspect_denom;
    //   this->aspect_ratio = width / height;
    //   if (!(this->flags & 0x10)) this->half_width = -this->half_width;
    //   return this->center_y_int;
    // UNRESOLVED: Four read-only globals (dbl_59E420, flt_59E43C, flt_59E440, flt_59E450) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them a base double constant and physics constants, all unverifiable from this packet
    // UNRESOLVED: The exact semantics of fields this+0x1C and this+0x20 (FOV/aspect denominators) are inferred from the division only
    // UNRESOLVED: a2 is declared in the prototype but never referenced by the function body
}
