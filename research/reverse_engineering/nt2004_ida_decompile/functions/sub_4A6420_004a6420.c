void __thiscall sub_4A6420(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  int v4; // edx

  if ( a2 )
  {
    v3 = operator new(0x10u);
    if ( v3 )
    {
      *v3 = a2;
      v3[1] = 0;
      v3[2] = 0;
      *((_BYTE *)v3 + 12) = 1;
    }
    else
    {
      v3 = 0;
    }
    if ( this[67] )
    {
      *(_DWORD *)(this[68] + 4) = v3;
      v3[2] = this[68];
    }
    else
    {
      this[67] = v3;
      this[69] = v3;
    }
    v4 = this[70] + 1;
    this[68] = v3;
    this[70] = v4;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 24))(a2, 0);
  }
}
