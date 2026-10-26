// f1c  0x0050fab7  size=132
_DWORD *__cdecl sub_50FAB7(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // esi
  unsigned int v4; // ecx
  _DWORD *result; // eax
  int v6; // eax
  int v7; // eax

  v3 = a1;
  if ( a1[4] != 205 )
  {
    *(_DWORD *)(*a1 + 20) = 18;
    *(_DWORD *)(*v3 + 24) = v3[4];
    (*(void (__cdecl **)(_DWORD *))*v3)(v3);
  }
  v4 = v3[30];
  if ( v4 < v3[24] )
  {
    v6 = v3[2];
    if ( v6 )
    {
      *(_DWORD *)(v6 + 4) = v4;
      *(_DWORD *)(v3[2] + 8) = v3[24];
      (*(void (__cdecl **)(_DWORD *))v3[2])(v3);
    }
    v7 = v3[96];
    a1 = 0;
    (*(void (__cdecl **)(_DWORD *, int, _DWORD **, int))(v7 + 4))(v3, a2, &a1, a3);
    result = a1;
    v3[30] += a1;
  }
  else
  {
    *(_DWORD *)(*v3 + 20) = 119;
    (*(void (__cdecl **)(_DWORD *, int))(*v3 + 4))(v3, -1);
    return 0;
  }
  return result;
}
