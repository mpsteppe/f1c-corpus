int __thiscall sub_5BC800(char *this)
{
  SOCKET v2; // eax
  int v3; // edi
  int result; // eax
  _DWORD *v5; // ebx

  if ( *((_DWORD *)this + 29) )
    sub_5C1B88(*((LPVOID *)this + 29));
  v2 = *((_DWORD *)this + 296);
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  if ( v2 != -1 )
    closesocket(v2);
  *((_DWORD *)this + 296) = -1;
  *(_DWORD *)this = 1;
  sub_5BC8A0(this);
  *((_DWORD *)this + 287) = -1;
  v3 = 0;
  result = *((_DWORD *)this + 286);
  if ( result > 0 )
  {
    v5 = this + 124;
    do
    {
      sub_5BDB30(this, *v5);
      result = *((_DWORD *)this + 286);
      ++v3;
      ++v5;
    }
    while ( v3 < result );
  }
  *((_DWORD *)this + 286) = 0;
  return result;
}
