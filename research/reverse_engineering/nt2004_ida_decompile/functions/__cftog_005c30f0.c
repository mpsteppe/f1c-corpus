char *__cdecl _cftog(double *a1, char *Src, signed int Size, int a4)
{
  int v5; // esi
  char *v6; // edi
  double v8; // [esp+0h] [ebp-44h]
  char Destination[24]; // [esp+1Ch] [ebp-28h] BYREF
  int v10; // [esp+34h] [ebp-10h] BYREF
  int v11; // [esp+38h] [ebp-Ch]

  v8 = *a1;
  _fltout2(SLOBYTE(v8), SHIDWORD(v8), (int)&v10, Destination);
  v5 = v11 - 1;
  v6 = &Src[v10 == 45];
  _fptostr(v6, Size, (int)&v10);
  if ( v11 - 1 < -4 || v11 - 1 >= Size )
    return _cftoe2(Src, Size, a4, (int)&v10, 1);
  if ( v5 < v11 - 1 )
    v6[strlen(v6) - 1] = 0;
  return _cftof2(Src, Size, &v10, 1);
}
