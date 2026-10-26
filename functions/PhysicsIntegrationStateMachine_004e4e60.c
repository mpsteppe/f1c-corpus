_DWORD *__thiscall sub_4E4E60(int this, int a2)
{
  double v3; // st7
  int v4; // ecx
  int v5; // eax
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  _DWORD *result; // eax
  int v10; // edx
  int v11; // edi

  v3 = *(float *)(this + 13576);
  v4 = *(_DWORD *)(this + 13464);
  if ( v3 * v3 > *(float *)(this + 13468) )
  {
    v5 = *(_DWORD *)(this + 13476);
    ++v4;
LABEL_6:
    *(_DWORD *)(this + 13480) = v5;
    goto LABEL_7;
  }
  if ( v7 | v8 )
  {
    v5 = *(_DWORD *)(this + 13472);
    goto LABEL_6;
  }
  ++v4;
  *(_DWORD *)(this + 13480) = *(_DWORD *)(this + 13476);
LABEL_7:
  result = (_DWORD *)(this + 13808);
  v10 = 4;
  do
  {
    *result = *(_DWORD *)(this + 13480);
    result += 62;
    --v10;
  }
  while ( v10 );
  if ( v4 <= 0 )
  {
    *(_DWORD *)(this + 13484) = a2;
  }
  else
  {
    v11 = v4;
    do
    {
      SuspensionSpringDampingRateReset(this);
      sub_4E58D0(this);
      sub_4E51A0(this);
      WheelForceCalculationSpringDamperTorque(this);
      result = (_DWORD *)sub_4E5AE0(this);
      --v11;
    }
    while ( v11 );
    *(_DWORD *)(this + 13484) = a2;
  }
  return result;
}
