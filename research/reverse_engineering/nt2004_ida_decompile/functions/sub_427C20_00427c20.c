char __thiscall sub_427C20(int this, float a2, char a3)
{
  bool v3; // c0
  bool v4; // c3
  double v6; // st7

  if ( a3 )
  {
    if ( *(float *)(this + 23648) < (double)a2 )
    {
      v3 = a2 < (double)*(float *)(this + 23644);
      v4 = a2 == *(float *)(this + 23644);
      *(float *)(this + 23648) = a2;
      if ( !v3 && !v4 )
      {
        *(_DWORD *)(this + 23648) = *(_DWORD *)(this + 23644);
        return 0;
      }
    }
  }
  else
  {
    v6 = a2 - *(float *)(this + 23716);
    if ( v6 > *(float *)(this + 23640) )
    {
      *(float *)(this + 23640) = v6;
      if ( v6 > *(float *)(this + 23636) )
      {
        *(_DWORD *)(this + 23640) = *(_DWORD *)(this + 23636);
        return 0;
      }
    }
  }
  return 1;
}
