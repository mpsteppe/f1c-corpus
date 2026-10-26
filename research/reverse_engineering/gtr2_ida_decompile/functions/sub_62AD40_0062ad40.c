int __fastcall sub_62AD40(int *a1, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  unsigned int v17; // eax
  int v18; // esi
  int v19; // edx
  unsigned int v20; // ecx
  int v21; // eax
  int v22; // ebx
  int v23; // ecx
  int v24; // [esp+8h] [ebp-8h]
  int v26; // [esp+14h] [ebp+4h]

  v4 = a2;
  if ( !a1 || *((_BYTE *)a1 + 92) != 114 )
    return -2;
  v5 = a1[14];
  if ( v5 == -3 || v5 == -1 )
    return -1;
  if ( v5 == 1 )
    return 0;
  v24 = a2;
  a1[3] = a2;
  a1[4] = a3;
  if ( a3 )
  {
    while ( !a1[22] )
    {
      if ( !a1[1] && !a1[15] )
      {
        *_errno() = 0;
        v8 = sub_6318A2(a1[17], 1, 0x4000, a1[16]);
        a1[1] = v8;
        if ( !v8 )
        {
          v9 = a1[16];
          a1[15] = 1;
          if ( (*(_BYTE *)(v9 + 12) & 0x20) != 0 )
          {
            a1[14] = -1;
            goto LABEL_24;
          }
        }
        *a1 = a1[17];
      }
      v10 = sub_62C6A0(a1, 0);
      a1[14] = v10;
      if ( v10 == 1 )
      {
        v11 = sub_62CAA0(a1[3] - v4);
        v12 = a1[3];
        a1[19] = v11;
        v26 = v12;
        if ( sub_62AA70(a1) != a1[19] )
        {
          a1[14] = -3;
LABEL_23:
          v4 = v26;
          goto LABEL_24;
        }
        sub_62AA70(a1);
        sub_62A3D0(a1);
        if ( a1[14] )
          goto LABEL_23;
        v13 = a1[2];
        v14 = a1[5];
        sub_62C500(a1);
        a1[2] = v13;
        a1[5] = v14;
        v4 = v26;
        a1[19] = sub_62CAA0(0);
      }
      if ( a1[14] || a1[15] || !a1[4] )
        goto LABEL_24;
    }
    v17 = a1[1];
    if ( v17 > a1[4] )
      v17 = a1[4];
    if ( v17 )
    {
      qmemcpy((void *)a1[3], (const void *)*a1, v17);
      v18 = *a1;
      v19 = a1[4];
      v24 = v17 + a2;
      a1[3] = v17 + a2;
      v20 = a1[1] - v17;
      *a1 = v17 + v18;
      a1[4] = v19 - v17;
      a1[1] = v20;
    }
    v21 = a1[4];
    if ( v21 )
      a1[4] -= sub_6318A2(v24, 1, v21, a1[16]);
    v22 = a3 - a1[4];
    v23 = v22 + a1[5];
    a1[2] += v22;
    a1[5] = v23;
    if ( !v22 )
      a1[15] = 1;
    return v22;
  }
  else
  {
LABEL_24:
    v15 = sub_62CAA0(a1[3] - v4);
    v16 = a1[4];
    a1[19] = v15;
    return a3 - v16;
  }
}
