int __thiscall sub_5BAAD0(SOCKET *lpMem)
{
  SOCKET *v1; // esi
  int result; // eax

  v1 = lpMem;
  if ( !lpMem )
    v1 = (SOCKET *)off_624A10;
  if ( v1[45] )
    sub_5BB940(v1, 2);
  if ( *v1 != -1 && v1[47] )
    closesocket(*v1);
  result = v1[47];
  *v1 = -1;
  v1[42] = 0;
  if ( result )
    result = j_WSACleanup();
  if ( v1 != (SOCKET *)&unk_624908 )
    return sub_5C1B88(v1);
  return result;
}
