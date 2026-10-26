float *__thiscall sub_4F1080(float *this, float a2, float a3, _DWORD *a4)
{
  signed int v4; // esi
  int v5; // edi
  int v6; // edx
  signed int v8; // esi
  float *v9; // edi
  float v10; // [esp+0h] [ebp-4h]
  float v11; // [esp+8h] [ebp+4h]

  v4 = 0;
  v5 = NumOfElements;
  if ( (int)NumOfElements <= 0 )
    goto LABEL_7;
  do
  {
    v6 = (v5 + v4) >> 1;
    v10 = a2 - a3;
    if ( v10 >= (double)this[v6 + 48] )
      v4 = v6 + 1;
    else
      v5 = (v5 + v4) >> 1;
  }
  while ( v4 < v5 );
  if ( v4 < (int)NumOfElements )
  {
    v8 = v6;
    v11 = a2 + a3;
    if ( v6 < (int)NumOfElements )
    {
      v9 = &this[v6 + 48];
      do
      {
        if ( v11 < (double)*v9 )
          break;
        ++v8;
        ++v9;
      }
      while ( v8 < (int)NumOfElements );
    }
    *a4 = v8 - v6;
    return &this[v6];
  }
  else
  {
LABEL_7:
    *a4 = 0;
    return 0;
  }
}
