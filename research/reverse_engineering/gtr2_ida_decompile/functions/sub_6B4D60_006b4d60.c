int __usercall sub_6B4D60@<eax>(int *a1@<esi>)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  _DWORD *v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  int result; // eax
  int v27; // [esp-10h] [ebp-10h]
  int v28; // [esp-10h] [ebp-10h]
  int v29; // [esp-Ch] [ebp-Ch]
  int v30; // [esp-Ch] [ebp-Ch]

  if ( a1[8] > 65500 || a1[7] > 65500 )
  {
    v1 = *a1;
    *(_DWORD *)(v1 + 20) = 41;
    *(_DWORD *)(v1 + 24) = 65500;
    (*(void (__stdcall **)(int *))v1)(a1);
  }
  v2 = a1[54];
  if ( v2 != 8 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 15;
    *(_DWORD *)(v3 + 24) = v2;
    (*(void (__stdcall **)(int *))v3)(a1);
  }
  v4 = a1[9];
  if ( v4 > 10 )
  {
    v5 = *a1;
    *(_DWORD *)(v5 + 20) = 26;
    *(_DWORD *)(v5 + 24) = v4;
    *(_DWORD *)(v5 + 28) = 10;
    (*(void (__stdcall **)(int *))v5)(a1);
  }
  v6 = a1[9];
  v7 = 0;
  a1[78] = 1;
  a1[79] = 1;
  if ( v6 > 0 )
  {
    v8 = (int *)(a1[55] + 12);
    do
    {
      v9 = *(v8 - 1);
      if ( v9 <= 0 || v9 > 4 || *v8 <= 0 || *v8 > 4 )
      {
        v10 = *a1;
        *(_DWORD *)(v10 + 20) = 18;
        (*(void (__stdcall **)(int *))v10)(a1);
      }
      v11 = a1[78];
      if ( v11 <= *(v8 - 1) )
        v11 = *(v8 - 1);
      v12 = *v8;
      a1[78] = v11;
      v13 = a1[79];
      if ( v13 <= v12 )
        v13 = v12;
      a1[79] = v13;
      ++v7;
      v8 += 21;
    }
    while ( v7 < a1[9] );
  }
  v14 = a1[9];
  v15 = a1[55];
  v16 = 0;
  a1[80] = 8;
  if ( v14 > 0 )
  {
    v17 = (_DWORD *)(v15 + 28);
    do
    {
      v29 = 8 * a1[78];
      v27 = a1[7] * *(v17 - 5);
      v17[2] = 8;
      v18 = sub_6B5FB0(v27, v29);
      v19 = a1[79];
      *v17 = v18;
      v20 = sub_6B5FB0(a1[8] * *(v17 - 4), 8 * v19);
      v30 = a1[78];
      v28 = a1[7] * *(v17 - 5);
      v17[1] = v20;
      v21 = sub_6B5FB0(v28, v30);
      v22 = a1[8] * *(v17 - 4);
      v17[3] = v21;
      v17[4] = sub_6B5FB0(v22, a1[79]);
      v23 = a1[9];
      v17[5] = 1;
      v17[12] = 0;
      ++v16;
      v17 += 21;
    }
    while ( v16 < v23 );
  }
  v24 = sub_6B5FB0(a1[8], 8 * a1[79]);
  v25 = a1[83];
  a1[81] = v24;
  if ( v25 < a1[9] || (result = a1[56]) != 0 )
  {
    result = a1[110];
    *(_DWORD *)(result + 16) = 1;
  }
  else
  {
    *(_DWORD *)(a1[110] + 16) = 0;
  }
  return result;
}
