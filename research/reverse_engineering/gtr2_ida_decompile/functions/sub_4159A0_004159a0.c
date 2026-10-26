void __thiscall sub_4159A0(char *this)
{
  char v2; // al
  int v3; // eax
  int v4; // eax
  char *v5; // ecx
  int v6; // eax
  _DWORD *v7; // eax
  void *v8; // eax

  v2 = this[160];
  *(_DWORD *)this = 1;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  if ( v2 )
    *(_BYTE *)(*((_DWORD *)this + 1) + 48) = 0;
  v3 = *((_DWORD *)this + 36);
  this[160] = 0;
  if ( v3 )
    sub_413CB0(*((_DWORD *)this + 1), v3, 1);
  v4 = *((_DWORD *)this + 37);
  if ( v4 >= 0 )
  {
    v5 = (char *)*(&dword_91E088 + v4);
    dword_91E078 = *((_DWORD *)this + 37);
    dword_91E07C = v5;
  }
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = -1;
  sub_6167F0(this + 76);
  v6 = *((_DWORD *)this + 34);
  if ( v6 )
  {
    *(_DWORD *)(v6 + 4) = 0;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    *(_DWORD *)(v6 + 16) = 0;
    *(_DWORD *)(v6 + 20) = 0;
    *(_DWORD *)(v6 + 24) = 0;
    *(_DWORD *)(v6 + 28) = 0;
    *(_BYTE *)(v6 + 32) = 0;
    *(_DWORD *)(v6 + 36) = 0;
    *(_DWORD *)(v6 + 40) = 1;
    *(_DWORD *)(v6 + 44) = 0;
  }
  else
  {
    v7 = operator new(0x30u);
    if ( v7 )
    {
      *v7 = this;
      v7[1] = 0;
      v7[2] = 0;
      v7[3] = 0;
      v7[4] = 0;
      v7[5] = 0;
      v7[6] = 0;
      v7[7] = 0;
      *((_BYTE *)v7 + 32) = 0;
      v7[9] = 0;
      v7[10] = 1;
      v7[11] = 0;
    }
    else
    {
      v7 = 0;
    }
    *((_DWORD *)this + 34) = v7;
  }
  if ( !*((_DWORD *)this + 34) )
    *(_DWORD *)this = -1;
  v8 = (void *)*((_DWORD *)this + 42);
  *((_DWORD *)this + 41) = 0;
  if ( v8 )
  {
    j_j__free(v8);
    *((_DWORD *)this + 42) = 0;
  }
  this[172] = 0;
}
