BOOL __cdecl sub_59373E(int a1, int a2, _DWORD *a3)
{
  int v3; // eax
  int v4; // ecx
  BOOL result; // eax

  v3 = *(_DWORD *)(a1 + 4);
  result = 1;
  if ( v3 && *(_BYTE *)(v3 + 8) )
  {
    v4 = *(_DWORD *)(a2 + 4);
    if ( v3 != v4 )
    {
      if ( sub_58FB90((unsigned int *)(v3 + 8), (_BYTE *)(v4 + 8)) )
        return 0;
    }
    if ( (*(_BYTE *)a2 & 2) != 0 && (*(_BYTE *)a1 & 8) == 0
      || (*a3 & 1) != 0 && (*(_BYTE *)a1 & 1) == 0
      || (*a3 & 2) != 0 && (*(_BYTE *)a1 & 2) == 0 )
    {
      return 0;
    }
  }
  return result;
}

