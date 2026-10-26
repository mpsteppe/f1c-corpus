int __thiscall sub_4E2760(int this)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  int v5; // ebx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  __int16 v9; // bx
  __int16 v10; // dx
  char v11; // al
  int v12; // esi
  float *v13; // edx
  char v14; // al
  char v15; // cl
  __int16 v16; // ax
  __int16 v17; // ax
  __int16 v18; // ax
  float v20; // [esp+10h] [ebp-2Ch]
  float v21; // [esp+10h] [ebp-2Ch]
  float v22; // [esp+10h] [ebp-2Ch]
  _WORD v23[6]; // [esp+20h] [ebp-1Ch]
  _DWORD v24[4]; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  v3 = this + 264;
  do
  {
    if ( *(int *)v3 < 24 )
      v4 = *(int *)v3 >> 3;
    else
      v4 = 3;
    v5 = CRTFtol(*(float *)(v3 - 24) * 7.0 + 0.5) + 8 * v4;
    v6 = CRTFtol(*(float *)(v3 - 20) * 7.0 + 0.5);
    v7 = *(float *)(v3 + 224) * 15.0;
    v24[v2] = v6 + 8 * v5;
    v23[v2++] = CRTFtol(v7 + 0.5);
    v3 += 296;
  }
  while ( v2 < 4 );
  v8 = *(float *)(this + 192) * 7.0;
  v9 = v23[2];
  v10 = 16 * v23[0];
  *(_DWORD *)(this + 2360) = v24[3] + ((v24[2] + ((v24[1] + (v24[0] << 8)) << 8)) << 8);
  *(_WORD *)(this + 2364) = v23[3] + 16 * (v9 + 16 * (v23[1] + v10));
  LOBYTE(v9) = 8 * CRTFtol(v8 + 0.5);
  LOBYTE(v9) = 4 * (CRTFtol(*(float *)(this + 172) * 7.0 + 0.5) + v9);
  LOBYTE(v9) = CRTFtol(*(float *)(this + 152) * 3.0 + 0.5) + v9;
  v11 = *(_BYTE *)(this + 2444);
  *(_BYTE *)(this + 2366) = v9;
  if ( v11 )
  {
    *(_DWORD *)(this + 2368) = 0;
    v12 = 0;
    v13 = (float *)(this + 2472);
    do
    {
      if ( *((_BYTE *)v13 - 24) )
      {
        *(_DWORD *)(this + 2368) |= 1 << v12;
        v14 = *((_BYTE *)v13 - 24);
        if ( (unsigned __int8)v14 > 0xFu )
          v14 = 15;
        v15 = *((_BYTE *)v13 - 23);
        if ( (unsigned __int8)v15 > 0xFu )
          v15 = 15;
        *(_BYTE *)(this + 2367) = v15 + 16 * v14;
        if ( *(v13 - 2) <= 511.98001 )
        {
          if ( *(v13 - 2) >= -511.98001 )
          {
            v20 = *(v13 - 2) * 64.0;
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
        *(_WORD *)(this + 2372) = v16;
        if ( *(v13 - 1) <= 511.98001 )
        {
          if ( *(v13 - 1) >= -511.98001 )
          {
            v21 = *(v13 - 1) * 64.0;
            v17 = (int)v21;
          }
          else
          {
            v17 = -32767;
          }
        }
        else
        {
          v17 = 0x7FFF;
        }
        *(_WORD *)(this + 2374) = v17;
        if ( *v13 <= 511.98001 )
        {
          if ( *v13 >= -511.98001 )
          {
            v22 = *v13 * 64.0;
            v18 = (int)v22;
          }
          else
          {
            v18 = -32767;
          }
        }
        else
        {
          v18 = 0x7FFF;
        }
        *(_WORD *)(this + 2376) = v18;
      }
      ++v12;
      v13 += 7;
    }
    while ( v12 < 17 );
    return this + 2360;
  }
  else
  {
    *(_BYTE *)(this + 2367) = 0;
    *(_DWORD *)(this + 2368) = 0;
    *(_WORD *)(this + 2372) = 0;
    *(_WORD *)(this + 2374) = 0;
    *(_WORD *)(this + 2376) = 0;
    return this + 2360;
  }
}
