int __usercall sub_504B37@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v4; // ecx
  _DWORD *v5; // ebx
  _DWORD *v7; // ecx
  unsigned int v8; // eax
  _DWORD *v9; // edx
  int v10; // esi
  int v11; // esi
  _DWORD *v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // esi
  int v23; // eax
  int v24; // esi
  int v25; // eax
  int v26; // eax
  int v27; // esi
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // esi
  int v32; // ecx
  int v33; // ecx
  bool v34; // zf
  int v35; // edi
  int v36; // esi
  unsigned int v37; // edx
  float *v38; // eax
  float *v39; // ecx
  double v40; // st6
  _DWORD *v41; // edi
  double v42; // st5
  double v43; // st5
  double v44; // st4
  float *v45; // eax
  double v46; // st6
  double v47; // st5
  double v48; // st4
  float *v49; // eax
  double v50; // st6
  double v51; // st5

  SEHHandlerInit();
  v5 = (_DWORD *)v4;
  if ( *(_BYTE *)(v4 + 8) != 5 )
    return -2147467259;
  v7 = *(_DWORD **)v4;
  v8 = *(_DWORD *)(*v5 + 4184);
  v9 = (_DWORD *)v5[1];
  v10 = v9[1046];
  if ( v10 != v8 >> 1 && (v10 != 1 || v8 != 1) )
    return -2147467259;
  v11 = v9[1047];
  if ( v11 != v7[1047] >> 1 && (v11 != 1 || v7[1047] != 1) )
    return -2147467259;
  if ( v9[1048] != 1 || v7[1048] != 1 )
    return -2147467259;
  if ( v8 > 1 && (v8 & 1) != 0 )
  {
    v7[1046] = v8 & 0xFFFFFFFE;
    *(_DWORD *)(*v5 + 4196) -= *(_DWORD *)(*v5 + 4200);
  }
  v12 = (_DWORD *)(*v5 + 4188);
  if ( *v12 > 1u )
    *v12 &= ~1u;
  if ( (*((_BYTE *)v5 + 10) & 8) != 0 )
    goto LABEL_44;
  v13 = *v5;
  v14 = *(_DWORD *)(*v5 + 4);
  if ( v14 != *(_DWORD *)(v5[1] + 4) || *(_DWORD *)(v13 + 4184) < 2u || *(_DWORD *)(v13 + 4188) < 2u )
    goto LABEL_44;
  if ( v14 <= 28 )
  {
    if ( v14 != 28 )
    {
      switch ( v14 )
      {
        case 21:
          v15 = PhysicsStateDispatch();
          goto LABEL_42;
        case 22:
          v15 = VehicleDataForwardingCall();
          goto LABEL_42;
        case 23:
          v15 = sub_503920(v5);
          goto LABEL_42;
        case 24:
          v15 = sub_503A70(v5);
          goto LABEL_42;
        case 25:
          v15 = F_16BitTextureBlending(v5);
          goto LABEL_42;
        case 26:
          v15 = BitplaneBlendingCompositing(v5);
          goto LABEL_42;
        case 27:
          v15 = PixelBlenderCompositor(v5);
          goto LABEL_42;
        default:
          goto LABEL_44;
      }
    }
    goto LABEL_39;
  }
  v16 = v14 - 29;
  if ( !v16 )
  {
    v15 = ImageBlendCombine(v5);
LABEL_42:
    if ( v15 >= 0 )
      return 0;
    goto LABEL_44;
  }
  v17 = v16 - 1;
  if ( !v17 )
  {
    v15 = sub_50415C(v5);
    goto LABEL_42;
  }
  v18 = v17 - 10;
  if ( v18 )
  {
    v19 = v18 - 1;
    if ( v19 )
    {
      v20 = v19 - 9;
      if ( !v20 )
      {
LABEL_39:
        v15 = F_2xBoxDownscale(v5);
        goto LABEL_42;
      }
      v21 = v20 - 1;
      if ( !v21 )
      {
        v15 = sub_50427D(v5);
        goto LABEL_42;
      }
      if ( v21 == 1 )
      {
        v15 = sub_5043C9(v5);
        goto LABEL_42;
      }
    }
  }
LABEL_44:
  v22 = *(_DWORD *)(v5[1] + 4184);
  v23 = OperatorNewNhMallocWrapper(16 * v22);
  *(_DWORD *)(a2 - 44) = v23;
  *(_DWORD *)(a2 - 4) = 0;
  if ( v23 )
  {
    sub_5008C2(v23, 16, v22, (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a2 - 28) = *(_DWORD *)(a2 - 44);
  }
  else
  {
    *(_DWORD *)(a2 - 28) = 0;
  }
  *(_DWORD *)(a2 - 4) = -1;
  if ( !*(_DWORD *)(a2 - 28) )
    return -2147024882;
  v24 = *(_DWORD *)(*v5 + 4184);
  if ( *(_DWORD *)(*v5 + 4188) == 1 )
  {
    v25 = OperatorNewNhMallocWrapper(16 * v24);
    *(_DWORD *)(a2 - 44) = v25;
    *(_DWORD *)(a2 - 4) = 1;
    if ( v25 )
    {
      sub_5008C2(v25, 16, v24, (int (__thiscall *)(int))sub_5007EC);
      v26 = *(_DWORD *)(a2 - 44);
    }
    else
    {
      v26 = 0;
    }
    *(_DWORD *)(a2 - 4) = -1;
    *(_DWORD *)(a2 - 36) = v26;
    *(_DWORD *)(a2 - 20) = v26;
  }
  else
  {
    v27 = 2 * v24;
    v28 = OperatorNewNhMallocWrapper(16 * v27);
    *(_DWORD *)(a2 - 44) = v28;
    *(_DWORD *)(a2 - 4) = 2;
    if ( v28 )
    {
      sub_5008C2(v28, 16, v27, (int (__thiscall *)(int))sub_5007EC);
      v29 = *(_DWORD *)(a2 - 44);
    }
    else
    {
      v29 = 0;
    }
    v30 = *(_DWORD *)(*v5 + 4184);
    *(_DWORD *)(a2 - 4) = -1;
    *(_DWORD *)(a2 - 36) = v29;
    *(_DWORD *)(a2 - 20) = v29;
    v26 = v29 + 16 * v30;
  }
  *(_DWORD *)(a2 - 16) = v26;
  if ( *(_DWORD *)(a2 - 36) )
  {
    v32 = *(_DWORD *)(a2 - 20);
    if ( *(_DWORD *)(*v5 + 4184) == 1 )
    {
      *(_DWORD *)(a2 - 40) = v32;
      v33 = *(_DWORD *)(a2 - 16);
    }
    else
    {
      *(_DWORD *)(a2 - 40) = v32 + 16;
      v33 = *(_DWORD *)(a2 - 16) + 16;
    }
    *(_DWORD *)(a2 - 44) = v33;
    v34 = *(_DWORD *)(v5[1] + 4188) == 0;
    *(_DWORD *)(a2 - 24) = 0;
    if ( !v34 )
    {
      do
      {
        v35 = *(_DWORD *)(a2 - 20);
        v36 = 2 * *(_DWORD *)(a2 - 24);
        (*(void (__thiscall **)(_DWORD, int, _DWORD, int, int, int, int))(*(_DWORD *)*v5 + 4))(
          *v5,
          v36,
          0,
          v35,
          a3,
          a4,
          a1);
        if ( *(_DWORD *)(a2 - 16) != v35 )
          (*(void (__thiscall **)(_DWORD, int, _DWORD, _DWORD))(*(_DWORD *)*v5 + 4))(
            *v5,
            v36 + 1,
            0,
            *(_DWORD *)(a2 - 16));
        v37 = 0;
        if ( *(_DWORD *)(v5[1] + 4184) )
        {
          *(_DWORD *)(a2 - 32) = *(_DWORD *)(a2 - 28);
          do
          {
            v38 = (float *)(32 * v37 + *(_DWORD *)(a2 - 40));
            v39 = (float *)(32 * v37 + *(_DWORD *)(a2 - 20));
            v40 = *v38 + *v39;
            v41 = *(_DWORD **)(a2 - 32);
            v42 = v38[1];
            *(_DWORD *)(a2 - 32) = v41 + 4;
            v43 = v42 + v39[1];
            *(float *)(a2 - 68) = v38[2] + v39[2];
            v44 = v38[3];
            v45 = (float *)(32 * v37 + *(_DWORD *)(a2 - 16));
            *(float *)(a2 - 64) = v44 + v39[3];
            *(float *)(a2 - 92) = v40 + *v45;
            v46 = v43 + v45[1];
            v47 = *(float *)(a2 - 68) + v45[2];
            v48 = *(float *)(a2 - 64) + v45[3];
            v49 = (float *)(32 * v37 + *(_DWORD *)(a2 - 44));
            *(float *)(a2 - 80) = v48;
            ++v37;
            *(float *)(a2 - 108) = *(float *)(a2 - 92) + *v49;
            *(float *)(a2 - 104) = v46 + v49[1];
            v50 = v47 + v49[2];
            v51 = *(float *)(a2 - 80) + v49[3];
            *(float *)(a2 - 60) = *(float *)(a2 - 108) * 0.25;
            *(float *)(a2 - 56) = *(float *)(a2 - 104) * 0.25;
            *(float *)(a2 - 52) = v50 * 0.25;
            *(float *)(a2 - 48) = v51 * 0.25;
            *v41++ = *(_DWORD *)(a2 - 60);
            *v41++ = *(_DWORD *)(a2 - 60 + 4);
            *v41 = *(_DWORD *)(a2 - 60 + 8);
            v41[1] = *(_DWORD *)(a2 - 60 + 12);
          }
          while ( v37 < *(_DWORD *)(v5[1] + 4184) );
        }
        a1 = *(_DWORD *)(a2 - 28);
        a4 = 0;
        a3 = *(_DWORD *)(a2 - 24);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v5[1] + 8))(v5[1]);
        ++*(_DWORD *)(a2 - 24);
      }
      while ( *(_DWORD *)(a2 - 24) < *(_DWORD *)(v5[1] + 4188) );
    }
    FreeWrapper_7bcf(*(LPVOID *)(a2 - 36));
    v31 = 0;
  }
  else
  {
    v31 = -2147024882;
  }
  FreeWrapper_7bcf(*(LPVOID *)(a2 - 28));
  return v31;
}

