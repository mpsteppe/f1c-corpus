BOOL sub_617350(int a1, char *Format, ...)
{
  int v2; // kr00_4
  char *v3; // eax
  char Buffer[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list va; // [esp+80Ch] [ebp+Ch] BYREF

  va_start(va, Format);
  vsprintf(Buffer, Format, va);
  v2 = strlen(Buffer);
  v3 = Buffer;
  if ( *(_BYTE *)(a1 + 92) )
    v3 = (char *)(*(int (__thiscall **)(int, char *, int))(*(_DWORD *)(a1 + 96) + 20))(a1 + 96, Buffer, v2);
  return v2 == sub_613C90((_DWORD *)a1, (int)v3, v2);
}
