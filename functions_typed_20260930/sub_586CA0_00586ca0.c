bool __thiscall sub_586CA0(_DWORD *this)
{
  unsigned __int16 *v1; // eax
  unsigned int v2; // esi
  unsigned int v3; // edi
  int v4; // ebp
  int v6; // [esp+Ch] [ebp-4h]

  v1 = (unsigned __int16 *)(this[7] + 4 * this[15]);
  v2 = v1[1];
  v3 = 0;
  v6 = 0;
  if ( (_WORD)v2 )
  {
    do
    {
      v4 = *v1 + (unsigned __int16)v2 - 1;
      if ( ((unsigned __int8)(1 << ((v4 - v3) & 7)) & *(_BYTE *)(((v4 - v3) >> 3) + this[5])) != 0 )
        v6 |= 1 << v3;
      ++v3;
    }
    while ( v3 < v2 );
  }
  return v6 != 0;
}

