double __cdecl asin(double X)
{
  int v1; // ecx

  _fload_withFB(v1);
  return sub_5C05ED(LODWORD(X), HIDWORD(X));
}
