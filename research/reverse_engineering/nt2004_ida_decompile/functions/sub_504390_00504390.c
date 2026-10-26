_DWORD *__thiscall sub_504390(char *this)
{
  _DWORD *result; // eax
  char *v2; // ecx
  _DWORD *v3; // eax
  _DWORD *v4; // esi

  result = 0;
  if ( this )
  {
    v2 = this - 1;
    if ( v2 )
    {
      if ( v2 != (char *)1 )
        return result;
    }
    else
    {
      result = operator new(0x20u);
      if ( result )
      {
        result[1] = 0;
        *((_BYTE *)result + 8) = 0;
        result[3] = 0;
        result[4] = 0;
        result[5] = -1;
        result[6] = 0;
        result[7] = -1;
        *result = &off_5EA9A0;
        return result;
      }
    }
  }
  else
  {
    v3 = operator new(0x20u);
    v4 = v3;
    if ( v3 )
    {
      v3[1] = 0;
      *((_BYTE *)v3 + 8) = 0;
      v3[3] = 0;
      v3[4] = 0;
      v3[5] = -1;
      v3[6] = 0;
      v3[7] = -1;
      *v3 = &off_5EA984;
      sub_578600(aInstantReplay_0);
      return v4;
    }
  }
  return 0;
}
