int __thiscall sub_5A3D10(_DWORD *this, int a2)
{
  unsigned __int16 *v2; // edx
  unsigned int v3; // edi
  int result; // eax
  unsigned int v5; // esi
  int v6; // [esp+Ch] [ebp-4h]

  v2 = (unsigned __int16 *)(this[2] + 4 * a2);
  v3 = v2[1];
  result = 0;
  v5 = 0;
  v6 = 0;
  if ( v2[1] )
  {
    do
    {
      if ( ((unsigned __int8)(1 << ((*v2 + v3 - 1 - v5) & 7)) & *(_BYTE *)(((*v2 + v3 - 1 - v5) >> 3) + *this)) != 0 )
        v6 |= 1 << v5;
      ++v5;
    }
    while ( v5 < v3 );
    return v6;
  }
  return result;
}
