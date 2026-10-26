char __cdecl sub_54DFF3(_DWORD *a1)
{
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // ebx
  unsigned __int16 v4; // ax
  unsigned __int8 *v5; // ebx
  int v7; // [esp+Ch] [ebp-4h]
  int v8; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v9; // [esp+18h] [ebp+8h]
  unsigned __int8 *v10; // [esp+18h] [ebp+8h]

  v2 = (unsigned __int8 **)a1[5];
  v3 = *v2;
  v9 = v2[1];
  if ( !v9 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v3 = *v2;
    v9 = v2[1];
  }
  v10 = v9 - 1;
  LOBYTE(v4) = 0;
  HIBYTE(v4) = *v3;
  v5 = v3 + 1;
  v7 = v4;
  if ( !v10 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v5 = *v2;
    v10 = v2[1];
  }
  v8 = *v5 + v7;
  *(_DWORD *)(*a1 + 20) = 90;
  *(_DWORD *)(*a1 + 24) = a1[94];
  *(_DWORD *)(*a1 + 28) = v8;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
  *v2 = v5 + 1;
  v2[1] = v10 - 1;
  (*(void (__cdecl **)(_DWORD *, int))(a1[5] + 16))(a1, v8 - 2);
  return 1;
}
