## FieldSetterAt0x48_00552fc0 — FieldSetterAt0x48

**Summary:** Simple field setter. Writes the parameter a2 to this[18] (offset 0x48) and returns a2. No guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DTextRenderingWithScissorRectangle (0049b370), UITextRenderWithScale (004d7e40), HUDFlagRendererMain (004d82d0), ScaledTextureRender (004dc660), FontSurfaceLookupDispatch (0053d260), DirectXMeshVertexBufferParsingAndLoading (00547b40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48 | RW | — | Render parameter / color value (diffuse color for vertex shading) |

**Written-by note (persistence):**
- this 0x48: unconditional write; survives external poke

**Guard conditions:** None. Always writes a2 to field and returns a2.
