int __thiscall sub_435710(_DWORD *this, int a2, char *Buffer, int a4)
{
  int v4; // esi
  int v5; // eax
  const char *v6; // edi
  float v8; // [esp+0h] [ebp-24h]
  _DWORD v9[3]; // [esp+Ch] [ebp-18h]
  float v10[3]; // [esp+18h] [ebp-Ch]

  v10[0] = *(float *)&this[3 * a2 + 1945] - 273.16;
  v4 = 0;
  v10[1] = *(float *)&this[3 * a2 + 1946] - 273.16;
  v5 = this[1];
  v10[2] = *(float *)&this[3 * a2 + 1947] - 273.16;
  if ( v5 == 1 )
  {
    v6 = (const char *)&unk_6F3EB0;
    do
    {
      v8 = (v10[v4] - -40.0) * 1.8 - 40.0;
      v9[v4++] = sub_4015C0(v8);
    }
    while ( v4 < 3 );
  }
  else
  {
    v6 = (const char *)&unk_6F3EAC;
    do
    {
      v9[v4] = sub_4015C0(v10[v4]);
      ++v4;
    }
    while ( v4 < 3 );
  }
  if ( a4 == 3 )
    return sprintf(Buffer, "%3d/%3d/%3d %s", v9[0], v9[1], v9[2], v6);
  else
    return sprintf(Buffer, off_6F4854, v9[a4]);
}
