double __cdecl acos(double X)
{
  _fload_withFB();
  return start_1(LODWORD(X), HIDWORD(X));
}
