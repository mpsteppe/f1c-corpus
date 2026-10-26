void *__thiscall sub_406F10(LPVOID *this)
{
  char *v2; // edi
  int v3; // ebx
  void *result; // eax

  *this = &off_5D558C;
  sub_407190();
  sub_408A70(this);
  if ( this[24] )
    sub_5BE8AE(this[24]);
  if ( *((_BYTE *)this + 88) && CloseHandle(this[20]) )
    this[20] = 0;
  v2 = (char *)(this + 19);
  v3 = 3;
  do
  {
    result = (void *)*((_DWORD *)v2 - 5);
    v2 -= 20;
    if ( result )
      result = (void *)sub_5BE8AE(result);
    --v3;
  }
  while ( v3 );
  *this = &off_5D55B0;
  return result;
}
