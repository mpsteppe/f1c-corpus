char __thiscall sub_422870(float *this, float *a2, int a3)
{
  char v4; // bl
  double v6; // st7
  float v7; // eax
  int v8; // edi

  v4 = 0;
  if ( (unsigned __int8)sub_5787B0(this + 4) )
    return 0;
  if ( this[5191] <= (double)a2[5164] )
    v6 = a2[5164];
  else
    v6 = this[5191];
  this[5191] = v6;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    if ( *((float **)this + 5380) == a2 )
    {
      v7 = *this;
      v8 = *(_DWORD *)a2;
      if ( *(_DWORD *)(*(_DWORD *)this + 22552) > *(_DWORD *)(*(_DWORD *)a2 + 22552) && *((int *)this + 4821) > 3 )
        v4 = 1;
      if ( (*(_DWORD *)(LODWORD(v7) + 4352) && !*(_BYTE *)(LODWORD(v7) + 4416) || sub_41FDF0(LODWORD(v7) + 2704))
        && (!*(_DWORD *)(v8 + 4352) || *(_BYTE *)(v8 + 4416))
        && sub_41FDF0(v8 + 2704) )
      {
        v4 = 1;
        goto LABEL_27;
      }
      if ( v4 == 1 )
      {
LABEL_27:
        if ( *((_DWORD *)this + 4607) != 2 && this[4299] > 0.001 )
        {
          *((_DWORD *)this + 5381) = a2;
          *((_DWORD *)this + 5158) = a3;
          *((_DWORD *)this + 5157) = 160;
        }
      }
    }
  }
  else if ( *(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4 )
  {
    if ( *((_DWORD *)this + 5212) != 1 && *((_DWORD *)this + 4857) == 2 && (unsigned __int8)sub_4227B0() )
    {
      v4 = 1;
      goto LABEL_27;
    }
  }
  else if ( this[4859] > (double)a2[4859] )
  {
    v4 = 1;
    goto LABEL_27;
  }
  return v4;
}
