char __thiscall sub_56ACD0(int this, _DWORD *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // eax

  *(_BYTE *)(this + 4) = 0;
  v3 = operator new(0x10u);
  v4 = v3;
  if ( v3 )
  {
    *(_WORD *)v3 = 2;
    v3[1] = htonl(0);
    *((_WORD *)v4 + 1) = htons(0);
  }
  else
  {
    v4 = 0;
  }
  *v4 = *a2;
  v4[1] = a2[1];
  v4[2] = a2[2];
  v4[3] = a2[3];
  v5 = operator new(0xCu);
  if ( v5 )
  {
    *v5 = v4;
    v5[1] = 0;
    *((_BYTE *)v5 + 8) = 1;
  }
  else
  {
    v5 = 0;
  }
  if ( *(_DWORD *)(this + 8) )
  {
    *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = v5;
  }
  else
  {
    *(_DWORD *)(this + 8) = v5;
    *(_DWORD *)(this + 16) = v5;
  }
  *(_DWORD *)(this + 12) = v5;
  ++*(_DWORD *)(this + 20);
  return 0;
}
