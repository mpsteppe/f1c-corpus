int __thiscall sub_53C9C0(void *this)
{
  int *v1; // edx
  int v2; // esi

  if ( dword_8B8E30 > 0 )
  {
    v1 = dword_8B5A38;
    v2 = dword_8B8E30;
    do
    {
      if ( (*v1 & 0x4000) != 0 )
        *v1 = *v1 & 0xFFFFBBFF | 0x400;
      v1 += 33;
      --v2;
    }
    while ( v2 );
  }
  return SearchPathPrune(this);
}
