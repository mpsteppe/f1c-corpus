float *__thiscall sub_528B80(char *this)
{
  float *v1; // eax
  float *v2; // ecx
  double v3; // st7
  float *result; // eax
  double v5; // st7
  float *v6; // ecx
  double v7; // st7
  float v8; // [esp+0h] [ebp-Ch]
  float v9; // [esp+0h] [ebp-Ch]
  float v10; // [esp+4h] [ebp-8h]
  float v11; // [esp+4h] [ebp-8h]
  float v12; // [esp+8h] [ebp-4h]
  float v13; // [esp+8h] [ebp-4h]

  v1 = (float *)*((_DWORD *)this + 74);
  if ( v1 )
  {
    v2 = (float *)(this + 12);
    v8 = *v1 - *(v2 - 3);
    v10 = v1[1] - *(v2 - 2);
    v3 = v1[2] - *(v2 - 1);
    *v2 = v8;
    v2[1] = v10;
    v12 = v3;
    result = (float *)LODWORD(v12);
    v2[2] = v12;
  }
  else
  {
    result = (float *)*((_DWORD *)this + 73);
    if ( result )
    {
      v5 = *(float *)this;
      v6 = (float *)(this + 12);
      v9 = v5 - *result;
      v11 = *(v6 - 2) - result[1];
      v7 = *(v6 - 1) - result[2];
      result = (float *)LODWORD(v11);
      *v6 = v9;
      v6[1] = v11;
      v13 = v7;
      v6[2] = v13;
    }
    else
    {
      *((_DWORD *)this + 3) = 0;
      *((_DWORD *)this + 4) = 0;
      *((_DWORD *)this + 5) = -1082130432;
    }
  }
  return result;
}
