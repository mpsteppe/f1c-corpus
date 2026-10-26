int __fastcall sub_5BE190(int a1, int a2)
{
  int result; // eax
  int v4; // eax

  result = *(_DWORD *)(a1 + 16);
  if ( result )
  {
    v4 = sub_5BE1B0(a1, a2);
    return (*(int (__thiscall **)(int))(a1 + 16))(v4);
  }
  return result;
}
