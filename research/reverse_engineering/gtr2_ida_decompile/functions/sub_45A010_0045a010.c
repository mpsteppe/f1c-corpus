int __stdcall sub_45A010(int a1, int a2, int a3, int a4, double **a5)
{
  double v5; // st7
  double v7[3]; // [esp+10h] [ebp-30h] BYREF
  double v8; // [esp+28h] [ebp-18h]
  double v9; // [esp+30h] [ebp-10h]

  sub_458420(v7, a1, a2);
  v8 = sub_458450(v7);
  sub_458420(v7, a2, a3);
  v9 = sub_458450(v7);
  sub_458420(v7, a3, a1);
  v5 = sub_458450(v7);
  if ( v8 >= v9 && v8 >= v5 && v8 > 22500.0 )
  {
    sub_4583E0(v7, a1, a2);
    sub_45A010(a1, v7, a3, a4, a5);
    return sub_45A010(v7, a2, a3, a4, a5);
  }
  if ( v9 >= v8 && v9 >= v5 && v9 > 22500.0 )
  {
    sub_4583E0(v7, a2, a3);
    sub_45A010(a1, a2, v7, a4, a5);
    return sub_45A010(a1, v7, a3, a4, a5);
  }
  if ( v5 >= v8 && v5 >= v9 && v5 > 22500.0 )
  {
    sub_4583E0(v7, a3, a1);
    sub_45A010(a1, a2, v7, a4, a5);
    return sub_45A010(v7, a2, a3, a4, a5);
  }
  return sub_4592E0(a5, a1, a2, a3, a4, 0);
}
