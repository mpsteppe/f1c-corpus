int __thiscall sub_4D4A50(void *this)
{
  int v2; // edi
  LPVOID **v3; // ecx
  int v4; // edi
  int v5; // ecx
  int v6; // edi
  int v7; // ecx
  int result; // eax
  void *v9; // esi

  v2 = *((_DWORD *)this + 18);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v2 = *(_DWORD *)(v2 + 4);
    sub_414480(v3, 1);
  }
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  v4 = *((_DWORD *)this + 14);
  while ( v4 )
  {
    v5 = v4;
    v4 = *(_DWORD *)(v4 + 4);
    sub_466750(v5, 1);
  }
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  v6 = *((_DWORD *)this + 10);
  while ( v6 )
  {
    v7 = v6;
    v6 = *(_DWORD *)(v6 + 4);
    sub_466750(v7, 1);
  }
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  if ( *((_DWORD *)this + 8) )
    sub_5BE8AE(*((LPVOID *)this + 8));
  if ( *((_DWORD *)this + 6) )
    sub_5BE8AE(*((LPVOID *)this + 6));
  if ( *((_DWORD *)this + 4) )
    sub_5BE8AE(*((LPVOID *)this + 4));
  result = *((_DWORD *)this + 2);
  if ( result )
    result = sub_5BE8AE(*((LPVOID *)this + 2));
  v9 = *(void **)this;
  if ( v9 )
    return sub_5BE8AE(v9);
  return result;
}
