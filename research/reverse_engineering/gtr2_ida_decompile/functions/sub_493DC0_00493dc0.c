int __thiscall sub_493DC0(_DWORD **this)
{
  int result; // eax
  int v2; // esi
  char *v3; // eax
  char *v4; // eax

  result = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 578);
  v2 = result;
  if ( result )
  {
    result = *(_DWORD *)(result + 284);
    if ( !result )
    {
      v3 = sub_41D840(&byte_91CC38, "Connecting to SimBin Server...");
      result = sub_615860(v3);
      *(_DWORD *)(v2 + 284) = 1;
    }
    if ( *(_DWORD *)(v2 + 284) == 11 )
    {
      v4 = sub_41D840(&byte_91CC38, "Leaving Game Server. Return to MoRe website.");
      return sub_615860(v4);
    }
  }
  return result;
}
