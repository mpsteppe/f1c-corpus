int __stdcall ClearBufferAndInit(void *a1)
{
  _BYTE v2[256]; // [esp+0h] [ebp-100h] BYREF

  PathBuilderWithBackslash(a1, 256);
  return AddVehicleConfigEntryToLinkedList(&dword_7C73E8, (int)v2, 0, 1);
}
