int __thiscall sub_6C466D(_DWORD *this)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  _DWORD *v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  _DWORD *v8; // eax
  _DWORD *v9; // ecx
  unsigned int i; // ebx
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+10h] [ebp-14h]
  int v14; // [esp+14h] [ebp-10h]
  int v15; // [esp+18h] [ebp-Ch]
  int v16; // [esp+1Ch] [ebp-8h]
  _DWORD *v17; // [esp+20h] [ebp-4h]

  do
  {
    v2 = 0;
    v12 = 0;
    v15 = 0;
    if ( !this[3] )
      break;
    do
    {
      if ( sub_680F22(*(_DWORD **)(this[6] + 4 * v2)) )
      {
        v3 = v2 + 1;
        v16 = 1;
        v13 = v2 + 1;
        if ( v2 + 1 >= this[3] )
          goto LABEL_21;
        do
        {
          v4 = *(_DWORD **)(this[6] + 4 * v3);
          if ( sub_680F5A(v4) )
            break;
          if ( (*v4 & 0xFFF00000) != 0x10000000 )
          {
            v16 = 0;
            break;
          }
          v5 = v4[3];
          if ( v5 )
          {
            v6 = this[5];
            v17 = (_DWORD *)v4[2];
            v7 = v4[4] - (_DWORD)v17;
            v14 = v5;
            do
            {
              v8 = *(_DWORD **)(v6 + 4 * *(_DWORD *)((char *)v17 + v7));
              v9 = *(_DWORD **)(v6 + 4 * *v17);
              if ( v8[14] != v9[14]
                || v8[15] != v9[15]
                || v8[1] != v9[1]
                || v8[3] != v9[3]
                || v8[2] != v9[2]
                || v8[4] != v9[4] )
              {
                v16 = 0;
              }
              ++v17;
              --v14;
            }
            while ( v14 );
            v3 = v13;
          }
          v13 = ++v3;
        }
        while ( v3 < this[3] );
        v2 = v15;
        if ( v16 )
        {
LABEL_21:
          v12 = 1;
          for ( i = v2; i < this[3]; **(_DWORD **)(this[6] + 4 * i++) = 0 )
          {
            if ( sub_680F5A(*(_DWORD **)(this[6] + 4 * i)) )
              break;
          }
        }
      }
      v15 = ++v2;
    }
    while ( v2 < this[3] );
  }
  while ( v12 );
  return 0;
}
