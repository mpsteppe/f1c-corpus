int __cdecl sub_55BAFC(_DWORD *a1)
{
  _DWORD *v1; // eax
  int result; // eax

  v1 = (_DWORD *)(*(int (__cdecl **)(_DWORD *, int, int))a1[1])(a1, 1, 88);
  a1[105] = v1;
  v1[17] = 0;
  v1[13] = 0;
  *v1 = sub_55BA1E;
  v1[2] = nullsub_8;
  v1[3] = sub_55BAE8;
  if ( (int)a1[25] > 4 )
  {
    *(_DWORD *)(*a1 + 20) = 54;
    *(_DWORD *)(*a1 + 24) = 4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)a1[21] > 256 )
  {
    *(_DWORD *)(*a1 + 20) = 56;
    *(_DWORD *)(*a1 + 24) = 256;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  sub_55B248(a1);
  result = sub_55B375(a1);
  if ( a1[19] == 2 )
    return sub_55B9E8(a1);
  return result;
}
