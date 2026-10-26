void *__thiscall sub_4BBF50(_DWORD *this)
{
  int v1; // esi
  void *result; // eax

  v1 = *((_DWORD *)off_5FD348 + 5213);
  *((_DWORD *)off_5FD348 + 5213) = this[1];
  sub_51C900((char *)off_5FD348 + 84);
  result = off_5FD348;
  *((_DWORD *)off_5FD348 + 5213) = v1;
  return result;
}
