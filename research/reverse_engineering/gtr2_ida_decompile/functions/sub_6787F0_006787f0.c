int __stdcall sub_6787F0(int *a1)
{
  int *v1; // edx
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // ebx
  int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // esi
  int v9; // ecx
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v17; // eax
  bool v18; // cc
  _BYTE v19[16]; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int8 **v20; // [esp+1Ch] [ebp-14h]
  unsigned int i; // [esp+20h] [ebp-10h]
  int v22; // [esp+24h] [ebp-Ch]
  unsigned int v23; // [esp+28h] [ebp-8h]
  unsigned __int8 *v24; // [esp+2Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  v20 = v2;
  if ( !v3 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v1 = a1;
    v24 = v2[1];
    v3 = v24;
  }
  v5 = 0;
  BYTE1(v5) = *v4;
  v6 = v3 - 1;
  v7 = v4 + 1;
  v22 = (unsigned __int16)v5;
  if ( v6 )
    goto LABEL_7;
  if ( !((int (__stdcall *)(int *))v2[3])(v1) )
    return 0;
  v7 = *v2;
  v1 = a1;
  v24 = v2[1];
  v6 = v24;
  v5 = v22;
LABEL_7:
  v8 = v6 - 1;
  v9 = *v7 + v5 - 2;
  v10 = v7 + 1;
  v24 = v8;
  v22 = v9;
  if ( v9 < 14 )
    v23 = v9 <= 0 ? 0 : v9;
  else
    v23 = 14;
  v11 = 0;
  for ( i = 0; v11 < v23; i = v11 )
  {
    if ( !v8 )
    {
      if ( !((int (__stdcall *)(int *))v2[3])(v1) )
        return 0;
      v10 = *v2;
      v11 = i;
      v24 = v2[1];
      v8 = v24;
      v9 = v22;
    }
    --v8;
    v19[v11++] = *v10++;
    v1 = a1;
    v24 = v8;
  }
  v12 = v9 - v23;
  v13 = v1[105] - 224;
  v22 = v12;
  if ( !v13 )
  {
    sub_678570(v23, v12, v19, v1);
    v2 = v20;
    goto LABEL_21;
  }
  if ( v13 == 14 )
  {
    sub_678750(v19, v23, v1, v12);
LABEL_21:
    v8 = v24;
    goto LABEL_22;
  }
  v14 = *v1;
  v15 = v1[105];
  *(_DWORD *)(v14 + 20) = 68;
  *(_DWORD *)(v14 + 24) = v15;
  (*(void (__stdcall **)(int *))v14)(v1);
LABEL_22:
  v17 = v22;
  v18 = v22 <= 0;
  *v2 = v10;
  v2[1] = v8;
  if ( !v18 )
    (*(void (__stdcall **)(int *, int))(a1[6] + 16))(a1, v17);
  return 1;
}
