int __fastcall sub_5629B0(int a1, const struct sockaddr *a2, char *buf, const char *a4)
{
  int result; // eax
  int v6; // ebp
  char *v7; // esi
  char v9[128]; // [esp+14h] [ebp-248h] BYREF
  char v10[256]; // [esp+94h] [ebp-1C8h] BYREF
  char v11[200]; // [esp+194h] [ebp-C8h] BYREF

  if ( *a4 )
  {
    result = 0;
    v6 = strlen(a4);
    if ( v6 > 128 )
      return result;
    strcpy(v9, a4);
    sub_562150(a1 + 72, strlen((const char *)(a1 + 72)), (int)v9, v6);
    sub_562090(v9, v6, v11);
    sub_58815F(v10, "\\validate\\%s", v11);
    v7 = buf;
    sub_562710((SOCKET *)a1, a2, buf, v10);
  }
  else
  {
    v7 = buf;
  }
  sub_58815F(v10, aFinal);
  sub_562710((SOCKET *)a1, a2, v7, v10);
  return sub_562610((SOCKET *)a1, a2, v7);
}
