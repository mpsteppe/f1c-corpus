int __stdcall sub_678940(int *a1)
{
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // edi
  unsigned __int16 v5; // cx
  unsigned __int8 *v6; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // eax
  int v11; // [esp+Ch] [ebp-4h]
  int v12; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v13; // [esp+18h] [ebp+8h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  if ( !v3 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v3 = v2[1];
    v4 = *v2;
  }
  LOBYTE(v5) = 0;
  HIBYTE(v5) = *v4;
  v6 = v4 + 1;
  v13 = v3 - 1;
  v11 = v5;
  if ( v3 == (unsigned __int8 *)1 )
  {
    if ( !((int (__stdcall *)(int *))v2[3])(a1) )
      return 0;
    v6 = *v2;
    v13 = v2[1];
  }
  v8 = a1[105];
  v9 = v11 + *v6 - 2;
  v10 = *a1;
  *(_DWORD *)(v10 + 20) = 91;
  *(_DWORD *)(v10 + 24) = v8;
  v12 = v9;
  *(_DWORD *)(v10 + 28) = v9;
  (*(void (__stdcall **)(int *, int))(v10 + 4))(a1, 1);
  v2[1] = v13 - 1;
  *v2 = v6 + 1;
  if ( v12 > 0 )
    (*(void (__stdcall **)(int *, int))(a1[6] + 16))(a1, v12);
  return 1;
}
