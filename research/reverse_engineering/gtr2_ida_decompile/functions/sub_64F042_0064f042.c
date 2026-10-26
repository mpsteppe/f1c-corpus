int __thiscall sub_64F042(_DWORD *this)
{
  float *v1; // edx
  _WORD *v2; // edi
  int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  float v11; // [esp+8h] [ebp-24h]
  float v12; // [esp+8h] [ebp-24h]
  float v13; // [esp+14h] [ebp-18h]
  float v14; // [esp+14h] [ebp-18h]
  float v15; // [esp+14h] [ebp-18h]
  float v16; // [esp+1Ch] [ebp-10h]
  int v17; // [esp+20h] [ebp-Ch]
  unsigned int v18; // [esp+20h] [ebp-Ch]
  float v19; // [esp+20h] [ebp-Ch]
  float v20; // [esp+20h] [ebp-Ch]
  float v21; // [esp+20h] [ebp-Ch]
  float v22; // [esp+20h] [ebp-Ch]
  unsigned int v23; // [esp+24h] [ebp-8h]
  float v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+24h] [ebp-8h]
  int v26; // [esp+28h] [ebp-4h]

  if ( this[40] && this[41] )
  {
    v1 = (float *)this[32];
    v2 = (_WORD *)(this[8] + this[24] * this[34] + this[25] * this[37] + 2 * this[33]);
    this[31] = v17;
    v3 = this[1];
    switch ( v3 )
    {
      case 844715353:
        goto LABEL_7;
      case 1111970375:
      case 1195525970:
        v5 = this[33];
        v23 = v5;
        while ( v5 < this[35] )
        {
          v19 = v1[1] * 255.0 + 0.5;
          v6 = (int)v19;
          v20 = *v1 * 255.0 + 0.5;
          *v2 = ((int)v20 << this[43]) | (v6 << this[42]);
          v21 = v1[5] * 255.0 + 0.5;
          v7 = (int)v21;
          v22 = v1[2] * 255.0 + 0.5;
          v1 += 8;
          v2 += 2;
          v23 += 2;
          *(v2 - 1) = ((int)v22 << this[43]) | (v7 << this[42]);
          v5 = v23;
        }
        break;
      case 1498831189:
LABEL_7:
        v4 = this[33];
        v18 = v4;
        while ( v4 < this[35] )
        {
          v16 = v1[4] * 65.481003 + v1[6] * 24.966 + v1[5] * 128.55299;
          v24 = v1[2] * 112.0 - v1[1] * 74.203003 - *v1 * 37.797001;
          v11 = *v1 * 112.0 - (v1[1] * 93.786003 + v1[2] * 18.214001);
          v13 = *v1 * 65.481003 + v1[1] * 128.55299 + v1[2] * 24.966 + 0.5;
          v8 = (int)v13 + 16;
          v14 = v16 + 0.5;
          v26 = (int)v14 + 16;
          v15 = v24 + 0.5;
          v9 = (int)v15 + 128;
          v12 = v11 + 0.5;
          v25 = (int)v12 + 128;
          if ( v8 >= 0 )
          {
            if ( v8 > 255 )
              v8 = 255;
          }
          else
          {
            v8 = 0;
          }
          if ( v26 >= 0 )
          {
            if ( v26 > 255 )
              v26 = 255;
          }
          else
          {
            v26 = 0;
          }
          if ( v9 >= 0 )
          {
            if ( v9 > 255 )
              v9 = 255;
          }
          else
          {
            v9 = 0;
          }
          if ( v25 >= 0 )
          {
            if ( v25 > 255 )
              v25 = 255;
          }
          else
          {
            v25 = 0;
          }
          v1 += 8;
          *v2 = (v9 << this[43]) | (v8 << this[42]);
          v2 += 2;
          v18 += 2;
          *(v2 - 1) = (v25 << this[43]) | (v26 << this[42]);
          v4 = v18;
        }
        break;
    }
    this[40] = 0;
  }
  return 0;
}
