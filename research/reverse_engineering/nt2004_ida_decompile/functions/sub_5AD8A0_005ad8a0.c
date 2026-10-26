void __thiscall sub_5AD8A0(int this, int a2)
{
  int v3; // eax
  int *v4; // ecx
  double v5; // st7
  int v6; // ecx

  if ( *(_DWORD *)(this + 28) )
  {
    v3 = *(_DWORD *)(this + 4);
    if ( (v3 & 0x1000) != 0 )
    {
      v4 = *(int **)this;
      *(_DWORD *)(this + 4) = v3 & 0xFFFF6FFF | 0x8000;
      *(_DWORD *)(this + 8) = 0;
      sub_5AC740(v4, 1);
    }
    if ( (BYTE1(*(_DWORD *)(this + 4)) & 0x80u) != 0 )
    {
      v5 = sub_5AC8D0((unsigned int *)*(_DWORD *)this);
      *(float *)(this + 16) = v5;
      v6 = *(_DWORD *)(this + 28);
      if ( v5 >= *(float *)(v6 + 8) )
      {
        *(_DWORD *)(this + 16) = *(_DWORD *)(v6 + 8);
        if ( (*(_DWORD *)(this + 4) & 0x20000) != 0 )
        {
          sub_5AD880((_DWORD *)this);
          sub_5AD5F0((_DWORD *)this, a2, *(float *)(this + 16));
          return;
        }
        sub_5AD820((_BYTE **)this);
        sub_5AD860(this);
      }
      sub_5AD5F0((_DWORD *)this, a2, *(float *)(this + 16));
    }
  }
}
