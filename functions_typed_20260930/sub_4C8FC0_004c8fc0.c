int __thiscall sub_4C8FC0(float *this)
{
  double v2; // st7

  v2 = this[6] - dbl_8AFE98;
  this[6] = v2;
  if ( v2 <= 0.0 && (this[6] = this[5], (unsigned __int8)ArithmeticComparison_9000()) )
    return (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
  else
    return 0;
}

