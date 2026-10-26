// f1c  0x0055be20  size=62
_DWORD *__thiscall sub_55BE20(char *this, int a2, _DWORD *a3, _DWORD *a4)
{
  char *v4; // eax
  char v5; // dl
  _DWORD *result; // eax

  if ( a2 )
  {
    v4 = this + 4;
    do
    {
      v5 = *v4;
      v4[a2 - (_DWORD)(this + 4)] = *v4;
      ++v4;
    }
    while ( v5 );
  }
  if ( a3 )
    *a3 = *((_DWORD *)this + 68);
  result = a4;
  if ( a4 )
    *a4 = *((_DWORD *)this + 69);
  return result;
}
