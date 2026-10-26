_DWORD *__thiscall sub_438C10(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  _DWORD *v4; // edi
  int v5; // edx

  ConstructorStub(this + 123);
  StructInitializer(this + 1371);
  StructInitWithZeroFillSubCall(this + 1387);
  DoubleArrayZero(this + 1550);
  DoubleArrayZero(this + 1575);
  memset(this, 0, 0x1F38u);
  v2 = this + 374;
  v3 = 4;
  do
  {
    *v2 = -1889785610;
    v2[1] = 1081507266;
    v4 = v2 + 2;
    v2[2] = *v2;
    v2[3] = v2[1];
    v2[4] = v2[2];
    v5 = v2[3];
    v2 += 281;
    --v3;
    v4[3] = v5;
  }
  while ( v3 );
  WheelDynamicsInit(this);
  return this;
}

