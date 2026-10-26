char *__usercall _onexit_lk@<eax>(int a1@<edi>)
{
  size_t v1; // eax
  char *v2; // ecx
  size_t v3; // esi
  int v4; // ecx
  char *result; // eax
  int v6; // ecx

  v1 = _msize(dword_FBC610);
  v2 = (char *)dword_FBC60C;
  v3 = v1;
  if ( v1 >= dword_FBC60C - (int)dword_FBC610 + 4 )
    goto LABEL_7;
  v4 = 2048;
  if ( v1 < 0x800 )
    v4 = v1;
  result = (char *)realloc(dword_FBC610, v1 + v4);
  if ( result || (result = (char *)realloc(dword_FBC610, v3 + 16)) != 0 )
  {
    v6 = dword_FBC60C - (_DWORD)dword_FBC610;
    dword_FBC610 = result;
    v2 = &result[4 * (v6 >> 2)];
    dword_FBC60C = (int)v2;
LABEL_7:
    *(_DWORD *)v2 = a1;
    dword_FBC60C += 4;
    return (char *)a1;
  }
  return result;
}
