int __thiscall sub_561F80(SOCKET *lpMem)
{
  SOCKET *v1; // esi
  SOCKET v2; // eax

  v1 = lpMem;
  if ( !lpMem )
    v1 = (SOCKET *)off_5E4DFC;
  if ( *v1 != -1 && v1[57] )
    closesocket(*v1);
  v2 = v1[1];
  if ( v2 != -1 && v2 != *v1 )
    closesocket(v1[1]);
  v1[1] = -1;
  *v1 = -1;
  v1[54] = 0;
  if ( v1 != (SOCKET *)&unk_5E4CF8 )
    sub_58AA6F(v1);
  return j_WSACleanup();
}
