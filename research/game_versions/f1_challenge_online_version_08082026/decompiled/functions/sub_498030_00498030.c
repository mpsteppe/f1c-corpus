int __stdcall sub_498030(int a1)
{
  int result; // eax
  _DWORD v2[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( a1 )
  {
    dword_5CC9E0 = LODWORD(flt_7CF2CC);
    memset(v2, 0, sizeof(v2));
    if ( flt_7CF2CC <= 1.0 )
    {
      if ( *(float *)&dword_5CC9E0 < 0.0 )
        dword_5CC9E0 = 0;
    }
    else
    {
      dword_5CC9E0 = 1065353216;
    }
    return (*(int (__stdcall **)(int, _DWORD *, _DWORD *, int, int, int))(*(_DWORD *)a1 + 4))(
             1,
             v2,
             v2,
             dword_5CC9E0,
             1065353216,
             1);
  }
  return result;
}
