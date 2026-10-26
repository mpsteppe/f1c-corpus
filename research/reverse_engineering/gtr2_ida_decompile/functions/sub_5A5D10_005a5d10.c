char __thiscall sub_5A5D10(HANDLE *dwData, int a2)
{
  (*((void (__thiscall **)(HANDLE *))*dwData + 15))(dwData);
  QueueUserAPC(pfnAPC, dwData[2], (ULONG_PTR)dwData);
  if ( !(unsigned __int8)sub_5A5A20() )
    return 0;
  ((void (__thiscall *)(int))sub_5A6A30)(a2);
  (*((void (__thiscall **)(HANDLE *))*dwData + 23))(dwData);
  return 1;
}
