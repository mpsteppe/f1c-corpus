int __thiscall sub_52DD50(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  unsigned int v4; // eax
  int result; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edx

  v2 = this[2345];
  v3 = this[2347];
  this[2346] = v3;
  if ( v2 )
    v4 = _byteswap_ulong(*(_DWORD *)((v3 >> 3) + v2));
  else
    v4 = this[2364];
  result = CMpegBase_ProcessHeader((int)this, v4);
  if ( result != -1 )
  {
    v6 = this[2342];
    v7 = this[2346] + 32;
    this[2346] = v7;
    v8 = v7 + 8 * v6;
    result = 0;
    this[2347] = v8;
  }
  return result;
}

