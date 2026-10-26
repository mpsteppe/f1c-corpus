int __thiscall sub_4D8080(int this)
{
  int v2; // esi
  LPVOID **v3; // ebp
  char v4; // al
  LPVOID *v5; // edi
  int result; // eax

  *(_BYTE *)(this + 864) = 1;
  v2 = *(_DWORD *)(this + 848);
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
          sub_5BE8AE(v5[1]);
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  result = 0;
  *(_DWORD *)(this + 848) = 0;
  *(_DWORD *)(this + 852) = 0;
  *(_DWORD *)(this + 856) = 0;
  *(_DWORD *)(this + 860) = 0;
  return result;
}
