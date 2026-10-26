void __thiscall sub_4C2C10(int *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // edi
  __int16 *v6; // ebp

  v2 = sub_4FA870(0);
  v3 = *this;
  if ( dword_7D7540 == 4
    || dword_7D7540 == 5
    || dword_7D7540 == 6
    || dword_7D7540 == 7
    || dword_6310D8[6326 * v2] == *(_DWORD *)(*this + 20848) && dword_7D7540 == 3 )
  {
    v4 = this[237];
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        if ( *(_DWORD *)(v3 + 20892) == 1 )
        {
          sub_4C1970(this, 3);
          sub_45D270(&byte_764D68, aPitThisLapYN, 0);
        }
        else
        {
          v5 = 0;
          v6 = word_762A08;
          while ( v5 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
          {
            if ( *v6 == 21 )
            {
              sub_4C1970(this, 2);
              sub_45D270(&byte_764D68, aPitThisLapYN, 0);
              sub_45D100(&byte_764D68, (int)aPitstopRequest, 0, 16909060, 0);
              ++v5;
              ++v6;
            }
            else
            {
              if ( *v6 == 49 )
              {
                sub_4C1970(this, 3);
                sub_45D270(&byte_764D68, aPitThisLapYN, 0);
                sub_45D100(&byte_764D68, (int)aPitstopDecline, 0, 16909060, 0);
              }
              ++v5;
              ++v6;
            }
          }
        }
        if ( this[237] == 1 && flt_7D7974 <= (double)*(float *)(*this + 20856) )
          sub_4C1970(this, 3);
      }
    }
    else if ( *(float *)(v3 + 20856) > flt_7D7974 - flt_6290D0 * 0.30000001
           && *(float *)(v3 + 20856) < (double)flt_7D7974 )
    {
      sub_4C1970(this, 1);
    }
  }
}
