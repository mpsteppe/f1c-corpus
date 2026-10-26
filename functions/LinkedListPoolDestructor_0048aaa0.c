int __thiscall sub_48AAA0(int this, char a2)
{
  int v3; // esi
  LPVOID **v4; // ebp
  char v5; // al
  LPVOID *v6; // edi

  v3 = *(_DWORD *)(this + 236);
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
          FreeWrapper_7bcf(*v6);
        FreeWrapper_7bcf(v6);
      }
    }
    FreeWrapper_7bcf(v4);
  }
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 0;
  *(_DWORD *)(this + 248) = 0;
  ConstructorWithVTableSet((LPVOID *)this);
  if ( (a2 & 1) != 0 )
    FreeWrapper_7bcf((LPVOID)this);
  return this;
}
