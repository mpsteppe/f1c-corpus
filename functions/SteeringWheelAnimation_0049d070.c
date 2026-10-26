int __thiscall sub_49D070(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v11; // eax
  char v12; // bl
  int v13; // eax
  int v14; // ecx
  int v15; // [esp+8h] [ebp-4h]

  v11 = *(_DWORD *)(dword_7C54E0 + 13000);
  if ( v11 )
  {
    if ( v11 <= 0 || v11 > 2 || *(float *)(dword_7C54E0 + 14752) <= 0.0 )
    {
      v12 = 0;
      LOBYTE(v15) = 1;
    }
    else
    {
      v12 = 1;
      LOBYTE(v15) = 1;
    }
  }
  else
  {
    v12 = byte_7C9081;
    LOBYTE(v15) = byte_7C9081 == 0;
  }
  v13 = this[4];
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 + 84);
    if ( v14 )
    {
      if ( this[1] )
      {
        RenderDrawOperationWithClipping(0, 0, *(_DWORD *)(v14 + 28), *(_DWORD *)(v14 + 32), 0);
        if ( v12 )
        {
          if ( (_BYTE)v15 )
            AudioEffectTrigger(0, 0);
          else
            sub_49D4C0(this);
          TrackPositionNameFormatter(this);
          WheelRotationAnimation(this);
          GlobalStateBranchFormat(this);
          FormatRegisterDispatch(this);
          LocalBufferSubsystemCall(this);
        }
        else
        {
          AudioEffectTrigger(0, 0);
        }
      }
    }
  }
  sub_49D5D0(v15);
  v1 = this[19];
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 84);
    if ( v2 )
      ParamRangeClampedLerp(0, this + 24, v2);
  }
  v3 = this[20];
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 84);
    if ( v4 )
      ParamRangeClampedLerp(1, this + 43, v4);
  }
  v5 = this[21];
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 84);
    if ( v6 )
      ParamRangeClampedLerp(2, this + 62, v6);
  }
  v7 = this[22];
  if ( v7 )
  {
    v8 = *(_DWORD *)(v7 + 84);
    if ( v8 )
      ParamRangeClampedLerp(3, this + 81, v8);
  }
  result = this[23];
  if ( result )
  {
    result = *(_DWORD *)(result + 84);
    if ( result )
      return ParamRangeClampedLerp(4, this + 100, result);
  }
  return result;
}
