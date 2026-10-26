int (__cdecl *__stdcall sub_67CBDA(_DWORD *a1, int a2, int (__cdecl *a3)(int, int)))(int, int)
{
  bool v3; // zf
  int (__cdecl *result)(int, int); // eax

  v3 = a1[19] == 0;
  a1[21] = a2;
  result = a3;
  a1[20] = a3;
  if ( !v3 )
  {
    a1[19] = 0;
    sub_679F26((int)a1, (int)"It's an error to set both read_data_fn and write_data_fn in the ");
    result = sub_679F26((int)a1, (int)"same structure.  Resetting write_data_fn to NULL.");
  }
  a1[72] = 0;
  return result;
}
