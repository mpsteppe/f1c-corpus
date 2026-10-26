int __stdcall sub_4A24E0(float a1)
{
  float v2; // [esp+0h] [ebp-4h]
  float v3; // [esp+8h] [ebp+4h]

  if ( a1 >= 0.0 )
  {
    if ( a1 > 1.0 )
      a1 = 1.0;
  }
  else
  {
    a1 = 0.0;
  }
  v2 = sub_521060(&dword_BE120C);
  v3 = sub_521070(&dword_BE120C) + v2 * a1;
  return sub_520FF0(LODWORD(v3));
}
