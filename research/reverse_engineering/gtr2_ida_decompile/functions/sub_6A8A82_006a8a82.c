int __thiscall sub_6A8A82(_DWORD *this)
{
  int v2; // ebx
  int v3; // eax
  _DWORD *v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  int result; // eax

  v2 = 0;
  if ( !this[19] )
    return 0;
  while ( 1 )
  {
    v3 = this[140];
    v4 = *(_DWORD **)(v3 + 4 * v2);
    if ( v4 )
    {
      v5 = **(_DWORD **)(v3 + 4 * v2);
      v6 = v5 & 0xFFF00000;
      v7 = v5 & 0xFFFFF;
      if ( v6 == 1615855616 || (*v4 & 0xFFF00000) == 0x60000000 )
      {
        v8 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(v4[2] + 4 * v7));
        if ( *(_DWORD *)(v8 + 4) == this[34] )
        {
          result = sub_6A86A5(this, this[139], this[136], *(_DWORD *)(v8 + 12));
          if ( result < 0 )
            break;
        }
      }
    }
    if ( (unsigned int)++v2 >= this[19] )
      return 0;
  }
  return result;
}
