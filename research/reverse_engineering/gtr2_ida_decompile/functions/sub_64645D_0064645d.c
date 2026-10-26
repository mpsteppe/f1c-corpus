int __thiscall sub_64645D(int this)
{
  int v2; // eax
  int v3; // eax
  DWORD v5; // eax
  DWORD NumberOfBytesWritten; // [esp+4h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(this + 16);
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 != 1 )
        return -2147467259;
    }
    else
    {
      v5 = *(_DWORD *)(this + 28);
      if ( v5 )
      {
        if ( !WriteFile(*(HANDLE *)this, *(LPCVOID *)(this + 24), v5, &NumberOfBytesWritten, 0) )
          return -2147467259;
        *(_DWORD *)(this + 32) += *(_DWORD *)(this + 28);
        *(_DWORD *)(this + 28) = 0;
      }
    }
  }
  return 0;
}
