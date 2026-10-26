double __thiscall sub_4BF120(float *this, int a2)
{
  float v6; // [esp+Ch] [ebp+4h]

  v6 = this[a2 + 2];
  if ( sub_4BE6A0(this, a2) == 0.0 )
    return v6;
  else
    return v6 / sub_4BE6A0(this, a2);
}
