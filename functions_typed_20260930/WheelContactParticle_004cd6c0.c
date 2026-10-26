int __userpurge sub_4CD6C0@<eax>(int a1@<ecx>, double a2@<st0>, int a3, int a4)
{
  int result; // eax
  float *v6; // ebx
  double v8; // st7
  double v9; // st7
  float v10; // [esp+4h] [ebp-Ch]
  float v11; // [esp+4h] [ebp-Ch]
  float v12; // [esp+4h] [ebp-Ch]
  float v13; // [esp+4h] [ebp-Ch]
  float v14; // [esp+8h] [ebp-8h]
  float v15; // [esp+8h] [ebp-8h]
  float v16; // [esp+8h] [ebp-8h]
  float v17; // [esp+8h] [ebp-8h]
  float v18; // [esp+Ch] [ebp-4h]
  float v19; // [esp+Ch] [ebp-4h]
  float v20; // [esp+Ch] [ebp-4h]
  float v21; // [esp+Ch] [ebp-4h]
  float v22; // [esp+18h] [ebp+8h]
  float v23; // [esp+18h] [ebp+8h]

  result = *(_DWORD *)(a1 + 88);
  if ( result > 0 )
  {
    v6 = (float *)CircularBufferSlotAlloc((_DWORD *)a1);
    if ( dword_8AB6E4 == 2 )
      Delegation(&dword_8AB6EC);
    else
      a2 = dbl_8AFEA0;
    v6[2] = a2;
    if ( *(_DWORD *)(a1 + 4) == 8 )
    {
      v6[3] = a2 + *(float *)(a1 + 48);
      v6[24] = (double)(unsigned __int8)*(_DWORD *)(a4 + 24) * 0.0039370079;
      v22 = (double)(unsigned __int8)*(_DWORD *)(a3 + 24) * 0.0039370079;
      if ( dword_8AB6E4 == 2 )
      {
        if ( VehicleDataAccessor(&dword_8AB6EC) == 5 )
          v8 = 0.0;
        else
          v8 = FloatDifference(&dword_8AB6EC);
      }
      else
      {
        v8 = dbl_8AFE98;
      }
      v9 = v22 - v8 * *(float *)(a1 + 64);
      if ( v9 >= 0.0 )
      {
        if ( v9 > 1.0 )
          v9 = 1.0;
      }
      else
      {
        v9 = 0.0;
      }
      v6[25] = v9;
      v23 = v9 * 63.5;
      *(_DWORD *)(a3 + 24) = (int)v23;
    }
    else
    {
      v6[3] = 3.4028235e38;
    }
    v10 = *(float *)a3 + *(float *)(a3 + 12);
    v14 = *(float *)(a3 + 16) + *(float *)(a3 + 4);
    v18 = *(float *)(a3 + 20) + *(float *)(a3 + 8);
    PixelWriteToTextureBuffer(*(_DWORD *)v6, 0, LODWORD(v10), LODWORD(v14), LODWORD(v18), *(_DWORD *)(a3 + 24));
    v11 = *(float *)(a4 + 12) + *(float *)a4;
    v15 = *(float *)(a4 + 16) + *(float *)(a4 + 4);
    v19 = *(float *)(a4 + 20) + *(float *)(a4 + 8);
    PixelWriteToTextureBuffer(*(_DWORD *)v6, 1, LODWORD(v11), LODWORD(v15), LODWORD(v19), *(_DWORD *)(a4 + 24));
    v12 = *(float *)a4 - *(float *)(a4 + 12);
    v16 = *(float *)(a4 + 4) - *(float *)(a4 + 16);
    v20 = *(float *)(a4 + 8) - *(float *)(a4 + 20);
    PixelWriteToTextureBuffer(*(_DWORD *)v6, 2, LODWORD(v12), LODWORD(v16), LODWORD(v20), *(_DWORD *)(a4 + 24));
    v13 = *(float *)a3 - *(float *)(a3 + 12);
    v17 = *(float *)(a3 + 4) - *(float *)(a3 + 16);
    v21 = *(float *)(a3 + 8) - *(float *)(a3 + 20);
    return PixelWriteToTextureBuffer(*(_DWORD *)v6, 3, LODWORD(v13), LODWORD(v17), LODWORD(v21), *(_DWORD *)(a3 + 24));
  }
  return result;
}

