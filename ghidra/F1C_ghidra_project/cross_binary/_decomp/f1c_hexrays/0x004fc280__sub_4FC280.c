// f1c  0x004fc280  size=102
void *__thiscall sub_4FC280(char *this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  void *result; // eax

  *((_DWORD *)this + 17) = -1;
  *(_DWORD *)this = 0;
  v2 = this + 16;
  v3 = 3;
  do
  {
    *v2 = 0;
    v2 += 4;
    --v3;
  }
  while ( v3 );
  if ( *((_DWORD *)this + 19) )
    sub_587BCF(*((LPVOID *)this + 19));
  result = (void *)*((_DWORD *)this + 32);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  this[80] = 0;
  *((_DWORD *)this + 28) = 0;
  if ( result )
    result = (void *)sub_587BCF(result);
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  this[132] = 0;
  *((_DWORD *)this + 41) = 0;
  return result;
}
