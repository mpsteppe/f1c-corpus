char __cdecl sub_54E166(_DWORD *a1)
{
  _DWORD *v1; // eax
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v5; // edx
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  int v9; // ecx
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // edi
  int v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+Ch] [ebp-4h]

  v1 = a1;
  v2 = (unsigned __int8 **)a1[5];
  v3 = v2[1];
  v4 = *v2;
  if ( !v3 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) )
      return 0;
    v4 = *v2;
    v3 = v2[1];
    v1 = a1;
  }
  v5 = *v4;
  v6 = v3 - 1;
  v7 = v4 + 1;
  v12 = v5;
  if ( !v6 )
  {
    if ( !((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(v1) )
      return 0;
    v7 = *v2;
    v6 = v2[1];
    v1 = a1;
    v5 = v12;
  }
  v9 = *v7;
  v10 = v6 - 1;
  v11 = v7 + 1;
  v13 = v9;
  if ( v5 != 255 || v9 != 216 )
  {
    *(_DWORD *)(*v1 + 20) = 52;
    *(_DWORD *)(*v1 + 24) = v5;
    *(_DWORD *)(*v1 + 28) = v9;
    (*(void (__cdecl **)(_DWORD *))*v1)(v1);
    v1 = a1;
    v9 = v13;
  }
  v1[94] = v9;
  *v2 = v11;
  v2[1] = v10;
  return 1;
}
