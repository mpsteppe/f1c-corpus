char *__cdecl _cftof(double *a1, char *Src, size_t Size)
{
  double v5; // [esp+0h] [ebp-3Ch]
  char Destination[24]; // [esp+14h] [ebp-28h] BYREF
  int v7[4]; // [esp+2Ch] [ebp-10h] BYREF

  v5 = *a1;
  _fltout2(SLOBYTE(v5), SHIDWORD(v5), (int)v7, Destination);
  _fptostr(&Src[v7[0] == 45], Size + v7[1], (int)v7);
  _cftof2(Src, Size, (int)v7, 0);
  return Src;
}
