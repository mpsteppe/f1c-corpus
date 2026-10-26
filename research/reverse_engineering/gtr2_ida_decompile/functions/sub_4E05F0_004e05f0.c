int __stdcall sub_4E05F0(int a1)
{
  int result; // eax
  _DWORD v2[3]; // [esp+0h] [ebp-Ch] BYREF

  if ( a1 )
  {
    dword_75B174 = dword_B70948;
    memset(v2, 0, sizeof(v2));
    if ( *(float *)&dword_B70948 <= 1.0 )
    {
      if ( *(float *)&dword_B70948 < 0.0 )
        dword_75B174 = 0;
    }
    else
    {
      dword_75B174 = 1065353216;
    }
    return (*(int (__stdcall **)(int, _DWORD *, _DWORD *, int, int, int))(*(_DWORD *)a1 + 4))(
             1,
             v2,
             v2,
             dword_75B174,
             1065353216,
             1);
  }
  return result;
}
