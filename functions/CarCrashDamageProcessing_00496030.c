char __thiscall sub_496030(int this, char a2)
{
  int v3; // eax
  int v4; // ebp
  int v5; // edi
  int v6; // edx
  int v7; // edx
  double v8; // st7
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  double v12; // st7
  float v14; // [esp+8h] [ebp-4h]

  if ( *(float *)(this + 220) <= 0.0 )
    return 0;
  v3 = *(_DWORD *)(this + 5500);
  if ( !v3 )
    return 0;
  v4 = *(_DWORD *)(v3 + 4);
  v5 = *(_DWORD *)(v3 + 12);
  if ( *(_DWORD *)(this + 220) == 1008981770 )
  {
    if ( !*(_DWORD *)(this + 5496) )
      *(_DWORD *)(this + 5496) = RandLCGRandomNumberGenerator(this) % 2;
    switch ( *(_DWORD *)(this + 5496) )
    {
      case 0:
        switch ( RandLCGRandomNumberGenerator(this) % 8 )
        {
          case 0:
            *(_DWORD *)(this + 5504) = v5;
            *(_DWORD *)(this + 5508) = -600;
            break;
          case 1:
            *(_DWORD *)(this + 5504) = v5;
            *(_DWORD *)(this + 5508) = 600;
            break;
          case 2:
            *(_DWORD *)(this + 5504) = 800;
            *(_DWORD *)(this + 5508) = -600;
            break;
          case 3:
            *(_DWORD *)(this + 5504) = 800;
            *(_DWORD *)(this + 5508) = v4;
            break;
          case 4:
            *(_DWORD *)(this + 5504) = 800;
            *(_DWORD *)(this + 5508) = 600;
            break;
          case 5:
            *(_DWORD *)(this + 5504) = -800;
            *(_DWORD *)(this + 5508) = -600;
            break;
          case 6:
            *(_DWORD *)(this + 5504) = -800;
            *(_DWORD *)(this + 5508) = v4;
            break;
          default:
            *(_DWORD *)(this + 5504) = -800;
            *(_DWORD *)(this + 5508) = 600;
            break;
        }
        break;
      case 1:
        v6 = RandLCGRandomNumberGenerator(this) % 3;
        if ( v6 )
        {
          v7 = v6 - 1;
          if ( !v7 )
          {
            *(_DWORD *)(this + 5504) = v5;
            *(_DWORD *)(this + 5508) = 600;
            goto LABEL_23;
          }
          if ( v7 != 1 )
            goto LABEL_23;
          *(_DWORD *)(this + 5504) = 800;
        }
        else
        {
          *(_DWORD *)(this + 5504) = v5;
        }
        *(_DWORD *)(this + 5508) = -600;
        goto LABEL_23;
      case 2:
      case 3:
      case 4:
LABEL_23:
        *(_DWORD *)(this + 6384) = 0;
        *(_BYTE *)(this + 6380) = 0;
        break;
      default:
        break;
    }
  }
  v8 = *(float *)(this + 220) - FloatFieldAccessor(this);
  *(float *)(this + 220) = v8;
  if ( v10 | v11 )
  {
    *(_DWORD *)(this + 5500) = 0;
    *(_DWORD *)(this + 220) = 0;
  }
  else
  {
    v14 = v8 * 100.0;
    v12 = InitViewportDimensions(this);
    sub_495DC0((_DWORD *)this, v12, v14);
    SceneEntityCleanup(a2);
  }
  ShortComputation_7250(1);
  return 1;
}
