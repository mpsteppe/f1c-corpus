int __userpurge sub_4ECD70@<eax>(int a1, int a2, const char *a3)
{
  int v3; // eax
  void *v4; // esi
  int result; // eax
  char *v6; // eax
  int *v7; // [esp+Ch] [ebp-10Ch] BYREF
  int v8; // [esp+10h] [ebp-108h] BYREF
  char Buffer[8]; // [esp+14h] [ebp-104h] BYREF
  int v10; // [esp+1Ch] [ebp-FCh] BYREF

  v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 37);
  v7 = &v10;
  v4 = (void *)v3;
  v10 = 0;
  result = sub_4CE380();
  if ( (_BYTE)result )
  {
    v8 = 0;
    sub_4CE140(v4, (int)&v8);
    v6 = sub_41D840(&byte_91CC38, "<--CHAT");
    sprintf(Buffer, "%s%s%s", a3, (const char *)&v7, v6);
    return sub_4D3F60();
  }
  return result;
}
