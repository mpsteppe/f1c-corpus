int __thiscall sub_465BA0(int *this)
{
  _DWORD *v2; // ecx
  int result; // eax
  float v4; // [esp+0h] [ebp-8h]

  v2 = (_DWORD *)*this;
  result = v2[1680];
  if ( result )
  {
    sub_460A60(v2);
    v4 = dbl_7DA9C8;
    sub_460F00(*this, v4);
    result = *this;
  }
  *(_BYTE *)(*this + 636) = 0;
  return result;
}
