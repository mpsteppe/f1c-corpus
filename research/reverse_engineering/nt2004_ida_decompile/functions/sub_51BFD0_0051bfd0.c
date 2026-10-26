void __thiscall sub_51BFD0(int this, int a2)
{
  char v3; // al
  int v4; // ecx

  v3 = *(_BYTE *)(this + 18826);
  *(_BYTE *)(this + 18825) = 0;
  if ( !v3 )
  {
    if ( !a2 )
    {
      *(_DWORD *)(this + 18852) = 0;
      *(_DWORD *)(this + 18848) = 0;
      *(_DWORD *)(this + 18828) = 0;
      return;
    }
    if ( *(float *)(this + 18848) <= 0.0 )
    {
      v4 = this + 8;
      if ( a2 <= *(_DWORD *)(this + 18828) )
      {
        sub_5262A0(v4);
        *(_DWORD *)(this + 18848) = *(_DWORD *)(this + 18844);
        if ( a2 >= 1
          && *(float *)(this + 17684) > 0.0
          && *(float *)(this + 18708) > 0.0
          && *(float *)(this + 18740) * 0.5 < *(float *)(this + 18736) )
        {
          sub_51BB70(this);
        }
      }
      else
      {
        sub_5261A0(v4);
        *(_DWORD *)(this + 18848) = *(_DWORD *)(this + 18840);
        if ( a2 == 1 && !*(_DWORD *)(this + 18828) )
        {
          *(_DWORD *)(this + 18852) = 1;
          *(_DWORD *)(this + 18828) = 0;
          *(_BYTE *)(this + 18825) = 1;
          return;
        }
      }
      *(_DWORD *)(this + 18852) = a2;
      *(_DWORD *)(this + 18828) = 0;
    }
  }
}
