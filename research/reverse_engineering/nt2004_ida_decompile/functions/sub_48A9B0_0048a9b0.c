int __thiscall sub_48A9B0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  char *v4; // edx
  char v5; // cl
  int result; // eax
  char Source[80]; // [esp+4h] [ebp-50h] BYREF

  v2 = sub_5A97F0(dword_7DA988);
  if ( (int)this[217] < 0 )
    this[217] = v2 - 1;
  if ( this[217] >= v2 )
    this[217] = 0;
  v3 = sub_5A9800(this[217]) + 4;
  v4 = &Source[-v3];
  do
  {
    v5 = *(_BYTE *)v3;
    v4[v3] = *(_BYTE *)v3;
    ++v3;
  }
  while ( v5 );
  result = sub_4A1AC0(Source);
  dword_62A138 = this[217];
  return result;
}
