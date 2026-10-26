int __thiscall sub_565520(float *this)
{
  char *v2; // eax
  int v3; // edx
  char v4; // cl
  char String[128]; // [esp+10h] [ebp-80h] BYREF

  if ( *((float *)dword_91E07C + 3905) > 0.0 && this[4] < 0.0 )
    return 1;
  this[4] = this[4] - dbl_FB1D10;
  strcpy(String, &dword_91E07C[108 * *((_DWORD *)dword_91E07C + 5447) + 21656]);
  _strupr(String);
  sub_562B70((int)String, 1180, 50, (int)byte_FFFFFF, 1, 0, 1.0, 1.0);
  v2 = dword_91E07C + 21872;
  v3 = String - (dword_91E07C + 21872);
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 );
  _strupr(String);
  sub_562B70((int)String, 1180, 90, (int)&loc_48AAB3, 1, 0, 1.0, 1.0);
  sprintf(String, "%.1f", *((float *)dword_91E07C + 3905));
  sub_562B70((int)String, 1180, 130, (int)dword_FFFF00, 1, 0, 1.0, 1.0);
  strcpy(String, sub_41D840(&byte_91CC38, "PIT STOP"));
  sub_562B70((int)String, 640, 130, (int)dword_FFFF00, 2, 0, 1.0, 1.0);
  return 0;
}
