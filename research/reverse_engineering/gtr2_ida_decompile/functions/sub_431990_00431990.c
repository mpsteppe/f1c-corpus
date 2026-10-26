int __thiscall sub_431990(const char *this, int a2, char *Buffer)
{
  double v3; // st7
  const char *v5; // [esp+8h] [ebp-4h]

  v3 = *(float *)&this[4 * a2 + 7764] * 100.0;
  v5 = this + 24;
  if ( *((_DWORD *)this + 1) == 1 )
    return sprintf(Buffer, "%.2f %s", v3, v5);
  else
    return sprintf(Buffer, "%.3f %s", v3 * 0.3937007874015748, v5);
}
