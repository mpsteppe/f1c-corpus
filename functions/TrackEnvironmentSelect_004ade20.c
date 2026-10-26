int __thiscall sub_4ADE20(_DWORD *this, char a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // ecx
  int v7; // eax

  if ( a2 )
  {
    if ( (byte_7CB710 & 1) != 0 )
    {
      sub_4AE750(2);
    }
    else if ( (byte_7CBB0C & 1) != 0 )
    {
      sub_4AE750(3);
    }
    else
    {
      sub_4AE750(1);
    }
  }
  else
  {
    this[1723] = 1;
  }
  if ( (int)this[1732] > 0 )
  {
    v3 = dword_5EC4A8 + 1;
    if ( dword_5EC4A8 + 1 > 4 )
      v3 = 4;
    v4 = this[1735];
    this[1732] = v3;
    v5 = this[1734];
    v6 = this[1732];
    if ( v6 >= v5 )
    {
      if ( v6 > v4 )
        this[1732] = v4;
    }
    else
    {
      this[1732] = v5;
    }
  }
  v7 = dword_8AC490 + 396 * dword_8AC48C;
  if ( v7 )
    TrackSceneLoader(v7 + 260);
  PhysicsParameterInitialization(this);
  EmptyStub_0170(this);
  DrivingModeParameterSetup(this);
  CarPartVisibilityController(this);
  sub_4AE9F0(this);
  return TireCompoundClamp(this);
}
