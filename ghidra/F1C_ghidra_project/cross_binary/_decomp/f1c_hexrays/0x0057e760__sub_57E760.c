// f1c  0x0057e760  size=128
int __thiscall sub_57E760(int *this)
{
  void *v1; // eax
  int *v2; // ebx
  DWORD v3; // eax
  int *v4; // edi
  int v5; // esi
  bool v6; // zf
  int v7; // ebp
  int result; // eax

  v1 = (void *)this[708];
  v2 = this + 704;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[709])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = *v4;
  v6 = *v4 == 0;
  v4[2] = *v4;
  if ( !v6 )
  {
    do
    {
      v7 = v5;
      v5 = *(_DWORD *)(v5 + 4);
      if ( *(_BYTE *)(v7 + 8) )
        sub_587BCF(*(LPVOID *)v7);
      sub_587BCF((LPVOID)v7);
    }
    while ( v5 );
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  result = v2[4];
  if ( result )
    return ReleaseMutex((HANDLE)v2[4]);
  return result;
}
