double __usercall sub_4854AA@<st0>(_DWORD *a1@<ecx>, long double a2@<st0>)
{
  double result; // st7
  int v3; // eax

  result = sqrt(a2);
  v3 = dword_76842C;
  if ( a1[216] != dword_76842C )
  {
    a1[216] = dword_76842C;
    if ( !v3 )
      a1[212] = 0;
    (*(void (__thiscall **)(_DWORD *))(*a1 + 180))(a1);
  }
  return result;
}
