double __cdecl acos(double X)
{
  int v1; // ecx

  _fload_withFB(v1);
  return sub_5C03ED(LODWORD(X), HIDWORD(X));
}
