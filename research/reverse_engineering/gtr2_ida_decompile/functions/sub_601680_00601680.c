bool __thiscall sub_601680(_DWORD *this, LPCWCH lpWideCharStr, int a3)
{
  int v4; // eax
  int v6; // eax
  int v7[7]; // [esp+4h] [ebp-1Ch] BYREF

  if ( a3 <= 0 )
  {
    v6 = sub_645876(lpWideCharStr, (int)v7);
    this[2] = v6;
    if ( v6 )
      return 0;
  }
  else
  {
    v4 = sub_64479A(lpWideCharStr, a3, v7);
    this[2] = v4;
    if ( v4 )
      return 0;
  }
  return v7[6] == 4;
}
