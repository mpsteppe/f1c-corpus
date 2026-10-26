int __thiscall sub_431A10(const char *this, int a2, char *Buffer)
{
  double v3; // st7
  int v4; // eax
  const char *v6; // [esp+8h] [ebp-4h]

  v3 = *(float *)&this[4 * a2 + 7828];
  v6 = this + 8;
  if ( *((_DWORD *)this + 1) )
    return sprintf(Buffer, "%.1f %s", v3 * 0.1450377377387031, v6);
  v4 = sub_431910(v3);
  return sprintf(Buffer, "%d %s", v4, v6);
}
