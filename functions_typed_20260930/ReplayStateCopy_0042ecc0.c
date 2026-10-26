_DWORD *__thiscall sub_42ECC0(_DWORD *this, int a2)
{
  _DWORD *v3; // edi
  _DWORD *result; // eax
  int v5; // ecx

  v3 = this + 1628;
  GearRatioConfigFileReader(this + 1628, a2);
  this[1424] = this[1630];
  result = this + 1440;
  v5 = 8;
  do
  {
    *result = *v3;
    result += 16;
    --v5;
  }
  while ( v5 );
  return result;
}

