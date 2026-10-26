int __stdcall sub_678490(int *a1)
{
  int *v1; // ecx
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // eax
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  int v11; // eax
  unsigned __int16 v12; // ax
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // edi
  int v16; // edx
  int v17; // eax
  int v18; // [esp+Ch] [ebp-4h]
  int v19; // [esp+Ch] [ebp-4h]
  int v20; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  if ( !v3 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v3 = v2[1];
    v1 = a1;
  }
  v5 = 0;
  BYTE1(v5) = *v4;
  v6 = v3 - 1;
  v7 = v4 + 1;
  v18 = (unsigned __int16)v5;
  if ( !v6 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(v1) )
      return 0;
    v7 = *v2;
    v6 = v2[1];
    v1 = a1;
    v5 = v18;
  }
  v8 = v6 - 1;
  v9 = *v7 + v5;
  v10 = v7 + 1;
  if ( v9 != 4 )
  {
    v11 = *v1;
    *(_DWORD *)(v11 + 20) = 11;
    (*(void (__stdcall **)(int *))v11)(v1);
    v1 = a1;
  }
  if ( !v8 )
  {
    if ( ((int (__stdcall *)(int *))v2[3])(v1) )
    {
      v10 = *v2;
      v8 = v2[1];
      v1 = a1;
      goto LABEL_12;
    }
    return 0;
  }
LABEL_12:
  LOBYTE(v12) = 0;
  HIBYTE(v12) = *v10;
  v13 = v8 - 1;
  v14 = v10 + 1;
  v19 = v12;
  if ( !v13 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(v1) )
      return 0;
    v14 = *v2;
    v13 = v2[1];
    v1 = a1;
  }
  v16 = *v14 + v19;
  v17 = *v1;
  *(_DWORD *)(v17 + 20) = 82;
  v20 = v16;
  *(_DWORD *)(v17 + 24) = v16;
  (*(void (__stdcall **)(int *, int))(v17 + 4))(v1, 1);
  *v2 = v14 + 1;
  v2[1] = v13 - 1;
  a1[70] = v20;
  return 1;
}
