double __thiscall sub_41D9B0(_DWORD *this, char *String1)
{
  const char *v2; // eax

  v2 = sub_41D8B0(this, String1);
  if ( !v2 || *((_DWORD *)v2 + 17) == -1082130432 )
    return -1.0;
  else
    return *((float *)v2 + 17);
}
