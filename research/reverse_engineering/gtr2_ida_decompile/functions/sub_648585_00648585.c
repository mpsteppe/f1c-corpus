int __thiscall sub_648585(_DWORD *this, int a2)
{
  unsigned int v2; // edi
  int v3; // eax
  int v4; // esi
  unsigned int v5; // ebx
  int *v6; // eax
  int v7; // ecx
  int v8; // edx
  _BYTE *v9; // eax
  int v10; // ecx
  unsigned int v13; // [esp+18h] [ebp-14h]
  unsigned int v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch] BYREF
  int v16; // [esp+24h] [ebp-8h] BYREF
  void *Block; // [esp+28h] [ebp-4h] BYREF

  v2 = 0;
  v15 = 0;
  Block = 0;
  v3 = sub_67A6F8("1.0.5", 0, sub_648550, nullsub_9);
  v16 = v3;
  if ( !v3 )
    goto LABEL_20;
  v15 = sub_67A0BB(v3);
  if ( !v15 )
    goto LABEL_20;
  if ( _setjmp3(v16, 0) )
  {
    v4 = -2147467259;
    goto LABEL_21;
  }
  v5 = 8 * (*this == 36) + 8;
  sub_67A8A3(v16, v15, this[3], this[4], 8 * (*this == 36) + 8, 2, 0, 0, 0);
  sub_67A883(v16, v15, 2.2);
  Block = operator new(3 * this[3] * (v5 >> 3));
  if ( Block )
  {
    sub_67A840(v16, a2, sub_648560, nullsub_9);
    sub_67A0E8(v16, v15);
    v14 = 0;
    if ( v5 == 8 )
    {
      if ( this[4] )
      {
        do
        {
          v6 = (int *)(this[1] + v14 * this[12]);
          v13 = 0;
          if ( this[3] )
          {
            v7 = 0;
            do
            {
              v8 = *v6;
              *((_BYTE *)Block + v7) = BYTE2(*v6);
              ++v13;
              *((_BYTE *)Block + v7 + 1) = BYTE1(v8);
              *((_BYTE *)Block + v7 + 2) = v8;
              v7 += 3;
              ++v6;
            }
            while ( v13 < this[3] );
          }
          sub_67A790(v16, &Block, 1);
          ++v14;
        }
        while ( v14 < this[4] );
      }
    }
    else if ( this[4] )
    {
      do
      {
        v9 = (_BYTE *)(this[1] + v14 * this[12]);
        if ( this[3] )
        {
          v10 = 0;
          do
          {
            *((_BYTE *)Block + v10) = v9[1];
            *((_BYTE *)Block + v10 + 1) = *v9;
            *((_BYTE *)Block + v10 + 2) = v9[3];
            *((_BYTE *)Block + v10 + 3) = v9[2];
            *((_BYTE *)Block + v10 + 4) = v9[5];
            *((_BYTE *)Block + v10 + 5) = v9[4];
            ++v2;
            v10 += 6;
            v9 += 8;
          }
          while ( v2 < this[3] );
          v2 = 0;
        }
        sub_67A790(v16, &Block, 1);
        ++v14;
      }
      while ( v14 < this[4] );
    }
    sub_67A14C(v16, v15);
    v4 = 0;
  }
  else
  {
LABEL_20:
    v4 = -2147024882;
  }
LABEL_21:
  if ( v16 )
    sub_67A7B7(&v16, &v15);
  j__free(Block);
  return v4;
}
