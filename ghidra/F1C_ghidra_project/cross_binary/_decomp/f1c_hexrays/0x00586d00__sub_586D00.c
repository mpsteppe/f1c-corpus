// f1c  0x00586d00  size=100
int __thiscall sub_586D00(_DWORD *this)
{
  int v1; // edx
  int v2; // esi
  unsigned __int16 v3; // di
  int result; // eax
  unsigned int v5; // esi
  int v6; // ebp
  unsigned int v7; // edi
  int v8; // [esp+Ch] [ebp-4h]

  v1 = this[13];
  v2 = this[7];
  v3 = *(_WORD *)(v2 + 4 * v1);
  result = 0;
  v5 = *(unsigned __int16 *)(v2 + 4 * v1 + 2);
  v8 = 0;
  v6 = v3 + (unsigned __int16)v5 - 1;
  v7 = 0;
  if ( (_WORD)v5 )
  {
    do
    {
      if ( ((unsigned __int8)(1 << ((v6 - v7) & 7)) & *(_BYTE *)(((v6 - v7) >> 3) + this[5])) != 0 )
        v8 |= 1 << v7;
      ++v7;
    }
    while ( v7 < v5 );
    return v8;
  }
  return result;
}
