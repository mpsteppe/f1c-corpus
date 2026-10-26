int __thiscall sub_6B025D(_DWORD *this, _DWORD *a2)
{
  unsigned int v2; // ebx
  int v4; // eax
  int v5; // esi
  unsigned int v6; // ecx
  int v7; // edx
  _DWORD *v8; // eax
  unsigned int v9; // edi
  _DWORD v10[4]; // [esp+4h] [ebp-24h] BYREF
  unsigned int v11; // [esp+14h] [ebp-14h]
  _DWORD *v12; // [esp+18h] [ebp-10h]
  unsigned int v13; // [esp+1Ch] [ebp-Ch]
  int v14; // [esp+20h] [ebp-8h]
  char *v15; // [esp+24h] [ebp-4h]

  v2 = *a2 & 0xFFFFF;
  v12 = this;
  if ( !v2 )
    return 1;
  v4 = a2[1] / v2;
  v13 = 0;
  v11 = v4;
  if ( !v4 )
    return 0;
  v5 = (int)(this[27] << 30) >> 31;
  v14 = 0;
  while ( 1 )
  {
    memset(v10, 255, sizeof(v10));
    v6 = 0;
    v7 = v12[5];
    v8 = (_DWORD *)(v14 + a2[2]);
    do
      v10[v6++] = *(_DWORD *)(*(_DWORD *)(v7 + 4 * *v8++) + 16);
    while ( v6 < v2 );
    if ( v5 )
    {
      v9 = 0;
      v15 = (char *)&unk_91A658;
      do
      {
        if ( sub_6A323B(v10, (int)v15) )
          break;
        v15 += 16;
        ++v9;
      }
      while ( v9 < 8 );
      if ( v9 == 8 )
        break;
    }
    ++v13;
    v14 += 4 * v2;
    if ( v13 >= v11 )
      return 0;
  }
  return 1;
}
