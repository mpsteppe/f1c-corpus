// f1c  0x004c2c40  size=111
void __thiscall sub_4C2C40(int this, int a2)
{
  int v2; // eax
  double v3; // st7
  double v4; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  float v8; // [esp+8h] [ebp+4h]

  v2 = *(_DWORD *)(this + 40);
  v3 = (double)a2;
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      *(float *)(this + 68) = v3;
    }
    else
    {
      v8 = (double)(v2 - 1) * *(float *)(this + 68) + v3;
      v4 = v8 / (double)*(int *)(this + 40);
      *(float *)(this + 68) = v4;
      if ( v6 | v7 )
      {
        *(_DWORD *)(this + 68) = 1065353216;
      }
      else if ( v4 > 22.0 )
      {
        *(_DWORD *)(this + 68) = 1102053376;
      }
    }
  }
}
