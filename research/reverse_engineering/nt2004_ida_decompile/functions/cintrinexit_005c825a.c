double __usercall cintrinexit@<st0>(double *a1@<ebp>, double result@<st0>)
{
  char v2; // fps
  char v6; // al
  __int16 v7; // ax
  int v8; // ebx

  if ( dword_7FF0EC )
    return result;
  *(a1 - 90) = result;
  v6 = *((_BYTE *)a1 - 144);
  if ( !v6 )
    goto checkinexact;
  if ( v6 == -1 || v6 == -2 )
  {
    v7 = *((_WORD *)a1 - 357) & 0x7FF0;
    if ( !v7 )
    {
      *(_DWORD *)((char *)a1 - 142) = 4;
      result = __FSCALE__(result, 1536.0);
      if ( fabs(result) < 2.225073858507201e-308 )
        result = result * 0.0;
      goto haveerror;
    }
    if ( v7 == 32752 )
    {
      *(_DWORD *)((char *)a1 - 142) = 3;
      result = __FSCALE__(result, -1536.0);
      if ( fabs(result) > 1.797693134862316e308 )
        result = result * INFINITY;
      goto haveerror;
    }
checkinexact:
    if ( (*((_WORD *)a1 - 82) & 0x20) != 0 || (v2 & 0x20) == 0 )
      return result;
    *(_DWORD *)((char *)a1 - 142) = 8;
    goto haveerror;
  }
  *(_DWORD *)((char *)a1 - 142) = v6;
haveerror:
  v8 = *((_DWORD *)a1 - 37) + 1;
  *(_DWORD *)((char *)a1 - 138) = v8;
  if ( (*(_BYTE *)(a1 - 89) & 1) == 0 )
  {
    *(_DWORD *)((char *)a1 - 134) = *((_DWORD *)a1 + 2);
    *(_DWORD *)((char *)a1 - 130) = *((_DWORD *)a1 + 3);
    if ( *(_BYTE *)(v8 + 12) != 1 )
    {
      *(_DWORD *)((char *)a1 - 126) = *((_DWORD *)a1 + 4);
      *(_DWORD *)((char *)a1 - 122) = *((_DWORD *)a1 + 5);
    }
  }
  *(double *)((char *)a1 - 118) = result;
  _87except(*(char *)(*((_DWORD *)a1 - 37) + 14), (char *)a1 - 142, (char *)a1 - 164);
  return *(double *)((char *)a1 - 118);
}
