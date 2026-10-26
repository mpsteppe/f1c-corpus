int __thiscall sub_45A2B0(_DWORD *this)
{
  int result; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ebp
  int v6; // edx
  bool v7; // sf
  int v8; // edi
  int v9; // eax
  int v10; // ebx
  double v11; // st6
  double v12; // st5
  double v13; // st3
  int v14; // ebp
  int v15; // edx
  int v16; // ecx
  float v17; // [esp+0h] [ebp-130h]
  float v18; // [esp+0h] [ebp-130h]
  int v19; // [esp+18h] [ebp-118h]
  float v20; // [esp+18h] [ebp-118h]
  float v21; // [esp+1Ch] [ebp-114h]
  float i; // [esp+20h] [ebp-110h]
  float j; // [esp+20h] [ebp-110h]
  float *v24; // [esp+24h] [ebp-10Ch]
  float v25; // [esp+28h] [ebp-108h]
  float v26; // [esp+2Ch] [ebp-104h]
  int v27; // [esp+30h] [ebp-100h]
  float v28; // [esp+34h] [ebp-FCh]
  int v29; // [esp+38h] [ebp-F8h] BYREF
  float v30; // [esp+3Ch] [ebp-F4h]
  float v31; // [esp+40h] [ebp-F0h]
  int v32; // [esp+50h] [ebp-E0h] BYREF
  float v33; // [esp+54h] [ebp-DCh]
  float v34; // [esp+58h] [ebp-D8h]
  _DWORD v35[50]; // [esp+68h] [ebp-C8h] BYREF

  result = *this;
  if ( *this )
  {
    v3 = this[1];
    v4 = 0;
    for ( i = 1.0 / (double)(v3 - 3); v4 < v3; ++v4 )
    {
      if ( !v4 || v4 == v3 - 1 )
      {
        *(_DWORD *)(28 * v4 + *this + 24) = -1082130432;
      }
      else if ( v4 == 1 )
      {
        *(_DWORD *)(*this + 52) = 0;
      }
      else
      {
        v5 = *this;
        if ( v4 == v3 - 2 )
          *(_DWORD *)(28 * v4 + v5 + 24) = 1065353216;
        else
          *(float *)(28 * v4 + v5 + 24) = i + *(float *)(28 * v4 + v5 - 4);
      }
      v3 = this[1];
    }
    v6 = this[1] - 2;
    v7 = this[1] - 3 < 0;
    memset(v35, 0, sizeof(v35));
    v27 = 1;
    if ( !(v7 ^ __OFSUB__(v6, 1) | (v6 == 1)) )
    {
      v8 = 28;
      v24 = (float *)&v35[2];
      do
      {
        v9 = *this;
        v10 = 10;
        v26 = *(float *)(v8 + *this + 24);
        v28 = *(float *)(v8 + *this + 52) - v26;
        v11 = *(float *)(v8 + v9 + 32) - *(float *)(v8 + v9 + 4);
        v12 = *(float *)(v8 + v9 + 36) - *(float *)(v8 + v9 + 8);
        v13 = *(float *)(v8 + v9 + 28) - *(float *)(v8 + v9);
        v25 = sqrt(v12 * v12 + v11 * v11 + v13 * v13);
        while ( 1 )
        {
          v14 = 0;
          v21 = 0.0;
          v19 = 0;
          for ( j = 1.0 / (double)v10;
                v14 < v10;
                v21 = sqrt(
                        (v31 - v34) * (v31 - v34)
                      + (v30 - v33) * (v30 - v33)
                      + (*(float *)&v29 - *(float *)&v32) * (*(float *)&v29 - *(float *)&v32))
                    + v21 )
          {
            v20 = (float)v19;
            v17 = v20 * v28 * j + v26;
            sub_459F60(this, v17, (int)&v32);
            v18 = (v20 + 1.0) * v28 * j + v26;
            sub_459F60(this, v18, (int)&v29);
            v19 = ++v14;
          }
          if ( fabs(v21 - v25) / v25 < 0.050000001 || v10 > 200 )
            break;
          v25 = v21;
          v10 *= 2;
        }
        v15 = this[1];
        *v24 = v21 + *(v24 - 1);
        v8 += 28;
        ++v27;
        ++v24;
      }
      while ( v27 < v15 - 2 );
    }
    result = 0;
    if ( (int)this[1] > 0 )
    {
      v16 = 0;
      do
      {
        *(_DWORD *)(v16 + *this + 24) = v35[result++];
        v16 += 28;
      }
      while ( result < this[1] );
    }
  }
  return result;
}
