int __fastcall sub_539830(char a1, char a2, int a3, int a4, int a5)
{
  int result; // eax

  result = (*(int (__fastcall **)(_DWORD, int, int))(a5 + 32))(*(_DWORD *)(a5 + 40), 1, 26);
  if ( result )
  {
    *(_BYTE *)(result + 16) = a1;
    *(_DWORD *)result = 0;
    *(_BYTE *)(result + 17) = a2;
    *(_DWORD *)(result + 18) = a3;
    *(_DWORD *)(result + 22) = a4;
  }
  return result;
}
