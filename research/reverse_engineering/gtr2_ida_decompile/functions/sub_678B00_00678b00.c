int __stdcall sub_678B00(int *a1)
{
  int *v1; // ecx
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // edx
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  int v12; // eax
  int v13; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  v4 = v2[1];
  if ( !v4 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v3 = *v2;
    v4 = v2[1];
    v1 = a1;
  }
  v5 = *v3;
  v6 = v4 - 1;
  v7 = v3 + 1;
  v13 = v5;
  if ( !v6 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(v1) )
      return 0;
    v7 = *v2;
    v6 = v2[1];
    v1 = a1;
    v5 = v13;
  }
  v9 = *v7;
  v10 = v6 - 1;
  v11 = v7 + 1;
  v14 = v9;
  if ( v5 != 255 || v9 != 216 )
  {
    v12 = *v1;
    *(_DWORD *)(v12 + 20) = 53;
    *(_DWORD *)(v12 + 24) = v5;
    *(_DWORD *)(v12 + 28) = v14;
    (*(void (__stdcall **)(int *))v12)(v1);
    v1 = a1;
    v9 = v14;
  }
  v2[1] = v10;
  *v2 = v11;
  v1[105] = v9;
  return 1;
}
