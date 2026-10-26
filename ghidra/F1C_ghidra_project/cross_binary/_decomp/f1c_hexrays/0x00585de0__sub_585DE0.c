// f1c  0x00585de0  size=19
DWORD __thiscall sub_585DE0(HANDLE *dwData, int a2)
{
  return QueueUserAPC(pfnAPC, dwData[1], (ULONG_PTR)dwData);
}
