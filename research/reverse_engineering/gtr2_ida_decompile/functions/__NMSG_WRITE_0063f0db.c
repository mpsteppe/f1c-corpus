unsigned int __cdecl _NMSG_WRITE(DWORD NumberOfBytesWritten)
{
  unsigned int result; // eax
  int v2; // esi
  const char *v3; // edi
  int v4; // ebx
  int v5; // eax
  int *v6; // esi
  HANDLE StdHandle; // eax
  LPCVOID v8; // [esp-10h] [ebp-9Ch]
  DWORD v9; // [esp-Ch] [ebp-98h]
  DWORD *p_NumberOfBytesWritten; // [esp-8h] [ebp-94h]
  int v11; // [esp-4h] [ebp-90h]
  char v12[140]; // [esp+0h] [ebp-8Ch] BYREF
  _BYTE v13[136]; // [esp+8Ch] [ebp+0h] BYREF
  int v14; // [esp+114h] [ebp+88h]

  v14 = dword_912B08;
  for ( result = 0; result < 0x13; ++result )
  {
    if ( NumberOfBytesWritten == dword_913580[2 * result] )
      break;
  }
  v2 = 2 * result;
  if ( NumberOfBytesWritten == dword_913580[2 * result] )
  {
    result = dword_FB81E0;
    if ( dword_FB81E0 == 1 || !dword_FB81E0 && dword_912B04 == 1 )
    {
      v11 = 0;
      p_NumberOfBytesWritten = &NumberOfBytesWritten;
      v6 = (int *)&(&off_913584)[v2];
      v9 = sub_6354D0(*v6);
      v8 = (LPCVOID)*v6;
      StdHandle = GetStdHandle(0xFFFFFFF4);
      return WriteFile(StdHandle, v8, v9, &NumberOfBytesWritten, 0);
    }
    else if ( NumberOfBytesWritten != 252 )
    {
      v13[132] = 0;
      if ( !GetModuleFileNameA(0, &v12[12], 0x104u) )
        strcpy(&v12[12], "<program name unknown>");
      v3 = &v12[12];
      if ( (unsigned int)(sub_6354D0((int)&v12[12]) + 1) > 0x3C )
      {
        v3 = &v13[sub_6354D0((int)&v12[12]) - 187];
        sub_630FE0((int)v3, (int)"...", 3);
      }
      v4 = sub_6354D0((int)v3);
      v5 = sub_6354D0((int)(&off_913584)[v2]);
      sub_631BD0((v4 + v5 + 31) & 0xFFFFFFFC, v12[0]);
      strcpy(v12, "Runtime Error!\n\nProgram: ");
      strcat(v12, v3);
      strcat(v12, "\n\n");
      strcat(v12, (&off_913584)[v2]);
      return __crtMessageBoxA(v12, "Microsoft Visual C++ Runtime Library", 8208);
    }
  }
  return result;
}
