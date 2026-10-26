int __thiscall sub_65861B(int this, int a2)
{
  unsigned int v3; // ecx
  int v4; // edi
  void *v5; // eax
  void *v6; // eax
  int v7; // eax
  void *v9; // [esp+Ch] [ebp-4h]

  sub_64FBCE((float *)this, (float *)a2, 0, 1);
  v3 = *(_DWORD *)(this + 60) & 0xFFFFFFFE;
  v4 = ((*(_DWORD *)(this + 68) + 1) & 0xFFFFFFFE) - v3;
  *(_DWORD *)(this + 140) = (*(_DWORD *)(this + 68) + 1) & 0xFFFFFFFE;
  *(_DWORD *)this = &off_7377B8;
  *(_DWORD *)(this + 132) = v3;
  *(_DWORD *)(this + 136) = 0;
  *(_DWORD *)(this + 148) = 0;
  *(_DWORD *)(this + 144) = 0;
  *(_DWORD *)(this + 152) = 0;
  *(_DWORD *)(this + 156) = v4;
  *(_DWORD *)(this + 160) = 0;
  *(_DWORD *)(this + 164) = 1;
  v5 = operator new(16 * v4);
  v9 = v5;
  if ( v5 )
  {
    sub_41D1B0((int)v5, 16, v4, (int)sub_681563);
    v6 = v9;
  }
  else
  {
    v6 = 0;
  }
  *(_DWORD *)(this + 128) = v6;
  if ( !v6 )
    *(_DWORD *)(this + 164) = 0;
  v7 = *(_DWORD *)(a2 + 4);
  switch ( v7 )
  {
    case 844715353:
      goto LABEL_11;
    case 1111970375:
LABEL_10:
      *(_DWORD *)(this + 168) = 8;
      *(_DWORD *)(this + 172) = 0;
      return this;
    case 1195525970:
LABEL_11:
      *(_DWORD *)(this + 168) = 0;
      *(_DWORD *)(this + 172) = 8;
      return this;
    case 1498831189:
      goto LABEL_10;
  }
  return this;
}
