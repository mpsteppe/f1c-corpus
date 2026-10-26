int __thiscall sub_4E9B50(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 4);
  if ( result )
  {
    UnmapViewOfFile(*(LPCVOID *)(this + 4));
    return CloseHandle(*(HANDLE *)this);
  }
  return result;
}
