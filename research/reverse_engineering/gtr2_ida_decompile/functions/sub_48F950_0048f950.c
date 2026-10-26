int __thiscall sub_48F950(_BYTE *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _BYTE v7[256]; // [esp+4h] [ebp-100h] BYREF

  if ( this[280] )
    v1 = sub_5944B0(&dword_FB1EF8);
  else
    v1 = sub_5943E0(&dword_FB1EF8);
  v2 = v1 - 1;
  if ( !v2 )
    goto LABEL_9;
  v3 = v2 - 1;
  if ( !v3 )
  {
    v4 = 1;
    goto LABEL_10;
  }
  if ( v3 != 1 )
  {
LABEL_9:
    v4 = 0;
    goto LABEL_10;
  }
  v4 = 2;
LABEL_10:
  v5 = sub_4CFC00(v4);
  sub_630FE0(v7, v5, 255);
  v7[255] = 0;
  sub_4CE020(v7);
  return 0;
}
