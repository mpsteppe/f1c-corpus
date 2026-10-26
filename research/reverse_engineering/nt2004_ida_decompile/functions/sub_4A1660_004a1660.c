int __thiscall sub_4A1660(int this, int a2, const char *a3, int a4, char a5, int a6, char a7)
{
  int v8; // eax

  sub_49C450((_DWORD *)this);
  v8 = a2;
  *(_DWORD *)this = &off_5E9880;
  if ( !a2 )
    v8 = this + 274;
  *(_DWORD *)(this + 796) = v8;
  sub_4A1750(this);
  if ( a4 > 0 )
    sub_4A1B90(a4);
  *(_DWORD *)(this + 808) = 0;
  if ( a3 && (int)strlen(a3) < a4 )
  {
    strcpy(*(char **)(this + 796), a3);
    strcpy((char *)(this + 531), a3);
  }
  *(_BYTE *)(this + 273) = a7;
  *(_BYTE *)(this + 270) = a5;
  *(_DWORD *)(this + 788) = a6;
  return this;
}
