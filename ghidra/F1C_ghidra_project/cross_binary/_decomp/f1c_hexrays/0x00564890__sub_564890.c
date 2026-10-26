// f1c  0x00564890  size=22
int __fastcall sub_564890(int a1, int a2)
{
  int result; // eax
  int v4; // eax

  result = *(_DWORD *)(a1 + 16);
  if ( result )
  {
    v4 = sub_5648B0(a1, a2);
    return (*(int (__thiscall **)(int))(a1 + 16))(v4);
  }
  return result;
}
