// f1c  0x005932f3  size=339
int *__cdecl sub_5932F3(DWORD NumberOfBytesWritten)
{
  int v1; // ecx
  int *result; // eax
  int v3; // esi
  CHAR *v4; // edi
  char **v5; // esi
  HANDLE StdHandle; // eax
  char *v7; // [esp-14h] [ebp-1B8h]
  char *v8; // [esp-10h] [ebp-1B4h]
  CHAR *p_NumberOfBytesWritten; // [esp-Ch] [ebp-1B0h]
  const char *v10; // [esp-8h] [ebp-1ACh]
  CHAR Filename[260]; // [esp+0h] [ebp-1A4h] BYREF
  _DWORD v12[40]; // [esp+104h] [ebp-A0h] BYREF
  int savedregs; // [esp+1A4h] [ebp+0h] BYREF

  v1 = 0;
  result = dword_5E78C0;
  do
  {
    if ( NumberOfBytesWritten == *result )
      break;
    result += 2;
    ++v1;
  }
  while ( (int)result < (int)&off_5E7950 );
  v3 = 2 * v1;
  if ( NumberOfBytesWritten == dword_5E78C0[2 * v1] )
  {
    result = (int *)dword_8D3EBC;
    if ( dword_8D3EBC == 1 || !dword_8D3EBC && dword_5E65B4 == 1 )
    {
      v5 = &(&off_5E78C4)[v3];
      v10 = 0;
      p_NumberOfBytesWritten = (CHAR *)&NumberOfBytesWritten;
      v8 = sub_58E1B0(*v5);
      v7 = *v5;
      StdHandle = GetStdHandle(0xFFFFFFF4);
      return (int *)WriteFile(StdHandle, v7, (DWORD)v8, &NumberOfBytesWritten, 0);
    }
    else if ( NumberOfBytesWritten != 252 )
    {
      if ( !GetModuleFileNameA(0, Filename, 0x104u) )
      {
        v10 = "<program name unknown>";
        p_NumberOfBytesWritten = Filename;
        sub_58FCA0();
      }
      v4 = Filename;
      if ( (unsigned int)(sub_58E1B0(Filename) + 1) > 0x3C )
      {
        v4 = &sub_58E1B0(Filename)[(_DWORD)&savedregs - 479];
        sub_587DD0(v4, asc_5C5C8C, 3u);
      }
      p_NumberOfBytesWritten = "Runtime Error!\n\nProgram: ";
      v8 = (char *)v12;
      sub_58FCA0();
      sub_58FCB0(v12, v4);
      sub_58FCB0(v12, "\n\n");
      sub_58FCB0(v12, (&off_5E78C4)[v3]);
      return (int *)sub_597234(v12, "Microsoft Visual C++ Runtime Library", 73744);
    }
  }
  return result;
}
