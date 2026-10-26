int __fastcall sub_553AA0(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v6; // eax
  int v7; // ebp
  int v9; // esi
  int v10; // esi
  char v11; // cl
  signed int v13; // edi
  signed int v14; // eax
  int v15; // edx
  int v16; // ebp
  int v17; // ecx
  int v18; // ebp
  int v19; // ecx
  BOOL v20; // edx
  int v24; // [esp+18h] [ebp-14h]
  int (__stdcall *v25)(int, int, int, int); // [esp+1Ch] [ebp-10h]
  int (__stdcall *v26)(int, int, int, int); // [esp+20h] [ebp-Ch]
  int (__cdecl *v27)(int, int, int, int, int, int, int, int); // [esp+24h] [ebp-8h]
  int v28; // [esp+24h] [ebp-8h]
  int (__cdecl *v29)(int, int, int, int, int, int, int, int, int); // [esp+28h] [ebp-4h]
  int v30; // [esp+30h] [ebp+4h]
  int v31; // [esp+30h] [ebp+4h]

  v6 = a6[12];
  v7 = a5;
  if ( v6 == 6 )
  {
    v9 = ((a5 >> 3) & 0x1F) + ((a5 >> 5) & 0x7E0) + ((a5 >> 8) & 0xF800);
  }
  else if ( v6 == 5 )
  {
    v9 = ((a5 >> 3) & 0x1F) + ((a5 >> 6) & 0x3E0) + ((a5 >> 9) & 0x7C00);
  }
  else
  {
    v9 = a4;
  }
  v24 = ThunkWithArgReorder(a6, 0, 0);
  if ( a6[9] == 16 )
  {
    v7 = v9;
    v26 = ClampedPixelSpanFill;
    v25 = sub_553D00;
    v27 = F_16BitPixelRectangleFill;
    v29 = PixelFillWithStrideStepCalculation;
    a5 = v9;
    v10 = (int)a6[10] >> 1;
    v11 = 1;
  }
  else
  {
    v26 = sub_553D40;
    v25 = DrawRectangle;
    v27 = F_2DArrayFillWithStrideSupport;
    v29 = NestedLoopArrayFillWithStride;
    v10 = (int)a6[10] >> 2;
    v11 = 2;
  }
  v13 = abs32(a3 - a1);
  if ( !v13 )
  {
    ((void (__fastcall *)(int, int, int, int, int, int))v25)(a1, a2, a4, v7, v10, v24);
    return ArgumentReorderWrapper_3230(a6, 0, 0);
  }
  v14 = abs32(a4 - a2);
  if ( !v14 )
  {
    ((void (__fastcall *)(int, int, int, int, int, int))v26)(a1, a3, a2, v7, v10, v24);
    return ArgumentReorderWrapper_3230(a6, 0, 0);
  }
  if ( v13 >= v14 )
  {
    v15 = v14 << v11;
    v30 = (v14 - v13) << v11;
    v16 = (v14 << v11) - v13;
    if ( a1 <= a3 )
    {
      v17 = a1 + a2 * v10;
      if ( a4 > a2 )
      {
LABEL_19:
        v27(v16, v13 + 1, v15, v30, v10, v17, a5, v24);
        return ArgumentReorderWrapper_3230(a6, 0, 0);
      }
    }
    else
    {
      v17 = a3 + a4 * v10;
      if ( a4 <= a2 )
        goto LABEL_19;
    }
    v10 = -v10;
    goto LABEL_19;
  }
  v18 = v13 << v11;
  v28 = (v13 << v11) - v14;
  v31 = (v13 - v14) << v11;
  if ( a2 <= a4 )
  {
    v19 = a1 + a2 * v10;
    v20 = a3 > a1;
  }
  else
  {
    v19 = a3 + a4 * v10;
    v20 = a3 <= a1;
  }
  v29(v28, v14 + 1, v18, v31, 2 * v20 - 1, v19, a5, v10, v24);
  return ArgumentReorderWrapper_3230(a6, 0, 0);
}
