int __thiscall sub_68F2C6(_DWORD *this)
{
  unsigned int v1; // edx
  int v3; // eax

  v1 = 0;
  if ( !this[56] )
    return 1;
  if ( this[2] )
  {
    do
    {
      v3 = *(_DWORD *)(this[5] + 4 * v1);
      if ( *(_DWORD *)(v3 + 68) != -1 )
      {
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[56] + 20) + 4 * *(_DWORD *)(v3 + 68)) + 12) = *(_DWORD *)(v3 + 12);
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this[56] + 20) + 4 * *(_DWORD *)(v3 + 68)) + 68) = v1;
      }
      ++v1;
    }
    while ( v1 < this[2] );
  }
  return sub_687124((_DWORD *)this[56]);
}
