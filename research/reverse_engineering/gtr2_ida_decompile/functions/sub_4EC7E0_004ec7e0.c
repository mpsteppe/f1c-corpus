int __stdcall sub_4EC7E0(int a1)
{
  int result; // eax
  int i; // esi
  __int32 v3; // eax
  char v4[256]; // [esp+Ch] [ebp-100h] BYREF

  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 52);
  if ( result )
  {
    result = sub_4D0AC0();
    for ( i = 0; i < a1; ++i )
    {
      LOBYTE(v3) = CGarageOnline::GetFileDetails((CGarageOnline *)dword_B6CBB4, i, v4);
      result = sub_4D93B0(v3, (int)v4, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    }
  }
  return result;
}
