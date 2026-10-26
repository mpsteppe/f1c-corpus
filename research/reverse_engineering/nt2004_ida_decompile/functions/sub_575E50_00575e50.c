DWORD __thiscall sub_575E50(HANDLE *dwData, int a2)
{
  return QueueUserAPC(pfnAPC, dwData[1], (ULONG_PTR)dwData);
}
