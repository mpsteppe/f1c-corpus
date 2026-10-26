// f1c  0x005972bd  size=70
int __stdcall sub_5972BD(_DWORD *a1)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)*a1;
  if ( *(_DWORD *)*a1 == -529697949 && v1[4] == 3 && v1[5] == 429065504 )
    return sub_593C9C((int)a1);
  if ( lpfn && sub_597359(lpfn) )
    return lpfn();
  return 0;
}
