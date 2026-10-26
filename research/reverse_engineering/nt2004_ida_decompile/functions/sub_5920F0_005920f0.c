int __thiscall sub_5920F0(void *this)
{
  int *v1; // edx
  int v2; // esi

  if ( dword_7E8D58 > 0 )
  {
    v1 = dword_7E4CC8;
    v2 = dword_7E8D58;
    do
    {
      if ( (*v1 & 0x4000) != 0 )
        *v1 = *v1 & 0xFFFFBBFF | 0x400;
      v1 += 33;
      --v2;
    }
    while ( v2 );
  }
  return sub_592130(this);
}
