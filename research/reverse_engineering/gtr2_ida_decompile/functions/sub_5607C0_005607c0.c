double *__thiscall sub_5607C0(double *this)
{
  double *v2; // edx
  int v3; // edi
  int v4; // edx

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = -1;
  v2 = this + 3;
  v3 = 4;
  do
  {
    sub_55F020(v2);
    v2 = (double *)(v4 + 496);
    --v3;
  }
  while ( v3 );
  return this;
}
