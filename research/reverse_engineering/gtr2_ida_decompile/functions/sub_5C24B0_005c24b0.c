void __thiscall sub_5C24B0(float *this, double a2)
{
  double v2; // st7
  double v3; // st7
  int v4; // ecx

  if ( !*((_BYTE *)this + 80) )
  {
    v2 = *(double *)this;
    this[13] = this[11];
    this[10] = v2;
    if ( !*((_BYTE *)this + 82) )
      goto LABEL_8;
    v3 = this[9] * a2 + this[8];
    this[8] = v3;
    if ( this[9] < 0.0 )
    {
      if ( v3 > this[7] )
        goto LABEL_8;
    }
    else if ( v3 < this[7] )
    {
      goto LABEL_8;
    }
    this[8] = this[7];
    *((_BYTE *)this + 82) = 0;
LABEL_8:
    v4 = *((_DWORD *)this + 17);
    if ( v4 )
      (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 12))(v4, LODWORD(a2), HIDWORD(a2));
  }
}
