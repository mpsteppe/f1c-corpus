int __thiscall sub_6BC410(_DWORD *this)
{
  unsigned int v1; // ebx
  _DWORD *v2; // edx
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // ebx
  unsigned int v6; // ebx
  _DWORD *v7; // esi
  int v8; // eax
  _DWORD *v9; // edx
  int v10; // esi
  int v12; // [esp+Ch] [ebp-14h]
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  _DWORD *v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  do
  {
    v1 = 0;
    v12 = 0;
    v16 = 0;
    if ( !this[3] )
      break;
    do
    {
      v2 = *(_DWORD **)(this[6] + 4 * v16);
      v14 = 0;
      if ( v2[1] )
      {
        v3 = this[5];
        v15 = (_DWORD *)v2[2];
        v13 = v2[1];
        do
        {
          v4 = *(_DWORD **)(v3 + 4 * *v15);
          if ( ((unsigned int)&dword_1000000 & *v4) != 0 )
            v14 = 1;
          v5 = v4[14];
          if ( v5 != -1 )
            v4 = *(_DWORD **)(v3 + 4 * v5);
          if ( ((unsigned int)&dword_1000000 & *v4) != 0 )
            v14 = 1;
          ++v15;
          --v13;
        }
        while ( v13 );
        v6 = 0;
        if ( v14 && v2[3] )
        {
          do
          {
            v7 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(v2[4] + 4 * v6));
            if ( (*v7 & (unsigned int)&dword_1000000) == 0 )
            {
              *v7 |= (unsigned int)&dword_1000000;
              v12 = 1;
            }
            ++v6;
          }
          while ( v6 < v2[3] );
        }
      }
      ++v16;
    }
    while ( v16 < this[3] );
    v1 = 0;
  }
  while ( v12 );
  if ( this[2] )
  {
    do
    {
      v8 = this[5];
      v9 = *(_DWORD **)(v8 + 4 * v1);
      v10 = v9[14];
      if ( v10 != -1 && ((unsigned int)&dword_1000000 & **(_DWORD **)(v8 + 4 * v10)) != 0 )
        *v9 |= (unsigned int)&dword_1000000;
      ++v1;
    }
    while ( v1 < this[2] );
  }
  return 0;
}
