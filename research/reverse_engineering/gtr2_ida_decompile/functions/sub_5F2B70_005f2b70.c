int __thiscall sub_5F2B70(_DWORD *ArgList, int a2)
{
  if ( (*(int (__stdcall **)(int, _DWORD, _DWORD))(*(_DWORD *)a2 + 472))(a2, ArgList[16], 0) )
  {
    sub_5D8C80((int)ArgList, (char *)0xFFFFFFFF, "Query type for %s not available", (char)ArgList);
    return -1;
  }
  else if ( (*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)a2 + 472))(a2, ArgList[16], ArgList + 17) )
  {
    sub_5D8C80((int)ArgList, (char *)0xFFFFFFFF, "Error creating device query %s", (char)ArgList);
    return -1;
  }
  else
  {
    return 0;
  }
}
