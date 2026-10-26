int __thiscall sub_4347E0(_DWORD *this, int a2, char *Buffer, int a4)
{
  int v4; // eax
  float *v5; // edx
  double v6; // st7
  int i; // eax
  int j; // eax
  _DWORD v10[2]; // [esp+4h] [ebp-18h]
  _DWORD v11[4]; // [esp+Ch] [ebp-10h]
  float v12; // [esp+20h] [ebp+4h]

  v4 = 0;
  v5 = (float *)&this[3 * a2 + 1848];
  do
  {
    ++v4;
    v6 = *v5++ - 273.16;
    *(float *)&v11[v4] = v6;
  }
  while ( v4 < 3 );
  if ( this[1] == 1 )
  {
    for ( i = 0; i < 3; ++i )
    {
      v12 = (*(float *)&v11[i + 1] - -40.0) * 1.8 - 40.0;
      v10[i] = (int)v12;
    }
  }
  else
  {
    for ( j = 0; j < 3; ++j )
      v10[j] = (int)*(float *)&v11[j + 1];
  }
  if ( a4 == 3 )
    return sprintf(Buffer, "%3d/%3d/%3d", v10[0], v10[1], v11[0]);
  else
    return sprintf(Buffer, off_5FE04C, v10[a4]);
}
