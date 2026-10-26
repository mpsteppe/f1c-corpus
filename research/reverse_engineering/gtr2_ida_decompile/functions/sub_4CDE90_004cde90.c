double __thiscall sub_4CDE90(int *this)
{
  int v2; // edi
  double v3; // st7

  v2 = (*(int (__thiscall **)(int *))(*this + 12))(this);
  v3 = (double)(v2 - (*(int (__thiscall **)(int *))(*this + 4))(this));
  if ( v3 <= 0.0 )
    return 0.0;
  else
    return (double)this[67] / v3;
}
