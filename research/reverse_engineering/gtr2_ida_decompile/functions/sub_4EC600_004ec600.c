int __userpurge sub_4EC600@<eax>(int a1@<edi>, int a2, int a3, int a4, int a5)
{
  int result; // eax
  void *v6; // esi
  int v7; // eax
  int v8; // [esp+14h] [ebp-114h] BYREF
  char Buffer[4]; // [esp+18h] [ebp-110h] BYREF
  int v10; // [esp+1Ch] [ebp-10Ch]
  const char *v11; // [esp+120h] [ebp-8h]
  const char *retaddr; // [esp+128h] [ebp+0h]

  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 37);
  v6 = (void *)result;
  v10 = 0;
  if ( result )
  {
    v8 = a1;
    *(_DWORD *)Buffer = 0;
    if ( (unsigned __int8)sub_4CE380() )
    {
      sub_4CE140(v6, (int)Buffer);
      sprintf(Buffer, "%s%s%s", retaddr, (const char *)&v8, v11);
      sub_4D3F60();
      result = sub_4CE380();
      if ( !(_BYTE)result )
        return result;
      return sub_4CE460(v6);
    }
    sub_4CE140(v6, (int)Buffer);
    v7 = sprintf(Buffer, "%s%s%s", retaddr, (const char *)&v8, v11);
    sub_4D93B0(v7, (int)Buffer, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    result = sub_4CE380();
    if ( (_BYTE)result )
      return sub_4CE460(v6);
  }
  return result;
}
