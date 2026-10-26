HANDLE __thiscall sub_47EB30(_DWORD *this, unsigned __int8 a2, int a3, int a4, const void *a5, signed int a6)
{
  HANDLE result; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // ebp
  unsigned int v11; // eax

  result = (HANDLE)WaitForSingleObject(dword_759E40, 0xFAu);
  if ( result != (HANDLE)258 && result != (HANDLE)-1 )
  {
    *(_DWORD *)(this[1] + 4 * a2 + 112052) = a3;
    v8 = 528 * a2;
    ++*(_DWORD *)(this[1] + 112884);
    v9 = this[1];
    if ( a6 <= 0 )
    {
      sub_4733E0((_BYTE *)(v8 + v9 + 2228));
    }
    else
    {
      qmemcpy((void *)(v9 + v8 + 2228), a5, a6);
      sub_47EA70();
      v10 = this[1];
      if ( (*(_BYTE *)(v8 + v10 + 2752) & 2) != 0 && *(_DWORD *)(v8 + v10 + 2228) == 3 )
      {
        v11 = *(char *)(v8 + v10 + 2740);
        if ( v11 < 0x68 )
          *(_DWORD *)(v10 + 4 * v11 + 112888) = a3;
      }
    }
    result = dword_759E40;
    if ( dword_759E40 )
      return (HANDLE)ReleaseMutex(dword_759E40);
  }
  return result;
}
