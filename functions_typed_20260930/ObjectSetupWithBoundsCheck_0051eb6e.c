int __cdecl sub_51EB6E(_DWORD *a1)
{
  _DWORD *v1; // eax
  int result; // eax

  v1 = (_DWORD *)(*(int (__cdecl **)(_DWORD *, int, int))a1[1])(a1, 1, 88);
  a1[105] = v1;
  v1[17] = 0;
  v1[13] = 0;
  *v1 = CodecModeSelect;
  v1[2] = nullsub_4;
  v1[3] = VirtualCallWithIntegerSet;
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
  ImageBufferStrideFill(a1);
  result = sub_51E3E7(a1);
  if ( a1[19] == 2 )
    return VirtualArrayFill(a1);
  return result;
}

