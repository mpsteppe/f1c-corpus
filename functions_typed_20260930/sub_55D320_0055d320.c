int __thiscall sub_55D320(int this, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // [esp-8h] [ebp-8h]
  int v7; // [esp-4h] [ebp-4h]

  switch ( a2 )
  {
    case 1:
      v7 = 2;
      *(float *)(this + 8) = (double)a3 * 0.0039215689 * *(float *)(this + 20);
      *(float *)(this + 12) = (double)a4 * 0.0039215689 * *(float *)(this + 20);
      *(float *)(this + 16) = (double)a5 * 0.0039215689 * *(float *)(this + 20);
      goto LABEL_7;
    case 2:
      v6 = *(_DWORD *)(this + 4);
      *(float *)(this + 24) = (double)a3 * 0.0039215689 * *(float *)(this + 36);
      *(float *)(this + 28) = (double)a4 * 0.0039215689 * *(float *)(this + 36);
      *(float *)(this + 32) = (double)a5 * 0.0039215689 * *(float *)(this + 36);
      DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, v6, 3);
      break;
    case 3:
      v7 = 4;
      *(float *)(this + 40) = (double)a3 * 0.0039215689 * *(float *)(this + 52);
      *(float *)(this + 44) = (double)a4 * 0.0039215689 * *(float *)(this + 52);
      *(float *)(this + 48) = (double)a5 * 0.0039215689 * *(float *)(this + 52);
LABEL_7:
      DirectXVertexBufferTextureCoordinateSetup(dword_8B78A0, this, *(_DWORD *)(this + 4), v7);
      break;
  }
  result = dword_8B8F28;
  *(_DWORD *)(dword_8B8F28 + 236) |= 0x800u;
  return result;
}

