int __cdecl sub_4304C0(int *a1, int *a2)
{
  double v2; // st7
  double v3; // st6

  v2 = (double)a1[1] / (double)*a1;
  v3 = (double)a2[1] / (double)*a2;
  if ( v2 <= v3 )
    return v2 < v3;
  else
    return -1;
}
