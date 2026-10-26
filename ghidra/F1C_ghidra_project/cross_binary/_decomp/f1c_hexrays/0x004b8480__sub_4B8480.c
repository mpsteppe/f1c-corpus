// f1c  0x004b8480  size=111
int __thiscall sub_4B8480(int this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax

  *(_BYTE *)(this + 1744) = 1;
  v2 = *(_DWORD *)(this + 1728);
  while ( v2 )
  {
    v3 = (LPVOID **)v2;
    v4 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v4 )
    {
      v5 = *v3;
      if ( *v3 )
      {
        if ( v5[1] )
          sub_587BCF(v5[1]);
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  result = 0;
  *(_DWORD *)(this + 1728) = 0;
  *(_DWORD *)(this + 1732) = 0;
  *(_DWORD *)(this + 1736) = 0;
  *(_DWORD *)(this + 1740) = 0;
  return result;
}
