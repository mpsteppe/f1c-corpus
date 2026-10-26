void __thiscall sub_4D5660(_DWORD *this, int a2, int a3)
{
  int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ecx

  v4 = ((int (*)(void))sub_4D6280)();
  if ( !v4 )
  {
    sub_4D6300(*(float *)&a3);
    v4 = sub_4D6280(this);
  }
  v5 = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v6 = this[332] - v5;
      if ( v6 < 0 )
        v6 += this[331];
      v7 = sub_4D62E0(v6);
      if ( *(float *)(a2 + 4) >= (double)*(float *)(v7 + 60) )
        break;
      if ( ++v5 >= v4 )
        return;
    }
    if ( *(float *)(a2 + 4) - *(float *)(v7 + 60) < 1.5 )
      sub_4D3840((_BYTE *)v7, (_DWORD *)a2, a3);
  }
}
