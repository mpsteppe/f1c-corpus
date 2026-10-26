int __stdcall sub_6A323B(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  unsigned int v3; // esi

  v2 = a1;
  v3 = 0;
  while ( *v2 == -1 || *v2 == *(_DWORD *)((char *)v2 + a2 - (_DWORD)a1) )
  {
    ++v3;
    ++v2;
    if ( v3 >= 4 )
      return 1;
  }
  return 0;
}
