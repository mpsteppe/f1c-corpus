void __thiscall sub_46C830(int this, int a2)
{
  unsigned __int8 v4; // c2
  unsigned __int8 v5; // c3
  int i; // edx
  int v7; // edx
  float v8; // [esp+0h] [ebp-8h]

  if ( *(float *)(this + 61) < (double)*(float *)(a2 + 4)
    || ((*(_DWORD *)a2 ^ *(_DWORD *)(this + 57)) & 0x3C00000) != 0
    || *(float *)(this + 61) - *(float *)(a2 + 4) > 5.0 )
  {
    if ( (*(_BYTE *)(a2 + 2) & 0x3F) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 2) & 0x3F) == 7 )
      {
        v8 = *(float *)(a2 + 4);
        if ( v5 | v4 )
          sub_4D0C80(this + 57, *(_DWORD *)a2 & 0x3F, LODWORD(v8));
        else
          sub_4D08E0(this + 57, LODWORD(v8));
      }
    }
    else
    {
      sub_4D1850(a2);
    }
    for ( i = 0; i < 49; i = v7 + 1 )
      sub_46C6C0((_BYTE *)(i + this), 0);
  }
}
