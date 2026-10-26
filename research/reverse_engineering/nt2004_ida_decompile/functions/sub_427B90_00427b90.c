char __thiscall sub_427B90(int this, float a2, char a3)
{
  bool v3; // c0
  double v5; // st7

  if ( a3 )
  {
    if ( *(float *)(this + 23644) > (double)a2 )
    {
      v3 = a2 < (double)*(float *)(this + 23648);
      *(float *)(this + 23644) = a2;
      if ( v3 )
      {
        *(_DWORD *)(this + 23644) = *(_DWORD *)(this + 23648);
        return 0;
      }
    }
  }
  else
  {
    v5 = a2 - *(float *)(this + 23716);
    if ( v5 < *(float *)(this + 23636) )
    {
      *(float *)(this + 23636) = v5;
      if ( v5 < *(float *)(this + 23640) )
      {
        *(_DWORD *)(this + 23636) = *(_DWORD *)(this + 23640);
        return 0;
      }
    }
  }
  return 1;
}
