int (__cdecl *__stdcall sub_67A840(_DWORD *a1, int a2, int a3, int (__cdecl *a4)(int, int)))(int, int)
{
  bool v4; // zf
  int (__cdecl *result)(int, int); // eax

  v4 = a1[20] == 0;
  a1[21] = a2;
  a1[19] = a3;
  result = a4;
  a1[72] = a4;
  if ( !v4 )
  {
    a1[20] = 0;
    sub_679F26((int)a1, (int)"Attempted to set both read_data_fn and write_data_fn in");
    return sub_679F26((int)a1, (int)"the same structure.  Resetting read_data_fn to NULL.");
  }
  return result;
}
