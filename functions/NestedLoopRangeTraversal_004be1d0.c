char __thiscall sub_4BE1D0(float *this, float *a2)
{
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edi
  int v13; // esi
  bool v14; // zf
  char result; // al
  char v16; // [esp+Bh] [ebp-Dh]
  float *v17; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+14h] [ebp-4h]
  int v20; // [esp+1Ch] [ebp+4h]

  v16 = 0;
  v4 = CRTFtol((a2[3] - a2[6] - this[585]) * this[586]);
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( v4 < 8 )
      goto LABEL_6;
    v5 = 7;
  }
  else
  {
    v5 = 0;
  }
  v16 = 1;
LABEL_6:
  v6 = CRTFtol((a2[6] + a2[3] - this[585]) * this[586]);
  v7 = v6;
  if ( v6 >= 0 )
  {
    if ( v6 < 8 )
      goto LABEL_11;
    v7 = 7;
  }
  else
  {
    v7 = 0;
  }
  v16 = 1;
LABEL_11:
  v8 = CRTFtol((a2[5] - a2[6] - this[587]) * this[588]);
  v9 = v8;
  if ( v8 >= 0 )
  {
    if ( v8 < 8 )
      goto LABEL_16;
    v9 = 7;
  }
  else
  {
    v9 = 0;
  }
  v16 = 1;
LABEL_16:
  v10 = CRTFtol((a2[6] + a2[5] - this[587]) * this[588]);
  v11 = v10;
  v20 = v10;
  if ( v10 >= 0 )
  {
    if ( v10 < 8 )
      goto LABEL_21;
    v20 = 7;
  }
  else
  {
    v20 = 0;
  }
  v11 = v20;
  v16 = 1;
LABEL_21:
  if ( v5 <= v7 )
  {
    v17 = &this[72 * v5 + 9 * v9];
    v19 = v7 - v5 + 1;
    do
    {
      if ( v9 <= v11 )
      {
        v12 = (int)v17;
        v13 = v11 - v9 + 1;
        do
        {
          DynamicArrayAppendWithRealloc(v12, (int)a2);
          v12 += 36;
          --v13;
        }
        while ( v13 );
        v11 = v20;
      }
      v14 = v19 == 1;
      v17 += 72;
      --v19;
    }
    while ( !v14 );
  }
  result = v16;
  if ( v16 )
    return DynamicArrayAppendWithRealloc((int)(this + 576), (int)a2);
  return result;
}
