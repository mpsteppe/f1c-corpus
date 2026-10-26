void __thiscall sub_529AC0(int this, float *a2, float a3, float a4, float a5)
{
  if ( !*(_DWORD *)(this + 328) && *(float *)(this + 96) < 3.4028235e38 )
  {
    *(_DWORD *)(this + 340) = 1;
    if ( dbl_7DA9D0 > *(float *)(this + 96) )
    {
      *(float *)(this + 88) = a4;
      *(float *)(this + 92) = a5;
      *(_DWORD *)(this + 344) = a2;
      goto LABEL_13;
    }
    if ( *a2 > (double)**(float **)(this + 344) )
    {
LABEL_13:
      *(float *)(this + 96) = dbl_7DA9D0 + a3;
      if ( dword_7D7928 == 3 )
      {
        *(_DWORD *)(this + 88) = 1065353216;
        *(_DWORD *)(this + 92) = -1082130432;
      }
      return;
    }
    if ( *(float *)(this + 88) <= (double)*(float *)(this + 92) )
    {
      if ( *(float *)(this + 88) > (double)a4 )
        *(float *)(this + 88) = a4;
      if ( *(float *)(this + 92) >= (double)a5 )
        goto LABEL_12;
    }
    else
    {
      *(float *)(this + 88) = a4;
    }
    *(float *)(this + 92) = a5;
LABEL_12:
    *(_DWORD *)(this + 344) = a2;
    goto LABEL_13;
  }
}
