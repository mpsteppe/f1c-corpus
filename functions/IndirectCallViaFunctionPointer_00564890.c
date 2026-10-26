int __fastcall sub_564890(int a1, int a2)
{
  int result; // eax
  int v4; // eax

  result = *(_DWORD *)(a1 + 16);
  if ( result )
  {
    v4 = LinearInterpolation(a1, a2);
    return (*(int (__thiscall **)(int))(a1 + 16))(v4);
  }
  return result;
}
