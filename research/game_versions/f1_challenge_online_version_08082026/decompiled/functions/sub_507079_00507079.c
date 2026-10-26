int __userpurge sub_507079@<eax>(_DWORD *a1@<ebp>, int a2, int a3, int a4)
{
  _DWORD *v4; // ecx
  _DWORD *v5; // ebx
  unsigned int v6; // esi
  bool v7; // zf
  int result; // eax
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  int v18; // edi
  unsigned int v19; // eax
  unsigned int v20; // edx
  int v21; // ecx
  _DWORD *v22; // edi
  _DWORD *v23; // esi
  unsigned int v24; // eax
  int v25; // esi
  unsigned int v26; // eax
  int v27; // edx
  int v28; // ecx
  int v29; // esi
  _DWORD *v30; // edi
  _DWORD *v31; // esi
  int v32; // esi
  bool v33; // cf

  sub_58A5D8();
  v5 = v4;
  v6 = v4[1037] + a1[2];
  a1[3] += v4[1040];
  v7 = v4[1072] == 0;
  a1[2] = v6;
  if ( v7 )
  {
    result = sub_587C03(8 * v4[1067] * v4[1066]);
    v5[1072] = result;
    if ( !result )
      return result;
    memset((void *)result, 0, 8 * v5[1067] * v5[1066]);
  }
  v9 = v5[1072] + 8 * (((v6 - v5[1060]) >> 2) + v5[1066] * (a1[3] - v5[1063]));
  v7 = *(_DWORD *)(v9 + 4) == 0;
  *(a1 - 4) = v9;
  if ( v7 )
  {
    v10 = 16 * v5[1065];
    *(a1 - 6) = v10;
    v11 = sub_587C03(16 * v10);
    *(a1 - 5) = v11;
    *(a1 - 1) = 0;
    if ( v11 )
    {
      sub_5008C2(v11, 16, *(a1 - 6), (int (__thiscall *)(int))sub_5007EC);
      result = *(a1 - 5);
    }
    else
    {
      result = 0;
    }
    *(a1 - 1) = -1;
    *(_DWORD *)(v9 + 4) = result;
    if ( !result )
      return result;
    *(_DWORD *)v9 = 0;
    ++v5[1071];
  }
  if ( !*(_DWORD *)v9 )
  {
    v12 = 4;
    if ( v5[1039] >= 4u )
      v12 = v5[1039];
    v13 = v6 & 3;
    if ( v13 < v5[1037] || v13 + 4 > v12 )
    {
      v17 = v5[1059];
      v18 = v5[6] + a1[3] * v5[1045] + v5[1056] * (v17 >> 2) + v5[1044] * (v6 >> 2);
      *(a1 - 5) = *(_DWORD *)(*(a1 - 4) + 4);
      *(a1 - 6) = v17;
      while ( v17 < v5[1061] )
      {
        ((void (__cdecl *)(_DWORD, int))v5[1057])(*(a1 - 5), v18);
        v18 += v5[1056];
        *(a1 - 5) += 256;
        *(a1 - 6) += 4;
        v17 = *(a1 - 6);
      }
      v9 = *(a1 - 4);
    }
    else
    {
      v14 = v5[1038];
      *(a1 - 6) = 4;
      if ( v14 >= 4 )
        *(a1 - 6) = v14;
      v15 = v5[1059];
      if ( v15 < v5[1036] )
        ((void (__cdecl *)(_DWORD, unsigned int))v5[1057])(
          *(_DWORD *)(v9 + 4),
          v5[6] + a1[3] * v5[1045] + v5[1044] * (v6 >> 2) + v5[1056] * (v15 >> 2));
      v16 = v5[1061];
      if ( v16 > *(a1 - 6) )
        ((void (__cdecl *)(_DWORD, unsigned int))v5[1057])(
          *(_DWORD *)(v9 + 4),
          v5[6] + a1[3] * v5[1045] + v5[1044] * (v6 >> 2) + v5[1056] * ((v16 - 4) >> 2));
    }
  }
  if ( v5[1042] )
    a1[4] = sub_506CE2(v5, a1[4]);
  v19 = v5[1036] - v5[1059];
  v20 = v19 + v5[1046];
  v21 = (v6 - v5[1060]) & 3;
  if ( v19 < v20 )
  {
    do
    {
      v22 = (_DWORD *)(*(_DWORD *)(*(a1 - 4) + 4) + 16 * (v19 & 3 | (4 * (v21 | v19 & 0xFFFFFFFC))));
      v23 = (_DWORD *)a1[4];
      a1[4] = v23 + 4;
      *v22 = *v23++;
      *++v22 = *v23++;
      *++v22 = *v23;
      ++v19;
      v22[1] = v23[1];
    }
    while ( v19 < v20 );
    v6 = a1[2];
    v9 = *(a1 - 4);
  }
  result = (v6 - v5[1060]) & 3;
  if ( v5[1053] )
  {
    a1[4] = 0;
    do
    {
      if ( (a1[4] & v5[1055]) == result )
        *(_DWORD *)v9 |= 1 << a1[4];
      ++a1[4];
    }
    while ( a1[4] < 4u );
  }
  else
  {
    *(_DWORD *)v9 |= 1 << result;
  }
  if ( *(_DWORD *)v9 == 15 )
  {
    v24 = v5[1059];
    v25 = v5[6] + a1[3] * v5[1045] + v5[1056] * (v24 >> 2) + v5[1044] * (v6 >> 2);
    a1[3] = *(_DWORD *)(v9 + 4);
    for ( *(a1 - 6) = v24; ; v24 = *(a1 - 6) )
    {
      v33 = v24 < v5[1061];
      *(a1 - 5) = v25;
      if ( !v33 )
        break;
      v26 = 0;
      if ( v5[1053] )
      {
        v27 = a1[3];
        do
        {
          a1[4] = 0;
          v28 = 4 * v26;
          a1[2] = v27;
          do
          {
            v29 = (v5[1054] & a1[4]) + 4 * (v26 & v5[1055]);
            if ( v28 != v29 )
            {
              v30 = (_DWORD *)a1[2];
              v31 = (_DWORD *)(a1[3] + 16 * v29);
              *v30 = *v31++;
              *++v30 = *v31++;
              *++v30 = *v31;
              v30[1] = v31[1];
              v9 = *(a1 - 4);
            }
            ++a1[4];
            a1[2] += 16;
            ++v28;
          }
          while ( a1[4] < 4u );
          v27 = a1[2];
          ++v26;
        }
        while ( v26 < 4 );
      }
      v32 = *(a1 - 5);
      ((void (__cdecl *)(int, _DWORD))v5[1058])(v32, a1[3]);
      v25 = v5[1056] + v32;
      a1[3] += 256;
      *(a1 - 6) += 4;
    }
    if ( v9 + 8 >= v5[1072] + 8 * v5[1066] * v5[1067] || *(_DWORD *)(v9 + 8) || *(_DWORD *)(v9 + 12) )
    {
      result = sub_587BCF(*(LPVOID *)(v9 + 4));
      --v5[1071];
    }
    else
    {
      result = *(_DWORD *)(v9 + 4);
      *(_DWORD *)(v9 + 12) = result;
      *(_DWORD *)(v9 + 4) = 0;
    }
    *(_DWORD *)(v9 + 4) = 0;
  }
  return result;
}
