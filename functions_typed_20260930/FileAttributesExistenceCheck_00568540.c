bool __thiscall sub_568540(LPCSTR lpFileName)
{
  ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128);
  return FileDeleteWithErrorHandling(lpFileName) == 0;
}

