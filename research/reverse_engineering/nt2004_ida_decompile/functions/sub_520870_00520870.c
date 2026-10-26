int __thiscall sub_520870(long double *this, int a2, char *String2)
{
  long double *v3; // esi
  long double *v4; // edi
  long double *v5; // ebx
  int result; // eax

  v3 = this + 20;
  v4 = this + 19;
  v5 = this + 18;
  result = sub_578450(String2, (int)(this + 18), (int)(this + 19), (int)(this + 20), 0);
  if ( result )
  {
    *v5 = fabs(*v5);
    *v4 = fabs(*v4);
    *v3 = fabs(*v3);
  }
  return result;
}
