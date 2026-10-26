int __thiscall sub_4A63C0(_DWORD *this, float a2)
{
  float *v3; // ecx
  double v4; // st7
  double v5; // st7
  int v6; // edx
  int result; // eax
  float v8; // [esp+8h] [ebp+4h]

  v3 = (float *)((char *)&unk_9204A0 + 22616 * this[210]);
  if ( v3 )
  {
    v4 = v3[4021];
    if ( LODWORD(a2) == 1 )
      v5 = v4 + 5.0;
    else
      v5 = v4 - 5.0;
    v8 = v5;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 100.0 )
        v8 = 100.0;
    }
    else
    {
      v8 = 0.0;
    }
    sub_573880(v8);
    v6 = *this;
    *((_BYTE *)this + 844) = 1;
    return (*(int (__thiscall **)(_DWORD *))(v6 + 184))(this);
  }
  return result;
}
