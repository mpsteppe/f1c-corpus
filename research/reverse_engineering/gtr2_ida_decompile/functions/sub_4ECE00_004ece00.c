int __stdcall sub_4ECE00(int a1)
{
  void *v1; // esi
  const char *v2; // edi
  int result; // eax
  char *v4; // eax
  _DWORD *v5; // [esp+0h] [ebp-11Ch] BYREF
  int v6; // [esp+4h] [ebp-118h] BYREF
  char Buffer[8]; // [esp+8h] [ebp-114h] BYREF
  _DWORD v8[67]; // [esp+10h] [ebp-10Ch] BYREF

  v1 = (void *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 37);
  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 34) )
    sub_4D0AC0();
  v2 = (const char *)v8[66];
  v5 = v8;
  v8[0] = 0;
  result = sub_4CE380();
  if ( (_BYTE)result )
  {
    v6 = 0;
    sub_4CE140(v1, (int)&v6);
    v4 = sub_41D840(&byte_91CC38, WindowName);
    sprintf(Buffer, "%s%s%s", v2, (const char *)&v5, v4);
    return sub_4D3F60();
  }
  return result;
}
