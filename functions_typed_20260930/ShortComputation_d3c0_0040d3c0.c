void __thiscall sub_40D3C0(int this, int a2)
{
  unsigned int v3; // eax

  if ( dword_7D0350 )
  {
    v3 = SessionPhaseDecode((_DWORD *)this);
    if ( a2 >= 7 && a2 <= 10 )
    {
      if ( v3 <= 5 )
        *(_DWORD *)(this + 16) = v3;
      GameActionStateMachine((_DWORD *)this, a2, 0);
      *(_BYTE *)(this + 36) = 1;
      ReciprocalWithSignCheck((int)&flt_5EA4E8, 0.75);
    }
  }
}

