int __stdcall sub_4BBAC0(int a1, int a2, int a3, int a4)
{
  int result; // eax
  _DWORD *v5; // esi
  __int32 v6; // edx
  __int32 v7; // edx
  int v8; // [esp+0h] [ebp-4h]
  int v9; // [esp+0h] [ebp-4h]
  int v10; // [esp+0h] [ebp-4h]

  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 68);
  v5 = (_DWORD *)result;
  if ( result )
  {
    sub_615860(a4);
    sub_4B99D0(v6, v8);
    sub_4B99D0(v7, v9);
    v5[154] = 0;
    sub_4D0AC0(v10);
    v5[139] = 0;
    v5[140] = 0;
    return sub_4A8980();
  }
  return result;
}
