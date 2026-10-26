int __thiscall sub_431AA0(_DWORD *this, int a2, int a3, int a4)
{
  int v6; // eax
  float *v7; // ecx
  double v8; // st7
  const char *v9; // ecx
  int i; // eax
  int j; // eax
  int result; // eax
  _DWORD v13[2]; // [esp+Ch] [ebp-18h]
  _DWORD v14[4]; // [esp+14h] [ebp-10h]
  float v15; // [esp+28h] [ebp+4h]

  v6 = 0;
  v7 = (float *)&this[3 * a2 + 1851];
  do
  {
    ++v6;
    v8 = *v7++ - 273.16;
    *(float *)&v14[v6] = v8;
  }
  while ( v6 < 3 );
  if ( this[1] == 1 )
  {
    v9 = &byte_5C3738;
    for ( i = 0; i < 3; ++i )
    {
      v15 = (*(float *)&v14[i + 1] - -40.0) * 1.8 - 40.0;
      v13[i] = (int)v15;
    }
  }
  else
  {
    v9 = &byte_5C3734;
    for ( j = 0; j < 3; ++j )
      v13[j] = (int)*(float *)&v14[j + 1];
  }
  if ( a4 == 3 )
    result = StringFormatWithBufferOverflowCheck(a3, "%3d/%3d/%3d %s", v13[0], v13[1], v14[0], v9);
  else
    result = StringFormatWithBufferOverflowCheck(a3, &off_5C3F70, v13[a4]);
  *((_BYTE *)this + a2 + 7400) = 0;
  return result;
}
