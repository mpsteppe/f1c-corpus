char __thiscall sub_457B00(int this, char a2)
{
  int v3; // eax

  LOBYTE(v3) = *(_BYTE *)(this + 156);
  if ( (_BYTE)v3 || a2 != 1 )
  {
    if ( (_BYTE)v3 == 1 && !a2 )
    {
      LOBYTE(v3) = (unsigned __int8)sub_456130((_DWORD *)this, (_DWORD *)(this + 144));
      *(_BYTE *)(this + 156) = 0;
    }
  }
  else
  {
    *(_DWORD *)(this + 144) = *(_DWORD *)(this + 24);
    v3 = *(_DWORD *)(this + 32);
    *(_DWORD *)(this + 148) = *(_DWORD *)(this + 28);
    *(_BYTE *)(this + 156) = 1;
    *(_DWORD *)(this + 152) = v3;
  }
  return v3;
}
