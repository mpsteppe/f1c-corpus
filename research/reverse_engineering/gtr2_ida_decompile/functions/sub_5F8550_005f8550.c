int __userpurge sub_5F8550@<eax>(int a1@<ecx>, char a2@<dil>, _DWORD *a3, int a4, const char *a5, const char *a6)
{
  int v7; // ebx
  char v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h] BYREF

  if ( a4 < 0 )
  {
    sub_5D8C80(a1 + 4, (char *)0xFFFFFFFF, "Invalid shader pass", v9);
    return -1;
  }
  else
  {
    v10 = 0;
    v11 = 0;
    sub_5F79C0((_DWORD *)(a1 + 9140), a5, &v10);
    v7 = v10;
    if ( !v10 )
    {
      sub_5D8C80(a1 + 4, (char *)0xFFFFFFFF, "Invalid vertex shader", a2);
      return -1;
    }
    sub_5F7A70((_DWORD *)(a1 + 9140), a6, &v11);
    if ( !v11 )
    {
      sub_5D8C80(a1 + 4, (char *)0xFFFFFFFF, "Invalid pixel shader", a2);
      return -1;
    }
    sub_5F8510(a3, a4, v7, v11);
    return 0;
  }
}
