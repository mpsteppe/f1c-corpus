int __fastcall sub_5BBFB0(int a1, int a2, char *Str, int a4)
{
  BOOL v6; // esi
  int result; // eax
  char v8; // al
  char v9; // al

  v6 = strstr(Str, aFinal) != 0;
  result = sub_5BA230((_DWORD *)a2, (int)Str);
  if ( v6 )
  {
    v8 = *(_BYTE *)(a2 + 20);
    if ( (v8 & 4) != 0 )
      v9 = v8 | 1;
    else
      v9 = v8 | 2;
    *(_BYTE *)(a2 + 20) = v9;
    *(_BYTE *)(a2 + 20) = v9 & 0xF3;
    *(_DWORD *)(a2 + 28) = GetTickCount() - *(_DWORD *)(a2 + 28);
    sub_5BBF60((int *)(a1 + 8), a2);
    return (*(int (__fastcall **)(int, _DWORD, int, _DWORD))(a1 + 64))(a1, 0, a2, *(_DWORD *)(a1 + 68));
  }
  return result;
}
