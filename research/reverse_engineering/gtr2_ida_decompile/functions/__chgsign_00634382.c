double __cdecl _chgsign(double X)
{
  double v2; // [esp+0h] [ebp-8h]

  LODWORD(v2) = LODWORD(X);
  HIDWORD(v2) = ~HIDWORD(X) ^ (HIDWORD(X) ^ ~HIDWORD(X)) & 0x7FFFFFFF;
  return v2;
}
