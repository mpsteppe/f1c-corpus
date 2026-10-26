int __thiscall sub_56B780(int this)
{
  int v2; // ebx
  int v3; // edi
  int v4; // ebp
  double v5; // st7
  double v6; // st7
  __int16 v7; // dx
  char v8; // al
  int v9; // ebx
  int v10; // edi
  char v11; // al
  char v12; // cl
  _WORD v14[6]; // [esp+10h] [ebp-1Ch]
  _DWORD v15[4]; // [esp+1Ch] [ebp-10h]

  v2 = 0;
  v3 = this + 404;
  do
  {
    if ( *(int *)v3 < 24 )
      v4 = *(int *)v3 >> 3;
    else
      v4 = 3;
    v5 = *(float *)(v3 + 224) * 15.0;
    v15[v2] = (unsigned __int64)(*(float *)(v3 - 20) * 7.0 + 0.5)
            + 8 * ((unsigned __int64)(*(float *)(v3 - 24) * 7.0 + 0.5) + 8 * v4);
    v14[v2++] = (unsigned __int64)(v5 + 0.5);
    v3 += 296;
  }
  while ( v2 < 4 );
  v6 = *(float *)(this + 204) * 3.0 + 0.5;
  v7 = v14[3] + 16 * (v14[2] + 16 * (v14[1] + 16 * v14[0]));
  *(_DWORD *)(this + 2960) = v15[3] + ((v15[2] + ((v15[1] + (v15[0] << 8)) << 8)) << 8);
  *(_WORD *)(this + 2964) = v7;
  v8 = *(_BYTE *)(this + 3092);
  *(_BYTE *)(this + 2966) = (unsigned __int64)(*(float *)(this + 164) * 3.0 + 0.5)
                          + 4
                          * ((unsigned __int64)(*(float *)(this + 184) * 3.0 + 0.5)
                           + 4 * ((unsigned __int64)v6 - 4 * (unsigned __int64)(*(float *)(this + 224) * -3.0)));
  if ( v8 )
  {
    v9 = 0;
    *(_DWORD *)(this + 2968) = 0;
    v10 = this + 3096;
    do
    {
      if ( *(_BYTE *)v10 )
      {
        *(_DWORD *)(this + 2968) |= 1 << v9;
        v11 = *(_BYTE *)v10;
        if ( *(_BYTE *)v10 > 0xFu )
          v11 = 15;
        v12 = *(_BYTE *)(v10 + 1);
        if ( (unsigned __int8)v12 > 0xFu )
          v12 = 15;
        *(_BYTE *)(this + 2967) = v12 + 16 * v11;
        sub_4164C0((__int16 *)(this + 2972), (float *)(v10 + 16));
      }
      ++v9;
      v10 += 28;
    }
    while ( v9 < 25 );
    return this + 2960;
  }
  else
  {
    *(_DWORD *)(this + 2968) = 0;
    *(_BYTE *)(this + 2967) = 0;
    *(_WORD *)(this + 2972) = 0;
    *(_WORD *)(this + 2974) = 0;
    *(_WORD *)(this + 2976) = 0;
    return this + 2960;
  }
}
