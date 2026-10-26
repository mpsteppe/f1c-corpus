// f1c  0x004fd840  size=101
int __thiscall sub_4FD840(int this)
{
  int result; // eax
  int v3; // esi
  int i; // esi
  LPVOID *v5; // ebp
  bool v6; // zf

  result = *(_DWORD *)(this + 60);
  *(_DWORD *)(this + 56) = 0;
  if ( result )
  {
    do
    {
      v3 = *(_DWORD *)(*(_DWORD *)(this + 60) + 12);
      result = sub_587BCF(*(LPVOID *)(this + 60));
      *(_DWORD *)(this + 60) = v3;
    }
    while ( v3 );
  }
  for ( i = *(_DWORD *)(this + 84); i; result = sub_587BCF(v5) )
  {
    v5 = (LPVOID *)i;
    v6 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v6 )
      sub_587BCF(*v5);
  }
  *(_DWORD *)(this + 84) = 0;
  *(_DWORD *)(this + 88) = 0;
  *(_DWORD *)(this + 92) = 0;
  *(_DWORD *)(this + 96) = 0;
  return result;
}
