int __thiscall sub_4F3490(long double *this, int a2, int a3)
{
  long double *v3; // esi
  long double *v4; // edi
  long double *v5; // ebx
  int result; // eax

  v3 = this + 20;
  v4 = this + 19;
  v5 = this + 18;
  result = sub_565AA0(a3, this + 18, this + 19, this + 20, 0);
  if ( result )
  {
    *v5 = fabs(*v5);
    *v4 = fabs(*v4);
    *v3 = fabs(*v3);
  }
  return result;
}

