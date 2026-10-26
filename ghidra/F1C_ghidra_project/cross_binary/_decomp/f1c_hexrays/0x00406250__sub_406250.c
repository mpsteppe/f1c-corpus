// f1c  0x00406250  size=96
void *__thiscall sub_406250(char *this)
{
  char *v2; // esi
  int v3; // ebx
  void *result; // eax

  *(_DWORD *)this = &off_59E4EC;
  sub_4064C0();
  sub_407C90(this);
  if ( this[88] && CloseHandle(*((HANDLE *)this + 20)) )
    *((_DWORD *)this + 20) = 0;
  v2 = this + 76;
  v3 = 3;
  do
  {
    result = (void *)*((_DWORD *)v2 - 5);
    v2 -= 20;
    if ( result )
      result = (void *)sub_587BCF(result);
    --v3;
  }
  while ( v3 );
  *(_DWORD *)this = &off_59E50C;
  return result;
}
