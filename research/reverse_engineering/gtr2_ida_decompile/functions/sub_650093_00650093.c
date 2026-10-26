int __thiscall sub_650093(_DWORD *this, int a2)
{
  int v3; // ebx
  int v4; // eax
  float *v6; // edi
  char *v7; // ebx
  double v8; // st7
  float *v10; // edi
  char *v11; // ebx
  double v12; // st7
  int v13; // eax
  float *v14; // edi
  float *v15; // edi
  int v17; // [esp+14h] [ebp-4h]
  unsigned int v18; // [esp+14h] [ebp-4h]
  unsigned int v19; // [esp+14h] [ebp-4h]
  unsigned int v20; // [esp+14h] [ebp-4h]
  unsigned int v21; // [esp+14h] [ebp-4h]
  int v22; // [esp+20h] [ebp+8h]
  int v23; // [esp+20h] [ebp+8h]

  v3 = 0;
  if ( this[5] )
  {
    v4 = this[2];
    if ( v4 == 1 || v4 == 4 )
    {
      v19 = 0;
      if ( this[26] )
      {
        v23 = -8 - a2;
        v10 = (float *)(a2 + 8);
        do
        {
          v11 = (char *)v10 + v23;
          *(float *)&v11[this[22]] = sub_5AF263(COERCE_UNSIGNED_INT(*(v10 - 2))) * *(v10 - 2);
          *(float *)&v11[this[22] + 4] = sub_5AF263(COERCE_UNSIGNED_INT(*(v10 - 1))) * *(v10 - 1);
          v12 = sub_5AF263(COERCE_UNSIGNED_INT(*v10)) * *v10;
          ++v19;
          v10 += 4;
          *(float *)&v11[this[22] + 8] = v12;
          *(float *)&v11[this[22] + 12] = *(v10 - 3);
        }
        while ( v19 < this[26] );
      }
    }
    else
    {
      v18 = 0;
      if ( this[26] )
      {
        v22 = -12 - a2;
        v6 = (float *)(a2 + 12);
        do
        {
          v7 = (char *)v6 + v22;
          *(float *)&v7[this[22]] = *(v6 - 3);
          *(float *)&v7[this[22] + 4] = *(v6 - 2);
          *(float *)&v7[this[22] + 8] = *(v6 - 1);
          v8 = sub_5AF263(COERCE_UNSIGNED_INT(*v6)) * *v6;
          ++v18;
          v6 += 4;
          *(float *)&v7[this[22] + 12] = v8;
        }
        while ( v18 < this[26] );
      }
    }
  }
  else
  {
    this[31] = v17;
    v13 = this[2];
    if ( v13 == 1 || v13 == 4 )
    {
      v21 = 0;
      if ( this[26] )
      {
        v15 = (float *)(a2 + 8);
        do
        {
          *(float *)(v3 + this[22]) = sub_64FB33(COERCE_UNSIGNED_INT(*(v15 - 2)));
          *(float *)(v3 + this[22] + 4) = sub_64FB33(COERCE_UNSIGNED_INT(*(v15 - 1)));
          ++v21;
          *(float *)(v3 + this[22] + 8) = sub_64FB33(COERCE_UNSIGNED_INT(*v15));
          *(float *)(v3 + this[22] + 12) = v15[1];
          v3 += 16;
          v15 += 4;
        }
        while ( v21 < this[26] );
      }
    }
    else
    {
      v20 = 0;
      if ( this[26] )
      {
        v14 = (float *)(a2 + 8);
        do
        {
          *(float *)(v3 + this[22]) = *(v14 - 2);
          *(float *)(v3 + this[22] + 4) = *(v14 - 1);
          *(float *)(v3 + this[22] + 8) = *v14;
          ++v20;
          *(float *)(v3 + this[22] + 12) = sub_64FB33(COERCE_UNSIGNED_INT(v14[1]));
          v3 += 16;
          v14 += 4;
        }
        while ( v20 < this[26] );
      }
    }
  }
  return this[22];
}
