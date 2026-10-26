int __thiscall sub_5A5A60(char *this, _DWORD *a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // edi
  int v7; // edi
  char *v8; // ebp
  int v9; // eax
  int v10; // eax
  int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v14; // eax
  int v15; // ecx
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  _WORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  unsigned int *i; // edi
  int *j; // edi
  int v25; // [esp+D4h] [ebp-64h]
  int v26; // [esp+D4h] [ebp-64h]
  int v27; // [esp+DCh] [ebp-5Ch]
  int v28; // [esp+DCh] [ebp-5Ch]
  int v29; // [esp+E0h] [ebp-58h]
  _DWORD v30[17]; // [esp+F4h] [ebp-44h] BYREF

  if ( (*((_DWORD *)this + 1282) & 0x10000000) == 0 )
  {
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        22,
                        *((_DWORD *)this + 1281));
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        26,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        28,
                        0);
    v3 = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(*((_DWORD *)this + 1112), 136, 1);
    v29 = *((_DWORD *)this + 1286);
    *(_DWORD *)this = v3;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        7,
                        v29);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        23,
                        2);
    sub_5AAD80(1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        60,
                        *((_DWORD *)this + 1291));
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        25,
                        5);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        24,
                        63);
    v4 = *((_DWORD *)this + 1112);
    *((_DWORD *)this + 1289) = 63;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v4 + 200))(v4, 29, 0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        27,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        19,
                        2);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        20,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        9,
                        2);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        15,
                        0);
    v5 = *((_DWORD *)this + 1284);
    v6 = 0;
    *((_DWORD *)this + 1288) = 65538;
    *((_DWORD *)this + 1141) = 256;
    if ( v5 > 0 )
    {
      do
      {
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, int))(**((_DWORD **)this + 1112) + 252))(
                            *((_DWORD *)this + 1112),
                            v6,
                            17,
                            2);
        *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, int))(**((_DWORD **)this + 1112) + 252))(
                            *((_DWORD *)this + 1112),
                            v6++,
                            16,
                            2);
      }
      while ( v6 < *((_DWORD *)this + 1284) );
    }
    v7 = 0;
    v8 = this + 4568;
    do
    {
      sub_5A9FA0(v7);
      if ( sub_5B4BE0(this) )
        sub_5AA7F0(-2.0);
      ++v7;
      v8 += 68;
    }
    while ( v7 < 8 );
    v9 = *((_DWORD *)this + 1112);
    *((_DWORD *)this + 1278) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 332))(v9, 0, 0, 0);
    v10 = *((_DWORD *)this + 1112);
    *((_DWORD *)this + 1279) = 0;
    *(_DWORD *)this = (*(int (__stdcall **)(int, int))(*(_DWORD *)v10 + 304))(v10, 1234);
    v11 = *((_DWORD *)this + 1112);
    v30[0] = 1065353216;
    v30[1] = 1065353216;
    v30[2] = 1065353216;
    v30[3] = 0;
    v30[4] = 1065353216;
    v30[5] = 1065353216;
    v30[6] = 1065353216;
    memset(&v30[7], 0, 16);
    v30[11] = 1065353216;
    memset(&v30[12], 0, 20);
    *(_DWORD *)this = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v11 + 168))(v11, v30);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        141,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        145,
                        1);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        147,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        146,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        148,
                        0);
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**((_DWORD **)this + 1112) + 200))(
                        *((_DWORD *)this + 1112),
                        137,
                        0);
    *((_DWORD *)this + 1293) = 0;
    sub_5B8F70(this);
    v12 = operator new(0x24u);
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
    *((_DWORD *)this + 1128) = v12;
    *v12 = 34;
    *(_DWORD *)(*((_DWORD *)this + 1128) + 12) = 64;
    *(_DWORD *)(*((_DWORD *)this + 1128) + 4) = dword_7FEEB4;
    *(_DWORD *)(*((_DWORD *)this + 1128) + 8) = 28;
    if ( sub_5A7F10((int)this, *((_DWORD *)this + 1128)) )
      return -1;
    v14 = (_DWORD *)(sub_5A8020(*((_DWORD *)this + 1128), 0, 0, 0) + 12);
    v15 = 64;
    do
    {
      *(v14 - 1) = 1065353216;
      *v14 = 1065353216;
      v14 += 7;
      --v15;
    }
    while ( v15 );
    sub_5A80B0(*((_DWORD *)this + 1128));
    v16 = operator new(0x24u);
    if ( v16 )
    {
      v16[5] = 0;
      v16[4] = 0;
      v16[3] = 0;
      v16[2] = 0;
      v16[1] = 0;
      *v16 = 0;
      v16[7] = 0;
      v16[6] = 0;
      v16[8] = 0;
    }
    else
    {
      v16 = 0;
    }
    *((_DWORD *)this + 1127) = v16;
    *v16 = 34;
    *(_DWORD *)(*((_DWORD *)this + 1127) + 12) = 1024;
    *(_DWORD *)(*((_DWORD *)this + 1127) + 4) = 322;
    *(_DWORD *)(*((_DWORD *)this + 1127) + 8) = 24;
    if ( sub_5A7F10((int)this, *((_DWORD *)this + 1127)) )
      return -1;
    v17 = operator new(0x1Cu);
    if ( v17 )
    {
      v17[3] = 0;
      v17[2] = 0;
      v17[1] = 0;
      *v17 = 0;
      v17[5] = 0;
      v17[4] = 0;
      v17[6] = 0;
    }
    else
    {
      v17 = 0;
    }
    *((_DWORD *)this + 1129) = v17;
    *v17 = 18;
    *(_DWORD *)(*((_DWORD *)this + 1129) + 4) = 24;
    if ( sub_5A80E0((int)this, *((_DWORD *)this + 1129)) )
      return -1;
    v18 = (_WORD *)sub_5A81C0(*((_DWORD *)this + 1129), 0, 0, 0);
    v18[3] = 2;
    v18[4] = 2;
    v18[5] = 3;
    v18[6] = 3;
    v18[1] = 1;
    v18[2] = 1;
    v18[13] = 7;
    v18[14] = 7;
    v18[23] = 7;
    *v18 = 0;
    v18[7] = 0;
    v18[8] = 4;
    v18[9] = 5;
    v18[10] = 5;
    v18[11] = 6;
    v18[12] = 6;
    v18[15] = 4;
    v18[16] = 0;
    v18[17] = 4;
    v18[18] = 1;
    v18[19] = 5;
    v18[20] = 2;
    v18[21] = 6;
    v18[22] = 3;
    sub_5A8220(*((_DWORD *)this + 1129));
    if ( a2 )
    {
      v19 = operator new(0x40u);
      if ( v19 )
        v20 = sub_59F160(v19);
      else
        v20 = 0;
      v27 = *((_DWORD *)this + 2161);
      v25 = *((_DWORD *)this + 2160);
      *((_DWORD *)this + 2146) = v20;
      if ( sub_59F580(v20, v25, v25, v27, 262152) )
      {
        if ( *((_DWORD *)this + 2146) )
        {
          j_nullsub_6(*((void **)this + 2146));
          sub_5BE8AE();
        }
        *((_DWORD *)this + 2146) = 0;
      }
      v21 = operator new(0x40u);
      if ( v21 )
        v22 = sub_59F160(v21);
      else
        v22 = 0;
      v28 = *((_DWORD *)this + 2161);
      v26 = *((_DWORD *)this + 2160);
      *((_DWORD *)this + 2147) = v22;
      if ( sub_59F580(v22, v26, v26, v28, 262152) )
      {
        if ( *((_DWORD *)this + 2147) )
        {
          j_nullsub_6(*((void **)this + 2147));
          sub_5BE8AE();
        }
        *((_DWORD *)this + 2147) = 0;
      }
      if ( sub_5969C0(a2) )
        return -1;
      sub_5AADD0((int)this, (int)a2);
      sub_597BA0(a2, 2u);
    }
    for ( i = (unsigned int *)*((_DWORD *)this + 2145); i; i = (unsigned int *)i[8] )
    {
      if ( (*i & 2) != 0 )
      {
        sub_5A1410(i, 2);
      }
      else if ( (*i & 1) != 0 )
      {
        sub_5A1410(i, 1);
      }
    }
    for ( j = (int *)*((_DWORD *)this + 2171); j; j = (int *)j[8] )
      sub_5A3200(j);
    *((_DWORD *)this + 1282) |= 0x10000000u;
  }
  return 0;
}
