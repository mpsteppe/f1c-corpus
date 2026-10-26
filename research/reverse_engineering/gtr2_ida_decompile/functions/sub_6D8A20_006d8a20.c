int __usercall sub_6D8A20@<eax>(int *a1@<esi>)
{
  int v1; // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ebx
  _DWORD *v16; // edi
  int v17; // eax
  int v18; // edx
  int v19; // eax
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int result; // eax
  int v24; // [esp-10h] [ebp-10h]
  int v25; // [esp-10h] [ebp-10h]
  int v26; // [esp-Ch] [ebp-Ch]
  int v27; // [esp-Ch] [ebp-Ch]

  if ( !a1[8] || !a1[7] || a1[15] <= 0 || a1[9] <= 0 )
  {
    v1 = *a1;
    *(_DWORD *)(v1 + 20) = 32;
    (*(void (__stdcall **)(int *))v1)(a1);
  }
  if ( a1[8] > 65500 || a1[7] > 65500 )
  {
    v2 = *a1;
    *(_DWORD *)(v2 + 20) = 41;
    *(_DWORD *)(v2 + 24) = 65500;
    (*(void (__stdcall **)(int *))v2)(a1);
  }
  v3 = a1[14];
  if ( v3 != 8 )
  {
    v4 = *a1;
    *(_DWORD *)(v4 + 20) = 15;
    *(_DWORD *)(v4 + 24) = v3;
    (*(void (__stdcall **)(int *))v4)(a1);
  }
  v5 = a1[15];
  if ( v5 > 10 )
  {
    v6 = *a1;
    *(_DWORD *)(v6 + 20) = 26;
    *(_DWORD *)(v6 + 24) = v5;
    *(_DWORD *)(v6 + 28) = 10;
    (*(void (__stdcall **)(int *))v6)(a1);
  }
  v7 = a1[15];
  v8 = 0;
  a1[60] = 1;
  a1[61] = 1;
  if ( v7 > 0 )
  {
    v9 = (int *)(a1[17] + 12);
    do
    {
      v10 = *(v9 - 1);
      if ( v10 <= 0 || v10 > 4 || *v9 <= 0 || *v9 > 4 )
      {
        v11 = *a1;
        *(_DWORD *)(v11 + 20) = 18;
        (*(void (__stdcall **)(int *))v11)(a1);
      }
      v12 = a1[60];
      if ( v12 <= *(v9 - 1) )
        v12 = *(v9 - 1);
      v13 = *v9;
      a1[60] = v12;
      v14 = a1[61];
      if ( v14 <= v13 )
        v14 = v13;
      a1[61] = v14;
      ++v8;
      v9 += 21;
    }
    while ( v8 < a1[15] );
  }
  v15 = 0;
  if ( a1[15] > 0 )
  {
    v16 = (_DWORD *)(a1[17] + 36);
    do
    {
      v26 = 8 * a1[60];
      v24 = a1[7] * *(v16 - 7);
      *(v16 - 8) = v15;
      *v16 = 8;
      v17 = sub_6B5FB0(v24, v26);
      v18 = a1[61];
      *(v16 - 2) = v17;
      v19 = sub_6B5FB0(a1[8] * *(v16 - 6), 8 * v18);
      v27 = a1[60];
      v25 = a1[7] * *(v16 - 7);
      *(v16 - 1) = v19;
      v20 = sub_6B5FB0(v25, v27);
      v21 = a1[8] * *(v16 - 6);
      v16[1] = v20;
      v16[2] = sub_6B5FB0(v21, a1[61]);
      v22 = a1[15];
      v16[3] = 1;
      ++v15;
      v16 += 21;
    }
    while ( v15 < v22 );
  }
  result = sub_6B5FB0(a1[8], 8 * a1[61]);
  a1[62] = result;
  return result;
}
