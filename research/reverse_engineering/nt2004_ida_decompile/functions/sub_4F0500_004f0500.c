int __thiscall sub_4F0500(float *this)
{
  double v2; // st7

  v2 = this[6] - dbl_7DA9C8;
  this[6] = v2;
  if ( v2 <= 0.0 && (this[6] = this[5], (unsigned __int8)sub_4F0540()) )
    return (*(int (__thiscall **)(float *))(*(_DWORD *)this + 12))(this);
  else
    return 0;
}
