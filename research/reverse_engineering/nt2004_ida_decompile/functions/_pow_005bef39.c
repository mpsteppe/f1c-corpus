double __cdecl pow(double X, double Y)
{
  _fload_withFB();
  return sub_5BEF42(LODWORD(X), HIDWORD(X), LODWORD(Y), HIDWORD(Y));
}
