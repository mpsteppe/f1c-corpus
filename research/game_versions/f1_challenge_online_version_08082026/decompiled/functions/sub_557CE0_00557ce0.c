int __thiscall sub_557CE0(char *lpSrcStr, int a2)
{
  _DWORD *v3; // ebx
  int v6; // edi
  int v7; // eax
  _DWORD *v8; // eax
  int v9; // edi
  _DWORD *v10; // ebx
  int v11; // edi
  int v12; // eax
  _DWORD *v13; // eax
  void *v14; // edi
  _DWORD *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ebp
  int v22; // ebx
  int v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  int v26; // eax
  int v27; // edx
  int v28; // eax
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ebx
  int v33; // ebp
  int v34; // eax
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  int v37; // eax
  int v38; // edx
  int v39; // eax
  int v40; // [esp-Ch] [ebp-20h]
  int v41; // [esp-8h] [ebp-1Ch]
  _DWORD *v42; // [esp+10h] [ebp-4h]
  _DWORD *v43; // [esp+18h] [ebp+4h]
  int v44; // [esp+18h] [ebp+4h]
  int v45; // [esp+18h] [ebp+4h]

  v3 = (_DWORD *)sub_545F40((_DWORD *)dword_8B8F28);
  v42 = v3;
  if ( !v3 )
    return -1;
  if ( sub_5474D0(
         v3,
         (const char *)a2,
         *(_DWORD *)(a2 + 88),
         *(_DWORD *)(a2 + 92),
         (_BYTE *)(a2 + 112),
         (_BYTE *)(a2 + 144),
         *(_DWORD *)(a2 + 104)) )
  {
    return -1;
  }
  if ( sub_5487A0(v3) )
    return -1;
  v6 = *(_DWORD *)(a2 + 36);
  if ( v6 <= 0 )
    return -1;
  *((_DWORD *)lpSrcStr + 11) = v6;
  v7 = sub_587C03((v6 << 7) + 4);
  if ( v7 )
  {
    v8 = (_DWORD *)(v7 + 4);
    *(v8 - 1) = v6;
    v9 = v6 - 1;
    v43 = v8;
    v10 = v8;
    if ( v9 >= 0 )
    {
      v11 = v9 + 1;
      do
      {
        sub_5573A0(v10);
        v10 += 32;
        --v11;
      }
      while ( v11 );
      v8 = v43;
    }
    v3 = v42;
  }
  else
  {
    v8 = 0;
  }
  *((_DWORD *)lpSrcStr + 13) = v8;
  strcpy(lpSrcStr, (const char *)a2);
  sub_589901(lpSrcStr);
  v12 = sub_587C03(4 * *((_DWORD *)lpSrcStr + 11));
  v40 = 4 * *((_DWORD *)lpSrcStr + 11);
  *((_DWORD *)lpSrcStr + 16) = v12;
  *((_DWORD *)lpSrcStr + 15) = sub_587C03(v40);
  if ( (*(_BYTE *)(a2 + 88) & 0x20) == 0 )
    *(_DWORD *)(a2 + 100) = 65538;
  *((_DWORD *)lpSrcStr + 19) = 1;
  v13 = (_DWORD *)sub_587C03(68);
  if ( v13 )
  {
    v14 = v13 + 1;
    *v13 = 1;
    sub_53C2A0(v13 + 1);
  }
  else
  {
    v14 = 0;
  }
  *((_DWORD *)lpSrcStr + 20) = v14;
  memset(v14, 0, 0x40u);
  *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 4) = sub_548890(v3, lpSrcStr);
  v15 = *(_DWORD **)(*((_DWORD *)lpSrcStr + 20) + 4);
  if ( v15 )
  {
    sub_5473C0(v15);
    sub_547240(
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 4),
      (unsigned __int16)*(_DWORD *)(a2 + 100),
      *(unsigned __int16 *)(a2 + 102));
    v16 = *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 4);
    if ( *(int *)(v16 + 164) > 0 )
    {
      sub_54FCB0(*(_DWORD **)(v16 + 168), *(_DWORD *)(a2 + 104));
      sub_54FCC0(*(_DWORD **)(*(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 4) + 168), *(_DWORD *)(a2 + 108));
    }
  }
  **((_DWORD **)lpSrcStr + 20) = 0;
  if ( (*(_BYTE *)(a2 + 88) & 8) != 0 )
    **((_DWORD **)lpSrcStr + 20) |= 1u;
  if ( (*(_BYTE *)(a2 + 88) & 0x10) != 0 )
    **((_DWORD **)lpSrcStr + 20) |= 2u;
  if ( (*(_BYTE *)(a2 + 32) & 0x10) != 0 )
    *((_DWORD *)lpSrcStr + 8) |= 0x210u;
  if ( (*(_BYTE *)(a2 + 32) & 0x20) != 0 )
    *((_DWORD *)lpSrcStr + 8) |= 0x220u;
  if ( (*(_DWORD *)(a2 + 32) & 0x200) != 0 )
    *((_DWORD *)lpSrcStr + 8) |= 0x200u;
  v17 = *(_DWORD *)(a2 + 32);
  if ( (v17 & 1) != 0 )
  {
    v18 = *((_DWORD *)lpSrcStr + 8) | 1;
    *((_DWORD *)lpSrcStr + 8) = v18;
    *((_DWORD *)lpSrcStr + 9) = 4;
    if ( (v18 & 0x200) != 0 )
      *((_DWORD *)lpSrcStr + 10) = 6;
    else
      *((_DWORD *)lpSrcStr + 10) = 12;
    *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 8) = 4 * *((_DWORD *)lpSrcStr + 11);
    *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 16) = *((_DWORD *)lpSrcStr + 10) * *((_DWORD *)lpSrcStr + 11);
    if ( *(char *)(a2 + 32) >= 0 )
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 12) = sub_587C03(144);
    else
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 12) = sub_587C03(36 * *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 8));
    *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 20) = sub_587C03(2 * *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 16));
    v19 = *(_DWORD *)(a2 + 96);
    if ( (v19 & 0xFF000000) == 0 )
      v19 |= 0xFF000000;
    if ( (*(_BYTE *)(a2 + 32) & 0x80) != 0 )
    {
      v20 = *((_DWORD *)lpSrcStr + 11);
      v21 = 0;
      *((_DWORD *)lpSrcStr + 8) |= 0x80u;
      if ( v20 > 0 )
      {
        v44 = 0;
        do
        {
          v22 = *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 12);
          v23 = 9 * v21 * *((_DWORD *)lpSrcStr + 9);
          *(_DWORD *)(v22 + 4 * v23) = -1090519040;
          *(_DWORD *)(v22 + 4 * v23 + 4) = 1056964608;
          *(_DWORD *)(v22 + 4 * v23 + 24) = v19;
          v24 = (_DWORD *)(v22 + 4 * v23);
          v24[2] = 0;
          v24[9] = -1090519040;
          v24[10] = -1090519040;
          v24[11] = 0;
          v24[15] = v19;
          v24 += 18;
          *v24 = 1056964608;
          v24[1] = -1090519040;
          v24[2] = 0;
          v24[6] = v19;
          v24 += 9;
          *v24 = 1056964608;
          v24[1] = 1056964608;
          v24[2] = 0;
          v24[6] = v19;
          *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v44 + 4) = v21;
          *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v44 + 12) = v19;
          v44 += 128;
          ++v21;
        }
        while ( v21 < *((_DWORD *)lpSrcStr + 11) );
      }
    }
    else
    {
      v25 = *(_DWORD **)(*((_DWORD *)lpSrcStr + 20) + 12);
      v25[6] = v19;
      v25[1] = 1056964608;
      v25[2] = 0;
      v25 += 9;
      *(v25 - 9) = -1090519040;
      *v25 = -1090519040;
      v25[1] = -1090519040;
      v25[2] = 0;
      v25[6] = v19;
      v25 += 9;
      *v25 = 1056964608;
      v25[1] = -1090519040;
      v25[2] = 0;
      v25[6] = v19;
      v25 += 9;
      *v25 = 1056964608;
      v25[1] = 1056964608;
      v25[2] = 0;
      v25[6] = v19;
      v26 = 0;
      if ( *((int *)lpSrcStr + 11) > 0 )
      {
        v27 = 0;
        do
        {
          *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v27 + 4) = v26;
          *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v27 + 12) = v19;
          ++v26;
          v27 += 128;
        }
        while ( v26 < *((_DWORD *)lpSrcStr + 11) );
      }
    }
  }
  else
  {
    if ( (v17 & 4) != 0 )
      return -1;
    if ( (v17 & 2) != 0 )
    {
      v28 = *((_DWORD *)lpSrcStr + 20);
      *((_DWORD *)lpSrcStr + 8) |= 2u;
      *((_DWORD *)lpSrcStr + 9) = 8;
      if ( (*(_BYTE *)v28 & 0x10) != 0 )
        *((_DWORD *)lpSrcStr + 10) = 48;
      else
        *((_DWORD *)lpSrcStr + 10) = 36;
      *(_DWORD *)(v28 + 8) = 8 * *((_DWORD *)lpSrcStr + 11);
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 16) = *((_DWORD *)lpSrcStr + 10) * *((_DWORD *)lpSrcStr + 11);
      if ( *(char *)(a2 + 32) >= 0 )
        v29 = *((_DWORD *)lpSrcStr + 9);
      else
        v29 = *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 8);
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 12) = sub_587C03(36 * v29);
      *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 20) = sub_587C03(2 * *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 16));
      v30 = *(_DWORD *)(a2 + 96);
      if ( (v30 & 0xFF000000) == 0 )
        v30 |= 0xFF000000;
      if ( (*(_BYTE *)(a2 + 32) & 0x80) != 0 )
      {
        v31 = *((_DWORD *)lpSrcStr + 11);
        v32 = 0;
        *((_DWORD *)lpSrcStr + 8) |= 0x80u;
        if ( v31 > 0 )
        {
          v45 = 0;
          do
          {
            v33 = *(_DWORD *)(*((_DWORD *)lpSrcStr + 20) + 12);
            v34 = 9 * v32 * *((_DWORD *)lpSrcStr + 9);
            *(_DWORD *)(v33 + 4 * v34) = -1090519040;
            *(_DWORD *)(v33 + 4 * v34 + 4) = 1056964608;
            *(_DWORD *)(v33 + 4 * v34 + 8) = -1090519040;
            *(_DWORD *)(v33 + 4 * v34 + 24) = v30;
            v35 = (_DWORD *)(v33 + 4 * v34);
            v35[9] = -1090519040;
            v35[10] = -1090519040;
            v35[11] = -1090519040;
            v35[15] = v30;
            v35 += 9;
            v35[9] = 1056964608;
            v35[10] = -1090519040;
            v35[11] = -1090519040;
            v35[15] = v30;
            v35 += 9;
            v35[9] = 1056964608;
            v35[10] = 1056964608;
            v35[11] = -1090519040;
            v35[15] = v30;
            v35 += 9;
            v35[9] = -1090519040;
            v35[10] = 1056964608;
            v35[11] = 1056964608;
            v35[15] = v30;
            v35 += 9;
            v35[9] = -1090519040;
            v35[10] = -1090519040;
            v35[11] = 1056964608;
            v35[15] = v30;
            v35 += 18;
            *v35 = 1056964608;
            v35[1] = -1090519040;
            v35[2] = 1056964608;
            v35[6] = v30;
            v35 += 9;
            *v35 = 1056964608;
            v35[1] = 1056964608;
            v35[2] = 1056964608;
            v35[6] = v30;
            *(_DWORD *)(v45 + *((_DWORD *)lpSrcStr + 13) + 4) = v32;
            *(_DWORD *)(v45 + *((_DWORD *)lpSrcStr + 13) + 12) = v30;
            v45 += 128;
            ++v32;
          }
          while ( v32 < *((_DWORD *)lpSrcStr + 11) );
        }
      }
      else
      {
        v36 = *(_DWORD **)(*((_DWORD *)lpSrcStr + 20) + 12);
        v36[6] = v30;
        v36[1] = 1028443341;
        *v36 = -1119040307;
        v36[2] = -1119040307;
        v36[9] = -1119040307;
        v36[10] = -1119040307;
        v36[11] = -1119040307;
        v36[15] = v30;
        v36 += 9;
        v36[9] = 1028443341;
        v36[10] = -1119040307;
        v36[11] = -1119040307;
        v36[15] = v30;
        v36 += 9;
        v36[9] = 1028443341;
        v36[10] = 1028443341;
        v36[11] = -1119040307;
        v36[15] = v30;
        v36 += 9;
        v36[9] = -1119040307;
        v36[10] = 1028443341;
        v36[11] = 1028443341;
        v36[15] = v30;
        v36 += 9;
        v36[9] = -1119040307;
        v36[10] = -1119040307;
        v36[11] = 1028443341;
        v36[15] = v30;
        v36 += 18;
        *v36 = 1028443341;
        v36[1] = -1119040307;
        v36[2] = 1028443341;
        v36[6] = v30;
        v36 += 9;
        *v36 = 1028443341;
        v36[1] = 1028443341;
        v36[2] = 1028443341;
        v36[6] = v30;
        v37 = 0;
        if ( *((int *)lpSrcStr + 11) > 0 )
        {
          v38 = 0;
          do
          {
            *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v38 + 4) = v37;
            *(_DWORD *)(*((_DWORD *)lpSrcStr + 13) + v38 + 12) = v30;
            ++v37;
            v38 += 128;
          }
          while ( v37 < *((_DWORD *)lpSrcStr + 11) );
        }
      }
    }
  }
  v39 = sub_587C03(4 * *((_DWORD *)lpSrcStr + 19));
  v41 = 4 * *((_DWORD *)lpSrcStr + 19);
  *((_DWORD *)lpSrcStr + 17) = v39;
  *((_DWORD *)lpSrcStr + 18) = sub_587C03(v41);
  return 0;
}
