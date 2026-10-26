void __thiscall sub_4BD160(int this, int a2, float a3)
{
  int v3; // esi
  int v4; // edx
  double v6; // st7
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c3
  float v9; // [esp+0h] [ebp-Ch]

  v3 = *(_DWORD *)(this + 104);
  if ( v3 )
  {
    v4 = this + 32 * a2;
    if ( *(_DWORD *)(v4 + 136) != -1 )
    {
      if ( *(_DWORD *)(32 * (a2 + 4) + this) )
      {
        if ( a3 > (double)*(float *)(v4 + 108) )
        {
          v6 = *(float *)(this + 68);
          if ( v7 | v8 )
          {
            if ( v6 != a3 )
            {
              *(float *)(this + 68) = a3;
              v9 = (a3 - *(float *)(v4 + 108)) * *(float *)(v4 + 116) * (*(float *)(v4 + 124) - *(float *)(v4 + 120))
                 + *(float *)(v4 + 120);
              sub_5AD5F0(v3, v9);
            }
          }
          else if ( v6 != *(float *)(v4 + 112) )
          {
            *(_DWORD *)(this + 68) = *(_DWORD *)(v4 + 112);
            sub_5AD5F0(v3, *(float *)(v4 + 124));
          }
        }
        else if ( *(float *)(this + 68) != *(float *)(v4 + 108) )
        {
          *(_DWORD *)(this + 68) = *(_DWORD *)(v4 + 108);
          sub_5AD5F0(v3, *(float *)(v4 + 120));
        }
      }
    }
  }
}
