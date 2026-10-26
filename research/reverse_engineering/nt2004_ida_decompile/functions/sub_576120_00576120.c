int __thiscall sub_576120(int *this)
{
  int v2; // esi
  int v3; // edi
  int result; // eax

  if ( *((_BYTE *)this + 24) && CloseHandle((HANDLE)this[4]) )
    this[4] = 0;
  v2 = *this;
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
    {
      sub_576830(*(void **)v3);
      sub_5BE8AE();
    }
    sub_5BE8AE();
  }
  result = 0;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  return result;
}
