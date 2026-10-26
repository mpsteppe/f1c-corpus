int sub_5ACA00()
{
  double *v0; // esi
  int v1; // edi
  int result; // eax
  double *v3; // esi

  dword_7E8D78 = 3;
  v0 = (double *)&unk_7E5EC8;
  do
  {
    sub_5AC5A0(v0, 1);
    v0 = (double *)((char *)v0 + 76);
  }
  while ( (int)v0 < (int)dbl_7E6848 );
  v1 = dword_7E8D78;
  result = dword_7E8D78 + 32;
  if ( !__OFSUB__(dword_7E8D78, dword_7E8D78 + 32) )
  {
    v3 = (double *)((char *)&unk_7E5EC8 + 76 * dword_7E8D78);
    do
    {
      result = sub_5AC5A0(v3, 1);
      ++v1;
      v3 = (double *)((char *)v3 + 76);
    }
    while ( v1 < dword_7E8D78 + 32 );
  }
  return result;
}
