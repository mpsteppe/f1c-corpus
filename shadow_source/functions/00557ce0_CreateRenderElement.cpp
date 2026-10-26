// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00557CE0
// Canonical corpus name: sub_557CE0
// Owner: RenderElement [DERIVED]
// Raw source: functions/sub_557CE0_00557ce0.c

void RenderElement::CreateRenderElement()
{
    // Constructs a render element (display-list sprite/quad) from a configuration descriptor: resolves a shared game object, creates the resource object from config, allocates a 128-byte-per-element buffer, builds a 68-byte control object holding a sub-object plus vertex/index buffers, then fills 36-byte vertex records (float coordinate/UV constants and an ARGB color) in either a per-element loop or a shared static record depending on config flag bits, and selects 2D-style (mode bit 1) vs 3D-style (mode bit 2) sizing paths.
    // CALL: Resolve the shared game object from the global dword_8B8F28 via ValueGetter; the result object is used for resource creation and ownership transfers. [callee:0x00545F40, global:0x008B8F28]
    // GUARD: If the resolved shared object is null, fail construction and return -1. [guard:0]
    // CALL: Create the resource object from the config descriptor: pass config dwords at a2+88, a2+92 and a2+104 plus byte arrays at a2+112 and a2+144. A nonzero return aborts construction with -1. [callee:0x005474D0, guard:0]
    // CALL: Walk and lock the shared object's linked list via LinkedListWalkInterlockedDec; a nonzero return aborts construction with -1. [callee:0x005487A0, guard:0]
    // ASSIGNMENT: Read the element count from config at a2+36 and store it into this+0x2C; this count drives all buffer sizing below. [field:this:0x0000002C]
    // GUARD: If the element count is <= 0, construction is invalid and the function returns -1. [guard:1]
    // CALCULATION: Compute the element-array allocation size as (count << 7) + 4: a 4-byte count header plus 128 bytes (32 dwords) per element. [source:raw]
    // CALL: Allocate the element array buffer (4-byte header plus 128 bytes per element) via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // LOOP: Write the element count into the buffer header, then initialize every element with StructInitWithVTableColor stepping 128 bytes per element; this installs the vertex-struct baseline including the 0.05f / -0.05f float constants observed on the vertex-data fields. [callee:0x005573A0, field:*(*(this+0x50)+0xC):0x00000000, field:*(*(this+0x50)+0xC):0x00000004, field:*(*(this+0x50)+0xC):0x00000008, field:*(*(this+0x50)+0xC):0x00000024, field:*(*(this+0x50)+0xC):0x00000028, field:*(*(this+0x50)+0xC):0x0000002C]
    // ASSIGNMENT: Store the element-array pointer into this+0x34. [field:this:0x00000034]
    // CALL: Copy the config descriptor identity string into this via strcpy, then run post-construction fixup sub_589901 on it. [callee:0x00589901, source:raw]
    // CALL: Allocate two 4-bytes-per-element buffers: one stored at this+0x3C and one at this+0x40. [callee:0x00587C03, field:this:0x0000003C, field:this:0x00000040]
    // CALCULATION: If config byte at a2+88 does not have bit 0x20 set, default the config dword at a2+100 to 65538 (indexed mode). [source:raw]
    // ASSIGNMENT: Set this+0x4C to 1 (usage/flag word). [field:this:0x0000004C]
    // CALL: Allocate the 68-byte control object: set its first dword (control+0x0) to 1, clear the remaining 64 bytes with GlobalZeroInit_c2a0, and store the control pointer at this+0x50. [callee:0x00587C03, callee:0x0053C2A0, field:this:0x00000050, field:*(this+0x50):0x00000000]
    // CALL: Zero the control object body (memset 0x40 bytes) and store the sub-object pointer into control+0x4, returned by sub_548890 for this render element. [callee:0x00548890, field:*(this+0x50):0x00000004, source:raw]
    // GUARD: If the sub-object pointer at control+0x4 is non-null, retain it with TwoCounterIncrements and set its dimensions from config dwords at a2+100 (low 16 bits) and a2+102 via sub_547240. [callee:0x005473C0, callee:0x00547240, field:*(this+0x50):0x00000004, guard:0]
    // GUARD: If the sub-object's count field at +0xA4 is > 0, set the field at +0xA8 (element-list pointer) from config dword a2+104 via FieldSetterAt0x80 and configure it via sub_54FCC0 with config dword a2+108. [callee:0x0054FCB0, callee:0x0054FCC0, field:*(*(this+0x50)+0x4):0x000000A4, field:*(*(this+0x50)+0x4):0x000000A8, guard:1]
    // ASSIGNMENT: Rebuild the control flags word at control+0x0: start from 0, set bit 0 if config byte at a2+88 has bit 0x8, set bit 1 if it has bit 0x10. [field:*(this+0x50):0x00000000, source:raw]
    // ASSIGNMENT: Merge render-mode flags into this+0x20 from config dword a2+32: bit 0x10 maps to 0x210, bit 0x20 maps to 0x220, bit 0x200 maps to 0x200. [field:this:0x00000020, source:raw]
    // STATE_TRANSITION: Mode-1 path when config a2+32 bit 0x1 is set: set this+0x20 bit 0, stride field this+0x24 to 4, this+0x28 to 6 (when the 0x200 flag is set) or 12; write control+0x8 = 4 * count and control+0x10 = this+0x28 * count; allocate the vertex buffer at control+0xC (144 bytes when config a2+32 sign bit is clear, else 36 * control+0x8) and the index buffer at control+0x14 (2 * control+0x10). [callee:0x00587C03, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:*(this+0x50):0x00000008, field:*(this+0x50):0x0000000C, field:*(this+0x50):0x00000010, field:*(this+0x50):0x00000014, source:raw]
    // CALCULATION: Read the color from config dword a2+96; if its high byte (alpha, mask 0xFF000000) is zero, force the alpha byte to full opacity. [source:raw]
    // LOOP: Mode-1 per-element path (config a2+32 bit 0x80 set): for each element write a 36-byte vertex record into the control+0xC buffer (float constants at 0x0/0x4/0x8 and 0x24/0x28/0x2C, ARGB color at 0x18 and 0x3C) and write the running element index at element-array offset +4 and the color at offset +12 with a 128-byte stride. [field:*(*(this+0x50)+0xC):0x00000000, field:*(*(this+0x50)+0xC):0x00000004, field:*(*(this+0x50)+0xC):0x00000008, field:*(*(this+0x50)+0xC):0x00000018, field:*(*(this+0x50)+0xC):0x00000024, field:*(*(this+0x50)+0xC):0x00000028, field:*(*(this+0x50)+0xC):0x0000002C, field:*(*(this+0x50)+0xC):0x0000003C, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Mode-1 static path (config a2+32 bit 0x80 clear): write the shared vertex records (float constants and color at the same vertex-data offsets) once into control+0xC, then fill every element with the running index (+4) and color (+12) at 128-byte strides. [field:*(*(this+0x50)+0xC):0x00000000, field:*(*(this+0x50)+0xC):0x00000004, field:*(*(this+0x50)+0xC):0x00000008, field:*(*(this+0x50)+0xC):0x00000018, field:*(*(this+0x50)+0xC):0x00000024, field:*(*(this+0x50)+0xC):0x00000028, field:*(*(this+0x50)+0xC):0x0000002C, field:*(*(this+0x50)+0xC):0x0000003C, field:this:0x00000034, source:raw]
    // GUARD: If config a2+32 bit 0x4 is set in the non-mode-1 branch, reject construction and return -1. [guard:1]
    // STATE_TRANSITION: Mode-2 path when config a2+32 bit 0x2 is set: set this+0x20 bit 1, stride field this+0x24 to 8, this+0x28 to 48 (when control+0x0 bit 0x10 is set) or 36; write control+0x8 = 8 * count and control+0x10 = this+0x28 * count; allocate the vertex buffer at control+0xC (36 * this+0x24 when config a2+32 sign bit is clear, else 36 * control+0x8) and the index buffer at control+0x14 (2 * control+0x10). [callee:0x00587C03, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:*(this+0x50):0x00000008, field:*(this+0x50):0x0000000C, field:*(this+0x50):0x00000010, field:*(this+0x50):0x00000014, source:raw]
    // CALCULATION: Read the mode-2 color from config dword a2+96 and force the alpha byte to full opacity when the high byte is zero. [source:raw]
    // LOOP: Mode-2 per-element path (config a2+32 bit 0x80 set): for each element write six 36-byte vertex records (float constants and ARGB color at the vertex-data offsets) into control+0xC and write the running index (+4) and color (+12) into the element array with a 128-byte stride. [field:*(*(this+0x50)+0xC):0x00000000, field:*(*(this+0x50)+0xC):0x00000004, field:*(*(this+0x50)+0xC):0x00000008, field:*(*(this+0x50)+0xC):0x00000018, field:*(*(this+0x50)+0xC):0x00000024, field:*(*(this+0x50)+0xC):0x00000028, field:*(*(this+0x50)+0xC):0x0000002C, field:*(*(this+0x50)+0xC):0x0000003C, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Mode-2 static path (config a2+32 bit 0x80 clear): write the shared vertex records (0.05f / -0.05f float constants plus color) once into control+0xC, then fill every element with the running index (+4) and color (+12) at 128-byte strides. [field:*(*(this+0x50)+0xC):0x00000000, field:*(*(this+0x50)+0xC):0x00000004, field:*(*(this+0x50)+0xC):0x00000008, field:*(*(this+0x50)+0xC):0x00000018, field:*(*(this+0x50)+0xC):0x00000024, field:*(*(this+0x50)+0xC):0x00000028, field:*(*(this+0x50)+0xC):0x0000002C, field:*(*(this+0x50)+0xC):0x0000003C, field:this:0x00000034, source:raw]
    // CALL: Allocate the final two buffers at this+0x44 and this+0x48, each sized 4 * this+0x4C. [callee:0x00587C03, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C]
    // RETURN: Return 0 on successful construction. [source:raw]

    // Conservative worker pseudocode:
    //   if (!(obj = ValueGetter(dword_8B8F28))) return -1;
    //   if (ResourceObjectCreationWithConfig(obj, config, config+88, config+92, config+112, config+144, config+104)) return -1;
    //   if (LinkedListWalkInterlockedDec(obj)) return -1;
    //   count = config[36];
    //   if (count <= 0) return -1;
    //   this[11] = count;
    //   elements = OperatorNewNhMallocWrapper((count << 7) + 4);
    //   if (elements) { elements[0] = count; for (i = 0; i < count; i++) StructInitWithVTableColor(elements + 1 + 32 * i); }
    //   this[13] = elements;
    //   strcpy(this, config); sub_589901(this);
    //   this[15] = OperatorNewNhMallocWrapper(4 * count);
    //   this[16] = OperatorNewNhMallocWrapper(4 * count);
    //   if (!(config[88] & 0x20)) config[100] = 65538;
    //   this[19] = 1;
    //   ctrl = OperatorNewNhMallocWrapper(68);
    //   if (ctrl) { ctrl[0] = 1; GlobalZeroInit_c2a0(ctrl + 1); }
    //   this[20] = ctrl;
    //   memset(ctrl, 0, 0x40);
    //   ctrl[4] = sub_548890(obj, this);
    //   if (ctrl[4]) { TwoCounterIncrements(ctrl[4]); sub_547240(ctrl[4], config[100], config[102]); if (ctrl[4][164] > 0) { FieldSetterAt0x80(ctrl[4][168], config[104]); sub_54FCC0(ctrl[4][168], config[108]); } }
    //   ctrl[0] = 0;
    //   if (config[88] & 0x8) ctrl[0] |= 1;
    //   if (config[88] & 0x10) ctrl[0] |= 2;
    //   if (config[32] & 0x10) this[8] |= 0x210;
    //   if (config[32] & 0x20) this[8] |= 0x220;
    //   if (config[32] & 0x200) this[8] |= 0x200;
    //   if (config[32] & 0x1) { /* mode-1: 2D-style vertex setup, per-element or shared fill * / }
    //   else if (config[32] & 0x4) return -1;
    //   else if (config[32] & 0x2) { /* mode-2: 3D-style vertex setup, per-element or shared fill * / }
    //   this[17] = OperatorNewNhMallocWrapper(4 * this[19]);
    //   this[18] = OperatorNewNhMallocWrapper(4 * this[19]);
    //   return 0;
    // UNRESOLVED: Exact meaning of the float vertex constants (-1090519040 / 1056964608 / 1028443341, i.e. -0.5f / 0.5f / 0.05f) and the -0.05f literals observed on vertex-data fields: interpreted as UV/position baselines but not confirmed.
    // UNRESOLVED: Semantics of sub_547240 (dimension setter) and sub_548890 (sub-object factory) are taken from call context only.
    // UNRESOLVED: Mapping between the config flag bits at a2+32 / a2+88 and the emitted this+0x20 / control+0x0 flags is only partially decoded.
    // UNRESOLVED: this+0x20 flags 0x210 / 0x220 / 0x200 and control+0x0 bits 1/2 are named by effect, not by an authoritative source.
}
