int __thiscall sub_600600(int this, const char *a2, int a3)
{
  char v4; // cl

  *(_DWORD *)(this + 20) = a3;
  sub_630FE0(this + 4);
  if ( strlen(a2) <= 0xF )
    *(_BYTE *)(strlen(a2) + this + 4) = 0;
  else
    *(_BYTE *)(this + 19) = v4;
  return 0;
}
