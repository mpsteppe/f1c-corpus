void __thiscall sub_467D20(int this, int a2)
{
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  float v7; // [esp+4h] [ebp-8h]
  float v8; // [esp+8h] [ebp-4h]

  v3 = sub_57B7C0(this);
  if ( v3 >= 0.33399999 )
  {
    sub_57B690(this);
    v8 = *(float *)(this + 76);
    v7 = v3;
    *(float *)(this + 76) = v8 - v7;
    if ( -15.0 <= *(float *)(this + 76) )
    {
      if ( *(float *)(this + 76) > 45.0 )
        *(_DWORD *)(this + 76) = 1110704128;
    }
    else
    {
      *(float *)(this + 76) = -15.0;
    }
    v4 = *(_DWORD *)(this + 92);
    if ( v4 )
    {
      v5 = *(_DWORD *)(this + 84);
      if ( *(_DWORD *)(this + 288) >= v5 )
      {
        v6 = v4 - 1;
        if ( v6 )
        {
          if ( v6 == 1 )
          {
            sub_46B230(a2);
            *(_DWORD *)(this + 92) = 0;
            *(float *)(this + 76) = 1.0 - 15.0;
            return;
          }
        }
        else
        {
          sub_46B200(a2);
        }
        *(_DWORD *)(this + 92) = 0;
        *(float *)(this + 76) = 1.0 - 15.0;
      }
      else if ( *(_DWORD *)(this + 292) > *(_DWORD *)(this + 88) - v5 || v8 > 0.0 && *(float *)(this + 76) <= 0.0 )
      {
        *(_DWORD *)(this + 76) = 0;
        *(_DWORD *)(this + 92) = 0;
      }
    }
  }
}
