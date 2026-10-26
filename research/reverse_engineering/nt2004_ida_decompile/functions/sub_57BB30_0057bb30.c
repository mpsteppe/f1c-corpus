char __thiscall sub_57BB30(int this, int a2, _DWORD *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ebp
  _BYTE *v6; // edi
  char v7; // dl
  int v8; // eax

  sub_57BA00(this, a2);
  sub_57BAA0((_DWORD *)this);
  *(_WORD *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20)) = *(_WORD *)(this + 16);
  *(_WORD *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20) + 2) = a2;
  v4 = *(unsigned __int16 *)(*(_DWORD *)(this + 8) + 4 * *(_DWORD *)(this + 20));
  v5 = (unsigned __int16)v4 + a2;
  if ( (unsigned __int16)v4 < v5 )
  {
    do
    {
      v6 = (_BYTE *)(*(_DWORD *)this + (v4 >> 3));
      v7 = ~(1 << (v4++ & 7));
      *v6 &= v7;
    }
    while ( v4 < v5 );
  }
  *a3 = *(_DWORD *)(this + 20);
  v8 = *(_DWORD *)(this + 20) + 1;
  *(_DWORD *)(this + 16) += a2;
  *(_DWORD *)(this + 20) = v8;
  return 1;
}
