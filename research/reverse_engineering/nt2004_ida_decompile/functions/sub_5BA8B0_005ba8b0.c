int __fastcall sub_5BA8B0(
        char **a1,
        char *a2,
        int a3,
        const char *a4,
        char *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  int v15; // edi
  int result; // eax
  int v17; // [esp+8h] [ebp-4h] BYREF

  v15 = sub_5BA7B0((SOCKET *)&v17, a2, &a3);
  if ( v15 )
  {
    j_WSACleanup();
    return v15;
  }
  else
  {
    result = sub_5BA610(a1, v17, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14);
    if ( !a1 )
      a1 = (char **)&off_624A10;
    *((_DWORD *)*a1 + 47) = 1;
  }
  return result;
}
