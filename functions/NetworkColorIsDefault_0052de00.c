BOOL __thiscall sub_52DE00(_DWORD *this)
{
  unsigned int *v1; // eax
  unsigned int v3; // [esp+0h] [ebp-4h]

  v1 = (unsigned int *)this[2345];
  if ( v1 )
    v3 = *v1;
  else
    v3 = this[2364];
  return CMpegBase_ProcessHeader((int)this, _byteswap_ulong(v3)) == -1;
}
