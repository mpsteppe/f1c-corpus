int __thiscall sub_50CE30(int this)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  double v5; // st7
  double v6; // st7
  __int16 v7; // bx
  __int16 v8; // dx
  char v9; // al
  int v10; // esi
  float *v11; // edx
  char v12; // al
  char v13; // cl
  __int16 v14; // ax
  __int16 v15; // ax
  __int16 v16; // ax
  float v18; // [esp+10h] [ebp-2Ch]
  float v19; // [esp+10h] [ebp-2Ch]
  float v20; // [esp+10h] [ebp-2Ch]
  _WORD v21[6]; // [esp+20h] [ebp-1Ch]
  _DWORD v22[4]; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  v3 = this + 272;
  do
  {
    if ( *(int *)v3 < 24 )
      v4 = *(int *)v3 >> 3;
    else
      v4 = 3;
    v5 = *(float *)(v3 + 232) * 15.0;
    v22[v2] = (__int64)(*(float *)(v3 - 20) * 7.0 + 0.5) + 8 * ((__int64)(*(float *)(v3 - 24) * 7.0 + 0.5) + 8 * v4);
    v21[v2++] = (__int64)(v5 + 0.5);
    v3 += 304;
  }
  while ( v2 < 4 );
  v6 = *(float *)(this + 200) * 7.0;
  v7 = v21[2];
  v8 = 16 * v21[0];
  *(_DWORD *)(this + 2796) = v22[3] + ((v22[2] + ((v22[1] + (v22[0] << 8)) << 8)) << 8);
  *(_WORD *)(this + 2800) = v21[3] + 16 * (v7 + 16 * (v21[1] + v8));
  v9 = *(_BYTE *)(this + 2912);
  *(_BYTE *)(this + 2802) = (__int64)(*(float *)(this + 160) * 3.0 + 0.5)
                          + 4 * ((__int64)(*(float *)(this + 180) * 7.0 + 0.5) + 8 * (__int64)(v6 + 0.5));
  if ( v9 )
  {
    *(_DWORD *)(this + 2804) = 0;
    v10 = 0;
    v11 = (float *)(this + 2940);
    do
    {
      if ( *((_BYTE *)v11 - 24) )
      {
        *(_DWORD *)(this + 2804) |= 1 << v10;
        v12 = *((_BYTE *)v11 - 24);
        if ( (unsigned __int8)v12 > 0xFu )
          v12 = 15;
        v13 = *((_BYTE *)v11 - 23);
        if ( (unsigned __int8)v13 > 0xFu )
          v13 = 15;
        *(_BYTE *)(this + 2803) = v13 + 16 * v12;
        if ( *(v11 - 2) <= 511.98001 )
        {
          if ( *(v11 - 2) >= -511.98001 )
          {
            v18 = *(v11 - 2) * 64.0;
            v14 = (int)v18;
          }
          else
          {
            v14 = -32767;
          }
        }
        else
        {
          v14 = 0x7FFF;
        }
        *(_WORD *)(this + 2808) = v14;
        if ( *(v11 - 1) <= 511.98001 )
        {
          if ( *(v11 - 1) >= -511.98001 )
          {
            v19 = *(v11 - 1) * 64.0;
            v15 = (int)v19;
          }
          else
          {
            v15 = -32767;
          }
        }
        else
        {
          v15 = 0x7FFF;
        }
        *(_WORD *)(this + 2810) = v15;
        if ( *v11 <= 511.98001 )
        {
          if ( *v11 >= -511.98001 )
          {
            v20 = *v11 * 64.0;
            v16 = (int)v20;
          }
          else
          {
            v16 = -32767;
          }
        }
        else
        {
          v16 = 0x7FFF;
        }
        *(_WORD *)(this + 2812) = v16;
      }
      ++v10;
      v11 += 7;
    }
    while ( v10 < 17 );
    return this + 2796;
  }
  else
  {
    *(_BYTE *)(this + 2803) = 0;
    *(_DWORD *)(this + 2804) = 0;
    *(_WORD *)(this + 2808) = 0;
    *(_WORD *)(this + 2810) = 0;
    *(_WORD *)(this + 2812) = 0;
    return this + 2796;
  }
}
