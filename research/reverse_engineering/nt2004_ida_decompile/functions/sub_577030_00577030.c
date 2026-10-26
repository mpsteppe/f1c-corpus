char __thiscall sub_577030(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  unsigned int v5; // esi
  unsigned __int16 *v6; // edx
  int v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // edi
  char v10; // al
  _BYTE *v11; // ecx
  char v12; // dl
  int i; // [esp+10h] [ebp+4h]
  int v15; // [esp+14h] [ebp+8h]

  v4 = this[2];
  v5 = *(unsigned __int16 *)(v4 + 4 * a2 + 2);
  v6 = (unsigned __int16 *)(v4 + 4 * a2);
  v7 = 0;
  v8 = 0;
  if ( (_WORD)v5 )
  {
    do
      v7 |= 1 << v8++;
    while ( v8 < v5 );
  }
  v9 = 0;
  v15 = v7 & a3;
  for ( i = *v6 + v5 - 1; v9 < v5; *v11 = v12 )
  {
    v10 = 1 << ((i - v9) & 7);
    v11 = (_BYTE *)(((i - v9) >> 3) + *this);
    if ( ((1 << v9) & v15) != 0 )
      v12 = v10 | *v11;
    else
      v12 = ~v10 & *v11;
    ++v9;
  }
  return 1;
}
