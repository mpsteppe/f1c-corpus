int __cdecl toupper(int C)
{
  int v1; // ebx
  int result; // eax
  int Ca; // [esp+8h] [ebp+4h]

  v1 = 0;
  if ( dword_7FF1E8 )
  {
    InterlockedIncrement(&dword_80151C);
    if ( dword_801518 )
    {
      InterlockedDecrement(&dword_80151C);
      _lock(19);
      v1 = 1;
    }
    Ca = toupper_0(C);
    if ( v1 )
      _unlock(19);
    else
      InterlockedDecrement(&dword_80151C);
    return Ca;
  }
  else
  {
    result = C;
    if ( C >= 97 && C <= 122 )
      return C - 32;
  }
  return result;
}
