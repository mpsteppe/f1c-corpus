int __thiscall sub_65D719(_DWORD *this, const char *a2)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  _DWORD *v5; // eax

  v3 = strlen(a2);
  v4 = v3 + 1;
  v5 = operator new(v3 + 5);
  if ( !v5 )
    return -2147024882;
  *v5 = *this;
  this[1] += v4 - 1;
  *this = v5;
  qmemcpy(v5 + 1, a2, v4);
  return 0;
}
