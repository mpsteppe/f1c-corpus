int __thiscall sub_59C310(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // ebp
  float *v7; // edx
  float *v8; // esi
  int v9; // edi
  int i; // ecx
  int v12; // ebp
  int v13; // [esp+10h] [ebp-4h]
  float *v14; // [esp+1Ch] [ebp+8h]

  v4 = this[63];
  v5 = this[5] & 0xFFFFFFF8;
  this[5] = v5;
  v6 = v5;
  v13 = 0;
  if ( v4 <= 0 )
  {
LABEL_9:
    this[5] = v6 | 1;
    return 0;
  }
  else
  {
    v14 = (float *)(a3 + 8);
    v7 = (float *)(a2 + 260);
    while ( 1 )
    {
      v8 = v14;
      v9 = 0;
      for ( i = 0; i < 8; ++i )
      {
        if ( -(*(v7 - 2) * *(v8 - 2)) - *(v7 - 1) * *(v8 - 1) - *v7 * *v8 > v7[1] )
          v9 |= 1 << i;
        v8 += 3;
      }
      if ( v9 )
        break;
      v7 += 4;
      if ( ++v13 >= this[63] )
        goto LABEL_9;
    }
    if ( v9 == 255 )
      v12 = v6 | 2;
    else
      v12 = v6 | 4;
    this[5] = v12;
    return 0;
  }
}
