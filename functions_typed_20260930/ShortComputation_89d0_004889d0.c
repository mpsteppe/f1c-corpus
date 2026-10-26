double __thiscall sub_4889D0(int *this)
{
  int v2; // edi
  double v3; // st7

  v2 = (*(int (__thiscall **)(int *))(*this + 32))(this);
  v3 = (double)(v2 - (*(int (__thiscall **)(int *))(*this + 24))(this));
  if ( v3 <= 0.0 )
    return 0.0;
  else
    return (double)this[56] / v3;
}

