char __thiscall sub_5A6A70(_DWORD *this, int a2, int a3)
{
  unsigned int v4; // edx
  int v5; // eax
  unsigned int i; // ecx
  int v7; // ecx
  int v8; // ebx
  unsigned int v9; // esi
  char v10; // al
  char *v11; // ecx
  char v12; // dl
  char v13; // dl
  int v15; // [esp+10h] [ebp+4h]
  unsigned int v16; // [esp+14h] [ebp+8h]

  v4 = *(unsigned __int16 *)(this[2] + 4 * a2 + 2);
  v5 = 0;
  for ( i = 0; i < v4; ++i )
    v5 |= 1 << i;
  v7 = this[2];
  v8 = v5 & a3;
  v9 = 0;
  v16 = *(unsigned __int16 *)(v7 + 4 * a2 + 2);
  v15 = *(unsigned __int16 *)(v7 + 4 * a2) + v16 - 1;
  if ( v16 )
  {
    do
    {
      v10 = 1 << ((v15 - v9) & 7);
      v11 = (char *)(((v15 - v9) >> 3) + *this);
      v12 = *v11;
      if ( ((1 << v9) & v8) != 0 )
        v13 = v10 | v12;
      else
        v13 = ~v10 & v12;
      ++v9;
      *v11 = v13;
    }
    while ( v9 < v16 );
  }
  return 1;
}
