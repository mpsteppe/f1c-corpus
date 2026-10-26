int __thiscall sub_53EB70(char *this, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  char *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  _DWORD *v16; // eax
  _WORD *v17; // eax
  int v18; // eax
  int v19; // eax
  void *v20; // edi
  int v21; // eax
  int v22; // eax
  void *v23; // edi
  int v24; // eax
  _DWORD *i; // edi
  int j; // edi
  int v27; // [esp+D4h] [ebp-64h]
  int v28; // [esp+D4h] [ebp-64h]
  int v29; // [esp+DCh] [ebp-5Ch]
  int v30; // [esp+DCh] [ebp-5Ch]
  int v31; // [esp+E0h] [ebp-58h]
  _DWORD v32[17]; // [esp+F4h] [ebp-44h] BYREF

  if ( (*((_DWORD *)this + 1258) & 0x10000000) == 0 )
  {
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        22,
                        *((_DWORD *)this + 1257));
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        26,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        28,
                        0);
    v3 = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(*((_DWORD *)this + 1088), 136, 1);
    v31 = *((_DWORD *)this + 1262);
    *(_DWORD *)this = v3;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        7,
                        v31);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        23,
                        2);
    sub_554BE0(1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        60,
                        *((_DWORD *)this + 1266));
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        25,
                        5);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        24,
                        63);
    v4 = *((_DWORD *)this + 1088);
    *((_DWORD *)this + 1264) = 63;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v4 + 200))(v4, 29, 0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        27,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        19,
                        2);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        20,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        9,
                        2);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        15,
                        0);
    v5 = *((_DWORD *)this + 1260);
    v6 = 0;
    *((_DWORD *)this + 1263) = 65538;
    *((_DWORD *)this + 1117) = 256;
    if ( v5 > 0 )
    {
      do
      {
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, int))(**((_DWORD **)this + 1088) + 252))(
                            *((_DWORD *)this + 1088),
                            v6,
                            17,
                            2);
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, int))(**((_DWORD **)this + 1088) + 252))(
                            *((_DWORD *)this + 1088),
                            v6++,
                            16,
                            2);
      }
      while ( v6 < *((_DWORD *)this + 1260) );
    }
    v7 = 0;
    v8 = this + 4472;
    do
    {
      sub_553E10(v7);
      if ( sub_55C9B0(this) )
        sub_554660(-2.0);
      ++v7;
      v8 += 68;
    }
    while ( v7 < 8 );
    v9 = *((_DWORD *)this + 1088);
    *((_DWORD *)this + 1254) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 332))(v9, 0, 0, 0);
    v10 = *((_DWORD *)this + 1088);
    *((_DWORD *)this + 1255) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int))(*(_DWORD *)v10 + 304))(v10, 1234);
    v11 = *((_DWORD *)this + 1088);
    v32[0] = 1065353216;
    v32[1] = 1065353216;
    v32[2] = 1065353216;
    v32[3] = 0;
    v32[4] = 1065353216;
    v32[5] = 1065353216;
    v32[6] = 1065353216;
    memset(&v32[7], 0, 16);
    v32[11] = 1065353216;
    memset(&v32[12], 0, 20);
    *(_DWORD *)this = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v11 + 168))(v11, v32);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        141,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        145,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        147,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        146,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        148,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1088) + 200))(
                        *((_DWORD *)this + 1088),
                        137,
                        0);
    *((_DWORD *)this + 1268) = 0;
    sub_560340(this);
    v12 = (_DWORD *)sub_587C03(36);
    if ( v12 )
    {
      v12[5] = 0;
      v12[4] = 0;
      v12[3] = 0;
      v12[2] = 0;
      v12[1] = 0;
      *v12 = 0;
      v12[7] = 0;
      v12[6] = 0;
      v12[8] = 0;
    }
    else
    {
      v12 = 0;
    }
    *((_DWORD *)this + 1104) = v12;
    *v12 = 34;
    *(_DWORD *)(*((_DWORD *)this + 1104) + 12) = 8;
    *(_DWORD *)(*((_DWORD *)this + 1104) + 4) = dword_8CEF78;
    *(_DWORD *)(*((_DWORD *)this + 1104) + 8) = 28;
    if ( sub_540DF0(*((_DWORD *)this + 1104)) )
      return -1;
    v14 = (_DWORD *)sub_540F00(*((_DWORD *)this + 1104), 0, 0, 0);
    v14[2] = 1065353216;
    v14[3] = 1065353216;
    v14[9] = 1065353216;
    v14[10] = 1065353216;
    v14 += 14;
    v14[2] = 1065353216;
    v14[3] = 1065353216;
    v14 += 7;
    v14[2] = 1065353216;
    v14[3] = 1065353216;
    sub_540F90(*((_DWORD *)this + 1104));
    v15 = (_DWORD *)sub_587C03(36);
    if ( v15 )
    {
      v15[5] = 0;
      v15[4] = 0;
      v15[3] = 0;
      v15[2] = 0;
      v15[1] = 0;
      *v15 = 0;
      v15[7] = 0;
      v15[6] = 0;
      v15[8] = 0;
    }
    else
    {
      v15 = 0;
    }
    *((_DWORD *)this + 1103) = v15;
    *v15 = 34;
    *(_DWORD *)(*((_DWORD *)this + 1103) + 12) = 128;
    *(_DWORD *)(*((_DWORD *)this + 1103) + 4) = 322;
    *(_DWORD *)(*((_DWORD *)this + 1103) + 8) = 24;
    if ( sub_540DF0(*((_DWORD *)this + 1103)) )
      return -1;
    v16 = (_DWORD *)sub_587C03(28);
    if ( v16 )
    {
      v16[3] = 0;
      v16[2] = 0;
      v16[1] = 0;
      *v16 = 0;
      v16[5] = 0;
      v16[4] = 0;
      v16[6] = 0;
    }
    else
    {
      v16 = 0;
    }
    *((_DWORD *)this + 1105) = v16;
    *v16 = 18;
    *(_DWORD *)(*((_DWORD *)this + 1105) + 4) = 24;
    if ( sub_540FC0(*((_DWORD *)this + 1105)) )
      return -1;
    v17 = (_WORD *)sub_541090(*((_DWORD *)this + 1105), 0, 0, 0);
    v17[3] = 2;
    v17[4] = 2;
    v17[5] = 3;
    v17[6] = 3;
    v17[1] = 1;
    v17[2] = 1;
    v17[9] = 5;
    v17[10] = 5;
    v17[19] = 5;
    *v17 = 0;
    v17[7] = 0;
    v17[8] = 4;
    v17[11] = 6;
    v17[12] = 6;
    v17[13] = 7;
    v17[14] = 7;
    v17[15] = 4;
    v17[16] = 0;
    v17[17] = 4;
    v17[18] = 1;
    v17[20] = 2;
    v17[21] = 6;
    v17[22] = 3;
    v17[23] = 7;
    sub_5410F0(*((_DWORD *)this + 1105));
    if ( a2 )
    {
      v18 = sub_587C03(60);
      if ( v18 )
        v19 = sub_5426A0(v18);
      else
        v19 = 0;
      v29 = *((_DWORD *)this + 1366);
      v27 = *((_DWORD *)this + 1365);
      *((_DWORD *)this + 1351) = v19;
      if ( sub_542950(v27, v27, v29, 262152) )
      {
        v20 = (void *)*((_DWORD *)this + 1351);
        if ( v20 )
        {
          j_nullsub_3(*((_DWORD *)this + 1351));
          sub_587BCF(v20);
        }
        *((_DWORD *)this + 1351) = 0;
      }
      v21 = sub_587C03(60);
      if ( v21 )
        v22 = sub_5426A0(v21);
      else
        v22 = 0;
      v30 = *((_DWORD *)this + 1366);
      v28 = *((_DWORD *)this + 1365);
      *((_DWORD *)this + 1352) = v22;
      if ( sub_542950(v28, v28, v30, 262152) )
      {
        v23 = (void *)*((_DWORD *)this + 1352);
        if ( v23 )
        {
          j_nullsub_3(*((_DWORD *)this + 1352));
          sub_587BCF(v23);
        }
        *((_DWORD *)this + 1352) = 0;
      }
      if ( sub_544740(a2) )
        return -1;
      v24 = sub_545F40(a2);
      sub_554C30(v24);
      sub_5458D0(2);
    }
    for ( i = (_DWORD *)*((_DWORD *)this + 1350); i; i = (_DWORD *)i[8] )
    {
      if ( (*i & 2) != 0 )
      {
        sub_553370(2);
      }
      else if ( (*i & 1) != 0 )
      {
        sub_553370(1);
      }
    }
    for ( j = *((_DWORD *)this + 1376); j; j = *(_DWORD *)(j + 2160) )
      sub_5527C0(j);
    *((_DWORD *)this + 1258) |= 0x10000000u;
  }
  return 0;
}
