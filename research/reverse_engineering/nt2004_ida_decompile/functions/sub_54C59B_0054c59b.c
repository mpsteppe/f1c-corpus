void __thiscall sub_54C59B(int this)
{
  const void *v2; // eax

  if ( *(_DWORD *)this != -1 )
  {
    v2 = *(const void **)(this + 8);
    if ( v2 )
    {
      UnmapViewOfFile(v2);
      *(_DWORD *)(this + 8) = 0;
      *(_DWORD *)(this + 12) = 0;
    }
    if ( *(_DWORD *)(this + 4) != -1 )
    {
      CloseHandle(*(HANDLE *)(this + 4));
      *(_DWORD *)(this + 4) = -1;
    }
    if ( *(_DWORD *)this != -1 )
    {
      CloseHandle(*(HANDLE *)this);
      *(_DWORD *)this = -1;
    }
  }
}
