int __thiscall sub_4CBC50(int this, float a2, float *a3, float *a4, float a5, int a6, char a7, int a8)
{
  int result; // eax
  float *v10; // esi
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17[3]; // [esp+4h] [ebp-34h] BYREF
  int v18; // [esp+1Ch] [ebp-1Ch]
  int v19; // [esp+20h] [ebp-18h]
  int v20; // [esp+24h] [ebp-14h]
  int v21; // [esp+28h] [ebp-10h]
  double v22; // [esp+2Ch] [ebp-Ch]
  int v23; // [esp+34h] [ebp-4h]

  result = *(_DWORD *)(this + 88);
  if ( result > 0 )
  {
    v10 = (float *)CircularBufferSlotAlloc((_DWORD *)this);
    v11 = a2 + v10[7];
    v10[2] = a2;
    v10[3] = v11;
    v10[11] = *a3;
    v10[12] = a3[1];
    v10[13] = a3[2];
    v10[14] = *a4;
    v10[15] = a4[1];
    v10[16] = a4[2];
    v12 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 64.0;
    *((_DWORD *)v10 + 17) = a8;
    v10[10] = (v12 + 190.0) * a5;
    v13 = *a3;
    v18 = 0;
    v17[0] = v13;
    v14 = a3[1];
    v19 = 1070596096;
    v17[1] = v14;
    v15 = a3[2];
    v20 = 0x40000000;
    v17[2] = v15;
    v21 = 1201543096;
    v23 = a6;
    if ( CollisionNormalFromFeature(dbl_7C9360, v17, v10 + 21) )
    {
      v16 = v22;
    }
    else
    {
      v10[21] = 0.0;
      v10[22] = 1.0;
      v10[23] = 0.0;
      v16 = a3[1] - 0.25;
    }
    if ( a7 )
    {
      v10[12] = *(float *)(this + 16) * 0.5 + v16;
      v10[15] = v10[26] * *(float *)(this + 28) * 0.5;
    }
    TextureLayerFlagSet(*(_DWORD *)v10, *((_DWORD *)v10 + 11), *((_DWORD *)v10 + 12), *((_DWORD *)v10 + 13));
    ArrayElementFlagSetWithBoundsCheck(
      *(_DWORD *)v10,
      *(_DWORD *)(this + 12),
      *(_DWORD *)(this + 16),
      *(_DWORD *)(this + 20));
    return BoundsCheckedArrayWrite(*(_DWORD *)v10, 0xFFFFFF);
  }
  return result;
}
