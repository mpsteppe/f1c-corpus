// f1c  0x0051aefc  size=91
char __usercall sub_51AEFC@<al>(_DWORD *a1@<edi>)
{
  int v1; // esi
  char result; // al
  int v3; // edx
  _DWORD *v4; // ecx

  v1 = a1[101];
  *(_DWORD *)(a1[100] + 88) += *(_DWORD *)(v1 + 20) / 8;
  *(_DWORD *)(v1 + 20) = 0;
  result = (*(int (__cdecl **)(_DWORD *))(a1[100] + 8))(a1);
  if ( result )
  {
    v3 = 0;
    if ( (int)a1[72] > 0 )
    {
      v4 = (_DWORD *)(v1 + 36);
      do
      {
        *v4 = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < a1[72] );
    }
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 52) = a1[63];
    *(_BYTE *)(v1 + 24) = 0;
    return 1;
  }
  return result;
}
