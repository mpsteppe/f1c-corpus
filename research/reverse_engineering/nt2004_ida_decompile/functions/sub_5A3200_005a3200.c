int __thiscall sub_5A3200(int *this)
{
  _DWORD *v2; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // edx

  if ( (this[25] & 0x20000) != 0 )
  {
    if ( !this[4] )
    {
      v2 = operator new(0x24u);
      if ( v2 )
      {
        v2[5] = 0;
        v2[4] = 0;
        v2[3] = 0;
        v2[2] = 0;
        v2[1] = 0;
        *v2 = 0;
        v2[7] = 0;
        v2[6] = 0;
        v2[8] = 0;
      }
      else
      {
        v2 = 0;
      }
      this[4] = (int)v2;
    }
    *(_DWORD *)this[4] = 34;
    *(_DWORD *)(this[4] + 12) = 768;
    *(_DWORD *)(this[4] + 8) = 28;
    *(_DWORD *)(this[4] + 4) = dword_7FEEB4;
    if ( sub_5A7F10((int)&unk_7E6B48, this[4]) )
      return -1;
    v4 = sub_5A8020(this[4], 96, 0, 0);
    v5 = this[4];
    this[5] = v4;
    v6 = 0;
    if ( *(int *)(v5 + 12) > 0 )
    {
      do
      {
        *(_DWORD *)(this[5] + 8) = 0;
        *(_DWORD *)(this[5] + 12) = 1065353216;
        v7 = this[4];
        this[5] += 28;
        ++v6;
      }
      while ( v6 < *(_DWORD *)(v7 + 12) );
    }
    sub_5A80B0(this[4]);
  }
  return 0;
}
