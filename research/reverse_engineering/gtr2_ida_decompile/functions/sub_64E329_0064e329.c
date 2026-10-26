int __thiscall sub_64E329(float *this, _DWORD *a2, int a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // edi
  void (__thiscall ***v8)(_DWORD, int); // ecx

  this[1] = 0.0;
  *this = 0.0;
  *((_DWORD *)this + 2) = a4;
  if ( !(_WORD)a4 || (unsigned __int16)a4 > 5u || (a4 & 0xFF800000) != 0 )
    return -2005530516;
  *(_DWORD *)(a3 + 72) = a4 & 0x200000;
  a2[18] = a4 & 0x400000;
  a2[16] = a4 & 0x80000;
  a2[17] = a4 & 0x100000;
  v5 = sub_659124(a2);
  *((_DWORD *)this + 1) = v5;
  if ( !v5 )
    goto LABEL_18;
  v6 = sub_659124(a3);
  *(_DWORD *)this = v6;
  if ( !v6 )
    goto LABEL_18;
  v7 = sub_64FD9A(v6);
  if ( v7 >= 0 )
  {
    if ( sub_64BDEE(this) >= 0
      || sub_64BEF8(this) >= 0
      || sub_64BFCB(this) >= 0
      || sub_64C19E(this) >= 0
      || sub_64C374(this, v7, this) >= 0
      || sub_64C73C(this, v7, this) >= 0
      || sub_64CC30(this) >= 0
      || sub_64CFD2(this) >= 0
      || sub_64DD69(this) >= 0
      || sub_64D6E3(this) >= 0 )
    {
      v7 = 0;
      goto LABEL_19;
    }
LABEL_18:
    v7 = -2147467259;
  }
LABEL_19:
  v8 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 1);
  if ( v8 )
  {
    (**v8)(v8, 1);
    this[1] = 0.0;
  }
  if ( *(_DWORD *)this )
  {
    (***(void (__thiscall ****)(_DWORD, int))this)(*(_DWORD *)this, 1);
    *this = 0.0;
  }
  return v7;
}
