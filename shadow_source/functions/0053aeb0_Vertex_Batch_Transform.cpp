// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053AEB0
// Canonical corpus name: sub_53AEB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53AEB0_0053aeb0.c

void UnknownObject::Vertex_Batch_Transform()
{
    // Batch vertex transform, structural twin of SSEMatrixVectorTransform (0053AE00). Reads the batch count from a2[2], the source vertex pointer from a2[3] and the output pointer from a2[8]. Copies the four __m128 columns of transform matrix a3 into the buffer at *(this+0x30) and seeds the working buffer at *(this+0x10) with w=1, then loops count times transforming each source vertex (12-dword stride) through the 4-column SSE matrix-vector product and writing three components to the output (16-dword stride). Then copies the three columns of a second transform matrix a4 and continues over the remainder of the source array (offset +12 dwords) with a 5-dword output stride using a 3-column SSE product. Returns the last transformed component.
    // ASSIGNMENT: Reads the vertex batch count from a2[2] into the loop counter and keeps a saved copy for the second batch [source:raw]
    // ASSIGNMENT: Loads the source vertex pointer from a2[3] and the output vertex pointer from a2[8] [source:raw]
    // ASSIGNMENT: Loads the matrix column buffer pointer from the this+0x30 slot (*(this+0x30)) and copies the four __m128 columns of transform matrix a3 into it, columns at +0x0/+0x10/+0x20/+0x30 [field:this:0x00000030, field:*(this+0x30):0x00000000, field:*(this+0x30):0x00000010, field:*(this+0x30):0x00000020, field:*(this+0x30):0x00000030]
    // ASSIGNMENT: Loads the working vector buffer pointer from the this+0x10 slot (*(this+0x10)) and seeds its fourth component to 1065353216 (1.0f as float), supplying the affine w term [field:this:0x00000010, field:*(this+0x10):0x00000000]
    // LOOP: First batch loop: iterates count times (post-decrement counter from a2[2], do/while), advancing the source pointer by 12 dwords and the output pointer by 16 dwords per vertex [source:raw]
    // CALCULATION: Per vertex, copies the three input components into the working buffer at *(this+0x10) (X at +0x0, Y read back at +0x4) and computes the full 4-column SSE matrix-vector product using the buffer columns at *(this+0x30) [field:*(this+0x10):0x00000000, field:*(this+0x10):0x00000004, field:*(this+0x30):0x00000000, source:raw]
    // ASSIGNMENT: Stores each transformed three-component result from the working buffer into the output stream [field:*(this+0x10):0x00000000, source:raw]
    // ASSIGNMENT: Re-loads the matrix column buffer from this+0x30 and copies the three __m128 columns of transform matrix a4 into it, leaving the fourth column untouched [field:this:0x00000030, field:*(this+0x30):0x00000000, field:*(this+0x30):0x00000010, field:*(this+0x30):0x00000020]
    // LOOP: Second batch loop: continues from the source vertex immediately after the first batch (source pointer +12 dwords), again count times, advancing the source by 12 dwords and the output by 5 dwords per vertex [source:raw]
    // CALCULATION: Per vertex, copies the three input components into the working buffer and computes a 3-column SSE matrix-vector product (columns +0x0/+0x10/+0x20 of *(this+0x30); no translation column) [field:*(this+0x10):0x00000000, field:*(this+0x30):0x00000000, source:raw]
    // ASSIGNMENT: Stores each transformed three-component result into the output stream at the 5-dword stride [field:*(this+0x10):0x00000000, source:raw]
    // RETURN: Returns the last transformed third component (Z) [function:0x0053AEB0, source:raw]

    // Conservative worker pseudocode:
    //   count = a2[2]; src = (int*)a2[3]; dst = (int*)a2[8];
    //   columns = *(this + 0x30); for (i = 0; i < 4; ++i) columns[i] = a3[i];
    //   buf = *(this + 0x10); buf->i32[3] = 1065353216;
    //   do { buf->i32[0..2] = src[0..2]; res = 4-column SSE dot(buf, columns); dst[0..2] = res; src += 12; dst += 16; } while (--count > 1);
    //   for (i = 0; i < 3; ++i) columns[i] = a4[i];
    //   do { buf->i32[0..2] = src[0..2]; res = 3-column SSE dot(buf, columns); dst[0..2] = res; src += 12; dst += 5; } while (--count > 1);
    //   return last Z;
    // UNRESOLVED: Two distinct transforms run sequentially over two vertex batches with different output strides (16 dwords then 5 dwords); the destination layout and the relationship between matrices a3 and a4 are not established
    // UNRESOLVED: Field *(this+0x10):0x4 is packet-flagged read-only yet the decompiled source writes the Y component through it; slot intent unresolved
    // UNRESOLVED: The second transform consumes only three columns of a4; whether the missing fourth column is deliberate (translation-free 3x4 block) or a decompiler artifact is inferred, not evidenced
}
