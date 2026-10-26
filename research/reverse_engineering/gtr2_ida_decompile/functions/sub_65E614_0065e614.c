char *__thiscall sub_65E614(_DWORD *this, _BYTE *a2, int *a3)
{
  char *v4; // eax
  _BYTE *v5; // esi

  if ( (unsigned int)a2 < this[1]
    && *a2 == 39
    && (v4 = sub_65E376((int)this, a2 + 1, a3)) != 0
    && (v5 = &a2[(_DWORD)v4 + 1], (unsigned int)v5 < this[1])
    && *v5 == 39 )
  {
    return v4 + 2;
  }
  else
  {
    return 0;
  }
}
