// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049EA10
// Canonical corpus name: F_2DRectangleRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DRectangleRender_0049ea10.c

void UnknownObject::F_2DRectangleRender()
{
    // Renders a 2D textured rectangle (quad). Guards on the render-data pointer at this+0x8, runs a short pre-render computation on this, then allocates/initializes a render object; when that succeeds it stores X/Y/width/height parameters as floats, computes per-texture UV scale factors from the texture sub-struct's width/height, and emits four corner vertices through sub_553650 with per-vertex position, UV and color arguments. Returns the last vertex-set result, or the render-data pointer result on the early-exit paths.
    // GUARD: Guard: read the render-data pointer at this+0x8; a null pointer skips the entire render body. [field:this:0x00000008, source:raw]
    // CALL: Run the short pre-render computation (sub_49EC40) on this object. [callee:0x0049EC40, source:raw]
    // CALL: Allocate and initialize the render object: ObjectConstructorWithAllocationAndSubInit(this, a6, renderData at this+0x8, 32, 192). A non-zero return skips the body. [callee:0x00553980, field:this:0x00000008, source:raw]
    // GUARD: Guard: only proceed when the allocation/init call returned zero. [callee:0x00553980, source:raw]
    // ASSIGNMENT: Store parameter a2 as a float at this+0x24 (X) and parameter a3 at this+0x28 (Y). [field:this:0x00000024, field:this:0x00000028, source:raw]
    // ASSIGNMENT: Store parameter a4 as a float at this+0x2C (width) and parameter a5 as a float at this+0x30 (height). [field:this:0x0000002C, field:this:0x00000030, source:raw]
    // CALCULATION: Compute U scale at this+0x34 = a4 / texture width, where texture width is the int at +0x1C of the sub-struct reached through +0x54 of the render data at this+0x8. [field:this:0x00000034, field:*(this+0x8):0x00000054, field:*(*(this+0x8)+0x54):0x0000001C, source:raw]
    // CALCULATION: Compute V scale at this+0x38 = a5 / texture height, where texture height is the int at +0x20 of the same sub-struct. [field:this:0x00000038, field:*(this+0x8):0x00000054, field:*(*(this+0x8)+0x54):0x00000020, source:raw]
    // CALL: Emit vertex 0 at (X, Y) with color/UV arguments (1.0, 0.0, 0.0, -1) through sub_553650. [callee:0x00553650, source:raw]
    // CALL: Emit vertex 1 at (X, Y+height) with color/UV arguments (1.0, 0.0, 1.0, -1). [callee:0x00553650, source:raw]
    // CALL: Emit vertex 2 at (X+width, Y+height) with color/UV arguments (1.0, 1.0, 1.0, -1). [callee:0x00553650, source:raw]
    // CALL: Emit vertex 3 at (X+width, Y) with color/UV arguments (1.0, 1.0, 0.0, -1); its result becomes the function return value. [callee:0x00553650, source:raw]
    // RETURN: Return the last sub_553650 result, or the render-data pointer result on the skip/early-exit paths. [source:raw]

    // Conservative worker pseudocode:
    //   result = this->renderData; // this+0x8
    //   if (result) {
    //     ShortComputation_ec40(this);
    //     if (!ObjectConstructorWithAllocationAndSubInit(this, a6, this->renderData, 32, 192)) {
    //       this->x = a2;         // this+0x24
    //       this->y = a3;         // this+0x28
    //       this->width = a4;     // this+0x2C
    //       this->height = a5;    // this+0x30
    //       this->uScale = a4 / textureWidth;   // textureWidth = *(int*)(*(*(this+0x8)+0x54)+0x1C)
    //       this->vScale = a5 / textureHeight;  // textureHeight = *(int*)(*(*(this+0x8)+0x54)+0x20)
    //       sub_553650(0, x, y, 1.0, 0.0, 0.0, -1);
    //       sub_553650(1, x, y+height, 1.0, 0.0, 1.0, -1);
    //       sub_553650(2, x+width, y+height, 1.0, 1.0, 1.0, -1);
    //       return sub_553650(3, x+width, y, 1.0, 1.0, 0.0, -1);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Global dword_8AFE64 (0x008AFE64) appears in the deterministic global facts for this function but is not referenced by the shown raw pseudocode; its exact role is unknown.
    // UNRESOLVED: Identity and purpose of the this object are unknown (owner stays UnknownObject).
    // UNRESOLVED: Meaning of the allocation constants 32 and 192 and of parameter a6 is unknown.
    // UNRESOLVED: Semantics of the -1 color/UV argument and of the leading three float arguments to sub_553650 are unknown; the UV/color split is inferred.
}
