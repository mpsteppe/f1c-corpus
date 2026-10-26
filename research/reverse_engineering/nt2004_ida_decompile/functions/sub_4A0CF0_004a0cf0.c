int __thiscall sub_4A0CF0(int this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = *(_DWORD *)(this + 276);
  while ( v3 )
  {
    v4 = (LPVOID **)v3;
    v5 = *(_BYTE *)(v3 + 8);
    v3 = *(_DWORD *)(v3 + 4);
    if ( v5 )
    {
      v6 = *v4;
      if ( *v4 )
      {
        if ( *v6 )
          sub_5BE8AE(*v6);
        sub_5BE8AE(v6);
      }
    }
    sub_5BE8AE(v4);
  }
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 0;
  *(_DWORD *)(this + 288) = 0;
  sub_49EC50((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    sub_5BE8AE((LPVOID)this);
  return this;
}
